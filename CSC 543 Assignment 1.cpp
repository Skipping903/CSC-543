#include <iostream>
#include<string>
#include<sstream>
using namespace std;

class INDICES
{
public:
    static int * findSum(int nums[], int target)
    {
        for (int i = 0; i < sizeof(nums); i++)
        {
            for (int j = 1; j < sizeof(nums) + 1; j++) 
            {
                int sum = nums[i] + nums[j];

                if (target == sum)
                {
                    /*
                    Was having a lot of issues trying to figure out how to return the index of the value.
                    This is what I found after scouring the internet for solutions.
                    Found here: https://stackoverflow.com/questions/3909784/how-do-i-find-a-particular-value-in-an-array-and-return-its-index
                    */
                    int ans[2] = { distance(nums, find(nums, nums + sizeof(nums), nums[i])), distance(nums, find(nums, nums + sizeof(nums), nums[j])) };

                    return ans;
                }
            }
        }
    }
};

int main()
{
    //sample data
    int nums[] = { 2, 15, 11, 7 };
    int target = 9;

    string answer = "[", conv1, conv2;
    stringstream ss1, ss2;
    
    //Was having problems figuring out how to convert the output to strings, ended up using a class called sstream as the solution.
    //It should also be mentioned that since the information specified that there is only one solution I hardcoded the index location of the returned array.
    ss1 << INDICES::findSum(nums, target)[0];
    ss1 >> conv1;
    ss2 << INDICES::findSum(nums, target)[1];
    ss2 >> conv2;

    answer += conv1 + ',' + conv2 + ']';
    
    std::cout << answer;

    return 0;
}