 inherit __DIR__"no_killing_place";
void create()
{
    set("short", "正厅");
    set("long", @LONG
一间并不宽敞的书房，却收拾得清爽可人。右边竹帘窗楹之下，摆着一张紫檀
案几，上面陈设着一张焦木古琴，琴身乌黑光亮，没有半点灰尘。琴旁又有一竹制
花筒，却插着一枝山间常见的绿叶。左边也是一张紫檀书桌，上面斜斜的摊开几本
线装书，一杯清茶，犹自余温。屋的正中，高悬着一副狂草中堂： 
　　　　　　世人都说神仙好，我只羡鸳不羡仙 
LONG
        );
    set("exits", ([ 
        "south" : __DIR__"cyard",
        "east" : __DIR__"grassland",
        ]) ); 
    set("item_desc", ([
        "狂草中堂": "一副墨笔狂草书法，行云流水，气势磅礴，更有一种说不出的玄机孕含在字里行间．．\n",
        "writing": "一副墨笔狂草书法，行云流水，气势磅礴，更有一种说不出的玄机孕含在字里行间．．\n",
        ]) );
    set("no_magic", 1);
    set("coor/x",210);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
} 
void init()
{
        ::init();
    add_action("do_search", "search");
} 
int do_search(string arg)
{
    object me, obj;
    
    me = this_player();
    
    if(!arg || arg != "room" && arg != "书房") return 0; 
    if(me->query_temp("marks/marble") && !query("marks/gone"))
    {
        message_vision("$N在书房内翻箱倒柜地找了一翻。\n", me);            
        tell_object(me, "终于你在焦木古琴的下面找到了一个小水晶球。\n");
        message("vision",me->name()+
                "偷偷摸摸地从焦木古琴下拿出了个东西放到怀里。\n",
                environment(me), me);
        me->delete_temp("marks/marble");
        set("marks/gone",1);
        obj = new(__DIR__"obj/marble");
        obj->move(me);
        return 1;
    }
    message_vision("$N在书房内翻箱倒柜地找了一翻。\n", me);             
    tell_object(me, "你却没发现什么有价值的东西。\n");
    return 1;   
} 
void reset()
{
    ::reset();
    delete("marks/gone");
} 
