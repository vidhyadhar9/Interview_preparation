

/*You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.
*/



int leastInterval(vector<char>& tasks, int n) {
    vector<int>v(26,0);
    int count=0;
    for(int i=0;i<tasks.size();i++){
        v[tasks[i]-'A']++;
        count=max(count, v[tasks[i]-'A']);
    }
    int sameFreq=0;
    for(int i=0;i<26;i++){
        if(count==v[i])sameFreq++;
    }
    sameFreq-=1;
    int intervals=count-1;
    int slots =intervals*n;
    int total=tasks.size();
    total=total -count-sameFreq*count;
    int remaining = slots-sameFreq*(intervals)-(total);
    if(remaining<=0)return tasks.size();
    else 
    return tasks.size()+remaining;
}


/*Approach:
calculate the maximum frequent element because the we can arrange the remianing elements with in that element
since  max element frequenet has lot of chances to create ideal time so if we use that ideal time to place otehr elements we can reduce other ideal timings
count the ideal times created and place the otehr items in that ideal timing and count the remaining iodeal times if the elemts are suffcient \
enough to place in those ideal timings then ans could be the size of the array and 
if the elements are not full filling the all ideal timings then count those ideal timings and add to the tasks length whcih could 
be the overall time taken to complete those all tasks
*/