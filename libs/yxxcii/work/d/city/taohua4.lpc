// taohua4.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃花村");
	set("long", @LONG
进了桃花谷便是桃花村。世外的感受，让你陶醉这山野的风、山间的
春泥味、山村的直朴、村民的宽容、山里的桃花、桃花溪的少女，让你不
会再去想尘世的名利、江湖的血腥、人心的险恶。你尽可忘了一切，来凝
望桃花村碧蓝的瓦、彤红的墙。
LONG
);
	set("outdoors", "city");
	set("objects", ([
		__DIR__"npc/cunzhang" : 1,
	]));
	set("exits", ([
		"southdown" : __DIR__"taohua3",
		"north"	 : __DIR__"taohua5",
	]));
	setup();
	replace_program(ROOM);
}
