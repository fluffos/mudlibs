// huanshou_di.c

inherit ITEM;

void create()
{
	set_name("幻兽哨",({ "shou shao", "shao" }) );
	set_weight(1);
	set("no_sell", "这是幻兽的化身，不可以卖的。\n");
	set("no_drop", "这样东西不能离开你。\n");
	set("no_give","这东西不可以给别人。 \n");
	set("no_put",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 10);
		set("material", "bamboo");
		set("long", "这是召唤幻兽使用的哨子。\n");
	}
	setup();
}

