# Initialize constants.
mu = c(0.001,0.015,0.05)
v  = matrix(c(0.01,0.005,0.0025))
f  = c(500, 300, 200)
C  = 100
T  = 10

# Initialize matrices.
demand  = matrix(nrow = T, ncol = 1)

arrival = matrix(nrow = T, ncol = 3)
colnames(arrival) = c('500', '300', '200')

# Get lambda.
mu = diag(mu)
lambda = t(mu %*% exp(v %*% 1:T) )
colnames(lambda) = c('500', '300', '200')

# Calculate demand.
for (t in 1:T){
  
  arrival[t,1] = rpois(1, lambda[t,1])
  arrival[t,2] = rpois(1, lambda[t,2])
  arrival[t,3] = rpois(1, lambda[t,3])
  
  if (arrival[t,1] == 1){
    demand[t] = 500
  }else if(arrival[t,2] == 1){
    demand[t] = 300
  }else if(arrival[t,3] == 1){
    demand[t] = 200
  }else{
    demand[t] = 0
  }
}
