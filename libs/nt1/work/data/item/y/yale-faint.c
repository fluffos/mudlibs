// SN:02eXYHo]b6FmiIDn
// ITEM Made by player(寒易:yale) /data/item/y/yale-faint.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Aug  2 20:12:33 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m鼠[1;36m标[2;37;0m", ({ "faint" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;37m这可是[1;34m高[1;31m科技[1;32m产品[2;37;0m
铁掌缘上刻着一行小字：寒易(yale)
");
	set("value", 2100000);
	set("point", 211);
	set("material", "magic stone");
	set("wear_msg", "[1;37m听说这个挺[1;31m拽，[1;37m要不要[1;34m试[1;33m一下。[2;37;0m\n");
	set("remove_msg", "[1;37m一点劲都没有，[1;31m算了，[1;33m回家吧。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
