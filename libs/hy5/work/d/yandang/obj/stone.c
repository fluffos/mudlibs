#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("晶石", ({ "stone" , "晶石"}) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "白色的晶石在天光下闪著迷人的色彩.\n");
		set("value", 1);
set("no_steal",1);
             set("no_drop",1);
             set("no_sell",1);
		set("material", "stone");

	}
setup();
}
void init()
{
	add_action("do_eat", "eat");
}
do_eat(string arg)
{
	object me;
	int max_gin, max_kee, max_sen;
	me = this_player();
	if( !living(me))	return 0;
      if (!arg) return notify_fail("你要吃什么?\n");
	max_gin = (int) me->query("max_qi");
        max_kee = (int) me->query("max_jing");
        max_sen = (int) me->query("max_neili");
	message_vision( HIR "$N的全身映出一阵红光！！\n" NOR, me);
	max_gin = max_gin * 11/10;
	max_kee = max_kee * 11/10;
	max_sen = max_sen * 11/10;
	switch(random(3)){
		case 0:
			me->set("max_qi", max_gin);
			break;
		case 1:
			me->set("max_jing", max_kee);
			break;
		case 2:
			me->set("max_neili", max_sen);
			break;
			}
	destruct(this_object());
        return 1;
}


