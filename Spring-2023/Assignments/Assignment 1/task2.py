import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

# After clustering
plt.figure()    # Create a new figure
df = pd.read_csv("C:\\Users\\Cyberseef\\Desktop\\Assignment1\\output.csv")      # Read the csv file
sns.scatterplot(x=df.x, y=df.y,z=df.z,      # Plot the data
                hue=df.c,             # Color the data by cluster      
                palette=sns.color_palette("hls", n_colors=5))       # Set the color palette
plt.xlabel("mean_dist_day")         # Set the x label
plt.ylabel("mean_over_speed_perc")    # Set the y label
plt.title("Clustered")        # Set the title

plt.show()