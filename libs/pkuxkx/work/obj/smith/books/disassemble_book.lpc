#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HBBLU+HIW+"装备结构入门"+NOR, ({"zhuangbei rumen", "rumen","introduction"}));
        set_weight(600);
        set("long", "这是一本关于装备结构和拆解装备方面的著作。\n");
        set("unit", "本");
		set("value",50000000);
		set("EnhanceMark","weapon_cast/disassemble");
		set("EnhanceMaterial","震雷");
		setup();
}

void init()
{
	add_action("do_yanjiu","yanjiu");
}
int do_yanjiu()
{
	object me=this_player(),ob=this_object();
	string mark=query("EnhanceMark");
	if (me->query(mark))
	{
		tell_object(me,"你已经掌握了装备结构方面的知识了，现在这个对你意义不大了。\n");
	}
	else
	{
		me->set(mark,1);
		tell_object(me,HIG+"恭喜！你掌握了拆解(disassemble)装备，学习装备构造的方法！\n"+NOR);
		message_vision(BLU+"$N"+BLU+"化成纸屑，飘散在风中。\n"+NOR,this_object());
		destruct(this_object());
	}
	return 1;
}