#include <ansi.h>

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();



void create()
{
        set("short", "湖中岛");
        set("long",@long
这里是太湖中心的一个小岛，小岛的中心有一座亭子。
long);
set("exits",([
"north" : __DIR__"bishuiting",
]));

    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "shaolin");

        set("outdoors", "shaolin");
        setup();
}

/*在此付钱摆渡或买鱼吃*/
/*（等）渡船靠了岸，付了钱，船家一声吆喝，客人们一涌
 * 而入，小小渡船片刻间便越过波澜涛涛的汉江，靠上北岸
 */
void init()
{

    add_action("do_yell", "yell");




    add_action("du_shui", "dushui");
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
                message("vision", "只听得湖面上隐隐传来：“别急嘛，"
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

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向湖边驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )


    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n湖边驶去。\n", room );
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
room->set("exits/out", __DIR__"hubiandadao");
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }

    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向湖边。\n", room);
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
    else if( (int)this_player()->query("neili") > 600 )
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
        message_vision("湖面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

int du_shui()
{
        object me = this_player();

        if (!living(me)) return 0;
        if (me->query_skill_mapped("dodge") != "shaolin-shenfa" || me->query_skill("shaolin-shenfa") < 50)
                return notify_fail("你的修为不够！\n");
        tell_room(environment(me), HIG + me->name() + "捡起一段芦苇抛入水中，紧跟着飞身跃上芦苇，长袖飘飘，渡过了水面。\n" NOR, ({me}));
 write("你使出「一苇渡江」渡过了水面。\n");
        me->move(__DIR__"hubiandadao");
        tell_room(environment(me), HIG "只见" + me->name() + "踩着一段芦苇从对岸过来，姿态潇洒地落在岸边。\n" NOR, ({me}));
        return 1;
}
