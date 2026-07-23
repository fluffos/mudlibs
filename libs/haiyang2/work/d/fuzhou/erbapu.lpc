// Room: /d/fuzhou/fzroad1.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "武夷山道");
	set("long", @LONG
    你走在窄窄的武夷山小道上，山路崎岖，密林森森，常有长
虫野兽出没。所谓“闽道更比蜀道难”，诚不相欺。西面隔着崇
阳溪，就是奇秀甲于东南的武夷山了。
LONG );
	set("exits", ([
		"north"     : __DIR__"fzroad1",
		"southdown" : __DIR__"fzroad2",
		"west"      : __DIR__"kedian",
	]));
        set("objects", ([
		"/d/huashan/npc/haoke" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

