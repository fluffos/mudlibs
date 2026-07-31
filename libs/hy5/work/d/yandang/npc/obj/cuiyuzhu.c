#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name( HIC"翠玉镯"NOR, ({ "cui yuzhuo", "yuzhuo" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
                set("long", "一只翡翠玉镯,雕刻成一条首尾相连的飞龙,\n
龙的眼珠却是镶嵌的天然"+HIR+"红宝石"+NOR+",似乎可以按(an)动!\n");
		set("value",500);
		set("material", "stone");
		set("armor_prop/armor", 150);
	}
	setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_an","an");
}
int do_an(string arg)
{
object jade,me;
	if( !living(this_player()))	return 0;
if ((!arg)||((arg!="红宝石")&&(arg!="眼珠"))) return notify_fail("你要按什么?\n");
me = this_player();
	jade = new(__DIR__"yuchang.c");
	jade->move(me);
message_vision("$N按下龙睛,啪的一声,"+HIC+"玉镯"+NOR+"弹开,变成一把"+HIC+"短剑.\n"NOR,this_player());
	destruct(this_object());

return 1;
}
