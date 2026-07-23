#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"备急千金要方"NOR, ({ "qianjin yaofang", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("unique", 1);
                set("treasure",1);
                set("long", "这是一本由汉代孙思邈所著的医学宝典，它与《千金翼方》合称作《千金方》。\n");
                set("value", 300000);
                set("material", "paper");
                set("exp_required", 300000);
                set("jing_cost", 70);
                set("difficulty", 34);
                set("min_skill", 140);
                set("max_skill", 161);
        }
}
#include "m-book.h";
              