//风波亭
//by male

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW"风波亭"NOR);
    set("long", @LONG
这里就是风波亭了,岳飞当年就是在这里英勇就义的,现在这个亭子已破败不堪,
成为了秦桧专门审犯人的地方,地上可以看到有几具横七竖八的尸首,都是一些冒死
前来示威的百姓!
LONG
       );
    set("iswear",0);

    set("exits", ([
                "west" : __DIR__"xiaodao4",

                ]));

    set("objects", ([
                __DIR__ + "obj/corpse" : 10,
                __DIR__ + "npc/qinhui" : 1,
                ]));
	set("no_newbie_task",1);
    setup();
}
void init()
{
    object gaoshou;
    object room;
    object me;
    object qinhui,baojia;
    me=this_player();
    if(me->query("id")=="qin hui") return;
    room=load_object("/d/yuewangmu/xiaodao4");
    if(!this_object()->query("iswear"))
    {
        if(objectp(qinhui=present("qin hui",this_object())))
        {
            qinhui->carry_object("/d/yuewangmu/obj/jsbaojia")->wear();
            this_object()->set("iswear",1);
        }
    }
}

