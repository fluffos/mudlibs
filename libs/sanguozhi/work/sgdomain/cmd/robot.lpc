// robot.c used for player to check the robot test result
// by fire on November , 1998
void start(string arg)
{
  object o_id;
  int is_robot; // 0 no robot 1 robot
  int robot_test; // how many times tested
  int robot_times; // how many times as robot  if((arg=="")||(!arg))
  if((!arg)||(arg==""))
     o_id=this_body();
  else
  {
     if(!wizardp(this_body()))
     {
        write("只有巫师才可检查他人的工作情况。\n");
        return;
     }
     o_id=find_body(arg);
     if(!objectp(o_id))
     {
        write("查无此人。\n");
        return;
     }
  }
  is_robot=o_id->query_robot();
  robot_test=o_id->query_robot_test(); // how many times tested
  robot_times=o_id->query_robot_times(); // how many times as robot  if((arg=="")||(!arg))
  
  write("智能测试：　测试总次数　　失败次数　　上次测试结果\n");
  write("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
write(sprintf("            %-14s%-12s%-10s\n",chinese_number(robot_test)+"次",
chinese_number(robot_times)+"次",(is_robot == 1 ? "弱　智" : "正  常")));
}
