#include <ansi.h>
inherit ROOM;
int do_push(string arg);
int do_open(string arg);
void create()
{
        set("short", "铁门");
        set("long", @LONG
一进到这个房间，一股霉味扑面而来，好久都没有来过了，墙角有一个箱子，似乎装有什
么重要的东西。南边是一扇沉重的铁门。
LONG
        );
        set("exits", ([

                  ]));
  set("item_desc",([
            "men": "这道铁门极为沉重，似乎有什么机关才能打开。\n",
            "door": "这道铁门极为沉重，似乎有什么机关才能打开。\n",
            "铁门": "这道铁门极为沉重，似乎有什么机关才能打开。\n",
            "box":"这个箱子很古怪，不知道装了什么东西。\n",
            "箱子":"这个箱子很古怪，不知道装了什么东西。\n",
                  ]));
        setup();
}
void init()
{        
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_open", "open");
}

int do_push(string arg)
{ 
        object me=this_player(); 

        if( !arg || arg=="" ) return 0;
        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！");
        if( arg=="men" ||arg=="door" ||arg=="铁门" )
        {
               message_vision("$N使劲推了铁门，只听“吱”的一声，门被推开了。\n",me);
               set("exits/south", __DIR__"yyd_yuanyang");
               remove_call_out("close");
               call_out("close", 5, this_object());  
               return 1; 
         } 
       else
        {
                return 0;
        }
}
void close(object room)
{
        message("vision","门“砰”的一声又自己关上了。\n", room);
        room->delete("exits/south");
}
int do_open(string arg)
{
        object me=this_player();
        object book1,book2;
        object yuan,yang;

        if( !arg || arg=="" ) 
             return notify_fail("你要打开什么\n？");
        if(me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢！\n");
        if(query("opened")<0)
             return notify_fail("看清楚，箱子已经破了，什么都没有！\n");
        if( arg=="box" ||arg=="箱子" )
        {
             message_vision("$N打开箱子，箱子“啪”的一声散了架，两本书掉了下来。\n",me);
             book1=new("/d/reborn/jinyong/obj/yyd");
             book1->move(environment(me));
             book2=new("/d/reborn/jinyong/obj/bmxxf");
             book2->move(environment(me));
             yuan=load_object("/d/reborn/jinyong/yyd_yuan");
             yang=load_object("/d/reborn/jinyong/yyd_yang");
             yuan->reset();
             yang->reset();
             add("opened",-1);
             return 1;      
        } 
}
