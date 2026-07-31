
inherit ROOM;


void create()
{
		set("coor",({-25,-50,5}));
	set("short", "淳风武馆二楼");
		set("long",
"这里是淳风武馆二楼，你在这里可以闻到一股浓郁的檀香，楼下的出口通往大厅,从这里可\n"
"以欣赏风云城的全境。\n"
);
		set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"innerhall",
		]));

		set("item_desc", ([
				"bell": "别碰哦。\n"
		]) );


		setup();
		set("no_clean_up", 0);

}

