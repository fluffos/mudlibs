// SN:5beRmHE;Xn1RgXd@
// ITEM Made by player(胡小僧:loop) /data/item/l/loop-zhanyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct  5 01:16:25 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m月白长袍[2;37;0m", ({ "zhanyi" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
这是为胡小僧定制的长袍，色做[1;37m月白[2;37;0m，做工精细无伦。[2;37;0m
战衣缘上刻着一行小字：胡小僧(loop)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "silk");
	set("wear_msg", "$N将$n一展，披在身上，顿时精神了许多。真是[1;36m人靠衣衫哪[2;37;0m。[2;37;0m\n");
	set("remove_msg", "$N除下$n，团成一团，收入怀中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
