#include <bits/stdc++.h>
using namespace std;
//To check is it possible to make next move to the cell in maze
bool issafe_move(int row, int col, int **m, int r,int c, bool **is_visited){
if (row == -1 || row == r || col == -1 ||col == c || is_visited[row][col]|| m[row][col] == 1)
return false;

return true;
}
//To check all possible combination of path from current position to reach top right from bottom left
void check_it(int row, int col, int **m,  int r,int c, string& path, vector<string>& possible_paths,bool **is_visited,int **cost, vector<int>& possible_cost, int co)
{
//to check if cell is already visited
if (row == -1 || row == r || col == -1|| col == c || is_visited[row][col]|| m[row][col] == 1)
return;
//To check if we have reached the destination in maze
if (row == 0 && col == c-1)
{
possible_paths.push_back(path); //we store the final path we got in one vector to print
possible_cost.push_back(co); //we store the cost of the final path we got
return;
}
is_visited[row][col] = true; //mark current position as visited

if (issafe_move(row + 1, col, m, r,c, is_visited)) //check if we can move down
{
path.push_back('D');
co+=cost[row][col];
check_it(row + 1, col, m, r,c,path, possible_paths, is_visited,cost,possible_cost,co); //recursively call function to find path to reach destination
path.pop_back();  //we delete the last path and search for other possible path
co-=cost[row][col];
}
if (issafe_move(row, col - 1, m, r,c, is_visited)) //check if we can move left
{
path.push_back('L');
co+=cost[row][col];
check_it(row, col - 1, m, r,c,path, possible_paths, is_visited,cost,possible_cost,co);//recursively call function to find path to reach destination
path.pop_back();
co-=cost[row][col];
}
if (issafe_move(row, col + 1, m, r,c, is_visited)) //check if we can move right
{
path.push_back('R');
co+=cost[row][col];
check_it(row, col + 1, m, r,c,path, possible_paths, is_visited,cost,possible_cost,co); //recursively call function to find path to reach destination
path.pop_back();
co-=cost[row][col];
}

if (issafe_move(row - 1, col, m, r,c, is_visited)) //check if we can move up
{
path.push_back('U');
co+=cost[row][col];
check_it(row - 1, col, m, r,c,path, possible_paths, is_visited,cost,possible_cost,co);//recursively call function to find path to reach destination
path.pop_back();
co-=cost[row][col];
}

is_visited[row][col] = false;
}

void solve(int **m, int r,int c, int **cost)
{
vector<string> possible_paths;
vector<int> possible_cost;
int co=0;
string path;
//bool is_visited[n][n];
bool **is_visited=new bool *[r];
for(int i=0;i<r;i++)
is_visited[i]=new bool[c];
//memset(is_visited, false, sizeof(is_visited));
for(int i=0;i<r;i++)
for(int j=0;j<c;j++)
is_visited[i][j]=false;  //we initialize the is_visited array to false initially as it is not visited still

check_it(r-1, 0, m, r,c, path,possible_paths, is_visited,cost,possible_cost,co); //call function to find all possible path
if(possible_paths.size()==0) //check if there is no path
{
cout<<"\nOops Sorry,There is no path available to reach the destination !!:(";
}
else  //if multiple path exists
{
int minp=0;
cout<<"\nPaths available: "<<possible_paths.size()<<" \tcost "<<endl;
cout<<"---------------------------------------------\n";
for (int i = 0; i < possible_paths.size(); i++)
{
cout << possible_paths[i] << "\t\t\t "<<possible_cost[i]+cost[0][c-1]<<endl;
if(possible_cost[i]<possible_cost[minp])
{
minp=i;  //finding the index of path which has min cost
}
}
cout<<"\nPath with minimum cost is : ";
cout<<"("<<possible_paths[minp]<<") "<<possible_cost[minp]+cost[0][c-1];
string st=possible_paths[minp];
char s[r][c];
for(int i=0;i<r;i++)
for(int j=0;j<c;j++)  // To display the path containing min cost in seperate matrix
s[i][j]='*';
s[r-1][0]='@';
int j=r-1,k=0;
for(int i=0;i<st.size();i++){
if(st[i]=='U')
s[--j][k]='@';
else if(st[i]=='R')
s[j][++k]='@';
else if(st[i]=='L')
s[j][--k]='@';
else
s[j++][k]='@';
}
cout<<"\n\nPATH HAVING MIN. COST:\n";
for(int i=0;i<r;i++){
cout<<" ";
for(int j=0;j<c;j++){
cout<<s[i][j]<<"  ";}
cout<<endl;}
}
}
int main()
{
int i,j;
cout<<"Enter the number of rows and columns for maze :";
int r,c;
cin>>r>>c;  //input no.of rows and columns
int **m=new int *[r];
for(int i=0;i<r;i++)
m[i]=new int[c];
int **cost=new int *[r];
for(int i=0;i<r;i++)
cost[i]=new int[c];
//int m[n][n],cost[n][n];
cout<<"\nEnter the values of each cell in matrix in 0's and 1's:\n";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cin>>m[i][j];  //input the 1's and 0's of maze
}
}
cout<<"\nEnter cost for the maze :\n";
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
cin>>cost[i][j];   //input the cost of each cell
}
}

solve(m, r,c, cost); //solve
cout<<endl;
return 0;
}
