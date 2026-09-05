// standard dagger

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
                set("long", "$long$");
                set("owner", "$owner$");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);

		set("unit", "柄");
		set("material", "steel");
		set("rigidity", 300);
                set("wield_msg", "$wield_msg$");
                set("unwield_msg", "$unwield_msg$");
	}

	init_dagger(10);

	setup();
}
/*
void init()
{
        if (this_player()->query("id")!=query("owner"))
        {
                message_vision(query("name")+"突然化成一道青烟，消失在空气中！\n",this_player());
                destruct(this_object());
                return;
        }
}
*/