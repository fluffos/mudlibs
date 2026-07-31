// This program is a part of NT MudLIB

#include <ansi.h>
inherit ROOM;

void death_stage(object ob, int stage);
void setup_weishi(object weishi, object ob);
#define BATTLEFIELD_D "/adm/daemons/battlefieldd"
void create()
{
        set("short", HIR"战场入口"NOR);
        set("long", @LONG
这里是战场的入口。。。
LONG);
        set("outdoors", "battle");
        set("invalid_startroom", 1);

        set("exits", ([
                "enter" : __DIR__"egarden",
        ]));

        //set("no_fight", 1);

        setup();
}

void init()
{
        object me = this_player();
        call_out( "death_stage", 1, me, 0 );
}

void death_stage(object ob, int stage)
{
        object weishi, *weishis;
        int nMyWeiShi=0, nOtherWeiShi=0;
        int i;

        if( !ob || !objectp(ob) || !userp(ob) ) return;

        weishis = filter_array(children(__DIR__"npc/weishi.c"), (: clonep :));

        for( i = 0; i < sizeof(weishis); i++)
        {
                weishi = weishis[i];
                if( weishi->query_temp("battle/team_name") == ob->query_temp("battle/team_name") )
                        nMyWeiShi++;
                else nOtherWeiShi++;
        }


        if( nMyWeiShi > nOtherWeiShi+3 || nMyWeiShi >8  ) return;
        else
        {
                weishi = new (__DIR__"npc/weishi.c");
                if( !weishi )return;
                weishi->move(__DIR__"etang");
                setup_weishi(weishi,ob);
                message("vision", "你忽然发现前面多了一个人影。\n", environment(weishi), weishi);
        }

}

void setup_weishi(object me,object obj)
{
        mapping skills;
        string *names;
        int level,i;
        mixed exp;

        if( !objectp(me) || !objectp(obj) )return;

        exp=obj->query("combat_exp")-10000000;
        if( exp < 0 ) exp = 1000000;

        me->set("combat_exp", exp);

        level = pow( exp*10.,0.33333 );
        if( level < 100 ) level = 100;

        if( obj->query("combat_exp")<3000000 )
        {
                level = level/2 + random(level*2/3);
        }
        else if( obj->query("combat_exp")<5000000 )
        {
                level = level/2 + random(level/2);
        }
        else if( obj->query("combat_exp")<8000000 )
        {
                level = level/2 + random(level/3);
        }
        else if( obj->query("combat_exp")<10000000 )
        {
                level = level/2 + random(level/4);
        }
        else
                level = level/2 + random(level/5);

        skills = me->query_skills();
        names = keys(skills);

        for( i=0; i<sizeof(names); i++ )
                me->set_skill(names[i], level);

        me->set_temp("battle/team_name",obj->query_temp("team_name"));
        if( exp>80000000)me->set("name", "特级武士");
        else if( exp>60000000)me->set("name", "一级武士");
        else if( exp>40000000)me->set("name", "二级武士");
        else if( exp>20000000)me->set("name", "三级武士");
        else if( exp>5000000)me->set("name", "四级武士");
        else me->set("name", "五级武士");

        me->set_temp("apply/short", ({HIW""+obj->query_temp("battle/team_name")+""NOR+me->name()+"(wushi)"}));
}