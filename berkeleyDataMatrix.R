setwd("/Users/allison/Desktop/Markov_2019_Research")
dF <- read.csv("year_avg.csv", header = F)
dF$V1 -> dataList
lenDataList <- length(dataList)
percentChange <- vector()

for(i in 2:lenDataList-1)
{
  cur <- dataList[i]
  nex <- dataList[i+1]
  change <- ((nex - cur) / abs(cur)) * 100
  percentChange  <- append(percentChange, change)
}

binList <- c(-2.5, -2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2, 2.5, 3)
tStates <- cut(percentChange, breaks = binList,
               labels = c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11))

library(markovchain)
weatherFittedMLE <- markovchainFit(data = tStates)
weatherFittedMLE

yearsPredictedTemp <- vector()
for(i in 1:1)
{
  simStates <- rmarkovchain(n = 80, object = weatherFittedMLE$estimate, t0 = 2)
  
  lenSimStates <- length(simStates) 
  i = 1
  k = 1
  
  simPercentChange <- vector()
  
  while(i <= lenSimStates)
  {
    for(k in 1:(length(binList) - 1))
    {
      if(simStates[i] == k)
      {
        simPercentChange[i] = ((((binList[k] + binList[k+1])/2))/100)+1
      }
    }
    i <- i + 1
  }
  
  curAvgT = 14.178 + 0.77
  
  cumPerChange = cumprod(simPercentChange)
  #print(cumPerChange)
  predictedTemp <- vector()
  
  predictedTemp[1]=curAvgT
  for(i in 1: lenSimStates)
    predictedTemp[i + 1] = curAvgT * (cumPerChange[i])
  
  yearsPredictedTemp <- append(yearsPredictedTemp, predictedTemp)
}

print(yearsPredictedTemp)

tempMatrix <- matrix (yearsPredictedTemp, nrow = 80, byrow = F)

print(tempMatrix)

#print(simPercentChange)
#print(predictedTemp)
 

plotTemp <- plot(dataList, type = "l", ylim = c(11, 19), xlim = c(0, 250))
#lines(predictedTemp, xlim = c(169, 250), type = "l", col = "red")
points(x = 169: 249, y = predictedTemp, type = "l", col = "red")
pr


#source command 
