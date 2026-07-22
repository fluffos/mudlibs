// yfzhen.c
// By River 98/09
// hehe by lane@SJ 2005/4/26

#include <ansi.h>
inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"

//	第一方案：如果禁止非古墓玩家使用（下面选择 no  ）
//	第二方案：如果非古墓玩家使用无毒（下面选择 yes ）

#define player_use "yes"

void create()
{
	set_name(HIY"玉蜂针" NOR, ({ "yufeng zhen", "zhen" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这玉蜂针乃是细如毛发的金针，六成黄金、四成精钢，以玉蜂尾刺上\n"+
			"毒液浸过，虽然细小，但因黄金沉重，掷出时仍可及远。\n");
		set("unit", "袋");
		set("no_sell", 1);
		set("value", 20);
		set("base_unit", "枚");
		set("base_weight", 100);
		set("material", "steel");
		set("damage", 10);
		set("poison", "bee_poison");
		set("embed", 1);
	}
	set_amount(10);
}

void init()
{
	add_action("action", "throw");
}

int action()
{
	object me = this_player();
	object ob = this_object();

	if( !living(me) ) {
		write("「书剑」就是这样被你弄当机的！\n");
		return 1;
	}

	if( me->query("family/family_name") != "古墓派" && player_use == "no" ) {
		write("古墓派的"+ob->name()+"可不是那么好使，小心别伤到自己！！\n");
		return 1;
	}

	if( me->query("family/family_name") != "古墓派" ) {
		if( wizardp(me) ) tell_object(me, "你很倒霉！系统会自动删除"+ob->name()+"的毒性。\n");
		ob->delete("poison");
		ob->set("long", "这玉蜂针乃是细如毛发的金针，六成黄金、四成精钢，以玉蜂尾刺上\n"+
                            "毒液浸过，虽然细小，但因黄金沉重，掷出时仍可及远，不过毒性效果已经不明显了。\n");
	} else {
		if( wizardp(me) ) tell_object(me, "你很厉害！系统自动加上了"+ob->name()+"的毒性。\n");
		ob->set("poison", "bee_poison");
		set("long", "这玉蜂针乃是细如毛发的金针，六成黄金、四成精钢，以玉蜂尾刺上\n"+
			"毒液浸过，虽然细小，但因黄金沉重，掷出时仍可及远。\n");
	}
	return 0;
}
