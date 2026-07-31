// /d/mr/didao1.c
// by leontt 11/10/2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);

void create() 
{
	set("short",BLU"地道"NOR);
	set("long", @long
这里是慕容世家的地下通道，仔细看还能发现墙上有一道暗门(door)。
long);
	set("exits",([
		"west" : __DIR__"cufang",
		"east" : __DIR__"sleeproom",
		"south" : __DIR__"didao",
	]));
	set("item_desc", ([
		"door" : "这是一扇非常厚的铁门，门上有个钥匙孔。\n", 
	]));
	setup();
}

void init()
{ 
//	add_action("do_open", "open");        
}

int do_open(string arg)
{
	object room;
	object ob;

        if(!arg) return 
                notify_fail("你要开什么？\n");
        
        if(arg != "door")
                return notify_fail("你要开什么？\n");
        
        if (query("exits/down"))
                return notify_fail("门已经是开着了。\n");
                
        if (!(ob = present("mrkey", this_player())))
                return notify_fail("你不会是想要撬锁吧？\n");
                
        message_vision("$N拿出黑钥匙插进铁门的钥匙孔中，显然钥匙已经再也拿不出来了。\n只听 “唰”的一声铁门向上快速的升起。\n",this_player());
        destruct(ob);

        if(!( room = find_object(__DIR__"didao2")) )
                room = load_object(__DIR__"didao2");
        if(objectp(room))
        {
                set("exits/down", __DIR__"didao2"); 
                room->set("exits/up", __FILE__);
                message("vision","“唰”的一声铁门向上升起，外面有人把门打开了。\n",room);
                remove_call_out("close_gate");
                call_out("close_gate", 4);
        }
        return 1;
}

void close_gate()
{
        object room;

        if(!( room = find_object(__DIR__"didao2")) )
                room = load_object(__DIR__"didao2");
        if(objectp(room)){
                delete("exits/down");
                message("vision","瞬间铁门又“啪”的一声快速的落了下来。。\n",this_object());
                message("vision","你两眼发直，知道自己已经进不去！\n" , this_object());
                room->delete("exits/up"); 
                message("vision","瞬间铁门又“啪”的一声快速的落了下来。\n",room);
                message("vision","你隐约感到眼前好象有一个鬼影在晃动，你吓出一身冷汗！\n",room );
        }
}
