 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
    set("short", "枯井底");
    set("long", @LONG
这里都是半腐烂的杂草和树叶，特别的松软，这口底就象是一个
葫芦，上面的井口特别窄小。井底很宽，因阳光的渗入，而且并不是
特别的阴暗。
LONG
        );
    set("objects",([
        __DIR__"npc/snake":1]));
    set("coor/x",-480);
    set("coor/y",-570);
    set("coor/z",-10);
    setup();
    replace_program(ROOM);
}       
