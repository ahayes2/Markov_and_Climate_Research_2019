setwd("/Users/allison/Desktop/Markov_2019_Research")
dF <- read.csv("year_avg.csv", header = F)
dF$V1 -> dataList
len <- length(dataList)
percentChange <- vector()

for(i in 2:len-1)
{
  cur <- dataList[i]
  nex <- dataList[i+1]
  change <- ((nex - cur) / abs(cur)) * 100
  percentChange  <- append(percentChange, change)
}

max <- max(percentChange)
min <- min(percentChange)

print(max)
print(min)
print(percentChange)

tStates <- cut(percentChange, breaks = c(-2.5, -2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2, 2.5, 3),
               labels = c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11))
print(tStates)


library(markovchain)
weatherFittedMLE <- markovchainFit(data = tStates)
weatherFittedMLE
simulatedWeather <- rmarkovchain(n = 80, object = weatherFittedMLE$estimate, t0 = 2)

print(simulatedWeather)
