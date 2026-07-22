inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIW"玉玺"NOR, ({ "yuxi"}) );
    set_weight(100);
    set("unit", "块"); 
    set("long", "这是一块大燕国的皇家玉玺，全身透着亮白色,玉玺的一边好象有一丝裂痕。\n");
    set("value", 0);
    setup();
}             