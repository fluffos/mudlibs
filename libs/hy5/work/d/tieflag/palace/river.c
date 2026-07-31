 inherit ROOM;
void create()
{
        set("short", "溪边");
        set("long", @LONG
湍急的小溪到了这里，由于溪流的加宽而渐渐平稳安静了下来。溪边
有一丛一人多高的芦苇，还有几株垂柳。柳树把它们的柳丝垂到了溪面上，
微风佛过，在平静的溪面上画著圈圈点点，逗的水中的鱼儿不停地跃出水
面。几只羽毛艳丽的野鸭在水面上荡来荡去，不时地把头探入水中寻找它
们的食物，还有几只在岸边休息。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"grass",
  "west" : __DIR__"naibridge",
  "east" : __DIR__"smalllake",
]));
        set("objects", ([
        __DIR__"npc/duck" : 2,
                        ]) ); 
        set("outdoors","fengyun");
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        setup();
} 
void init()
{
        add_action("do_pick", "pick");
} 
int do_pick(string arg)
{
        object  me, lu; 
        if( arg != "luwei" && arg != "芦苇") 
                return notify_fail("什么？\n");
        me = this_player();
        if(me->query_temp("marks/luwei"))
                return notify_fail("芦苇已经被你摘没了。\n");
        lu = new(__DIR__"obj/luwei");
        lu->move(me);
        me->set_temp("marks/luwei", 1);
        message_vision("\n$N摘了一根芦苇放在怀里。\n", me);
        return 1;
}    
