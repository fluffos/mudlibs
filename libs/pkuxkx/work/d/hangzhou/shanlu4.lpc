// Room: /hangzhou/shanlu3.c
// hubo 2008/4/19

inherit ROOM;
#include "to_song.h"
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一条山路上，不时有些农民和猎户从你身边经过，他们唱着山歌，逍遥
快活，这条路往北通向临安府。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "northdown" : __DIR__"nanmen",
                "westup" : "/d/nanchang/milinout",    
]));
          
	set("dirs_to_song",(["south":({"lvlin","南","绿林"}),]));
	set("look_refuse_msg","这里常年有山贼出没，没事别进去。\n");
	set("look_accept_msg","这里常年有山贼出没，如果要进去就pass south。\n");
	set("accept_enter_msg","你向南面的绿林走去。\n");
	set("refuse_enter_msg","你迟疑犹豫了一下，还是不要进去为妙。\n");
	setup();
	make_entrance();
}
