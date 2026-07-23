#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(CYN"外台秘要"NOR, ({ "waitai miyao", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("unique", 1);
                set("treasure",1);
                set("long", "这是一本由古代医学宝典，由王焘所著。\n");
                set("value", 1000000);
                set("material", "paper");
                set("exp_required", 700000);
                set("jing_cost", 85);
                set("difficulty", 38);
                set("min_skill", 180);
                set("max_skill", 191);
        }
}
#include "m-book.h";
                