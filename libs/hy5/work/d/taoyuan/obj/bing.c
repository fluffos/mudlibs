 inherit ITEM;
inherit F_FOOD; 
void create()
{
    set_name("´ĞÓÍ±ı", ({ "bing" }) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "Ò»¸öÏãÅçÅç¡¢ÈÈÌÚÌÚµÄ´ĞÓÍ±ı\n");
        set("unit", "¸ö");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 60);
    }
    
}  
