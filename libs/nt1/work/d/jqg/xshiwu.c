//xshiwu.c 小石屋
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小石屋");
	 set("long",@LONG
这是一座小石屋，四围是用大石块砌起来的。地上胡乱铺着几张草席，墙
角放着一张桌子，看上去破烂不堪，桌上放着几只破碗。
LONG
);
         set("sleep_room",1);
	 set("no_fight",1); 
	 set("exits",([
               "east": __DIR__"shanding",
         ]));
         
         setup();
	 replace_program(ROOM);
}
