// d/qujing/huangfeng/obj/jiasha.c
//降魔袈裟      // created by angell 1/1/2001

#include <armor.h>
#include <ansi.h>

inherit CLOTH;


void create()
{
	set_name(HIY"降魔袈裟"NOR, ({ "xiangmo jiasha", "jiasha" }) );
	set("long", "此乃我祖如来所赐之降魔袈裟，穿上可增强降魔法力。\n");
	set_weight(2800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 360);
		set("armor_prop/spells", 40);
		set("armor_prop/dodge", 30);
		set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 500);
	}
	setup();
}

