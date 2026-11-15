// wujins.c 乌金丝

inherit ITEM;
void create()
{
	set_name(WHT "乌金丝" NOR, ({ "black silk", "wujin si", "si"}));
	set_weight(1800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一束黑白相间的细丝，是由乌金丝和蚕丝混合织就而成。\n");
		set("spectxt", "制造装备的材料。\n");
		set("unit", "束");
		set("value", 3000000);
		set("yuanbao", 200);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", YEL "乌金丝" NOR);
		set("can_make", ({ "鞭", "护甲", "战衣", "腰带", "裤子", "靴子" }));
		set("power_point", 70);
	}

}

