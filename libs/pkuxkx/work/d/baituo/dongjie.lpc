//dongjiec
inherit ROOM;
void create()
{
        set("short", "东街");
        set("long",
             "这里是小镇的东街。南边有个打铁铺，里面不时传来丁丁当当的\n"
         "声音。东南方是一眼望不到边的荒凉的戈壁，往东北方走就出了小镇\n"
         "了。从那里可以通往山上。\n"
           );
        set("outdoors", "baituo");
        set("exits", ([
                "west" : __DIR__"xijie",
                "south" : __DIR__"datiepu",
                "southeast" : __DIR__"gebi",
                "north" : __DIR__"machehang",
        ]));
//        set("objects",([
//             "/kungfu/class/btshan/ouyangke":1,
//                      ]));
        setup();
        replace_program(ROOM);
}
