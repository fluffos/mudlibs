 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("´ÖÃ×·¹", ({ "rice", "°×·¹"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Íë´ÖÃ×·¹¡£\n");
                set("unit", "Íë");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
        
} 
int finish_eat()
{
        set_name("´Ö´ÉÍë", ({ "bowl" }) );
        set_weight(50);
        set("long", "Ò»Ö»´Ö´ÉÍë¡£\n");
        return 1;
}
