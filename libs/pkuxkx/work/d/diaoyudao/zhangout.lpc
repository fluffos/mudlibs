// Room: /d/diaoyudao/zhangout.c 帐外
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "帐外");
	set("long", @LONG
你绕到了大帐旁外，这里堆放着木柴，看来是生火做饭用的，靠
近大帐有一口水缸，里面盛满了清水，大概是从不远的小溪边挑
来的。帐后有一大片营地。
LONG
	);

	set("resource/water", 1);
	set("exits", ([
                 "northwest" : __DIR__"zhanghou",
		 "southwest" : __DIR__"zhangqian",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

