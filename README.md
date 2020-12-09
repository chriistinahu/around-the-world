# Around the World 🌎 

*Contributors: Amy Qian, Cindia Hua, Christina Hu*

Have you ever wondered what the shortest path between O'Hare to John Wayne Aiport is? What about the shortest distance from O'Hare to all of the other aiports in the world? Or the shortest distance from O'Hare to Haneda Airport but you also *really, really* want to pass through John F. Kennedy International Aiport at the same time? Well, we've got you covered! Using the hottest travesals known as BFS, Dijkstra, and Landmark Path, you now have a way to find out all of this information and more to your heart's content! 

## File Format

For this project to compile, you will need two CSV text files: one containing airport data and another containing route data.

### Aiports Text File

This file should contain the following attributes:

<img src="https://github-dev.cs.illinois.edu/cs225-fa20/ch35-amyyq2-xinranh2/blob/master/readme_media/airport_1.png" width="600">

Here is a sample of what a few rows of data could look like:

<img src="https://github-dev.cs.illinois.edu/cs225-fa20/ch35-amyyq2-xinranh2/blob/master/readme_media/airport_2.png" width="1000">


### Routes Text File

This file should contain the following attributes:

<img src="https://github-dev.cs.illinois.edu/cs225-fa20/ch35-amyyq2-xinranh2/blob/master/readme_media/route_1.png" width="850">

Here is a sample of what a few rows of data could look like:

<img src="https://github-dev.cs.illinois.edu/cs225-fa20/ch35-amyyq2-xinranh2/blob/master/readme_media/route_2.png" width="200">


## Executable Instructions

In order to run `main`, which runs BFS, Dijkstra, and Landmark simultaneously, please run `make` and then follow the following order of arguments:

`make`

`./main <AIRPORTS_FILE> <ROUTES_FILE> <SOURCE> <DEST> <LANDMARK>`

In order to run each of the traversals individually, please follow the following order of arguments:

`./run_traversal <AIRPORTS_FILE> <ROUTES_FILE> <SOURCE_ID> <DEST_ID>` 

For Landmark, there will be an extra `<LANDMARK_ID>` argument at the end. 

### Argument Definitions

- `AIRPORTS_FILE`: Must be in CSV file format. Please refer to the [File Format](#file-format) section to see what the file should look like. Enter the **file path** of the file.
- `ROUTES_FILE`: Must be in CSV file format. Please refer to the [File Format](#file-format) section to see what the file should look like. Enter the **file path** of the file.
- `SOURCE_ID`: Must be a string, the ICAO airport code of the source airport. (ex. ORD, LAX, JFK, etc)
- `DEST_ID`: Must be a string, the ICAO airport code of the destination airport. (ex. ORD, LAX, JFK, etc)
- `LANDMARK_ID`: Must be a string, the ICAO airport code of the landmark airport to pass through. (ex. ORD, LAX, JFK, etc)


**BFS**

`./run_bfs <AIRPORTS_FILE> <ROUTES_FILE> <SOURCE_ID> <DEST_ID>`

**Dijkstra**

`./run_dijkstra <AIRPORTS_FILE> <ROUTES_FILE> <SOURCE_ID> <DEST_ID>`

**Landmark**

`./run_landmark <AIRPORTS_FILE> <ROUTES_FILE> <SOURCE_ID> <DEST_ID> <LANDMARK_ID>`

- add gif showing example

## Output

After running the executable for a traversal, you should see the resulting path print out in the terminal. It will be in the format of: `source_airport -> airport_2 -> airport_3 -> dest_airport`

Below is a sample output:

<img src="https://github-dev.cs.illinois.edu/cs225-fa20/ch35-amyyq2-xinranh2/blob/master/readme_media/dijkstra_2.png" width="850">


For Dijkstra, there is an additional output being printed. Since Dijkstra is also able to find the shortest path from a source to every other airport, you should see something in the format of: 

`dest_1 | distance`

`dest_2 | distance`

Where `dest_i` is the destination airport and `distance` is the shortest distance from the source airport to the destination airport. 

Below is a sample output:

<img src="https://github-dev.cs.illinois.edu/cs225-fa20/ch35-amyyq2-xinranh2/blob/master/readme_media/dijkstra_1.png" width="500">


## Tests

To run tests for this project, run in the terminal:

`make test`

`./test`

To run tests for the specific traversals, run with:

`./test [bfs]` or `./test [dijkstra]` or `./test [landmark]`
