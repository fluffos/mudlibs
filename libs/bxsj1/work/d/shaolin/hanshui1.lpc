// Room: /d/shaolin/hanshui1.c

#include <ansi.h>

#define	SHIP_TO	__DIR__"hanshui2"

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();

void create()
{
    set("short", "汉水南岸");
    set("long", @LONG
面前是一条波涛翻滚的大江(river)。浊流滚滚，万舟竞发。
两岸渡船来来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸
边，几个破萝支一块木板，板上摆满了活蹦乱跳的汉江鲤鱼。过
去不远，是有名的老河口，不少过江客都在这里等待渡船摆渡。
LONG
    );

    set("exits", ([
        "south" : __DIR__"yidao2",
    ]));

    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "shaolin");
    setup();
}


void init()
{
    add_action("do_yell", "yell");
    add_action("du_jiang", "dujiang");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n江心驶去。\n", room );
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
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
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
				else tell_room(room, "$N听了艄公的话，乖乖地下了船　n", ob[i]);
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "走下了船。\n", ({ob[i]}));
			}
		}
        message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "船家";
	if (arg != "船家") arg = "哇";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="船家")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}

int du_jiang()
{
	object me = this_player();

	if (!living(me)) return 0;
	if (me->query_skill_mapped("dodge") != "shaolin-shenfa" || me->query_skill("shaolin-shenfa") < 50)
		return notify_fail("你的修为不够！\n");
	tell_room(environment(me), HIG + me->name() + "捡起一段芦苇抛入水中，紧跟着飞身跃上芦苇，长袖飘飘，渡过了汉水。\n" NOR, ({me}));
	write("你使出「一苇渡江」渡过了汉水。\n");
	me->move(__DIR__"hanshui2");
	tell_room(environment(me), HIG "只见" + me->name() + "踩着一段芦苇从对岸过来，姿态潇洒地落在岸边。\n" NOR, ({me}));
	return 1;
}
