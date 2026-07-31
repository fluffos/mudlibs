// Room: /city/ximenroad.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
    set("short", "西门大道");
	set("long", @LONG
这里是扬州西城门外大道。西通长安城，向东就是西门了。南边，新开了
个武道大会场，每到比武之期，人声鼎沸，你不禁想去见识一下当今的成名人
物。
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"ximen",
  		"west"  : "/d/luoyang/road1",
		"south" : __DIR__"wudao4",
	]));
        set("objects", ([
            "/d/village/npc/boy" : 3,
        ]));
	setup();
}
int valid_leave(object me, string dir)
{
	object obj;
	if (dir == "south") me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}

