//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
这里是一家赌场,进门你就会看见遒劲有力的四个大字
"愿赌服输".相传这是当年的"恶赌鬼"轩辕三光的大手笔。
听说这里有一个世外高人在这里开了个大场子。没钱的人
最好回家抱娃娃去。
LONG
        );

        set("exits", ([
                "west" : __DIR__"beijie2",
                "east" : __DIR__"duchang1",  
        ]));
      
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && this_player()->query("age")<18)
                return notify_fail("小娃儿家家的往里头拱啥子?!\n");
        return ::valid_leave(me, dir);
}

 
