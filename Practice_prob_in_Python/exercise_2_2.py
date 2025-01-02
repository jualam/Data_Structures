def print_items(n):
    for i in range(n):
        for j in range(n):
            print(i,j)
  
        
print_items(10)

#in big-O this ran for n*n times,so O(n^2)is the time complexity