 inherit ITEM;
inherit F_FOOD; 
void create()
{
        int i;
        set_name("∫Ï…’»‚", ({ "meat" }) );
        set_weight(500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
        set("long", "“ªøÈœ„≈Á≈Á£¨”Õπ‚π‚µƒ∫Ï…’»‚°£\n");
        set("unit", "øÈ");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 10);
        set("marks/catfood", 1);
    }
    
}      
