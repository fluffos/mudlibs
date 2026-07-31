
// Room: /d/yanziwu/hupan.c
// Date: Feb.14.1998 by Java

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
         set("short", "太湖湖畔");
         set("long", @LONG
太湖(hu)处江浙之间。她襟带三江，东南之水尽汇于此，周行五百
里，古称五湖。矗立湖岸，唯见长天远波，放眼皆碧，七十二峰苍翠挺
立在三万六千顷波涛之中，使人心襟大开，直欲仰天长啸，方能表此喜
乐。
LONG );
        set("exits", ([
            "northeast" : "/d/suzhou/road5",
        ]));

        set("item_desc", ([
            "hu":"近湖畔处有一叶小舟，舟上一个绿衫姑娘正在戏水。喊(yell)一声试试吧。\n",
        ]));

        set("outdoors", "shaolin");
        set("no_clean_up", 0);
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
        if( !(room = find_object(__DIR__"xiaozhou")) )
            room = load_object(__DIR__"xiaozhou");
        if( room = find_object(__DIR__"xiaozhou") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"xiaozhou");
                room->set("exits/out", __FILE__);
                message("vision", "一尾小舟缓缓地驶了过来，一个采莲少女招手让你登舟。\n", this_object() );
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "只听得湖面上隐隐传来：“就来了啦……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "湖畔一尾小舟上一个绿衫少女细声说到：侬有啥事体。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "少女竹篙一点，小舟离岸向湖心滑去。\n",
        this_object() );

    if( room = find_object(__DIR__"xiaozhou") )
    {
        room->delete("exits/out");
        message("vision",
"\n少女说了一声“坐稳喽”，声音极甜极清，令人一听之下，说不出的舒
适。然后竹篙一点，扁舟向湖心滑去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"xiaozhou") )
    {
        room->set("exits/out", __DIR__"muti");
message("vision","少女说: “到啦，上岸吧。”，随即一点竹篙，把舟泊好。\n",room);
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"xiaozhou") ) {
        room->delete("exits/out");
        message("vision","少女竹篙一点，撑了小舟到湖中采莲戏水。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "姑娘";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="姑娘")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("湖面上远远传来一阵回声：“"+arg+"～～～”\n",this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"xiaozhou") )
        room->delete("yell_trigger"); 
}
