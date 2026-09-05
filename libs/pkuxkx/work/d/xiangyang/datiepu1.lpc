#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",YEL"打铁铺(售刀剑)"NOR);
        set("long",
   CYN"这是一家打铁铺,屋子中心摆着一个火炉,一个中年铁匠
在满头大汗地打铁.这位扬铁匠是远近闻名的好把式,他的手艺是
祖传的,以打刀剑见长.\n"NOR
        );
        set("exits", ([
                "north" : __DIR__"xywest1",
        ]));
      set("objects", ([
                __DIR__"npc/yang": 1,
                 __DIR__"npc/huoji2": 1,
        ]));
set("no_fight",1);
        setup();
        replace_program(ROOM);
}
