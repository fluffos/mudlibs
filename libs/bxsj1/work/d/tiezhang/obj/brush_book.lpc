//brush_book.c 临摹字贴
inherit ITEM;

void create()
{
        set_name("临摹字贴", ({ "linmo zitie","zitie","shu","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本汇集众多名家书法的临摹字贴。\n");
                set("unique", 1);
                set("treasure",1);                              
                set("value", 1000);
                set("material", "paper");
                set("skill", 
                ([
                        "name": "brush",         // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    20,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    30      // the maximum level you can learn
                ]));
        }
}
