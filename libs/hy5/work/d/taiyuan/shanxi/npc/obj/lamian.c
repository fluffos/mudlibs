 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("¿≠√Ê", ({ "la mian", "mian" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ω¥‘∞œÔ∑ππ›µƒ¿≠√Ê°£\n");
                set("unit", "ÕÎ");
                set("value", 2000);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        
}
int finish_eat()
{
        set_name("æ∞Ã©¿∂¥…ÕÎ", ({"wan"}));
        set("value",200);
        set("long", "“ª÷ªæ∞Ã©¿∂¥…ÕÎ°£\n");
        return 1;
} 
