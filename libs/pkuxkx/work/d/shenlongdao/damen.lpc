// damen
//by kiden
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "五龙堂大门");
        set("long", @LONG
    这里是五龙堂的大门，几名弟子在这里把守，看来想见五龙使不是一件容易的事情。
西侧是黑龙堂，东侧是赤龙堂，而北面看过去似乎是一个花园。
LONG
        );
        set("outdoors", "shenlongdao");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"heilongtang",
  "east" : __DIR__"chilongtang",
  "north" : __DIR__"huayuan",
  "southwest" : __DIR__"xiaodao",  
        ]));
        set("objects", ([
              __DIR__"npc/dizi" : 2,
       ]));
        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
        if ((!myfam || myfam["family_name"] != "神龙教") && dir != "southwest"
            && objectp(present("shenlong dizi", environment(me)))
            && living(present("shenlong dizi", environment(me))))
           return notify_fail("神龙教弟子大声喝道：本教重地，外人不得入内！\n");
        return ::valid_leave(me, dir);
}
