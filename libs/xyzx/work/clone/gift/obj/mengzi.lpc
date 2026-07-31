// mengzi.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT "孟子" NOR, ({ "mengzi book", "shu" }));
        set_weight(300);

        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long", "这本书记载了当年孟子许多言行哲论，是儒家经典书籍。\n");
                set("value", 100);
                set("no_sell", "这...这值什么钱？\n");
                set("material", "paper");
                set("skill", ([
                        "name": "literate",    // name of the skill
                        "jing_cost":   200,    // jing cost every time study this
                        "difficulty":   80,    // the base int to learn this skill
                        "max_skill":   250,    // the maximum level you can learn to
                        "min_skill":   200,    // minimun level required
                ]));
        }
}
