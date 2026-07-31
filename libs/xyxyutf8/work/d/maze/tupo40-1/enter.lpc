#include <ansi.h>
inherit ROOM; 

void create() 
{ 
        set("short", "古蜀道口"); 
        set("long", @LONG 
蜀道难，难于上青天，走惯平坦大道的你今天才深深体会到行路的艰难，前面一条
歪歪斜斜，松松垮垮的木栈道，断断续续的通往山顶。
LONG); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_fight",1);    
        set("exits", ([
                "east" : __DIR__"maze/entry", 
                "south": "/d/shushan/road1",
        ])); 
        setup();
} 