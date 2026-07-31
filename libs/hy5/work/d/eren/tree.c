 inherit ROOM;
void create()
{
        set("short", "银杉树上");
        set("long", @LONG
你现在正攀附在一株银杉树上，树叶很密，在这里阳光也透不过茂密的树冠。
从这里可以很清楚地望见树下的一切动静，而不被人发觉，似乎是个干偷鸡摸狗
勾当的好地方。树冠很大，一部分树枝甚至垂到了附近的院子里。
LONG
        );
        set("objects", ([
                __DIR__"npc/banditspy" : 1,
        ]) ); 
        set("exits", ([ /* sizeof() == 2 */
                "down" : __DIR__"groad3",
        ])); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump1", "jumpdown");
} 
int do_jump(string arg)
{
        object me, room; 
        me = this_player();
        if(!arg || arg != "down") return 0;
        if (me->is_busy()|| me->is_fighting()) {
                tell_object(me,"你现在正忙。\n");
                return 1;
                }
        message_vision("$N从树上拔身而起，轻飘飘地落到了院内。\n\n", me);
        room = find_object(__DIR__"backyard"); 
        if(!objectp(room)) room=load_object(__DIR__"backyard");
        me->move(room);
        message("vision",me->name()+"轻飘飘地落到了院内。\n", environment(me), me); 
           return 1;
} 
int do_jump1(string arg)
{
        object me, room; 
        me = this_player();
        if (me->is_busy()|| me->is_fighting()) {
                tell_object(me,"你现在正忙。\n");
                return 1;
                }
        message_vision("$N从树上拔身而起，轻飘飘地落到了院内。\n\n", me);
        room = find_object(__DIR__"backyard"); 
        if(!objectp(room)) room=load_object(__DIR__"backyard");
        me->move(room);
        message("vision",me->name()+"轻飘飘地落到了院内。\n", environment(me), me); 
        return 1;
}      
