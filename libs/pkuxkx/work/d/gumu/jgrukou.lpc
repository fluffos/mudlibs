// room: jgrukou.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_ban(string);

void create()
{
    set("short", " 机关入口");
    set("long", @LONG
  这是一间什麽也没有的小石洞，走在里边有点恐怖。身旁
有一快大石头(stone),不知有没有用。
LONG
    );

    set("exits", ([ /* sizeof() == 4 */
        "east":__DIR__"jguan1",
        "south" : __DIR__"jguan"+random(3),
      //  "west" : __DIR__"xiaoshidong",
        "north":__DIR__"jguan"+random(6),
]));
        set("no_clean_up", 0);

set("no_task",1);
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
        
    if((n>=200)&&me->query("jiguan")==1){
        message_vision(
        "$N只听一声轰响，石壁中裂,出现了个小洞！\n", this_player());
        set("exits/west", __DIR__"xiaoshidong");
        this_player()->set("neili",n-200);
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
    message("vision","石壁哄地一声合上了，看不见一点痕迹。\n", room);
    room->delete("exits/west");
}

