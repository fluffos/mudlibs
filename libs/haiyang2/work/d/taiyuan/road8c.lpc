// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条大路。路边是一排排笔直的白杨树。西面是银川府，这
里已经进入了回民集中居住的地方，路上不时的能见到头戴白帽，蓄着
山羊胡子的回人。
LONG );
	set("exits", ([
		"northwest"  : __DIR__"yinchuan",
 		"east"  : __DIR__"road8b",
///		"southwest":"/d/changan/shandao3",
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



