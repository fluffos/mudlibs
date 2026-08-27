// teie-ling.c
inherit ITEM;

void create()
{
	set_name( "重陽令", ({ "chongyang ling", "ling", "iron" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "塊");
		set("long", "這是一塊用於通行重陽宮的鐵鑄令牌。 由丹陽真人簽發，邀各路英雄入宮觀禮。\n");
		set("value", 100);
		set("material", "iron");
	}
	setup();
}

void init()
{
	call_out("dest", 1800);
}

void dest()
{
	destruct(this_object());
}
