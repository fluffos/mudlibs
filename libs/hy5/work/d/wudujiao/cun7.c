// Room: /u/star/cun7.c
// star 1998/12/04 亮晶晶版权所有，请勿随意修改传播


inherit ROOM;

void create()
{
	set("short", "小村");
	set("long", @LONG
走在小村的石板路上，两旁都是用青石砌成的房屋。东边有一座学堂，
里面传来朗朗的读书声。 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"northwest" : __DIR__"cun5",
		"southeast" : __DIR__"cun8",
		"southwest" : __DIR__"cun6",
		"east" : __DIR__"minju7",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

