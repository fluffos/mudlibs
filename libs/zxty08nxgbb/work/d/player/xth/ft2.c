// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "神风飘云");
	set("long", "这里是神风堂堂主和堂子弟子开会讨论江湖大事的地方。
正中间一张太师椅是堂主的位置，两边是两排弟子坐的椅子。
房间两边还放着兵器架，架上的兵器正闪着寒光。从这儿出去
就是神风堂大厅了。\n");

	set("exits", ([
                "east" : __DIR__"ft1",

	]));
	setup();
	replace_program(ROOM);
}

