//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "渡口");
        set("long", @LONG
渡口前就是汹涌澎湃的黄河 (river)了。浊流滚滚，泥沙
俱下，声震数里。两岸渡船来来往往，在波谷中穿行，甚为凶
险。北边不远就是洛阳了。
LONG
        );
        set("no_task",1);
        set("item_desc", ([
                "river" : HIC"只见近岸处有一叶小舟，也许大声喊("+HIY"yell"+HIC")一声船家("+HIY"boat"+HIC")就\n能听见。倘若你自负轻功绝佳,也可直接渡水("+HIY"cross"+HIC")踏江而过。\n"NOR,
        ]));
        set("exits", ([
//                "northest" : __DIR__"huanghe",
                  "north" : __DIR__"guandao",
        ]));

        set("objects", ([
              __DIR__"npc/randomnpc" : 1,
           ])); 
        set("outdoors", "luoyang");
        setup();
//        replace_program(ROOM);
}
void init()
{
    add_action("do_yell", "yell");
    add_action("do_cross", "cross");
}

int do_cross(string arg)
{
    object me, room;
    me = this_player();
    if(!arg || arg != "river")
        return notify_fail("你要过什么？\n");

    if(me->query_skill("dodge", 1) < me->query("str") * 5)
        return notify_fail("你的轻功不足以把你这样的庞然大物送过河去！\n");
    if(me->is_busy())
        return notify_fail("你正忙着呢！\n");
    message_vision(HIC"$N长袖飘飘，跃过江面！\n"NOR, me);
    if( !(room = find_object(__DIR__"dukou")) )
        room = load_object(__DIR__"dukou");
    me->move(room);    
    if(random(me->query("dex")) == 0)
    {
        message_vision(HIR"$N从对岸跃了过来，忽然一个失足，掉进水里，狼狈不堪的爬了起来。\n"NOR, me);
        me->start_busy(3);
    }
    else
    message_vision(HIC"$N从对岸跃了过来，稳稳站在地上。\n"NOR, me);
    tell_room(__DIR__"duchuan",HIM+me->query("name")+"长袖飘飘，从你头上跃过。\n"NOR);

    return 1;
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
                message("vision", "一只渡船缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向下"
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

    message("vision", "艄公把踏脚板收了起来，竹篙一点，渡船向江心驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，渡船向\n江心驶去。\n", room );
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
        room->set("exits/out", __DIR__"dukou");
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
        message("vision","艄公把踏脚板收起来，把渡船驶向江心。\n", room);
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

