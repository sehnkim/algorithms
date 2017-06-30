#include <iostream>
using namespace std;

// Calculating how many units of water can be contained..


[1, 0, 1, 0, 2] ==> 2

   
   #*#*#
   #*#*###
 # #*#*###
##########
0123456789    kv = {0:0, 1:2, 2:0,...} -> sort(kv, value)
   
   #
   # #
 # # #
######
012789    
   
   #
 #*#
####
0129   
   
    
==> [3, 3, 3, 2, 1, 0, 0, 0, 0]



0) arr = [0, 1, 0, 3, 0, 3, 0, 3, 0, 2]
1) # store (index, value) pair        ==> O(NlogN)
2) # sortedArr = sortByVal(arr)
3) # find 1st and 2nd items        
    3.1) # find if same vals exist
    3.2)    # find max, min indice and select
4) # compute x
5) # compute y
6) # compute x*y - sum(x1:x2) --> return units  ==> O(N)
7) # sortedArr.pop(x1~x2)  ==> O(N)
8) # sortedArr.pop(max(x1,x2))
9) # if len(sortedArr) > 1: goto 3)
     else: end

a = [0, 2, 7, 3, 8, 0, 2, 3]

int CalcWaterUnits(std::vector<int> a)
{
    sort(a.begin(), a.end(), xxx)
}


int main() {
    cout<<"Hello";
    return 0;
}



/*
# 
# Your last C/C++ code is saved below:
# 
# 
# 
# Calculating how many units of water can be contained..
#     
# 
#     
# {
#     
# }
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# #include <iostream>
# using namespace std;
# 
# int main() {
#     cout<<"Hello";
#     return 0;
#     int label = 0;
#     
#      for (int i=0; i<height; ++i) {
#         for (int j=0; j<width; ++j) {
#             if (image[i][j] == 1) {
#                 // check 4 directions. 
#                 ConnectedComp(i,j, image)   ;            
#             }
#             
#         }
#     }
#         
#     //connected component labling
#     
# }
# 
# 01111000000100100
# 11100000000100100
# 00100100000111100 
# 00100100000000000
#     
#     
# 01000000000300400
# 11100000000300400
# 00100200000044400 
# 00100200000000000    
# 
# void ConnectedComp(int i, int j uchar** image, int label)
# {
#     // Base condition.
#     if (image[i][j] == 0) 
#         return;
#     
#     
#     // for the image, try to find the first-encounting 
#     if (image[i-1][j] == 1 )
#         ConnectedComp(i-1, j, image);
#     
#     if (image[i-1][j] == 1 )
#         ConnectedComp(i+1, j, image);
#     
#     
#     ConnectedComp(i, j-1, image);
#     ConnectedComp(i, j+1, image); 
#    
# 
# }
# 
# 
# // 0, 1 : binary
# up, down, left, right
# how many objs in the image.
# labeling each object.
#     */
