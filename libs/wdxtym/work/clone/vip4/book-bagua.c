#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"八卦奇书"NOR, ({ "bagua"}));
	set("long","这是一本"HIG"八卦奇书"NOR"，使用限制为250到360"ZJURL("cmds:kan bagua")+ZJSIZE(28)+"研究"NOR"。\n");
	set("unit","本");
	set_weight(100);
	set("value",30000);
	set("yuanbao",50);	
    set("no_steal",1);
	set("desc","八卦奇书");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="bagua")
  	return notify_fail("你要看什么?\n");
      		
 if(me->query_skill("count") < 120)
			return notify_fail("你对阴阳八卦的认知太少了 。\n");
 
 if(me->query_skill("count") > me->query_skill("mathematics"))
			return notify_fail("你对算术的认知太少了 。\n");
			
 if(me->query_skill("count") > 359)
			return notify_fail("八卦奇书已经帮不了 。\n");

  me->set_skill("count", me->query_skill("count",1) + 1);

	write(HIY"你研究"HIG"八卦奇书"HIY"刷新了自己对阴阳八卦的认知!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }