#include <ansi.h>
string look_sign();
int do_go(string);
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string);
void reset();
inherit ROOM;

mapping *sign=({
/*    ([  "name":"北京",
        "id":"bj",
        "file":__FILE__,
        "value":10000,
	"time":20
    ]),*/
    ([  "name":"扬州",
        "id":"yz",
        "file":__DIR__"yzyunhe",
"value":2500,
	"time":10
    ])
});

void create()
{	set("short", "运河");
	set("long", @long
这里是古老的运河的桥头边，只见这条运河蜿蜒流淌，从苏州城里穿过。
运河的两岸都是苏州的寻常百姓家，在苏州的城里出门最好的交通工具就是
船了。只见进处有一位老船夫，见你走过来，起身向你迎来，(sign)。
long);
    set("exits",([
    "southeast" : __DIR__"xidajie1",
    ]));
    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
        "sign" : (: look_sign :)
    ]));

    set("outdoors", "suzhou");
    setup();
}

void init()
{
    add_action("do_yell", "yell");
//     add_action("do_go", "qu");
}

string look_sign()
{
    string str="";
    int i=sizeof(sign);

    while (i--) {
        str += sign[i]["name"];
        str += "(" + sign[i]["id"] + ") ";
        str += MONEY_D->price_str(sign[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
    ob->enable_player();
    ob->delete_temp("block_msg/all");
    write("终点站到了。\n");
    ob->move(sign[i]["file"]);
    tell_room(environment(ob), ob->name() + "从船上走了下来。\n", ({ob}));
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(sign);

    if (!arg) return 0;
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("你正忙着呢！\n");
    while(i--) {
        if (arg == sign[i]["id"]) {
            switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
                case 0:
                    return notify_fail("穷光蛋，一边呆着去！\n");
                case 2:
                    return notify_fail("有零钱吗？\n");
            }
	    message_vision("$N登上了去" + sign[i]["name"] + "的船。\n", ob);
	    ob->disable_player("<旅途中>");
	    ob->set_temp("block_msg/all", 1);
	    ob->move(__DIR__"onroad");
            call_out("do_move", sign[i]["time"], ob, i);
            return 1;
        }
    }
    return notify_fail("你要去哪里？\n");
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
                message("vision", "只听得河面不远处隐隐传来：“别急嘛，"
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

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向运河驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
       message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n运河驶去。\n", room );
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
        room->set("exits/out", __DIR__"huzhongdao");
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
        message("vision","艄公把踏脚板收起来，把扁舟驶向运河。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
// string dir;

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
        message_vision("河面上远远传来一阵回声：“" + arg +
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

