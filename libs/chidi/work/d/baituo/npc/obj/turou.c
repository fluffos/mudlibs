// turou.c
inherit F_FOOD;
inherit ITEM;
void create()
{
	set_name("ÍÃÈâ", ({ "tu rou", "rou" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ò»Ö»ÉÕ¿¾µÃÏãÏãµÄÍÃÈâ¡£\n");
		set("unit", "¿é");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 25);
        }
    setup();
}
