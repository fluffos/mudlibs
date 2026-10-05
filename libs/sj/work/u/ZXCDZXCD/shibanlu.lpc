#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "石板路");
    set("long", @LONG
一条平整宽阔的石路,路的两边古松参天,面前的路是越来越宽阔.
从这里向远处看,在对面的山峰上有个神兽王的大雕像,看上去似
天神一般威武.凡是路过此地的兽族勇士们必须向他磕三个头.
在路的尽头是一座金碧辉煌的宫殿,看来你快到兽王神殿了.
LONG);
    set("exits", (
     "south" : __DIR__"gate",
     "north" : __DIR__"tianxinchi",
    ]));
 set("objects", ([   "/kungfu/class/shouzu/yongshi": 3        ]));
    setup();
    replace_program(ROOM); 
}
