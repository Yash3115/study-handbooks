# ML, AI, GenAI, and RAG Interview Roadmap

Personalized preparation plan for ML Engineer, AI Engineer, GenAI Engineer, Data Scientist, and RAG-focused roles.

Current estimated level: early beginner overall, with some useful intuition in machine learning basics, overfitting/underfitting, tokenization, and backpropagation.

Primary goal: build from fundamentals to interview-ready depth across theory, coding, system design, production ML, GenAI, and RAG.

---

## 1. How To Use This Roadmap

This roadmap is designed to be used progressively. Do not jump to advanced topics before the basics are comfortable.

Each topic should be learned using this format:

1. Intuition first
2. Formal explanation
3. Key formulas or algorithms
4. Real-world example
5. Python or code example where useful
6. Common interview questions
7. Tricky follow-up questions
8. Mistakes candidates make
9. Mini quiz
10. Practical assignment

Recommended weekly rhythm:

- 4 days learning new concepts
- 1 day coding practice
- 1 day revision and quizzes
- 1 day mock interview or project work

Recommended session structure:

1. Revise previous topic for 10 minutes
2. Learn one new concept deeply
3. Solve 2 to 4 interview questions
4. Write or read code
5. Explain the topic back in your own words
6. End with homework

---

## 2. Diagnostic Assessment Summary

### 2.1 Math for ML

Current level: beginner.

Strengths:

- You understand that dot product relates to similarity or relationship between vectors.

Gaps:

- Need formula precision.
- Need geometric interpretation.
- Need connection to linear models, embeddings, and attention.

Target:

- Explain vectors, matrices, dot product, norms, cosine similarity, probability, statistics, derivatives, gradients, and optimization.

### 2.2 Python

Current level: beginner.

Strengths:

- You can think through simple logic.
- You understand that mean, median, and frequency-based calculations require different steps.

Gaps:

- Syntax precision.
- Function arguments.
- Sorting.
- Standard deviation.
- Clean implementation.

Target:

- Write clean Python for lists, dictionaries, NumPy, pandas, ML preprocessing, model training, and interview coding.

### 2.3 Machine Learning

Current level: beginner plus.

Strengths:

- Your overfitting and underfitting explanation was good.

Gaps:

- Need model families, metrics, validation, feature engineering, tuning, and classical algorithms.

Target:

- Explain and apply supervised learning, unsupervised learning, regression, classification, clustering, bias-variance, regularization, and evaluation metrics.

### 2.4 Deep Learning

Current level: beginner.

Strengths:

- You know that weights are adjusted to reduce loss.

Gaps:

- Need chain rule, gradients, optimizers, activations, architectures, and training behavior.

Target:

- Understand neural networks, backpropagation, optimizers, CNNs, RNNs, LSTMs, GRUs, attention, transformers, transfer learning, and fine-tuning.

### 2.5 NLP

Current level: beginner.

Strengths:

- You understand tokenization at a high level.

Gaps:

- Need word embeddings, TF-IDF, sequence models, BERT, GPT, text classification, NER, summarization, and semantic search.

Target:

- Build and explain NLP pipelines from classic techniques to transformer-based models.

### 2.6 Transformers and LLMs

Current level: new.

Target:

- Understand attention, self-attention, query-key-value, positional encoding, encoder-only models, decoder-only models, encoder-decoder models, BERT, GPT, pretraining, instruction tuning, RLHF, and inference parameters.

### 2.7 Generative AI

Current level: new.

Target:

- Understand LLM behavior, prompt engineering, fine-tuning, RAG, hallucinations, guardrails, agents, function calling, tool use, and multimodal AI.

### 2.8 RAG

Current level: new.

Target:

- Build and explain production RAG systems including chunking, embeddings, vector databases, retrieval, hybrid search, reranking, query rewriting, context construction, evaluation, security, and monitoring.

### 2.9 Vector Databases and Embeddings

Current level: new.

Target:

- Understand embeddings, vector similarity, approximate nearest neighbor search, metadata filtering, indexing, and vector database tradeoffs.

### 2.10 MLOps and Deployment

Current level: new.

Target:

- Understand deployment, monitoring, drift, experiment tracking, CI/CD, model versioning, feature stores, A/B testing, latency, scalability, and cost optimization.

---

## 3. Full Learning Path Overview

### Phase 1: Core Foundations

Goal: build the foundation required for all ML, DL, NLP, GenAI, and RAG interviews.

Topics:

- Python for ML
- Math for ML
- What machine learning is
- Types of learning
- Regression and classification
- Train/test split
- Evaluation metrics
- Overfitting and underfitting

Outcome:

- You can explain basic ML clearly.
- You can write simple Python code.
- You can understand model training at a high level.

### Phase 2: Classical Machine Learning

Goal: become strong in traditional ML interviews.

Topics:

- Linear regression
- Logistic regression
- k-nearest neighbors
- Naive Bayes
- Decision trees
- Random forests
- Gradient boosting
- XGBoost
- LightGBM
- Clustering
- Dimensionality reduction
- Feature engineering
- Cross-validation
- Hyperparameter tuning

Outcome:

- You can choose models for tabular problems.
- You can evaluate model performance correctly.
- You can discuss tradeoffs in interviews.

### Phase 3: Deep Learning

Goal: understand neural networks and modern deep learning.

Topics:

- Neural network basics
- Backpropagation
- Activation functions
- Loss functions
- Optimizers
- CNNs
- RNNs
- LSTMs
- GRUs
- Attention
- Transformers
- Transfer learning
- Fine-tuning

Outcome:

- You can explain how neural networks learn.
- You can understand architecture choices.
- You can discuss training issues and improvements.

### Phase 4: NLP and LLMs

Goal: move from classical NLP to modern transformer-based LLMs.

Topics:

- Tokenization
- Text preprocessing
- Bag of words
- TF-IDF
- Word2Vec
- GloVe
- Text classification
- Named entity recognition
- Summarization
- Semantic search
- BERT
- GPT-style models
- Encoder vs decoder architectures
- Pretraining and fine-tuning

Outcome:

- You can explain NLP pipelines.
- You can compare classical NLP and transformer-based NLP.
- You can reason about LLM behavior.

### Phase 5: Generative AI Engineering

Goal: prepare for GenAI Engineer interviews.

Topics:

- LLM basics
- Prompt engineering
- Instruction tuning
- RLHF
- Fine-tuning vs prompt engineering vs RAG
- Context windows
- Temperature
- Top-p
- Hallucinations
- Guardrails
- Function calling
- Tool use
- Agents
- Multimodal AI

Outcome:

- You can design LLM applications.
- You can choose between prompting, RAG, and fine-tuning.
- You can discuss reliability, safety, cost, and latency.

### Phase 6: RAG Specialization

Goal: become interview-ready for RAG architecture and implementation.

Topics:

- What RAG is
- Why RAG matters
- Embeddings
- Chunking strategies
- Vector databases
- Similarity search
- Hybrid search
- Reranking
- Query rewriting
- Metadata filtering
- Context construction
- RAG evaluation
- Failure modes
- Production RAG architecture
- Security and privacy

Outcome:

- You can design end-to-end RAG systems.
- You can debug poor retrieval and hallucinations.
- You can discuss production tradeoffs.

### Phase 7: MLOps and Production ML

Goal: understand how ML systems run in the real world.

Topics:

- Model deployment
- Batch inference
- Real-time inference
- Model serving
- Monitoring
- Data drift
- Concept drift
- Experiment tracking
- Model registry
- CI/CD for ML
- Feature stores
- A/B testing
- Latency
- Scalability
- Cost optimization

Outcome:

- You can explain the lifecycle of a production ML system.
- You can monitor and improve deployed models.
- You can answer system design questions with production awareness.

### Phase 8: Interview Mastery

Goal: perform well in real interviews.

Topics:

- Python coding problems
- NumPy and pandas coding
- ML theory questions
- Deep learning questions
- NLP questions
- LLM questions
- RAG system design
- ML system design
- Behavioral explanations
- Mock interviews

Outcome:

- You can answer with structure.
- You can handle follow-up questions.
- You can explain tradeoffs clearly.

---

## 4. Phase 1: Core Foundations

## 4.1 Python for ML

### Intuition

Python is the main language used in ML because it is readable, flexible, and has a strong ecosystem of libraries.

For ML interviews, Python matters in two ways:

1. General coding ability
2. Ability to manipulate data and train models

### Formal Explanation

You should know:

- Variables
- Lists
- Tuples
- Dictionaries
- Sets
- Functions
- Loops
- Comprehensions
- Error handling
- Classes
- NumPy arrays
- pandas DataFrames
- Basic file handling

### Key Skills

- Write clean functions.
- Use list and dictionary operations.
- Sort data.
- Count frequencies.
- Handle edge cases.
- Use NumPy for numerical computation.
- Use pandas for tabular data.

### Example

Calculate mean, median, and population standard deviation.

```python
def summary_stats(nums):
    if not nums:
        raise ValueError("Input list cannot be empty")

    n = len(nums)
    mean = sum(nums) / n

    sorted_nums = sorted(nums)
    mid = n // 2

    if n % 2 == 1:
        median = sorted_nums[mid]
    else:
        median = (sorted_nums[mid - 1] + sorted_nums[mid]) / 2

    variance = sum((x - mean) ** 2 for x in nums) / n
    std = variance ** 0.5

    return mean, median, std
```

### Common Interview Questions

- Reverse a list.
- Find duplicate values.
- Count word frequencies.
- Compute mean, median, and standard deviation.
- Implement train/test split.
- Normalize a list of numbers.
- Implement cosine similarity.
- Process a CSV file with pandas.

### Tricky Follow-Ups

- What happens if the list is empty?
- What is the difference between `list.sort()` and `sorted(list)`?
- What is the difference between a list and a tuple?
- What is the difference between shallow copy and deep copy?
- How does a dictionary work internally?

### Mistakes Candidates Make

- Forgetting edge cases.
- Modifying input data accidentally.
- Confusing `sort()` and `sorted()`.
- Writing code that works only for one example.
- Not explaining time complexity.

### Mini Quiz

1. What does `*args` mean in a Python function?
2. What is the difference between `append` and `extend`?
3. Why is NumPy faster than plain Python loops for many numerical tasks?
4. What does `axis=0` mean in NumPy or pandas?
5. How do you handle missing values in pandas?

### Practical Assignment

Write Python functions for:

1. Mean
2. Median
3. Mode
4. Variance
5. Standard deviation
6. Min-max scaling
7. Z-score standardization
8. Cosine similarity

---

## 4.2 Math for ML

### Intuition

Math helps you understand what models are doing internally.

You do not need to become a mathematician first, but you must understand the core ideas:

- Vectors represent data.
- Matrices represent transformations or batches of data.
- Probability represents uncertainty.
- Statistics helps summarize data.
- Calculus tells us how to optimize.
- Optimization tells us how models learn.

### Formal Explanation

Core areas:

- Linear algebra
- Probability
- Statistics
- Calculus
- Optimization

### Key Concepts

#### Vectors

A vector is a list of numbers.

Example:

```text
x = [2, 4, 6]
```

In ML, a vector can represent:

- A row of features
- An embedding
- A model weight vector
- A hidden state in a neural network

#### Dot Product

Formula:

```text
a . b = a1*b1 + a2*b2 + ... + an*bn
```

Example:

```text
a = [1, 2, 3]
b = [4, 5, 6]

a . b = 1*4 + 2*5 + 3*6 = 32
```

Meaning:

- Large positive dot product: vectors point in a similar direction.
- Near zero dot product: vectors are close to perpendicular.
- Negative dot product: vectors point in opposite directions.

#### Cosine Similarity

Formula:

```text
cosine_similarity(a, b) = (a . b) / (||a|| * ||b||)
```

Used in:

- Semantic search
- Embedding comparison
- Recommendation systems
- RAG retrieval

#### Probability

Probability measures uncertainty.

Examples:

- Probability that an email is spam
- Probability that a transaction is fraud
- Probability that a user will click an ad

#### Statistics

Important statistics:

- Mean
- Median
- Mode
- Variance
- Standard deviation
- Correlation
- Distribution
- Sampling
- Confidence intervals

#### Calculus

Calculus helps us understand how a small change in one variable affects another.

In ML, derivatives tell us how changing model parameters changes the loss.

#### Gradient

A gradient is a vector of partial derivatives.

It points in the direction of steepest increase.

To minimize loss, we move in the opposite direction.

#### Gradient Descent

Formula:

```text
w_new = w_old - learning_rate * gradient
```

### Real-World Example

In house price prediction:

- Features are vector values like area, bedrooms, age, and location score.
- Weights determine how important each feature is.
- The model predicts price using a weighted combination.
- Loss measures prediction error.
- Gradient descent updates weights to reduce error.

### Python Example

```python
def dot_product(a, b):
    if len(a) != len(b):
        raise ValueError("Vectors must have the same length")
    return sum(x * y for x, y in zip(a, b))


def cosine_similarity(a, b):
    dot = dot_product(a, b)
    norm_a = sum(x ** 2 for x in a) ** 0.5
    norm_b = sum(y ** 2 for y in b) ** 0.5

    if norm_a == 0 or norm_b == 0:
        raise ValueError("Cosine similarity is undefined for zero vectors")

    return dot / (norm_a * norm_b)
```

### Common Interview Questions

- What is a vector?
- What is a matrix?
- What is a dot product?
- What is cosine similarity?
- What is variance?
- What is standard deviation?
- What is a derivative?
- What is a gradient?
- Why does gradient descent work?

### Tricky Follow-Ups

- Dot product vs cosine similarity?
- Why normalize features?
- What happens if learning rate is too high?
- What happens if learning rate is too low?
- Why can gradient descent get stuck?

### Mistakes Candidates Make

- Memorizing formulas without intuition.
- Confusing variance and standard deviation.
- Saying dot product is always similarity without mentioning magnitude.
- Not understanding why gradients matter.

### Mini Quiz

1. What does a vector represent in ML?
2. What does a large positive dot product mean?
3. Why is cosine similarity useful for embeddings?
4. What is the role of a derivative in ML?
5. What does the learning rate control?

### Practical Assignment

Implement from scratch:

1. Dot product
2. Vector norm
3. Cosine similarity
4. Mean squared error
5. One step of gradient descent for linear regression

---

## 4.3 What Machine Learning Is

### Intuition

Machine learning means teaching computers to learn patterns from data instead of manually writing every rule.

Example:

Instead of writing rules like:

```text
if email contains "free money" then spam
```

we train a model on many examples of spam and non-spam emails. The model learns patterns automatically.

### Formal Explanation

Machine learning is a branch of artificial intelligence where algorithms learn from data to make predictions or decisions.

Basic ML flow:

```text
Data -> Features -> Model -> Prediction -> Loss -> Optimization -> Better Model
```

### Types of Learning

#### Supervised Learning

The model learns from labeled data.

Examples:

- House price prediction
- Spam detection
- Customer churn prediction
- Disease diagnosis

Tasks:

- Regression
- Classification

#### Unsupervised Learning

The model learns patterns from unlabeled data.

Examples:

- Customer segmentation
- Topic discovery
- Anomaly detection

Tasks:

- Clustering
- Dimensionality reduction

#### Semi-Supervised Learning

The model learns from a small amount of labeled data and a large amount of unlabeled data.

Useful when labels are expensive.

#### Reinforcement Learning

An agent learns by taking actions and receiving rewards or penalties.

Examples:

- Game playing
- Robotics
- Recommendation policies
- Autonomous systems

### Key Algorithms

Supervised:

- Linear regression
- Logistic regression
- Decision trees
- Random forests
- Gradient boosting
- Neural networks

Unsupervised:

- K-means
- Hierarchical clustering
- PCA
- Autoencoders

Reinforcement learning:

- Q-learning
- Policy gradients
- Actor-critic methods

### Real-World Example

Credit risk prediction:

- Input: income, age, credit history, loan amount
- Output: likely to default or not
- Type: supervised classification
- Metric: precision, recall, ROC-AUC

### Python Example

```python
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

X = [
    [25, 50000],
    [45, 80000],
    [35, 65000],
    [22, 30000],
]
y = [0, 1, 1, 0]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42
)

model = LogisticRegression()
model.fit(X_train, y_train)

preds = model.predict(X_test)
print(accuracy_score(y_test, preds))
```

### Common Interview Questions

- What is machine learning?
- Difference between AI, ML, DL, and GenAI?
- Supervised vs unsupervised learning?
- Regression vs classification?
- What is reinforcement learning?
- What is the difference between training and inference?

### Tricky Follow-Ups

- Is clustering supervised or unsupervised?
- Can classification output probabilities?
- Can regression be used for classification?
- When would you avoid ML and use rules instead?

### Mistakes Candidates Make

- Saying ML and AI are exactly the same.
- Saying deep learning is bigger than machine learning.
- Not distinguishing labels and features.
- Not knowing when ML is unnecessary.

### Mini Quiz

1. Is house price prediction regression or classification?
2. Is spam detection regression or classification?
3. Is customer segmentation supervised or unsupervised?
4. What is the difference between training and prediction?
5. What is a label?

### Practical Assignment

Choose five real-world problems and classify each as:

- Supervised or unsupervised
- Regression or classification
- Possible features
- Possible metric

---

## 4.4 Overfitting, Underfitting, and Bias-Variance

### Intuition

Overfitting means memorizing training data.

Underfitting means not learning enough.

A good model learns useful patterns that generalize to new data.

### Formal Explanation

Overfitting:

- Low training error
- High validation or test error
- Model is too complex or trained too long

Underfitting:

- High training error
- High validation or test error
- Model is too simple or not trained enough

### Bias-Variance Tradeoff

Bias:

- Error from overly simple assumptions.
- High bias often causes underfitting.

Variance:

- Error from sensitivity to training data.
- High variance often causes overfitting.

Goal:

- Find a balance between bias and variance.

### Real-World Example

House price prediction:

- Underfit model: uses only number of bedrooms.
- Overfit model: memorizes exact houses in the training set.
- Good model: uses meaningful features and generalizes to unseen houses.

### How To Detect

Use train and validation metrics.

```text
High train error + high validation error = underfitting
Low train error + high validation error = overfitting
Low train error + low validation error = good fit
```

### How To Fix Overfitting

- Get more data.
- Use simpler model.
- Add regularization.
- Use dropout for neural networks.
- Use early stopping.
- Use data augmentation.
- Prune trees.
- Reduce noisy features.

### How To Fix Underfitting

- Use more complex model.
- Add useful features.
- Train longer.
- Reduce regularization.
- Tune hyperparameters.
- Improve data quality.

### Common Interview Questions

- What is overfitting?
- What is underfitting?
- How do you detect overfitting?
- What is bias?
- What is variance?
- How do you reduce overfitting?

### Tricky Follow-Ups

- Can a model have both high bias and high variance?
- Does more data always fix overfitting?
- Can regularization cause underfitting?
- How do learning curves help?

### Mistakes Candidates Make

- Saying high accuracy always means a good model.
- Looking only at training performance.
- Not using a validation set.
- Confusing bias with unfairness or social bias in this context.

### Mini Quiz

1. If training accuracy is 99 percent and validation accuracy is 65 percent, what is happening?
2. If training and validation accuracy are both 55 percent, what is happening?
3. What is one way to reduce overfitting?
4. What is one way to reduce underfitting?
5. What is high variance?

### Practical Assignment

Train a decision tree with different max depths and observe:

- Training accuracy
- Validation accuracy
- Overfitting behavior
- Underfitting behavior

---

## 5. Phase 2: Classical Machine Learning

## 5.1 Regression

### Intuition

Regression predicts a continuous number.

Examples:

- House price
- Temperature
- Revenue
- Delivery time
- Customer lifetime value

### Formal Explanation

Linear regression models the relationship between input features and a continuous target.

Formula:

```text
y_hat = w1*x1 + w2*x2 + ... + wn*xn + b
```

Where:

- `y_hat` is prediction
- `x` values are features
- `w` values are weights
- `b` is bias/intercept

### Loss Function

Mean squared error:

```text
MSE = (1/n) * sum((y_i - y_hat_i)^2)
```

Mean absolute error:

```text
MAE = (1/n) * sum(|y_i - y_hat_i|)
```

### Real-World Example

Predicting house price using:

- Square footage
- Number of rooms
- Location
- Age of property
- Nearby schools

### Python Example

```python
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model = LinearRegression()
model.fit(X_train, y_train)

preds = model.predict(X_test)

print(mean_squared_error(y_test, preds))
print(mean_absolute_error(y_test, preds))
```

### Common Interview Questions

- What is linear regression?
- What assumptions does linear regression make?
- What is MSE?
- What is MAE?
- When would you use MAE instead of MSE?
- What is R-squared?

### Tricky Follow-Ups

- Why is MSE sensitive to outliers?
- Can linear regression model nonlinear data?
- What happens with multicollinearity?
- Why scale features?

### Mistakes Candidates Make

- Calling every prediction problem classification.
- Not checking residuals.
- Not handling outliers.
- Using accuracy for regression.

### Mini Quiz

1. Is predicting salary regression or classification?
2. Why does MSE penalize large errors more than MAE?
3. What does R-squared measure?
4. What is an outlier?
5. What does the intercept mean?

### Practical Assignment

Build a house price predictor using a small dataset.

Steps:

1. Load data.
2. Clean missing values.
3. Split train and test.
4. Train linear regression.
5. Evaluate using MAE and RMSE.
6. Explain results.

---

## 5.2 Classification

### Intuition

Classification predicts a category.

Examples:

- Spam or not spam
- Fraud or not fraud
- Disease or no disease
- Churn or not churn
- Image class

### Formal Explanation

A classifier maps features to class labels.

For binary classification:

```text
y in {0, 1}
```

For multiclass classification:

```text
y in {class_1, class_2, ..., class_k}
```

### Logistic Regression

Despite the name, logistic regression is used for classification.

It uses the sigmoid function:

```text
sigmoid(z) = 1 / (1 + e^-z)
```

The output is a probability between 0 and 1.

### Metrics

Accuracy:

```text
(TP + TN) / (TP + TN + FP + FN)
```

Precision:

```text
TP / (TP + FP)
```

Recall:

```text
TP / (TP + FN)
```

F1 score:

```text
2 * (precision * recall) / (precision + recall)
```

### Real-World Example

Fraud detection:

- Fraud cases are rare.
- Accuracy can be misleading.
- Recall is important because missing fraud is costly.
- Precision is also important because false alarms annoy users.

### Python Example

```python
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report

model = LogisticRegression()
model.fit(X_train, y_train)

preds = model.predict(X_test)
print(classification_report(y_test, preds))
```

### Common Interview Questions

- What is classification?
- What is logistic regression?
- What is the sigmoid function?
- Accuracy vs precision vs recall?
- What is F1 score?
- What is a confusion matrix?

### Tricky Follow-Ups

- Why is accuracy bad for imbalanced datasets?
- When is precision more important than recall?
- When is recall more important than precision?
- How do you choose a classification threshold?
- What is ROC-AUC?

### Mistakes Candidates Make

- Using accuracy blindly.
- Not considering class imbalance.
- Confusing precision and recall.
- Not explaining false positives and false negatives.

### Mini Quiz

1. In disease detection, is recall important? Why?
2. In spam detection, what is a false positive?
3. What does precision measure?
4. What does recall measure?
5. Why can accuracy be misleading?

### Practical Assignment

Build a spam classifier.

Steps:

1. Load text data.
2. Convert text to features using TF-IDF.
3. Train logistic regression.
4. Evaluate precision, recall, and F1.
5. Explain errors.

---

## 5.3 Clustering

### Intuition

Clustering groups similar data points without labels.

Examples:

- Customer segmentation
- Grouping documents by topic
- Image grouping
- Anomaly detection

### Formal Explanation

Clustering is unsupervised learning. The algorithm tries to find structure in unlabeled data.

### K-Means

K-means divides data into `k` clusters.

Algorithm:

1. Choose `k` cluster centers.
2. Assign each point to nearest center.
3. Recompute centers.
4. Repeat until stable.

### Real-World Example

Customer segmentation:

- Cluster 1: high spenders
- Cluster 2: discount seekers
- Cluster 3: inactive users
- Cluster 4: new users

### Python Example

```python
from sklearn.cluster import KMeans

model = KMeans(n_clusters=3, random_state=42)
clusters = model.fit_predict(X)
```

### Common Interview Questions

- What is clustering?
- What is k-means?
- How do you choose k?
- What is the elbow method?
- What are limitations of k-means?

### Tricky Follow-Ups

- Does k-means work well with non-spherical clusters?
- Why scale features before k-means?
- What if clusters have different densities?
- How do you evaluate clustering without labels?

### Mistakes Candidates Make

- Treating clustering like classification.
- Forgetting that labels are not available.
- Not scaling features.
- Assuming clusters always have clear business meaning.

### Mini Quiz

1. Is clustering supervised or unsupervised?
2. What does k mean in k-means?
3. Why do we scale features before clustering?
4. What is the elbow method?
5. What is one limitation of k-means?

### Practical Assignment

Cluster customers using features like age, income, and purchase frequency.

---

## 5.4 Model Evaluation

### Intuition

Model evaluation tells us whether a model is actually useful.

Training performance alone is not enough. We care about performance on unseen data.

### Formal Explanation

Common splits:

- Training set: used to train model
- Validation set: used to tune model
- Test set: used for final evaluation

### Regression Metrics

- MAE
- MSE
- RMSE
- R-squared

### Classification Metrics

- Accuracy
- Precision
- Recall
- F1 score
- ROC-AUC
- PR-AUC
- Log loss

### Cross-Validation

K-fold cross-validation:

1. Split data into k folds.
2. Train on k-1 folds.
3. Validate on the remaining fold.
4. Repeat k times.
5. Average the results.

### Real-World Example

In fraud detection, accuracy might be 99 percent because fraud is rare. But the model may still fail to detect actual fraud. Recall and precision are more meaningful.

### Python Example

```python
from sklearn.model_selection import cross_val_score
from sklearn.ensemble import RandomForestClassifier

model = RandomForestClassifier(random_state=42)
scores = cross_val_score(model, X, y, cv=5, scoring="f1")

print(scores)
print(scores.mean())
```

### Common Interview Questions

- Why do we split data?
- Train vs validation vs test?
- What is cross-validation?
- Accuracy vs F1?
- ROC-AUC vs PR-AUC?

### Tricky Follow-Ups

- When is PR-AUC better than ROC-AUC?
- What is data leakage?
- Why not tune on the test set?
- How do you evaluate time series models?

### Mistakes Candidates Make

- Tuning on test data.
- Ignoring class imbalance.
- Reporting only one metric.
- Not matching metric to business goal.

### Mini Quiz

1. Why do we need a test set?
2. What is validation data used for?
3. What metric would you use for imbalanced fraud detection?
4. What is data leakage?
5. Why use cross-validation?

### Practical Assignment

Take one classification dataset and evaluate it using:

- Accuracy
- Precision
- Recall
- F1
- ROC-AUC
- Confusion matrix

Explain which metric matters most.

---

## 5.5 Feature Engineering

### Intuition

Feature engineering means transforming raw data into useful inputs for a model.

Good features often matter more than fancy algorithms, especially for tabular ML.

### Formal Explanation

Feature engineering includes:

- Handling missing values
- Encoding categorical variables
- Scaling numerical variables
- Creating new features
- Removing leakage
- Handling outliers
- Feature selection

### Common Techniques

Missing values:

- Mean imputation
- Median imputation
- Mode imputation
- Missing indicator

Categorical encoding:

- One-hot encoding
- Ordinal encoding
- Target encoding

Scaling:

- Standardization
- Min-max scaling
- Robust scaling

Feature creation:

- Ratios
- Counts
- Time differences
- Aggregations
- Text features

### Real-World Example

For customer churn:

Raw data:

- Last login date
- Subscription date
- Number of support tickets

Engineered features:

- Days since last login
- Account age
- Tickets per month
- Usage decline over last 30 days

### Python Example

```python
import pandas as pd

df["account_age_days"] = (
    pd.to_datetime("2026-06-02") - pd.to_datetime(df["signup_date"])
).dt.days

df["tickets_per_month"] = df["support_tickets"] / (df["account_age_days"] / 30)
```

### Common Interview Questions

- What is feature engineering?
- How do you handle missing values?
- How do you encode categorical variables?
- Why scale features?
- What is data leakage?

### Tricky Follow-Ups

- Can target encoding cause leakage?
- Do tree models need feature scaling?
- How do you handle high-cardinality categorical variables?
- What features would you create for churn prediction?

### Mistakes Candidates Make

- Creating features using future information.
- Applying preprocessing before train/test split incorrectly.
- Ignoring missingness patterns.
- Encoding categories inconsistently between train and test.

### Mini Quiz

1. What is one-hot encoding?
2. Why can target encoding be risky?
3. What is feature leakage?
4. Do neural networks usually benefit from scaling?
5. What is one feature you would create for churn prediction?

### Practical Assignment

For a customer churn dataset, create at least 10 useful features and explain why each might help.

---

## 5.6 Tree Models, Random Forests, and Gradient Boosting

### Intuition

Decision trees make predictions using a sequence of questions.

Example:

```text
Is income > 50000?
Is age < 30?
Has user purchased before?
```

Random forests combine many trees to reduce overfitting.

Gradient boosting builds trees sequentially, where each new tree tries to fix previous errors.

### Decision Trees

Pros:

- Easy to understand
- Handles nonlinear relationships
- Works with numerical and categorical features
- Little feature scaling needed

Cons:

- Can overfit easily
- Unstable with small data changes

### Random Forest

Random forest uses:

- Bootstrap samples
- Multiple decision trees
- Random feature subsets
- Averaging or voting

Main benefit:

- Reduces variance compared to a single tree.

### Gradient Boosting

Gradient boosting builds weak learners one by one.

Each new learner focuses on previous mistakes.

Popular libraries:

- XGBoost
- LightGBM
- CatBoost

### XGBoost

Strengths:

- Strong performance on tabular data
- Regularization
- Handles missing values
- Efficient implementation

### LightGBM

Strengths:

- Fast training
- Memory efficient
- Good for large datasets
- Leaf-wise tree growth

### Real-World Example

Credit scoring:

- Decision tree gives explainable rules.
- Random forest improves robustness.
- Gradient boosting often gives top predictive performance.

### Python Example

```python
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier

rf = RandomForestClassifier(n_estimators=100, random_state=42)
rf.fit(X_train, y_train)

gb = GradientBoostingClassifier(random_state=42)
gb.fit(X_train, y_train)
```

### Common Interview Questions

- How does a decision tree work?
- What is entropy?
- What is Gini impurity?
- Why do decision trees overfit?
- How does random forest reduce overfitting?
- Bagging vs boosting?
- XGBoost vs random forest?
- LightGBM vs XGBoost?

### Tricky Follow-Ups

- Why does random forest reduce variance?
- Can boosting overfit?
- Why are boosted trees strong on tabular data?
- What hyperparameters matter most?
- How do you interpret feature importance?

### Mistakes Candidates Make

- Saying random forest always prevents overfitting.
- Not knowing bagging vs boosting.
- Ignoring class imbalance.
- Assuming feature importance always implies causation.

### Mini Quiz

1. What is a decision tree split?
2. What is bagging?
3. What is boosting?
4. Why does random forest use random feature subsets?
5. Why is gradient boosting sequential?

### Practical Assignment

Train and compare:

- Logistic regression
- Decision tree
- Random forest
- Gradient boosting

Use the same dataset and compare metrics.

---

## 6. Phase 3: Deep Learning

## 6.1 Neural Networks

### Intuition

A neural network is a stack of layers that transforms input data into predictions.

Each layer learns useful representations.

### Formal Explanation

A neuron computes:

```text
z = w . x + b
a = activation(z)
```

Where:

- `x` is input
- `w` is weights
- `b` is bias
- `z` is weighted sum
- `a` is activation output

### Why Activations Matter

Without nonlinear activation functions, a deep neural network would behave like one linear model.

Common activations:

- Sigmoid
- Tanh
- ReLU
- Leaky ReLU
- GELU
- Softmax

### Real-World Example

Image classifier:

- Input: image pixels
- Hidden layers: learn edges, textures, shapes
- Output layer: class probabilities

### Python Example

```python
import torch
import torch.nn as nn

model = nn.Sequential(
    nn.Linear(10, 32),
    nn.ReLU(),
    nn.Linear(32, 2)
)
```

### Common Interview Questions

- What is a neural network?
- What is a neuron?
- What is an activation function?
- Why do we need nonlinear activations?
- What is a hidden layer?

### Tricky Follow-Ups

- What happens if there are no activation functions?
- Why is ReLU popular?
- What is vanishing gradient?
- What is exploding gradient?

### Mistakes Candidates Make

- Thinking neural networks always outperform classical ML.
- Not understanding activations.
- Ignoring data size and compute requirements.
- Treating deep learning as magic.

### Mini Quiz

1. What does a neuron compute?
2. Why do we need activation functions?
3. What is ReLU?
4. What is the output layer used for?
5. When might classical ML beat deep learning?

### Practical Assignment

Build a simple neural network for binary classification using PyTorch.

---

## 6.2 Backpropagation

### Intuition

Backpropagation tells each weight how responsible it was for the final error.

Then the optimizer updates weights to reduce future error.

### Formal Explanation

Backpropagation computes gradients of the loss with respect to model parameters using the chain rule.

Important distinction:

- Backpropagation computes gradients.
- Optimizer updates parameters.

### Formula

Gradient descent update:

```text
w_new = w_old - learning_rate * dL/dw
```

### Real-World Example

If a model predicts a house price too high, backpropagation calculates how each weight contributed to that error.

### Common Interview Questions

- What is backpropagation?
- What is the chain rule?
- What is a gradient?
- What does the optimizer do?
- Backpropagation vs gradient descent?

### Tricky Follow-Ups

- Why do gradients vanish?
- Why do gradients explode?
- How does batch size affect training?
- Why does learning rate matter?

### Mistakes Candidates Make

- Saying backpropagation directly updates weights.
- Not mentioning chain rule.
- Not distinguishing loss and gradient.
- Not knowing the optimizer's role.

### Mini Quiz

1. What does backpropagation compute?
2. What does gradient descent do?
3. What is the chain rule used for?
4. What happens if learning rate is too high?
5. What happens if learning rate is too low?

### Practical Assignment

Manually compute one gradient descent update for a one-parameter model:

```text
y_hat = w*x
loss = (y - y_hat)^2
```

---

## 6.3 Optimizers

### Intuition

Optimizers decide how model parameters should move based on gradients.

### Common Optimizers

#### Gradient Descent

Uses all data to compute one update.

#### Stochastic Gradient Descent

Uses one sample at a time.

#### Mini-Batch Gradient Descent

Uses a small batch of samples.

#### Momentum

Adds memory of past update directions.

#### Adam

Uses adaptive learning rates and momentum-like behavior.

### Real-World Example

Training an LLM uses optimizer variants to update billions of parameters efficiently.

### Common Interview Questions

- SGD vs batch gradient descent?
- What is Adam?
- What is momentum?
- Why tune learning rate?
- What is weight decay?

### Tricky Follow-Ups

- Can Adam generalize worse than SGD in some cases?
- Difference between L2 regularization and weight decay?
- Why use learning rate schedules?

### Mistakes Candidates Make

- Thinking Adam removes the need to tune learning rate.
- Ignoring batch size.
- Not knowing what momentum does.

### Mini Quiz

1. What does an optimizer do?
2. What is SGD?
3. What is Adam?
4. What is momentum?
5. Why use mini-batches?

### Practical Assignment

Train the same neural network with SGD and Adam. Compare convergence.

---

## 6.4 CNNs

### Intuition

Convolutional neural networks are designed for grid-like data such as images.

They detect local patterns like edges, textures, and shapes.

### Formal Explanation

A convolutional layer applies filters across an image to produce feature maps.

Key concepts:

- Convolution
- Kernel/filter
- Stride
- Padding
- Pooling
- Feature map

### Real-World Example

Medical image classification:

- CNN detects edges and textures in scans.
- Deeper layers detect complex patterns.
- Output predicts disease class.

### Common Interview Questions

- What is a CNN?
- What is a convolution filter?
- What is pooling?
- Why are CNNs good for images?
- What is stride?
- What is padding?

### Tricky Follow-Ups

- Why does convolution reduce parameters compared to fully connected layers?
- What is translation invariance?
- Max pooling vs average pooling?

### Mistakes Candidates Make

- Not knowing the role of filters.
- Confusing channels and filters.
- Ignoring input dimensions.

### Mini Quiz

1. What does a convolution filter learn?
2. What is pooling used for?
3. What is stride?
4. What is padding?
5. Why are CNNs parameter-efficient for images?

### Practical Assignment

Build a small CNN for image classification.

---

## 6.5 RNNs, LSTMs, and GRUs

### Intuition

RNNs process sequences step by step.

They were commonly used for text, speech, and time series before transformers became dominant.

### Formal Explanation

RNNs maintain a hidden state that carries information across time steps.

Problem:

- Vanilla RNNs struggle with long-range dependencies because of vanishing gradients.

LSTMs and GRUs help solve this using gates.

### Real-World Example

Sentiment analysis:

The model reads words sequentially and updates its hidden state until it predicts sentiment.

### Common Interview Questions

- What is an RNN?
- What is hidden state?
- What is vanishing gradient?
- Why use LSTM?
- LSTM vs GRU?

### Tricky Follow-Ups

- Why did transformers replace RNNs in many NLP tasks?
- Can RNNs process sequences of variable length?
- Why are RNNs harder to parallelize?

### Mistakes Candidates Make

- Not understanding hidden state.
- Saying LSTM completely solves all long-context problems.
- Not knowing why transformers are more parallelizable.

### Mini Quiz

1. What is a hidden state?
2. Why do vanilla RNNs struggle with long sequences?
3. What do gates do in LSTMs?
4. Why are transformers easier to parallelize?
5. Name one use case for RNNs.

### Practical Assignment

Build a simple sentiment classifier using an LSTM.

---

## 6.6 Attention and Transformers

### Intuition

Attention lets a model decide which tokens are important for understanding another token.

Example:

```text
The animal did not cross the road because it was tired.
```

To understand "it", the model should pay attention to "animal".

### Formal Explanation

Self-attention allows every token to look at every other token in the sequence.

Each token creates:

- Query
- Key
- Value

Attention compares queries with keys to decide how much value to use.

### Formula

```text
Attention(Q, K, V) = softmax(QK^T / sqrt(d_k))V
```

### Transformer Components

- Token embeddings
- Positional encodings
- Multi-head self-attention
- Feed-forward network
- Residual connections
- Layer normalization

### Encoder vs Decoder

Encoder-only models:

- Good for understanding tasks
- Example: BERT

Decoder-only models:

- Good for generation
- Example: GPT-style models

Encoder-decoder models:

- Good for sequence-to-sequence tasks
- Example: translation and summarization models

### Real-World Example

Question answering:

The model uses attention to connect question tokens with relevant passage tokens.

### Common Interview Questions

- What is attention?
- What is self-attention?
- What are query, key, and value?
- Why divide by square root of `d_k`?
- What is multi-head attention?
- What is positional encoding?
- BERT vs GPT?

### Tricky Follow-Ups

- Why do transformers need positional information?
- Why is self-attention expensive for long contexts?
- What is causal masking?
- Why are decoder-only models used for text generation?

### Mistakes Candidates Make

- Saying attention is just "focus" without explaining scores.
- Not knowing Q, K, V.
- Forgetting positional encoding.
- Confusing encoder and decoder models.

### Mini Quiz

1. What does attention help a model do?
2. What are Q, K, and V?
3. What is self-attention?
4. What is causal masking?
5. Why are transformers important for LLMs?

### Practical Assignment

Write a small self-attention function in NumPy or PyTorch and inspect the attention matrix.

---

## 7. Phase 4: NLP and LLMs

## 7.1 NLP Basics

### Intuition

Natural language processing helps computers work with human language.

Tasks include:

- Classifying text
- Extracting entities
- Searching documents
- Summarizing content
- Translating text
- Answering questions

### Formal Explanation

NLP pipelines often include:

- Text cleaning
- Tokenization
- Feature extraction
- Model training
- Evaluation

### Tokenization

Tokenization splits text into smaller units.

Tokens can be:

- Words
- Subwords
- Characters
- Punctuation
- Special tokens

Example:

```text
"I love machine learning!"
```

Word-level tokens:

```text
["I", "love", "machine", "learning", "!"]
```

LLM-style tokens may include spaces or subwords.

### TF-IDF

TF-IDF measures how important a word is to a document in a collection.

Term frequency:

```text
How often a term appears in a document
```

Inverse document frequency:

```text
How rare the term is across documents
```

### Word Embeddings

Embeddings convert words or text into dense vectors.

Examples:

- Word2Vec
- GloVe
- FastText
- Transformer embeddings

### Real-World Example

Support ticket classification:

- Input: customer message
- Output: billing, technical issue, cancellation, refund, or account access

### Python Example

```python
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression

texts = [
    "I need a refund",
    "My account is locked",
    "The app keeps crashing",
]
labels = ["billing", "account", "technical"]

vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(texts)

model = LogisticRegression()
model.fit(X, labels)
```

### Common Interview Questions

- What is NLP?
- What is tokenization?
- What is TF-IDF?
- What are word embeddings?
- Word2Vec vs GloVe?
- What is semantic similarity?

### Tricky Follow-Ups

- Why are subword tokenizers useful?
- Why does TF-IDF fail to capture meaning well?
- What is out-of-vocabulary?
- How do embeddings capture semantic similarity?

### Mistakes Candidates Make

- Thinking tokens always equal words.
- Not understanding sparse vs dense vectors.
- Confusing TF-IDF with embeddings.
- Ignoring preprocessing choices.

### Mini Quiz

1. What is tokenization?
2. What is TF-IDF used for?
3. What is an embedding?
4. Why are subwords useful?
5. What is semantic search?

### Practical Assignment

Build a text classifier using TF-IDF and logistic regression.

---

## 7.2 BERT and GPT-Style Models

### Intuition

BERT is mainly used for understanding text.

GPT-style models are mainly used for generating text.

### Formal Explanation

BERT:

- Encoder-only transformer
- Bidirectional context
- Often used for classification, NER, retrieval, and question answering

GPT-style models:

- Decoder-only transformer
- Causal language modeling
- Predict next token
- Used for generation, chat, reasoning, summarization, and tool use

### Key Difference

BERT can look left and right at surrounding context.

GPT-style models generate one token at a time and usually only attend to previous tokens during generation.

### Real-World Example

BERT:

- Classify whether a review is positive or negative.

GPT-style model:

- Generate a response to a customer support question.

### Common Interview Questions

- What is BERT?
- What is GPT?
- BERT vs GPT?
- What is masked language modeling?
- What is causal language modeling?
- What is pretraining?
- What is fine-tuning?

### Tricky Follow-Ups

- Why is BERT not naturally a text generation model?
- Why are GPT-style models good for chat?
- What is instruction tuning?
- What is RLHF?

### Mistakes Candidates Make

- Saying all transformers are the same.
- Confusing encoder and decoder architectures.
- Not understanding pretraining objective.

### Mini Quiz

1. Is BERT encoder-only or decoder-only?
2. Is GPT encoder-only or decoder-only?
3. What does masked language modeling mean?
4. What does next-token prediction mean?
5. Which model style is more natural for chat generation?

### Practical Assignment

Use a pretrained transformer model for sentiment classification.

---

## 8. Phase 5: Generative AI Engineering

## 8.1 LLM Basics

### Intuition

A large language model predicts the next token based on previous tokens and learned patterns from training data.

It does not "know" facts like a database. It generates likely continuations based on its learned parameters and context.

### Formal Explanation

LLMs are usually transformer-based neural networks trained on large text corpora.

They learn probability distributions over tokens:

```text
P(next_token | previous_tokens)
```

### Important Concepts

- Parameters
- Tokens
- Context window
- Prompt
- Completion
- Temperature
- Top-p
- Top-k
- System prompt
- Tool calling
- Structured output

### Parameters

Parameters are learned weights in the model.

More parameters can increase capacity, but do not automatically guarantee better output for every task.

### Context Window

The context window is the maximum number of tokens the model can consider at once.

### Temperature

Temperature controls randomness.

Low temperature:

- More deterministic
- Better for factual tasks

High temperature:

- More creative
- More varied

### Top-p

Top-p samples from the smallest set of tokens whose cumulative probability reaches `p`.

### Real-World Example

Customer support chatbot:

- User asks a question.
- LLM generates a helpful answer.
- If connected to tools, it may check order status.
- If connected to RAG, it may retrieve policy documents.

### Common Interview Questions

- What is an LLM?
- How does an LLM generate text?
- What is a token?
- What is a context window?
- Temperature vs top-p?
- What are hallucinations?

### Tricky Follow-Ups

- Why can LLMs hallucinate?
- Does increasing context window solve all problems?
- Are LLMs databases?
- What happens when context is too long?

### Mistakes Candidates Make

- Saying LLMs retrieve facts from memory like SQL.
- Not understanding token limits.
- Using high temperature for factual workflows.
- Ignoring latency and cost.

### Mini Quiz

1. What does an LLM predict?
2. What is a token?
3. What does temperature control?
4. What is a context window?
5. Why can LLMs hallucinate?

### Practical Assignment

Write prompts for the same task using:

- Zero-shot prompting
- Few-shot prompting
- Structured output
- Role-based instruction

Compare outputs.

---

## 8.2 Prompt Engineering

### Intuition

Prompt engineering means giving the model clear instructions, context, examples, and output constraints.

### Formal Explanation

A good prompt often includes:

- Role
- Task
- Context
- Constraints
- Examples
- Output format
- Evaluation criteria

### Prompt Template

```text
You are a [role].

Task:
[specific task]

Context:
[relevant context]

Constraints:
[rules]

Output format:
[schema or structure]
```

### Real-World Example

Invoice extraction:

Ask the model to extract:

- Invoice number
- Vendor
- Total amount
- Due date
- Line items

Return JSON only.

### Common Interview Questions

- What is prompt engineering?
- What is zero-shot prompting?
- What is few-shot prompting?
- How do you reduce hallucinations?
- How do you force structured output?

### Tricky Follow-Ups

- When is prompt engineering not enough?
- How do you evaluate prompts?
- How do you prevent prompt injection?
- What makes a prompt brittle?

### Mistakes Candidates Make

- Writing vague prompts.
- Not specifying output format.
- Not testing prompts on edge cases.
- Treating prompt engineering as a one-time task.

### Mini Quiz

1. What is zero-shot prompting?
2. What is few-shot prompting?
3. Why specify output format?
4. What is prompt injection?
5. When would prompt engineering fail?

### Practical Assignment

Design prompts for:

1. Summarizing a legal document
2. Extracting fields from an invoice
3. Classifying support tickets
4. Answering questions using provided context

---

## 8.3 Fine-Tuning vs Prompting vs RAG

### Intuition

Use the right tool for the problem.

Prompting:

- Best when the model already knows the skill and only needs instruction.

RAG:

- Best when the model needs access to external or private knowledge.

Fine-tuning:

- Best when you need the model to learn a behavior, style, format, or task pattern.

### Comparison

| Approach | Best For | Pros | Cons |
|---|---|---|---|
| Prompt engineering | Quick behavior control | Fast, cheap, no training | Can be brittle |
| RAG | Fresh or private knowledge | Reduces need to retrain, cites sources | Retrieval quality matters |
| Fine-tuning | Style, format, task behavior | More consistent behavior | Needs training data and evaluation |

### Real-World Example

Company policy chatbot:

- Prompting sets answer style.
- RAG retrieves current policy documents.
- Fine-tuning may be used if the model must follow a very specific support tone or output format.

### Common Interview Questions

- When would you use RAG?
- When would you fine-tune?
- Fine-tuning vs RAG?
- Can you combine RAG and fine-tuning?
- What are tradeoffs?

### Tricky Follow-Ups

- Would fine-tuning teach the model new facts?
- How do you update knowledge in a fine-tuned model?
- Why might RAG still hallucinate?
- What if retrieval returns irrelevant chunks?

### Mistakes Candidates Make

- Choosing fine-tuning for every problem.
- Thinking RAG fully eliminates hallucinations.
- Not considering data privacy.
- Ignoring maintenance cost.

### Mini Quiz

1. Which approach is best for private documents?
2. Which approach is best for changing output style?
3. Which approach is fastest to try?
4. Can RAG and fine-tuning be combined?
5. Why might fine-tuning be expensive?

### Practical Assignment

For each scenario, choose prompting, RAG, fine-tuning, or a combination:

1. Chatbot over company HR policies
2. Model must always return a strict JSON schema
3. Model needs to write in a brand-specific tone
4. Model needs today's inventory data
5. Model needs to classify internal tickets

---

## 8.4 Hallucinations and Guardrails

### Intuition

Hallucination means the model generates something that sounds plausible but is false or unsupported.

Guardrails are techniques to reduce unsafe, invalid, or unreliable outputs.

### Causes of Hallucination

- Missing context
- Poor retrieval
- Ambiguous prompt
- Model overconfidence
- Outdated knowledge
- Bad instructions
- Conflicting context

### Guardrail Techniques

- Use RAG with reliable sources
- Ask model to cite sources
- Restrict answer to provided context
- Use structured output validation
- Add moderation checks
- Add tool verification
- Use confidence thresholds
- Use fallback behavior
- Log and monitor failures

### Real-World Example

Medical assistant:

- Must not invent medical advice.
- Should provide safe, limited information.
- Should recommend professional consultation when needed.
- Should cite approved medical sources if used.

### Common Interview Questions

- What is hallucination?
- Why do LLMs hallucinate?
- How can RAG reduce hallucinations?
- What are guardrails?
- How do you validate LLM output?

### Tricky Follow-Ups

- Can hallucinations be fully eliminated?
- What if retrieved context is wrong?
- What if the user prompt conflicts with system instructions?
- What if the model gives valid JSON but wrong facts?

### Mistakes Candidates Make

- Claiming RAG removes hallucinations completely.
- Trusting model confidence.
- Not validating structured output.
- Ignoring prompt injection.

### Mini Quiz

1. What is hallucination?
2. Name two causes of hallucination.
3. Name two guardrail techniques.
4. Why is output validation useful?
5. Can hallucination be completely eliminated?

### Practical Assignment

Design guardrails for a customer support chatbot that answers refund policy questions.

---

## 8.5 Agents, Function Calling, and Tool Use

### Intuition

An agent uses an LLM to decide actions, call tools, observe results, and continue until a task is complete.

Function calling lets the model produce structured arguments for external tools.

### Formal Explanation

Agent loop:

```text
User task -> Plan -> Tool call -> Observation -> Next action -> Final answer
```

Tools may include:

- Search
- Database query
- Calculator
- File reader
- Email sender
- Code executor
- CRM API

### Real-World Example

Travel assistant:

- User asks for a trip plan.
- Agent searches flights.
- Checks hotels.
- Compares prices.
- Calls booking API only after user approval.

### Common Interview Questions

- What is an AI agent?
- What is function calling?
- Why use tools with LLMs?
- What are risks of agents?
- How do you evaluate agents?

### Tricky Follow-Ups

- How do you prevent unsafe tool calls?
- How do you handle tool errors?
- How do you limit cost?
- How do you debug agent behavior?

### Mistakes Candidates Make

- Calling every chatbot an agent.
- Giving agents too many permissions.
- Not logging tool calls.
- Not adding human approval for risky actions.

### Mini Quiz

1. What makes a system an agent?
2. What is function calling?
3. Why are tools useful?
4. What is one risk of agents?
5. Why log tool calls?

### Practical Assignment

Design an agent for resolving customer support tickets. Include:

- Tools
- Permissions
- Guardrails
- Failure handling
- Human escalation

---

## 9. Phase 6: RAG Specialization

## 9.1 What RAG Is

### Intuition

RAG stands for Retrieval-Augmented Generation.

It lets an LLM answer using retrieved external knowledge instead of relying only on its internal training.

### Formal Explanation

RAG pipeline:

```text
User question -> Retrieve relevant documents -> Add documents to prompt -> LLM generates answer
```

### Why RAG Matters

RAG helps with:

- Private company knowledge
- Fresh information
- Source-grounded answers
- Reducing hallucinations
- Avoiding frequent retraining

### Real-World Example

Employee asks:

```text
How many paid leave days do I have after 2 years at the company?
```

The RAG system retrieves the HR policy document and uses it to answer.

### Common Interview Questions

- What is RAG?
- Why use RAG?
- RAG vs fine-tuning?
- What are the main components of RAG?
- Does RAG eliminate hallucinations?

### Tricky Follow-Ups

- What if retrieval returns wrong context?
- What if the answer is spread across multiple documents?
- How do you handle access control?
- How do you evaluate RAG?

### Mistakes Candidates Make

- Thinking RAG is just vector search.
- Ignoring chunking.
- Ignoring reranking.
- Not considering security permissions.

### Mini Quiz

1. What does RAG stand for?
2. Why does RAG help with private data?
3. What are the two main stages of RAG?
4. Can RAG hallucinate?
5. What happens if retrieval fails?

### Practical Assignment

Draw a RAG architecture for a PDF question-answering app.

---

## 9.2 Embeddings

### Intuition

Embeddings convert text into vectors so that similar meanings are close together in vector space.

Example:

```text
"car" and "automobile" should have similar embeddings.
```

### Formal Explanation

An embedding model maps text to a dense numerical vector.

```text
embedding_model(text) -> [0.12, -0.44, 0.88, ...]
```

### Why Embeddings Matter

They enable:

- Semantic search
- Recommendation
- Clustering
- Deduplication
- Retrieval in RAG

### Similarity Metrics

- Cosine similarity
- Dot product
- Euclidean distance

### Real-World Example

In a documentation chatbot:

- Convert all document chunks into embeddings.
- Convert user question into embedding.
- Retrieve chunks with similar embeddings.

### Common Interview Questions

- What is an embedding?
- Why use embeddings?
- Cosine similarity vs dot product?
- What is semantic search?
- How do embeddings help RAG?

### Tricky Follow-Ups

- Can embeddings fail?
- How do you choose an embedding model?
- What is embedding dimensionality?
- How do you update embeddings when documents change?

### Mistakes Candidates Make

- Thinking embeddings preserve exact text.
- Ignoring domain mismatch.
- Not re-embedding updated documents.
- Using embeddings alone for exact keyword needs.

### Mini Quiz

1. What is an embedding?
2. Why are similar texts close in vector space?
3. What is cosine similarity?
4. How are embeddings used in RAG?
5. Why might embeddings fail on domain-specific language?

### Practical Assignment

Create embeddings for 20 sentences and find the most similar pairs.

---

## 9.3 Chunking Strategies

### Intuition

Chunking splits documents into pieces small enough to retrieve and fit into the LLM context.

Good chunking improves retrieval quality.

### Formal Explanation

Documents are split before embedding.

Common strategies:

- Fixed-size chunking
- Sliding window chunking
- Paragraph-based chunking
- Section-based chunking
- Semantic chunking
- Recursive chunking

### Key Tradeoffs

Small chunks:

- More precise
- May miss context

Large chunks:

- More context
- May include irrelevant content

Overlap:

- Helps preserve continuity
- Increases storage and cost

### Real-World Example

For legal documents:

- Split by sections and clauses.
- Preserve section titles.
- Store metadata like document name, page, clause number, and access permissions.

### Common Interview Questions

- What is chunking?
- Why does chunk size matter?
- What is chunk overlap?
- How do you chunk PDFs?
- What metadata should be stored?

### Tricky Follow-Ups

- How do you handle tables?
- How do you handle code files?
- How do you handle scanned PDFs?
- How do you chunk documents with complex hierarchy?

### Mistakes Candidates Make

- Using arbitrary chunk sizes without evaluation.
- Dropping headings and metadata.
- Ignoring tables and images.
- Not preserving page references.

### Mini Quiz

1. Why chunk documents?
2. What is a downside of tiny chunks?
3. What is a downside of huge chunks?
4. Why use overlap?
5. What metadata is useful?

### Practical Assignment

Take a document and test three chunking strategies. Compare retrieval results.

---

## 9.4 Vector Databases

### Intuition

A vector database stores embeddings and lets you search for similar vectors efficiently.

### Formal Explanation

Vector databases support:

- Vector storage
- Similarity search
- Metadata filtering
- Approximate nearest neighbor indexes
- Updates and deletes
- Scaling and replication

### Popular Options

- FAISS
- Milvus
- Pinecone
- Weaviate
- Qdrant
- Chroma
- Elasticsearch or OpenSearch with vector search
- PostgreSQL with pgvector

### Similarity Search

Given a query vector, find nearest document vectors.

```text
query_embedding -> top_k_similar_chunks
```

### Approximate Nearest Neighbor Search

Exact search can be expensive at scale.

ANN methods trade a small amount of accuracy for speed.

### Real-World Example

Enterprise search:

- Store millions of document chunks.
- Search by semantic similarity.
- Filter by department, permissions, freshness, or document type.

### Common Interview Questions

- What is a vector database?
- Why use vector search?
- What is ANN?
- What is metadata filtering?
- FAISS vs managed vector DB?
- What is top-k retrieval?

### Tricky Follow-Ups

- How do you handle access control?
- How do you update deleted documents?
- How do you choose index type?
- How do you monitor retrieval quality?

### Mistakes Candidates Make

- Ignoring metadata filters.
- Forgetting delete/update pipelines.
- Using vector search for everything.
- Not testing retrieval recall.

### Mini Quiz

1. What does a vector database store?
2. What is similarity search?
3. What is top-k?
4. Why use metadata filters?
5. What is approximate nearest neighbor search?

### Practical Assignment

Build a small vector search demo using local embeddings and a simple vector store.

---

## 9.5 Retrieval Methods

### Intuition

Retrieval decides what information the LLM receives. Bad retrieval often causes bad answers.

### Retrieval Types

#### Dense Retrieval

Uses embeddings and semantic similarity.

Good for meaning-based search.

#### Sparse Retrieval

Uses keyword methods like BM25.

Good for exact terms, IDs, names, and rare keywords.

#### Hybrid Search

Combines dense and sparse retrieval.

Often better than either alone.

#### Reranking

Reranking takes initial retrieved candidates and reorders them using a stronger model.

### Query Rewriting

The system rewrites the user query to improve retrieval.

Examples:

- Expand acronyms
- Add missing context
- Generate multiple query variants
- Convert conversational question into standalone question

### Metadata Filtering

Filters results using structured fields.

Examples:

- Department
- Date
- Document type
- User permissions
- Region
- Product

### Real-World Example

User asks:

```text
What is the refund policy for annual enterprise plans in India?
```

Retrieval may use:

- Dense semantic search for refund policy meaning
- Keyword search for "annual", "enterprise", "India"
- Metadata filter for region = India
- Reranker to pick best chunks

### Common Interview Questions

- Dense vs sparse retrieval?
- What is hybrid search?
- What is reranking?
- Why rewrite queries?
- What is metadata filtering?

### Tricky Follow-Ups

- When does dense retrieval fail?
- When does keyword retrieval fail?
- How do you combine scores?
- How do you evaluate retrievers?

### Mistakes Candidates Make

- Using only vector search.
- Ignoring exact-match queries.
- Skipping reranking.
- Not filtering by permissions.

### Mini Quiz

1. What is dense retrieval?
2. What is sparse retrieval?
3. Why use hybrid search?
4. What does a reranker do?
5. Why is query rewriting useful?

### Practical Assignment

Compare dense retrieval, keyword retrieval, and hybrid retrieval on the same document set.

---

## 9.6 Context Construction

### Intuition

Context construction is deciding what retrieved information to place into the LLM prompt.

Even good retrieval can fail if context is too long, messy, duplicated, or badly ordered.

### Formal Explanation

Context construction includes:

- Selecting chunks
- Removing duplicates
- Ordering chunks
- Compressing content
- Preserving citations
- Adding metadata
- Respecting token limits

### Real-World Example

For a policy question:

The final prompt may include:

- User question
- Relevant policy excerpts
- Document titles
- Dates
- Section headings
- Instruction to answer only from context

### Common Interview Questions

- What is context construction?
- How many chunks should you pass?
- How do you avoid irrelevant context?
- How do you handle conflicting sources?
- How do you cite sources?

### Tricky Follow-Ups

- What if retrieved chunks exceed context limit?
- What if two documents conflict?
- What if context has sensitive information?
- How do you handle multi-hop questions?

### Mistakes Candidates Make

- Passing too many chunks.
- Losing source metadata.
- Ignoring order.
- Not handling conflicts.

### Mini Quiz

1. Why does context construction matter?
2. What is one risk of too much context?
3. Why preserve citations?
4. What should happen if context is insufficient?
5. How do metadata and source titles help?

### Practical Assignment

Design a prompt template for RAG answers with citations and fallback behavior.

---

## 9.7 RAG Evaluation

### Intuition

RAG evaluation checks whether the system retrieves the right information and generates the right answer.

You must evaluate both retrieval and generation.

### Evaluation Dimensions

Retrieval:

- Recall@k
- Precision@k
- Mean reciprocal rank
- NDCG
- Hit rate

Generation:

- Faithfulness
- Answer correctness
- Relevance
- Citation accuracy
- Completeness

System:

- Latency
- Cost
- User satisfaction
- Failure rate
- Security violations

### Real-World Example

For enterprise search:

- Does the correct document appear in top 5?
- Does the answer cite the right source?
- Does the model avoid unsupported claims?
- Is latency acceptable?

### Common Interview Questions

- How do you evaluate RAG?
- Retrieval metrics vs generation metrics?
- What is faithfulness?
- What is recall@k?
- How do you build a test set?

### Tricky Follow-Ups

- How do you evaluate when there is no single correct answer?
- Can LLMs judge RAG outputs?
- How do you detect hallucinations?
- How do you evaluate citations?

### Mistakes Candidates Make

- Evaluating only final answer.
- Ignoring retrieval quality.
- Using tiny test sets.
- Not testing failure cases.

### Mini Quiz

1. Why evaluate retrieval separately?
2. What is recall@k?
3. What is faithfulness?
4. What is citation accuracy?
5. Why track latency?

### Practical Assignment

Create a small RAG evaluation set:

- 20 questions
- Expected supporting document
- Expected answer
- Evaluation rubric

---

## 9.8 Common RAG Failure Modes

### Failure Mode 1: Poor Chunking

Problem:

- Correct answer split across chunks or missing context.

Fix:

- Better chunking strategy.
- Add overlap.
- Preserve headings.

### Failure Mode 2: Bad Embeddings

Problem:

- Query and relevant document are not close in vector space.

Fix:

- Use better embedding model.
- Domain-specific embeddings.
- Hybrid search.

### Failure Mode 3: Retrieval Miss

Problem:

- Correct chunk not retrieved.

Fix:

- Increase top-k.
- Use query rewriting.
- Use hybrid search.
- Tune retrieval.

### Failure Mode 4: Irrelevant Context

Problem:

- Retrieved chunks are related but not answer-bearing.

Fix:

- Reranking.
- Metadata filters.
- Better query decomposition.

### Failure Mode 5: Hallucinated Answer

Problem:

- Model invents answer not supported by context.

Fix:

- Strong prompt constraints.
- Citation requirement.
- Answer only from context.
- Use verification step.

### Failure Mode 6: Stale Data

Problem:

- Documents are outdated.

Fix:

- Freshness pipeline.
- Document versioning.
- Re-embedding schedule.

### Failure Mode 7: Permission Leakage

Problem:

- User sees documents they should not access.

Fix:

- Enforce access control before retrieval or during retrieval.
- Use metadata filters.
- Audit logs.

### Common Interview Questions

- Why might RAG give wrong answers?
- How do you debug a RAG system?
- What if correct answer exists but model still fails?
- How do you reduce hallucination?
- How do you handle stale documents?

### Tricky Follow-Ups

- Where should access control happen?
- What if metadata filters remove the correct result?
- What if query rewriting changes user intent?
- How do you debug production failures?

### Mistakes Candidates Make

- Blaming the LLM for every RAG error.
- Not inspecting retrieved chunks.
- Not logging intermediate retrieval results.
- Ignoring document ingestion quality.

### Mini Quiz

1. What is a retrieval miss?
2. How can chunking cause failure?
3. Why use reranking?
4. How can stale data affect RAG?
5. How do permissions affect RAG?

### Practical Assignment

Create a debugging checklist for when a RAG answer is wrong.

---

## 9.9 Production RAG Architecture

### High-Level Architecture

```text
Documents
  -> Ingestion pipeline
  -> Cleaning and parsing
  -> Chunking
  -> Metadata extraction
  -> Embedding generation
  -> Vector database

User query
  -> Authentication
  -> Query rewriting
  -> Retrieval
  -> Metadata filtering
  -> Reranking
  -> Context construction
  -> LLM generation
  -> Safety checks
  -> Answer with citations
  -> Logging and evaluation
```

### Core Components

Ingestion:

- PDF parsing
- HTML parsing
- OCR for scanned documents
- Table extraction
- Metadata extraction

Indexing:

- Chunking
- Embedding
- Vector storage
- Keyword index
- Hybrid retrieval

Serving:

- API endpoint
- Query understanding
- Retrieval
- Reranking
- LLM call
- Response formatting

Monitoring:

- Retrieval hit rate
- Latency
- Cost
- User feedback
- Answer faithfulness
- Security events

### Security and Privacy

Important controls:

- Authentication
- Authorization
- Row-level or document-level permissions
- Encryption in transit
- Encryption at rest
- PII redaction where needed
- Prompt injection defense
- Audit logs
- Data retention policies

### Scaling Concerns

- Embedding cost
- Vector index size
- Query latency
- Reranker latency
- LLM latency
- Caching
- Batch ingestion
- Incremental updates

### Cost Optimization

- Cache frequent queries
- Use smaller models when possible
- Use reranking only on top candidates
- Tune chunk size and top-k
- Batch embedding jobs
- Compress context
- Route easy queries to cheaper models

### Common Interview Questions

- Design a RAG system for enterprise documents.
- How do you ingest PDFs?
- How do you handle permissions?
- How do you update indexes?
- How do you evaluate quality?
- How do you reduce latency?
- How do you reduce cost?

### Tricky Follow-Ups

- What if documents contain tables?
- What if documents are scanned images?
- What if two users have different permissions?
- How do you handle deleted documents?
- How do you detect prompt injection?
- How do you monitor hallucinations?

### Mistakes Candidates Make

- Forgetting ingestion complexity.
- Forgetting authentication and authorization.
- Forgetting monitoring.
- Not discussing latency or cost.
- Not including evaluation.

### Mini Quiz

1. What are the main stages of a RAG system?
2. Where does chunking happen?
3. Where should access control be enforced?
4. What should be logged?
5. How do you reduce RAG latency?

### Practical Assignment

Design a production RAG architecture for an internal company knowledge assistant.

Include:

- Data sources
- Ingestion
- Chunking
- Embeddings
- Vector database
- Hybrid search
- Reranking
- LLM
- Guardrails
- Evaluation
- Monitoring
- Security

---

## 10. Phase 7: MLOps and Production ML

## 10.1 Model Deployment

### Intuition

Training a model is only part of the work. Deployment makes it usable by real users or systems.

### Deployment Types

Batch inference:

- Run predictions on many records at scheduled times.

Real-time inference:

- Serve predictions immediately through an API.

Streaming inference:

- Process events continuously.

Edge deployment:

- Run model on user device or local hardware.

### Real-World Example

Fraud detection:

- Real-time model scores transactions before approval.
- Batch model reviews transactions overnight for additional analysis.

### Common Interview Questions

- How do you deploy an ML model?
- Batch vs real-time inference?
- What is model serving?
- What is an API?
- How do you handle latency?

### Tricky Follow-Ups

- How do you roll back a bad model?
- How do you deploy multiple model versions?
- How do you scale inference?
- How do you handle cold starts?

### Mistakes Candidates Make

- Thinking deployment is just saving a model file.
- Ignoring preprocessing consistency.
- Not versioning models.
- Ignoring latency.

### Mini Quiz

1. What is batch inference?
2. What is real-time inference?
3. Why version models?
4. Why version preprocessing code?
5. What is model serving?

### Practical Assignment

Wrap a trained model in a simple FastAPI endpoint.

---

## 10.2 Monitoring, Drift, and Retraining

### Intuition

Models can get worse after deployment because the world changes.

### Types of Drift

Data drift:

- Input distribution changes.

Concept drift:

- Relationship between input and target changes.

Label drift:

- Target distribution changes.

### Example

A fraud model trained on old fraud patterns may fail when attackers change behavior.

### What To Monitor

- Input feature distributions
- Prediction distributions
- Model confidence
- Business metrics
- Ground truth labels when available
- Latency
- Error rates
- Data quality

### Fixes

- Retrain model
- Add new features
- Update labels
- Tune thresholds
- Improve data pipeline
- Roll back model
- Use human review

### Common Interview Questions

- Why can model performance degrade?
- What is data drift?
- What is concept drift?
- How do you monitor a model?
- When do you retrain?

### Tricky Follow-Ups

- What if labels arrive late?
- How do you monitor without ground truth?
- How do you distinguish data drift from concept drift?
- What should trigger retraining?

### Mistakes Candidates Make

- Monitoring only accuracy.
- Ignoring input data quality.
- Not logging predictions.
- Retraining blindly without diagnosis.

### Mini Quiz

1. What is data drift?
2. What is concept drift?
3. Why might accuracy drop after deployment?
4. What can you monitor before labels arrive?
5. What is a retraining trigger?

### Practical Assignment

Design a monitoring plan for a churn prediction model.

---

## 10.3 Experiment Tracking and Model Versioning

### Intuition

Experiment tracking helps you remember what you tried and what worked.

Model versioning helps you reproduce and deploy models safely.

### What To Track

- Dataset version
- Feature code version
- Model type
- Hyperparameters
- Metrics
- Training time
- Artifacts
- Evaluation reports

### Tools

- MLflow
- Weights and Biases
- Neptune
- DVC
- Model registries

### Common Interview Questions

- What is experiment tracking?
- Why version models?
- What is a model registry?
- How do you reproduce a model?
- What is lineage?

### Tricky Follow-Ups

- How do you compare experiments fairly?
- How do you track data versions?
- What metadata is needed for auditability?
- How do you promote a model to production?

### Mistakes Candidates Make

- Not tracking data version.
- Comparing experiments with different splits.
- Not storing preprocessing artifacts.
- Not recording random seeds.

### Mini Quiz

1. Why track experiments?
2. What is a model registry?
3. Why version datasets?
4. What is lineage?
5. Why store preprocessing artifacts?

### Practical Assignment

Use MLflow or a simple spreadsheet to track 10 model experiments.

---

## 10.4 CI/CD for ML

### Intuition

CI/CD for ML automates testing, training, validation, and deployment.

ML CI/CD is harder than normal software CI/CD because data and model behavior also change.

### ML Pipeline Stages

- Data validation
- Feature generation
- Training
- Evaluation
- Model registration
- Deployment
- Monitoring

### Tests

- Unit tests
- Data validation tests
- Feature tests
- Training pipeline tests
- Model performance tests
- Integration tests

### Common Interview Questions

- What is CI/CD for ML?
- How is ML CI/CD different from software CI/CD?
- What tests do ML systems need?
- How do you automate retraining?
- What is a model promotion gate?

### Tricky Follow-Ups

- Should every retrained model be deployed automatically?
- What if model accuracy improves but latency worsens?
- How do you prevent training-serving skew?
- How do you test data pipelines?

### Mistakes Candidates Make

- Ignoring data validation.
- Deploying purely based on one metric.
- Not testing preprocessing.
- Not having rollback.

### Mini Quiz

1. What is CI/CD?
2. Why is ML CI/CD harder?
3. What is data validation?
4. What is training-serving skew?
5. What is a model promotion gate?

### Practical Assignment

Design a CI/CD pipeline for a classification model.

---

## 10.5 Feature Stores

### Intuition

A feature store manages reusable features for training and inference.

It helps keep feature definitions consistent.

### Formal Explanation

Feature stores provide:

- Feature definitions
- Offline features for training
- Online features for real-time inference
- Feature versioning
- Feature monitoring
- Access control

### Real-World Example

Fraud detection:

Feature:

```text
Number of failed transactions in last 10 minutes
```

The same feature should be computed consistently during training and real-time scoring.

### Common Interview Questions

- What is a feature store?
- Why use a feature store?
- Offline store vs online store?
- What is training-serving skew?
- When is a feature store overkill?

### Tricky Follow-Ups

- How do you handle time-travel correctness?
- How do you avoid leakage in historical features?
- How do you update online features in real time?

### Mistakes Candidates Make

- Thinking feature stores are always needed.
- Ignoring point-in-time correctness.
- Not considering latency.

### Mini Quiz

1. What is a feature store?
2. What is an offline feature store?
3. What is an online feature store?
4. What is training-serving skew?
5. What is point-in-time correctness?

### Practical Assignment

Design features for a fraud model and decide which should be online vs offline.

---

## 10.6 A/B Testing

### Intuition

A/B testing compares two versions in production to see which performs better.

### Formal Explanation

Users are split into groups:

- Control group: existing model or experience
- Treatment group: new model or experience

Compare business and model metrics.

### Real-World Example

Recommendation system:

- Control: old recommender
- Treatment: new recommender
- Metrics: click-through rate, conversion, revenue, session time

### Common Interview Questions

- What is A/B testing?
- Why not deploy a model immediately?
- What metrics do you track?
- What is statistical significance?
- What is guardrail metric?

### Tricky Follow-Ups

- What if offline metrics improve but online metrics drop?
- How long should an A/B test run?
- How do you avoid sample bias?
- What are network effects?

### Mistakes Candidates Make

- Ignoring guardrail metrics.
- Ending tests too early.
- Looking only at average results.
- Not considering user segments.

### Mini Quiz

1. What is a control group?
2. What is a treatment group?
3. Why use guardrail metrics?
4. What is statistical significance?
5. Why can offline and online metrics disagree?

### Practical Assignment

Design an A/B test for a new recommendation model.

---

## 11. Phase 8: Interview Preparation

## 11.1 Answer Structure

Use this structure for theory answers:

1. One-sentence definition
2. Intuition
3. Formal detail
4. Example
5. Tradeoff or limitation

Example:

Question:

```text
What is overfitting?
```

Strong answer:

```text
Overfitting happens when a model learns the training data too closely, including noise, so it performs well on training data but poorly on unseen data. The intuition is that the model memorized instead of generalizing. We detect it by comparing training and validation metrics: low training error but high validation error indicates overfitting. Common fixes include regularization, simpler models, more data, early stopping, dropout, or pruning. For example, a very deep decision tree may perfectly classify training samples but fail on new data.
```

### For System Design Answers

Use this structure:

1. Clarify requirements
2. Define inputs and outputs
3. Choose high-level architecture
4. Explain data flow
5. Discuss models and algorithms
6. Discuss evaluation
7. Discuss scaling and latency
8. Discuss monitoring
9. Discuss security and failure modes
10. Summarize tradeoffs

---

## 11.2 Beginner Interview Questions

### ML Basics

1. What is machine learning?
2. What is the difference between AI, ML, and deep learning?
3. What is supervised learning?
4. What is unsupervised learning?
5. Regression vs classification?
6. What is overfitting?
7. What is underfitting?
8. What is train/test split?
9. What is a feature?
10. What is a label?

### Python

1. Write a function to compute mean.
2. Write a function to compute median.
3. Count word frequencies in a sentence.
4. Remove duplicates from a list.
5. Find the second largest number.
6. Normalize a list of numbers.
7. Implement dot product.
8. Implement cosine similarity.
9. Read a CSV using pandas.
10. Handle missing values in a DataFrame.

### Math

1. What is a vector?
2. What is a matrix?
3. What is dot product?
4. What is cosine similarity?
5. What is mean?
6. What is variance?
7. What is standard deviation?
8. What is probability?
9. What is a derivative?
10. What is gradient descent?

---

## 11.3 Intermediate Interview Questions

### Machine Learning

1. Explain bias-variance tradeoff.
2. Explain regularization.
3. L1 vs L2 regularization?
4. What is cross-validation?
5. How do you handle imbalanced data?
6. Precision vs recall?
7. ROC-AUC vs PR-AUC?
8. Decision tree vs random forest?
9. Bagging vs boosting?
10. XGBoost vs LightGBM?

### Deep Learning

1. What is backpropagation?
2. What is an activation function?
3. Why use ReLU?
4. What is vanishing gradient?
5. What is dropout?
6. What is batch normalization?
7. What is Adam?
8. CNN vs RNN?
9. LSTM vs GRU?
10. What is attention?

### NLP

1. What is tokenization?
2. What is TF-IDF?
3. What is Word2Vec?
4. What is GloVe?
5. What is semantic similarity?
6. What is BERT?
7. What is GPT?
8. What is named entity recognition?
9. How do you build a text classifier?
10. How do you evaluate summarization?

---

## 11.4 Advanced Interview Questions

### Transformers and LLMs

1. Explain self-attention.
2. Explain query, key, and value.
3. Why do transformers need positional encoding?
4. What is causal masking?
5. BERT vs GPT?
6. What is instruction tuning?
7. What is RLHF?
8. What is temperature?
9. What is top-p?
10. Why do LLMs hallucinate?

### RAG

1. Design a RAG system for company documents.
2. How do you choose chunk size?
3. Dense retrieval vs sparse retrieval?
4. What is hybrid search?
5. What is reranking?
6. What is query rewriting?
7. How do you evaluate RAG?
8. What are common RAG failure modes?
9. How do you secure a RAG system?
10. How do you reduce RAG latency and cost?

### MLOps

1. How do you deploy a model?
2. Batch vs real-time inference?
3. What is model monitoring?
4. Data drift vs concept drift?
5. What is experiment tracking?
6. What is a model registry?
7. What is a feature store?
8. What is CI/CD for ML?
9. How do you run an A/B test?
10. How do you roll back a bad model?

---

## 12. Coding Practice Plan

### Beginner Python

Implement:

1. Mean
2. Median
3. Mode
4. Variance
5. Standard deviation
6. Min-max scaling
7. Z-score normalization
8. Dot product
9. Cosine similarity
10. Train/test split

### NumPy

Practice:

1. Create arrays
2. Reshape arrays
3. Matrix multiplication
4. Broadcasting
5. Axis operations
6. Vectorized distance calculation
7. Batch normalization calculation
8. Softmax implementation
9. Cross-entropy loss
10. Gradient descent for linear regression

### pandas

Practice:

1. Load CSV
2. Inspect data
3. Handle missing values
4. Group by
5. Merge tables
6. Encode categorical features
7. Create date features
8. Detect outliers
9. Split features and labels
10. Build preprocessing pipeline

### ML From Scratch

Implement:

1. Linear regression
2. Logistic regression
3. K-means
4. k-nearest neighbors
5. Decision tree intuition
6. Gradient descent
7. Evaluation metrics
8. Confusion matrix
9. Cross-validation
10. Simple neural network

---

## 13. Practical Project Roadmap

### Project 1: House Price Prediction

Skills:

- Regression
- Feature engineering
- Model evaluation
- Linear regression
- Random forest

Deliverables:

- Notebook
- Metrics report
- Error analysis
- Short explanation

### Project 2: Customer Churn Prediction

Skills:

- Classification
- Imbalanced data
- Feature engineering
- Precision and recall
- Business metric thinking

Deliverables:

- Model
- Confusion matrix
- Feature importance
- Deployment plan

### Project 3: Spam Classifier

Skills:

- NLP
- TF-IDF
- Logistic regression
- Text preprocessing

Deliverables:

- Text classifier
- Error examples
- Metric comparison

### Project 4: Image Classifier

Skills:

- CNNs
- Transfer learning
- Deep learning training

Deliverables:

- PyTorch model
- Training curves
- Misclassification analysis

### Project 5: Semantic Search App

Skills:

- Embeddings
- Cosine similarity
- Vector search

Deliverables:

- Search demo
- Query examples
- Retrieval evaluation

### Project 6: PDF RAG Chatbot

Skills:

- Document loading
- Chunking
- Embeddings
- Vector DB
- Retrieval
- LLM response generation

Deliverables:

- Working RAG prototype
- Architecture diagram
- Evaluation set
- Failure mode analysis

### Project 7: Production RAG Design

Skills:

- Security
- Metadata filtering
- Reranking
- Monitoring
- Cost optimization
- System design

Deliverables:

- Architecture document
- API design
- Monitoring plan
- Security plan

### Project 8: ML Model Deployment

Skills:

- FastAPI
- Model serving
- Docker basics
- Monitoring

Deliverables:

- API endpoint
- Model artifact
- Inference script
- Deployment README

---

## 14. ML System Design Templates

## 14.1 Churn Prediction System

Clarify:

- What is churn?
- How early should we predict?
- What action will be taken?
- What data is available?

Data:

- User profile
- Login history
- Billing history
- Support tickets
- Product usage

Model:

- Logistic regression baseline
- Random forest
- Gradient boosting

Metrics:

- Precision
- Recall
- F1
- ROC-AUC
- PR-AUC
- Business lift

Deployment:

- Batch scoring daily or weekly
- Send high-risk users to retention campaign

Monitoring:

- Feature drift
- Churn rate
- Campaign effectiveness
- Prediction distribution

Risks:

- Label delay
- Data leakage
- User behavior changes

## 14.2 Fraud Detection System

Clarify:

- Real-time or batch?
- Cost of false positives?
- Cost of false negatives?
- Available latency budget?

Data:

- Transaction amount
- Merchant
- Device
- Location
- User history
- Velocity features

Model:

- Rules baseline
- Gradient boosting
- Neural network if enough data

Metrics:

- Recall
- Precision
- PR-AUC
- False positive rate
- Financial loss prevented

Deployment:

- Real-time API
- Human review queue
- Risk thresholds

Monitoring:

- Fraud patterns
- Drift
- Latency
- False positive complaints

Risks:

- Adversarial behavior
- Concept drift
- Imbalanced labels

## 14.3 Recommendation System

Clarify:

- Recommend what?
- Optimize clicks, purchases, watch time, or satisfaction?
- Real-time or batch?

Data:

- User interactions
- Item metadata
- User profile
- Context

Approaches:

- Popularity baseline
- Collaborative filtering
- Content-based filtering
- Two-tower retrieval
- Ranking model

Metrics:

- Precision@k
- Recall@k
- NDCG
- CTR
- Conversion
- Retention

Deployment:

- Candidate generation
- Ranking
- Re-ranking
- Business rules

Monitoring:

- CTR
- Diversity
- Freshness
- Latency
- Feedback loops

Risks:

- Popularity bias
- Filter bubbles
- Cold start

---

## 15. GenAI and RAG System Design Templates

## 15.1 Chat With PDFs

Requirements:

- Upload PDFs
- Ask questions
- Retrieve relevant passages
- Generate answers with citations

Architecture:

```text
PDF upload
  -> Parse text
  -> Extract tables/images if needed
  -> Chunk text
  -> Generate embeddings
  -> Store in vector database

Question
  -> Embed question
  -> Retrieve chunks
  -> Rerank
  -> Build prompt
  -> Generate answer
  -> Return citations
```

Key decisions:

- Chunk size
- Embedding model
- Vector DB
- Reranker
- Citation format
- Fallback behavior

Failure modes:

- Bad PDF extraction
- Wrong chunks retrieved
- Hallucinated answer
- Missing citations

Evaluation:

- Retrieval recall
- Answer correctness
- Faithfulness
- Citation accuracy
- Latency

## 15.2 Enterprise Knowledge Assistant

Requirements:

- Search across internal docs
- Respect permissions
- Answer with citations
- Handle stale documents
- Support multiple departments

Architecture:

- Ingestion from Google Drive, SharePoint, Confluence, Slack, and databases
- Document parsing
- Metadata extraction
- Permission sync
- Chunking
- Embedding
- Hybrid index
- Retrieval with ACL filtering
- Reranking
- Answer generation
- Logging and monitoring

Security:

- Authentication
- Authorization
- Access-controlled retrieval
- Audit logs
- PII handling
- Prompt injection defense

Monitoring:

- Query volume
- Latency
- Cost
- Retrieval quality
- User feedback
- Permission violations

## 15.3 Customer Support Agent

Requirements:

- Answer customer questions
- Retrieve policy and product information
- Use tools for account/order status
- Escalate to human when needed

Architecture:

- RAG for knowledge base
- Function calling for account tools
- Guardrails for policy compliance
- Conversation memory
- Human handoff

Tools:

- Order lookup
- Refund status
- Ticket creation
- Account verification

Guardrails:

- Never expose private data without authentication
- Do not make refunds without confirmation
- Escalate angry or complex cases
- Cite policy where useful

Evaluation:

- Resolution rate
- Escalation rate
- Customer satisfaction
- Hallucination rate
- Tool-call success rate

---

## 16. Spaced Revision Plan

### Daily

- Review previous session notes.
- Answer 5 flash questions.
- Write 1 concept explanation in your own words.

### Weekly

- Take one mini quiz.
- Solve one coding assignment.
- Do one mock interview round.
- Update weak-topic list.

### Every 2 Weeks

- Revisit all topics learned so far.
- Build one small project component.
- Practice one system design question.

### Monthly

- Full mock interview:
  - 20 minutes theory
  - 30 minutes coding
  - 30 minutes system design
  - 10 minutes feedback

---

## 17. First 30-Day Study Plan

### Week 1: Python and Math Basics

Day 1:

- What is ML?
- Features and labels
- Python functions

Day 2:

- Lists, dictionaries, loops
- Mean, median, standard deviation

Day 3:

- Vectors and dot product
- Cosine similarity

Day 4:

- Probability and statistics basics
- Mean, variance, standard deviation

Day 5:

- Derivatives and gradients
- Gradient descent intuition

Day 6:

- Coding practice
- Implement math functions

Day 7:

- Review and quiz

### Week 2: Core ML

Day 8:

- Supervised vs unsupervised learning

Day 9:

- Regression
- Linear regression

Day 10:

- Classification
- Logistic regression

Day 11:

- Train/test split
- Cross-validation

Day 12:

- Metrics for regression and classification

Day 13:

- Overfitting, underfitting, regularization

Day 14:

- Review and mock questions

### Week 3: Classical ML Algorithms

Day 15:

- kNN and Naive Bayes

Day 16:

- Decision trees

Day 17:

- Random forests

Day 18:

- Gradient boosting

Day 19:

- XGBoost and LightGBM

Day 20:

- Feature engineering

Day 21:

- Project: tabular classification

### Week 4: Deep Learning Start

Day 22:

- Neural networks

Day 23:

- Backpropagation

Day 24:

- Activation functions and loss functions

Day 25:

- Optimizers

Day 26:

- CNNs

Day 27:

- RNNs, LSTMs, GRUs

Day 28:

- Attention intuition

Day 29:

- Transformer overview

Day 30:

- Review, quiz, and mock interview

---

## 18. First Homework

Rewrite these answers in your own words:

1. What is machine learning?
2. What is overfitting?
3. What is underfitting?
4. What is tokenization?
5. What happens during backpropagation?

Then implement these functions in Python:

1. `mean(nums)`
2. `median(nums)`
3. `standard_deviation(nums)`
4. `dot_product(a, b)`
5. `cosine_similarity(a, b)`

Finally, answer:

1. Why is accuracy not always a good metric?
2. Why do we split data into train and test sets?
3. What is the difference between ML and DL?
4. What is one reason an LLM might hallucinate?
5. What is the basic idea of RAG?

---

## 19. Progress Tracker

Use this checklist as you learn.

### Foundations

- [ ] Python basics
- [ ] NumPy basics
- [ ] pandas basics
- [ ] Vectors
- [ ] Matrices
- [ ] Dot product
- [ ] Cosine similarity
- [ ] Probability basics
- [ ] Statistics basics
- [ ] Gradients
- [ ] Gradient descent

### Machine Learning

- [ ] Supervised learning
- [ ] Unsupervised learning
- [ ] Regression
- [ ] Classification
- [ ] Clustering
- [ ] Train/test split
- [ ] Cross-validation
- [ ] Bias-variance tradeoff
- [ ] Overfitting
- [ ] Underfitting
- [ ] Regularization
- [ ] Feature engineering
- [ ] Evaluation metrics
- [ ] Hyperparameter tuning
- [ ] Decision trees
- [ ] Random forests
- [ ] Gradient boosting
- [ ] XGBoost
- [ ] LightGBM

### Deep Learning

- [ ] Neural networks
- [ ] Backpropagation
- [ ] Activation functions
- [ ] Loss functions
- [ ] Optimizers
- [ ] CNNs
- [ ] RNNs
- [ ] LSTMs
- [ ] GRUs
- [ ] Attention
- [ ] Transformers
- [ ] Transfer learning
- [ ] Fine-tuning

### NLP

- [ ] Tokenization
- [ ] Bag of words
- [ ] TF-IDF
- [ ] Word2Vec
- [ ] GloVe
- [ ] Embeddings
- [ ] Text classification
- [ ] Named entity recognition
- [ ] Summarization
- [ ] Semantic search
- [ ] BERT
- [ ] GPT-style models

### Generative AI

- [ ] LLM basics
- [ ] Prompt engineering
- [ ] Instruction tuning
- [ ] RLHF
- [ ] Fine-tuning vs prompting vs RAG
- [ ] Context window
- [ ] Temperature
- [ ] Top-p
- [ ] Hallucinations
- [ ] Guardrails
- [ ] Agents
- [ ] Function calling
- [ ] Tool use
- [ ] Multimodal AI

### RAG

- [ ] RAG basics
- [ ] Embeddings
- [ ] Chunking
- [ ] Vector databases
- [ ] Similarity search
- [ ] Dense retrieval
- [ ] Sparse retrieval
- [ ] Hybrid search
- [ ] Reranking
- [ ] Query rewriting
- [ ] Metadata filtering
- [ ] Context construction
- [ ] RAG evaluation
- [ ] RAG failure modes
- [ ] Production RAG architecture
- [ ] Security and privacy

### MLOps

- [ ] Model deployment
- [ ] Batch inference
- [ ] Real-time inference
- [ ] Model monitoring
- [ ] Data drift
- [ ] Concept drift
- [ ] Experiment tracking
- [ ] Model versioning
- [ ] Feature stores
- [ ] CI/CD for ML
- [ ] A/B testing
- [ ] Latency
- [ ] Scalability
- [ ] Cost optimization

### Interview Practice

- [ ] Beginner ML questions
- [ ] Intermediate ML questions
- [ ] Advanced ML questions
- [ ] Python coding questions
- [ ] NumPy coding
- [ ] pandas coding
- [ ] ML system design
- [ ] GenAI system design
- [ ] RAG system design
- [ ] Mock interview 1
- [ ] Mock interview 2
- [ ] Mock interview 3

---

## 20. How We Will Continue

Next lesson:

```text
Lesson 1: What Machine Learning Actually Is
```

We will cover:

1. Intuition first
2. Formal explanation
3. Types of learning
4. Regression vs classification
5. Real-world examples
6. Simple Python example
7. Interview questions
8. Tricky follow-ups
9. Mistakes candidates make
10. Mini quiz
11. Homework

The focus will be on building a strong base before moving into deeper ML, DL, LLM, and RAG topics.

