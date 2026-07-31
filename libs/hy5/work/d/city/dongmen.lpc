// Room: /city/dongmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "广储门");
	set("long", @LONG
这是东城门，城门正上方刻着“广储门”三个楷书大字，城墙上贴
着几张官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心
为妙。一条笔直的青石板大道向东西两边延伸。东边是郊外，隐约可见
一片一望无际的树林，神秘莫测。北面有一片茂盛的青竹林。南面是一
大片的草地，西边是城里。
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/taishan/yidao",
		"north" : __DIR__"ml1",
		"south" : __DIR__"jiaowai1",
		"west" : __DIR__"dashidongjie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

