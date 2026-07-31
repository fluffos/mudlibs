// SN:_F8_j_GEah0ER<_J
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-huwan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 24 21:25:26 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m锦瑟无端五十弦[2;37;0m", ({ "huwan" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
[1;34m这是一根七彩色的手链，链子由五十个弧形所组成，当真是巧到毫颠，链子中间挂着一只小铃铛。[2;37;0m
护腕缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 196);
	set("material", "magic stone");
	set("wear_msg", "[1;34m只闻得一阵叮叮玲玲的清脆声响，$N的皓腕之上突然多了一根七彩手链，而声音正是由那链上的铃铛所发出。\n看$N惊异的模样，无疑她自己也不知道是如何来的，不过雪白的手腕上多了一根这样的手链，越发显得纤细可爱。[2;37;0m\n");
	set("remove_msg", "[1;34m$N心神一凝，盯着手腕上那根手链，言道：“你可以走了吗？”又是一阵叮铃铃的声音，那根手链果真不见了。\n$N见手链随心意而动，对此大是兴奋，笑逐颜开，双眼弯成月牙般的弧形，清秀的脸庞上也多了一抹浅红。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
