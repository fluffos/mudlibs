// zhusun.c ôä´äÖñİ¥

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ôä´äÖñİ¥", ({"zhusun", "zhu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌË¬¿ÚµÄÖñº£ÌØ²ú-Öñİ¥¡£\n");
		set("unit", "ÅÌ");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
