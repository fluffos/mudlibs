// tzhroad11.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "村庄的东边");
	set("long", @LONG
     这里是东街的尽头。人很少。只有几个三姑六婆在聊天。北面是去铁
掌帮的路。南面是一间比较大而且很漂亮的房子，里面住着这条小村庄最有钱财
主张八爷。屋子里面不时传出狗叫声。西面是村庄的中心。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"south" : __DIR__"caizhu1",
	                  "west" : __DIR__"tzhroad10",
                                     "north" : __DIR__"tzhroad8",
	]));

	setup();
	replace_program(ROOM);
}

