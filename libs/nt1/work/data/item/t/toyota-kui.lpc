// SN:VQ;?jn202TZnCc;@
// ITEM Made by player(曰曰:toyota) /data/item/t/toyota-kui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Nov 11 23:39:51 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m幽冥盔[2;37;0m", ({ "kui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
盔上斑驳纵横，看上去经历了太多的战斗。[2;37;0m
头盔缘上刻着一行小字：曰曰(toyota)
");
	set("value", 2100000);
	set("point", 123);
	set("material", "magic stone");
	set("wear_msg", "$N将$n戴在头上。[2;37;0m\n");
	set("remove_msg", "$N将$n自头上摘下。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
