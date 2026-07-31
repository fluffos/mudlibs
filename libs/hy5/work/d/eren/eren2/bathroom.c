 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "茅房");
        set("long", @LONG
这地下的宫阙，显然是经过精心的设计，每一寸地方，都没有浪费，
长道的弯曲处，就是方便之处。一块屏风似的假山石后，有个蹲坑，上面
盖着个盖子。 
LONG
        );
        set("exits", ([ 
       "south" : __DIR__"corridor",
        ]));
        set("item_desc", ([
                "假山石": "方便之处，总要有个遮人耳目的东西。。。。\n",
                "rock": "方便之处，总要有个遮人耳目的东西。。。。\n",
                "盖子": "蹲坑上的盖子(lid)，似乎可以打开（open）。\n",
                "lid": "蹲坑上的盖子(lid)，似乎可以打开（open）。\n",
                "gaizi": "蹲坑上的盖子(lid)，似乎可以打开（open）。\n",
                "坑": "一个很普通的蹲坑，上面有个盖子(lid)，似乎可以打开（open）。\n",
                "ken": "一个很普通的蹲坑，上面有个盖子(lid)，似乎可以打开（open）。\n",
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("lid_open",0);
        setup();
} 
void init()
{
        add_action("do_open", "open");
        add_action("do_climb", "climb");
} 
int do_open(string arg)
{
        object me;
        me = this_player();
        if (arg=="lid" || arg=="盖子") {
                message_vision(YEL"$N把盖子掀起，一股熟悉的气味扑面而来。\n"NOR,me);
           message_vision(YEL"下面是个深坑，边缘上还粘着些黄白之物。\n"NOR,me);
                set("lid_open",1);
        }       
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        
        me=this_player();
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "坑" || arg == "ken" || arg == "down")       {
                if (!query("lid_open"))
                        return notify_fail("盖子盖着怎么爬？\n");
                call_out("climb_down",6,me);
                me->start_busy(3);
                message_vision("$N一猫腰钻进了蹲坑，四肢并用地向下爬去。\n",me);
                return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n。");
                return 1;
        }
} 
int climb_down(object me)       {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        room = find_object(__DIR__"hole");
        if(!objectp(room)) 
                room = load_object(__DIR__"hole");  
        message_vision(YEL"粪坑本有一个洞通向地下，但没下几尺，旁边竟又有条小道。\n"NOR,me);
        message_vision(YEL"$N像蛇一样地爬进小道，里面是个小小的洞。\n\n"NOR,me);
        message("vision",YEL"小洞里臭烘烘地又爬进个人来。\n"NOR,room);
        me->move(room);
        return 1;
} 
void reset()
{
        ::reset();
        set("lid_open",0);
        
}    
