#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
    set_name(HIW"小刀"NOR, ({ "xin wu","xiao dao" }));
    set_weight(7000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("long", "这是一柄镶缀个绿宝石的小刀，价值连城。\n");
        set("value", 1);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
    }
	set("no_get",1);
    init_blade(300);
    setup();
	call_out("dest",180);
}

void init()
{
	add_action("do_drop",({ "drop"}));
}

int dest()
{
    if (environment())
    {
	    tell_object(environment(),"小刀滑落路边，然后你再也找不到了。\n");
    }
    if (this_object())
    {
	    destruct(this_object());
    }
	return 1;
}

int do_drop(string arg)
{
	if (!arg)
	{
		return 1;
	}
	if (arg=="xin wu"||arg=="xiao dao")
	{
		tell_object(environment(),"此等宝物，丢弃岂不可惜？\n");
		return 1;
	}
}

