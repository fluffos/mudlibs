#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name("十八木偶", ({ "18 muou", "18", "muou" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__); 
        else {
                set("unit", "盒");
                set("long", NOR + YEL "
这是一个小木盒，盒中垫着棉花，并列着三排木偶，神情或喜
悦不禁，或痛哭流泪，或裂嘴大怒，或慈和可亲，竟无一相同。
木偶身上油着层桐油，绘满黑线，却无穴道位置。这盒木偶刻
工精巧，面目栩栩如生。竟似一门非常高深的武学。\n" NOR);
                set("value", 200);
                set("material", "paper");
                set("skill", ([
                        "name":         "luohan-fumogong",
                        "exp_required": 1000,
                        "jing_cost":    20,
                        "difficulty":   20,
                        "max_skill":    20,
                ]));
        }
}