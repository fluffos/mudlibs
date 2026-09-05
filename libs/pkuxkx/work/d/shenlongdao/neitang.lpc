
#include <room.h>
inherit ROOM;

void create()
{
        set("short","内堂");
        set("long",@LONG 
穿过议事大厅北侧的小门，你来到了内堂。内堂是教主和夫人临时歇息之处，
到处放了一些书籍，看起来很温馨，西墙角的书架还摆了一个照明灯(light)。
LONG
        );

        set("item_desc",([
           ]));
        set("objects",([
                ]));


        set("exits", ([
      "south" : __DIR__"yishidating",
        ]));


        setup();
}

void init()
{
        add_action("do_look","l");
        add_action("do_look","look");
        add_action("do_push","push");
}

int do_look(string arg)
{
        object me = this_player();
        if (arg == "light")
        {
                if (random(20) == 1)
                {
                        tell_object(me,"你仔细看了一下照明灯，发现手握的地方非常光滑。\n");
                        me->set_temp("shenlong/看灯",1);
                        return 1;
                }
                tell_object(me,"一盏很普通的照明灯，看起来似乎没有什么特别。\n");
                return 1;
        }
        return 0;
}

int do_push(string arg)
{
        object me = this_player();
        if (arg == "light")
        {
                if (me->query_temp("shenlong/看灯"))
                {
                        message_vision("$N握住照明灯用力一按，只听到墙壁发出沉重的声音，墙上开了一个小门。\n",me);
                        set("exits/north",__DIR__"andao");
                        remove_call_out("close");
      call_out("close", 15, this_object());

                        return 1;
                }
                return 0;
        }
        return 0;
}
void close(object room)
{
        message("vision","墙壁缓缓移动，吭的一声合在一起。\n", room);
        room->delete("exits/north");
}

