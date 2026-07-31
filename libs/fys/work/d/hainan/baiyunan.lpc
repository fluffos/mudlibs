// Room: /d/hainan/baiyunan.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "白云庵");
	set("long", @LONG
在茫茫苍苍的绿树环绕中,一座小尼庵掩映其中,显得分外淡雅清幽
走近看,门楣上挂的一块木匾已经很破旧了,但还能看出'白云'两字.尼庵
并无一点装饰,就连寻常寺庙的铁马铜铃都没挂,确显得更加飘然出尘.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road3",
  "north" : __DIR__"jingtang",
]));
create_door("north","庵门","south",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
