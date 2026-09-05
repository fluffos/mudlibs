// room: duanlongshi.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_ban(string);

void create()
{
    set("short", "断龙石");
set("outdoors","gumu");
    set("long", @LONG
 这儿有一块很大的石头，据说叫断龙石，以前这儿是古
墓的入口。石头有点松动，不知好不好推开它(ban)，这儿
地上满是大大小小的石头，好像是断龙石才放下来一样，可
知有人从这里经常出入。
  
LONG
    );

    set("exits", ([
       "south" : __DIR__"caodi3",
	"east" : __DIR__"shandao",
	"west" : __DIR__"machehang",
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
        set("exits/north", __DIR__"mudao");
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
    room->delete("exits/north");
}

