#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"本草经集注"NOR, ({ "bencao jizhu", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("treasure",1);
                set("unique", 1);
                set("long", "这是一本陶弘景所著的有关本草术理的书。\n");
                set("value", 200000);
                set("material", "paper");
                set("exp_required", 150000);
                set("jing_cost", 60);
                set("difficulty", 30);
                set("min_skill", 100);
                set("max_skill", 121);
        }
}
#include "m-book.h";
               