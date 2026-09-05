// Room: /d/gumu/ceshi2.c
#include <room.h> 
inherit ROOM; 
 
void create() 
{ 
        set("short", "侧室");
        set("long", @LONG
        你这是一间较大的石室，约一丈高，这里有一个石座，
三尺见方，桌旁有几个木凳，靠西坐着位慈祥的老婆婆，正和蔼
地看着你。石室的北边和西边各有一个小石洞，好象里面还有几
个石室.

LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zoudao1",
  "north" : __DIR__"zoudao2",
    "east" : __DIR__"mudao2",
]));
      set("objects",([__DIR__"npc/popo":1,"/clone/armor/tiejia":1,]))
;
        set("no_clean_up", 0);

        setup();
}
/*
        int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "古墓派") && (dir == "west" || dir == "north")
            && objectp(present("sun popo", environment(me)))
            && living(present("sun popo", environment(me))))
           return notify_fail("孙婆婆喝道：你不是古墓弟子，不得入内。\n");
        return ::valid_leave(me, dir);
}
*/
