import random
import sys

# Initialize the matrix
matrix = [['C' for _ in range(20)] for _ in range(20)]

# Add the crystal to a random location in the matrix
crystal_x, crystal_y = random.randint(0, 19), random.randint(0, 19)
matrix[crystal_x][crystal_y] = '*'

# Add 25 rewards to random locations in the matrix
rewards = ['J', 'P', 'W']
for _ in range(25):
    reward_x, reward_y = random.randint(0, 19), random.randint(0, 19)
    while matrix[reward_x][reward_y] != 'C':
        reward_x, reward_y = random.randint(0, 19), random.randint(0, 19)
    matrix[reward_x][reward_y] = random.choice(rewards)

# Add 15 death points to random locations in the matrix
for _ in range(15):
    death_x, death_y = random.randint(0, 19), random.randint(0, 19)
    while matrix[death_x][death_y] != 'C':
        death_x, death_y = random.randint(0, 19), random.randint(0, 19)
    matrix[death_x][death_y] = '%'

# Add 50 obstacles to random locations in the matrix
for _ in range(50):
    obstacle_x, obstacle_y = random.randint(0, 19), random.randint(0, 19)
    while matrix[obstacle_x][obstacle_y] != 'C':
        obstacle_x, obstacle_y = random.randint(0, 19), random.randint(0, 19)
    matrix[obstacle_x][obstacle_y] = '#'

# Add 20 monsters to random locations in the matrix
monsters = ['&', '$', '@']
for _ in range(20):
    monster_x, monster_y = random.randint(0, 19), random.randint(0, 19)
    while matrix[monster_x][monster_y] != 'C':
        monster_x, monster_y = random.randint(0, 19), random.randint(0, 19)
    matrix[monster_x][monster_y] = random.choice(monsters)

# Save the output to a text file
original_stdout = sys.stdout
with open('output.txt', 'w') as f:
    sys.stdout = f

    # Print the matrix
    for row in matrix:
        print(' '.join(row))

# Restore the original output stream (console)
sys.stdout = original_stdout
