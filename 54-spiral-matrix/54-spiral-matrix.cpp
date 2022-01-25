class Solution {
  class Node{
    public:
    int i,j,k;
    Node(int i, int j, int k){
      this->i=i;
      this->j=j;
      this->k=k;
    }
  };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      /*
      0 -> right
      1 -> down
      2 -> left
      3 -> up
      */
      deque<Node> q;
      int visited = -101;

      q.push_back(Node(0,0,0));

      auto isValid = [&](int i, int j){
        if(i >= 0 && i < matrix.size()
          && j >=0 && j < matrix[0].size()
          && matrix[i][j] != visited)
          return true;
        else return false;
        
      };
      vector<int> res;
      vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
      while(!q.empty()){
        Node frnt = q.front();
        q.pop_front();
        int x = frnt.i,y=frnt.j;
        res.push_back(matrix[x][y]);
        matrix[x][y] = visited;
        int k = frnt.k;
    
        if(isValid(x+moves[k][0],y+moves[k][1])){
          q.push_back(Node(x+moves[k][0],y+moves[k][1],k));
        } else {
          k = (k+1)%4;
          if(isValid(x+moves[k][0],y+moves[k][1]))
            q.push_back(Node(x+moves[k][0],y+moves[k][1],k));
        }
      }
      
      return res;
    }
};