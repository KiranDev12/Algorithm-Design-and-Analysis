import matplotlib.pyplot as plt

# Read the data from the text file
data = []
with open('/home/kiran/Desktop/Study/Algorithm-Design-and-Analysis/Sorting/InsertionSort/output.txt', 'r') as file:
    lines = file.readlines()

for line in lines:
    row = list(map(float, line.strip().split()))
    data.append(row)

# Transpose the data
data = list(map(list, zip(*data)))

# Create the figure and axes
fig, ax = plt.subplots()

# Plot the data
x = data[0]
y1 = data[1]
y2 = data[2]
y3 = data[3]

ax.plot(x, y1, label='Best')
ax.plot(x, y2, label='Worst')
ax.plot(x, y3, label='Average')

# Set the labels and title
ax.set_xlabel('Size')
ax.set_ylabel('No of basic operations')
ax.set_title('Insertion Sort')

# Add a legend
ax.legend()

# Show the plot
plt.show()
