# Basket-Asian Option Pricing
Overview: This repository contains an OOP implementation of basket-asian option pricing using Monte Carlo Simulation and operator overloading in C++.

## Features:
Basket-Asian option pricing: The code provides a comprehensive implementation of pricing basket of Asian options whose payoff depends on the entire path of the underlying asset. The assets are assumed to follow Geometric-Brownian motion. 

Monte Carlo Simulation: The option price is calculated using Monte Carlo Simulation, a widely used numerical method for pricing options.

## File Structure:
Main.cpp: Contains the main method calling the Price by Monte Carlo to price Basket of Asian Options.

MCModel02.h: Defines the Mone Carlo class, which encapsulates the necessary parameters and methods to generate sample paths which are used for simulation.

PathDepOption02.h: Defines PathDepOption Class which encapsulates necessary methods to price path dependent options. Additionally, Path Dependent option acts as a parent class for Arithematic Asian options. Payoff is a virtual function which is inherited by Arithematic Asian Option class.

Matrix.cpp: Defines operator overloading methods which are used to price the basket of Asian options. 

Makefile: It defines a set of rules and dependencies for compiling and linking source code files, managing dependencies, and generating executable files or libraries.


