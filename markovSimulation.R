mcWeather <- new("markovchain", states = c("sunny", "cloudy", "rain"),
                  transitionMatrix = matrix(data = c(0.70, 0.2, 0.1,
                                                        0.3, 0.4, 0.3,
                                                        0.2, 0.45, 0.35), byrow = TRUE, nrow = 3),
                  name = "Weather")
Nsim=10000
Ntimesteps=1000
endValues <- vector(length=Nsim)

for (i in 1:Nsim)
{
  weathersOfDays <- rmarkovchain(n = Ntimesteps, object = mcWeather, t0 = "sunny")
  end = tail(weathersOfDays, 1)
  endValues[i]=end 
}

print(endValues)

table(endValues)/Nsim
mcWeather^1000

