P=t(matrix(c(0.1,0.9,0,0,0.5,0.5,0.1,0.1,0.8),nrow=3))
Pinf= P%^%100
limdist=Pinf[1,]
n=length(P[1,])
maxT=100
X=vector("numeric",length=maxT)
X[1]=sample(1:n,size=1,prob=limdist)
for(t in 2:maxT){
  X[t]=sample(1:n,size=1,prob=P[X[t-1],])
}

