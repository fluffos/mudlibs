 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "茅房");
        set("long", @LONG
一块屏风似的岩石后，悬着条钢索，吊着辆滑车(huache)。 
钢索通向一个黑黝黝的山洞。 
LONG
        );
        set("exits", ([ 
       "south" : __DIR__"corridor",
        ]));
        set("item_desc", ([
                "huache": @TEXT
似乎可以跳(dash)进去,但里面...
TEXT
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
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"hole");
        message_vision("$N一下子就跳进了滑车！\n",me);
        tell_object(me,"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n");
        me->move(room);
        return 1;
}        
