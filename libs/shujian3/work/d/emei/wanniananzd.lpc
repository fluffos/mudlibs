// Room: /d/emei/wanniananzd.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "万年庵砖殿");
	set("long", @LONG
这里是万年庵的拱顶无梁砖殿。砖殿四壁为正方形，顶为穹窿圆拱形，殿
内有普贤菩萨骑六牙白象的铜铸像一尊。拱顶无梁砖殿四壁下方，有小龛二十
四个，内各供铁铸佛像一尊。四壁上方则有横龛六道，列置铜铸小佛三百零七
个。
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"chanfang3",
  "out" : __DIR__"wannianan",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-kong" : 1,
		CLASS_D("emei") + "/wen-fang" : 1,
]));
create_door("east", "小门", "west", DOOR_CLOSED);
	setup();
}
