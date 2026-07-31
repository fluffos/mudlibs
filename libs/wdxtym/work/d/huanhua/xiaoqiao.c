//bridge.c

inherit ROOM;

void create()
{
        set("short", "小桥");
        set("long",
             "这是一座小竹桥，一条清澈的小溪从桥下缓缓流过。\n"
            "不时有顽皮的小鱼跃出水面，在阳光下划出一条银白色的弧线。\n"
        );
        set("outdoors", "huanhua");
        set("exits", ([
"northwest" : "/d/heimuya/changtan",	
                "east" : __DIR__"podi",
        ]));
        set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
