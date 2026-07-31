#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "天梯尽头");
    set("long", @LONG
这里有两扇门，一扇（door1）通向外面，是活路；还有一扇（door2）门是死
路—门外就是看不见底的万丈探蹦，只要一脚踏下，就万劫不复了！没有人知道哪
扇门外是活路。你可以自己选择去开门，但只要一开了门，就非走出去不可，不能
后悔了。
LONG
        );
    set("exits", ([ /* sizeof() == 0 */
        "down" : __DIR__"tianti3", 
        ]));
    set("item_desc", ([
        "door1":
        "两扇门几乎是完全一模一样的，没有人能看出其间的差别。生与死的差别。\n",
        "door2": 
        "两扇门几乎是完全一模一样的，没有人能看出其间的差别。生与死的差别。\n",
        ]) );
    set("coor/x",3310);
    set("coor/y",20);
    set("coor/z",20);
    setup();
} 
void init()
{
    add_action("do_open", "open");
    add_action("do_noregret", "noregret");
    add_action("do_say", "say");
    add_action("do_regret", "regret");
    remove_call_out("give_hint");
    call_out("give_hint",5,this_player());
} 
void give_hint(object who)
{
    if(present(who)) message_vision(HIY"
面对这生死的选择，你不禁想起你的一生，你曾经爱过的人和你的朋友们。
作了选择后，你会后悔吗？"NOR"\n",who);
}
                  
int do_open(string arg)
{
    if( arg == "door1" || arg == "door2")
    {
        message_vision(HIB"$N推开了门，失足掉入了万丈深渊，在离开这个世界的 
一刹那间，$P的眼前又浮现出最心爱的人的笑容...  \n"NOR, this_player());
        this_player()->die();
        return 1;
    }
    return 0;
} 
int do_say(string arg)
{
    object room;
    if( arg == "我来过，活过，爱过！" || arg == "我绝不后悔！" ||
        arg == "I won't regret!" || arg == "我总算已想通了。"||
        arg == "活过爱过已足够。")
    {
        message_vision(HIY "$N随手推开了一扇门，眼前现出灿烂无比的夕阳... \n"
                      NOR, this_player());
        room = load_object(__DIR__"anbian1");
        this_player()->move(room);
        return 1;
    }
    return 0;
} 
int do_noregret(string arg)
{
    object room;
    tell_object(this_player(),HIW"不，我不会后悔的！我来过，活过，爱过！这已经足够了。"NOR"\n");
    message_vision(HIY "$N随手推开了一扇门，眼前现出灿烂无比的夕阳... \n"NOR,
                   this_player());
    room = load_object(__DIR__"anbian1");
    this_player()->move(room);
    return 1;
} 
int do_regret(string arg)
{
    tell_object(this_player(),HIW"我一定要小心，这世界上还有太多的事我没有做完。"NOR"\n");
    return 1;
}     
