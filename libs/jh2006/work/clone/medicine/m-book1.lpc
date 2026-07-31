inherit ITEM;

void create()
{
        set_name("肘後备急方", ({ "ji fang", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本明末葛洪所写的讲述本草术理的书。\n");
                set("value", 2500);
                set("material", "paper");
                set("exp_required", 5000);
                set("jing_cost", 20);
                set("difficulty", 22);
                set("max_skill", 31);
        }
}
#include "m-book.h";
