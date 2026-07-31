
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("∫Ï…’—Ú»‚", ({"hongshao yangrou","yangrou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "’‚ «“ª≈Ãœ„¿±∫Ï…’—Ú»‚°£\n");
                set("unit", "≈Ã");
                set("value", 400);
                set("food_remaining", 20);
                set("food_supply", 70);
        }
}

