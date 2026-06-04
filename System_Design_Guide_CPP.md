# Complete System Design Guide: Beginner to Advanced

This guide teaches system design from fundamentals to advanced interview-level thinking. It covers both high-level design (HLD) and low-level design (LLD), with practical C++ examples for object-oriented design, SOLID principles, design patterns, caching, rate limiting, and concurrency-style building blocks.

The goal is not to memorize diagrams. The goal is to learn how to reason about requirements, trade-offs, scale, failure, data, APIs, and maintainable code.

## Table of Contents

1. [Introduction to System Design](#1-introduction-to-system-design)
2. [Core Concepts for Beginners](#2-core-concepts-for-beginners)
3. [Intermediate System Design Topics](#3-intermediate-system-design-topics)
4. [Advanced System Design Topics](#4-advanced-system-design-topics)
5. [Design Patterns With C++ Examples](#5-design-patterns-with-c-examples)
6. [Real-World Case Studies](#6-real-world-case-studies)
7. [Interview Questions and Answers](#7-interview-questions-and-answers)
8. [Summary and Revision Notes](#8-summary-and-revision-notes)

---

## 1. Introduction to System Design

### What Is System Design?

System design is the process of designing software systems that satisfy functional requirements, non-functional requirements, and real-world constraints.

Functional requirements describe what the system does:

- Users can post messages.
- Users can upload images.
- Users can search products.
- A driver can accept a ride.

Non-functional requirements describe how well the system works:

- Low latency.
- High availability.
- Reliability.
- Scalability.
- Fault tolerance.
- Security.
- Maintainability.
- Cost efficiency.

### Low-Level Design vs High-Level Design

| Type | Focus | Examples |
|---|---|---|
| Low-Level Design | classes, interfaces, methods, object relationships, design patterns | parking lot, elevator, snake and ladder, logger, cache class |
| High-Level Design | services, databases, queues, caches, APIs, scale, reliability | URL shortener, WhatsApp, YouTube, Uber, Twitter feed |

In interviews, LLD checks if you can write clean maintainable code. HLD checks if you can design large systems that work under load and failure.

### A Good System Design Answer

A strong system design answer usually follows this order:

1. Clarify requirements.
2. Estimate scale.
3. Define APIs.
4. Design data model.
5. Draw high-level architecture.
6. Explain core flows.
7. Discuss bottlenecks.
8. Add scalability.
9. Add reliability and fault tolerance.
10. Discuss trade-offs.
11. Mention monitoring, security, and future improvements.

### Beginner Mental Model

Think of a system like a restaurant:

- Client: customer placing an order.
- API server: waiter taking the order.
- Database: kitchen record book.
- Cache: ready-to-serve popular items.
- Queue: order line for kitchen.
- Worker: chef preparing orders.
- Load balancer: manager assigning customers to waiters.
- Monitoring: cameras and dashboards.
- Replication: multiple kitchens with copied recipes.
- Sharding: different kitchens handling different food categories.

### Common Interview Mistakes

- Jumping into microservices before understanding requirements.
- Ignoring data model.
- Ignoring failure cases.
- Saying "use cache" without cache invalidation strategy.
- Saying "use sharding" without shard key.
- Forgetting trade-offs.
- Designing for 1 billion users when interviewer asked for 10 thousand.
- Not explaining why a component is needed.

### Interview Questions

**Q: What is the difference between scalability and availability?**

Scalability means the system can handle more load by adding resources. Availability means the system remains usable when parts fail.

**Q: What is the difference between HLD and LLD?**

HLD focuses on services, storage, APIs, traffic, reliability, and infrastructure. LLD focuses on classes, interfaces, design patterns, and code structure.

---

## 2. Core Concepts for Beginners

### 2.1 Requirements

Before designing anything, ask questions.

Functional requirement examples:

- Can users create accounts?
- Can users upload files?
- Can users search?
- Can users follow each other?
- Can users delete data?

Non-functional requirement examples:

- How many users?
- Read-heavy or write-heavy?
- Maximum acceptable latency?
- Required uptime?
- Data consistency requirements?
- Security or privacy requirements?

#### Requirement Checklist

| Question | Why it matters |
|---|---|
| Who uses the system? | determines scale and access patterns |
| What are the main actions? | defines APIs |
| How much traffic? | defines capacity |
| Is data read-heavy or write-heavy? | affects cache and database design |
| Can data be eventually consistent? | affects replication and queues |
| What can fail? | affects reliability design |

### 2.2 Capacity Estimation

Capacity estimation helps choose the right architecture.

Example:

- 10 million daily active users.
- Each user reads 100 posts/day.
- Each user writes 2 posts/day.
- Reads/day = 1 billion.
- Writes/day = 20 million.
- Average reads/sec = 1,000,000,000 / 86,400 = about 11,600 reads/sec.
- Average writes/sec = 20,000,000 / 86,400 = about 231 writes/sec.

This is read-heavy. Caching and read replicas matter.

### 2.3 Latency, Throughput, and Bandwidth

| Term | Meaning |
|---|---|
| Latency | time taken for one request |
| Throughput | number of requests handled per second |
| Bandwidth | amount of data transferred per second |

Low latency does not always mean high throughput. A system can respond quickly to one request but fail under many requests.

### 2.4 APIs

APIs define how clients interact with the system.

Example URL shortener APIs:

```text
POST /shorten
Request: { "longUrl": "https://example.com/very/long/path" }
Response: { "shortUrl": "https://sho.rt/abc123" }

GET /{shortCode}
Response: HTTP 302 redirect to long URL
```

Good APIs are:

- clear
- versioned when needed
- idempotent where possible
- secure
- easy to monitor

### 2.5 Data Modeling

Data model depends on access patterns.

For a URL shortener:

```text
Table: urls
short_code | long_url | user_id | created_at | expires_at
```

For a chat app:

```text
Table: messages
message_id | conversation_id | sender_id | body | created_at | status
```

Design data around queries:

- What do we read most often?
- What do we write most often?
- What needs indexing?
- What needs strong consistency?

### 2.6 Basic C++ Abstraction Example

System design also includes clean code design. Use interfaces when behavior can change.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Storage {
public:
    virtual void save(const string& key, const string& value) = 0;
    virtual optional<string> get(const string& key) = 0;
    virtual ~Storage() = default;
};

class InMemoryStorage : public Storage {
    unordered_map<string, string> data;

public:
    void save(const string& key, const string& value) override {
        data[key] = value;
    }

    optional<string> get(const string& key) override {
        if (!data.count(key)) return nullopt;
        return data[key];
    }
};

class UrlService {
    Storage& storage;

public:
    UrlService(Storage& storage) : storage(storage) {}

    void createShortUrl(const string& code, const string& longUrl) {
        storage.save(code, longUrl);
    }

    optional<string> resolve(const string& code) {
        return storage.get(code);
    }
};
```

Why this is good:

- `UrlService` does not care if storage is memory, MySQL, Redis, or a file.
- Easy to test.
- Easy to replace implementation.

### Core Topic Interview Questions

**Q: Why do we estimate traffic in system design interviews?**

To understand whether simple architecture is enough or whether we need caching, sharding, queues, replicas, and special storage choices.

**Q: Why should API design come before database design?**

APIs reveal access patterns. Access patterns decide database schema, indexes, cache keys, and partitioning.

---

## 3. Intermediate System Design Topics

## 3.1 Scalability

### Plain Idea

Scalability means the system can handle more traffic, data, or users.

### Vertical Scaling

Vertical scaling means using a bigger machine:

- more CPU
- more RAM
- faster disk

Pros:

- simple
- fewer distributed system problems

Cons:

- physical limit
- expensive
- single machine can still fail

### Horizontal Scaling

Horizontal scaling means adding more machines.

Pros:

- handles much larger scale
- better fault tolerance

Cons:

- needs load balancing
- distributed consistency problems
- more operational complexity

### Best Practice

Start simple, then scale bottlenecks. Do not add distributed complexity before it is needed.

## 3.2 Load Balancing

### Plain Idea

A load balancer distributes requests across many servers.

```text
Client -> Load Balancer -> Server 1
                        -> Server 2
                        -> Server 3
```

### Algorithms

| Algorithm | Use when | Trade-off |
|---|---|---|
| Round robin | servers are similar | ignores server load |
| Weighted round robin | servers have different capacity | needs weights |
| Least connections | long-lived requests | needs connection tracking |
| IP hash | sticky sessions | uneven distribution possible |
| Random | simple large-scale systems | less predictable |

### When Load Balancing Fails

- All backend servers are unhealthy.
- Health checks are wrong.
- Sticky sessions overload one server.
- Load balancer itself is a single point of failure.

### C++ Round Robin Example

```cpp
class RoundRobinLoadBalancer {
    vector<string> servers;
    atomic<int> index{0};

public:
    RoundRobinLoadBalancer(vector<string> servers) : servers(move(servers)) {}

    string nextServer() {
        int i = index.fetch_add(1);
        return servers[i % servers.size()];
    }
};
```

## 3.3 Caching

### Plain Idea

Cache stores frequently accessed data in a faster place.

Examples:

- Browser cache.
- CDN cache.
- Redis cache.
- Application memory cache.
- Database page cache.

### Cache Patterns

| Pattern | How it works | Use when | Problem |
|---|---|---|---|
| Cache-aside | app checks cache, then DB | common read-heavy systems | stale data |
| Read-through | cache loads from DB | cleaner app logic | cache system more complex |
| Write-through | write cache and DB together | strong cache consistency | slower writes |
| Write-back | write cache first, DB later | fast writes | data loss risk |
| Refresh-ahead | refresh before expiry | hot keys | more background work |

### Cache Eviction

| Policy | Meaning |
|---|---|
| LRU | remove least recently used |
| LFU | remove least frequently used |
| FIFO | remove oldest |
| TTL | expire after time |

### Common Cache Mistakes

- No TTL.
- Cache key not versioned.
- Cache stampede when many requests rebuild same missing key.
- Caching sensitive data insecurely.
- Forgetting invalidation after writes.

### C++ LRU Cache Example

```cpp
class LRUCache {
    int capacity;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> pos;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (!pos.count(key)) return -1;
        auto it = pos[key];
        int value = it->second;
        items.erase(it);
        items.push_front({key, value});
        pos[key] = items.begin();
        return value;
    }

    void put(int key, int value) {
        if (pos.count(key)) {
            items.erase(pos[key]);
        } else if ((int)items.size() == capacity) {
            auto [oldKey, oldValue] = items.back();
            items.pop_back();
            pos.erase(oldKey);
        }
        items.push_front({key, value});
        pos[key] = items.begin();
    }
};
```

## 3.4 Database Design

### SQL vs NoSQL

| Database type | Good for | Not good for |
|---|---|---|
| SQL | transactions, joins, strict schema | huge flexible unstructured data |
| Key-value | simple fast lookups | complex queries |
| Document DB | flexible JSON-like data | heavy joins |
| Wide-column | massive writes and scale | ad hoc joins |
| Graph DB | relationship-heavy queries | simple key-value access |
| Search engine | full-text search | source of truth |

### Indexing

Index speeds reads but slows writes.

Use indexes on:

- columns used in filters
- columns used in joins
- columns used in sorting

Do not over-index:

- extra storage
- slower inserts/updates
- more maintenance

### Normalization vs Denormalization

| Approach | Benefit | Cost |
|---|---|---|
| Normalization | less duplicate data, safer updates | joins can be slower |
| Denormalization | faster reads | duplicate data and update complexity |

## 3.5 Replication

### Plain Idea

Replication copies data across machines.

```text
Primary DB -> Replica 1
           -> Replica 2
```

### Types

| Type | Meaning | Trade-off |
|---|---|---|
| Primary-replica | writes to primary, reads from replicas | replica lag |
| Multi-primary | multiple write nodes | conflict resolution |
| Synchronous | write waits for replica | slower but safer |
| Asynchronous | primary responds first | faster but possible data loss |

### When Replication Fails

- Replica lag causes stale reads.
- Primary fails and failover is slow.
- Split brain: two primaries accept writes.

## 3.6 Sharding

### Plain Idea

Sharding splits data across machines.

```text
user_id % 4 = 0 -> shard 0
user_id % 4 = 1 -> shard 1
user_id % 4 = 2 -> shard 2
user_id % 4 = 3 -> shard 3
```

### Shard Key

A shard key decides where data lives.

Good shard key:

- evenly distributes traffic
- appears in common queries
- avoids hot shards
- does not change often

Bad shard key:

- timestamp for write-heavy system because latest shard becomes hot
- country if most users are from one country
- celebrity user id if followers create huge hot partition

### C++ Consistent Hashing Example

```cpp
class ConsistentHashRing {
    map<size_t, string> ring;
    hash<string> hasher;

public:
    void addServer(const string& server, int replicas = 100) {
        for (int i = 0; i < replicas; i++) {
            string key = server + "#" + to_string(i);
            ring[hasher(key)] = server;
        }
    }

    string getServer(const string& itemKey) {
        if (ring.empty()) throw runtime_error("no servers");
        size_t h = hasher(itemKey);
        auto it = ring.lower_bound(h);
        if (it == ring.end()) it = ring.begin();
        return it->second;
    }
};
```

## 3.7 Messaging and Queues

### Plain Idea

Message queues decouple producers and consumers.

```text
API Server -> Queue -> Worker
```

Use queues for:

- emails
- notifications
- video processing
- payment workflows
- log processing
- async retries

### Queue Benefits

- absorbs traffic spikes
- retries failures
- decouples services
- improves latency by moving slow work to background

### Queue Problems

- duplicate messages
- out-of-order processing
- poison messages
- delayed failures
- queue backlog

### C++ Thread-Safe Queue Example

```cpp
template <class T>
class BlockingQueue {
    queue<T> q;
    mutex m;
    condition_variable cv;

public:
    void push(T item) {
        {
            lock_guard<mutex> lock(m);
            q.push(move(item));
        }
        cv.notify_one();
    }

    T pop() {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&] { return !q.empty(); });
        T item = move(q.front());
        q.pop();
        return item;
    }
};
```

## 3.8 Reliability, Availability, and Fault Tolerance

### Definitions

| Term | Meaning |
|---|---|
| Reliability | system works correctly over time |
| Availability | system is accessible when needed |
| Fault tolerance | system continues despite failures |
| Durability | saved data is not lost |

### Availability Numbers

| Availability | Downtime per year |
|---|---|
| 99% | about 3.65 days |
| 99.9% | about 8.76 hours |
| 99.99% | about 52.6 minutes |
| 99.999% | about 5.26 minutes |

### Techniques

- redundancy
- replication
- retries with backoff
- circuit breakers
- timeouts
- health checks
- graceful degradation
- backups
- disaster recovery
- monitoring and alerts

### Common Reliability Mistakes

- Infinite retries.
- No timeout.
- Retrying non-idempotent requests.
- No dead-letter queue.
- No backup restore testing.
- Depending on one region.

## 3.9 Rate Limiting

### Plain Idea

Rate limiting protects the system from abuse and overload.

### Algorithms

| Algorithm | Use case | Trade-off |
|---|---|---|
| Fixed window | simple limits | boundary burst |
| Sliding window log | accurate | high memory |
| Sliding window counter | approximate | small error |
| Token bucket | allows bursts | needs refill logic |
| Leaky bucket | smooth output | can delay requests |

### C++ Token Bucket Example

```cpp
class TokenBucket {
    double capacity;
    double tokens;
    double refillPerSecond;
    chrono::steady_clock::time_point last;

public:
    TokenBucket(double capacity, double refillPerSecond)
        : capacity(capacity),
          tokens(capacity),
          refillPerSecond(refillPerSecond),
          last(chrono::steady_clock::now()) {}

    bool allow() {
        auto now = chrono::steady_clock::now();
        double elapsed = chrono::duration<double>(now - last).count();
        last = now;
        tokens = min(capacity, tokens + elapsed * refillPerSecond);

        if (tokens >= 1.0) {
            tokens -= 1.0;
            return true;
        }
        return false;
    }
};
```

### Intermediate Topic Interview Questions

**Q: When should you use a cache?**

Use a cache when data is read frequently, expensive to compute, or expensive to fetch. Avoid caching data that changes constantly unless you have a clear invalidation strategy.

**Q: What is the difference between replication and sharding?**

Replication copies the same data to multiple machines. Sharding splits different data across machines.

**Q: Why use queues?**

Queues decouple services, smooth traffic spikes, allow retries, and move slow work outside the request path.

---

## 4. Advanced System Design Topics

## 4.1 Consistency

### Strong Consistency

After a write completes, all future reads see it.

Use when:

- banking
- inventory
- account balance
- password changes

Cost:

- higher latency
- lower availability during network partitions

### Eventual Consistency

Reads may be stale for a short time, but replicas eventually converge.

Use when:

- likes
- views
- feeds
- analytics

Cost:

- users may see old data temporarily

### CAP Theorem

When a network partition happens, a distributed system must choose between:

- Consistency: all nodes see the same data.
- Availability: every request receives a response.

Partition tolerance is required in real distributed systems because networks fail.

## 4.2 Idempotency

An operation is idempotent if repeating it has the same effect as doing it once.

Example:

```text
PUT /user/123/email
```

Setting email to the same value multiple times is safe.

Payment systems use idempotency keys:

```text
POST /payments
Idempotency-Key: abc-123
```

If client retries, server returns the same result instead of charging twice.

## 4.3 Distributed Transactions

### Two-Phase Commit

1. Prepare phase.
2. Commit phase.

Problem:

- coordinator failure can block participants.
- high latency.

### Saga Pattern

Break transaction into steps. Each step has a compensating action.

Example travel booking:

1. Reserve flight.
2. Reserve hotel.
3. Reserve car.
4. If hotel fails, cancel flight.

Use saga when services are distributed and eventual consistency is acceptable.

## 4.4 Event-Driven Architecture

Services communicate through events.

```text
OrderService -> OrderCreated event -> PaymentService
                                -> InventoryService
                                -> EmailService
```

Pros:

- services are decoupled
- easy to add consumers
- good for async workflows

Cons:

- debugging is harder
- events can be duplicated
- eventual consistency

## 4.5 Observability

Observability answers: what is happening inside the system?

### Three Pillars

| Pillar | Purpose |
|---|---|
| Logs | discrete events |
| Metrics | numeric trends |
| Traces | request path across services |

Important metrics:

- request rate
- error rate
- latency percentiles
- CPU/memory
- queue lag
- cache hit rate
- DB query latency

## 4.6 Security

Security must be part of design, not an afterthought.

Checklist:

- authentication
- authorization
- input validation
- encryption in transit
- encryption at rest
- rate limiting
- audit logs
- secret management
- least privilege
- safe password hashing

Common mistakes:

- storing passwords directly
- exposing internal IDs without checks
- no rate limit on login
- logging sensitive data
- using one admin credential everywhere

## 4.7 Advanced Storage Concepts

### Partitioning

Partitioning splits a large table into smaller parts.

Types:

- range partition
- hash partition
- list partition

### Read Replicas

Read replicas reduce load on primary DB.

Trade-off:

- reads may be stale.

### Materialized Views

Precomputed query results.

Use when:

- query is expensive
- data changes less often than it is read

### Search Indexes

Use Elasticsearch/OpenSearch-like systems for:

- full-text search
- ranking
- typo tolerance
- filtering

Do not use search index as the source of truth.

## 4.8 CDN and Static Content

CDN stores content near users.

Use for:

- images
- videos
- CSS/JS
- public downloads

Benefits:

- lower latency
- less origin traffic
- better global availability

Problems:

- invalidation can be hard
- stale content
- signed URLs needed for private files

## 4.9 Advanced Interview Questions

**Q: How do you handle duplicate messages in a queue?**

Use idempotent consumers, message IDs, deduplication tables, and safe retry logic.

**Q: How do you avoid cache stampede?**

Use request coalescing, locks, stale-while-revalidate, jittered TTL, and background refresh.

**Q: What is graceful degradation?**

The system keeps core features working even if optional features fail. Example: checkout works even if recommendations are down.

---

## 5. Design Patterns With C++ Examples

Design patterns are reusable solutions to common code design problems. Use them when they reduce complexity. Do not force them everywhere.

## 5.1 SOLID Principles

### S: Single Responsibility Principle

A class should have one main reason to change.

Bad: one class validates, saves, emails, and logs.

Good: separate validator, repository, email service, logger.

### O: Open/Closed Principle

Open for extension, closed for modification.

Use interfaces to add new behavior without editing old code.

### L: Liskov Substitution Principle

Child classes should be usable wherever parent class is expected.

### I: Interface Segregation Principle

Do not force classes to implement methods they do not need.

### D: Dependency Inversion Principle

High-level code should depend on abstractions, not concrete classes.

### SOLID C++ Example

```cpp
class PaymentMethod {
public:
    virtual bool pay(double amount) = 0;
    virtual ~PaymentMethod() = default;
};

class CreditCardPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        cout << "Paid " << amount << " by credit card\n";
        return true;
    }
};

class UpiPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        cout << "Paid " << amount << " by UPI\n";
        return true;
    }
};

class CheckoutService {
    PaymentMethod& payment;

public:
    CheckoutService(PaymentMethod& payment) : payment(payment) {}

    bool checkout(double amount) {
        return payment.pay(amount);
    }
};
```

Why this is good:

- Add `WalletPayment` without changing `CheckoutService`.
- Easy to test with mock payment.
- High-level service depends on abstraction.

## 5.2 Strategy Pattern

### When to Use

Use when you need to switch algorithms at runtime.

Examples:

- payment method
- sorting strategy
- route calculation
- pricing strategy

```cpp
class PricingStrategy {
public:
    virtual double price(double base) = 0;
    virtual ~PricingStrategy() = default;
};

class RegularPricing : public PricingStrategy {
public:
    double price(double base) override { return base; }
};

class DiscountPricing : public PricingStrategy {
public:
    double price(double base) override { return base * 0.8; }
};

class Cart {
    PricingStrategy& strategy;

public:
    Cart(PricingStrategy& strategy) : strategy(strategy) {}
    double finalPrice(double base) { return strategy.price(base); }
};
```

## 5.3 Factory Pattern

### When to Use

Use when object creation depends on input or configuration.

```cpp
class Notification {
public:
    virtual void send(const string& msg) = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const string& msg) override { cout << "Email: " << msg << "\n"; }
};

class SmsNotification : public Notification {
public:
    void send(const string& msg) override { cout << "SMS: " << msg << "\n"; }
};

class NotificationFactory {
public:
    static unique_ptr<Notification> create(const string& type) {
        if (type == "email") return make_unique<EmailNotification>();
        if (type == "sms") return make_unique<SmsNotification>();
        throw invalid_argument("unknown notification type");
    }
};
```

## 5.4 Observer Pattern

### When to Use

Use when many objects need to react to an event.

Examples:

- order status updates
- pub-sub
- UI listeners
- notification systems

```cpp
class Observer {
public:
    virtual void update(const string& event) = 0;
    virtual ~Observer() = default;
};

class EmailObserver : public Observer {
public:
    void update(const string& event) override {
        cout << "Email received event: " << event << "\n";
    }
};

class Subject {
    vector<Observer*> observers;

public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void notify(const string& event) {
        for (auto* obs : observers) obs->update(event);
    }
};
```

## 5.5 Singleton Pattern

### When to Use

Use rarely. It can be useful for one shared config or logger, but it can make testing harder.

```cpp
class Logger {
    Logger() = default;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    void log(const string& msg) {
        cout << "[LOG] " << msg << "\n";
    }
};
```

## 5.6 Decorator Pattern

### When to Use

Use to add behavior without changing the original class.

```cpp
class DataSource {
public:
    virtual string read() = 0;
    virtual void write(const string& data) = 0;
    virtual ~DataSource() = default;
};

class FileDataSource : public DataSource {
    string data;

public:
    string read() override { return data; }
    void write(const string& d) override { data = d; }
};

class CompressionDecorator : public DataSource {
    DataSource& source;

public:
    CompressionDecorator(DataSource& source) : source(source) {}
    string read() override {
        return "decompressed(" + source.read() + ")";
    }
    void write(const string& data) override {
        source.write("compressed(" + data + ")");
    }
};
```

## 5.7 Adapter Pattern

### When to Use

Use when an existing class has the wrong interface.

```cpp
class OldPrinter {
public:
    void printOld(const string& text) {
        cout << text << "\n";
    }
};

class Printer {
public:
    virtual void print(const string& text) = 0;
    virtual ~Printer() = default;
};

class PrinterAdapter : public Printer {
    OldPrinter& oldPrinter;

public:
    PrinterAdapter(OldPrinter& oldPrinter) : oldPrinter(oldPrinter) {}
    void print(const string& text) override {
        oldPrinter.printOld(text);
    }
};
```

## 5.8 Builder Pattern

### When to Use

Use when object construction has many optional fields.

```cpp
class HttpRequest {
public:
    string url;
    string method = "GET";
    map<string, string> headers;
    string body;
};

class HttpRequestBuilder {
    HttpRequest req;

public:
    HttpRequestBuilder& url(const string& u) {
        req.url = u;
        return *this;
    }

    HttpRequestBuilder& method(const string& m) {
        req.method = m;
        return *this;
    }

    HttpRequestBuilder& header(const string& k, const string& v) {
        req.headers[k] = v;
        return *this;
    }

    HttpRequestBuilder& body(const string& b) {
        req.body = b;
        return *this;
    }

    HttpRequest build() {
        return req;
    }
};
```

## 5.9 Command Pattern

### When to Use

Use when you want to store, queue, retry, undo, or log operations.

```cpp
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class SendEmailCommand : public Command {
    string to, body;

public:
    SendEmailCommand(string to, string body) : to(move(to)), body(move(body)) {}

    void execute() override {
        cout << "Sending email to " << to << ": " << body << "\n";
    }
};

class CommandQueue {
    queue<unique_ptr<Command>> q;

public:
    void push(unique_ptr<Command> cmd) {
        q.push(move(cmd));
    }

    void run() {
        while (!q.empty()) {
            q.front()->execute();
            q.pop();
        }
    }
};
```

## 5.10 Pattern Selection Guide

| Need | Pattern |
|---|---|
| switch algorithms | Strategy |
| create object by type | Factory |
| notify many listeners | Observer |
| one shared instance | Singleton |
| add behavior dynamically | Decorator |
| convert interface | Adapter |
| construct complex object | Builder |
| queue/retry/undo operation | Command |

---

## 6. Real-World Case Studies

## 6.1 URL Shortener

### Requirements

Functional:

- Create short URL.
- Redirect short URL to long URL.
- Optional expiry.
- Optional analytics.

Non-functional:

- Very low redirect latency.
- High availability.
- Read-heavy.

### APIs

```text
POST /shorten
GET /{code}
```

### Data Model

```text
short_code | long_url | created_at | expires_at | user_id
```

### Design

```text
Client -> Load Balancer -> API Servers -> Cache -> Database
                                  |
                                  -> Analytics Queue -> Workers
```

### Key Decisions

- Use cache for popular short codes.
- Use base62 short codes.
- Use DB unique constraint on code.
- Analytics should be async.

### Failures and Fixes

| Failure | Fix |
|---|---|
| hot URL overloads DB | cache |
| analytics slows redirect | queue |
| generated code collision | retry or unique ID generator |
| DB primary fails | replication and failover |

### Interview Follow-Ups

**Q: How do you generate short codes?**

Use auto-increment ID converted to base62, or random code with collision check. Auto-increment is simple but predictable. Random is harder to guess but needs collision handling.

## 6.2 Chat Application

### Requirements

- One-to-one chat.
- Group chat.
- Message delivery status.
- Online/offline users.
- Push notifications.

### Design

```text
Client -> WebSocket Gateway -> Chat Service -> Message Store
                                  |
                                  -> Queue -> Push Notification Service
```

### Concepts Applied

- WebSocket for real-time connection.
- Persistent storage for messages.
- Queue for offline push notifications.
- Cache for online user presence.
- Partition messages by conversation ID.

### Trade-Offs

| Choice | Benefit | Cost |
|---|---|---|
| WebSocket | real time | connection scaling |
| Polling | simple | higher latency and waste |
| Store before send | reliable | slightly more latency |
| Send before store | fast | possible message loss |

## 6.3 News Feed

### Requirements

- Users follow other users.
- Users create posts.
- Home feed shows recent relevant posts.

### Fanout Models

| Model | How it works | Good for | Problem |
|---|---|---|---|
| Fanout on write | push post to follower feeds when created | fast reads | expensive for celebrity users |
| Fanout on read | build feed when user opens app | cheap writes | slower reads |
| Hybrid | push for normal users, pull for celebrities | practical large systems | more complexity |

### Design

```text
Post Service -> Feed Fanout Queue -> Feed Workers -> Feed Cache/Store
User -> Feed API -> Feed Cache -> Post Store
```

### Concepts Applied

- cache feed pages
- queue fanout work
- denormalize feed entries
- handle celebrity users separately
- eventual consistency is acceptable

## 6.4 Video Streaming Platform

### Requirements

- Upload video.
- Transcode into formats.
- Stream video globally.
- Show metadata and recommendations.

### Design

```text
Uploader -> Upload Service -> Object Storage -> Transcode Queue -> Workers
                                             -> CDN
Client -> CDN -> Video Segments
Client -> Metadata API -> Metadata DB
```

### Concepts Applied

- object storage for large files
- queue for transcoding
- CDN for global delivery
- metadata in database
- async processing

### Failure Cases

| Failure | Fix |
|---|---|
| transcoding fails | retry and dead-letter queue |
| CDN stale content | versioned URLs |
| upload interrupted | multipart upload |
| origin overloaded | CDN caching |

## 6.5 Ride Sharing

### Requirements

- Riders request rides.
- Drivers share location.
- Match rider with nearby driver.
- Track trip.
- Payments.

### Design

```text
Driver App -> Location Service -> Geo Index
Rider App -> Matching Service -> Nearby Drivers
Trip Service -> Payment Service
```

### Concepts Applied

- geospatial indexing
- high write volume for driver location
- matching service
- event-driven trip updates
- strong consistency for payments

### Trade-Offs

| Choice | Benefit | Cost |
|---|---|---|
| frequent location updates | accurate matching | high write load |
| less frequent updates | cheaper | less accurate |
| nearest driver only | simple | may overload one driver |
| ranked matching | better | more complex |

## 6.6 E-Commerce Checkout

### Requirements

- Browse products.
- Add to cart.
- Place order.
- Pay.
- Reduce inventory.

### Design

```text
Client -> API Gateway -> Cart Service
                    -> Order Service -> Payment Service
                    -> Inventory Service
                    -> Notification Queue
```

### Consistency Choices

- Cart can be eventually consistent.
- Payment must be strongly consistent.
- Inventory should prevent overselling.
- Emails can be async.

### Saga Example

1. Create order pending.
2. Reserve inventory.
3. Charge payment.
4. Confirm order.
5. If payment fails, release inventory.

---

## 7. Interview Questions and Answers

## 7.1 Beginner Questions

**Q: How do you start a system design interview?**

Clarify requirements first. Ask about users, traffic, core features, latency, availability, consistency, and constraints.

**Q: What is a load balancer?**

A component that distributes traffic across multiple servers so no single server takes all requests.

**Q: What is caching?**

Caching stores frequently used data in a fast layer to reduce latency and database load.

**Q: What is a database index?**

An index is a data structure that speeds up reads for selected columns, but it adds storage and slows writes.

## 7.2 Intermediate Questions

**Q: Cache-aside vs write-through?**

Cache-aside means the app reads cache first, then DB on miss, and writes DB directly. Write-through writes cache and DB together. Cache-aside is common and flexible; write-through gives better cache consistency but slower writes.

**Q: Sharding vs replication?**

Sharding splits different data across machines. Replication copies the same data across machines.

**Q: How do you choose a shard key?**

Choose a key that spreads data evenly, appears in common queries, avoids hot partitions, and rarely changes.

**Q: Why use a message queue?**

To decouple services, smooth traffic spikes, retry failed work, and move slow tasks outside the user request path.

**Q: What is eventual consistency?**

It means replicas may temporarily disagree, but if no new writes happen, they eventually converge.

## 7.3 Advanced Questions

**Q: How do you handle duplicate events?**

Use idempotent handlers, message IDs, deduplication storage, and safe retry logic.

**Q: How do you prevent cache stampede?**

Use locks, request coalescing, jittered TTL, stale-while-revalidate, and background refresh.

**Q: What is circuit breaker pattern?**

It stops calling a failing dependency temporarily so failures do not cascade. After a timeout, it allows limited trial requests.

**Q: How do you design for disaster recovery?**

Use backups, multi-zone or multi-region replication, tested restore procedures, runbooks, and clear RPO/RTO targets.

**Q: What are RPO and RTO?**

RPO is how much data loss is acceptable. RTO is how long recovery can take.

## 7.4 LLD Questions

**Q: How do you design extensible payment logic?**

Use a `PaymentMethod` interface and concrete classes like `CreditCardPayment`, `WalletPayment`, and `UpiPayment`. The checkout service depends on the interface.

**Q: When should you use Strategy pattern?**

When multiple algorithms can solve the same task and the algorithm should be swappable.

**Q: Why is Singleton often discouraged?**

It creates global state, makes tests harder, and can hide dependencies. Use dependency injection when possible.

**Q: How do you make code easier to test?**

Depend on interfaces, separate responsibilities, avoid global state, inject dependencies, and keep business logic away from infrastructure code.

---

## 8. Summary and Revision Notes

### Final System Design Flow

1. Clarify functional requirements.
2. Clarify non-functional requirements.
3. Estimate scale.
4. Define APIs.
5. Design data model.
6. Draw high-level components.
7. Explain request flows.
8. Identify bottlenecks.
9. Add cache, queue, replication, sharding, and load balancing where needed.
10. Discuss consistency, reliability, and failure handling.
11. Discuss monitoring, security, and trade-offs.

### HLD Revision Table

| Need | Use |
|---|---|
| distribute traffic | load balancer |
| reduce read latency | cache |
| handle async work | queue |
| scale reads | read replicas |
| scale writes/data size | sharding |
| global static content | CDN |
| find text | search index |
| protect service | rate limiter |
| avoid duplicate side effects | idempotency key |
| recover from failure | retry, backup, failover |

### LLD Revision Table

| Need | Use |
|---|---|
| hide implementation | interface/abstraction |
| one class one job | Single Responsibility Principle |
| add behavior without modifying old code | Open/Closed Principle |
| switch algorithm | Strategy |
| create object by type | Factory |
| notify listeners | Observer |
| add wrapper behavior | Decorator |
| convert old interface | Adapter |
| build complex object | Builder |
| queue operation | Command |

### Common Design Mistakes

- No requirement clarification.
- No scale estimation.
- No data model.
- No failure handling.
- Overusing microservices.
- Using cache without invalidation.
- Sharding without shard key.
- Ignoring hot keys.
- Ignoring monitoring.
- Ignoring security.
- Giving only buzzwords without trade-offs.

### Short Answers for Final Revision

**Scalability:** ability to handle more load.

**Availability:** ability to stay accessible.

**Reliability:** ability to work correctly over time.

**Fault tolerance:** ability to continue despite failures.

**Replication:** copy same data to multiple nodes.

**Sharding:** split different data across nodes.

**Cache:** fast temporary storage for hot data.

**Queue:** async buffer between producer and consumer.

**Load balancer:** distributes requests across servers.

**CDN:** caches content near users.

**Index:** speeds reads but slows writes.

**Strong consistency:** reads see latest write.

**Eventual consistency:** replicas converge later.

**Idempotency:** repeating request has same effect.

**Circuit breaker:** stops calls to failing dependency.

**Rate limiter:** controls request frequency.

**Design pattern:** reusable solution to common code design problem.

### Practice Plan

1. Design URL shortener.
2. Design rate limiter.
3. Design chat app.
4. Design news feed.
5. Design video streaming platform.
6. Design e-commerce checkout.
7. Design ride sharing app.
8. Design notification system.
9. Design file storage system.
10. Design search autocomplete.

For each design, write:

- requirements
- APIs
- database schema
- architecture
- bottlenecks
- failure cases
- trade-offs
- monitoring metrics
- security concerns
