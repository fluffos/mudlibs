inherit ITEM;

void create()
{
        set_name("三冈识略", ({ "sangang shilue", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本明末董含所写的讲述本草术理的书。\n");
                set("value", 10);
                set("material", "paper");
                set("exp_required", 10000);
                set("jing_cost", 30);
                set("difficulty", 24);
                set("min_skill", 40);
                set("max_skill", 51);
        }
}
#include "m-book.h";
              
