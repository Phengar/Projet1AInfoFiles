#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np



def main():
	with open("/root/Documents/Projet_info/testblabla","r") as file:
		data_array=[line.split(" ") for count,line in enumerate(file)]
		for data in data_array:
			print(data)
			print("test")
		max_day=int(data_array[0][1])
		for_plots=[[] for i in range(max_day)]
		for client in data_array:
			for_plots[int(client[1])-1].append(client)
		X=[int(personne[0]) for personne in for_plots[0]]
		Y=[int(personne[2]) for personne in for_plots[0]]
		plt.plot(X,Y)
		plt.show()
	return


main()
