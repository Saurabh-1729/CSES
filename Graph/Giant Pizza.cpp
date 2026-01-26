/*
This is the 2-SAT Problem: 
2-SAT (2-satisfiability) is a computational problem that determines if a Boolean formula, expressed as a Conjunction of clauses (CNF) where each clause has exactly
two literals (variables or their negations), can be satisfied. Unlike general 3-SAT, 2-SAT is solvable in linear time (\(O(n+m)\)) using strongly connected components.
Key Aspects of 2-SAT Problem Structure: It involves assigning True/False values to variables (\(x_{1},x_{2},\dots ,x_{n}\)) 
to satisfy clauses like \((x_{1}\lor \neg x_{2})\).Implicative Form: 2-SAT problems are often solved by converting them into an implication graph, 
where \((A\lor B)\) is represented as \((\neg A\implies B)\) and \((\neg B\implies A)\).Solvability: A 2-SAT instance is unsatisfiable if and
only if \(x\) and \(\neg x\) exist in the same strongly connected component.Efficiency: It is solvable in linear time \(O(V+E)\) using algorithms like
Kosaraju's or Tarjan's. It is widely used to solve problems involving dependency constraints, such as scheduling or circuit design, where choices are limited
to two options. 
*/
