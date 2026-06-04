# Complete Python Handbook: Beginner to Professional

This handbook teaches Python from the first principles of programming through professional, real-world Python work. It uses Python 3.12+ style and focuses on clarity, examples, practice, and habits that transfer to real projects.

## Table of Contents

1. [How To Use This Handbook](#how-to-use-this-handbook)
2. [Beginner Python](#beginner-python)
   - [What Is Python?](#what-is-python)
   - [Installing Python](#installing-python)
   - [Running Python Programs](#running-python-programs)
   - [Python IDEs](#python-ides)
   - [Variables](#variables)
   - [Basic Data Types](#basic-data-types)
   - [Type Checking And Type Conversion](#type-checking-and-type-conversion)
   - [Input And Output](#input-and-output)
   - [Comments](#comments)
   - [Operators](#operators)
   - [Strings](#strings)
   - [Conditional Statements](#conditional-statements)
   - [Loops](#loops)
   - [Basic Data Structures](#basic-data-structures)
   - [Functions](#functions)
   - [Scope](#scope)
   - [Beginner Mini Projects](#beginner-mini-projects)
   - [Beginner Interview Questions](#beginner-interview-questions)
3. [Intermediate Python](#intermediate-python)
   - [Error Handling](#error-handling)
   - [File Handling](#file-handling)
   - [Modules And Packages](#modules-and-packages)
   - [pip And Virtual Environments](#pip-and-virtual-environments)
   - [Object-Oriented Programming](#object-oriented-programming)
   - [Comprehensions](#comprehensions)
   - [Lambda, map, filter, And reduce](#lambda-map-filter-and-reduce)
   - [Iterators And Generators](#iterators-and-generators)
   - [Decorators](#decorators)
   - [Context Managers](#context-managers)
   - [Dates And Times](#dates-and-times)
   - [Regular Expressions](#regular-expressions)
   - [Type Hints](#type-hints)
   - [Dataclasses](#dataclasses)
   - [Enum](#enum)
   - [collections Module](#collections-module)
   - [pathlib, os, And sys](#pathlib-os-and-sys)
   - [Intermediate Mini Projects](#intermediate-mini-projects)
   - [Intermediate Interview Questions](#intermediate-interview-questions)
4. [Advanced Python](#advanced-python)
   - [Advanced OOP Design](#advanced-oop-design)
   - [SOLID Principles In Python](#solid-principles-in-python)
   - [Design Patterns In Python](#design-patterns-in-python)
   - [Functional Programming Concepts](#functional-programming-concepts)
   - [Closures](#closures)
   - [Advanced Decorators](#advanced-decorators)
   - [Metaclasses](#metaclasses)
   - [Descriptors](#descriptors)
   - [Properties](#properties)
   - [Memory Management](#memory-management)
   - [Garbage Collection](#garbage-collection)
   - [Copy Vs deepcopy](#copy-vs-deepcopy)
   - [Mutability And Immutability](#mutability-and-immutability)
   - [Python Internals](#python-internals)
   - [Concurrency And Parallelism](#concurrency-and-parallelism)
   - [Networking](#networking)
   - [Databases](#databases)
   - [Testing](#testing)
   - [Debugging](#debugging)
   - [Logging](#logging)
   - [Performance Optimization](#performance-optimization)
   - [Packaging Python Projects](#packaging-python-projects)
   - [Command-Line Tools](#command-line-tools)
   - [Environment Variables And Configuration](#environment-variables-and-configuration)
   - [Security Basics](#security-basics)
   - [Advanced Mini Projects](#advanced-mini-projects)
   - [Advanced Interview Questions](#advanced-interview-questions)
5. [Professional And Real-World Python](#professional-and-real-world-python)
   - [Web Development Overview](#web-development-overview)
   - [Data Science Overview](#data-science-overview)
   - [Automation Scripts](#automation-scripts)
   - [Web Scraping](#web-scraping)
   - [API Development](#api-development)
   - [Building CLI Apps](#building-cli-apps)
   - [Working With Excel Files](#working-with-excel-files)
   - [Working With PDFs](#working-with-pdfs)
   - [Sending Emails With Python](#sending-emails-with-python)
   - [Building Bots](#building-bots)
   - [Deployment Basics](#deployment-basics)
   - [Docker Basics For Python](#docker-basics-for-python)
   - [Git And GitHub Basics](#git-and-github-basics)
   - [Code Formatting And Linting](#code-formatting-and-linting)
   - [Project Structure Best Practices](#project-structure-best-practices)
   - [Real-World Projects](#real-world-projects)
   - [Professional Interview Questions](#professional-interview-questions)
6. [Final Job-Ready Roadmap](#final-job-ready-roadmap)

## How To Use This Handbook

Learn in passes.

1. First pass: read the explanations and run every small code example.
2. Second pass: solve the exercises without looking at solutions.
3. Third pass: build the projects and modify them.
4. Fourth pass: write tests, add logging, clean the structure, and publish the best projects on GitHub.

Every topic is taught with the same practical questions:

- What it means
- Why it matters
- Syntax
- Simple example
- Real-world example
- Common mistakes
- Best practices
- Practice exercises
- Solutions where useful

Use Python 3.12 or newer if possible. Most examples also work in slightly older Python 3 versions, but the handbook assumes modern Python habits.

---

# Beginner Python

Beginner Python is about learning how to think like a programmer: store values, make decisions, repeat actions, group data, and break work into functions.

## What Is Python?

### What It Means

Python is a high-level, general-purpose programming language. "High-level" means Python lets you write code close to human language compared with lower-level languages. "General-purpose" means it can be used for web apps, scripts, automation, data analysis, machine learning, testing, APIs, command-line tools, and more.

### Why It Is Important

Python is popular because it is readable, has a huge ecosystem, and lets beginners become productive quickly. Professional teams use Python because it is excellent for glue code, backend services, data workflows, testing, and automation.

### Syntax

Python uses indentation to define blocks:

```python
if True:
    print("This line belongs to the if block")
```

### Simple Example

```python
print("Hello, Python!")
```

Line by line:

- `print` is a built-in function.
- `"Hello, Python!"` is text, also called a string.
- The function displays the text on the screen.

### Real-World Example

```python
customer_name = "Asha"
order_total = 1299.50

print(f"Invoice for {customer_name}: Rs. {order_total}")
```

This resembles a tiny part of a billing system.

### Common Mistakes

- Thinking Python is only for beginners. It is beginner-friendly, but also professional-grade.
- Ignoring indentation. In Python, indentation is part of the program structure.
- Copying code without running and changing it.

### Best Practices

- Read code aloud: Python should usually be understandable.
- Write small programs often.
- Use meaningful names like `order_total`, not vague names like `x`.

### Practice Exercises

1. Print your name.
2. Print three facts about Python.
3. Create a variable called `favorite_language` and print it.

### Solutions

```python
print("Yash")
print("Python is readable.")
print("Python is used in web development.")
print("Python is used in data science.")

favorite_language = "Python"
print(favorite_language)
```

## Installing Python

### What It Means

Installing Python puts the Python interpreter on your computer. The interpreter reads and executes Python code.

### Why It Is Important

Without Python installed, your computer cannot run `.py` files directly. A correct setup also gives you `pip`, the package installer.

### Basic Steps

1. Download Python 3.12+ from the official Python website.
2. On Windows, enable "Add Python to PATH" during installation.
3. Open a terminal and check:

```powershell
python --version
pip --version
```

On some systems the command is:

```bash
python3 --version
pip3 --version
```

### Common Mistakes

- Installing Python but not adding it to PATH on Windows.
- Having multiple Python versions and using the wrong one.
- Installing packages globally instead of inside a virtual environment.

### Best Practices

- Use Python 3.12+ for new learning.
- Use a virtual environment for each project.
- Learn to run Python from the terminal, not only from an IDE button.

### Practice Exercises

1. Check your Python version.
2. Check your pip version.
3. Create a file named `hello.py` and run it.

## Running Python Programs

### What It Means

You can run Python interactively or from a script file.

### Why It Is Important

Interactive mode is good for experiments. Script files are good for saved programs.

### Syntax

Run a file:

```bash
python hello.py
```

Open interactive mode:

```bash
python
```

### Simple Example

Create `hello.py`:

```python
print("Hello from a Python file")
```

Run it:

```bash
python hello.py
```

### Real-World Example

Create `daily_report.py`:

```python
from datetime import date

print(f"Daily report for {date.today()}")
print("No incidents reported.")
```

### Common Mistakes

- Saving the file as `hello.py.txt`.
- Running the command from the wrong folder.
- Naming a file after a standard library module, such as `json.py` or `random.py`.

### Best Practices

- Keep file names lowercase with underscores: `daily_report.py`.
- Run scripts from the terminal to understand paths.
- Keep beginner scripts small.

### Practice Exercises

1. Create `about_me.py`.
2. Print your name, city, and goal.
3. Run it from the terminal.

## Python IDEs

### What It Means

An IDE or editor helps you write code. Common choices:

- VS Code: lightweight, popular, flexible.
- PyCharm: powerful Python IDE.
- Jupyter Notebook: interactive notebooks for data science, teaching, and experiments.

### Why It Is Important

Good tools catch errors early, format code, show documentation, and speed up learning.

### Simple Example

In VS Code:

1. Open a folder.
2. Create `main.py`.
3. Select the Python interpreter.
4. Run the file in the terminal.

### Real-World Example

Professional teams often use:

- VS Code or PyCharm for application code.
- Jupyter for data exploration.
- Terminal commands for tests and deployment.

### Common Mistakes

- Depending only on the green Run button.
- Not knowing which interpreter the IDE is using.
- Keeping all files on the desktop instead of inside project folders.

### Best Practices

- Learn the terminal basics.
- Use formatting tools like `black` or `ruff format`.
- Create one folder per project.

### Practice Exercises

1. Install a Python extension in your editor.
2. Create and run a Python file.
3. Change the interpreter and observe what happens.

## Variables

### What It Means

A variable is a name that refers to a value.

### Why It Is Important

Variables let programs remember information and reuse it.

### Syntax

```python
name = value
```

### Simple Example

```python
age = 21
print(age)
```

Line by line:

- `age` is the variable name.
- `=` assigns the value on the right to the name on the left.
- `21` is an integer.
- `print(age)` displays the value stored in `age`.

### Real-World Example

```python
unit_price = 499
quantity = 3
total_price = unit_price * quantity

print(f"Total: Rs. {total_price}")
```

### Common Mistakes

- Using `=` when you mean comparison. `=` assigns; `==` compares.
- Using unclear names such as `a`, `b`, `temp2`.
- Starting variable names with numbers.

### Best Practices

- Use lowercase names with underscores: `total_price`.
- Name values after their meaning, not their type: `customer_name`, not `string1`.
- Keep variables close to where they are used.

### Practice Exercises

1. Store your name and age in variables.
2. Store two prices and calculate their total.
3. Change a variable after assigning it.

### Solutions

```python
name = "Riya"
age = 22
print(name, age)

price_one = 100
price_two = 250
total = price_one + price_two
print(total)

status = "pending"
status = "complete"
print(status)
```

## Basic Data Types

### What It Means

A data type tells Python what kind of value something is.

Core beginner types:

- `int`: whole numbers, such as `10`
- `float`: decimal numbers, such as `10.5`
- `str`: text, such as `"hello"`
- `bool`: truth values, `True` or `False`
- `None`: absence of a value

### Why It Is Important

Different types support different operations. You can add numbers, join strings, test booleans, and use `None` for missing data.

### Syntax

```python
age = 30
price = 99.99
name = "Meera"
is_active = True
middle_name = None
```

### Simple Example

```python
students = 35
average_score = 82.5
course = "Python"
is_open = True
next_batch = None

print(students)
print(average_score)
print(course)
print(is_open)
print(next_batch)
```

Line by line:

- `students` stores an integer count.
- `average_score` stores a decimal.
- `course` stores text.
- `is_open` stores a boolean.
- `next_batch` stores no value yet.

### Real-World Example

```python
product = "Wireless Mouse"
stock = 42
price = 799.0
is_available = stock > 0
discount_code = None

print(f"{product}: Rs. {price}, available: {is_available}")
```

### Common Mistakes

- Writing `true` instead of `True`.
- Writing `none` instead of `None`.
- Mixing strings and numbers in arithmetic.

### Best Practices

- Use booleans for yes/no state: `is_logged_in`, `has_access`.
- Use `None` when a value is intentionally missing.
- Convert user input before doing numeric calculations.

### Practice Exercises

1. Create one variable for each basic type.
2. Print each value and its type.
3. Create a boolean expression using comparison.

### Solutions

```python
city = "Pune"
population = 7_000_000
temperature = 31.5
is_capital = False
airport_code = None

print(type(city))
print(type(population))
print(type(temperature))
print(type(is_capital))
print(type(airport_code))

is_hot = temperature > 30
print(is_hot)
```

## Type Checking And Type Conversion

### What It Means

Type checking means finding a value's type. Type conversion means changing a value from one type to another.

### Why It Is Important

Input usually arrives as text. APIs and files often contain strings that must be converted into numbers, dates, booleans, or structured data.

### Syntax

```python
type(value)
int(value)
float(value)
str(value)
bool(value)
```

### Simple Example

```python
age_text = "25"
age_number = int(age_text)

print(age_number + 5)
```

Line by line:

- `age_text` is a string because it is inside quotes.
- `int(age_text)` converts `"25"` to `25`.
- Now Python can add `25 + 5`.

### Real-World Example

```python
price_text = "1499.50"
quantity_text = "2"

price = float(price_text)
quantity = int(quantity_text)
total = price * quantity

print(f"Total bill: Rs. {total}")
```

### Common Mistakes

- Trying `int("10.5")`, which raises `ValueError`.
- Assuming `bool("False")` becomes `False`. Non-empty strings are truthy.
- Forgetting that `input()` always returns a string.

### Best Practices

- Convert as soon as you receive input.
- Validate before converting when data may be messy.
- Use clear names like `age_text` before conversion and `age` after conversion.

### Practice Exercises

1. Convert `"100"` to an integer.
2. Convert `"45.75"` to a float.
3. Ask for two numbers and print their sum.

### Solutions

```python
number = int("100")
price = float("45.75")

first = float(input("First number: "))
second = float(input("Second number: "))
print(first + second)
```

## Input And Output

### What It Means

Input receives information from the user. Output displays information.

### Why It Is Important

Most programs interact with users, files, databases, APIs, or other systems. `input()` and `print()` are the beginner version of that interaction.

### Syntax

```python
name = input("Prompt text: ")
print("Output text")
```

### Simple Example

```python
name = input("What is your name? ")
print(f"Hello, {name}!")
```

Line by line:

- `input(...)` displays a question and waits.
- The user's answer is stored in `name`.
- `f"Hello, {name}!"` inserts the variable into the string.
- `print(...)` displays the greeting.

### Real-World Example

```python
hours = float(input("Hours worked: "))
rate = float(input("Hourly rate: "))
pay = hours * rate

print(f"Gross pay: Rs. {pay:.2f}")
```

### Common Mistakes

- Forgetting to convert input before math.
- Putting too much logic inside `print()`.
- Not making prompts clear.

### Best Practices

- Use clear prompts.
- Convert and validate input.
- Format money and decimals with format specifiers such as `{pay:.2f}`.

### Practice Exercises

1. Ask for a name and print a greeting.
2. Ask for birth year and estimate age.
3. Ask for item price and quantity, then print total.

## Comments

### What It Means

Comments are notes in code that Python ignores.

### Why It Is Important

Comments explain why code exists, especially when logic is not obvious.

### Syntax

```python
# This is a single-line comment
```

Docstrings document modules, classes, and functions:

```python
def greet(name: str) -> str:
    """Return a friendly greeting."""
    return f"Hello, {name}"
```

### Simple Example

```python
# Convert minutes to seconds
minutes = 5
seconds = minutes * 60
print(seconds)
```

### Real-World Example

```python
# Apply free shipping only after discounts.
subtotal = 1200
discount = 100
final_amount = subtotal - discount
has_free_shipping = final_amount >= 1000
```

### Common Mistakes

- Commenting the obvious: `# add 1` above `count += 1`.
- Leaving outdated comments after code changes.
- Using comments instead of clear names.

### Best Practices

- Explain why, not what.
- Prefer good names over excessive comments.
- Use docstrings for functions that others will call.

### Practice Exercises

1. Add comments to a temperature conversion script.
2. Write a function with a docstring.
3. Remove comments that repeat obvious code.

## Operators

Operators perform actions on values.

### Arithmetic Operators

#### What It Means

Arithmetic operators do math.

#### Why It Is Important

They are used in billing, scoring, reports, measurements, statistics, and many business rules.

#### Syntax

```python
a + b   # addition
a - b   # subtraction
a * b   # multiplication
a / b   # true division
a // b  # floor division
a % b   # remainder
a ** b  # exponent
```

#### Simple Example

```python
length = 10
width = 5
area = length * width
print(area)
```

Line by line:

- `length` stores one side of a rectangle.
- `width` stores the other side.
- `length * width` multiplies them.
- `area` stores the result.

#### Real-World Example

```python
cart_total = 2500
tax_rate = 0.18
tax = cart_total * tax_rate
grand_total = cart_total + tax

print(f"Grand total: Rs. {grand_total:.2f}")
```

#### Common Mistakes

- Expecting `/` to return an integer.
- Forgetting operator precedence.
- Dividing by zero.

#### Best Practices

- Use parentheses when it improves readability.
- Use meaningful names for intermediate calculations.
- Use `decimal.Decimal` for serious financial calculations.

#### Exercises

1. Calculate the area of a circle.
2. Convert Celsius to Fahrenheit.
3. Calculate simple interest.

#### Solutions

```python
radius = 5
area = 3.14159 * radius ** 2
print(area)

celsius = 30
fahrenheit = (celsius * 9 / 5) + 32
print(fahrenheit)

principal = 10_000
rate = 0.08
years = 2
interest = principal * rate * years
print(interest)
```

### Comparison Operators

#### What It Means

Comparison operators compare values and return `True` or `False`.

#### Syntax

```python
a == b
a != b
a > b
a < b
a >= b
a <= b
```

#### Simple Example

```python
age = 19
is_adult = age >= 18
print(is_adult)
```

#### Real-World Example

```python
stock = 3
requested_quantity = 5

if requested_quantity > stock:
    print("Not enough stock")
else:
    print("Order can be placed")
```

#### Common Mistakes

- Using `=` instead of `==`.
- Comparing unrelated types.
- Comparing floating-point values for exact equality.

#### Best Practices

- Store complex conditions in named booleans.
- Use chained comparisons when natural: `18 <= age <= 65`.
- Be careful with decimal precision.

### Logical Operators

#### What It Means

Logical operators combine boolean expressions.

#### Syntax

```python
condition_a and condition_b
condition_a or condition_b
not condition_a
```

#### Simple Example

```python
age = 25
has_id = True

can_enter = age >= 18 and has_id
print(can_enter)
```

#### Real-World Example

```python
is_admin = False
is_owner = True
account_active = True

can_edit = account_active and (is_admin or is_owner)
print(can_edit)
```

#### Common Mistakes

- Writing English-like conditions incorrectly: `age > 18 and < 65`.
- Forgetting parentheses in mixed `and` and `or` expressions.
- Confusing truthy values with actual `True`.

#### Best Practices

- Use parentheses to clarify mixed logic.
- Prefer readable named conditions over one long line.
- Avoid double negatives where possible.

### Assignment Operators

#### What It Means

Assignment operators update variables.

#### Syntax

```python
x = 10
x += 5
x -= 2
x *= 3
x /= 2
```

#### Example

```python
score = 0
score += 10
score += 5
print(score)
```

#### Real-World Example

```python
balance = 5000
withdrawal = 1200
balance -= withdrawal
print(balance)
```

#### Common Mistakes

- Using assignment before defining a variable.
- Accidentally changing a value that should stay constant.

#### Best Practices

- Use `+=` for counters and accumulators.
- Keep important constants in uppercase names: `TAX_RATE = 0.18`.

### Membership Operators

#### What It Means

Membership operators test whether a value exists inside a collection.

#### Syntax

```python
value in collection
value not in collection
```

#### Simple Example

```python
fruits = ["apple", "banana", "mango"]
print("mango" in fruits)
```

#### Real-World Example

```python
allowed_roles = {"admin", "manager"}
user_role = "manager"

if user_role in allowed_roles:
    print("Access granted")
```

#### Common Mistakes

- Using membership on the wrong level of nested data.
- Expecting case-insensitive matching.

#### Best Practices

- Use sets for fast membership checks.
- Normalize text before checking: `email.lower()`.

### Identity Operators

#### What It Means

Identity operators check whether two names refer to the exact same object.

#### Syntax

```python
a is b
a is not b
```

#### Simple Example

```python
value = None

if value is None:
    print("No value yet")
```

#### Real-World Example

```python
selected_user = None

if selected_user is not None:
    print("Show profile")
else:
    print("Ask user to log in")
```

#### Common Mistakes

- Using `is` to compare strings or numbers.
- Writing `value == None` instead of `value is None`.

#### Best Practices

- Use `is None` and `is not None` for `None`.
- Use `==` for value equality.

## Strings

### What It Means

A string is a sequence of characters.

### Why It Is Important

Programs process names, messages, emails, URLs, file paths, logs, commands, and user input as strings.

### Syntax

```python
name = "Python"
message = 'Hello'
multi_line = """This string
spans multiple lines."""
```

### Indexing

Indexing gets one character. Python indexes start at `0`.

```python
word = "Python"
print(word[0])   # P
print(word[-1])  # n
```

Line by line:

- `word[0]` gets the first character.
- `word[-1]` gets the last character.

### Slicing

Slicing gets part of a string.

```python
word = "Python"
print(word[0:3])  # Pyt
print(word[:2])   # Py
print(word[2:])   # thon
```

### String Methods

```python
text = "  python programming  "

print(text.strip())
print(text.upper())
print(text.title())
print(text.replace("python", "Python"))
print(text.strip().startswith("python"))
```

### f-strings

f-strings insert expressions inside strings.

```python
name = "Arjun"
score = 91.5
print(f"{name} scored {score:.1f}%")
```

### Escape Characters

```python
print("Line one\nLine two")
print("She said, \"Python is fun.\"")
print("C:\\Users\\Name")
```

### Real-World Example

```python
raw_email = "  USER@Example.COM "
email = raw_email.strip().lower()

if email.endswith("@example.com"):
    print(f"Internal user: {email}")
```

### Common Mistakes

- Forgetting strings are immutable. Methods return new strings.
- Off-by-one errors in slicing.
- Mixing quotes incorrectly.
- Forgetting that indexes start at `0`.

### Best Practices

- Use f-strings for readable formatting.
- Normalize input with `.strip()` and `.lower()` where appropriate.
- Use triple quotes for multiline text.

### Practice Exercises

1. Ask for a full name and print it in title case.
2. Extract the username from an email before `@`.
3. Count how many times `"a"` appears in a sentence.

### Solutions

```python
full_name = input("Full name: ").strip().title()
print(full_name)

email = "riya@example.com"
username = email.split("@")[0]
print(username)

sentence = "Data analysis and automation"
print(sentence.lower().count("a"))
```

## Conditional Statements

### What It Means

Conditional statements let a program choose between paths.

### Why It Is Important

Decision-making is everywhere: login checks, discounts, validation, permissions, game rules, and workflows.

### Syntax

```python
if condition:
    ...
elif another_condition:
    ...
else:
    ...
```

### Simple Example

```python
temperature = 35

if temperature > 30:
    print("It is hot")
elif temperature > 20:
    print("It is pleasant")
else:
    print("It is cool")
```

Line by line:

- Python checks `temperature > 30` first.
- If it is true, the first block runs.
- If not, Python checks `temperature > 20`.
- If no condition is true, the `else` block runs.

### Nested if

```python
is_logged_in = True
is_admin = False

if is_logged_in:
    if is_admin:
        print("Admin dashboard")
    else:
        print("User dashboard")
else:
    print("Please log in")
```

### Real-World Example

```python
cart_total = 1800
customer_type = "premium"

if customer_type == "premium" and cart_total >= 1000:
    discount = 0.15
elif cart_total >= 1000:
    discount = 0.10
else:
    discount = 0.0

final_total = cart_total * (1 - discount)
print(f"Final total: Rs. {final_total:.2f}")
```

### Common Mistakes

- Forgetting the colon after `if`, `elif`, or `else`.
- Incorrect indentation.
- Writing too many nested conditions instead of simplifying.

### Best Practices

- Put the most specific condition first.
- Use `elif` for mutually exclusive branches.
- Extract complex conditions into named variables.

### Practice Exercises

1. Check if a number is positive, negative, or zero.
2. Check if a password has at least 8 characters.
3. Create a grading program for marks.

### Solutions

```python
number = int(input("Number: "))

if number > 0:
    print("Positive")
elif number < 0:
    print("Negative")
else:
    print("Zero")
```

```python
marks = int(input("Marks: "))

if marks >= 90:
    grade = "A"
elif marks >= 75:
    grade = "B"
elif marks >= 60:
    grade = "C"
else:
    grade = "D"

print(grade)
```

## Loops

### What It Means

Loops repeat code.

### Why It Is Important

Loops process lists, retry actions, read files, run games, collect input, and automate repeated tasks.

### for Loop

Use a `for` loop when you know the collection or range to process.

```python
for item in collection:
    ...
```

Simple example:

```python
for number in range(1, 4):
    print(number)
```

Line by line:

- `range(1, 4)` produces `1`, `2`, `3`.
- `number` receives each value one at a time.
- The indented block runs for each value.

Real-world example:

```python
prices = [199, 499, 1299]
total = 0

for price in prices:
    total += price

print(f"Cart total: Rs. {total}")
```

### while Loop

Use a `while` loop when repetition depends on a condition.

```python
while condition:
    ...
```

Example:

```python
attempts = 0

while attempts < 3:
    print("Try logging in")
    attempts += 1
```

### break

`break` exits a loop.

```python
for number in range(1, 10):
    if number == 5:
        break
    print(number)
```

### continue

`continue` skips to the next iteration.

```python
for number in range(1, 6):
    if number == 3:
        continue
    print(number)
```

### pass

`pass` is a placeholder that does nothing.

```python
for item in []:
    pass
```

### Loop with else

The `else` block runs if the loop finishes without `break`.

```python
target = 7

for number in [1, 3, 5]:
    if number == target:
        print("Found")
        break
else:
    print("Not found")
```

### Common Mistakes

- Creating infinite `while` loops.
- Forgetting to update loop variables.
- Modifying a list while looping over it.
- Misunderstanding `range(stop)`, which stops before `stop`.

### Best Practices

- Prefer `for` loops for collections.
- Use `enumerate()` when you need an index.
- Use `break` and `continue` sparingly and clearly.

### Practice Exercises

1. Print numbers from 1 to 10.
2. Sum all numbers in a list.
3. Ask for input until the user types `quit`.
4. Find the first even number in a list.

### Solutions

```python
for number in range(1, 11):
    print(number)
```

```python
numbers = [5, 10, 15]
total = 0

for number in numbers:
    total += number

print(total)
```

```python
while True:
    command = input("Command: ")
    if command == "quit":
        break
    print(f"You typed: {command}")
```

## Basic Data Structures

Data structures organize multiple values.

## Lists

### What It Means

A list is an ordered, mutable collection.

### Why It Is Important

Lists are used for records, tasks, search results, rows, messages, and many other sequences.

### Syntax

```python
items = [value1, value2, value3]
```

### Simple Example

```python
fruits = ["apple", "banana", "mango"]
print(fruits[0])
fruits.append("orange")
print(fruits)
```

Line by line:

- `fruits` stores three strings.
- `fruits[0]` gets the first item.
- `.append("orange")` adds a new item at the end.

### List Methods

```python
numbers = [3, 1, 2]

numbers.append(4)
numbers.insert(0, 0)
numbers.remove(3)
last = numbers.pop()
numbers.sort()

print(numbers)
print(last)
```

### Real-World Example

```python
tasks = []
tasks.append("Pay electricity bill")
tasks.append("Submit report")

for index, task in enumerate(tasks, start=1):
    print(f"{index}. {task}")
```

### Common Mistakes

- Accessing an index that does not exist.
- Forgetting lists are mutable.
- Using a list when a set or dictionary would be better.

### Best Practices

- Use lists for ordered collections.
- Use `enumerate()` for index plus value.
- Avoid large nested lists when dictionaries or classes would be clearer.

### Practice Exercises

1. Create a list of five numbers.
2. Add a number.
3. Remove one number.
4. Print the average.

## Tuples

### What It Means

A tuple is an ordered, immutable collection.

### Why It Is Important

Tuples are useful for fixed groups of values, such as coordinates or rows that should not change.

### Syntax

```python
point = (10, 20)
```

### Simple Example

```python
location = ("Delhi", 28.61, 77.20)
print(location[0])
```

### Real-World Example

```python
def get_dimensions() -> tuple[int, int]:
    return (1920, 1080)

width, height = get_dimensions()
print(width, height)
```

### Common Mistakes

- Forgetting the comma for a single-item tuple: `(5,)`.
- Trying to change tuple items.

### Best Practices

- Use tuples for fixed-size records.
- Unpack tuples into meaningful names.

### Practice Exercise

Create a tuple representing `(name, age, city)` and unpack it.

## Sets

### What It Means

A set is an unordered collection of unique values.

### Why It Is Important

Sets remove duplicates and make membership checks fast.

### Syntax

```python
unique_items = {1, 2, 3}
empty_set = set()
```

### Simple Example

```python
names = {"Asha", "Ravi", "Asha"}
print(names)
```

### Set Operations

```python
python_students = {"Asha", "Ravi", "Meera"}
sql_students = {"Ravi", "Imran"}

print(python_students | sql_students)  # union
print(python_students & sql_students)  # intersection
print(python_students - sql_students)  # difference
```

### Real-World Example

```python
visited_pages = set()
visited_pages.add("/home")
visited_pages.add("/pricing")
visited_pages.add("/home")

print(len(visited_pages))
```

### Common Mistakes

- Expecting sets to keep order.
- Trying to store unhashable values like lists in a set.
- Using `{}` for an empty set. `{}` creates a dictionary.

### Best Practices

- Use sets for uniqueness.
- Convert a list to a set to remove duplicates.
- Use set operations for comparisons.

### Practice Exercise

Given two lists of email addresses, find common emails.

## Dictionaries

### What It Means

A dictionary stores key-value pairs.

### Why It Is Important

Dictionaries model real data: users, products, settings, API responses, counts, and lookups.

### Syntax

```python
person = {
    "name": "Anika",
    "age": 30,
}
```

### Simple Example

```python
student = {"name": "Kabir", "marks": 88}
print(student["name"])
student["grade"] = "A"
print(student)
```

Line by line:

- `student` maps keys to values.
- `student["name"]` gets the value for the key `"name"`.
- `student["grade"] = "A"` adds a new key-value pair.

### Dictionary Methods

```python
profile = {"name": "Sara", "city": "Mumbai"}

print(profile.get("name"))
print(profile.get("email", "Not provided"))
print(profile.keys())
print(profile.values())
print(profile.items())

profile.update({"city": "Bengaluru", "role": "developer"})
removed = profile.pop("role")
```

### Real-World Example

```python
inventory = {
    "notebook": 30,
    "pen": 100,
    "marker": 15,
}

item = "pen"
quantity = inventory.get(item, 0)

if quantity > 0:
    print(f"{item} is in stock")
```

### Common Mistakes

- Accessing a missing key with `dict[key]`, causing `KeyError`.
- Using mutable objects as keys.
- Creating deeply nested dictionaries without structure.

### Best Practices

- Use `.get()` when keys may be missing.
- Use clear key names.
- Consider dataclasses or classes for complex records.

### Practice Exercises

1. Create a contact dictionary.
2. Add an email.
3. Print all keys and values.
4. Count word frequency in a sentence.

### Solutions

```python
contact = {"name": "Nisha", "phone": "9999999999"}
contact["email"] = "nisha@example.com"

for key, value in contact.items():
    print(f"{key}: {value}")
```

```python
sentence = "python is fun and python is useful"
counts = {}

for word in sentence.split():
    counts[word] = counts.get(word, 0) + 1

print(counts)
```

## Functions

### What It Means

A function is a reusable block of code that performs a task.

### Why It Is Important

Functions reduce repetition, make code easier to test, and organize programs into meaningful pieces.

### Syntax

```python
def function_name(parameter1, parameter2):
    return result
```

### Defining Functions

```python
def greet():
    print("Hello")

greet()
```

Line by line:

- `def greet():` defines a function named `greet`.
- The indented line is the function body.
- `greet()` calls the function.

### Parameters And Arguments

Parameters are names in the function definition. Arguments are values passed during a call.

```python
def greet(name):
    print(f"Hello, {name}")

greet("Priya")
```

### Return Values

```python
def add(a, b):
    return a + b

result = add(10, 5)
print(result)
```

### Default Arguments

```python
def greet(name, greeting="Hello"):
    return f"{greeting}, {name}"

print(greet("Ravi"))
print(greet("Ravi", "Namaste"))
```

### Keyword Arguments

```python
def create_user(name, email, is_admin=False):
    return {"name": name, "email": email, "is_admin": is_admin}

user = create_user(email="a@example.com", name="Asha")
print(user)
```

### *args

`*args` collects extra positional arguments into a tuple.

```python
def add_all(*numbers):
    total = 0
    for number in numbers:
        total += number
    return total

print(add_all(1, 2, 3, 4))
```

### **kwargs

`**kwargs` collects extra keyword arguments into a dictionary.

```python
def build_profile(**details):
    return details

profile = build_profile(name="Ira", city="Chennai", role="analyst")
print(profile)
```

### Real-World Example

```python
def calculate_invoice_total(subtotal, tax_rate=0.18, discount=0):
    taxable_amount = subtotal - discount
    tax = taxable_amount * tax_rate
    return taxable_amount + tax

total = calculate_invoice_total(2000, discount=200)
print(f"Invoice total: Rs. {total:.2f}")
```

### Common Mistakes

- Forgetting to call the function with parentheses.
- Printing a value instead of returning it when another part of the program needs it.
- Using mutable default arguments like `items=[]`.
- Making one function do too many things.

### Best Practices

- Give functions verb-based names: `calculate_total`, `send_email`.
- Keep functions focused.
- Return values instead of only printing.
- Use type hints once you are comfortable.

### Practice Exercises

1. Write a function that returns the square of a number.
2. Write a function that checks whether a number is even.
3. Write a function that calculates final price after discount.
4. Write a function that accepts any number of marks and returns the average.

### Solutions

```python
def square(number):
    return number * number
```

```python
def is_even(number):
    return number % 2 == 0
```

```python
def final_price(price, discount_percent):
    discount = price * discount_percent / 100
    return price - discount
```

```python
def average(*marks):
    if not marks:
        return 0
    return sum(marks) / len(marks)
```

## Scope

### What It Means

Scope determines where a variable can be used.

### Why It Is Important

Understanding scope prevents accidental bugs and helps you design functions properly.

### Local Scope

A variable created inside a function is local to that function.

```python
def show_total():
    total = 100
    print(total)

show_total()
```

### Global Scope

A variable created outside functions is global.

```python
tax_rate = 0.18

def calculate_tax(amount):
    return amount * tax_rate
```

### global Keyword

`global` lets a function reassign a global variable. Use it rarely.

```python
count = 0

def increment():
    global count
    count += 1
```

### nonlocal Keyword

`nonlocal` lets an inner function reassign a variable from an enclosing function.

```python
def counter():
    count = 0

    def increment():
        nonlocal count
        count += 1
        return count

    return increment

next_count = counter()
print(next_count())
print(next_count())
```

### Real-World Example

```python
TAX_RATE = 0.18

def calculate_total(subtotal):
    tax = subtotal * TAX_RATE
    return subtotal + tax
```

### Common Mistakes

- Expecting local variables to exist outside a function.
- Modifying globals from many places.
- Shadowing built-in names like `list`, `dict`, or `str`.

### Best Practices

- Prefer passing values into functions and returning results.
- Use global constants for values that do not change.
- Avoid global mutable state.

### Practice Exercises

1. Create a global constant and use it in a function.
2. Show that a local variable cannot be used outside its function.
3. Build a simple closure counter.

## Beginner Mini Projects

### Project 1: Beginner Calculator

#### Goal

Build a command-line calculator that performs basic arithmetic.

#### Features

- Ask for two numbers.
- Ask for an operation.
- Support addition, subtraction, multiplication, and division.
- Handle division by zero.

#### Required Concepts

Variables, input, type conversion, conditionals, arithmetic operators, functions.

#### Full Code

```python
def calculate(first, second, operation):
    if operation == "+":
        return first + second
    if operation == "-":
        return first - second
    if operation == "*":
        return first * second
    if operation == "/":
        if second == 0:
            return "Cannot divide by zero"
        return first / second
    return "Unknown operation"


first_number = float(input("First number: "))
second_number = float(input("Second number: "))
operator = input("Operation (+, -, *, /): ")

result = calculate(first_number, second_number, operator)
print(f"Result: {result}")
```

#### Explanation

The program converts input strings to numbers, chooses behavior based on the operation, returns a result, and prints it. The division branch checks for zero before dividing.

#### Possible Improvements

- Add exponent support.
- Keep calculating until the user quits.
- Add input validation with `try` and `except`.

### Project 2: Number Guessing Game

#### Goal

Build a game where the user guesses a random number.

#### Features

- Generate a secret number.
- Give hints: too high or too low.
- Count attempts.
- Stop when guessed.

#### Required Concepts

Loops, conditionals, input, random module.

#### Full Code

```python
import random

secret = random.randint(1, 100)
attempts = 0

print("Guess the number from 1 to 100.")

while True:
    guess = int(input("Your guess: "))
    attempts += 1

    if guess < secret:
        print("Too low")
    elif guess > secret:
        print("Too high")
    else:
        print(f"Correct! Attempts: {attempts}")
        break
```

#### Explanation

`random.randint(1, 100)` chooses the hidden number. The `while True` loop keeps asking until the correct guess triggers `break`.

#### Possible Improvements

- Limit attempts.
- Add difficulty levels.
- Validate non-numeric input.

### Project 3: To-Do List App

#### Goal

Build a simple command-line to-do manager.

#### Features

- Add tasks.
- View tasks.
- Mark tasks done.
- Quit the app.

#### Required Concepts

Lists, loops, dictionaries, functions, conditionals.

#### Full Code

```python
tasks = []


def show_tasks():
    if not tasks:
        print("No tasks yet.")
        return

    for index, task in enumerate(tasks, start=1):
        status = "done" if task["done"] else "pending"
        print(f"{index}. {task['title']} [{status}]")


while True:
    print("\n1. Add task")
    print("2. Show tasks")
    print("3. Mark done")
    print("4. Quit")

    choice = input("Choose: ")

    if choice == "1":
        title = input("Task title: ")
        tasks.append({"title": title, "done": False})
    elif choice == "2":
        show_tasks()
    elif choice == "3":
        show_tasks()
        task_number = int(input("Task number: "))
        if 1 <= task_number <= len(tasks):
            tasks[task_number - 1]["done"] = True
    elif choice == "4":
        break
    else:
        print("Invalid choice")
```

#### Explanation

Each task is a dictionary with a title and status. The app repeats a menu until the user chooses to quit.

#### Possible Improvements

- Save tasks to a file.
- Delete tasks.
- Add due dates.

### Project 4: Contact Book

#### Goal

Build a contact manager using dictionaries.

#### Features

- Add contacts.
- Search by name.
- List all contacts.
- Delete contacts.

#### Required Concepts

Dictionaries, loops, functions, input, conditionals.

#### Full Code

```python
contacts = {}


def add_contact():
    name = input("Name: ").strip().title()
    phone = input("Phone: ").strip()
    email = input("Email: ").strip().lower()
    contacts[name] = {"phone": phone, "email": email}


def show_contact():
    name = input("Search name: ").strip().title()
    contact = contacts.get(name)
    if contact is None:
        print("Contact not found")
    else:
        print(f"{name}: {contact['phone']}, {contact['email']}")


def list_contacts():
    for name, details in contacts.items():
        print(f"{name}: {details['phone']}, {details['email']}")


while True:
    print("\n1. Add")
    print("2. Search")
    print("3. List")
    print("4. Delete")
    print("5. Quit")

    choice = input("Choose: ")

    if choice == "1":
        add_contact()
    elif choice == "2":
        show_contact()
    elif choice == "3":
        list_contacts()
    elif choice == "4":
        name = input("Delete name: ").strip().title()
        contacts.pop(name, None)
    elif choice == "5":
        break
    else:
        print("Invalid choice")
```

#### Explanation

The contact name is the dictionary key. The phone and email are stored in a nested dictionary.

#### Possible Improvements

- Save contacts to JSON.
- Support partial name search.
- Validate phone and email.

## Beginner Interview Questions

1. What is the difference between `=` and `==`?
2. What are Python's basic data types?
3. Why does `input()` return a string?
4. What is the difference between a list and a tuple?
5. What is the difference between `break` and `continue`?
6. What is a function return value?
7. What is local scope?
8. When should you use a dictionary?
9. What does `None` mean?
10. Why is indentation important in Python?

Sample answers:

- `=` assigns a value, while `==` compares two values.
- A list is mutable; a tuple is immutable.
- `break` exits a loop; `continue` skips the rest of the current iteration.
- `None` represents no value or a missing value.

---

# Intermediate Python

Intermediate Python is where you start writing code that looks like real software: files, packages, objects, error handling, reusable modules, tests, and better data modeling.

## Error Handling

### What It Means

Error handling lets your program respond to problems instead of crashing.

### Why It Is Important

Real input is messy. Files may be missing, APIs may fail, users may type invalid values, and databases may reject data.

### Syntax

```python
try:
    risky_operation()
except SomeError:
    handle_error()
else:
    run_if_no_error()
finally:
    always_run()
```

### Simple Example

```python
try:
    age = int(input("Age: "))
except ValueError:
    print("Please enter a valid number.")
else:
    print(f"Next year you will be {age + 1}.")
finally:
    print("Finished age check.")
```

### Raising Exceptions

```python
def withdraw(balance, amount):
    if amount <= 0:
        raise ValueError("Amount must be positive")
    if amount > balance:
        raise ValueError("Insufficient funds")
    return balance - amount
```

### Custom Exceptions

```python
class PaymentError(Exception):
    """Raised when a payment cannot be processed."""


def process_payment(amount):
    if amount <= 0:
        raise PaymentError("Payment amount must be positive")
    return "Payment successful"
```

### Real-World Example

```python
from pathlib import Path

path = Path("settings.txt")

try:
    settings = path.read_text(encoding="utf-8")
except FileNotFoundError:
    settings = "theme=light"
    path.write_text(settings, encoding="utf-8")

print(settings)
```

### Common Mistakes

- Catching every exception with bare `except:`.
- Hiding errors silently.
- Using exceptions for normal control flow too often.
- Raising generic `Exception` instead of a specific type.

### Best Practices

- Catch specific exceptions.
- Keep `try` blocks small.
- Log unexpected errors.
- Use custom exceptions for domain-specific failures.

### Practice Exercises

1. Ask for a number until valid input is entered.
2. Raise `ValueError` if a password is shorter than 8 characters.
3. Create a custom `InsufficientStockError`.

### Solution

```python
while True:
    try:
        number = int(input("Number: "))
        break
    except ValueError:
        print("Invalid number. Try again.")

print(number)
```

## File Handling

### What It Means

File handling means reading from and writing to files.

### Why It Is Important

Programs store logs, reports, exports, settings, user data, CSV files, JSON files, and more.

### Text Files

```python
from pathlib import Path

path = Path("notes.txt")
path.write_text("Learn Python\nPractice daily\n", encoding="utf-8")
content = path.read_text(encoding="utf-8")
print(content)
```

### Reading Files

```python
from pathlib import Path

path = Path("notes.txt")

if path.exists():
    print(path.read_text(encoding="utf-8"))
```

### Writing Files

```python
from pathlib import Path

Path("report.txt").write_text("Monthly report\n", encoding="utf-8")
```

### Appending Files

```python
from pathlib import Path

with Path("app.log").open("a", encoding="utf-8") as file:
    file.write("Application started\n")
```

### CSV Files

```python
import csv
from pathlib import Path

rows = [
    {"name": "Asha", "score": 92},
    {"name": "Ravi", "score": 85},
]

with Path("scores.csv").open("w", newline="", encoding="utf-8") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "score"])
    writer.writeheader()
    writer.writerows(rows)

with Path("scores.csv").open("r", newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row["name"], row["score"])
```

### JSON Files

```python
import json
from pathlib import Path

settings = {"theme": "dark", "font_size": 14}

Path("settings.json").write_text(
    json.dumps(settings, indent=2),
    encoding="utf-8",
)

loaded = json.loads(Path("settings.json").read_text(encoding="utf-8"))
print(loaded["theme"])
```

### Real-World Example

```python
import json
from pathlib import Path

TASK_FILE = Path("tasks.json")


def load_tasks():
    if not TASK_FILE.exists():
        return []
    return json.loads(TASK_FILE.read_text(encoding="utf-8"))


def save_tasks(tasks):
    TASK_FILE.write_text(json.dumps(tasks, indent=2), encoding="utf-8")
```

### Common Mistakes

- Forgetting to close files when not using `with`.
- Not specifying encoding.
- Using string paths everywhere instead of `pathlib`.
- Manually parsing CSV with `.split(",")`.

### Best Practices

- Use `with` when opening files.
- Prefer `pathlib.Path`.
- Use `csv` and `json` modules for structured formats.
- Keep data serialization separate from business logic.

### Practice Exercises

1. Save a list of names to a text file.
2. Read a CSV of expenses and sum the amount column.
3. Store contacts in a JSON file.

## Modules And Packages

### What It Means

A module is a Python file. A package is a folder of modules.

### Why It Is Important

Modules and packages organize code so programs can grow without becoming one huge file.

### Syntax

```python
import math
from pathlib import Path
from package.module import function_name
```

### Simple Example

```python
import math

print(math.sqrt(25))
```

### Creating Your Own Module

Create `tax.py`:

```python
def calculate_tax(amount, rate=0.18):
    return amount * rate
```

Create `main.py`:

```python
from tax import calculate_tax

print(calculate_tax(1000))
```

### Real-World Example

Project structure:

```text
shop/
  main.py
  pricing.py
  inventory.py
```

`pricing.py`:

```python
def final_price(subtotal, discount=0, tax_rate=0.18):
    taxable = subtotal - discount
    return taxable + taxable * tax_rate
```

`main.py`:

```python
from pricing import final_price

print(final_price(2000, discount=150))
```

### Common Mistakes

- Naming your file like a standard library module, such as `math.py`.
- Creating circular imports.
- Running code at import time unintentionally.

### Best Practices

- Keep modules focused.
- Use `if __name__ == "__main__":` for script entry points.
- Use packages as projects grow.

### Practice Exercises

1. Create a `calculator.py` module.
2. Import it in `main.py`.
3. Add `add`, `subtract`, `multiply`, and `divide`.

## pip And Virtual Environments

### What It Means

`pip` installs third-party packages. A virtual environment isolates project dependencies.

### Why It Is Important

Different projects need different package versions. Virtual environments prevent conflicts.

### Syntax

```bash
python -m venv .venv
```

Activate on Windows PowerShell:

```powershell
.\.venv\Scripts\Activate.ps1
```

Activate on macOS/Linux:

```bash
source .venv/bin/activate
```

Install a package:

```bash
python -m pip install requests
```

### Real-World Example

```bash
python -m venv .venv
python -m pip install fastapi uvicorn
python -m pip freeze > requirements.txt
```

### Common Mistakes

- Installing packages globally.
- Forgetting to activate the environment.
- Committing `.venv` to Git.

### Best Practices

- Create one virtual environment per project.
- Use `python -m pip` to ensure pip belongs to the selected Python.
- Commit dependency files, not the environment folder.

### Practice Exercises

1. Create a virtual environment.
2. Install `requests`.
3. Create `requirements.txt`.

## Object-Oriented Programming

### What It Means

Object-oriented programming, or OOP, organizes code around objects that combine data and behavior.

### Why It Is Important

OOP helps model real-world entities, share behavior, and keep related logic together.

### Classes And Objects

A class is a blueprint. An object is an instance of that blueprint.

```python
class Dog:
    pass


my_dog = Dog()
```

### __init__, Instance Variables, And Instance Methods

```python
class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        if amount <= 0:
            raise ValueError("Amount must be positive")
        self.balance += amount

    def withdraw(self, amount):
        if amount > self.balance:
            raise ValueError("Insufficient funds")
        self.balance -= amount


account = BankAccount("Asha", 1000)
account.deposit(500)
print(account.balance)
```

Line by line:

- `class BankAccount:` defines a class.
- `__init__` runs when a new object is created.
- `self.owner` and `self.balance` are instance variables.
- `deposit` and `withdraw` are instance methods.
- `account` is an object.

### Class Variables

```python
class User:
    active_count = 0

    def __init__(self, name):
        self.name = name
        User.active_count += 1
```

### Class Methods

```python
class User:
    def __init__(self, name):
        self.name = name

    @classmethod
    def guest(cls):
        return cls("Guest")


user = User.guest()
```

### Static Methods

```python
class Temperature:
    @staticmethod
    def celsius_to_fahrenheit(celsius):
        return celsius * 9 / 5 + 32
```

### Inheritance

```python
class Employee:
    def __init__(self, name):
        self.name = name

    def work(self):
        return f"{self.name} is working"


class Developer(Employee):
    def write_code(self):
        return f"{self.name} is writing Python"
```

### Multiple Inheritance

```python
class LoggerMixin:
    def log(self, message):
        print(f"LOG: {message}")


class Service(LoggerMixin):
    def run(self):
        self.log("Service started")
```

Use multiple inheritance carefully. It is best for mixins with small, focused behavior.

### Polymorphism

Polymorphism means different objects can respond to the same method name.

```python
class EmailNotification:
    def send(self, message):
        print(f"Email: {message}")


class SmsNotification:
    def send(self, message):
        print(f"SMS: {message}")


def notify(channel, message):
    channel.send(message)


notify(EmailNotification(), "Welcome")
notify(SmsNotification(), "Welcome")
```

### Encapsulation

Encapsulation means hiding internal details and exposing safe methods.

```python
class Wallet:
    def __init__(self):
        self._balance = 0

    def add_money(self, amount):
        if amount <= 0:
            raise ValueError("Amount must be positive")
        self._balance += amount

    def get_balance(self):
        return self._balance
```

Python uses convention: `_balance` means internal use.

### Abstraction

Abstraction focuses on what something does, not every detail of how it does it.

```python
from abc import ABC, abstractmethod


class Storage(ABC):
    @abstractmethod
    def save(self, data):
        pass
```

### Method Overriding

```python
class Animal:
    def speak(self):
        return "Some sound"


class Cat(Animal):
    def speak(self):
        return "Meow"
```

### Dunder Methods

Dunder methods customize Python behavior.

```python
class Money:
    def __init__(self, amount):
        self.amount = amount

    def __str__(self):
        return f"Rs. {self.amount:.2f}"

    def __add__(self, other):
        return Money(self.amount + other.amount)


print(Money(100) + Money(50))
```

### Real-World Example

```python
class Product:
    def __init__(self, sku, name, price):
        self.sku = sku
        self.name = name
        self.price = price

    def apply_discount(self, percent):
        if not 0 <= percent <= 100:
            raise ValueError("Discount must be between 0 and 100")
        self.price *= 1 - percent / 100

    def __str__(self):
        return f"{self.sku}: {self.name} - Rs. {self.price:.2f}"
```

### Common Mistakes

- Creating classes for everything.
- Using inheritance when composition is simpler.
- Forgetting `self`.
- Exposing internal state without validation.

### Best Practices

- Use classes when data and behavior naturally belong together.
- Prefer composition for flexible designs.
- Keep methods small.
- Use dataclasses for simple data containers.

### Practice Exercises

1. Create a `Book` class.
2. Create a `Student` class with marks and an average method.
3. Create a `Vehicle` base class and `Car` subclass.
4. Add `__str__` to a class.

## Comprehensions

### What It Means

Comprehensions create collections concisely.

### Why It Is Important

They make transformation and filtering readable when used well.

### List Comprehension

```python
squares = [number ** 2 for number in range(1, 6)]
print(squares)
```

### Dictionary Comprehension

```python
prices = {"pen": 10, "notebook": 50}
with_tax = {item: price * 1.18 for item, price in prices.items()}
```

### Set Comprehension

```python
names = ["Asha", "asha", "Ravi"]
unique_names = {name.lower() for name in names}
```

### Generator Expression

```python
numbers = [1, 2, 3, 4]
total = sum(number ** 2 for number in numbers)
```

### Real-World Example

```python
orders = [
    {"id": 1, "total": 500},
    {"id": 2, "total": 1500},
    {"id": 3, "total": 700},
]

large_order_ids = [order["id"] for order in orders if order["total"] >= 1000]
```

### Common Mistakes

- Making comprehensions too complex.
- Using them only to cause side effects.
- Forgetting that generator expressions are lazy.

### Best Practices

- Use comprehensions for simple map/filter operations.
- Use normal loops when logic needs multiple steps.
- Keep them readable.

### Practice Exercises

1. Create a list of even numbers from 1 to 20.
2. Create a dictionary of names and name lengths.
3. Remove duplicate lowercase emails using a set comprehension.

## Lambda, map, filter, And reduce

### What It Means

`lambda` creates small anonymous functions. `map`, `filter`, and `reduce` are functional-style tools.

### Why It Is Important

You will see these in existing Python code, data pipelines, and callback-style APIs.

### Syntax

```python
lambda arguments: expression
map(function, iterable)
filter(function, iterable)
```

`reduce` lives in `functools`.

```python
from functools import reduce
```

### Simple Examples

```python
square = lambda number: number ** 2
print(square(5))
```

```python
numbers = [1, 2, 3, 4]
print(list(map(lambda number: number * 2, numbers)))
print(list(filter(lambda number: number % 2 == 0, numbers)))
```

```python
from functools import reduce

numbers = [1, 2, 3, 4]
product = reduce(lambda a, b: a * b, numbers)
print(product)
```

### Real-World Example

```python
users = [
    {"name": "Asha", "active": True},
    {"name": "Ravi", "active": False},
]

active_names = list(
    map(
        lambda user: user["name"],
        filter(lambda user: user["active"], users),
    )
)
```

Often, a comprehension is clearer:

```python
active_names = [user["name"] for user in users if user["active"]]
```

### Common Mistakes

- Overusing `lambda` when `def` is clearer.
- Forgetting that `map` and `filter` return iterators.
- Using `reduce` for code that `sum`, `any`, or `all` can express better.

### Best Practices

- Prefer comprehensions for most transformations.
- Use `lambda` for short callback functions.
- Use named functions for reusable logic.

### Practice Exercises

1. Sort names by length using `lambda`.
2. Filter numbers greater than 10.
3. Use `map` to convert strings to integers.

## Iterators And Generators

### What It Means

An iterator produces values one at a time. A generator is a convenient way to create an iterator using `yield`.

### Why It Is Important

Iterators and generators handle large data efficiently because they do not need to store everything in memory at once.

### Syntax

```python
def generator_function():
    yield value
```

### Simple Example

```python
def count_up_to(limit):
    number = 1
    while number <= limit:
        yield number
        number += 1


for value in count_up_to(3):
    print(value)
```

### Real-World Example

```python
from pathlib import Path


def read_large_file(path):
    with Path(path).open("r", encoding="utf-8") as file:
        for line in file:
            yield line.strip()


for line in read_large_file("app.log"):
    if "ERROR" in line:
        print(line)
```

### Common Mistakes

- Expecting a generator to restart after it is exhausted.
- Converting huge generators to lists unnecessarily.
- Forgetting that `yield` pauses function execution.

### Best Practices

- Use generators for streams, large files, and pipelines.
- Use lists when you need indexing or repeated iteration.
- Keep generator functions simple.

### Practice Exercises

1. Write a generator for even numbers up to a limit.
2. Write a generator that yields words from a sentence.
3. Use `next()` on a generator.

## Decorators

### What It Means

A decorator wraps a function to add behavior before or after it runs.

### Why It Is Important

Decorators are used for logging, authentication, caching, validation, timing, and web route registration.

### Syntax

```python
@decorator_name
def function_name():
    ...
```

### Simple Example

```python
def announce(func):
    def wrapper():
        print("Before")
        func()
        print("After")
    return wrapper


@announce
def say_hello():
    print("Hello")


say_hello()
```

### Better Version With functools.wraps

```python
from functools import wraps


def announce(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Calling {func.__name__}")
        return func(*args, **kwargs)
    return wrapper
```

### Real-World Example

```python
from functools import wraps
from time import perf_counter


def timer(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = perf_counter()
        result = func(*args, **kwargs)
        elapsed = perf_counter() - start
        print(f"{func.__name__} took {elapsed:.4f} seconds")
        return result
    return wrapper


@timer
def slow_sum(numbers):
    return sum(numbers)
```

### Common Mistakes

- Forgetting to return the wrapper.
- Forgetting to return the original function's result.
- Not using `functools.wraps`.

### Best Practices

- Use decorators for cross-cutting behavior.
- Keep wrappers generic with `*args` and `**kwargs`.
- Use `wraps` to preserve metadata.

### Practice Exercises

1. Create a decorator that prints before and after a function.
2. Create a timing decorator.
3. Create a decorator that blocks calls unless `is_admin=True`.

## Context Managers

### What It Means

A context manager sets up and cleans up resources automatically.

### Why It Is Important

Files, locks, database connections, and network connections need reliable cleanup.

### Syntax

```python
with context_manager as value:
    ...
```

### Simple Example

```python
with open("notes.txt", "w", encoding="utf-8") as file:
    file.write("Hello")
```

The file closes automatically.

### Custom Context Manager

```python
from contextlib import contextmanager


@contextmanager
def section(name):
    print(f"Starting {name}")
    try:
        yield
    finally:
        print(f"Ending {name}")


with section("report"):
    print("Generating report")
```

### Real-World Example

```python
import sqlite3

with sqlite3.connect("app.db") as connection:
    connection.execute(
        "CREATE TABLE IF NOT EXISTS notes (id INTEGER PRIMARY KEY, text TEXT)"
    )
```

### Common Mistakes

- Opening files without closing them.
- Putting too much unrelated work inside a context.
- Forgetting cleanup in custom resource code.

### Best Practices

- Use `with` for resources.
- Use `contextlib.contextmanager` for simple custom managers.
- Keep setup and cleanup predictable.

### Practice Exercises

1. Write to a file using `with`.
2. Create a context manager that prints start and end.
3. Use `with` for a SQLite connection.

## Dates And Times

### What It Means

Python's `datetime` module handles dates, times, durations, and formatting.

### Why It Is Important

Apps need timestamps, deadlines, reports, scheduling, logs, and time calculations.

### Syntax

```python
from datetime import date, datetime, timedelta
```

### Simple Example

```python
from datetime import date

today = date.today()
print(today)
print(today.year)
```

### Real-World Example

```python
from datetime import datetime, timedelta

created_at = datetime.now()
expires_at = created_at + timedelta(days=7)

print(expires_at.strftime("%Y-%m-%d %H:%M"))
```

### Common Mistakes

- Treating formatted date strings as dates.
- Ignoring time zones in real apps.
- Comparing naive and aware datetimes.

### Best Practices

- Store timestamps in UTC in real systems.
- Convert to local time only for display.
- Parse and format dates at system boundaries.

### Practice Exercises

1. Print today's date.
2. Print the date 30 days from now.
3. Parse `"2026-06-02"` into a date.

## Regular Expressions

### What It Means

Regular expressions, or regex, are patterns for matching text.

### Why It Is Important

Regex is useful for validation, searching logs, extracting fields, and cleaning text.

### Syntax

```python
import re

re.search(pattern, text)
re.findall(pattern, text)
re.sub(pattern, replacement, text)
```

### Simple Example

```python
import re

text = "Contact: user@example.com"
match = re.search(r"\w+@\w+\.\w+", text)

if match:
    print(match.group())
```

### Real-World Example

```python
import re

log_line = "2026-06-02 ERROR Payment failed for order 1234"
pattern = r"(?P<date>\d{4}-\d{2}-\d{2}) (?P<level>\w+) (?P<message>.+)"

match = re.search(pattern, log_line)

if match:
    print(match.groupdict())
```

### Common Mistakes

- Using regex for formats that need parsers, such as HTML or JSON.
- Forgetting raw strings: use `r"\d+"`.
- Writing unreadable giant patterns.

### Best Practices

- Keep regex patterns small.
- Name groups for complex matches.
- Test patterns with examples.

### Practice Exercises

1. Find all numbers in text.
2. Validate a simple email format.
3. Replace multiple spaces with one space.

## Type Hints

### What It Means

Type hints describe expected types for variables, parameters, and return values.

### Why It Is Important

They improve readability, editor help, refactoring, and static analysis.

### Syntax

```python
def add(a: int, b: int) -> int:
    return a + b
```

### Simple Example

```python
def greet(name: str) -> str:
    return f"Hello, {name}"
```

### Python 3.12+ Generic Function Example

```python
def first[T](items: list[T]) -> T:
    return items[0]
```

### Real-World Example

```python
from typing import Literal


OrderStatus = Literal["pending", "paid", "shipped", "cancelled"]


def can_ship(status: OrderStatus) -> bool:
    return status == "paid"
```

### Common Mistakes

- Thinking hints enforce types at runtime by default.
- Using overly complex type hints too early.
- Letting type hints drift from behavior.

### Best Practices

- Add hints to function signatures.
- Use built-in generics: `list[str]`, `dict[str, int]`.
- Use type aliases for repeated complex types.

### Practice Exercises

1. Add type hints to a calculator function.
2. Create a function returning `list[str]`.
3. Define a type alias for a user dictionary.

## Dataclasses

### What It Means

A dataclass is a concise way to create classes mainly used to store data.

### Why It Is Important

Dataclasses reduce boilerplate for records while keeping code typed and readable.

### Syntax

```python
from dataclasses import dataclass


@dataclass
class ClassName:
    field: type
```

### Simple Example

```python
from dataclasses import dataclass


@dataclass
class Product:
    name: str
    price: float
    stock: int = 0


product = Product("Keyboard", 1499.0, 10)
print(product)
```

### Real-World Example

```python
from dataclasses import dataclass
from datetime import datetime


@dataclass(frozen=True)
class AuditEvent:
    actor: str
    action: str
    created_at: datetime
```

### Common Mistakes

- Using dataclasses for behavior-heavy objects where a normal class is clearer.
- Using mutable defaults incorrectly.

### Best Practices

- Use `field(default_factory=list)` for mutable defaults.
- Use `frozen=True` for immutable records.
- Add methods when they belong to the data.

### Practice Exercise

Create a `Task` dataclass with `title`, `done`, and `priority`.

## Enum

### What It Means

An enum defines a fixed set of named values.

### Why It Is Important

Enums avoid typo-prone strings and make states explicit.

### Syntax

```python
from enum import Enum
```

### Simple Example

```python
from enum import Enum


class OrderStatus(Enum):
    PENDING = "pending"
    PAID = "paid"
    SHIPPED = "shipped"


status = OrderStatus.PAID
print(status.value)
```

### Real-World Example

```python
def can_cancel(status: OrderStatus) -> bool:
    return status in {OrderStatus.PENDING, OrderStatus.PAID}
```

### Common Mistakes

- Comparing enum members to raw strings.
- Creating enums for values that change frequently.

### Best Practices

- Use enums for stable state sets.
- Store `.value` when serializing to JSON.
- Compare enum members directly.

### Practice Exercise

Create a `Priority` enum with `LOW`, `MEDIUM`, and `HIGH`.

## collections Module

### What It Means

`collections` provides specialized container types.

### Why It Is Important

These containers solve common problems cleanly and efficiently.

### Counter

```python
from collections import Counter

words = "python python data".split()
counts = Counter(words)
print(counts)
```

### defaultdict

```python
from collections import defaultdict

groups = defaultdict(list)
groups["python"].append("Asha")
groups["python"].append("Ravi")
print(groups)
```

### deque

```python
from collections import deque

queue = deque()
queue.append("first")
queue.append("second")
print(queue.popleft())
```

### namedtuple

```python
from collections import namedtuple

Point = namedtuple("Point", ["x", "y"])
point = Point(10, 20)
print(point.x)
```

### Real-World Example

```python
from collections import Counter, deque

recent_errors = deque(maxlen=5)
error_counts = Counter()

for level in ["INFO", "ERROR", "ERROR", "WARNING"]:
    if level == "ERROR":
        recent_errors.append(level)
    error_counts[level] += 1
```

### Common Mistakes

- Reimplementing counters manually when `Counter` fits.
- Using lists as queues with slow `pop(0)`.
- Using `namedtuple` when a dataclass would be clearer.

### Best Practices

- Use `Counter` for frequency.
- Use `defaultdict` for grouping.
- Use `deque` for queues and fixed recent history.

### Practice Exercises

1. Count characters in a string.
2. Group students by grade.
3. Build a queue of support tickets.

## pathlib, os, And sys

### What It Means

`pathlib` handles file paths as objects. `os` provides operating system functions. `sys` provides interpreter-level information and command-line arguments.

### Why It Is Important

Professional scripts need reliable path handling, environment access, and command-line behavior.

### pathlib Example

```python
from pathlib import Path

project_dir = Path.cwd()
data_file = project_dir / "data" / "input.txt"
print(data_file)
```

### os Example

```python
import os

api_key = os.environ.get("API_KEY")
print(api_key)
```

### sys Example

```python
import sys

print(sys.version)
print(sys.argv)
```

### Real-World Example

```python
from pathlib import Path
import sys


def main():
    if len(sys.argv) < 2:
        print("Usage: python count_lines.py file.txt")
        return

    path = Path(sys.argv[1])
    text = path.read_text(encoding="utf-8")
    print(len(text.splitlines()))


if __name__ == "__main__":
    main()
```

### Common Mistakes

- Building paths by string concatenation.
- Assuming Windows and Linux path separators are the same.
- Reading command-line arguments without checking length.

### Best Practices

- Prefer `pathlib` for paths.
- Use `os.environ` for environment variables.
- Keep command-line parsing simple or use `argparse`.

### Practice Exercises

1. Print the current working directory.
2. List all `.txt` files in a folder.
3. Read a filename from `sys.argv`.

## Intermediate Mini Projects

### Project 5: File Organizer Script

#### Goal

Organize files in a folder by extension.

#### Features

- Scan a folder.
- Create folders such as `Images`, `Documents`, `Archives`, and `Other`.
- Move files into matching folders.

#### Required Concepts

`pathlib`, dictionaries, loops, file operations, functions.

#### Full Code

```python
from pathlib import Path
import shutil


CATEGORIES = {
    "Images": {".jpg", ".jpeg", ".png", ".gif"},
    "Documents": {".pdf", ".docx", ".txt", ".md"},
    "Spreadsheets": {".xlsx", ".csv"},
    "Archives": {".zip", ".tar", ".gz"},
}


def category_for(path):
    suffix = path.suffix.lower()
    for category, suffixes in CATEGORIES.items():
        if suffix in suffixes:
            return category
    return "Other"


def organize(folder):
    folder_path = Path(folder)

    for item in folder_path.iterdir():
        if item.is_dir():
            continue

        category = category_for(item)
        destination_dir = folder_path / category
        destination_dir.mkdir(exist_ok=True)
        shutil.move(str(item), str(destination_dir / item.name))


if __name__ == "__main__":
    target = input("Folder to organize: ")
    organize(target)
```

#### Explanation

The script maps extensions to folder names, loops through files, creates category folders, and moves each file.

#### Possible Improvements

- Add a dry-run mode.
- Handle duplicate file names.
- Add logging.
- Use command-line arguments.

### Project 6: Weather API App

#### Goal

Fetch weather data from an API and display a summary.

#### Features

- Ask for a city.
- Call an HTTP API.
- Parse JSON.
- Display temperature and condition.

#### Required Concepts

Virtual environments, `requests`, JSON, errors, functions.

#### Full Code

```python
import requests


def get_weather(city, api_key):
    url = "https://api.openweathermap.org/data/2.5/weather"
    params = {"q": city, "appid": api_key, "units": "metric"}
    response = requests.get(url, params=params, timeout=10)
    response.raise_for_status()
    return response.json()


def print_weather(data):
    city = data["name"]
    temp = data["main"]["temp"]
    description = data["weather"][0]["description"]
    print(f"{city}: {temp} C, {description}")


def main():
    city = input("City: ")
    api_key = input("API key: ")

    try:
        data = get_weather(city, api_key)
    except requests.RequestException as error:
        print(f"Could not fetch weather: {error}")
        return

    print_weather(data)


if __name__ == "__main__":
    main()
```

#### Explanation

The API returns JSON. `response.raise_for_status()` raises an exception for failed HTTP responses.

#### Possible Improvements

- Store the API key in an environment variable.
- Add unit tests with mocked responses.
- Cache results.

### Project 7: Expense Tracker

#### Goal

Track expenses in a CSV file.

#### Features

- Add expenses.
- List expenses.
- Show total.
- Store data in CSV.

#### Required Concepts

CSV, functions, dictionaries, dates, file handling.

#### Full Code

```python
import csv
from datetime import date
from pathlib import Path


EXPENSE_FILE = Path("expenses.csv")
FIELDNAMES = ["date", "category", "amount", "note"]


def ensure_file():
    if not EXPENSE_FILE.exists():
        with EXPENSE_FILE.open("w", newline="", encoding="utf-8") as file:
            writer = csv.DictWriter(file, fieldnames=FIELDNAMES)
            writer.writeheader()


def add_expense():
    category = input("Category: ")
    amount = float(input("Amount: "))
    note = input("Note: ")

    with EXPENSE_FILE.open("a", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=FIELDNAMES)
        writer.writerow(
            {
                "date": date.today().isoformat(),
                "category": category,
                "amount": amount,
                "note": note,
            }
        )


def list_expenses():
    total = 0
    with EXPENSE_FILE.open("r", newline="", encoding="utf-8") as file:
        reader = csv.DictReader(file)
        for row in reader:
            amount = float(row["amount"])
            total += amount
            print(row)
    print(f"Total: Rs. {total:.2f}")


def main():
    ensure_file()
    while True:
        print("\n1. Add expense")
        print("2. List expenses")
        print("3. Quit")
        choice = input("Choose: ")

        if choice == "1":
            add_expense()
        elif choice == "2":
            list_expenses()
        elif choice == "3":
            break


if __name__ == "__main__":
    main()
```

#### Explanation

CSV stores tabular rows. Each expense is a row. The listing function reads rows and calculates the total.

#### Possible Improvements

- Filter by month.
- Group totals by category.
- Export charts.

## Intermediate Interview Questions

1. What is the difference between a module and a package?
2. Why should you use a virtual environment?
3. What does `with` do?
4. What is the difference between instance methods, class methods, and static methods?
5. What is inheritance?
6. What is polymorphism?
7. What is a decorator?
8. What is a generator?
9. Why use type hints?
10. When should you use `Counter`?

Sample answers:

- A module is a `.py` file; a package is a directory containing modules.
- A virtual environment isolates dependencies for one project.
- `with` ensures resources are cleaned up, such as closing files.
- A generator yields values lazily one at a time.

---

# Advanced Python

Advanced Python is about designing robust systems, understanding tradeoffs, and writing code that scales in complexity, performance, and team usage.

## Advanced OOP Design

### What It Means

Advanced OOP design is the art of modeling behavior with classes, interfaces, composition, and dependency boundaries.

### Why It Is Important

Large systems fail when classes become tangled. Good design keeps code changeable.

### Syntax Pattern

```python
class Service:
    def __init__(self, dependency):
        self.dependency = dependency
```

### Simple Example

```python
class EmailSender:
    def send(self, to, message):
        print(f"Sending email to {to}: {message}")


class WelcomeService:
    def __init__(self, sender):
        self.sender = sender

    def welcome(self, email):
        self.sender.send(email, "Welcome!")
```

### Real-World Example

```python
from typing import Protocol


class NotificationSender(Protocol):
    def send(self, to: str, message: str) -> None:
        ...


class SmsSender:
    def send(self, to: str, message: str) -> None:
        print(f"SMS to {to}: {message}")


class AlertService:
    def __init__(self, sender: NotificationSender):
        self.sender = sender

    def alert(self, user_phone: str, message: str) -> None:
        self.sender.send(user_phone, message)
```

### Common Mistakes

- Deep inheritance trees.
- Classes with too many responsibilities.
- Hidden dependencies created inside methods.

### Best Practices

- Prefer composition over inheritance.
- Inject dependencies.
- Keep domain logic separate from I/O.
- Use `Protocol` for structural interfaces.

### Practice Exercises

1. Refactor a class that sends email directly to accept a sender dependency.
2. Define a `PaymentGateway` protocol.
3. Implement two payment gateway classes with the same interface.

## SOLID Principles In Python

### What It Means

SOLID is a set of design principles:

- Single Responsibility
- Open/Closed
- Liskov Substitution
- Interface Segregation
- Dependency Inversion

### Why It Is Important

SOLID helps code remain understandable as projects grow.

### Simple Example: Single Responsibility

Poor design:

```python
class Report:
    def calculate(self):
        ...

    def save_to_file(self):
        ...
```

Better:

```python
class ReportCalculator:
    def calculate(self):
        return {"total": 100}


class ReportWriter:
    def save(self, report):
        print(report)
```

### Real-World Example: Dependency Inversion

```python
from typing import Protocol


class Repository(Protocol):
    def save(self, item: dict) -> None:
        ...


class OrderService:
    def __init__(self, repository: Repository):
        self.repository = repository

    def create_order(self, item: dict) -> None:
        self.repository.save(item)
```

### Common Mistakes

- Treating SOLID as rules instead of guidance.
- Creating too many tiny abstractions.
- Applying enterprise patterns to tiny scripts.

### Best Practices

- Use SOLID when change is likely.
- Keep simple code simple.
- Introduce interfaces at boundaries: database, API, payment, email.

### Practice Exercise

Refactor a `UserManager` that validates users, saves users, and sends emails into separate components.

## Design Patterns In Python

### What It Means

Design patterns are common solutions to recurring design problems.

### Why It Is Important

Patterns give shared vocabulary and proven structures.

### Factory Pattern

```python
class CsvExporter:
    def export(self, data):
        return "csv data"


class JsonExporter:
    def export(self, data):
        return "json data"


def exporter_factory(format_name):
    if format_name == "csv":
        return CsvExporter()
    if format_name == "json":
        return JsonExporter()
    raise ValueError("Unsupported format")
```

### Strategy Pattern

```python
class PercentageDiscount:
    def apply(self, amount):
        return amount * 0.9


class FixedDiscount:
    def apply(self, amount):
        return amount - 100


def checkout(amount, discount_strategy):
    return discount_strategy.apply(amount)
```

### Repository Pattern

```python
class InMemoryNoteRepository:
    def __init__(self):
        self.notes = []

    def add(self, note):
        self.notes.append(note)

    def list(self):
        return self.notes
```

### Common Mistakes

- Forcing patterns where functions would do.
- Using Singleton for global mutable state.
- Confusing pattern names with good design.

### Best Practices

- Use patterns to simplify change.
- Prefer Pythonic implementations over Java-style ceremony.
- Start simple, refactor when duplication appears.

### Practice Exercises

1. Implement a factory for notification channels.
2. Use strategy for shipping cost calculation.
3. Create a repository interface for notes.

## Functional Programming Concepts

### What It Means

Functional programming treats computation as the evaluation of functions, often avoiding mutation.

### Why It Is Important

Pure functions are easier to test, reason about, and parallelize.

### Simple Example

```python
def add_tax(price, tax_rate):
    return price * (1 + tax_rate)
```

This function does not modify external state.

### Real-World Example

```python
def normalize_email(email):
    return email.strip().lower()


def normalize_users(users):
    return [
        {**user, "email": normalize_email(user["email"])}
        for user in users
    ]
```

### Common Mistakes

- Thinking functional programming means never using classes.
- Overusing `map` and `lambda` where comprehensions are clearer.
- Mutating inputs inside functions unexpectedly.

### Best Practices

- Write pure functions for business rules.
- Avoid modifying arguments unless the function name makes it clear.
- Separate data transformation from I/O.

### Practice Exercise

Write pure functions to apply discount, tax, and rounding to an order amount.

## Closures

### What It Means

A closure is a function that remembers variables from its enclosing scope.

### Why It Is Important

Closures power decorators, callbacks, and configurable functions.

### Syntax

```python
def outer(value):
    def inner():
        return value
    return inner
```

### Simple Example

```python
def multiplier(factor):
    def multiply(number):
        return number * factor
    return multiply


double = multiplier(2)
print(double(10))
```

### Real-World Example

```python
def minimum_length_validator(min_length):
    def validate(text):
        return len(text) >= min_length
    return validate


password_ok = minimum_length_validator(8)
print(password_ok("secret123"))
```

### Common Mistakes

- Late binding surprises in loops.
- Overusing closures where classes would be clearer.

### Best Practices

- Use closures for small configured behavior.
- Use classes when state becomes complex.
- Be careful with variables captured in loops.

### Practice Exercise

Create a closure that prefixes log messages with a component name.

## Advanced Decorators

### What It Means

Advanced decorators accept arguments, decorate classes, or manage async functions.

### Why It Is Important

Frameworks such as Flask, FastAPI, and pytest use decorators heavily.

### Decorator With Arguments

```python
from functools import wraps


def require_role(role):
    def decorator(func):
        @wraps(func)
        def wrapper(user, *args, **kwargs):
            if user.get("role") != role:
                raise PermissionError("Access denied")
            return func(user, *args, **kwargs)
        return wrapper
    return decorator


@require_role("admin")
def delete_user(user, user_id):
    return f"Deleted {user_id}"
```

### Real-World Example: Retry Decorator

```python
from functools import wraps
from time import sleep


def retry(times, delay=0.5):
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            last_error = None
            for _ in range(times):
                try:
                    return func(*args, **kwargs)
                except Exception as error:
                    last_error = error
                    sleep(delay)
            raise last_error
        return wrapper
    return decorator
```

### Common Mistakes

- Swallowing exceptions in decorators.
- Hiding function signatures.
- Applying retries to non-idempotent operations carelessly.

### Best Practices

- Preserve metadata with `wraps`.
- Keep decorators focused.
- Document side effects.

### Practice Exercise

Create a decorator that retries a function only for `ConnectionError`.

## Metaclasses

### What It Means

A metaclass controls how classes are created. Classes are objects, and metaclasses create those class objects.

### Why It Is Important

Most developers rarely need metaclasses, but understanding them helps with frameworks and ORMs.

### Syntax

```python
class MyMeta(type):
    pass


class MyClass(metaclass=MyMeta):
    pass
```

### Simple Example

```python
class UppercaseAttributes(type):
    def __new__(mcls, name, bases, namespace):
        uppercase_namespace = {
            key.upper() if not key.startswith("__") else key: value
            for key, value in namespace.items()
        }
        return super().__new__(mcls, name, bases, uppercase_namespace)


class Example(metaclass=UppercaseAttributes):
    value = 10


print(Example.VALUE)
```

### Real-World Use Cases

- Registering subclasses automatically.
- Validating class definitions.
- Building ORMs and serialization frameworks.

### Common Mistakes

- Using metaclasses when decorators or base classes would work.
- Making class creation hard to understand.

### Best Practices

- Avoid metaclasses unless you are building frameworks.
- Prefer `__init_subclass__` for subclass registration.
- Document metaclass behavior clearly.

### Practice Exercise

Use `__init_subclass__` to register plugin classes before trying a metaclass.

## Descriptors

### What It Means

A descriptor customizes attribute access with `__get__`, `__set__`, or `__delete__`.

### Why It Is Important

Descriptors power properties, methods, classmethods, staticmethods, and many ORMs.

### Syntax

```python
class Descriptor:
    def __get__(self, instance, owner):
        ...

    def __set__(self, instance, value):
        ...
```

### Simple Example

```python
class PositiveNumber:
    def __set_name__(self, owner, name):
        self.name = "_" + name

    def __get__(self, instance, owner):
        return getattr(instance, self.name)

    def __set__(self, instance, value):
        if value <= 0:
            raise ValueError("Value must be positive")
        setattr(instance, self.name, value)


class Product:
    price = PositiveNumber()

    def __init__(self, price):
        self.price = price
```

### Real-World Example

Descriptors are useful for reusable validation fields in frameworks:

```python
class NonEmptyString:
    def __set_name__(self, owner, name):
        self.name = "_" + name

    def __get__(self, instance, owner):
        return getattr(instance, self.name)

    def __set__(self, instance, value):
        if not value:
            raise ValueError("Value cannot be empty")
        setattr(instance, self.name, value)
```

### Common Mistakes

- Forgetting `__set_name__`.
- Storing values on the descriptor instead of the instance.
- Using descriptors for one-off validation.

### Best Practices

- Use `property` first for simple cases.
- Use descriptors for reusable attribute behavior.
- Test descriptors carefully.

### Practice Exercise

Create an `EmailField` descriptor that requires `@` in the value.

## Properties

### What It Means

A property exposes method logic like an attribute.

### Why It Is Important

Properties provide validation and computed attributes without changing the public API.

### Syntax

```python
@property
def name(self):
    return self._name
```

### Simple Example

```python
class Person:
    def __init__(self, name):
        self.name = name

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        if not value.strip():
            raise ValueError("Name cannot be empty")
        self._name = value.strip()
```

### Real-World Example

```python
class Cart:
    def __init__(self, items):
        self.items = items

    @property
    def total(self):
        return sum(item["price"] * item["quantity"] for item in self.items)
```

### Common Mistakes

- Doing expensive work in a property without caching.
- Using properties for actions with side effects.
- Recursive setter bugs by assigning to `self.name` inside `name` setter.

### Best Practices

- Use properties for computed values and validation.
- Use methods for actions.
- Keep property logic lightweight.

### Practice Exercise

Create a `Rectangle` class with `area` as a property.

## Memory Management

### What It Means

Memory management is how Python allocates and frees memory for objects.

### Why It Is Important

Understanding memory helps avoid leaks, reduce overhead, and handle large data.

### Simple Example

```python
a = [1, 2, 3]
b = a
b.append(4)
print(a)
```

Both names refer to the same list.

### Real-World Example

```python
def read_lines(path):
    with open(path, "r", encoding="utf-8") as file:
        for line in file:
            yield line
```

This streams lines instead of loading the full file.

### Common Mistakes

- Loading huge files into memory with `.read()`.
- Keeping references to objects longer than needed.
- Accidentally sharing mutable objects.

### Best Practices

- Use generators for large streams.
- Delete or release large temporary data when done.
- Be aware of object references.

### Practice Exercise

Rewrite a function that reads a whole file into one that yields lines.

## Garbage Collection

### What It Means

Garbage collection frees memory used by objects that are no longer reachable.

### Why It Is Important

Most memory cleanup is automatic, but reference cycles and resource handling still matter.

### Simple Example

```python
import gc

print(gc.isenabled())
```

### Real-World Example

Use context managers to close external resources even though memory is automatic:

```python
with open("data.txt", "r", encoding="utf-8") as file:
    content = file.read()
```

### Common Mistakes

- Assuming garbage collection closes files immediately.
- Creating reference cycles with `__del__`.
- Manually calling `gc.collect()` without measuring.

### Best Practices

- Use `with` for resources.
- Let Python manage normal memory.
- Profile before optimizing.

### Practice Exercise

Create and remove a reference cycle, then inspect `gc.collect()`.

## Copy Vs deepcopy

### What It Means

A shallow copy copies the outer container. A deep copy recursively copies nested objects.

### Why It Is Important

Nested mutable data can change unexpectedly if shared.

### Syntax

```python
import copy

copy.copy(value)
copy.deepcopy(value)
```

### Simple Example

```python
import copy

original = [[1, 2], [3, 4]]
shallow = copy.copy(original)
deep = copy.deepcopy(original)

original[0].append(99)

print(shallow)
print(deep)
```

### Real-World Example

```python
import copy

default_settings = {"theme": {"name": "dark"}}
user_settings = copy.deepcopy(default_settings)
user_settings["theme"]["name"] = "light"
```

### Common Mistakes

- Using `.copy()` on nested structures and expecting full independence.
- Deep-copying large objects unnecessarily.

### Best Practices

- Know whether your data is nested and mutable.
- Prefer immutable structures when possible.
- Copy only when ownership matters.

### Practice Exercise

Show the difference between shallow and deep copy using a nested dictionary.

## Mutability And Immutability

### What It Means

Mutable objects can change after creation. Immutable objects cannot.

### Why It Is Important

Mutation affects references, function behavior, defaults, caching, and thread safety.

### Examples

Mutable:

```python
items = []
items.append("apple")
```

Immutable:

```python
name = "Python"
name = name.upper()
```

The string was not changed; a new string was created.

### Real-World Example

```python
def add_item(item, items=None):
    if items is None:
        items = []
    items.append(item)
    return items
```

### Common Mistakes

- Mutable default arguments.
- Unexpected shared state.
- Assuming assignment copies objects.

### Best Practices

- Use `None` as the default, then create a list inside.
- Return new values for pure transformations.
- Be explicit when mutating inputs.

### Practice Exercise

Write a function with a safe list default.

## Python Internals

### GIL

The Global Interpreter Lock, or GIL, allows only one thread to execute Python bytecode at a time in the standard CPython interpreter. Threads still help with I/O-bound tasks, but CPU-bound Python code often needs multiprocessing, native extensions, or specialized runtimes.

### Bytecode

Python source code is compiled into bytecode that the interpreter executes.

```python
import dis


def add(a, b):
    return a + b


dis.dis(add)
```

### Interpreter Basics

The common implementation is CPython. It parses code, compiles it to bytecode, executes it in a virtual machine, manages objects, and loads modules.

### Why It Is Important

Internals explain performance behavior, threading limitations, import behavior, and debugging output.

### Common Mistakes

- Assuming Python threads always speed up CPU-heavy work.
- Optimizing bytecode-level details before measuring.
- Confusing Python language with CPython implementation.

### Best Practices

- Understand enough internals to make good design decisions.
- Use profiling before optimizing.
- Choose concurrency tools based on workload.

### Practice Exercise

Disassemble a simple function with `dis.dis()` and identify constants and operations.

## Concurrency And Parallelism

### What It Means

Concurrency handles multiple tasks in overlapping time. Parallelism executes tasks at the same time.

### Why It Is Important

Modern programs call APIs, handle many users, process files, run background jobs, and perform CPU-heavy work.

### threading

Best for I/O-bound work.

```python
from threading import Thread
from time import sleep


def download(name):
    sleep(1)
    print(f"Downloaded {name}")


threads = [Thread(target=download, args=(f"file{i}",)) for i in range(3)]

for thread in threads:
    thread.start()

for thread in threads:
    thread.join()
```

### multiprocessing

Best for CPU-bound work.

```python
from multiprocessing import Pool


def square(number):
    return number * number


if __name__ == "__main__":
    with Pool() as pool:
        print(pool.map(square, [1, 2, 3, 4]))
```

### asyncio And async/await

Best for many I/O tasks with async libraries.

```python
import asyncio


async def fetch(name):
    await asyncio.sleep(1)
    return f"Fetched {name}"


async def main():
    results = await asyncio.gather(fetch("a"), fetch("b"))
    print(results)


asyncio.run(main())
```

### concurrent.futures

High-level thread and process pools.

```python
from concurrent.futures import ThreadPoolExecutor


def work(number):
    return number * 2


with ThreadPoolExecutor(max_workers=4) as executor:
    results = list(executor.map(work, [1, 2, 3]))
```

### Common Mistakes

- Using threads for CPU-bound Python work and expecting speedup.
- Blocking inside async code.
- Forgetting `if __name__ == "__main__"` with multiprocessing on Windows.
- Sharing mutable data without synchronization.

### Best Practices

- Use threads for blocking I/O.
- Use processes for CPU-heavy pure Python work.
- Use async for high-concurrency I/O with async-compatible libraries.
- Keep shared state minimal.

### Practice Exercises

1. Download several URLs concurrently with threads.
2. Compute squares with multiprocessing.
3. Write two async functions and run them with `asyncio.gather`.

## Networking

### What It Means

Networking lets programs communicate over networks using sockets, HTTP, and APIs.

### Why It Is Important

Most real software talks to services: payment APIs, databases, web servers, cloud platforms, and internal systems.

### sockets

```python
import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.connect(("example.com", 80))
    sock.sendall(b"GET / HTTP/1.1\r\nHost: example.com\r\n\r\n")
    response = sock.recv(1024)
    print(response[:100])
```

### HTTP requests

```python
import requests

response = requests.get("https://api.github.com", timeout=10)
response.raise_for_status()
print(response.json())
```

### APIs

An API defines how programs communicate. HTTP APIs often use URLs, methods, headers, status codes, and JSON.

```python
payload = {"title": "Learn Python"}
response = requests.post("https://httpbin.org/post", json=payload, timeout=10)
print(response.json())
```

### Common Mistakes

- No timeout on network calls.
- Ignoring HTTP status codes.
- Hardcoding secrets in source code.
- Not handling retries or rate limits.

### Best Practices

- Always set timeouts.
- Use `raise_for_status()`.
- Store API keys in environment variables.
- Log request failures without leaking secrets.

### Practice Exercises

1. Fetch JSON from a public API.
2. Print status code and response headers.
3. Handle network errors with `try` and `except`.

## Databases

### What It Means

Databases store, query, and manage structured data.

### Why It Is Important

Real apps need durable data for users, orders, notes, logs, and analytics.

### SQLite

SQLite is a small database stored in a file.

```python
import sqlite3

with sqlite3.connect("notes.db") as connection:
    connection.execute(
        "CREATE TABLE IF NOT EXISTS notes (id INTEGER PRIMARY KEY, text TEXT)"
    )
    connection.execute("INSERT INTO notes (text) VALUES (?)", ("Learn SQLite",))

    rows = connection.execute("SELECT id, text FROM notes").fetchall()
    print(rows)
```

### PostgreSQL Basics

PostgreSQL is a powerful server database. In Python, teams commonly use `psycopg`, SQLAlchemy, or async drivers.

Typical concepts:

- Database server
- Database name
- Tables
- SQL queries
- Connection string
- Transactions
- Migrations

### SQLAlchemy Overview

SQLAlchemy can be used as a SQL toolkit or ORM.

```python
from sqlalchemy import create_engine, text

engine = create_engine("sqlite:///app.db")

with engine.begin() as connection:
    connection.execute(text("CREATE TABLE IF NOT EXISTS items (name TEXT)"))
    connection.execute(text("INSERT INTO items (name) VALUES (:name)"), {"name": "Pen"})
```

### Common Mistakes

- Building SQL with f-strings and user input.
- Forgetting transactions.
- Keeping database connections open forever.
- Skipping migrations in real apps.

### Best Practices

- Use parameterized queries.
- Use transactions for related changes.
- Use migrations for schema changes.
- Keep database logic in a repository or data access layer.

### Practice Exercises

1. Create a SQLite table for tasks.
2. Insert and list tasks.
3. Update a task as done.
4. Use parameterized SQL.

## Testing

### What It Means

Testing checks that code behaves as expected.

### Why It Is Important

Tests prevent regressions, document expected behavior, and make refactoring safer.

### unittest

```python
import unittest


def add(a, b):
    return a + b


class TestAdd(unittest.TestCase):
    def test_adds_numbers(self):
        self.assertEqual(add(2, 3), 5)


if __name__ == "__main__":
    unittest.main()
```

### pytest

```python
def add(a, b):
    return a + b


def test_adds_numbers():
    assert add(2, 3) == 5
```

Run:

```bash
pytest
```

### Mocking

```python
from unittest.mock import Mock


sender = Mock()
sender.send.return_value = True

sender.send("user@example.com", "Hi")
sender.send.assert_called_once()
```

### Test Coverage

Coverage measures how much code tests execute.

```bash
coverage run -m pytest
coverage report
```

### Real-World Example

```python
def calculate_discount(total, is_premium):
    if total < 0:
        raise ValueError("Total cannot be negative")
    if is_premium:
        return total * 0.15
    if total >= 1000:
        return total * 0.10
    return 0


def test_premium_discount():
    assert calculate_discount(1000, True) == 150


def test_negative_total_raises():
    import pytest

    with pytest.raises(ValueError):
        calculate_discount(-1, False)
```

### Common Mistakes

- Only testing happy paths.
- Testing implementation details instead of behavior.
- Relying on network or real databases in unit tests.

### Best Practices

- Test pure logic heavily.
- Use mocks for external services.
- Keep tests readable.
- Add regression tests when fixing bugs.

### Practice Exercises

1. Test a calculator function.
2. Test invalid inputs.
3. Mock an email sender.

## Debugging

### What It Means

Debugging means finding and fixing defects.

### Why It Is Important

Every developer spends significant time debugging. Good debugging is systematic.

### print Debugging

```python
total = 0
for price in [100, 200]:
    total += price
    print("DEBUG total:", total)
```

### pdb

```python
import pdb

def divide(a, b):
    pdb.set_trace()
    return a / b
```

### IDE Debugger

An IDE debugger lets you set breakpoints, inspect variables, step through code, and evaluate expressions.

### Real-World Strategy

1. Reproduce the bug.
2. Reduce it to a small case.
3. Inspect state.
4. Form a hypothesis.
5. Change one thing.
6. Add a test.

### Common Mistakes

- Changing many things at once.
- Guessing without observing values.
- Ignoring stack traces.

### Best Practices

- Read the full error message.
- Use breakpoints for complex flow.
- Add tests for fixed bugs.

### Practice Exercise

Debug a function that divides by zero for empty input.

## Logging

### What It Means

Logging records events from a program.

### Why It Is Important

Logs help understand production behavior, failures, performance, and audit trails.

### Syntax

```python
import logging

logging.basicConfig(level=logging.INFO)
logging.info("Application started")
```

### Simple Example

```python
import logging

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s %(levelname)s %(message)s",
)

logging.info("Starting job")
logging.warning("Missing optional setting")
```

### Real-World Example

```python
import logging

logger = logging.getLogger(__name__)


def process_order(order_id):
    logger.info("Processing order %s", order_id)
    try:
        return {"order_id": order_id, "status": "processed"}
    except Exception:
        logger.exception("Failed to process order %s", order_id)
        raise
```

### Common Mistakes

- Using `print` for production diagnostics.
- Logging secrets.
- Catching errors and logging without re-raising when failure matters.

### Best Practices

- Use module-level loggers.
- Use structured messages.
- Use `logger.exception` inside exception handlers.
- Never log passwords, tokens, or full credit card numbers.

### Practice Exercises

1. Add logging to the expense tracker.
2. Log errors when file reading fails.
3. Configure logs to write to a file.

## Performance Optimization

### What It Means

Performance optimization makes code faster or more memory-efficient.

### Why It Is Important

Slow code costs time, money, and user trust. But premature optimization creates complexity.

### timeit

```python
import timeit

elapsed = timeit.timeit("sum(range(1000))", number=10_000)
print(elapsed)
```

### Profiling

```python
import cProfile


def work():
    return sum(number * number for number in range(1_000_000))


cProfile.run("work()")
```

### Big O Basics

Big O describes how work grows with input size.

- `O(1)`: constant time
- `O(n)`: linear time
- `O(n^2)`: nested loop style growth
- `O(log n)`: logarithmic growth

Example:

```python
names = {"asha", "ravi", "meera"}
print("asha" in names)  # usually much faster than list membership for large data
```

### Optimizing Loops

```python
# Prefer this
squares = [number * number for number in range(1000)]
```

### Caching

```python
from functools import lru_cache


@lru_cache(maxsize=128)
def fibonacci(number):
    if number < 2:
        return number
    return fibonacci(number - 1) + fibonacci(number - 2)
```

### Common Mistakes

- Optimizing without profiling.
- Choosing clever code over clear code for tiny gains.
- Using lists for large membership tests.

### Best Practices

- Measure first.
- Improve algorithms before micro-optimizing.
- Use caching for repeated expensive pure functions.
- Consider libraries like NumPy for numeric work.

### Practice Exercises

1. Compare list membership vs set membership.
2. Profile a slow function.
3. Add `lru_cache` to a recursive function.

## Packaging Python Projects

### What It Means

Packaging organizes Python code so it can be installed, reused, and distributed.

### Why It Is Important

Professional projects need clear metadata, dependencies, entry points, and reproducible installs.

### Modern pyproject.toml Example

```toml
[project]
name = "notes-cli"
version = "0.1.0"
description = "A simple notes CLI"
requires-python = ">=3.12"
dependencies = []

[project.scripts]
notes = "notes_cli.main:main"
```

### Project Layout

```text
notes-cli/
  pyproject.toml
  README.md
  src/
    notes_cli/
      __init__.py
      main.py
  tests/
    test_notes.py
```

### Common Mistakes

- Importing from the current directory in a way that fails after packaging.
- Missing project metadata.
- Mixing source code, tests, and generated files chaotically.

### Best Practices

- Use `pyproject.toml`.
- Use `src/` layout for packages.
- Include a README.
- Pin or constrain dependencies for applications.

### Practice Exercise

Create a small package with one console script.

## Command-Line Tools

### What It Means

A command-line tool accepts arguments and runs from the terminal.

### Why It Is Important

CLIs are excellent for automation, developer tools, data jobs, and operations scripts.

### argparse Example

```python
import argparse


def main():
    parser = argparse.ArgumentParser(description="Greet a user")
    parser.add_argument("name")
    parser.add_argument("--shout", action="store_true")
    args = parser.parse_args()

    message = f"Hello, {args.name}"
    if args.shout:
        message = message.upper()
    print(message)


if __name__ == "__main__":
    main()
```

### Real-World Example

```bash
python greet.py Yash --shout
```

### Common Mistakes

- Parsing `sys.argv` manually for complex tools.
- No help text.
- Returning vague error messages.

### Best Practices

- Use `argparse` for standard CLIs.
- Exit with non-zero status for failures.
- Keep command behavior scriptable.

### Practice Exercise

Create a CLI that counts lines, words, and characters in a file.

## Environment Variables And Configuration

### What It Means

Environment variables store configuration outside source code.

### Why It Is Important

They keep secrets and environment-specific settings out of code.

### Syntax

```python
import os

api_key = os.environ.get("API_KEY")
```

### Real-World Example

```python
import os


def get_database_url():
    database_url = os.environ.get("DATABASE_URL")
    if database_url is None:
        raise RuntimeError("DATABASE_URL is required")
    return database_url
```

### Common Mistakes

- Hardcoding secrets.
- Not validating required configuration.
- Committing `.env` files with real secrets.

### Best Practices

- Use environment variables for secrets.
- Provide example files like `.env.example`.
- Validate configuration at startup.

### Practice Exercise

Read an API key from an environment variable and fail clearly if missing.

## Security Basics

### What It Means

Security basics are habits that prevent common vulnerabilities.

### Why It Is Important

Even small Python scripts can leak secrets, corrupt files, expose APIs, or mishandle user data.

### Avoiding Hardcoded Secrets

Bad:

```python
API_KEY = "real-secret-key"
```

Better:

```python
import os

API_KEY = os.environ["API_KEY"]
```

### Input Validation

```python
def parse_quantity(value):
    quantity = int(value)
    if quantity <= 0:
        raise ValueError("Quantity must be positive")
    return quantity
```

### Secure Password Handling

Do not store plain-text passwords. Use proven password hashing libraries such as `bcrypt` or `argon2-cffi` in real apps.

Conceptual example:

```python
# Real apps should use a dedicated password hashing library.
```

### Dependency Safety

```bash
python -m pip install --upgrade pip
python -m pip audit
```

### Common Mistakes

- Logging secrets.
- Building SQL with user input.
- Trusting client-side validation only.
- Installing abandoned packages without review.

### Best Practices

- Validate inputs at boundaries.
- Use parameterized SQL.
- Store secrets outside code.
- Keep dependencies updated.
- Use HTTPS for network calls.

### Practice Exercises

1. Refactor hardcoded API keys to environment variables.
2. Validate user registration input.
3. Replace string-built SQL with parameterized SQL.

## Advanced Mini Projects

### Project 8: Web Scraper

#### Goal

Scrape article titles from a web page.

#### Features

- Fetch a page.
- Parse HTML.
- Extract titles.
- Save results to JSON.

#### Required Concepts

`requests`, BeautifulSoup, file handling, JSON, error handling.

#### Full Code

```python
import json
from pathlib import Path

import requests
from bs4 import BeautifulSoup


def fetch_html(url):
    response = requests.get(url, timeout=10)
    response.raise_for_status()
    return response.text


def extract_headings(html):
    soup = BeautifulSoup(html, "html.parser")
    return [heading.get_text(strip=True) for heading in soup.find_all(["h1", "h2"])]


def save_json(data, path):
    Path(path).write_text(json.dumps(data, indent=2), encoding="utf-8")


def main():
    url = input("URL: ")
    try:
        html = fetch_html(url)
    except requests.RequestException as error:
        print(f"Fetch failed: {error}")
        return

    headings = extract_headings(html)
    save_json(headings, "headings.json")
    print(f"Saved {len(headings)} headings")


if __name__ == "__main__":
    main()
```

#### Explanation

The scraper fetches HTML, parses it with BeautifulSoup, extracts heading text, and writes JSON output.

#### Possible Improvements

- Respect `robots.txt`.
- Add rate limiting.
- Add tests using saved HTML fixtures.
- Use Selenium only when JavaScript rendering is required.

### Project 9: Flask Or FastAPI REST API

#### Goal

Build a small REST API for tasks.

#### Features

- List tasks.
- Create tasks.
- Mark tasks done.
- Return JSON.

#### Required Concepts

APIs, HTTP methods, JSON, type hints, web framework basics.

#### Full Code: FastAPI Version

```python
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel


app = FastAPI()


class TaskCreate(BaseModel):
    title: str


class Task(BaseModel):
    id: int
    title: str
    done: bool = False


tasks: list[Task] = []
next_id = 1


@app.get("/tasks")
def list_tasks() -> list[Task]:
    return tasks


@app.post("/tasks", status_code=201)
def create_task(payload: TaskCreate) -> Task:
    global next_id
    task = Task(id=next_id, title=payload.title)
    next_id += 1
    tasks.append(task)
    return task


@app.patch("/tasks/{task_id}/done")
def mark_done(task_id: int) -> Task:
    for task in tasks:
        if task.id == task_id:
            task.done = True
            return task
    raise HTTPException(status_code=404, detail="Task not found")
```

Run:

```bash
uvicorn main:app --reload
```

#### Explanation

FastAPI maps functions to HTTP routes. Pydantic models validate request and response data.

#### Possible Improvements

- Use SQLite instead of memory.
- Add tests with `TestClient`.
- Add authentication.
- Add pagination.

### Project 10: SQLite-Based Notes App

#### Goal

Build a CLI notes app backed by SQLite.

#### Features

- Add note.
- List notes.
- Search notes.
- Delete note.

#### Required Concepts

SQLite, SQL, CLI menus, functions, parameterized queries.

#### Full Code

```python
import sqlite3


DB_PATH = "notes.db"


def connect():
    return sqlite3.connect(DB_PATH)


def initialize():
    with connect() as connection:
        connection.execute(
            """
            CREATE TABLE IF NOT EXISTS notes (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                text TEXT NOT NULL
            )
            """
        )


def add_note(text):
    with connect() as connection:
        connection.execute("INSERT INTO notes (text) VALUES (?)", (text,))


def list_notes():
    with connect() as connection:
        return connection.execute("SELECT id, text FROM notes ORDER BY id").fetchall()


def search_notes(term):
    with connect() as connection:
        return connection.execute(
            "SELECT id, text FROM notes WHERE text LIKE ?",
            (f"%{term}%",),
        ).fetchall()


def delete_note(note_id):
    with connect() as connection:
        connection.execute("DELETE FROM notes WHERE id = ?", (note_id,))


def main():
    initialize()

    while True:
        print("\n1. Add")
        print("2. List")
        print("3. Search")
        print("4. Delete")
        print("5. Quit")

        choice = input("Choose: ")

        if choice == "1":
            add_note(input("Note: "))
        elif choice == "2":
            for note_id, text in list_notes():
                print(f"{note_id}. {text}")
        elif choice == "3":
            for note_id, text in search_notes(input("Search: ")):
                print(f"{note_id}. {text}")
        elif choice == "4":
            delete_note(int(input("ID: ")))
        elif choice == "5":
            break


if __name__ == "__main__":
    main()
```

#### Explanation

SQLite stores notes in a database file. Parameterized queries prevent SQL injection and handle quoting.

#### Possible Improvements

- Add timestamps.
- Add tags.
- Add tests with temporary databases.
- Package as a CLI.

## Advanced Interview Questions

1. What is the GIL?
2. When would you use multiprocessing instead of threading?
3. What is a decorator with arguments?
4. What is a descriptor?
5. What is a metaclass?
6. What is the difference between shallow copy and deep copy?
7. Why are mutable default arguments dangerous?
8. What is dependency injection?
9. How do you prevent SQL injection?
10. How do you profile Python code?

Sample answers:

- The GIL is a lock in CPython that allows only one thread to execute Python bytecode at a time.
- Multiprocessing is useful for CPU-bound work because it can use multiple CPU cores.
- Parameterized SQL prevents user input from being interpreted as SQL code.

---

# Professional And Real-World Python

Professional Python is about building useful systems: web services, data workflows, automation, tools, integrations, deployment, maintainability, and collaboration.

## Web Development Overview

### What It Means

Web development uses Python to build websites, APIs, admin systems, and backend services.

### Why It Is Important

Many Python jobs involve backend development, internal tools, automation APIs, or data-backed web apps.

### Flask

Flask is lightweight and flexible.

```python
from flask import Flask, jsonify

app = Flask(__name__)


@app.get("/health")
def health():
    return jsonify({"status": "ok"})
```

### FastAPI

FastAPI is modern, typed, and great for APIs.

```python
from fastapi import FastAPI

app = FastAPI()


@app.get("/health")
def health():
    return {"status": "ok"}
```

### Django

Django is a full-featured framework with ORM, admin, authentication, templates, and many built-ins.

### Common Mistakes

- Putting all logic in route functions.
- Skipping input validation.
- Returning inconsistent response shapes.
- Hardcoding configuration.

### Best Practices

- Keep routes thin.
- Put business logic in services.
- Validate request data.
- Use environment variables for settings.
- Add tests for endpoints.

### Practice Exercises

1. Build a `/health` endpoint.
2. Build CRUD endpoints for notes.
3. Add input validation.

## Data Science Overview

### What It Means

Data science uses Python to clean, analyze, visualize, and model data.

### Why It Is Important

Python is one of the main languages for analytics, reporting, machine learning, and scientific computing.

### NumPy

```python
import numpy as np

values = np.array([1, 2, 3])
print(values.mean())
```

### Pandas

```python
import pandas as pd

df = pd.DataFrame(
    [
        {"product": "Pen", "sales": 100},
        {"product": "Notebook", "sales": 250},
    ]
)

print(df.groupby("product")["sales"].sum())
```

### Matplotlib

```python
import matplotlib.pyplot as plt

plt.plot([1, 2, 3], [10, 20, 15])
plt.title("Sales Trend")
plt.show()
```

### Seaborn

```python
import seaborn as sns

sns.set_theme()
```

### Common Mistakes

- Not inspecting missing values.
- Confusing correlation with causation.
- Modifying data without preserving the raw source.

### Best Practices

- Keep raw data unchanged.
- Document cleaning steps.
- Use clear charts with labels.
- Validate assumptions.

### Practice Exercises

1. Load a CSV with Pandas.
2. Show summary statistics.
3. Plot sales by month.

## Automation Scripts

### What It Means

Automation scripts perform repetitive tasks.

### Why It Is Important

Automation saves time and reduces human error.

### Example

```python
from pathlib import Path

for path in Path(".").glob("*.txt"):
    print(path.name, path.stat().st_size)
```

### Real-World Example

```python
from pathlib import Path


def rename_reports(folder):
    for path in Path(folder).glob("report_*.txt"):
        new_name = path.name.replace("report_", "archive_report_")
        path.rename(path.with_name(new_name))
```

### Common Mistakes

- Running destructive scripts without a dry run.
- Not handling spaces and unusual file names.
- Hardcoding paths.

### Best Practices

- Add dry-run mode.
- Log actions.
- Test on sample folders first.
- Use `pathlib`.

### Practice Exercise

Write a script that finds files larger than 10 MB.

## Web Scraping

### What It Means

Web scraping extracts data from websites.

### Why It Is Important

Scraping is useful for research, monitoring, migration, and data collection when an API is unavailable.

### requests

```python
import requests

response = requests.get("https://example.com", timeout=10)
print(response.text[:100])
```

### BeautifulSoup

```python
from bs4 import BeautifulSoup

soup = BeautifulSoup("<h1>Hello</h1>", "html.parser")
print(soup.h1.get_text())
```

### Selenium Overview

Selenium controls a real browser. Use it when the page requires JavaScript interaction that simple HTTP requests cannot capture.

### Common Mistakes

- Ignoring terms of service.
- Sending too many requests too quickly.
- Parsing HTML with regex.
- Not setting timeouts.

### Best Practices

- Prefer official APIs when available.
- Respect robots and rate limits.
- Cache pages during development.
- Use Selenium only when needed.

### Practice Exercises

1. Extract all links from a page.
2. Save scraped data to CSV.
3. Add a delay between requests.

## API Development

### What It Means

API development creates endpoints that other software can call.

### Why It Is Important

APIs connect frontends, mobile apps, partners, microservices, and automation.

### Example Endpoint

```python
from fastapi import FastAPI

app = FastAPI()


@app.get("/users/{user_id}")
def get_user(user_id: int):
    return {"id": user_id, "name": "Demo User"}
```

### Real-World Concerns

- Status codes
- Validation
- Authentication
- Authorization
- Pagination
- Rate limiting
- Logging
- Monitoring
- Versioning

### Common Mistakes

- Returning `200 OK` for errors.
- No validation.
- Leaking internal exception messages.
- Missing tests.

### Best Practices

- Use proper HTTP status codes.
- Validate inputs.
- Keep response models consistent.
- Document APIs.
- Test endpoints.

### Practice Exercise

Build an API for notes with create, list, update, and delete endpoints.

## Building CLI Apps

### What It Means

A CLI app is a command-line interface with arguments, help, and predictable output.

### Why It Is Important

Professional Python teams build internal tools, migration scripts, release tools, and admin utilities as CLIs.

### Example

```python
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--name", required=True)
    args = parser.parse_args()
    print(f"Hello, {args.name}")
```

### Common Mistakes

- Interactive prompts in scripts that need automation.
- No exit codes.
- Output that is hard to parse.

### Best Practices

- Support arguments for automation.
- Use prompts only for human-first tools.
- Print clear errors to stderr for serious CLIs.
- Add `--help`.

### Practice Exercise

Build a CLI that converts CSV to JSON.

## Working With Excel Files

### What It Means

Python can read and write Excel workbooks.

### Why It Is Important

Many businesses run on spreadsheets. Python can automate reporting and cleanup.

### openpyxl Example

```python
from openpyxl import Workbook

workbook = Workbook()
sheet = workbook.active
sheet["A1"] = "Product"
sheet["B1"] = "Sales"
sheet.append(["Pen", 100])
workbook.save("sales.xlsx")
```

### pandas Example

```python
import pandas as pd

df = pd.read_excel("sales.xlsx")
print(df.head())
```

### Common Mistakes

- Treating Excel as a database.
- Losing formatting when using the wrong tool.
- Not validating column names.

### Best Practices

- Use Pandas for data analysis.
- Use openpyxl for workbook formatting.
- Validate required columns.

### Practice Exercise

Read an Excel file and calculate total sales.

## Working With PDFs

### What It Means

Python can extract text, merge PDFs, split PDFs, and generate reports.

### Why It Is Important

Invoices, forms, statements, and reports are often PDFs.

### Example

```python
from pypdf import PdfReader

reader = PdfReader("document.pdf")
text = reader.pages[0].extract_text()
print(text)
```

### Common Mistakes

- Expecting perfect text extraction from scanned PDFs.
- Ignoring OCR requirements.
- Losing layout information.

### Best Practices

- Use OCR for scanned documents.
- Validate extracted text.
- Keep original PDFs.

### Practice Exercise

Extract text from every page of a PDF and save it to a `.txt` file.

## Sending Emails With Python

### What It Means

Python can send email through SMTP or email APIs.

### Why It Is Important

Apps send alerts, reports, invoices, password resets, and notifications.

### SMTP Example

```python
import smtplib
from email.message import EmailMessage


message = EmailMessage()
message["Subject"] = "Test email"
message["From"] = "sender@example.com"
message["To"] = "receiver@example.com"
message.set_content("Hello from Python")

with smtplib.SMTP_SSL("smtp.example.com", 465) as smtp:
    smtp.login("sender@example.com", "password")
    smtp.send_message(message)
```

### Common Mistakes

- Hardcoding email passwords.
- Sending too many emails without rate limits.
- Not handling delivery failures.

### Best Practices

- Use app passwords or email APIs.
- Store credentials in environment variables.
- Log message IDs, not sensitive content.

### Practice Exercise

Create a function that builds an email message without sending it.

## Building Bots

### What It Means

Bots automate conversations or actions on platforms such as Slack, Discord, Telegram, or internal chat systems.

### Why It Is Important

Bots can alert teams, answer common questions, trigger workflows, and integrate systems.

### Conceptual Example

```python
def handle_message(text):
    if text.lower() == "status":
        return "All systems operational"
    return "Unknown command"
```

### Common Mistakes

- Trusting all user input.
- No rate limiting.
- Logging private messages.
- Mixing platform code and business logic.

### Best Practices

- Validate commands.
- Keep bot logic testable.
- Use environment variables for tokens.
- Respect privacy and platform rules.

### Practice Exercise

Build a command handler for `help`, `status`, and `echo`.

## Deployment Basics

### What It Means

Deployment means running your Python app where users or jobs can access it.

### Why It Is Important

Code only delivers value when it runs reliably outside your laptop.

### Common Deployment Targets

- Virtual machines
- Containers
- Platform-as-a-service
- Serverless functions
- Scheduled job runners

### Real-World Checklist

- Dependencies installed
- Environment variables configured
- Database reachable
- Logs collected
- Health check available
- Error reporting enabled
- Backups planned

### Common Mistakes

- Deploying with debug mode on.
- Missing environment variables.
- No logs.
- No rollback plan.

### Best Practices

- Automate deployment.
- Use separate dev, staging, and production settings.
- Add health checks.
- Monitor errors and performance.

### Practice Exercise

Prepare a FastAPI app for deployment with a `/health` endpoint and environment-based settings.

## Docker Basics For Python

### What It Means

Docker packages an app and its dependencies into a container image.

### Why It Is Important

Containers make apps more consistent across machines and deployment environments.

### Dockerfile Example

```dockerfile
FROM python:3.12-slim

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

CMD ["python", "main.py"]
```

### Common Mistakes

- Copying secrets into images.
- Running as root unnecessarily.
- Huge images.
- Not using `.dockerignore`.

### Best Practices

- Use slim base images.
- Keep dependency install layers separate.
- Add `.dockerignore`.
- Use environment variables for config.

### Practice Exercise

Dockerize a simple CLI or FastAPI app.

## Git And GitHub Basics

### What It Means

Git tracks code changes. GitHub hosts repositories and collaboration workflows.

### Why It Is Important

Professional development depends on version control, pull requests, reviews, branches, and history.

### Basic Commands

```bash
git init
git status
git add .
git commit -m "Initial commit"
git branch
git checkout -b feature/tasks
git push
```

### Real-World Workflow

1. Create a branch.
2. Make a focused change.
3. Run tests.
4. Commit with a clear message.
5. Open a pull request.
6. Address review feedback.

### Common Mistakes

- Committing secrets.
- Making huge mixed commits.
- Not pulling latest changes before work.
- Ignoring `.gitignore`.

### Best Practices

- Commit small logical changes.
- Write clear commit messages.
- Review diffs before committing.
- Use branches for features.

### Practice Exercise

Create a repository for the notes app and commit it with a README.

## Code Formatting And Linting

### What It Means

Formatters rewrite code style. Linters detect problems.

### Why It Is Important

Consistent code is easier to read and review. Linters catch bugs and maintain standards.

### black

```bash
black .
```

### isort

```bash
isort .
```

### flake8

```bash
flake8 .
```

### ruff

```bash
ruff check .
ruff format .
```

### Common Mistakes

- Debating style manually instead of automating it.
- Running formatters only after huge changes.
- Ignoring lint warnings without understanding them.

### Best Practices

- Use `ruff` for fast linting and formatting in many modern projects.
- Run tools before committing.
- Add tools to CI for teams.

### Practice Exercise

Run a formatter and linter on one of your projects.

## Project Structure Best Practices

### What It Means

Project structure organizes source code, tests, configuration, documentation, and scripts.

### Why It Is Important

Clear structure makes projects easier to run, test, package, and maintain.

### Example Structure

```text
my_project/
  README.md
  pyproject.toml
  .gitignore
  src/
    my_project/
      __init__.py
      main.py
      services.py
      repositories.py
  tests/
    test_services.py
  docs/
  scripts/
```

### Common Mistakes

- One giant `main.py`.
- Tests mixed randomly with source files.
- Configuration scattered across code.
- No README.

### Best Practices

- Keep source in `src/`.
- Keep tests in `tests/`.
- Put docs in `docs/`.
- Put throwaway helpers in `scripts/`.
- Add a README with setup and usage.

### Practice Exercise

Refactor one mini project into a clean package structure.

## Real-World Projects

### Project 11: Data Analysis Project Using Pandas

#### Goal

Analyze sales data and produce a summary report.

#### Features

- Load CSV sales data.
- Clean column names.
- Calculate total sales.
- Group by product and month.
- Save summary CSV.
- Plot a chart.

#### Required Concepts

Pandas, file handling, grouping, plotting, project structure.

#### Full Code

```python
from pathlib import Path

import matplotlib.pyplot as plt
import pandas as pd


DATA_FILE = Path("sales.csv")
OUTPUT_DIR = Path("output")


def load_sales(path):
    df = pd.read_csv(path)
    df.columns = [column.strip().lower().replace(" ", "_") for column in df.columns]
    df["date"] = pd.to_datetime(df["date"])
    df["sales"] = df["quantity"] * df["unit_price"]
    return df


def summarize(df):
    by_product = df.groupby("product", as_index=False)["sales"].sum()
    by_month = (
        df.assign(month=df["date"].dt.to_period("M").astype(str))
        .groupby("month", as_index=False)["sales"]
        .sum()
    )
    return by_product, by_month


def save_outputs(by_product, by_month):
    OUTPUT_DIR.mkdir(exist_ok=True)
    by_product.to_csv(OUTPUT_DIR / "sales_by_product.csv", index=False)
    by_month.to_csv(OUTPUT_DIR / "sales_by_month.csv", index=False)

    plt.figure(figsize=(8, 4))
    plt.bar(by_product["product"], by_product["sales"])
    plt.title("Sales by Product")
    plt.xlabel("Product")
    plt.ylabel("Sales")
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "sales_by_product.png")


def main():
    df = load_sales(DATA_FILE)
    by_product, by_month = summarize(df)
    save_outputs(by_product, by_month)
    print("Analysis complete")


if __name__ == "__main__":
    main()
```

#### Explanation

The project loads data, normalizes columns, creates a sales column, groups results, saves CSV summaries, and generates a chart.

#### Possible Improvements

- Validate required columns.
- Add command-line arguments.
- Add tests for transformation functions.
- Generate an HTML report.

### Project 12: Final Advanced Project - Production-Style Notes API

#### Goal

Build a small but professional notes API combining API design, database access, testing, logging, configuration, and deployment basics.

#### Features

- FastAPI app.
- SQLite database.
- CRUD notes.
- Pydantic models.
- Logging.
- Environment-based database path.
- Tests.
- Dockerfile.

#### Required Concepts

FastAPI, SQLite, type hints, repositories, tests, logging, environment variables, Docker.

#### Suggested Structure

```text
notes_api/
  pyproject.toml
  README.md
  Dockerfile
  src/
    notes_api/
      __init__.py
      config.py
      database.py
      main.py
      models.py
      repository.py
  tests/
    test_api.py
```

#### Full Code: `src/notes_api/config.py`

```python
import os
from dataclasses import dataclass


@dataclass(frozen=True)
class Settings:
    database_path: str = os.environ.get("NOTES_DB", "notes.db")
```

#### Full Code: `src/notes_api/database.py`

```python
import sqlite3
from collections.abc import Iterator
from contextlib import contextmanager

from .config import Settings


settings = Settings()


@contextmanager
def connect() -> Iterator[sqlite3.Connection]:
    connection = sqlite3.connect(settings.database_path)
    connection.row_factory = sqlite3.Row
    try:
        yield connection
        connection.commit()
    finally:
        connection.close()


def initialize_database() -> None:
    with connect() as connection:
        connection.execute(
            """
            CREATE TABLE IF NOT EXISTS notes (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                title TEXT NOT NULL,
                body TEXT NOT NULL,
                done INTEGER NOT NULL DEFAULT 0
            )
            """
        )
```

#### Full Code: `src/notes_api/models.py`

```python
from pydantic import BaseModel, Field


class NoteCreate(BaseModel):
    title: str = Field(min_length=1, max_length=100)
    body: str = Field(min_length=1)


class NoteUpdate(BaseModel):
    title: str | None = Field(default=None, min_length=1, max_length=100)
    body: str | None = Field(default=None, min_length=1)
    done: bool | None = None


class Note(BaseModel):
    id: int
    title: str
    body: str
    done: bool
```

#### Full Code: `src/notes_api/repository.py`

```python
from .database import connect
from .models import Note, NoteCreate, NoteUpdate


def row_to_note(row) -> Note:
    return Note(
        id=row["id"],
        title=row["title"],
        body=row["body"],
        done=bool(row["done"]),
    )


def create_note(payload: NoteCreate) -> Note:
    with connect() as connection:
        cursor = connection.execute(
            "INSERT INTO notes (title, body) VALUES (?, ?)",
            (payload.title, payload.body),
        )
        note_id = cursor.lastrowid
        row = connection.execute("SELECT * FROM notes WHERE id = ?", (note_id,)).fetchone()
        return row_to_note(row)


def list_notes() -> list[Note]:
    with connect() as connection:
        rows = connection.execute("SELECT * FROM notes ORDER BY id DESC").fetchall()
        return [row_to_note(row) for row in rows]


def get_note(note_id: int) -> Note | None:
    with connect() as connection:
        row = connection.execute("SELECT * FROM notes WHERE id = ?", (note_id,)).fetchone()
        return row_to_note(row) if row else None


def update_note(note_id: int, payload: NoteUpdate) -> Note | None:
    current = get_note(note_id)
    if current is None:
        return None

    title = payload.title if payload.title is not None else current.title
    body = payload.body if payload.body is not None else current.body
    done = payload.done if payload.done is not None else current.done

    with connect() as connection:
        connection.execute(
            "UPDATE notes SET title = ?, body = ?, done = ? WHERE id = ?",
            (title, body, int(done), note_id),
        )
        row = connection.execute("SELECT * FROM notes WHERE id = ?", (note_id,)).fetchone()
        return row_to_note(row)


def delete_note(note_id: int) -> bool:
    with connect() as connection:
        cursor = connection.execute("DELETE FROM notes WHERE id = ?", (note_id,))
        return cursor.rowcount > 0
```

#### Full Code: `src/notes_api/main.py`

```python
import logging

from fastapi import FastAPI, HTTPException, Response

from .database import initialize_database
from .models import Note, NoteCreate, NoteUpdate
from . import repository


logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

app = FastAPI(title="Notes API")


@app.on_event("startup")
def startup() -> None:
    initialize_database()
    logger.info("Database initialized")


@app.get("/health")
def health() -> dict[str, str]:
    return {"status": "ok"}


@app.post("/notes", response_model=Note, status_code=201)
def create_note(payload: NoteCreate) -> Note:
    return repository.create_note(payload)


@app.get("/notes", response_model=list[Note])
def list_notes() -> list[Note]:
    return repository.list_notes()


@app.get("/notes/{note_id}", response_model=Note)
def get_note(note_id: int) -> Note:
    note = repository.get_note(note_id)
    if note is None:
        raise HTTPException(status_code=404, detail="Note not found")
    return note


@app.patch("/notes/{note_id}", response_model=Note)
def update_note(note_id: int, payload: NoteUpdate) -> Note:
    note = repository.update_note(note_id, payload)
    if note is None:
        raise HTTPException(status_code=404, detail="Note not found")
    return note


@app.delete("/notes/{note_id}", status_code=204)
def delete_note(note_id: int) -> Response:
    deleted = repository.delete_note(note_id)
    if not deleted:
        raise HTTPException(status_code=404, detail="Note not found")
    return Response(status_code=204)
```

#### Full Code: `tests/test_api.py`

```python
import os

os.environ["NOTES_DB"] = ":memory:"

from fastapi.testclient import TestClient

from notes_api.main import app


client = TestClient(app)


def test_health():
    response = client.get("/health")
    assert response.status_code == 200
    assert response.json() == {"status": "ok"}
```

#### Full Code: `Dockerfile`

```dockerfile
FROM python:3.12-slim

WORKDIR /app

COPY pyproject.toml .
COPY src ./src
RUN pip install --no-cache-dir .

CMD ["uvicorn", "notes_api.main:app", "--host", "0.0.0.0", "--port", "8000"]
```

#### Explanation

This project separates API routes, models, repository logic, configuration, and database setup. It uses parameterized SQL, typed request models, logging, tests, and container deployment basics.

#### Possible Improvements

- Add Alembic migrations.
- Add authentication.
- Add pagination and search.
- Add CI.
- Add structured JSON logging.
- Use PostgreSQL in production.

## Professional Interview Questions

1. How would you structure a production Python project?
2. What belongs in environment variables?
3. How do Flask, FastAPI, and Django differ?
4. How do you handle database migrations?
5. What is the difference between unit and integration tests?
6. How do you deploy a Python API?
7. How do you protect secrets?
8. How do you debug a production issue?
9. How do you make a script safe before moving files?
10. What tools do you use for formatting and linting?

Sample answers:

- Flask is minimal, FastAPI is modern and typed for APIs, and Django is full-featured.
- Secrets, database URLs, and environment-specific settings belong in environment variables.
- Unit tests isolate small logic; integration tests verify components working together.

---

# Final Job-Ready Roadmap

## Phase 1: Core Programming

Focus:

- Variables, types, input/output
- Strings
- Conditionals
- Loops
- Lists, dictionaries, sets, tuples
- Functions

Build:

- Calculator
- Number guessing game
- To-do list
- Contact book

Checkpoint:

- You can solve beginner problems without copying.
- You can explain every line of your code.

## Phase 2: Practical Python

Focus:

- Error handling
- Files, CSV, JSON
- Modules and packages
- Virtual environments
- OOP basics
- Dataclasses and type hints

Build:

- Expense tracker
- File organizer
- JSON-backed contact manager

Checkpoint:

- You can create a multi-file Python project.
- You use virtual environments.
- You can persist data to files.

## Phase 3: Professional Foundations

Focus:

- Testing with pytest
- Logging
- Debugging
- pathlib, os, sys
- CLI apps
- SQLite
- APIs with FastAPI or Flask

Build:

- SQLite notes app
- FastAPI task API
- CLI data converter

Checkpoint:

- You can write tests for important logic.
- You can debug errors from tracebacks.
- You can build a working API with persistence.

## Phase 4: Advanced Capability

Focus:

- Decorators
- Generators
- Context managers
- Concurrency
- Performance profiling
- Design principles
- Security basics

Build:

- Web scraper
- Concurrent downloader
- Production-style notes API

Checkpoint:

- You choose the right tool for I/O-bound vs CPU-bound work.
- You profile before optimizing.
- You avoid hardcoded secrets and SQL injection.

## Phase 5: Real-World Specialization

Choose one primary path:

### Backend Python

Learn:

- FastAPI or Django
- PostgreSQL
- SQLAlchemy
- Authentication
- Docker
- Deployment
- CI/CD

Portfolio:

- REST API with database, tests, Docker, README, and deployed demo.

### Data Python

Learn:

- NumPy
- Pandas
- Matplotlib
- Seaborn
- Jupyter
- Data cleaning
- Statistics basics

Portfolio:

- Data analysis project with clean notebook, source CSV, charts, and written insights.

### Automation Python

Learn:

- pathlib
- APIs
- Excel/PDF automation
- Scheduling
- Logging
- Error handling

Portfolio:

- Automation toolkit that solves a real repetitive workflow.

## Weekly Study Plan

### Weeks 1-2

- Beginner syntax
- 20 small exercises
- Calculator and guessing game

### Weeks 3-4

- Data structures and functions
- To-do list and contact book
- Start using Git

### Weeks 5-6

- Files, JSON, CSV
- Error handling
- Expense tracker and file organizer

### Weeks 7-8

- OOP, dataclasses, type hints
- SQLite notes app
- pytest basics

### Weeks 9-10

- APIs with FastAPI or Flask
- Logging
- Environment variables
- Docker basics

### Weeks 11-12

- Final project
- Tests
- README
- GitHub cleanup
- Interview practice

## What Job-Ready Looks Like

You are job-ready for junior Python roles when you can:

- Build a complete project from scratch.
- Read documentation and apply it.
- Use Git and GitHub confidently.
- Write clean functions and classes.
- Work with files, APIs, databases, and packages.
- Add tests for core behavior.
- Debug using tracebacks, logs, and breakpoints.
- Explain tradeoffs in your design.
- Keep secrets out of code.
- Package or deploy a small app.

## Final Practice Checklist

- Build one CLI app.
- Build one API app.
- Build one data analysis project.
- Use SQLite or PostgreSQL.
- Write tests with pytest.
- Add logging.
- Use environment variables.
- Format with ruff or black.
- Write a strong README.
- Push polished projects to GitHub.

## Closing Advice

Do not only read Python. Type it, run it, break it, fix it, and explain it. The difference between "I know Python" and "I can work professionally in Python" is repeated practice with real files, real errors, real data, and real project structure.
