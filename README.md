# Lem-in

Optimize ant movement through a simple graph.

Rules:
* The graph can consist of any number of nodes
* Each node can be linked to any other node in the graph
* The goal is to move all the ants from the start node to the end node
* Any number of ants can move each turn if possible
* Only the start and end nodes can hold more than one ant at a time

## Usage

```
make
Usage: ./lem-in [-c -s -v] < sample_file
```

Options:
* -c: color option (color coordinate the ants)
* -v: verbose option (display heatmap connections)
* -s: silent option (silence map info display)

## Input Format
The input graph consists of three portions in the following order:
```
number of ants
list of rooms
list of links between rooms
```
Commands can be placed throughout the file for different effects. Unknown commands will be ignored

List of commands:
* ##start: Next room is the starting position of the ants (required)
* ##end: Next room is the final destination of the ants (required)

### Room format:
Each room is declared using the following format:
* name_of_room x_coordinate y_coordinate

Example:
```
Room1 32 42
``` 
Illegal characters in room names:
* No spaces within the name
* Cannot begin with the character 'L'
* Cannot contain the character '-'

### Link Format:
A link contains two rooms delimited by a '-'.

### Input Example:
```
# number of ants
10
# start of room listings
r1 1 0
r9 0 1
##start
r0 0 0
r2 1 1
##end
r10 2 1
# start of link section
r0-r9
r9-r2
r1-r0
r1-r10
r2-r10
```

Graphical representation of the map:
```
r0-r1-r10
|    /
r9-r2
```


## Output:
Each line for the output displays all the ants that moved that turn.

Format: L[ant_nbr]-[room name]

Only ants that moved during a turn are displayed.


### Example:
The following example took 6 turns to move 10 ants from the start to the end of the graph.
```
L1-r1 L2-r9
L1-r10 L2-r2 L3-r1 L4-r9
L2-r10 L3-r10 L4-r2 L5-r1 L6-r9
L4-r10 L5-r10 L6-r2 L7-r1 L8-r9
L6-r10 L7-r10 L8-r2 L9-r1
L8-r10 L9-r10 L10-r1
L10-r10
```