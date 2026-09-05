// Room: /city/beimen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
这是扬州的北城门，因为曾经失火，到现在城墙还是黑乎乎的，因此白纸黑
字的官府告示(gaoshi)就显得特别显眼。北方是一片崇山峻岭，一条黄土小径在
山里蜿蜒而上。
LONG);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"south" : __DIR__"beidajie2",
		"north" : "/d/village/hsroad1",
	]));
        set("objects", ([
		__DIR__"npc/wujiang1"+random(2) : 1,
                __DIR__"npc/bing" : 2,
        ]));
	set("outdoors", "city");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}