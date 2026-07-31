#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"禅宗经书"NOR, ({ "czjsshu"}));
	set("long","这是一本"HIG"禅宗经书"NOR"，使用限制为0到360"ZJURL("cmds:kan czjsshu")+ZJSIZE(28)+"研究"NOR"。\n");
	set("unit","本");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","禅宗经书");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="czjsshu")
  	return notify_fail("你要看什么?\n");
      		
 if(me->query_skill("buddhism") < 0)
			return notify_fail("你对禅宗的认知太少了 。\n");
 
 if(me->query_skill("buddhism") > 359)
			return notify_fail("禅宗经书已经帮不了 。\n");

  me->set_skill("buddhism", me->query_skill("buddhism",1) + 25);

	write(HIY"你研究"HIG"禅宗经书"HIY"刷新了自己对禅宗的认知!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }