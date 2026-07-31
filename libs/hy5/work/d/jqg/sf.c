// Room: /u/dubei/u/gumu/jqg/sf
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是公孙止的书房，书架上放着一些武林秘籍，一般很少
有人能够进来。
LONG
	);

	set("exits", ([
 
                "south" : __DIR__"sqx",
	]));
 

  
	setup();
	replace_program(ROOM); 
}

