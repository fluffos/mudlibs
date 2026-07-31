inherit ROOM;

void create()
{
  set("short","茅屋大门");
  set("long",@LONG
 这里是荒郊的一处茅屋。透过墙壁可以隐隐看到一丝灯光
一扇大门(men)紧锁着,周围是高高的围墙(wall).一切都很
干净,并没有积多少灰尘。
LONG);
  set("outdoors","yinju");
 set("item_desc", ([
        "men" : "这扇门是锁着的，除非你打破(break)它。\n",
        "wall" : "墙很高，可能翻不过去(climb)。\n",
    ]) );
set("exits",([
   "west"  : __DIR__"shenglin",
   ]));
  setup();
}
void init()
{
    object me;
    me = this_player();
    add_action("do_break", "break");
    add_action("do_climb", "climb");
}

int do_break(string arg)
{
    int n;
 n = this_player()->query("neili");
    if( !arg || arg!="men" ) {
        write("不要随便打碎别人的东西！\n");
        return 1;
    }


    message_vision(
    "$N走到门前，深吸一口气，双掌同时拍出。\n", this_player());
    if (n>=200) {
        message_vision(
        "$N只听一声轰响，$N把门震开了！\n", this_player());
        set("exits/enter", __DIR__"shitu");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
   }

    return 1;
}

int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="wall" ) {
        write("不要到处乱爬！\n");
        return 1;
    }

    message_vision(
    "$N在墙前站定,深吸一口气，猛然跃起.\n", this_player());
        
    if (n>=80) {
        message_vision(
        "只见$N足尖在墙上一点,已悠然飘落院中.\n", this_player());
        this_player()->move("/d/yinju/chitang");
    }
    else if (n>=50) {
        message_vision(
        "只见$N双手在墙上一攀,勉强翻过围墙,跌落院中.\n", this_player());
        this_player()->move("/d/yinju/chitang");
    }
    else {
        message_vision(
        "$N高高跃起,可还差一大截呢,看来是轻功不够好。\n", this_player());
     }
    return 1;
}

void close(object room)
{
    message("vision","门吱呀一声又合上了,好象有鬼。\n", room);
    room->delete("exits/enter");
}