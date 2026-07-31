 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "东南角");
        set("long", @LONG
洞顶很低，钟乳石相当的多，形成一片石林。石林中还有几
株紫蘑。紫蘑旁边居然有几张石凳和一张石台，可以供人休息。
洞顶一直在滴水，弄得这里似乎总是在下雨。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"ntdm",
                "west" : __DIR__"tdnd",
        ]));
    set("objects", ([
        __DIR__"npc/dinggan": 1,
    ]) );
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-24);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object obj, string dir){
        object ma;
        if(dir == "west"){
                if(obj->query_temp("marks/underground_gao")){
                        return 1;
                }
                if(!obj->query("vendetta/authority") && present("ding gan", this_object())){
                        ma = present("ding gan", this_object());
                        return notify_fail("你没看到"+ma->name()+"身形移动，然而他却站在你身前挡住了你的路。\n");
                }
        }       
        return 1;
} 
