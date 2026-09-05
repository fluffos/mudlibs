// Room: /hangzhou/td_dilao4.c
// hubo 2008/4/19
 
inherit "/d/hangzhou/song_room";
#include <ansi.h>
int do_break(string);

void create()
{
        set("short", "地牢大门");
        set("long", @LONG
这是提督府的地牢大门口，里边关着朝廷的重犯，一个大门（men）上着锁。
LONG);

        set("exits", ([
                "north" : __DIR__"td_xiaodao1",
        ]));
        set("no_dbr_stage",1);
		set("hsz_no_task",1);
        set("no_task",1);		
        setup();
}

void init()
{

        object ob, room;
        
        ob = this_player();
        room = this_object();

        if ( !living(ob) ) return;
                
        if (ob->query_temp("hhh_wt1") != 7)
                 return;
        
        if ((ob->query_temp("hhh_wt1") == 7) && ( !present("shiwei fu",ob)))
        {
         call_out("killer1", 1, ob);
         call_out("killer2", 1, ob);
        
           return;
        }
        else
                return;
}    

void killer1(object me)
{
        object killer1;
        killer1 = new("/d/hangzhou/npc/daneibaobiao1");
        killer1->move(environment(me));
        return;
}

void killer2(object me)
{
        object killer2;
        killer2 = new("/d/hangzhou/npc/daneibaobiao2");
        killer2->move(environment(me));
        return;
}
