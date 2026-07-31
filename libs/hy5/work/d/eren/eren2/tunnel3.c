 inherit ROOM;
void create()
{
        set("short", "暗道口");
        set("long", @LONG
在狭窄的孔道中又爬行数丈，空间逐渐宽敞起来，四周的青苔，青藤
也茂盛起来，远远地似乎听到有人说话的声音。再过几丈，竟以出了暗道，
到了一个小小的蝙蝠洞之中。往下看去，足有三丈多高。也许是受人惊扰，
洞里的蝙蝠开始不安地骚动起来。
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"tunnel2",
        ]));
        set("objects", ([
                __DIR__"npc/bat" : 3,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_jump", "jump");
        add_action("do_climb", "climb");
        add_action("do_jump", "jumpto");
        add_action("do_jump", "jumpdown");
} 
int do_jump(string arg)
{
        object room;
        object me;
        me = this_player();
        room = find_object(__DIR__"court1");
        if(!objectp(room)) 
                room = load_object(__DIR__"court1");   
        message_vision("$N长长吸了口气，一纵身，向洞下跳去。\n",me);
        me->move(room);
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "洞" || arg == "down")
        {
                write("这个地方太险，大概爬不下去。\n");
                return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}   
