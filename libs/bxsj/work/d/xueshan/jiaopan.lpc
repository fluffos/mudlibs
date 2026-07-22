// Room: jiaopan.c 绞盘

#include <ansi.h>

#define SHIP_TO __DIR__"hubian"

inherit ROOM;

void create()
{
        set("short", "绞盘");
        set("long", @LONG
面前是个方圆几十丈的平台。是借着山势，经过人工开凿而成的。平台边
建造了一个大绞盘，绞盘绳子一端连着个巨大的藤筐(tengkuang)。 一个高大
的番僧(fanseng)走来走去，指挥着众人。
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"houzidong",
        ]));

        set("item_desc", ([
          "tengkuang" : "这个巨大的藤筐看来进去四、五个人不成问题，筐外被儿臂粗的麻绳紧紧箍住。\n",
          "fanseng" : "他满脸横肉，因为常年风吹日晒，脸色红里透黑。衣衫单薄，在寒冷的山风中却显的毫不在乎。\n" +
                      "和他打个招呼(zhaohu)就可以把你送下山。\n"
        ]));

        set("outdoors", "雪山");
        set("coor/x",-250);
  set("coor/y",150);
   set("coor/z",20);
   setup();
}

void init()
{
        add_action("do_zhaohu", "zhaohu");
}

void check_trigger(object me)
{
        object room;
        object thisroom = this_object();

        if(!query("exits/enter") ) {
                if( !(room = find_object(__DIR__"tengkuang")) )
                        room = load_object(__DIR__"tengkuang");
                if( room = find_object(__DIR__"tengkuang") ) {
                        if((int)room->query("yell_trigger")==0 ) {
                                room->set("yell_trigger", 1);
                                set("exits/enter", __DIR__"tengkuang");
                                room->set("exits/out", __FILE__);
                                message("vision", "番僧把麻绳理顺，将藤筐扶稳后边道：好啦，上去吧。\n", thisroom);
                                message("vision", "番僧把麻绳理顺，将藤筐扶稳后边道：好啦，上去吧。\n", room);
                                remove_call_out("on_board");
                                call_out("on_board", 15, me);
                        }
                        else
                                message("vision", "番僧点了点头说道：现在正在载人，你等下一拨吧。\n", thisroom);
                }
                else
                        message("vision", "ERROR: Tengkuang Not Found\n", thisroom);
        }
        else 
                message("vision", "番僧点了点头道：正好，筐正要放下去，你快进去吧。\n", thisroom);
}

void on_board(object me)
{
        object room;

        if( !me || !query("exits/enter") ) return;

        message("vision", "番僧用力一推，将藤筐推离平台，绞盘跟着慢慢放松，藤筐一荡，降了下去。\n", this_object());

        if( room = find_object(__DIR__"tengkuang") )
        {
                room->delete("exits/out");
                message("vision", "番僧用力一推，将藤筐推离平台，绞盘跟着慢慢放松，藤筐一荡，降了下去。\n", room);
        }
        delete("exits/enter");
        remove_call_out("no_board_two");
        call_out("on_board_two", 10, me);
}

void on_board_two(object me)
{
           message_vision("向外俯瞰，天湖已经变成了面小镜子。一阵山风吹得藤筐在空中摇荡起来，\n"+
                          "$N连忙抓紧藤筐，脸色吓得苍白。\n",me);
           remove_call_out("arrive");
           call_out("arrive", 10);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"tengkuang") )
        {
                room->set("exits/out", SHIP_TO);
                message("vision", "藤筐离地面越来越近，终于腾的一声着了地，众人都吁了口长气，悬着的心也随之放了下来。\n", room);
        }
        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"tengkuang") ) {
                room->delete("exits/out");

                tell_room(room, "藤筐一歪，似乎要往上升起，你赶忙从藤筐中窜了出来。\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "$N从倾斜的藤筐中滚了出去。\n", ob[i]);
                                else tell_room(room, "$N赶忙从藤筐中窜了出去。\n", ({ob[i]}));
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "从倾斜的藤筐中滚了出来。\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "急忙忙从藤筐中窜了出来。\n", ({ob[i]}));
                        }
                }
                message("vision", "藤筐飞快的升了起来，一会就消失在云中。\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_zhaohu(string arg)
{
        object me = this_player();

        if (!arg) return 0;

        if (arg == "fanseng") 
        {
                message_vision("$N上前恭恭敬敬的和番僧打了个招呼。\n", me);
                check_trigger(me);
                return 1;
        }
        else {
                message_vision("$N向众人招了招手：“喂！你们都过来。”可众人都没理睬。\n", me);
        }
        me->start_busy(1);
        return 1;
}

void reset()
{
        object room;

        ::reset();
        if (room = find_object(__DIR__"tengkuang"))
                room->delete("yell_trigger"); 
}

int valid_leave(object me, string dir)
{
        if( dir =="enter" ){
        if( me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("你要骑马上藤筐，不怕翻了？\n");
        }
        return ::valid_leave(me, dir);
}

