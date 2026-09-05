inherit ROOM;
void create()
{
        set("short", "农舍");
        set("long",
             "这里是一间小农舍，家具看起来很新的样子。看来主人比较富裕。\n"
 //        "一条小狗在脚底下跑来跑去，很有意思！\n"
        );
        set("exits", ([
                "west" : __DIR__"guangchang",
        ]));
        set("objects",([
                __DIR__"npc/woman" : 1,
 //               __DIR__"npc/dog"   : 1, 
        ]));
        setup();
        replace_program(ROOM);
}
