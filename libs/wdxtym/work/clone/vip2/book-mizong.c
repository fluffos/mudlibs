#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"密宗经书"NOR, ({ "mzjishu"}));
	set("long","这是一本"HIG"密宗经书"NOR"，使用限制为0到360"ZJURL("cmds:kan mzjishu")+ZJSIZE(28)+"研究"NOR"。\n");
	set("unit","本");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","密宗经书");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="mzjishu")
  	return notify_fail("你要看什么?\n");
      		
 if(me->query_skill("lamaism") < 0)
			return notify_fail("你对密宗的认知太少了 。\n");
 
 if(me->query_skill("lamaism") > 359)
			return notify_fail("密宗经书已经帮不了 。\n");

  me->set_skill("lamaism", me->query_skill("lamaism",1) + 25);

	write(HIY"你研究"HIG"密宗经书"HIY"刷新了自己对密宗的认知!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }