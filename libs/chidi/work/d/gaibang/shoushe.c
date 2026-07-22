//room: shoushe.c
inherit ROOM;

void create()
{
	set("short","兽舍");
	set("long", @LONG
这里是丐帮弟子的兽舍。这里豢养了各种猛兽，以供出道的丐帮
弟子使用。兽舍里猛兽长声嘶嚎，老远都听得见。尤其是夜晚听来，
更有是撕心裂肺的惨烈。
LONG );
	set("exits",([
		"east"  : "/d/city/pomiao",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/d/baituo/npc/fox" :1,
		"/d/baituo/npc/wolf" :1,
		"/d/baituo/npc/tiger" :1,
		"/d/baituo/npc/lion" :1,
	]));
	setup();
	replace_program(ROOM);
}

