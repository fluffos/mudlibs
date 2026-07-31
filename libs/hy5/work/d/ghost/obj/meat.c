 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("ºìÉÕÈâ", ({ "meat", "Èâ"}) );
        set_weight(400500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»´ó¹øÏãÅçÅçµÄºìÉÕÈâ¡£\n");
                set("unit", "¹ø");
                set("value", 30);
                set("food_remaining", 10);
                set("food_supply", 100);
        }
        
} 
int finish_eat()
{
        set_name("´óÌú¹ø", ({ "big pot" }) );
        set_weight(50);
        set("long", "Ò»Ö»´óÌú¹ø¡£\n");
        return 1;
}
