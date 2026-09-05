// Room: /d/quanzhou/wuminggudi.c
// By Eric 96.9.25 

inherit ROOM;

void create()
{
    set("short", "无名谷底");
    set("long", @LONG
这里是一个山谷的底部，不时传来一阵雕鸣，声音微带嘶哑，但激越苍
凉，气势甚豪，谷中淡淡地飘来一阵湿气，一股水流由北面流下来。
    北面是个山坡，东面是有一个阴阴森森的洞穴，西边是一座小茅屋。
LONG
    );
    set("outdoors", "quanzhou");

    set("exits", ([
	"east" : __DIR__"huanggu",
	"west" : __DIR__"sheku",
	"southup" : __DIR__"nanhu",
	"northup" : __DIR__"caocong",
    ]));
                                                    
    set("objects", ([
        __DIR__"npc/choudiao" : 1]));

    
    setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northup" && objectp(present("chou diao", environment(me))))
                return notify_fail(
"丑雕神情冷漠地拦住了你的去路。\n");
	if ( dir == "northup" ) 
		return notify_fail(
"面前是一片齐腰高的草丛，你犹豫了一下，退了回来。\n");
        return ::valid_leave(me, dir);
}



