 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "庄稼地");
        set("long", @LONG
一块绿油油的麦田。田中半人高的麦杆儿随风而动，正如江湖中
的你，随著江湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,
不禁沧然泪下。 
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"farm4",
                "south" : __DIR__"farm2",
                "east" : __DIR__"farm4",
                "west" : __DIR__"farm6",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",120);
        set("coor/y",-70);
        set("coor/z",0);
        setup(); 
}  
int valid_enter(object me)
{
        
        if(random(50)==1)
                call_out("wind_blow",5,me);
        return 1; 
}
void init()
{
        add_action("do_throw","throw");
} 
int wind_blow(object me)
{
        if(!me || !present(me,this_object()) || !living(me))
                return 1;
        message_vision("阵阵微风拂过，如果将什么树叶之类的抛(throw)在空中的话，一定会随风飘去吧。\n",me);
        set("微风中",1);
   call_out("wind_stop",20);
        return 1;
} 
int wind_stop()
{
        message("vision","风停了。。。\n",this_object());
        delete("微风中");
        return 1;
} 
int do_throw(string arg)
{
        string leaf_name;
        object leaf;
        
        if(!arg) return notify_fail("你要抛什么？\n");
        leaf = present(arg, this_player());
        if(!leaf)
                return notify_fail("你没有这个东西呀？\n");
        if(!leaf->query("castable"))
                return notify_fail("这个东西抛不起来。\n");
        if(!query("微风中"))
                return notify_fail("现在没有风，抛不起来。\n");
        if(this_player()->query("age")>13||this_player()->query("宿命B/武当_枫叶",1))
                return notify_fail("你已经不是小孩子了。\n");
        leaf_name=leaf->query("name");
        message_vision("$N将一片"+leaf_name+NOR"抛在风中，慢慢的飘走了。\n",this_player());
        if(leaf_name==HIR"枫叶"NOR)
this_player()->set("宿命B/武当_枫叶", 1+random(10));
        destruct(leaf);
        return 1;
}
                  
