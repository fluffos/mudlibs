//Cracked by Roath
// oufen.c Åº·Û

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("Åº·Û", ({ "oufen" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ò»ÍëºÃ³ÔµÄÅº·Û,²ú×ÔÌ«ºþ¡£\n");
		set("unit", "Íë");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
        }
    setup();
}

