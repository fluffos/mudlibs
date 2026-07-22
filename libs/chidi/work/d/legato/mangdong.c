#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "蟒洞");
        set("long", @LONG
你来到一个布满了钟乳石的山洞，不时听到滴滴答答的水珠落地的
声音，你看了一下四周，忽然发现不远处一条巨蟒盘在那里，正警
惕的看着你，两只眼睛发出绿莹莹的光，
LONG );
          
                set("objects",([
         "/u/legato/npc/mangshe":1,
       ]));
              set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"shandong",
         "north":__DIR__"shishi",
           ]));
        set("no_clean_up", 0);
        setup();
}

