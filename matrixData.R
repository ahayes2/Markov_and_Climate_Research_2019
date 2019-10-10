setwd("/Users/allison/Desktop/Markov_2019_Research")
dF <- read.csv("weatherData.csv")
tAvg <- df$TAVG
tAvg


tStates <- cut(tavg, breaks = c(0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100),
               labels = c("1", "2", "3", "4","5", "6", "7", "8", "9", "10"))
tStates

library(markovchain)
weatherFittedMLE <- markovchainFit(data = tStates)
weatherFittedMLE
weatherOfDays <- rmarkovchain(n = 365, object = weatherFittedMLE$estimate, t0 = 2)


