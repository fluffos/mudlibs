// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "神风堂大厅");
	set("long", "这里是神风堂大厅，四周墙上挂了不少名人字画，大厅中
央一张八仙桌边不少神风堂弟子在聚会交流江湖上的人文逸事。
北边是神风堂咨询厅，往南就到了金钱厅，去西边就是神风飘
云，西南是神风堂堂主的私人卧室。\n");

	set("exits", ([
                "north" : __DIR__"zxt",
		"south" : __DIR__"jqt",
                "west" : __DIR__"ft2",
                "east" : __DIR__"ft",
                "southwest" : __DIR__"ws",

	]));
	setup();
	replace_program(ROOM);
}

