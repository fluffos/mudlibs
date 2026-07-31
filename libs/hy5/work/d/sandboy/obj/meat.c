inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("猪肉", ({ "meat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块血淋淋的猪肉,鲜血一滴滴地掉下来.\n");
		set("unit", "块");
		set("value", 10);
                set("eat_msg","$N用牙齿撕下一块血淋淋的$n,狼吞虎咽吃了起来.\n");
		set("food_remaining",8);
		set("food_supply", 60);
	}
}
