// Written by Doing Lu 1998/11/2

inherit ITEM;

// 这是生成道具时的依据，只有一部分数据预先设定
// 其它的数据在打造粗坯和生成道具时才设定
// 生成道具后这个object将destruct
// 鉴别这是道具粗坯得标志是 item_origin 属性

void create()
{
	set_name("甲坯", ({"jia pi", "pi"}));	// 在程序中修订
	set_weight(100);			// 在程序中设定
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是干将的弟子打造的甲坯。\n");
		set("unit", "件");
		set("no_sell", 1);
                set("no_pawn", 1);
		set("nopawn", 1);
		set("item_origin", 1);		// 这个属性表明它是道具粗坯
		set("item_type", "armor");	// 这个属性表明它是防具类
		set("type", "armor");		// 这个属性表明它是甲类/即 include 的文件
		set("inherit", "CLOTH");	// 这个属性表明它应该继承 CLOTH
		set("ctype", "甲");		// armor 的中文

		set("material1", "");		// 在程序中设定
		set("mat_attr1", 0);		// 在程序中设定
		set("material2", "");		// 在程序中设定
		set("mat_attr2", 0);		// 在程序中设定
		set("value", 0);		// 在程序中设定
		set("wear_msg", "");		// 在程序中设定
		set("remove_msg", "");		// 在程序中设定
		set("point", 0);		// 在程序中设定
		set("owner", "");		// 在程序中设定
		set("ownerid", "");		// 在程序中设定
	}
}
