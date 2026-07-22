// Room: menlang.c 门廊

inherit ROOM;

void create()
{
	set("short", "门廊");
	set("long", @LONG
这里是衙门的门廊，这里平常没什么人，两旁摆放着许多肃静回避牌，以
及知府日常出行用的仪仗。东边有间屋子，里面偶尔传来几句说话声，好象有
什么人在聊天。
LONG
	);

	set("exits", ([
		"east" : __DIR__"banfang",
		"south" : __DIR__"yamen",
		"north" : __DIR__"ymzhengting",
		
	]));
	set("objects", ([
        	__DIR__"npc/yayi" : 2,
	]));

	set("incity",1);
	setup();
}