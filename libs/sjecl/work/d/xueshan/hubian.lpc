// Room: hubian.c 湖边

#include <ansi.h>

#define SHIP_TO __DIR__"jiaopan"

inherit ROOM;

void create()
{
        set("short", "湖边");
        set("long", @LONG
走到这里，小路已经到了尽头，一道刀削似的峭壁(qiaobi)横在面前。抬头
看去，峭壁间云雾缭绕，石壁光滑，无可攀缘之处，看来只能回头了。
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiaolu3",
        ]));

        set("item_desc", ([
                "qiaobi" : "这道峭壁拔地而起，即使是猿猴估计也爬不上去。\n",
        ]));

        set("outdoors", "雪山");
        set("coor/x",-240);
  set("coor/y",130);
   set("coor/z",0);
   setup();
}

void init()
{
        add_action("do_yell", "yell");
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
                                message("vision", "一条粗大的绳索坠着个大藤筐自云雾中缓缓垂落下来，轻轻落在地上。\n", thisroom);
                                message("vision", "一条粗大的绳索坠着个大藤筐自云雾中缓缓垂落下来，轻轻落在地上。\n", room);
                                remove_call_out("on_board");
                                call_out("on_board", 15, me);
                        }
                        else
                                message("vision", "只听峭壁上面有个沙哑的嗓子喊：“等……”，距离太远听不清楚。\n", thisroom);
                }
                else
                        message("vision", "ERROR: Tengkuang Not Found\n", thisroom);
        }
        else 
                message("vision", "喊了半天没动静，你这才发现眼前就有一个老大的藤筐。\n", thisroom);
}

void on_board(object me)
{
        object room;

        if( !me || !query("exits/enter") ) return;

        message("vision", "绳索一紧，藤筐左右摇晃振动了几下，冉冉向上升了起来。\n", this_object());

        if( room = find_object(__DIR__"tengkuang") )
        {
                room->delete("exits/out");
                message("vision", "绳索一紧，藤筐左右摇晃振动了几下，冉冉向上升了起来。\n", room);
        }
        delete("exits/enter");
        remove_call_out("no_board_two");
        call_out("on_board_two", 10, me);
}

void on_board_two(object me)
{
	if (!me) return;
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
                message("vision", "一个番僧用沙哑的声音道：“大轮寺到啦，出来吧。”，话音未落，藤筐已经被稳稳的停住了。\n", room);
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

                tell_room(room, "番僧不耐烦的道：“都下来吧，吓傻了动弹不了啦？”\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "番僧把$N抬出了藤筐。\n", ob[i]);
                                else tell_room(room, "$N双腿颤抖，不听使唤，被番僧架出了藤筐。\n", ({ob[i]}));
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬出了藤筐。\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "脸色苍白，双腿绵软，被两个番僧一左一右架出了藤筐。\n", ({ob[i]}));
                        }
                }
                message("vision", "藤筐飞快的降了下去，一会就消失在云中。\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_yell(string arg)
{
        object me = this_player();

        if (!arg) return 0;

        if (arg == "tengkuang")arg = "藤筐";
	if (arg != "藤筐") arg = "哇";

        if (me->query("age") < 16  )        
                message_vision("$N使出吃奶的力气喊了一声：“放下" + arg + "”\n", me);
        else if (me->query("neili") > 500)
                message_vision("$N吸了口气，一声“放下" + arg + "”，声音中正平和地远远传了出去。\n", me);
        else
                message_vision("$N鼓足中气，长啸一声：“放下" + arg + "！”\n", me);
        if (arg == "藤筐")
        {
                check_trigger(me);
                return 1;
        }
        else
                message_vision("山谷间远远传来一阵回声：“" + arg + "～～～”\n", me);
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

