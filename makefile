program6: Airport7.o TravelNetwork.o ggerac3Proj7.o
	g++ -std=c++11 -o program7 Airport7.o TravelNetwork.o ggerac3Proj7.o

Airport7.o: Airport7.cpp program7.h
	g++ -std=c++11 -c Airport7.cpp

TravelNetwork.o: TravelNetwork.cpp program7.h
	g++ -std=c++11 -c TravelNetwork.cpp

ggerac3Proj7.o: ggerac3Proj7.cpp program7.h
	g++ -std=c++11 -c ggerac3Proj7.cpp

clean:
	rm Airport7.o TravelNetwork.o ggerac3Proj7.o program7
