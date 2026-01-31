/*
“Every node’s farthest node must be one of the two diameter endpoints.”

1. Pick any node and calculate the fartest distance from that node/
2. Now the farthest calculaed node will be the starting point of the second dfs, and that will give us the second another farthest node that is the other end of the diametere

Now we can run the BFS on the above two nodes and can calculate the distance of each node from that farthest node.
  */


