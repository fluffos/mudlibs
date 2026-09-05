//Made by goodtaste
//wanluntai.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",YEL "万纶台" NOR);
        set("long", @LONG
        杀手帮万纶台，是杀手帮处理大小事物的地方，这里的总管是梁柳鹤，有什么事就多向他打听
LONG
        );
        set("outdoors", "pker");
        set("exits", ([
                "south" : "/adm/npc/shanmen",
                "north" : __DIR__"shijie1",
                "west" : __DIR__"fanting",
              ]));
          set("objects", ([
         
                   __DIR__"npc/liangliuhe" : 1,
                   __DIR__"npc/dizi" : 3,
           ]));
        setup();
       
}

int valid_leave(object me, string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
    if(dir=="north" && me->query_temp("face_zhu") != 1
    && me->query_temp("pkallowenter") !=1
    && objectp(present("liang liuhe", environment(me)))
    && living(present("liang liuhe", environment(me)))
    && !me->query("accomplish1") && !me->query("accomplish2"))
        return notify_fail("你的经验不够，还是不要进去的好。\n");
    return ::valid_leave(me, dir);
}
