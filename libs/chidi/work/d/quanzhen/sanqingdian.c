// sanqingdian.c 三清殿

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "三清殿");
        set("long", @LONG
这里是重阳宫的三清殿，是全真教会客的地点。正中供着元始天尊、灵宝天
尊和太上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着几个蒲
团。南边是玉皇殿，北边是后殿。
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"yuhuangdian",
                "west" : __DIR__"xilang1",
                "east" : __DIR__"donglang1",
                "north" : __DIR__"houdian",
        ]));

       set("objects", ([
"/d/quanzhen/npc/yinzhiping" : 1]));

       
        setup();
        "/clone/board/quanzhen_b"->foo();
//        replace_program(ROOM);
        
}
/*
void init()
{
        object me;
        mapping skill_status;
        string *sname;
        int i, level; 
        float exper;

        me = this_player();

        exper = to_float(me->query("combat_exp"));

        if ( !(skill_status = me->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++) 
        {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper 
                && exper > 100.0
                && sname[i] != "buddhism"
                && sname[i] != "literate"
                && sname[i] != "taoism" ) 
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        me->set_skill(sname[i], level);
                }
        }
}
*/

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "全真教") && dir == "north" &&                 objectp(present("master yin", environment(me))))
     return notify_fail(HIW"\n 尹志平喝道：你不是全真弟子，要想过去先胜过我手中长剑! \n\n"NOR);
                
        return ::valid_leave(me, dir);
}

