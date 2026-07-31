// road3.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "黄土路");
	set("long", @LONG
你走在一条黄土路上。西面望去，隐隐可以看到平定州。望
东，北京城快到了。
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
                "northwest" : "/d/beijing/ximenwai",
                "east" : "/d/cangzhou/sancakou",
                "west" : __DIR__"pingdingzhou",
"north" : "/d/beijing/was/road1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
