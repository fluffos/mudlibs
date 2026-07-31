// sanqingdian.c 三清殿
inherit ROOM;

void create()
{
	set("short", "三清殿");
	set("long", @LONG
这里是凌霄宫的三清殿，是武当派会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着几
个蒲团。东西两侧是走廊，北边是练武的广场，南边是后院。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"houyuan",
		"east"  : __DIR__"donglang1",
		"west"  : __DIR__"xilang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/guxu" : 1,
		CLASS_D("wudang") + "/song" : 1
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (dir == "north" ||
	    ! objectp(guarder = present("song yuanqiao", this_object())) ||
	    ! living(guarder))
		return ::valid_leave(me, dir);

	return guarder->permit_pass(me, dir);
}

