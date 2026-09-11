// m_robot.c by fire on Nov 1998
// this is used to record robot information
private int is_robot; // 0 no robot 1 robot
private int robot_test; // how many times tested
private int robot_times; // how many times as robot
string query_primary_id();
int query_literate();

void reset_robot()
{
is_robot = 0;
}


void set_robot(int r)
{
   string p_id;
   is_robot=r;
   robot_test++;
   if(is_robot)
      robot_times++;
   p_id=query_primary_id();
   CHAR_D->set_char(p_id,"literate",query_literate());


}
int query_robot()
{
  return is_robot;
}
int query_robot_test()
{  return robot_test;
}
int query_robot_times()
{   return robot_times;
}
int query_literate() {
   
   int tmp;
   tmp=robot_times-10;
   tmp=bmax(tmp,0);
   return bmax(0,robot_test-tmp*4);
}
string query_literate_str() {
   return CHENGHU_D->literate_str(query_literate());
}
int set_robot_time(int r) {
	robot_times=r;
	return robot_times;
}
int set_test_time(int r) {
	robot_test=r;
	return robot_test;
}
