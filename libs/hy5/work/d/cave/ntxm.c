 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "水牢");
        set("long", @LONG
青龙地城中暗河水道星罗密布，而据说这赤水一旦搀杂了某
样东西，便会变成天下至毒至腐的黑水，而青龙会凭此秘方，在
江湖中数次与各大名门血战中取得上风，而在地城中这依河而建
的这间黑水牢，更是被青龙会擒来的各派弟子的鬼门关。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ntxl",
//  "south" : __DIR__"xnj",
]));
        set("indoors", "cave");
        set("coor/x",-60);
        set("coor/y",-50);
        set("coor/z",-20);
        set("objects", ([
        __DIR__"npc/guard2": 1,
                        ]) );
        setup();
        replace_program(ROOM);
}      
