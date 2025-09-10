/*
Intuition
Here we will apply greedy approach

Approach
In the question given that
If there exists a solution, it is guaranteed to be unique
-This lines clearly tells us that we have unique or no solution exists

Here two cases are possible

if our total_gas is less than our total cost in that case we can't complete our journey ,so will return -1
Now we have a unique solution that means single starting_point exists
To find that point we will keep track of my current_gas+=gas[i]-cost[i]
lets suppose at any index our current gas became negative so we can clearly say that till that index all the gas station between ith and starting point are bad, starting point as well.
So, this means we can start trying at next gas_station on the i+1 station
*/class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int t_gas = 0, t_cost = 0, c_gas = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            t_gas += gas[i];//these two variable are to check if no case is possible
            t_cost += cost[i];

            c_gas += gas[i] - cost[i];//for checking the total present gas at index i
            if (c_gas<0)
            {
                start = i + 1; //there is a breakdown....so we will start from next point or index

                c_gas = 0;   //reset our fuel 

            }
            
        }
        if (t_gas<t_cost)
        {
            return -1;
        }
        else
        {
            return start;
        }
        
    }
};