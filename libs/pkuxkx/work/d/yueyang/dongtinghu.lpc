// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"洞庭湖"NOR);
        set("long", "洞庭湖上波光粼粼。它承纳长江中上游和湖南的湘、资、沅、澧四条江河水\n量，湖泊的周围是广阔的沼泽和平原。你可以可以雇(yell)渡船游览湖心小岛。\n");
        set("exits", ([
               "west" : __DIR__"guandaow1",
               "north" : __DIR__"yueyanglou",
               "southup" : __DIR__"shanlu",
                
        ]));
        set("objects", ([

        "/d/city/npc/bookseller":1,
        ]));
        set("couldfish",1);
        set("outdoors", "yueyang");
        setup();
   
}

void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )//boat
            room = load_object(__DIR__"duchuan");//boat
        if( room = find_object(__DIR__"duchuan") ) //boat
            {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");//boat
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 5);//wait time
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

    if( room = find_object(__DIR__"duchuan") )//boat
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n江心驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 10);//time
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )//boat
    {
        room->set("exits/out", __DIR__"xiaodao");//destination
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 12);//time
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) //boat
        {
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;
    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "船家";
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
        object *all;

        ::reset();

        if( room = find_object(__DIR__"duchuan") )
        {
            all = filter_array( all_inventory(room), (: userp :));
            if (sizeof(all)>0)
            {
                return;
            }
            room->delete("yell_trigger");
        }
}

