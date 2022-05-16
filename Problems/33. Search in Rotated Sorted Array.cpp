#include<vector>
#include<iostream>


using namespace std;


class Solution {
    public:

        int binarySearch(vector<int>& nums, int target, int left, int right) {

            if(right>=left){

                int mid = left + (right - left) /2;

                cout << endl;
                cout << "mid: " << mid << " val: " << nums[mid] << " target: " << target << endl;
                cout << "Right: " << right << " And Left: " << left << endl;
                cout << endl;


                if(nums[mid]==target){
                    return mid;
                }


                if(target>nums[mid]){

                    if(target > nums[mid]){
                        return binarySearch(nums,target,mid+1,right);
                    }
                    else{
                        return binarySearch(nums,target,left,mid-1);
                    }

                    // if(target > nums[right]){
                    //     return binarySearch(nums,target,left,mid-1);
                    // }
                    // else{   
                    //     return binarySearch(nums,target,mid+1,right);
                    // }
                }
                if(target<nums[mid]){

                    if(target < nums[left]){
                        return binarySearch(nums,target,mid+1,right);
                    }
                    else{
                        return binarySearch(nums,target,left,mid-1);
                    }
                }


            }

            return -1;
        }
        

        int search(vector<int>& nums, int target) {
            return binarySearch(nums,target,0,nums.size()-1);
        }
};


void printVector(vector<int> nums){
    cout << " ";
    for(int i=0;i<nums.size();i++){
        cout << " " << nums[i] << " ";
    }
    cout << endl;
}

int main(){

    Solution solution;

    vector<int> input = {4,5,6,7,8,1,2,3};


    printVector(input);


    int answer = solution.search(input,8);

    cout << "Answer: " << answer << endl;

}