// liao_kao.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name(HIR "香囊" NOR, ({ "xiang nang", "nang" }) );
	set_weight(100);
	if (clonep()) set_default_object(__FILE__);
	set("unit", "个");
	set("value", 1);
	set("material", "silk");
	set("armor_type", "married");
	set("armor_prop/armor",0);
	set("no_get",1);
	set("no_drop",1);
	setup();
}

int query_autoload()
{
	return 1;
}

void init()
{
	object ob = this_player();

        if (environment() == ob && !wizardp(ob)) {
		if (ob->query("gender") == "女性") {
        set_name(HIC "玉佩" NOR, ({ "yu pei", "yupei" }) );
			set("unit", "块");
			set("material", "jade");
		}
		if (!ob->query("marry/id") || !ob->query("marry/name")) {
			ob->delete("marry");
			call_out("lost", 1);
			return;
		}
		set("long", "这是你"
			+ (ob->query("gender") == "女性"?"相公":"娘子")
			+ "送给你的定情信物，上面"
			+ (ob->query("gender") == "女性"?"刻":"绣")
			+ "着一行小字：「"
			+ (ob->query("gender") == "女性"?"情深不寿 ":"强极则辱 ")
			+ ob->query("marry/name") + "」。\n");
		wear();
	}
}

void lost()
{
	object ob = environment();

	if (userp(ob) && (!ob->query("marry/id") || !ob->query("marry/name"))) {
		tell_object(ob, HIB "\n你隐约觉得有一样很重要的东西丢失了！\n\n" NOR);
		destruct(this_object());
	}
}

int unequip()
{
	object ob = environment();

	if (ob && userp(ob) && ob->query("marry/id") && ob->query("marry/name"))
		return notify_fail("你不能卸下你的定情信物。\n");

	return ::unequip();
}
