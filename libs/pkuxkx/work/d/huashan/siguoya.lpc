// Room: /d/huashan/square.c

inherit ROOM;

void create()
{
        set("short", "思过崖");
        set("long", @LONG
这里在华山后山，名为「思过崖」。通常华山弟子犯了大错
将到此思过，外人无法进入。崖上三面是悬崖，只有西边有一条
小路。你仔细一看发现路边有个山洞。崖上有一人正在低着头发
呆。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"xiaolu4",
        ]));
        set("objects", ([
                "/kungfu/class/huashan/linghu" : 1 ]));
        set("no_hsnewbiejob",1);
        set("item_desc", ([
                "山洞": "那是一个山洞，里面黑乎乎的。\n"
        ]) );
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
        object me;
        me = this_player();
        if( me->query_temp("marks/风1") ) {
                message("vision",me->name() + "向崖边山洞钻了进去。\n",
                environment(me), ({me}) );
                me->move("/d/huashan/siguoyahoudong");
                message("vision",me->name() + "钻进崖边的山洞。\n",
                environment(me), ({me}) );
                return 1;
                }
        else {
                write("那个山洞黑乎乎的，看来还是不进去的好。\n");
                return 1;
                }

}
