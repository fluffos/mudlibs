//pianting2.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"练功房"NOR);
        set("long", @LONG
房间的四周墙上点满了火把。这里极为安静，仅能听到或悠长，或粗重的
呼吸声。厅里零零落落地摆着几个蒲团，并无其他陈设。几个人正在沈城的指
导下坐在蒲团上打坐（dazuo)，吐纳（tuna）。北面是一条石板路。
LONG
        );        
  
        set("exits", ([
               "north" : __DIR__"shilu4",               
        ]));
       set("no_fight",1);
        set("objects", ([
               __DIR__"npc/dizi8" : 1,
        ]));

        setup();
}
