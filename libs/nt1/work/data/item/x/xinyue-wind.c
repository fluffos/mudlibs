// SN:U0UT[=0ea\cV<a9]
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-wind.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr  3 22:08:55 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m风之顶冠[2;37;0m", ({ "wind" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;34m这是风之神遗留在人间唯一的见证，周围一股青气在滚动着，使得帽子看起来若有若无。[2;37;0m
头盔缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 166);
	set("material", "magic stone");
	set("wear_msg", "[1;34m$N轻轻地念了一句咒语：“掌管大气的精灵，听从我的祈祷，以我与风之神的契约，解脱大地的束缚。”\n[1;34m随著咒语的咏唱，$N慢慢浮了起来，往天上飘去，一会儿就消失在茫茫的苍穹之中。[2;37;0m\n");
	set("remove_msg", "[1;34m半空中传来一阵古老而苍凉的咒语声，随着咒语的完毕，于无尽的碧落中渐渐飘落了$N的身影。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
