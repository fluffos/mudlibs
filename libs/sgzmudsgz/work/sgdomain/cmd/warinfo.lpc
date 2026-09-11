// warinfo.c 
// by fire on Oct 7, 1998
// used for player to attack in the war
inherit M_ANSI;
string get_btype(int t)
{
   mixed mtmp;
   string ret="";
   mtmp=TROOP_D->get_troops(t,"soldier");
   mtmp=keys(mtmp);
   if(!sizeof(mtmp)) return "";
   foreach(string tp in mtmp)
   {
     string bt;
     bt=WARAI_D->get_soldier(tp,"name");
     bt=colour_truncate(bt,4);
     ret+=bt[0..1];
   }
   return ret;
}
string get_action(int t)
{
   mixed cmd;
   string chars;
   chars=TROOP_D->get_troops(t,"chars");
   foreach(string c in chars)
   {
      if(CHAR_D->get_char(c,"status")==STATUS_ONLINE)
            return "人控";
   }
   cmd=TROOP_D->get_troops(t,"command");
   if(!cmd) return "待命";
   if(!cmd["action"]) return "待命";
   switch(cmd["action"])
   {
      case "match": return "行军";
      case "guard": return "防守";
      case "pursue": return "追击";
      default : return "待命";
   }

}
string get_pos(int t)
{
   int* pos;
   string ps="ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ";
   string ret="";
   pos=TROOP_D->get_troops(t,"position");
   ret=ps[pos[0]*2..pos[0]*2+1];
   ret+=sprintf("%d",pos[1]+1);
   return ret;
}
void start(string arg)
{
        string p_id;
        string disp;
        int t_id;
        int* t_task;
        string m_side;
        int *tf,*te;
	string *def_party;

   object o;
   string p_name,id;
   string tmp;
   string c_id,c_name;
   int b_num;

   int can_see;


        p_id=this_body()->query_id()[0];
        if(!arg||arg=="")
          arg=p_id;
        if((arg!=p_id)&&(!wizardp(this_body())))
        {  write("只有巫师才可以查看他人的军事情报。\n");
           return;
        }
        t_task=TASK_D->get_char_task(arg);
        if((t_task[0]==-1)||((t_task[1]!=TASK_WAR)&&(t_task[1]!=TASK_TRAIN)))
        {  write("你并没处在战争中。  \n");
           return;
        }
	p_id=arg;
        t_id=t_task[0];
	def_party=TASK_D->get_task(t_id,"def_party");
	if(member_array(p_id,def_party)!=-1) m_side="d";
		else m_side="a";
//        m_side=TROOP_D->get_troop_side(TROOP_D->get_char_troop(p_id));
//        if(m_side="Ａ") m_side="a";
//        else m_side ="d";

        if(m_side=="a")
        {
           tf=TASK_D->get_task(t_id,"att_army");
           te=TASK_D->get_task(t_id,"def_army");
        }
        else
        {
           te=TASK_D->get_task(t_id,"att_army");
           tf=TASK_D->get_task(t_id,"def_army");
        }
        disp=
"我方部队　　　　　代号     主将　　 大将数　兵数　 兵种    位置　状态\n";
disp+=
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
if(sizeof(tf))
{
	foreach(int t in tf)
	{
   o=TROOP_D->find_troop(t);
   if(!objectp(o)) continue;
   p_name=TROOP_D->get_troops(t,"name");
   id=o->query_id()[0];
   c_id=TROOP_D->get_troops(t,"chars")[0];
   c_name=CHAR_D->get_char(c_id,"name");
   b_num=TROOP_D->get_troops(t,"total_num");
   tmp=sprintf("%-18s%-9s%-8s %-8d%-7d%-9s%-6s%s\n"
    ,p_name,id,c_name,
    sizeof(TROOP_D->get_troops(t,"chars")),
    b_num,get_btype(t),get_pos(t),
    get_action(t));
   disp+=tmp;
}
}
        disp+=
"敌方部队　　　　　代号     主将　　 大将数　兵数　 兵种    位置　状态\n";
disp+=
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
if(sizeof(te))
{
foreach(int t in te)
{
   o=TROOP_D->find_troop(t);
   if(!objectp(o)) continue;
   can_see=TROOP_D->get_troop_canbeseen(t);

   p_name=TROOP_D->get_troops(t,"name");
   id=o->query_id()[0];
   c_id=TROOP_D->get_troops(t,"chars")[0];
   c_name=CHAR_D->get_char(c_id,"name");
   b_num=TROOP_D->get_troops(t,"total_num");

   if(can_see)
	   tmp=sprintf("%-18s%-9s%-8s %-8d%-7d%-9s%-6s%s\n"
	    ,p_name,id,c_name,
	    sizeof(TROOP_D->get_troops(t,"chars")),
	    b_num,get_btype(t),get_pos(t),
	    get_action(t));
   else
	   tmp=sprintf("%-18s%-9s%-8s %8-8d%-7s%-9s%-6s%s\n"
	    ,p_name,id,c_name,
	    sizeof(TROOP_D->get_troops(t,"chars")),
	    "----","----","----",
	    "----");

   disp+=tmp;
} 
}
more(disp);       
}
