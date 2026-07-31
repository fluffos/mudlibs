//LUCAS 2000-6-18
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"雪山剑谱"NOR, ({ "swordbook","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本凌霄城的剑法秘籍，封面上写着四个字“雪山剑法”。\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "xueshan-sword",       // name of the skill
                        "exp_required": 10000,                  // minimum combat experience required
                                                                // to learn this skill.
                        "jing_cost" :   30,
                        "difficulty":   30,                     // the base int to learn this skill
                                                                // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    100,                     // the maximum level you can learn
                        "min_skill":    0                       // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}

