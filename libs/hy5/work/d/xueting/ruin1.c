// Room: /d/snow/ruin1.c
#include <localtime.h>
inherit ROOM;
int flag = 0;
void create()
{
        set("short", "破旧大宅");
        set("long", @LONG
这里是一间破旧大宅的前院，大厅已经崩塌了一半，焦黑的梁
柱挡住了你的去路，庭院里杂草丛生，看来已经很久没有人住了，
据说这里晚上有鬼魂出现，但是倒也从没听说过有人被害。因此附
近的居民仍然照常生活，往西可以经由大宅的正门回到街上。
LONG
        );
       set("item_desc", ([ /* sizeof() == 2 */
                "杂草": "这里的杂草已经足足有及腰的长度了，你忽然发现南边的草丛有什
麽东西发出金属的闪光，不过也有可能是你的错觉。
",
                "梁柱": "从梁柱焦黑的痕迹来看，这座大宅的主人大概是因为火灾的关系才
离开的吧。
",
]));
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"lane1",
]));
        setup();
}


void init()
{
        add_action("do_climb", "climb");
      //  add_action("do_search", "search");
}
int do_climb(string arg)
{
        if( arg == "梁柱" )
        message_vision("$N小心翼翼地爬过坍塌的梁柱进入大厅。\n", this_player());
        this_player()->move(__DIR__"ruin2");
        message("vision", this_player()->name() + "从坍塌梁柱的另一头爬了过来。\n",
                environment(this_player()), this_player());
        return 1;
}
/*
int do_search(string arg)
{
        mixed t;
        object ob;
        if( arg == "杂草" ){
        t = NATURE_D->game_time(1);
        // Can only be found during 11:00 to 14:00
        if( flag || (t[LT_HOUR] < 10) || (t[LT_HOUR] > 13) ) {
                message_vision("$N在杂草丛里找来找去，但是什麽也没有找到。\n", this_player());
                return 1;
        }
        flag = 1;
        ob = new(__DIR__"/npc/obj/hairpin");
        ob->move(this_player());
        message_vision("$N在草丛里找来找去，结果发现了一支发簪！\n", this_player());
        return 1;}
        message_vision("$N找来找去，但是什麽也没有找到。\n", this_player());
        return 1;
}
void reset()
{
        flag = 0;
        ::reset();
}
*/