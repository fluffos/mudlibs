// Room: /hangzhou/td_datang.c
// hubo 2008/4/19

inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
        set("short", HIM"花园"NOR);
        set("long", @LONG
杭州提督府的花园，种着五颜六色的鲜花，香味扑鼻，另人陶醉。你一走进来，
感觉失去了方向。心里有种不祥的预感。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "east" : __DIR__"td_huayuan"+(random(8)+2),
                "south" : __DIR__"td_huayuan"+(random(8)+2),
                "west" : __DIR__"td_huayuan"+(random(8)+2),
                "north" : __DIR__"td_huayuan"+(random(8)+2),     
]));
     
   set("no_task",1);
   setup();
}

void init()
{

        object ob, room;
        
        ob = this_player();
        room = this_object();

        if ( !living(ob) ) return;

        room->delete("exits");

        
        ob->set("startroom", "/d/hangzhou/tidufu/td_jianyu");

        message_vision(HIR "\n$N一不小心，走进了清兵们设下的陷阱！
                              $N只觉得脚下一空，掉了进去。\n\n" NOR, ob);

        message_vision(HIR "\n$N心里一凉，默默念叨：完了，完了。。。\n\n" NOR, ob);

        call_out("trapping", 20, ob, room);

}

void trapping(object ob, object room)
{
        if (!ob|| !living(ob)) return; //要把!ob写在!living(ob)前面，否则先执行living(ob)就可能因为没object而报错，Zine 2013-05-28

        message_vision(HIY "\n清兵们把$N从陷井里起了出来，送进了监狱！\n\n\n" NOR, ob);
        ob->move(__DIR__"td_jianyu"); 

        room->set("exits/south", __DIR__"td_huayuan"+(random(8)+2));
        room->set("exits/north", __DIR__"td_huayuan"+(random(8)+2));
        room->set("exits/east", __DIR__"td_huayuan"+(random(8)+2));
        room->set("exits/west", __DIR__"td_huayuan"+(random(8)+2));
}
