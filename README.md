# Lem-in

Optimize ant movement through a simple graph.

## Usage

```
make
Usage: ./lem-in [-c -s -v] < file
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

