#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "√‘π¨≤‚ ‘ “");
    set("long", "√‘π¨≤‚ ‘ “°£\n");

  set("objects", ([ /* sizeof() == 4 */
  "/adm/fubendoor" : 1,
]));


  set("exits", ([ /* sizeof() == 1 */
//"1" : "/p/migong/boss/vrm_0000/exit",
//"2" : "/p/migong/boss/vrm_0001/exit",
//"3" : "/p/migong/boss/vrm_0002/exit",
//"4" : "/p/migong/boss/vrm_0003/exit",
//"5" : "/p/migong/boss/vrm_0004/exit",
//"6" : "/p/migong/boss/vrm_0005/exit",		  	
//"7" : "/p/migong/boss/vrm_0006/exit",	
//"8" : "/p/migong/boss/vrm_0007/exit",	
//"9" : "/p/migong/boss/vrm_0008/exit",	
//"10" : "/p/migong/boss/vrm_0009/exit",	
//"11" : "/p/migong/boss/vrm_0010/exit",	
//"12" : "/p/migong/boss/vrm_0011/entry",						
"14" : "/p/migong/boss/vrm_0013/exit",
"15" : "/p/migong/boss/vrm_0014/exit",
"16" : "/p/migong/boss/vrm_0015/exit",
]));

//    set("objects",  ([
//    ]));
set("pingan",1);
  set("valid_startroom", 1);
  set("outdoors", "/u/lywin");

  setup();
}
