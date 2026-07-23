 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "土路");
        set("long", @LONG
荒原上的一段蜿蜒曲折的土路，伴随一条默默的溪流（ＲＩＶＥＲ），
清澈的溪水，使人感到一股清新气息。周围群山起伏，碧水蜿蜒，风光秀丽。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"hongshan",
  "south" : __DIR__"beimen",
]));
        set("objects", ([
        __DIR__"npc/baiyi" : 1,
        "/d/zangbei/npc/xuedahan" : 1,
                        ]) );

        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","清澈的溪水");
        set("liquid/container", "溪流");
        set("coor/x",-1120);
        set("coor/y",2120);
        set("coor/z",0);
        setup();
} 

