// Room: /hangzhou/td_houmen.c
// hubo 2008/4/19
 
inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
        set("short", HIR"提督府后门"NOR);
        set("long", @LONG
这是提督府的后门。很少有人从这里经过，一些给提督大人走后门送礼的人
经常从这个门出入，门口有几个清兵在站岗，不过也无精打采的。
LONG
        );
        set("outdoors", "hangzhou");

        set("exits", ([
                "northeast" : __DIR__"td_xiaojing1",
        ]));
        
        set("objects", ([
                "/d/hangzhou/npc/qingbing1" : 4,
        ]));     

        setup();
}

void init()
{

        object ob, room;
        
        ob = this_player();
        room = this_object();

        if ( !living(ob) ) return;
                
        if (ob->query_temp("hhh_wt1") != 5)
                 return 0;
        
        if (ob->query_temp("hhh_wt1") == 5)

        message_vision(HIR "\n$N突然听到东面正门处一片噼里啪啦的鞭炮声响！
                              绿营清兵乱做一团，喊道：正门着火了，快去救火呀！\n\n" NOR, ob);

        message_vision(HIR "\n$N看到了后门有个入口没人注意，$N心里一喜，成功了。赶快进去。\n\n" NOR, ob);

        set("exits/enter", __DIR__"td_xiaodao2");
       remove_call_out("close");
        call_out("close", 5, this_object());

     return  0;
}

void close(object room)
{
        message("vision","绿营清兵骂道：妈的，假消息，不用去了，都站好了。\n", room);
        room->delete("exits/enter");
}    
