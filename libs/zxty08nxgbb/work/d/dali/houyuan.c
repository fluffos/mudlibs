// Room: /d/shaolin/hanshui1.c
// bye mei
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是客栈的后院，这里有辆马车，专门负责迎送住
店的客人。旁边有一个牌子（ｓｉｇｎ）。
LONG);

        set("no_fight", 1);
        set("exits" , ([
             "east": __DIR__"kezhan",
           ]));

        set("item_desc", ([
                "sign": @TEXT
车夫休息中，需要用车的，请（ｊｉａｏ）。
TEXT
        ]) );

        setup();
}

void init()
{
    add_action("do_jiao", "jiao");
}

void check_trigger()
{
    object room;
    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"chexiang")) )
            room = load_object(__DIR__"chexiang.c");
        if( room = find_object(__DIR__"chexiang") ) {
            if((int)room->do_check() && !room->query("yell") ) {
                set("exits/enter", __DIR__"chexiang");
                room->set("exits/out", __FILE__);
                room->set("yell",1);
                message("vision", "马车缓缓从马厮开了出来，车夫说道，上车吧。\n", this_object() );
                message("vision", "车夫将一块踏脚板搭上车厢，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "马车已经出去了,请稍等一会。\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "车夫说道：正等着你呢，上来吧。\n",
            this_object() );
}
void on_board()
{
    object room;
    message("vision", "马夫一甩鞭子，马车随着阵阵马蹄转眼间跑得无影无踪。\n",
        this_object() );
    delete("exits/enter");
    if( room = find_object(__DIR__"chexiang") )
    {
        room->delete("exits/out");
        room->delete("yell");
        message("vision", "车夫把车门关上了！\n", room );
        if (!(int)room->do_check())
        {
        remove_call_out("arrive");
        call_out("arrive", 20);
        }
    }
}

void on_out()
{
    object room;
    message("vision", "一阵阵马蹄传了过来，转眼间马车已经到了你面前。\n",
        this_object() );
    if( room = find_object(__DIR__"chexiang") )
    {
        room->delete("yell");
        if (!(int)room->do_check())
        {
        remove_call_out("arrive");
        call_out("arrive", 20);
        }
    }
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"chexiang") )
    {
        room->set("exits/out", "/d/city/kedian");
        room->set("yell",1);
    message("vision", HIR "车夫说道：喝啥子喝，到了。\n" NOR,room );
    remove_call_out("on_out");
    call_out("on_out", 10);
   }
}

int do_jiao(string arg)
{
        check_trigger();
        return 1;
}
