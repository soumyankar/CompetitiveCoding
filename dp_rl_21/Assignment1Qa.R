simulate.demand = function(){
# Initialize constants.
mu = c(0.001,0.015,0.05)
v  = matrix(c(0.01,0.005,0.0025))
f  = c(500, 300, 200)
T  = 600

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
return(list(demand, arrival, lambda))
}
compute.lambda = function(T, mu, v){
  mu = diag(mu)
  lambda = t(mu %*% exp(v %*% 1:T) )
  colnames(lambda) = c('500', '300', '200')
  return(lambda)
}

# AIRPLANE: CAPACITY = 500, TIME = 600 ------------------------------------------------------------------------------------
f  = c(500, 300, 200)
T  = 600
C  = 100
mu = c(0.001,0.015,0.05)
v  = matrix(c(0.01,0.005,0.0025))
  
lambda = compute.lambda(T, mu, v)
p500 = lambda[,1]
p300 = lambda[,1] + lambda[,2]
p200 = lambda[,1] + lambda[,2] + lambda[,3]

V = matrix(ncol = T+1, nrow = C)
V[ ,T+1] = 0

A = matrix(ncol = T, nrow = C)

for (s in 1:C){
  for (t in T:1){
    if (s == 1){
      action1 = p500[t] * 500 + (1-p500[t]) * V[s,t+1]
      action2 = p300[t] * 300 + (1-p300[t]) * V[s,t+1]
      action3 = p200[t] * 200 + (1-p200[t]) * V[s,t+1]
      V[s,t] = max(action1, action2, action3)
      A[s,t] = f[which.max(list(action1, action2, action3))]
    }
    else{
      action1 = p500[t] * (500+V[s-1,t+1]) + (1-p500[t]) * V[s,t+1]
      action2 = p300[t] * (300+V[s-1,t+1]) + (1-p300[t]) * V[s,t+1]
      action2 = p200[t] * (200+V[s-1,t+1]) + (1-p200[t]) * V[s,t+1]
      V[s,t] = max(action1, action2, action3)
      A[s,t] = f[which.max(list(action1, action2, action3))]
    }
  }
}

# SIMPLE EXAMPLE FROM LECTURE: CAPACITY = 2, TIME = 3 (TO VERYFY RESULTS) --------------------------------------------------
f  = c(100, 150)
T  = 3
C  = 2

p100 = 0.8
p150 = 0.4

V = matrix(ncol = T+1, nrow = C)
V[ ,T+1] = 0

A = matrix(ncol = T, nrow = C)

for (s in 1:C){
  for (t in T:1){
    if (s == 1){
      action1 = p100 * 100 + (1-p100) * V[s,t+1]
      action2 = p150 * 150 + (1-p150) * V[s,t+1]
      V[s,t] = max(action1, action2)
      A[s,t] = f[which.max(list(action1, action2))]
    }
    else{
      action1 = p100 * (100+V[s-1,t+1]) + (1-p100) * V[s,t+1]
      action2 = p150 * (150+V[s-1,t+1]) + (1-p150) * V[s,t+1]
      V[s,t] = max(action1, action2)
      A[s,t] = f[which.max(list(action1, action2))]
    }
  }
}
print(V)
print(A)
