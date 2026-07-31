
#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIR "更名卡" NOR, ({ "gengming card" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来改名换姓的卡片。\n");
		set("unit", "张");
		set("base_unit", "张");
		set("base_value", 500);
		set("yuanbao", 800);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);
            set("no_put",1);
		set("only_do_effect", 1);
		set("base_weight", 10);
	}
	setup();
}

void init()
{
	add_action("change_name","chname");
}

int change_name(string arg)
{
	string result;
	object me=this_player();

	if(me->query("combat_exp", 1) < 10000) 
	{
		tell_object(me,"你没有实战基础，无法使用" + name() + "！\n");
		return 1;
	}

	if(!arg||arg=="")
	{
		tell_object(me,INPUTTXT("你想改成什么名字？","chname $txt#\n"));
		return 1;
	}

	result = NAME_D->change_name(me, arg);

	if (result)
	{
		tell_object(me,result);
		return 1;
	}
	else
		write("改名换姓成功！\n");

	add_amount(-1);

	return 1;
}

int do_effect(object me)
{
	change_name("");
	return 1;
}
