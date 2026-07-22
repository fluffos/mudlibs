inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long",@LONG
阿熏常来练习剑术的地方。四周的木人成品字形摆放着，大概是用
来练习以寡敌众用的吧。
LONG
);
	set("outdoors", "feitian");
	set("exits", ([
		"southwest" : __DIR__"xiangfang",
                        "southeast" : __DIR__"huayuan",
	]));
	set("objects",([
		__DIR__"npc/muren" : 6,
	]));
	setup();
	replace_program(ROOM);
}