
inherit ROOM;
void create()
{
	set("short", "帅府大厅");
	set("long", @LONG
	这里是襄阳驻军的帅府,郭靖统领襄阳守军,就在这里办理军务.
     里面的人都是来去匆匆,一脸严肃的表情,各项事物井然有序.
LONG
	);

	set("exits", ([
//		"south" : __DIR__"shuaifu",
		"north" : __DIR__"sfgate"          
	]));

	set("objects", ([
		__DIR__"npc/shjiang1" : 2,
                __DIR__"npc/guojing" :1,
                __DIR__"npc/rong" :1,
        ]));
        set("no_beg", 1);
	setup();
}


