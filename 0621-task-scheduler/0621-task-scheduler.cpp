class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char ch:tasks){
            freq[ch]++;
        }

        priority_queue<int> pq;

        for(auto it: freq){
            pq.push(it.second);
        }

        int time =0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();

                    f--;
                    if(f>0){
                        temp.push_back(f);
                    }
                    time++;
                }
                else{
                    if(temp.empty()){
                        break;
                    }
                    time++;
                }
            }

            for(int i:temp){
                pq.push(i);
            }
        }
        return time;
    }
};