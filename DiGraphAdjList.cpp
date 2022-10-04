#include "DiGraphAdjList.h"

namespace ds {

/**
 * Determine if an edge is in graph
 *
 * @param v1 id of the source node
 * @param v2 id of the target node
 * @return true if the edge is in the graph
 * @return false otherwise
 */
bool DiGraphAdjList::hasEdge(int v1, int v2) const {
  // TODO: return true if edge v1-v2 is in the graph
  int s = v(); // number of vertices
  for(int i = 0; i < s; i++){
    if(v1 == adj(v2).get(i))
      return true;
  }
  return false;
}

/**
 * Add an edge to graph
 *
 * @param v1 id of the source node
 * @param v2 id of the target node
 */
void DiGraphAdjList::addEdge(int v1, int v2) {
  // TODO: record edge v1-v2 in adjList
  if(hasEdge(v1, v2) == false)
    adjList[v2].addLast(v1);
}

/**
 * Remove an edge
 *
 * @param v1 id of the source node
 * @param v2 id of the target node
 */
void DiGraphAdjList::delEdge(int v1, int v2) {
  // TODO: delete edge v1-v2 from graph
  if(hasEdge(v1, v2) == false){
    return;
  }else if(hasEdge(v1, v2)){
    int s = v();
    for(int i = 0; i < s; i++){
      if (adjList[v1].get(i) == v2)
        adjList[v1].remove(i);
    } 
  }
}
/**
 * Helper function for hasCycle
 *
 * @param g reference to the graph
 * @param v vertex id
 * @param marked int array indicating the number of visits for each vertex
 *
 * @return true if there are cycles
 * @return false otherwise
 */
bool DiGraphAdjList::hasCycleHelp(int v, int marked[]) const {
  marked[v] = 1;
  for(auto &v2 : adj(v)){
    if(marked[v2] == 0){
      if(hasCycleHelp(v2, marked))
        return true;
    }else if(marked[v2 == -1]){
      continue;
    }else if(marked[v2] == 1){
      return true;
    }
  }
  marked[v] = -1;
  return false;
}

/**
 * Check if the directed graph has cycles
 *
 * @return true if there are
 * @return false otherwise
 */
bool DiGraphAdjList::hasCycle() const {
  // TODO:
  int marked[] = { 0 };
  int s = e();
  for(int i = 0; i < s; i++){
    if(hasCycleHelp(V, marked))
      return true;
  }

  return false;
}

} // namespace ds