// Room: /d/diaoyudao/zhangqian.c 帐前
// hongdou 98.09.20

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "帐前");
	set("long", @LONG
你靠近大帐，面前的帐子气魄宏伟，显然是主帅的中军大帐，外表
看来大帐受损不是很严重，仍能够居住。隐约听到帐里有声响，不知有
什么在里面。帐外门口有一根旗杆，上面挂着一面旗子。
LONG
	);
	set("objects", ([
        	__DIR__"obj/qigan":1,
         ]) ); 
	
	set("exits", ([
                 "west" : __DIR__"kongdi",
		 "northeast" : __DIR__"zhangout",
		 "south": __DIR__"junying1",
		 "enter": __DIR__"dazhang",
	]));

	set("outdoors", "diaoyudao");
	setup();
        replace_program(ROOM);
}
