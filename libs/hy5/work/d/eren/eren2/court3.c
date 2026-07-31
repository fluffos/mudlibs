 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "彩石路尽头");
        set("long", @LONG
彩石路至此突然就中断了，前面是一个深不见底的大坑，黑漆漆的，
丢一块石块要半晌才有回应。左侧有块屏风似的岩石，悬着条钢索，吊着
个三尺高，二尺见方的筒子(elevator)，刚好可以容得一人。 
LONG
        );
        set("exits", ([ 
       "westup" : __DIR__"court2",
        ]));
        set("objects", ([
                __DIR__"npc/guarda" : 2,
                __DIR__"npc/guarda1" : 1,
        ]) );
        set("item_desc", ([
                "elevator": "这个筒子像是载人上下用的，也许可以跳进去。(dash)\n",
                "筒子": "这个筒子像是载人上下用的，也许可以跳进去。(dash)\n",
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_dash", "dash");
} 
int do_dash(string arg)
{
        object room, op_room,togo_room;
        object me,guard;
        me = this_player();
        if (guard=present("lieutenant",this_object()))
                return notify_fail("小头目大喝一声，“这地方也是你去得的?“\n");
        if (guard=present("guardian",this_object()))
                return notify_fail(guard->query("name")+"说道:“头儿不在，老子不会放你下去的。“\n");
        message_vision("$N一下子就跳进了筒子里！\n",me);
        op_room = find_object(__DIR__"controlroom");
        if(!objectp(op_room)) 
                op_room = load_object(__DIR__"controlroom");       
        if (op_room->query("elevator")) {
                message_vision("筒子晃动了几下又停了下来，好像有什么机关没有启动。\n", me);
                return 1;
                }
        togo_room = find_object(__DIR__"palace1");
        if(!objectp(togo_room)) 
                togo_room = load_object(__DIR__"palace1");    
        message_vision(YEL"筒子一沉，飞也似地向下降去！\n"NOR,me);
        tell_object(me,YEL"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n"NOR);
        me->move(togo_room);
        return 1;
}       
