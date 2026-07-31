// ITEM Made by player(蛋仔:mxjd001_1) /data/item/m/mxjd001_1-iiii.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 28 17:11:50 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m魑[1;35m魅[30m魍魉[2;37;0m", ({ "iiii" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;31m真龙[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：蛋仔(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m恶鬼在人间游荡，吾等该往何方。地狱早已空荡荡，天堂间谁相望。佛祖何曾度众生，人世魑魅魍魉。黑暗根深留余恨，光明可存少许。[2;37;0m\n");
	set("unwield_msg", "[1;33m孤芳自赏，魑魅魍魉。来来往往，撕碎了爱情，停止了生长。也许雾里看花，看不透一个他，也许一念之差，拼凑出一个家，虚伪的鬼，善变的嘴，爱情足够完美。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
