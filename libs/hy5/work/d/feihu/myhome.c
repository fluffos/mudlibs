// myhome
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "萧然居");
	set("long", @LONG
        这是一间很小的房子,房里的家具都用粗木制成,却显得大气异常。
屋中有一个年轻人，很舒服的坐在一张宽大的椅子上，身前生着一个大火
炉，手中持着一个碧绿的酒杯，脸上带着满不在乎的笑意。
LONG
	);
      //set("no_fight",1);
      set("exits", ([
		"west" : __DIR__"iceroad5",
			]));
      set("objects",([
          __DIR__"npc/me":1,
    ]) ); 
	setup();
	replace_program(ROOM);
}

