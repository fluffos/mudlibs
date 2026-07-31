// ROOM:__DIR__"canyon4"

#include <ansi.h>

inherit ROOM;
void create()
{
        set("coor",({-300,4250,0}));
	set("short","隘口中道");
	set("long",
"来到这里，风势比其他地方大了许多，或许是因为东边为军营入口通风较为良好的原因，南\n"
"方一十里路的地方就是京城关口－雁门关的入口，在西边的山壁似乎过于平滑，不太自然，\n"
"或许这里有什么秘密也说不定。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==3 */
        	"north" : __DIR__"canyon3",
        	"south" : __DIR__"canyon5",
        	"east" : __DIR__"camp1",
          //"west" : __DIR__"blackmarket",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
} //EOF


