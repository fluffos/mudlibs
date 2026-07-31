#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"道家心法"NOR, ({ "daojiaxf"}));
	set("long","这是一本"HIG"道家心法"NOR"，使用限制为0到360"ZJURL("cmds:kan daojiaxf")+ZJSIZE(28)+"研究"NOR"。\n");
	set("unit","本");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","道家心法");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="daojiaxf")
  	return notify_fail("你要看什么?\n");
      		
 if(me->query_skill("taoism") < 0)
			return notify_fail("你对密宗的认知太少了 。\n");
 
 if(me->query_skill("taoism") > 359)
			return notify_fail("道家心法已经帮不了 。\n");

  me->set_skill("taoism", me->query_skill("taoism",1) + 25);

	write(HIY"你研究"HIG"道家心法"HIY"刷新了自己对密宗的认知!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }