// /u/beyond/mr/jiashan.c
// this is made by beyond
// update 1997.6,20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",BLU"假山"NOR);
         set ("long",@long
这是一假山。假山上洞穴很多，一阵微风吹过，洞穴发出“飕飕”的响
声，令人有些毛骨悚然。旁边有一块岩石(shi)。
long);
         set("item_desc", ([
             "shi" : "这块岩石已经很松动了，不知能不能(break)它。\n",
]));

setup();
}

void init()
{
    add_action("do_break", "break");
    add_action("do_jump","jump");
}
int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="shi" ) {
                write("你要打碎什么的东西！\n");
                return 1;
        }

  message_vision(
   "$N深吸一口气，双掌同时拍出。\n", this_player());

  if (n>=200) {
        message_vision(
 "$N只听一声“轰”的一声，$N把岩石震开了！发现有一个洞口。\n", this_player());
        set("exits/down", __DIR__"shandong");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","岩石滚回了原位，又挡住了洞口。\n", room);
         room->delete("exits/down");
   }
int do_jump(string arg)
{
        object me;
me = this_player();

        if (arg !="shuichi") 
return notify_fail("你要到那去？\n");
if( arg=="shuichi")
        {
            
                    write("你纵身跃起跳回了水池边。\n");
                    message("vision",
                             me->name() + "一纵身跳了过去。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"shuichi");
                    message("vision",
                    me->name() + "从水池中跳了过来。\n",
                                environment(me), ({me}) );
                }
                return 1;
 }
