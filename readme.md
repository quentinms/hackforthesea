# Hack for the sea 2016
## Spock
Spock is an [Adafruit Circuit Playground](https://learn.adafruit.com/introducing-circuit-playground/overview), in charge of collecting the data from the sensors (temperature, light, conductivity)
## Uhura
Uhura is a [Particle Core](https://docs.particle.io/guide/getting-started/start/core/) in charge of communications, gathering the results from Spock, and sending them over wifi to a central server using HTTP.
