#include <ansi.h>
inherit ROOM; 

void create() 
{ 
        set("short", "茫茫雪岭"); 
        set("long", @LONG 
北风呼啸，飞雪茫茫，四面望去均是绵延不尽的雪峰。天地之间似已毫无生迹，除
了雪还是雪。

LONG); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_fight",1);    
        set("exits", ([
                "east" : __DIR__"maze/entry", 
                "south": "/d/xueshan/xueshan1",
        ])); 
        setup();
} 