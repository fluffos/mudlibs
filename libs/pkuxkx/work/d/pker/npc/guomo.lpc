// 郭没

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
	set_name("郭没", ({ "guo mo","guo"}));
	set("str", 20);
	set("gender", "男性");
	set("age", 20);
	set("long", "襄阳守将,是郭靖的手下\n");
	set("combat_exp", 25000);
        set("neili",351);
        set("max_neili",351);
	set("attitude", "friendly");
	set("shen_type",-1);
set("score",5000);
setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        
}
  

void init()
{
  add_action("get_msg","msg");
  add_action("get_kill","kill");
  add_action("get_kill","hit");
  add_action("get_kill","fight");
}

int get_msg()
{
   object me=this_player();
   object death,where;
   string deathname;
   if(!me->query("pker")||me->query("spyname")!="襄阳郭没"||!me->query("deathname"))
   {
   return 0;
   }
   deathname=me->query("deathname");
   if(!death=find_player(deathname))
    {  
      message("vision",HIR"郭没告诉你：你要杀的人现在不在线上!\n"NOR,me);
      return 1;
    }
   where = environment(death);
   if (!where) return notify_fail("这个人不知道在哪里...\n");
   printf("%s(%s)现在在%s.\n",
		(string)death->name(),
		(string)death->query("id"),
		(string)where->query("short"),
		);
   write("\n\n\n");
   printf("%s\n",(string)where->query("long"));
   return 1;
}


  
int get_kill(string arg)
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if((arg=="guo mo"||arg=="guo")&&me->query("combat_exp")<2000000)
   {
     write("郭没嘿嘿一笑：你突然看到一把长剑已经架到了你的脖子上!\n");
     me->unconcious();
     return 1;
   }
   return 0;
}





  



