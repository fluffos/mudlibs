// guiyunzhuang/mafang.c 马房

inherit ROOM;

void create()
{
         set("short", "马房");
        set("long", @LONG
这是[归云庄]的马房，是陆庄主平时外出备马的地方。
一位御马翁在此管马。
LONG);
         set("exits", ([ /* sizeof() == 1*/
         "west" : __DIR__"zoulang4",
                          ]));
	set("objects",([__DIR__"obj/maxue":1,
	__DIR__"npc/horse":1,
	__DIR__"npc/yumaweng":1,	
	]));
	set("no_fight",1);
	set("no_magic",1);
	set("hsz_no_task",1);
	setup();
}
