// gebi5.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","西域大戈壁");
       set("long", @LONG
这是西域的大戈壁，要走出这里并非易事。不远处尘土沙粒铺天盖
地般吹来，看来要起风暴了。
LONG);
        set("exits", ([
                "north" : __DIR__"gebi2",
                "south" : __DIR__"gebi3",
                "east" : __DIR__"gebi4",
                "west" : __DIR__"gebi1",
        ]));
        set("outdoors", "gaochang");
        setup();
}

void init()
{
       object me = this_player();
       switch(random(4)) {
       case 0 : me->set_temp("gc_n",1); break;
       case 1 : me->set_temp("gc_s",1); break;
       case 2 : me->set_temp("gc_e",1); break;
       case 3 : me->set_temp("gc_w",1); break;
       }       
       if(me->query_skill("dodge", 1) <= 150) 
            me->add("jingli", -15);
       else me->add("jingli", -5);
}