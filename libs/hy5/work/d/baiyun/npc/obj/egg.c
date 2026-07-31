 inherit F_FOOD;
inherit ITEM; 
void create()
{
    set_name("°×Öó¼¦µ°", ({ "egg"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "Ò»¸ö°þÁË¿ÇµÄ°×Öó¼¦µ°¡£\n");
        set("unit", "¸ö");
        set("value", 2000);
        set("food_remaining", 4);
                set("food_supply", 40);
                set("material", "food");
        }
        
}    
