// Room: /d/snow/inn_kitchen.c
inherit ROOM;
void create()
{
        set("short", "饮风厨房");
        set("long", @LONG
这里是一间宽敞的厨房，一座大灶占据了东边半个墙壁，南边
的柜子整整齐齐地放著许多锅碗瓢盆，这里平常是相当忙碌的，如
果你要在这里东张西望的话，最好小心别被店小二端著的热汤给烫
到了，往东可以回到客栈里。
LONG
        );
 set("item_desc", ([
                "柜子": "这些柜子里放的是给客人用的碗盘碟筷，分门别类装在几个大柜子\n"
                                 "里，柜子的门都拆了，想是方便取用。\n",
                "大灶": "一座燃烧著熊熊炭火的大灶，灶口可以容纳一个汉子爬进去，不过\n"
                                 "白天炭火烧得正热，当然不会有人干这种傻事。\n"
        ]));
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"inn",
        ]));
        setup();
}
void init()
{
        add_action("do_enter", ({"enter", "climb"}));
}
        
int do_enter(string arg)
{
        if( arg != "大灶" ) return 0;
        message_vision("$N一矮身, 从大灶的灶口钻了进去.\n", this_player());
        if( this_player()->move(__DIR__"fireplace") )
                message("vision", this_player()->name() + "从外面钻了进来, 跟你挤成一团.\n",
                        environment(this_player()), this_player());
        return 1;
}       
