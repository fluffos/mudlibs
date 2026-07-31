 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "莽林边缘");
        set("long", @LONG
越走树林越密，树缝中洒下来的阳光也变得斑斑点点。茅草渐厚，灌木
丛生，路径漫灭。吹来的风也越发的阴冷潮湿。远方密林的天空上有几只盘
旋的秃鹰，发出撕心裂肺的叫声，令人毛骨耸然。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"groups4",
  "southup" : "/d/baiyun/woodsroad",
]));
        set("outdoors", "manglin");
        set("NONPC",1);
        set("coor/x",10);
        set("coor/y",-600);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}
