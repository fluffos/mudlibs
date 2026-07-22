inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
    你走在西大街上，感到这里的街面要比别处的干净、整洁。大概因
为靠近衙门、兵营可受保护的缘故，富人们都喜欢住在这里。东边静悄悄地
没有几个行人，西边是西城门通往郊外。南边是玄妙观，北边是一个书堂。
LONG
	);
        set("outdoors", "苏州");
	set("objects",([
		NPC_D("girl") : 1,
	]));
	set("exits", ([
		"east" : __DIR__"xidajie1",
		"south" : __DIR__"xuanmiaoguan",
		"west" : __DIR__"westgate",
		"north" : __DIR__"shuchang",
	]));
	set("incity",1);
	setup();
}
