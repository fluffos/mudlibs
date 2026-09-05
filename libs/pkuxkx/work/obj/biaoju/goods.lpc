#pragma save_binary
inherit ITEM;

void create()
{
	set_name("货物", ({"goods", "huo wu", "wu"}));
	set_weight((1+random(20))*1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("no_pawn",1);
		set("no_paimai",1);
		set("unit", "箱");
		set("long", "这是由商家交托镖局运送的货物,它相当值钱!\n");
		set("value", 1);
	}
}
