// axe-book.c 基本斧法
inherit ITEM;

void create()
{
        set_name("斧法秘要", ({ "fufa miyao", "book","shu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本学习基本斧法的书。\n");
                set("unique", 1);
                set("treasure",1);                              
                set("value", 1000);
                set("material", "paper");
                set("skill", 
                ([
                        "name": "axe",          // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    101      // the maximum level you can learn
                ]));
        }
}
