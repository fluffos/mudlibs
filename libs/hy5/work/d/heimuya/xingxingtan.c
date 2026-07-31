#include <ansi.h>

#define SHIP_TO __DIR__"changtan"

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();


void create()
{
        set("short", "猩猩滩");
        set("long", @LONG
只见一片长滩，山石殷红如血，水流湍急，这便是有名的猩猩滩，对面
岸边停泊着几艘小船(chuan) ，要过对面就要靠这几艘小船了。
LONG
        );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastup" : __DIR__"shidao2",
        ]));
        set("item_desc", ([
            "boat" : "一叶小舟隐藏在芦苇中，喊(yell)一声试看。\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "heimuya");
        setup();
}

/*在此付钱摆渡或买鱼吃*/
/*（等）渡船靠了岸，付了钱，船家一声吆喝，客人们一涌
 * 而入，小小渡船片刻间便越过波澜涛涛的汉江，靠上北岸
 */
void init()
{
        add_action("do_yell", "yell");
        add_action("du_jiang", "dujiang");
}

void check_trigger()
{
        object room;
        object thisroom = this_object();

        if(!query("exits/enter") ) {
                if( !(room = find_object(__DIR__"duchuan")) )
                        room = load_object(__DIR__"duchuan");
                if( room = find_object(__DIR__"duchuan") ) {
                        if((int)room->query("yell_trigger")==0 ) {
                                room->set("yell_trigger", 1);
                                set("exits/enter", __DIR__"duchuan");
                                room->set("exits/out", __FILE__);
                                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n", thisroom);
                                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上的阶梯。\n", room);
                                remove_call_out("on_board");
                                call_out("on_board", 15);
                        }
                        else
                                message("vision", "只听得江面上隐隐传来：“别急嘛，这儿正忙着呐……”\n", thisroom);
                }
                else
                        message("vision", "ERROR: boat not found\n", thisroom);
        }
        else 
                message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n", thisroom);
}

void on_board()
{
        object room;

        if( !query("exits/enter") ) return;

        message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n", this_object());

        if( room = find_object(__DIR__"duchuan") )
        {
                room->delete("exits/out");
                message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向江心驶去。\n", room);
        }
        delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 6);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"duchuan") )
        {
                room->set("exits/out", SHIP_TO);
                message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n", room);
        }
        remove_call_out("close_passage");
        call_out("close_passage", 10);
}

void close_passage()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");

                tell_room(room, "艄公轻声说道：“都下船吧，我也要回去了。”\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "艄公把$N抬下了船。\n", ob[i]);
                                else tell_room(room, "听了艄公的话，乖乖地下了船。\n", ob[i]);
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "走下了船。\n", ({ob[i]}));
                        }
                }
                message("vision", "艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_yell(string arg)
{
        object me = this_player();

        if (!arg) return 0;

        if (arg == "boat") arg = "船家";
        if (me->query("age") < 16  )
                message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
        else if (me->query("neili") > 500)
                message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
        else
                message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
        if (arg == "船家")
        {
                check_trigger();
                return 1;
        }
        else
                message_vision("江面上远远传来一阵回声：“" + arg + "～～～”\n", me);
        return 1;
}

void reset()
{
        object room;

        ::reset();
        if (room = find_object(__DIR__"duchuan"))
                room->delete("yell_trigger"); 
}

int du_jiang()
{
        object me = this_player();

        if (!living(me)) return 0;
        if (me->query_skill("dodge") < 150)
                return notify_fail("你的修为不够！\n");
        tell_room(environment(me), HIG + me->name() + "捡起一段芦苇抛入水中，紧跟着飞身跃上芦苇，长袖飘飘，渡过了汉水。\n" NOR, ({me}));
        write("你使出「一苇渡江」渡过了汉水。\n");
        me->move(SHIP_TO);
        tell_room(environment(me), HIG "只见" + me->name() + "踩着一段芦苇从对岸过来，姿态潇洒地落在岸边。\n" NOR, ({me}));
        return 1;
}

