  //碧水剑
  //by dewbaby@sk


#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
    set_name(BLINK+HIG"碧水剑"NOR,({"bishui jian","bishui","jian"}));
     set_weight(4000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit","柄");
                set("value",4000);
                 set("no_drop","1");
                set("material","gold");
                set("long",HIG"据说这是九天玄女的神剑，它周身闪烁着碧绿的光芒。\n"NOR);
                set("wield_msg",HIG"时光如梭，花草凋零，$N已将$n"HIG"握在手中，你心中一寒。\n"NOR);
                 set("unwield_msg",HIG"$N双眼微闭，眨眼间已将$n"HIG"插回腰间。你只觉周身冰凉。\n"NOR);
                      set("no_drop","还是不要丢吧，小心九天玄女要了你的小命！\n");
              }
    init_sword(2000);
     setup();
}
