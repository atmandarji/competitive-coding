// https://leetcode.com/problems/24-game/
class MyNum{
public:
    int num,dnum;
    MyNum(int num, int dnum){
        this->num=num;
        this->dnum=dnum;
    }
    MyNum operator +(MyNum &number){
        MyNum ans(this->num*number.dnum + this->dnum*number.num,
                  this->dnum*number.dnum);
        return ans;
    }
    MyNum operator -(MyNum &number){
        MyNum ans(this->num*number.dnum - this->dnum*number.num,
                  this->dnum*number.dnum);
        return ans;
    }
     MyNum operator *(MyNum &number){
        MyNum ans(this->num*number.num,
                  this->dnum*number.dnum);
        return ans;
    }
    MyNum operator /(MyNum &number){
        MyNum ans(this->num*number.dnum,
                  this->dnum*number.num);
        return ans;
    }
    double val(){
        return (num+0.0)/(dnum+0.0);
    }
};

class Solution {
public:
    bool is_possible(vector<MyNum> &nums, int target){
        if(nums.size()==1){
            if(nums[0].val()==target) return true;
            return false;
        }
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                MyNum p_num = nums[i]+nums[j];
                MyNum m_num = nums[i]-nums[j];
                MyNum rm_num = nums[j]-nums[i];
                MyNum mul_num = nums[i]*nums[j];
                MyNum d_num = nums[i]/nums[j];
                MyNum rd_num = nums[j]/nums[i];
                
                vector<MyNum> next_nums, nums_to_check;
                for(int k=0;k<nums.size();k++)
                    if(k!=i && k!=j) next_nums.push_back(nums[k]);
                nums_to_check = next_nums;
                nums_to_check.push_back(p_num);
                if(is_possible(nums_to_check, target)) return true;
                
                nums_to_check = next_nums;
                nums_to_check.push_back(m_num);
                if(is_possible(nums_to_check, target)) return true;
                
                nums_to_check = next_nums;
                nums_to_check.push_back(rm_num);
                if(is_possible(nums_to_check, target)) return true;
                
                nums_to_check = next_nums;
                nums_to_check.push_back(mul_num);
                if(is_possible(nums_to_check, target)) return true;
                
                nums_to_check = next_nums;
                nums_to_check.push_back(d_num);
                if(is_possible(nums_to_check, target)) return true;
                
                nums_to_check = next_nums;
                nums_to_check.push_back(rd_num);
                if(is_possible(nums_to_check, target)) return true;
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<MyNum> numbers;
        for(int i=0;i<nums.size();i++){
            MyNum t_num(nums[i],1);
            numbers.push_back(t_num);
        }
        return is_possible(numbers, 24);
    }
};
