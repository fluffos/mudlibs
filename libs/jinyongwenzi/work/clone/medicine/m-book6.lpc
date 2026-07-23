inherit ITEM;

void create()
{
        set_name("博集稀痘方", ({ "boji xidoufang", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本明代郭子章所著的有关本草术理的书。\n");
                set("value", 100000);
                set("material", "paper");
                set("exp_required", 50000);
                set("jing_cost", 45);
                set("difficulty", 27);
                set("min_skill", 70);
                set("max_skill", 81);
        }
}
#include "m-book.h";
               