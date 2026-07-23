#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"千金翼方"NOR, ({ "qianjin yifang", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("unique", 1);
                set("treasure",1);
                set("long", "这是一本由汉代孙思邈所著的医学宝典，它与《备急千金要方》合称作《千金方》。\n");
                set("value", 1000000);
                set("material", "paper");
                set("exp_required", 500000);
                set("jing_cost", 75);
                set("difficulty", 36);
                set("min_skill", 160);
                set("max_skill", 181);
        }
}
#include "m-book.h";
               