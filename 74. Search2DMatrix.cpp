// class Solution {
//     bool BinarySearch(vector<int> v, int target)
//     {
//         int l = 0, r = v.size();
//         while(l< v.size() && l<r)
//         {
//             int mid = l + (r-l)/2;
//             if (v[mid] == target)
//                 return true;
//             else if (v[mid] < target)  //search right of mid
//                 l = mid+1;
//             else r = mid;
//         }
//         return false;
//     }
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty()) return false;
        
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         int i = 0, j = m;
//         //which row: compare target with matrix[i][n-1]
//         while(i < m && i<j-1)
//         {
//             int mid = i + (j-i)/2;
//             if (matrix[mid][0] > target) j = mid;
//             else i = mid;
//         }
//         //if (i == m) return false;
        
//         return BinarySearch(matrix[i], target);
        
//     }
// };


 class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m=matrix.size();
            if(!m)  return false;
            int n=matrix[0].size();
            /*** binary-search the line-index ***/
            int start=0, end=m, mid;
            /*** [start, end) ***/
            while(end-start > 1){
                mid=(start+end)/2;
                if(matrix[mid][0]<=target)  start=mid;
                else if(matrix[mid][0]>target)  end=mid;
            }
            int row=start;
            cout<<"row:"<<row<<endl;
            /*** binary-search the line-index ***/
            start=0;
            end=n;
            /*** [start, end) ***/
            while(end-start > 1){
                mid=(start+end)/2;
                if(matrix[row][mid]<=target)  start=mid;
                else if(matrix[row][mid]>target)  end=mid;
            }
            return matrix[row][start]==target;
        }
    };