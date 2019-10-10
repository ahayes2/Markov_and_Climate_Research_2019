# Filename: rnoaa examples.R
# Date:     8-1-19

# Notes:    Use this code to locate and download daily weather data from NOAA

# Contact:  Stephen Hayes (hayess@gonzaga.edu)

install.packages("rnoaa")
library('rnoaa')

# This link will be good to study before you begin: https://www.ncdc.noaa.gov/cdo-web/webservices/v2#gettingStarted
# you need an API key emailed to you from NOAA
# goto "https://www.ncdc.noaa.gov/cdo-web/token" to get it... it will be emailed to you, perhaps in your junk email folder?
# then use:
#           options(noaakey = "KEY_EMAILED_TO_YOU")

options(noaakey = "OQcSKRXEsnlzKyefRlHtMnsaxMFXeSgn")

# Which weather station do you want to obtain data from?

# The following commented-out lines locate ncdc stations. I don't think these stations necessarily record daily obs.
# I've left this in because of the handy map box it draws.
# Goto https://recology.info/2015/07/weather-data-with-rnoaa/ for info on where I got this section of code.
#install.packages("lawn")
#library("lawn")
#area.box <- c(-119.5, 46.0, -117.0, 47.75)
#lawn_bbox_polygon(area.box) %>% view
#station.list <- ncdc_stations(extent = c(46.0, -119.5, 47.75, -117.0))
#station.list$data

# To get daily data, use the ghcnd functions in the rnoaa package
# https://www.rdocumentation.org/packages/rnoaa/versions/0.8.4/topics/ghcnd
# This page describes how to parameterize the meteo_nearby_stations function:
# https://www.rdocumentation.org/packages/rnoaa/versions/0.8.4/topics/meteo_nearby_stations

# Be patient while the following line executes, this is a search for all weather station data across the planet!
station_data <- ghcnd_stations()
# This data frame is a required input for the meteo_nearby_stations function
input.df <- data.frame(id = c("Spokane"),
                       latitude = 47.6588,
                       longitude = -117.4260)

nearby_stations <-  meteo_nearby_stations(input.df,
                                          station_data = station_data, radius = 10)

# I chose to use the Spokane Intl Airport weather station data
# USW00024157 SPOKANE INTL AP       47.6     -118.    8.69

nearby_stations

# Examine the type data available for this station
ncdc_stations(datasetid='GHCND', locationid='FIPS:53063', stationid='GHCND:USW00024157')

# Create a dataframe containing ALL the daily data for this station
geg.daily <- ghcnd(stationid = "USW00024157")

# This page will be instrumental to understanding the structure of the geg.daily data frame:
# https://www1.ncdc.noaa.gov/pub/data/ghcn/daily/readme.txt

View(geg.daily)

# The dplyr package is probably the best way to slice and dice the geg.daily dataframe to create your data set
# containing 365 days of weather info... What happened to using the music data?