// sample puren.c code
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("天星的女仆", ({"puren", "ren", "nv pu"}));
	set("gender", "女性");
	set("age", 18);
	set("long", HIY
		"这是一位天星的女仆。\n她看上去花容月貌，如天仙下凡，让人一看就心动不已。\n"NOR);
	
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	
                               
  	set("inquiry", ([
		"天星大侠" : "天星大侠是个级好的人，他专门负责制作一些武器和npc，要是有事找他就post留言，或者在星期六的晚上来这吧！\n",
		"天星" : "什么！！！你居然敢直呼天星大侠的姓名，你不想活了吧！！\n",
                     ]));
		
        set("force", 10000);
        set("neili",1000);
        set("max_neili",1000);
        set("max_qi",1000);
        set("qi",1000);
	set("max_force", 10000);
	set("force_factor", 50);
	
	set("combat_exp", 2000000);
	set("score", 500000);
	
	
	
	setup();
}
	
	

void init()
{
   add_action("do_ask","帮我K");
}
int do_ask(string arg)
{
 int i;
      object *obs;
      object ob,where;
      object me=this_player();
    if (me->query("id")!="super") 
{
 command("say 你居然敢假冒天星大侠，不想活了吧，看来小女子非教训教训你不可了！");
remove_call_out("kill_ob");
call_out("kill_ob", 1, me);
}
  if (!arg) return notify_fail("你想让我帮你K谁？\n");
   ob=present(lower_case(arg), environment(this_player()));
if (arg = "super") return notify_fail("不行，不行，我不敢打你的！\n");
if (!ob) return notify_fail("没有这个人耶！\n");
   for(i=0; i<sizeof(ob); i++) {
where = environment(obs[i]);
this_object()->move(file_name(where));
remove_call_out("kill_ob");
call_out("kill_ob",1,ob);
}
}
