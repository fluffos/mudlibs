//changlang.c

inherit ROOM;
void init();
void create()
{
        set("short", "走廊");
        set("long", @LONG
一条宽阔的长廊，四周没有什么饰物，光滑的石壁上有着一些天然的
纹理，时而有一些浣花剑手匆匆走过，东面通往浣花剑派的祠堂。
LONG
        );

        set("exits", ([
              "north" : __DIR__"xiuxishi",
                "east" : __DIR__"jiashan",
                "west" : __DIR__"changlang2",
                ]));
        set("no_clean_up", 0);
        set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "浣花剑派" ) && dir == "north" )
               return notify_fail("你不是浣花剑派的弟子，跑进去干嘛？\n");
                
        return ::valid_leave(me, dir);
}


