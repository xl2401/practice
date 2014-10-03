/* there are many jobs. Every job will depend on some jobs. For example, a depends on b, c ,d. d depends on c, e and so on. Output the jobs so that jobs depended on should be in front of jobs depending on them.
 *
 * Actually, it is a topological sort problem.
 *
 * We use DFS to solve the problem. But be careful we must take care if there is a circle in the graph .
 *
 * Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
 *
 *
 * The reference : http://www.geeksforgeeks.org/topological-sorting/
 *
 * Another reference should be chenxi's lecture DFS and Topological Sort
 *: 
    http://alg12.wikischolars.columbia.edu/file/view/DEPTHFIRST.pdf/316876270/DEPTHFIRST.pdf
 *
 */

#include<iostream>
#include<unordered_map>
#include<list>
#include<unordered_set>
using namespace std;

class Solution
{
    public:
        bool DFS(unordered_map<char, list<char> > &taskgraph, char i, list<char> &task, unordered_set<char> path, unordered_set<char> &visited)
        {
            visited.insert(i);
            path.insert(i);
            for(auto it = taskgraph[i].begin(); it!=taskgraph[i].end(); it++)
            {
                if(visited.find(*it)==visited.end())
                {
                    if(!DFS(taskgraph, *it,task,path,visited))
                        return false;
                }
                else
                {
                    if(path.find(*it)!=path.end())
                        return false;
                }
            }
            task.push_back(i);
            return true;
        }
        bool sort_task(unordered_map<char,list<char> > taskgraph, list<char> & task)
        {
            unordered_set<char> visited;
            for(auto it = taskgraph.begin(); it!= taskgraph.end(); it++)
            {
                unordered_set<char> path;
                if(visited.find(it->first)==visited.end())
                {
                    //check if there is circle in directed graph
                    if(!DFS(taskgraph,it->first,task,path,visited))
                        return false;
                }
            }
        }
        void insert(char key, char value)
        {
            taskgraph[key].push_back(value);
        }
    private:
        unordered_map<char,list<char> > taskgraph;
};

int main()
{

}
