//大白熊
//by steel
#include "ansi.h"
inherit NPC;

void create()
{
  set_name("大白熊",({"bear","bigbear"}));
  set("race","野兽");
  set("age", 5);
  set("long","这是一头憨憨的大白熊。毛色看来很好！\n");
  set("attitude","aggressive");
    set("max_qi",518860);
  set("qi",518860);
  set("max_neili",518860);
  set("neili",518860);
  set("max_jing",518860);
  set("jing",518860);
  set("str",60);
  set("cor",30);
 
  set("limbs",({ "头部", "身体", "腿部", "臀部","前胸",}) );
  set("verbs",({"bite"}) );
  set("combat_exp",9950000);
  set_temp("apply/attack", 200);
  set_temp("apply/damage", 2000);
  set_temp("apply/armor", 2000);
  set_temp("apply/defence",200);  
  setup();
}

void init()
{  
    add_action("do_name","pou");
}

int do_name(string arg)
{
   object me,obj,heart;
   string str;
   me=this_player();
   obj=this_object();
   if(!living(obj)) 
   {
    message_vision(HIW"$N连尸体都不放过,你还是人吗?\n"NOR,me); 
    return 0;            
   }  
   if(!arg||arg=="") return notify_fail("你想剖开甚么？\n");
   sscanf(arg,"%s",str);
   if(str!="bear")   return notify_fail("这里没有这东东!\n");
   if(!obj->query_temp("yun"))
   {
    message_vision(HIW"$N没看它还是活蹦乱跳的吗？\n"NOR,me); 
    return 1;                                     
   }
  else
  {
   heart=new("/d/feihu/obj/bearheart");
   heart->set_amount(1);
   message_vision(HIR"$N看着这头呆呆的熊，举起大刀向它胸部砍去...\n"NOR,
   me);
   heart->move(this_player());
   message_vision(HIY"$N得到了一颗熊心!!"NOR,me);
   obj->delete_temp("yun");     
   obj->die();
   return 1;
   }
}

void unconcious()
{
        this_object()->remove_all_enemy();
        message("system", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,
		this_object());
	write(HIR"\n大白熊快不行了,快动手!!\n"NOR);
	set("jing", 0);
	set("qi", 0);
	
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
        this_object()->set_temp("yun",1); 
}

varargs void revive()
{
  ::revive();
  this_object()->set_temp("yun",0);
} 
