class Solution {
    
    void flood(vector<vector<int>>& image,int sr,int sc,int &newColor,int &precolor,int n,int m)
    {
        //base case
        if(sr<0 || sc<0 || sr>=n || sc >=m || image[sr][sc]!=precolor || image[sr][sc]==newColor)
            return;
        
        image[sr][sc] = newColor;
        
        flood(image,sr,sc-1,newColor,precolor,n,m);
        flood(image,sr+1,sc,newColor,precolor,n,m);
        flood(image,sr,sc+1,newColor,precolor,n,m);
        flood(image,sr-1,sc,newColor,precolor,n,m);
        return;
      
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int precolor = image[sr][sc];
        flood(image,sr,sc,newColor,precolor,n,m);
        
        return image;
        
    }
};
