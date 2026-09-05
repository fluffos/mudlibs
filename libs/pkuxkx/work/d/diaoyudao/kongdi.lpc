// Room: /d/diaoyudao/kongdi.c 空地
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
你昏昏然走出了树林，来到一大片空地，不远处似乎有许多大大小小的
帐篷。难道这里还有人居住？恐怕是倭寇吧？你有些踌躇不前。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"zhangqian",
                 "west" : __DIR__"shulinout",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

