# XOR Problem Solution using RBFN

## 1. Problem Definition
XOR truth table:
- f(0,0) = 0
- f(0,1) = 1
- f(1,0) = 1
- f(1,1) = 0

## 2. RBFN Architecture
- Input layer: 2 nodes
- Hidden layer: 4 RBF neurons
- Output layer: 1 node

## 3. RBF Centers
c₁ = (0,0), c₂ = (0,1), c₃ = (1,0), c₄ = (1,1)

## 4. RBF Width
σ = 0.5 (chosen arbitrarily)

## 5. Gaussian RBF Activation Function
φ(x) = exp(-||x - c||² / (2σ²))

Where:
- x is the input vector
- c is the center vector
- σ is the width parameter

## 6. Output Calculation
y = w₁φ₁(x) + w₂φ₂(x) + w₃φ₃(x) + w₄φ₄(x)

Where wᵢ are the weights from the hidden layer to the output.

## 7. Activation Calculations for Each Input

### For input (0,0):
φ₁(0,0) = exp(-||(0,0) - (0,0)||² / (2·0.5²)) = 1
φ₂(0,0) = exp(-||(0,0) - (0,1)||² / (2·0.5²)) ≈ 0.1353
φ₃(0,0) = exp(-||(0,0) - (1,0)||² / (2·0.5²)) ≈ 0.1353
φ₄(0,0) = exp(-||(0,0) - (1,1)||² / (2·0.5²)) ≈ 0.0183

### For input (0,1):
φ₁(0,1) ≈ 0.1353
φ₂(0,1) = 1
φ₃(0,1) ≈ 0.0183
φ₄(0,1) ≈ 0.1353

### For input (1,0):
φ₁(1,0) ≈ 0.1353
φ₂(1,0) ≈ 0.0183
φ₃(1,0) = 1
φ₄(1,0) ≈ 0.1353

### For input (1,1):
φ₁(1,1) ≈ 0.0183
φ₂(1,1) ≈ 0.1353
φ₃(1,1) ≈ 0.1353
φ₄(1,1) = 1

## 8. Weight Determination
To solve the XOR problem, we need to find weights w₁, w₂, w₃, w₄ such that:

1 · w₁ + 0.1353 · w₂ + 0.1353 · w₃ + 0.0183 · w₄ ≈ 0
0.1353 · w₁ + 1 · w₂ + 0.0183 · w₃ + 0.1353 · w₄ ≈ 1
0.1353 · w₁ + 0.0183 · w₂ + 1 · w₃ + 0.1353 · w₄ ≈ 1
0.0183 · w₁ + 0.1353 · w₂ + 0.1353 · w₃ + 1 · w₄ ≈ 0

One possible solution (there are infinitely many) is:
w₁ ≈ -9.65
w₂ ≈ 9.65
w₃ ≈ 9.65
w₄ ≈ -9.65

## 9. Final RBFN Function
f(x₁, x₂) = -9.65 · exp(-||(x₁,x₂) - (0,0)||² / 0.5) 
           + 9.65 · exp(-||(x₁,x₂) - (0,1)||² / 0.5)
           + 9.65 · exp(-||(x₁,x₂) - (1,0)||² / 0.5)
           - 9.65 · exp(-||(x₁,x₂) - (1,1)||² / 0.5)

This function will approximate the XOR operation for binary inputs.
