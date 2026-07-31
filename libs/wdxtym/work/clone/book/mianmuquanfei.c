// mengzi.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT "面目全非" NOR, ({ "huirong book", "shu" }));
        set_weight(300);

        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long", "这是一本夺命书生记录下来的面目全非脚的武学秘笈。\n");
                set("value", 100);
               // set("no_sell", "这...这值什么钱？\n");
                set("material", "paper");
                set("skill", ([
                        "name": "mianmu-quanfei",    // name of the skill
                        "jing_cost":   100,    // jing cost every time study this
                        "difficulty":   38,    // the base int to learn this skill
                        "max_skill":   180,    // the maximum level you can learn to
                        "min_skill":   0,    // minimun level required
                ]));
        }
}
