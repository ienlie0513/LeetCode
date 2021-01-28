int searchInsert(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize-1;
    
    while(true){
        if(target == nums[(head+tail)/2])
            return (head+tail)/2;
        if(head == tail){
            if(target > nums[head])
                return head+1;
            else
                return head;
        }
        if(target > nums[(head+tail)/2])
            head = (head+tail)/2+1;
        else
            tail = (head+tail)/2;
    }
    
    return 0;
}
