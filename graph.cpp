#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;
class edge
{
public:
    int destinationvertexid, weight;
    edge()
    {
        destinationvertexid = 0;
        weight = 0;
    }

    edge(int d, int w)
    {
        destinationvertexid = d;
        weight = w;
    }
    void setdestinationvertexid(int d)
    {
        destinationvertexid = d;
    }
    void setweight(int w)
    {
        weight = w;
    }
    int getdestinationvertexid()
    {
        return destinationvertexid;
    }
    int getweight()
    {
        return weight;
    }
};
class vertex
{
public:
    int stateid;
    string statename;
    list<edge> edgeList;
    int indegree=0;
    int outdegree=0;
    vertex()
    {
        stateid = 0;
        statename = "";
    }
    vertex(int SI, string SN)
    {
        stateid = SI;
        statename = SN;
    }
    void setstateid(int SI)
    {
        stateid = SI;
    }
    void setstatename(string SN)
    {
        statename = SN;
    }
    int getstateid()
    {
        return stateid;
    }
    string getstatename()
    {
        return statename;
    }

    list<edge> getEdgeList()
    {
        return edgeList;
    }

    void print_edge_list(){
        cout<<"[";
        for (auto it = edgeList.begin(); it!=edgeList.end(); it++)
        {
            cout<<it->getdestinationvertexid()<<"("<<it->getweight()<<")"<<endl;
        }
        cout<<"]"<<endl;
        
    }
};
class graph
{
public:
    vector<vertex> vertices; 

    bool checkvertexbyid(int id)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getstateid() == id)
            {
                return true;
            }
        }
        return false;
    }
    void AddVertex(vertex v)
    {
        bool check = checkvertexbyid(v.getstateid());
        if (check == true)
        {
            cout << "Already exists" << endl;
        }
        else
        {
            vertices.push_back(v);
            cout << "vertex added in graph \n";
        }
    }

    vertex getvertexbyid(int v_id)
    {
        vertex temp;
        for (int i = 0; i < vertices.size(); i++)
        {
            temp = vertices.at(i);
            if (temp.getstateid() == v_id)
            {
                return temp;
            }
        }
        return temp;
    }

    bool checkedgeById(int fromVertex, int ToVertex)
    {
        vertex v = getvertexbyid(fromVertex);
        list<edge> e;
        e = v.getEdgeList();
        for (auto it = e.begin(); it != e.end(); it++)
        {
            if (it->getdestinationvertexid() == ToVertex)
            {
                return true;
            }
        }
        return false;
    }

    void AddEdge(int fromver, int tover, int w){
        bool check1 = checkvertexbyid(fromver);
        bool check2 = checkvertexbyid(tover);

        if((check1 && check2) == true){
            bool check3 = checkedgeById(fromver, tover);
            if(check3==true){
                cout<<"edge already exists"<<endl;
            }
            else{
                for (int i = 0; i < vertices.size(); i++)
                {
                    if(vertices.at(i).getstateid()==fromver){
                        edge e(tover,w);
                        vertices.at(i).edgeList.push_back(e);
                        vertices.at(i).outdegree+=1;
                    }
                    else if (vertices.at(i).getstateid()==tover) 
                    {
                        edge e(fromver,w);
                        vertices.at(i).edgeList.push_back(e);
                        vertices.at(i).indegree+=1;
                    }
                    
                }
                
            }
        }
        else{
            cout<<"Vertices not found \n";
        }
    }

    void print_in_degree(){
        for (int i = 0; i < vertices.size(); i++)
        {
            cout<<"In degree of state id "<<vertices.at(i).getstatename()<<" is "<<vertices.at(i).indegree<<endl;
        }
               
     
    }

    void print_out_degree(){
        for (int i = 0; i < vertices.size(); i++)
        {
            cout<<"Out degree of state id "<<vertices.at(i).getstatename()<<" is "<<vertices.at(i).outdegree<<endl;
        }               
     
    }
    void print_graph(){
        for (int i = 0; i < vertices.size(); i++)
        {
            vertex temp;
            temp=vertices.at(i);
            cout<<temp.getstatename()<<"("<<temp.getstateid()<<")"<<"-->";
            temp.print_edge_list();
        }
        
    }



};
int main()
{
    int option,id,id2,w;
    string name;
    graph g;
    vertex v1;

    do
    {
        cout<<"------------------------------------------------"<<endl;
        cout<<"select what operation you want to perform"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        cout<<"0-to exit "<<endl;
        cout<<"1-addVertex()"<<endl;
        cout<<"2- addEdgeById() "<<endl;
        cout<<"3-printInDegree()"<<endl;
        cout<<"4-printOutDegree()"<<endl;
        cout<<"5-printGraph()"<<endl;
    

        cin>>option;

        switch (option)
        {

        case 1:
            cout<<"add vertex operation"<<endl;
            cout<<"enter state id "<<endl;
            cin>>id;

            cout<<"enter state name "<<endl;
            cin>>name;

            v1.setstateid(id);
            v1.setstatename(name);
            g.AddVertex(v1);

            break;
        
        case 2:
            cout<<"add edge operation "<<endl;
            cout<<"enter id of source vertex(state)"<<endl;
            cin>>id;

            cout<<"enter id of destination vertex(state)"<<endl;
            cin>>id2;

            cout<<"enter weight "<<endl;
            cin>>w;
            g.AddEdge(id,id2,w);
            break;

        case 3:
            g.print_in_degree();
            break;

        case 4:
            g.print_out_degree();
            break;

        case 5:
            g.print_graph();
            break;

     
        default:
            break;
        }
    } while (option !=0);

    return 0;
}