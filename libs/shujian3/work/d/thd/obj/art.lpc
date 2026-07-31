#include <ansi.h>
inherit ITEM;
void create()
{
        switch(random(10)) {
               case 0 : set_name(HIW "清明上河图" NOR, ({ "tu", "art"})); break;
               case 1 : set_name(HIG "山中游旅图" NOR, ({ "tu", "art"})); break;
               case 2 : set_name(HIR "率意帖" NOR, ({ "tie", "art"})); break;
               case 3 : set_name(HIB "八骏图" NOR, ({ "tu", "art"})); break;
               case 4 : set_name(HIY "黄山行旅图" NOR, ({ "tu", "art"})); break;
               case 5 : set_name(HIM "裴将军诗帖" NOR, ({ "tie", "art"})); break;
               case 6 : set_name(HIC "满江红词稿" NOR, ({ "ci", "art"})); break;
               case 7 : set_name(CYN "明月宝剑图" NOR, ({ "tu", "art"})); break;
               case 8 : set_name(BLU "百鸟朝凤图" NOR, ({ "tu", "art"})); break;
               case 9 : set_name(MAG "宋徽宗字帖" NOR, ({ "tie", "art"})); break;
        }
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 300000);
                set("unit", "幅");
                set("weight", 100);
                set("material", "paper");
                }
        setup();
}

