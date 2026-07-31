 inherit ITEM;
inherit F_FOOD; 
void create()
{
    set_name("´ø¼ÔÃ«¶¹", ({ "soy beans", "maodou" }) );
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "ÄÛÄÛÂÌÂÌµÄĞ¡Ã«¶¹¡£\n");
        set("unit", "Ğ©");
        set("value", 10);
        set("food_remaining", 3);
        set("food_supply", 15);
    }
    
} 
