//Cracked by hotjc
//yuchun.c

inherit ROOM;

void create()
{
        set("short", "太湖渔村");
        set("long", @LONG
这里是太湖渔村，极目望去，不远处可见烟波浩渺，远水接天。这里
祗有寥寥几户人家，不远处泊着一些渔船。
LONG
        );
         set("exits", ([
                "east" : "/d/murong/matou",
                "west" : "/d/taihu/taihu2",
        ]));
        set("objects", ([
		"/kungfu/class/murong/boe" : 1,
		]));

        setup();
}
