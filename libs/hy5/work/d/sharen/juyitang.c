 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "聚义堂");
        set("long", @LONG
这本来是聚义庄的聚义堂，不过随着主人家的衰败，
这里只留下一些没人带走的朽木梁柱。不过，现在整个大
厅已经重新收拾过，白布缠梁，白纱盖柱，大厅的当中，
是一个简单庄重的灵位，许多江湖人的挽联花圈挂在四周。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"qyuan",


   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 1,
        __DIR__"npc/bandit2" : 1,
        __DIR__"npc/bandit3" : 1,
        __DIR__"npc/bandit4" : 1,
        __DIR__"npc/bandit5" : 1,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-5);
        setup();
                replace_program(ROOM);

} 