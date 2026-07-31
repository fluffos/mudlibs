// xiaoxuan.c 黄河小轩
// by chenww

inherit ROOM;

void create()
{
        set("short", "黄河小轩");
        set("long", @LONG
房虽草覆，却高爽宽敞，窗台明亮。堂中挂一幅无名小画，设一张白木
卧榻。桌凳之类，色色洁净。打扫得地下无纤毫尘垢。堂中花卉无所不有，
十分繁茂。真个四时不谢，八节长春。
LONG
        );
        set("exits", ([
                "south" : __DIR__"tingyulou",
             "west" : __DIR__"chashi",
		"east" : __DIR__"jianshi" ,
        ]));
        set("objects", ([
                __DIR__"npc/xiaomeng" : 1,
                       ]));
        set("outdoors", "huanhua" );

        set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
