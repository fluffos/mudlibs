 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "东寨墙");
        set("long", @LONG
寨墙是照箭楼的格式修筑的，一、二两层都有箭眼，三层只有一半墙壁，从上
半段也可露出头来向外射箭。若是有人来攻，寨里的人站在墙上向下射箭。居高临
下，十分得手。寨墙外面是茂密的森林，寨墙里面可以看到一个大院，院子的四周
有几间瓦房。靠墙有一把长梯供人上下。
LONG
        );
        set("exits", ([ 
                "northwest":    __DIR__"e_wall2",
        ]));
        set("item_desc", ([
                "ladder": "一把长梯从寨墙上通向大院，你可以爬下去（climb down），
不过，若是在梯子上遭到敌人攻击，恐怕会吃大亏。\n",
                "长梯":  "一把长梯从寨墙上通向大院，你可以爬下去（climb down），
不过，若是在梯子上遭到敌人攻击，恐怕会吃大亏。\n",        
        ]));
        
        set("objects", ([
                __DIR__"npc/archer":    2,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_climb","climb");
}  
int do_climb(string arg) {
        
        object me;
        
        me=this_player();
        if (arg=="down" || arg == "ladder" || arg== "长梯") {
           if (me->query_temp("zangbei/zaiqiang_1"))
                        return notify_fail("你已经在梯子中央了。\n");
                message_vision("$N把着长梯小心翼翼地向下爬去。\n\n",me);
                call_out("pass_river",4,me);
                me->start_busy(6);
                me->set_temp("zangbei/zaiqiang_1",1);
                return 1;
        }
        tell_object(me,"你要爬什么？\n");
        return 1;
}  
int pass_river(object me) {
        object room;
        if (!objectp(me) || me->is_ghost()) return 0;
        room=find_object(__DIR__"village");
        if (!objectp(room)) room=load_object(__DIR__"village");
        tell_object(me,"你轻巧地下到院子里。\n");
        message("vision",me->name()+"从梯子上爬了下来。\n",room);
        me->move(room);
        me->delete_temp("zangbei/zaiqiang_1");
        return 1;
}   
