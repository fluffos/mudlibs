// Room: /u/mei/room34.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
int do_get(string arg);
int do_break(string);

void create()
{
    set("short", "甬道");
    set("long", @LONG
前面山石阻路，已到尽头。只见尽头处闪闪生光，走近看时，却是一玉石巨
门。这门高达丈许，那里像门，直是一块巨大的岩石。石门上下左右还有四个门
环，均有两尺多长的粗大铁钮扣住。
LONG
    );
    set("exits", ([ 
        "south" : __DIR__"room33",
]));
    setup();
}
void init()
{
    object *obj;
    if (query("time")+1800<time() ){
        set("axe",1);
        set("time",time());
    }
    obj=children(__DIR__"obj/goldaxe");
        add_action("do_get", "get");
        add_action("do_break", "break");
    if (sizeof(obj)>1)        set("axe",0);
    if (query("axe")){
        set("item_desc",([
        "石门": "门环上插着一把"+YEL+"黄金斧"+NOR+"(Axe)\n",]));
     }else
        set("item_desc",([
        "石门": "两扇厚厚的大石门，似乎不可能打破它!\n",]));
}

int do_get(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (query("axe"))
        if( arg=="axe from men" || arg=="axe from 石门") {
             ob=new(__DIR__"obj/goldaxe");
            if (ob->move(me)){
                     message_vision("$N拔出一把"+YEL+"黄金斧"+NOR+"。\n",me);
                    delete("axe");
                     set("item_desc",([
                     "石门": "两扇厚厚的大石门，似乎不可能打破它!\n",]));
             }else{
                     message_vision("$N使出了吃奶的力，但是门环上的"+YEL+"黄金斧"+NOR+"依然纹丝不动。\n",me);
                     destruct(ob);
             }
             return 1;
       }
        return 0;
}
int do_break(string arg)
{
        object me,ob;
        object room;
        me = this_player();
    if (!arg || arg !="石门")
        return notify_fail("你要毁掉什么？\n");
    ob=me->query_temp("weapon");
    if (!ob){
        message_vision("$N气沉丹田，扎起马步，大吼一声，双拳击向石门！\n\n结果什么事也没发生！\n",me);
        me->receive_damage("qi",100);
        return 1;
    }
    if (base_name(ob)!=__DIR__"obj/goldaxe"){
        message_vision("$N高高举起手中的"+ob->query("name")+"挥向石门！\n\n结果$N虎口一震，"+ob->query("name")+"脱手飞出！\n",me);
        ob->move(environment(me));
        me->receive_damage("qi",300);
        return 1;
    }
    if ((int)me->query_skill("force",1) < 600 ) {
       me->add_temp("tmark/金",1);
        message_vision("结果只听一声闷哼，$N被石门的反弹力震得眼前一黑....\n",me);
        me->receive_damage("qi",500);
        if (me->query_temp("tmark/金")>4)
        me->unconcious();
        return 1;
        }
    if (!( room = find_object(__DIR__"room35")) )
        room = load_object(__DIR__"room35");
    message_vision("$N大吼一声，用"+ob->query("name")+"把石门劈开，露出一条甬道。\n$N一个弓身钻了进去。\n",me);
    me->set_temp("竹简", 1);
    me->delete_temp("marks");
    message("vision", "外面传来一声巨响，石门被人劈开了。\n",room);
    message("vision", me->name()+"破门而入。\n",room,me);
    me->move(room);
    message("vision","一块大石掉了下来，洞口又被封住了。\n",this_object());
    message("vision","一块大石掉了下来，洞口又被封住了。\n",room);
    return 1;
}

