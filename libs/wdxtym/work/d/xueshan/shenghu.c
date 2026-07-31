//      shenghu.c 圣湖
inherit ROOM;

void create()
{
	set("short", "圣湖");
	set("long", @LONG
眼前就是著名的圣湖，碧蓝的湖面倒影着蓝天和白云，
浩淼的水面让人心旷神怡。远处金碧辉煌的雪山寺清晰可
见，再远处是几座延绵的大雪山，其中最高大的是神山，
相传山中有神仙居住。雪山中融化的雪水都汇入湖中。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"tulu3",
		"east"  : __DIR__"hubian1",
	]));

	set("outdoors", "xueshan");

	setup();
}

int valid_leave(object me, string dir)
{
	if (! playerp(me))
		return ::valid_leave(me, dir);

	if (random(3))
	{
		write("你突然发现眼前的景象有些迷乱。\n");
		return -1;
	}
	return ::valid_leave(me, dir);
}
