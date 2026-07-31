//changlang2.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
一条宽阔的长廊，四周没有什么饰物，光滑的石壁上有着一些天然的
纹理，时而有一些浣花剑手匆匆走过，东面通往浣花剑派的祠堂。
LONG
        );

        set("exits", ([
                "east" : __DIR__"changlang",
            "south" : __DIR__"shanshiting",
                "west" : __DIR__"changlang3",
                ]));

        set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
