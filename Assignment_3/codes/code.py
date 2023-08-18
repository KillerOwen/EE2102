from scipy.stats import binom

def calculate_probability_of_losing():
    n = 3  # Number of coin tosses
    p = 0.5  # Probability of getting heads (or tails) in a single toss

    # Calculate the probability of getting different outcomes in all three tosses
    favorable_outcomes = binom.pmf(1, n, p) + binom.pmf(2, n, p)
    
    return favorable_outcomes

losing_probability = calculate_probability_of_losing()
print(f"The probability of Hanif losing the game is approximately {losing_probability:.2f}")

