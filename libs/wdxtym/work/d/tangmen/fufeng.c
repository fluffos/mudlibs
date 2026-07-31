// Room: /dream/fufen.c
// HEM 1998/10/14
#include <ansi.h>
#define SHIP_TO __DIR__"damen"
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
	set("outdoors", "tangmen");
	set("short", "扶风湖");
        set("long", @LONG
    出了竹林，面前是一片平静的湖面(lake)，微风拂过，水面泛起鳞鳞波纹。远
远望去，湖中水雾蒙蒙，隐约有一个小岛的影子。水域很宽望不到对岸。
LONG
    );

    set("exits", ([
        "west" : __DIR__"feicui",
    ]));

    set("item_desc", ([
        "lake" : "岸边有一座画舫，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "tangmen");
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
        if( !(room = find_object(__DIR__"huafang")) )
            room = load_object(__DIR__"huafang");
        if( room = find_object(__DIR__"huafang") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"huafang");
                room->set("exits/out", __FILE__);
                message("vision", "一座画舫缓缓地驶了过来，唐菱将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "唐菱将一块踏脚板搭上堤岸，形成一个向上"
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
        message("vision", "画舫上唐菱嘻嘻一笑：等着你呢，快上船吧。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "唐菱把踏脚板收了起来，竹篙一点，扁舟向湖心驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"huafang") )
    {
        room->delete("exits/out");
        message("vision", "唐菱把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n湖心驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"huafang") )
    {
        room->set("exits/out", __DIR__"damen");
        message("vision", "唐菱说道“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 10);
}

void close_passage()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"huafang") ) {
                room->delete("exits/out");

                tell_room(room, "唐菱轻声说道：“都下船吧，我也要回去了。”\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "唐菱把$N抬下了船。\n", ob[i]);
                                else tell_room(room, "听了唐菱的话，乖乖地下了船。\n", ob[i]);
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "走下了船。\n", ({ob[i]}));
                        }
                }
                message("vision", "唐菱把踏脚板收起来，把扁舟驶向江心。\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("neili") < 300 )
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
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"huafang") )
        room->delete("yell_trigger"); 
}
