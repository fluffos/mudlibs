// yuxiao.c 玉箫

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("玉箫", ({"yu xiao", "xiao"}));
	set_weight(250);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit", "支");
		set("value", 2000);
		set("material", "gem");
                set("rigidity", 1);
		set("long","这是一支用蓝田美玉制做的箫，看起来温润光洁，令人爱不释手。\n");
		set("wield_msg","$N伸手轻轻一招，一支$n已出现在$N手中。\n");
		set("unwield_msg","$N一声清啸，将$n插回腰间。\n");
	}
	init_sword(25);
	setup();
}

int wield() 
{
        object me = environment();
        if (living(me) && me->query_skill("yuxiao-jian", 1) < 50){
            message_vision("$N拿起"+name()+"，但是不会使用。\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

