// ev_ldapp.c 
// by fire on July 23, 1998
// this is the event for area leader appear regular
void app(string a_id)
{
   string c_id;
   
//   tell_user("fire",a_id+"\n");
   if(!AREA_D->get_area(a_id,"meeting")) return;
   c_id=AREA_D->get_area(a_id,"leader");
   if(!c_id) return;
   if(CHAR_D->get_char(c_id,"status")==STATUS_ONLINE) return;     //如果是玩家在线，就退出
   if(CHAR_D->get_char(c_id,"task")!=TASK_NONE) return;
   CHAR_D->appear(c_id,a_id,"meeting");

}
void leader_appear() // this is used for the leader to come every day
{
    string *list;
    int i;
    list=AREA_D->list_areas();
    i=0;
    foreach(string p_id in list)
    {
		call_out("app",i,p_id);
		if(random(5)==0)
			i++;
    }
}
