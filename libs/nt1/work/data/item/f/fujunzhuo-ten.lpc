// SN:<4PH:61lkS82BWDh
// ITEM Made by player(傅君婥:fujunzhuo) /data/item/f/fujunzhuo-ten.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun  3 20:11:45 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m十年生死两茫茫[2;37;0m", ({ "ten" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;34m一柄不像长剑的长剑，剑刃上流淌着莽莽苍苍的悲伤与哀愁，中间一道浅痕，恰似离人泪。[2;37;0m
剑柄上刻着一行小字：傅君婥(fujunzhuo)
");
	set("value", 2100000);
	set("point", 431);
	set("material", "magic stone");
	set("wield_msg", "[1;34m$N对着虚无飘渺的天空深情地凝望着，眼神里流露出掩饰不住地思念之意。\n一声低沉地呼唤自$N的口里念出，仿佛来自九幽底下的深切相思，一柄不属于凡间的$n[1;34m出现在她的手上。[2;37;0m\n");
	set("unwield_msg", "[1;34m$N再度对着茫茫的大地，仿佛要看穿这隔离一切的深度，寻觅那深藏在那里的恋人。\n$N樱唇轻启，呢喃出深入骨髓的名字，洒落了一滴清漾的泪，手中的$n[1;34m也随着泪水凭空幻作虚无。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
