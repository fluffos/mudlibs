// Room: /hangzhou/td_huayuan9.c
// hubo 2008/4/19

inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
        set("short", "花园");
        set("long", @LONG
杭州提督府的花园，种着五颜六色的鲜花，香味扑鼻，另人陶醉。你一走进来，
感觉失去了方向。心里有种不祥的预感。这里看起来似乎和其他地方不太一样，
有一股让人觉得很危险的气息。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "east" : __DIR__"td_huayuan"+(random(8)+2),
                "south" : __DIR__"td_huayuan"+(random(8)+2),
                "west" : __DIR__"td_huayuan"+(random(8)+2),
                "north" : __DIR__"td_huayuan"+(random(8)+2),     
]));
   	set("no_newbie_task",1);  
   setup();
}

void init()
{

        object ob, room;
        
        ob = this_player();
        room = this_object();

        if ( !living(ob) ) return;
        
        if (ob->query("id") == "wen tailai")
                {
                        room = load_object(__DIR__"td_dilao3");
            ob->move(room);
            return;
          }

        room->delete("exits");
        ob->delete_temp("hz_huayuan");
        ob->start_busy(20);
        ob->set_temp("tidufu/xianjing",1);

        message_vision(HIR "\n$N一不小心，走进了清兵们设下的陷阱！
$N只觉得脚下一空，掉了进去。\n\n" NOR, ob);

        message_vision(HIR "\n$N心里一凉，默默念叨：完了，完了。。。\n\n" NOR, ob);

        call_out("trapping", 20, ob, room);

}

void trapping(object ob, object room)
{
		if (!ob) return;//人如果quit就会报错，加个判断人走了就不继续了Zine
        if ( !living(ob) ) return;

        message_vision(HIY "\n清兵们高呼：又抓到一个。把$N从陷井里起了出来，送进了大堂！\n\n\n" NOR, ob);
        ob->move(__DIR__"td_zhengting"); 

        room->set("exits/south", __DIR__"td_huayuan"+(random(8)+2));
        room->set("exits/north", __DIR__"td_huayuan"+(random(8)+2));
        room->set("exits/east", __DIR__"td_huayuan"+(random(8)+2));
        room->set("exits/west", __DIR__"td_huayuan"+(random(8)+2));
}

