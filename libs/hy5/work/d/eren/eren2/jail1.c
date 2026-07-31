 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "牢房");
        set("long", @LONG
说是牢房，却没有铁栏，没有镣铐，四壁空荡荡的，门也没有锁。屋
子正中央有一块很大的铁板盖在地上，足有四五百斤重。铁板上有一个三
寸见方的孔。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jail2",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("item_desc", ([
                "铁板": "一块四五百斤重的铁板，下面好像是个大坑。\n",
                "tieban": "一块四五百斤重的铁板，下面好像是个大坑。\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init()     {
        add_action("do_push","push");
} 
void close_passage()
{
        object room; 
        if (room = find_object("/d/eren2/underjail1")) {
                if (!room->query("exits/up")) return;
                message("vision","铁板砰地一声又倒了下来盖住了出口。\n",room);
                room->delete("exits/up");
        }
        message("vision", "铁板“轰”的一声又倒下去盖住了深坑。\n", this_object() );
} 
void check_trigger()
{
        object room;
        if( query("trigger")==5)  { 
        if( room = find_object(__DIR__"underjail1") ) {
                message("vision","顶上的大铁板忽然吱吱嘎嘎地向上移动起来，露出一条窄缝。\n",room );
                room->set("exits/up", __DIR__"jail1");
                message("vision","大铁板吱吱嘎嘎地移动起来，露出一条窄缝。\n",this_object());
        }
                delete("trigger");
                call_out("close_passage", 10);
        }
}   
int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "铁板" && arg != "tieban")) {
                return 0;
        }
        room = find_object(__DIR__"underjail1");
        if(!objectp(room)) 
                room = load_object(__DIR__"underjail1");   
        if (room->query("exits/up"))
                return notify_fail("铁板已经托起了。\n");
        message_vision(WHT"$N大喝一声，用尽全力向上托起铁板。\n"NOR, this_player());
        add("trigger", 1);
        check_trigger();
        return 1;
}  
void reset()
{
        ::reset();
        delete("trigger");
}
 
