// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "窦大夫祠");
	set("long", @LONG
窦大夫祠在太原西北20里上兰村，汾河峡谷左侧.祠内古柏苍翠。
晋国大夫窦犨封地太原，曾开渠兴利，后人在此立祠祀奉。历代都留
有碑记。现存山门、献亭、大殿等都是元至正三年(1343年)重建，局
部还保留宋金时期风格。其中献亭甚大，后檐柱，用大殿明间廊柱代
替，结构简练而严谨，为金元建筑中所罕见。祠旁清泉自烈石山苍崖
下涌出，水温较低，人称“寒泉”。“烈石寒泉”为太原名胜之一。
LONG );
	set("exits", ([
//		"east"  : "/d/leshou/road4",
 		"northwest"  : __DIR__"road6",
//		"southwest"  : "/d/xucheng/dadao12",
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



