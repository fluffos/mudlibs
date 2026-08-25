// the body of merchant
inherit PMODULES+"m_charnpc";
inherit __DIR__+"guy/guy_thought";
inherit __DIR__+"guy/guy_final";
private int life=600; //fake guy exist for 10 minutes

void clear_catch(string p_id) {
    CHAR_D->set_char(p_id,"catch_time",0);
    CHAR_D->set_char(p_id,"catch_file",0);
    CHAR_D->set_char(p_id,"catch_function",0);
    CHAR_D->set_char(p_id,"catch_para",0);

}

void setup()
{  
	//call_out("my_heart",5);
	add_question("recruit","recruit");
	add_question("followme","followme");
	add_question("getppl","getppl");
	add_ask_str("followme","$N对这群$T招了招手：小伙子们，在家闲者多没意思，\n"+
		"和我去吧，有吃有喝还可以杀人放火，多自在呀。\n");
	add_ask_str("recruit","$N对这群$T招了招手：小伙子们，在家闲者多没意思，\n"+
		"和我去吧当兵吧，有吃有喝还可以杀人放火，多自在呀。\n");
	add_ask_str("getppl","$N对这群$T招了招手：小伙子们，过来，过来。$S找你们有好事干。\n");
	call_out("my_heart",20);
}
string long()
{
  string p_id=this_object()->query_id()[1];
   return "一群"+p_id+
      "，正在一起议论什么。\n";
}
string query_title(string p_id,string c_id)
{  return "一群"+c_id+ "("+p_id+")";
}
void do_my_dispear()
{
	string p_id;
	object o;
	p_id=query_pure_leader(); // use query_pure_leader to avoid dead loop
	if(stringp(p_id)) {
		clear_catch(p_id);		
		o=find_user(p_id);
		if(objectp(o))
			o->modal_pop();
	}
	this_object()->simple_action
     ("一$N道：时候不早，大家都回去吧。\n");
   this_object()->simple_action
     ("众$N一散而去了。\n");
   remove();
}
void do_my_speak()
{  switch(random(5))
   {  case 0:
        this_object()->simple_action
          ("$N不知在议论什么，突然大笑起来。\n");
       break;
     case 1:
        this_object()->simple_action
          ("一名$N道：还是当兵最赚钱。\n");
        this_object()->simple_action
          ("众人点头称是。\n");
       break;
     case 2:
        this_object()->simple_action
          ("一名$N道：听说当兵后顿顿有肉吃。\n");
        this_object()->simple_action
          ("另一$N道：别傻了，前几天我见了几个老兵，个个饿得皮包骨头。\n");
       break;
     case 3:
        this_object()->simple_action
          ("一名$N道：其实在家待得也不安宁，还不如去打仗。\n");
        this_object()->simple_action
          ("众$N均感慨道：这世道。\n");
       break;
     default: 
        this_object()->simple_action
          ("一名$N道：当今圣上昏庸，奸臣当道，江山不保呀。\n");
        this_object()->simple_action
          ("另一$N嘘道：小声点，不要命啦。\n");
       break;
    }
}
void my_charaction()
{  int act;
   string p_id=query_leader();
   if(sizeof(p_id))
         return;
   act=random(5);
   switch(act)
   {    case 0:
//          if(random(100)==0)
//             do_my_dispear();
     
      case 1:
      	  return;
      case 2:
          do_my_speak();
          return;         
      case 3:
      	   return;
      default:
          do_my_moving();
   }
}
void my_heart()
{
	int tick = 20 + random(10);
	remove_call_out("my_heart");
	//printf("my heart is going on %d! life left %d\n",tick,life);
	if (this_object()->query("is_fake"))
	{
		life-=tick;
		if (life>0 || this_object()->query("is_locked")==1)
		{
		   my_charaction();
		   call_out("my_heart",20+random(10));
		}
		else
		{
		   if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^【飞鸽传书】密报："+
				"吾方间谍已被敌人识破，全体杀身成仁。%^RESET%^ \n");
		   do_my_dispear();
		}
	}
	else
	{			
		my_charaction();
		call_out("my_heart",20+random(10));
	}
		
}
void answer_followme(object who)
{
   mixed ret;
   string p_id=who->query_id()[0];

   write("%^H_RED%^对不起,召亲兵的功能暂时被关闭了！%^RESET%^\n");
   return;

   who->start_busy(2,"你正在说话呢！\n");
   this_object()->set("is_locked",1);
   ret=can_ask_for_join(p_id);
   if(ret!=1)
   {
     this_object()->targetted_action(ret,who);
	 check_leader();
     return;
   }
   set_act("followme");
   call_out("my_respond",1);
   
}
void answer_recruit(object who)
{
   mixed ret;
   string p_id=who->query_id()[0];
   who->start_busy(2,"你正在说话呢！\n");
   this_object()->set("is_locked",1);
   ret=can_ask_for_recruit(p_id);
   if(ret!=1)
   {
     this_object()->targetted_action(ret,who);
	 check_leader();
     return;
   }
   set_act("recruit");
   call_out("my_respond",1);
}

void answer_getppl(object who)
{
   mixed ret;
   string p_area,f_id,r_id;
   string p_id=who->query_id()[0];
   who->start_busy(2,"你正在说话呢！\n");
   this_object()->set("is_locked",1);
   ret=can_ask_for_getppl(p_id);
   if(ret!=1)
   {
     this_object()->targetted_action(ret,who);
	 check_leader();
     return;
   }
   set_act("getppl");
   p_area=who->query_job("getppl","p_area");
   f_id=who->query_job("getppl","f_id");
   r_id=who->query_job("getppl","r_id");
   this_object()->targetted_action("$N问$T道：什么好事。\n",who);
   who->targetted_action("$N道："+AREA_D->get_area(p_area,"name")+
	   "的"+BASE_D->get_base(f_id,"name")+ "要招一批"+
	   BASE_D->get_base(f_id,"workername")+"，跟我去吧，必然大有好处。\n",this_object());

   call_out("my_respond",1);

}

void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "followme" :
         answer_followme(who);
       return;
      case "recruit" :
         answer_recruit(who);
		 return;
      case "getppl" :
         answer_getppl(who);
	  return;
  }
}
int is_guy() {
	return 1;
}
// will not be clean_up
int query_clean_up() {
	return 1;
}
