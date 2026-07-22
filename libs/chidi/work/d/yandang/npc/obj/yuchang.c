#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIC"鱼肠剑"NOR, ({ "yuchang","sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "短小的剑身精茫四射,把手后雕刻了一条飞龙.\n
合拢(close)后能成为一只玉镯.\n");
		set("value", 100000);
		set("material", "steel");
	}
	init_sword(60);
      set("wield_msg",
"鱼---肠----剑----------$N仰天长啸,一把短小的"+HIC+"剑"+NOR+"出现在手中!\n");
	set("unwield_msg","$N把"+HIC+"短剑"+NOR+"小心地收好.\n");
       setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_close","close");
}
int do_close()
{
object jade,me;
me = this_player();
	if( !living(me))	return 0;
	jade = new(__DIR__"cuiyuzhu.c");
	jade->move(me);
message_vision("$N把"+HIC+"鱼肠剑"+NOR+"合成一只小巧的"+HIC+"翠玉镯.\n"NOR,this_player());
	destruct(this_object());

return 1;
}
