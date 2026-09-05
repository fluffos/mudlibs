// room: mudao.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_ban(string);

void create()
{
    set("short", "墓道");
    set("long", @LONG
     这是一条窄窄的墓道，北边通向古墓深处，南边已到
了尽头。南边尽头处有一个巨石，据说叫断龙石，石头有点松
动，不知好不好推开它(ban)。地上满是大大小小的石头，有
人从这里经常出入。
  
LONG
    );

    set("exits", ([
       "north" : __DIR__"mudao2",
    ]));

    set("item_desc", ([
      "stone" : "这是一个巨大的石头，比较光滑，搬搬试试(ban)。\n",
    ]) );
    setup();
}

void init()
{
    object book, me;
    me = this_player();
    add_action("do_ban", "ban");
   
}

int do_ban(string arg)
{
    int n;object me=this_player();
    n = this_player()->query("neili");
    if( !arg || arg!="stone"){
        write("不要随便搬别人的东西！\n");
        return 1;
    }


    message_vision(
    "$N走到石头前，左右旋了一番。\n", this_player());
        
    if(n>=1000){
        message_vision(
        "$N只听一声轰响，巨石被掀起少许。\n", this_player());
        set("exits/south", __DIR__"duanlongshi");
        this_player()->set("neili",n-1000);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else {
        message_vision(
	"$N走到石头前，乱旋一通，结果什么都没发生。\n",this_player());
        
        this_player()->set("neili",0);
    }

    return 1;
}

void close(object room)
{
    message("vision","巨石哄地一声落了下来，封住了洞口。\n", room);
    room->delete("exits/south");
}

