#include <ansi.h>
inherit ROOM;
int do_push(string arg);
void create()
{
        set("short", "铁门");
        set("long", @LONG
这是沙漠中的一个土房间，一扇铁门（door）紧紧关闭，似乎打不开。
LONG
        );
        set("exits", ([
            "west" : __DIR__"yyd_yuan" ,
        "south" : __DIR__"yyd_hole2",
            "east" : __DIR__"yyd_yang" ,
//out
                  ]));
  set("item_desc",([
            "men": "这道铁门极为沉重，似乎有什么机关才能打开。\n",
            "door": "这道铁门极为沉重，似乎有什么机关才能打开。\n",
            "铁门": "这道铁门极为沉重，似乎有什么机关才能打开。\n",
                  ]));
        setup();
}
void init()
{        
        add_action("do_push", "push");
        add_action("do_push", "tui");
}

int do_push(string arg)
{ 
        object me=this_player(); 
        object yuan,yang;
        int flag1,flag2;
        yuan=load_object("/d/reborn/jinyong/yyd_yuan");
        yang=load_object("/d/reborn/jinyong/yyd_yang");
        if( yuan->query("yuandao") ) flag1 = 1;
        if( yang->query("yangdao") ) flag2 = 1;
        if( !arg || arg=="" ) return 0;
        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！");
        if( arg=="men" ||arg=="door" ||arg=="铁门" )
        {
            if (flag1 && flag2) 
            {
               message_vision("$N使劲推了铁门，只听“吱”的一声，门被推开了。\n",me);
               set("exits/north", __DIR__"yyd_room");
               remove_call_out("close");
               call_out("close", 5, this_object());    
            }
            else
            {
                message_vision("$N使出吃奶的力气使劲推铁门，铁门根本没有任何反应。\n",me);
            }
        }
        return 1;
}
void close(object room)
{
    message("vision","门“砰”的一声又自己关上了。\n", room);
    room->delete("exits/north");
}
