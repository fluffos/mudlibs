#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "花园");
        set("long", @LONG
这是一座极大的花园，四面群山围绕，园中万花竞艳。牡丹芍药，黄菊
红玫，四季香花，在这地竞同时开放，抬眼望去，宛如置身一片香涛花海之
中。白石小径，青竹篱笆间，零乱地站了十余个红衣少女，正在剪草灌花。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"garden",
  "east" : __DIR__"valley",
]));
        set("objects", ([
        __DIR__"npc/whitewoman" : 1,
                        ]) ); 
        set("outdoors","palace");
        set("coor/x",270);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
        replace_program(ROOM); 
}     
