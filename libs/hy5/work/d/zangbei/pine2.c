 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "大松树顶");
        set("long", @LONG
终于爬到大松树的树顶了，离地有七、八丈，盘曲的丫枝，扇形的簇叶，遮住
了半个天空。可以闻到阵阵松果的清香，可是周围昏沉沉的，什么也看不清。树叶
里似乎有几个鸟窝，听到叽叽喳喳的叫声，不过离你太远，怎么也够不到。
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"pine1",
        ])); 
        set("item_desc", ([
                "鸟窝": "树叶里似乎有几个鸟窝，听到叽叽喳喳的叫声，也许你可以试着跳过去（jumpto）看看。\n",
                "nest": "树叶里似乎有几个鸟窝，听到叽叽喳喳的叫声，也许你可以试着跳过去（jumpto）看看。\n",
        ]));
        set("in_tree",1);
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init() {
        add_action("do_jump","jumpto");
}  
int do_jump(string arg){
        object me, room,item;
        
        me=this_player();
        
        if (!arg || (arg != "nest" && arg!="鸟窝") )
                return notify_fail("你要向哪儿跳？\n");
        
        message_vision("\n$N提一口真气，朝着鸟窝的方向纵身一跃。\n",me);
        
        room = find_object(__DIR__"temple5");
        if (!objectp(room)) room= load_object(__DIR__"temple5");
   
        if (me->query_skill("move",1)<=100) {
                message_vision("$N一脚踩空，双手向空中胡乱抓了几下，一个跟斗栽了下去。\n\n",me);
                message("vision","只听扑通一声，树上掉下一个人来。\n",room);
                me->move(room);
                me->unconcious();
                return 1;
        }
        
        if (me->query_temp("zangbei/树顶")) {
                tell_object(me,WHT"你朝着那个喇嘛注视过的地方跃去，单足在树枝上一点一跃。\n"NOR);
                tell_object(me,WHT"卡啪一声，树枝断了，你百忙之中往鸟窝里伸手一摸，抓到一个硬硬的东西，
赶紧揣到怀里。\n"NOR);
                item = new(__DIR__"obj/item");
                item->move(me);
        }
        
        message_vision("$N脚下再无着力之处，直通通地往树下落去。\n\n",me);
        message("vision","只听扑通一声，树上跳下一个人来。\n",room);
        me->move(room);
        return 1;
} 
