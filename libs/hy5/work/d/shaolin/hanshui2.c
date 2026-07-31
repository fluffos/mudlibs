// Room: /d/shaolin/hanshui2.c
// Date: YZC 96/01/19
#define SHIP_TO __DIR__"hanshui1"
inherit ROOM;
#include <ansi.h>

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_yell(string arg);

void create()
{
	set("short", "汉水北岸");
	set("long", @LONG
汉水北岸也是相当热闹，自北岸渡口往北，一条笔直的官道
直通南阳。此地民风淳朴，路旁夹柳成阴，酒厮林立，且都有一
面大大的「酒」旗迎风飘扬，蔚为壮观。也有不少小贩沿路叫买，
语多难辨，却也令人盛情难却。
LONG
	);

    set("exits", ([
	"north" : "/d/nanyang/nanmen",
    "south" : __DIR__"bridge",
    ]));

    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "shaolin");
    set("no_clean_up", 0);
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
        call_out("arrive", 20);
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
        call_out("close_passage", 20);
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
	int skill = 0;

        if (!living(me)) return 0;

        if (stringp(me->query_skill_mapped("dodge")))
        	skill = me->query_skill( me->query_skill_mapped("dodge"), 1 );

	if ( skill + me->query_skill("dodge", 1) /2 < 200 )
		return notify_fail(HIR "你的修为不够！\n" NOR);
        tell_room(environment(me), HIG + me->name() + "捡起一段芦苇抛入水中，紧跟着飞身跃上芦苇，长袖飘飘，渡过了汉水。\n" NOR, ({me}));
        write(HIY "你使出「一苇渡江」渡过了汉水。\n" NOR);
        me->move(SHIP_TO);
        tell_room(environment(me), HIG "只见" + me->name() + "踩着一段芦苇从对岸过来，姿态潇洒地落在岸边。\n" NOR, ({me}));
        return 1;
}








