
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵入口");
	set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。往北是一片桃
花林，往南则是一个小亭子。
LONG );
       set("exits", ([
	   "south" : __DIR__"tao0",
	   "north" : __DIR__"haitan",
       ]));
       set("objects", ([
	   CLASS_D("taohua")+"/feng" : 1,
       ]) );
    
       set("outdoors","taohua");
       setup();
       //replace_program(ROOM);
}

