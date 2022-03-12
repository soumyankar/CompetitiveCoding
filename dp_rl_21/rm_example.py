
# Value function
v = [[0 for x in range(4)] for y in range(3)]
v[1][0] = 124.8
v[2][0] = 199.2
v[1][1] = 108
v[1][2] = 80
v[2][1] = 160
v[2][2] = 80

# print (v)
# Pretty print 2D arrays
print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in v]))
mu = [0.4,0.4]
f = [150,100]

value_function_matrix = [[0 for x in range(4)] for y in range(3)]
optimal_function_matrix = [[0 for x in range(4)] for y in range(3)]

for i in range(4):
    for j in range(3):
        first_value = mu[0]*f[0] + (1-mu[0])*value_function_matrix[i][j]
        second_value =mu[1]*f[1] + (1-mu[1])*value_function_matrix[i][j]
        value_function_matrix[i][j] = max(first_value,second_value)
        if first_value >= 100 and first_value < 150:
            optimal_function_matrix[i][j] = 100
        if first_value >=150:
            optimal_function_matrix[i][j] = 150

print('Value function matrix')
print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in value_function_matrix]))
print('Optimal function matrix')
print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in optimal_function_matrix]))