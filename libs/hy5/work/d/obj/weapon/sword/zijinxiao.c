//Cracked by Roath
// created by ajax on 7/8/1999

#include <ansi.h>
#include <weapon.h>

//inherit F_UNIQUE;

inherit SWORD;

void create()
{
        set_name(HIM"紫"+HIY"金"+HIG"箫"NOR, ({ "zijin xiao","xiao","zijinxiao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("material", "wood");
                set("long", BLU"韩湘子的紫金箫，听说是用南海紫竹林里的一株神竹做的，用此物奏箫，音质美妙绝伦．．．\n"NOR);
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("value", 3000);
//                set("replace_file", "/d/obj/weapon/sword/yudi");
		set("wield_msg", "$N拿起$n，不禁想起了为这箫而被困南海的丽人。\n");
		set("unwield_msg", "$N神情萎靡，无精打采的将$n插回腰间。\n");
       	        set("weapon_prop/int", 2);
                set("music/type", "xiao");
	}
        init_sword(210);
	setup();
}
