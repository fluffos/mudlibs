#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_ban(string);
void create()
{
   set("short","花园");
   set("long",@LONG
你的眼前出现了一个美丽的花园，花园里种着一些花,花从中隐约可见
飘渺的倩影，那是宫中的姐妹们在玩耍.花园中央有一座假山(shan)
秀丽异常.
LONG );
    set("exits",([
      "east" : __DIR__"xuzhuroom",
       ]));
    set("outdoors", "lingjiu");
    set("objects",([
    __DIR__"npc/dizi":random(3),
    __DIR__"npc/lu" : 1,
    ]));
 //  set("no_clean_up", 0);
    setup(); 
}

void init()
{
    object me = this_player();
    add_action("do_ban", "ban");
    add_action("do_use","use");
   
}

int do_ban(string arg)
{
    int n;object me=this_player();
    n = me->query("neili");
    if( !arg || arg!="shan"){
        write("你没事搬什么你？\n");
        return 1;

    }

    message_vision("$N走到假山前，运起内力，试图搬起它来。\n", this_player());
        
    if(n>=1000){
        message_vision(
        "$N只听一声轰响，假山被搬了起来，露出了一个洞口。\n", this_player());
        set("exits/down", __DIR__"midao1");
        if(this_player()->query("family/family_name") != "灵鹫宫")
            this_player()->set("neili",n-1000);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else {
        message_vision("$N搬了半天，结果发现假山太重了，根本搬不动！\n",this_player());    
        this_player()->set("neili",0);
    }

    return 1;
}

void close(object room)
{
    message("vision","假山哄地一声落了下来，封住了洞口。\n", room);
    room->delete("exits/down");
}


