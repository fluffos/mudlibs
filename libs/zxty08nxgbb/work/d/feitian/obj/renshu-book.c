// zixia_book.c  紫霞秘芨
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"忍法皆转"NOR, ({ "renshu-book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("no_drop",1);
                set("long",
                        "这是风魔小次郎写下的忍术要决。\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "bearart",       // name of the skill
                        "exp_required": 10000,                  // minimum combat experience required
                                                                // to learn this skill.
                        "jing_cost" :   30,
                        "difficulty":   30,                     // the base int to learn this skill
                                                                // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    99,                     // the maximum level you can learn
                        "min_skill":    0                       // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}
int query_autoload() { return 1; }

