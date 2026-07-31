 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("µ¶²¦Ãæ", ({ "bo mian", "mian" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "½´Ô°Ïï·¹¹ÝµÄµ¶²¦Ãæ¡£\n");
                set("unit", "Íë");
                set("value", 2000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        
}
int finish_eat()
{
        set_name("¾°Ì©À¶´ÉÍë", ({"wan"}));
        set("value",200);
        set("long", "Ò»Ö»¾°Ì©À¶´ÉÍë¡£\n");
        return 1;
} 
