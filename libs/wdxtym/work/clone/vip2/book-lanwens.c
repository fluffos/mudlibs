#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"梵文经书"NOR, ({ "lanwens"}));
	set("long","这是一本"HIG"梵文经书"NOR"，使用限制为0到360"ZJURL("cmds:kan lanwens")+ZJSIZE(28)+"研究"NOR"。\n");
	set("unit","本");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","梵文经书");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="lanwens")
  	return notify_fail("你要看什么?\n");
      		
 if(me->query_skill("sanscrit") < 0)
			return notify_fail("你对梵文的认知太少了 。\n");
 
 if(me->query_skill("sanscrit") > 359)
			return notify_fail("梵文经书已经帮不了 。\n");

  me->set_skill("sanscrit", me->query_skill("sanscrit",1) + 25);

	write(HIY"你研究"HIG"梵文经书"HIY"刷新了自己对梵文的认知!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }