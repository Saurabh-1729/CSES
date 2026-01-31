/*

This problem is based on re-rooting 

1. first we need to calculate the answer for any node, let it be node 1. 
So while calculating the distance for node1 we parallely calculate the subtree size of each node we visit while calculating the answer for node 1

ans[0] += current_lvl
and size we for that node (v)

after that we need to do some re-rooting. When we move the root node to its neighbour node what all things chnages? 
the answer would change in this way ans[v] = ans[root] - size(v) + (n - size(v))

here root is basically the parent when we are doing dfs for the second time.
 
*/
