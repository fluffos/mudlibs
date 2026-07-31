// Room: /d/5lt/mianbaowu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "面包屋");
	set  ("long",  @LONG
这是一家面包屋。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"nroad1",
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -160);
	set("coor/y", 15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
