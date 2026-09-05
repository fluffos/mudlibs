#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIW"倚天剑"NOR, ({ "yitian jian","jian" }));
        set_weight(10000);
        set("value",0);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIW+"这就是灭绝师太那把断金切玉、锋锐绝伦的倚天宝剑！\n"+NOR);
                set("value", 0);
                set("no_drop",this_object()->query("name")+HIR"是武林至宝，多少人为它丢掉了性命，你竟然舍得把他扔掉？\n"NOR);
             }
        set("robinterval",60);  
        init_sword(300);
        setup();
}

