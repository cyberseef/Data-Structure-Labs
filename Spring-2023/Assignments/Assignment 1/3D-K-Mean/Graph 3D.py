import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

# After clustering
plt.figure()
df = pd.read_csv("C:\\Users\\Cyberseef\\Desktop\\Assignment 1\\Output\\output3d.csv")
sns.scatterplot(x=df.x, y=df.y,
                hue=df.c,
                palette=sns.color_palette("hls", n_colors=5))
plt.xlabel("mean_dist_day")
plt.ylabel("mean_over_speed_perc")
plt.title("Clustered")

plt.show()