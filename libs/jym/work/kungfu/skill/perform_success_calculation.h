// Function usage:
// 1 arg: the skill level/exp of the performer you want to compare
// 2 arg: the skill level/exp of the target you want to compare
// 3 arg: basic success rate if arg1 == arg2, 50%, put 0.5, 75%, put 0.75
// 4 arg: arg1 >= arg2 or arg1 < arg2, + or - how many percent on success rate, if you want 10%, put 0.1, 20% put 0.2 and so on
// 5 arg: in how many % different in skills level/exp, success rate start to take effect
// if you want 10%, put 0.1, if you want 20%, put 0.2 and so on
// Example:
// Get_Success_Rate(100, 100, 0.75, 0.1, 0.1);
// example above is my skill is 100, target skill is 100, and my perform have 75% to success when we have equal skill level
// if I have 10% skill level higher than target, i get 10% more on perform success rate
// if I have 10% skill level less than target, i get 10% less on perform sucess rate
int Get_Success_Rate(float f_My_Level, float f_Target_Level, float f_Basic_Success_Rate, float f_Add_Success_Rate, float f_Skill_Level_Diff);