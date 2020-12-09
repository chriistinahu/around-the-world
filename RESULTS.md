# Project Outcomes

For our final project, we implemented BFS, Dijkstra, and Landmark Path algorithms. We were able to finish all of the traversals and wrote tests to check each functionality. We chose to use the Open Flights dataset to use the algorithms on. In particular, we used the Routes.txt and Airports.txt datasets. 

Routes.txt only included data on the source and destination airports of each route, while Airports.txt included specific details on each airport such as its main city served, latitude, and longitude. Since the airport ID attribute is the common feature between the two datasets, we used it to match and locate information for each airport in the file. It was very important to ensure that all airports in Routes.txt had a corresponding entry in Airports.txt in order to retrieve its latitude and longitude coordinates. We removed any airports, which were very few in number, that did not satisfy that requirement. 

In order to calculate the distances between locations using the latitude and longitude coordinates, we used the Haversine formula, which determines the great-circle distance between two points on a sphere. We acknowledge that the formula does introduce some error since Earth is a spheroid, but upon comparison with the true distances, our calculated distances are relatively accurate. We also acknowledge that we could have used the Vincenty formula instead, which is more accurate for calculating geodesic distances as it accounts for the ellipsoidal model of the Earth. However, the formula was very complicated and we felt like it would be better to use one that we understood better and was computationally less heavy.  

Using BFS, we were able to traverse the entire graph and return an in order vector of the Vertices that were visited. We were able to find the shortest path from a source to a destination airport, only considering the number of stops between the airports instead of the distances. 

For Dijkstra we implemented two functions; one is able to calculate the shortest paths between a source airport to all other airports in the graph, and the other is able to calculate the shortest path from a source airport to a destination airport. In both cases, the distances between each airport in the graph are used in the algorithm as the graph weights. 

For Landmark Path, we were able to find the shortest path considering the distances between a source and destination airport, with the condition that a third airport must also be visited during the process. Since this algorithm requires two traversals, one from source to landmark airport and another from the landmark airport to the destination airport, we used two Dijkstra traversals to find the shortest paths. 

We also created executables for running the main file, which runs all of the traversals at once, as well as running each traversal individually. Each traversal other than Dijkstra has a single output. For Dijkstra, we have two outputs, one for finding the shortest distance between a source and a destination airport, and another displaying the shortest distances from a source to ALL airports in the graph. Below is a sample output when running Dijkstra’s algorithm:




An interesting discovery that we made is that Los Angeles International Airport does not have direct flights to Kansai International Airport which is surprising since Los Angeles International Airport seems to fly to many major international airports. It was also interesting to discover that there is an airport in Peru, Tarapoto Airport, that only flies to two other airports in the world. Furthermore, we learned that sometimes, the direct flight between two airports is not always the shortest path!
