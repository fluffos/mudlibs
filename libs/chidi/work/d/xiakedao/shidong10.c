// shidong10.c 石洞

inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", @LONG
这是一个石室，隐约可以感觉到四周是冰冷而坚硬的石壁，石
洞内干干净净，一尘不染。
LONG );
        set("exits", ([
               "east" : __DIR__"shidong9",
               "out"  : __DIR__"dating",
        ]));
        set("objects", ([
               __DIR__"obj/baihongjian" : 1,
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out")
            tell_object(me,"你走出了石洞，神秘地出现在大厅之中。\n");
        return ::valid_leave(me,dir);
}

