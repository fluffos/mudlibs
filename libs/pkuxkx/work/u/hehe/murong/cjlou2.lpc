// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19
// modify by chui

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "藏经阁小屋");
        set("long", @LONG
千余年来少林寺之所以成为武林泰斗，自达摩老祖以下，历代
人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下
的少林七十二绝艺。少林也收藏了一些其他门派的武技、秘籍，
尽集于此，对此少林弟子也从未提起。许多少林的绝技也是于此
领悟、变化而出(linwu、digest)。
LONG
        );

        set("exits", ([
               // "down" : __DIR__"cjlou",
                "north" : __DIR__"cjlou1",
        ]));

        set("objects",([
                "d/shaolin/obj/wuji1" : 1,
                "d/shaolin/obj/wuji2" : 1,
                "d/shaolin/obj/wuji3" : 1,
				"/d/murong/npc/murongbo" : 1,
        ]));
        create_door("north", "壁门", "south", DOOR_CLOSED);

        setup();
}

void init()
{
        add_action("do_linwu", "linwu");
        add_action("do_linwu", "digest");
}


int do_linwu(string arg)
{
        object me;
        string *sname;    
        int *svalue, myint ,mykar ,k;
        mapping skill_status; 
        me=this_player();   
        skill_status=me->query_skills("");
        sname=keys(skill_status);
        svalue=values(skill_status);
        myint = me->query("int");
        mykar = me->query("kar");
      	k = random(sizeof(skill_status));
        
        if(arg) return 1;
        if(me->query("combat_exp")<2000000) 
        {
        write(HIY"你现在经验太低无法冥想佛家的真理!\n"NOR);
        return 1;
        }
        if(me->is_busy()||me->is_fighting())
        {
        write(HIY"你现在无法静下心领悟佛家的真理!\n"NOR);
        return 1;
        }
        if((int)me->query("max_neili")<(int)me->query("neili"))
        {
        write(HIY"你现在内息紊乱，无法静下心领悟佛家的真理!\n"NOR);
        return 1;
        }
        if(me->query("jingli")<100)
        {
        write(HIY"很明显,你现在太累了,无法冥想佛家的真理!\n"NOR);
        return 1;
        }
                
        if((random(600)==0) && me->query("family/family_name")== "少林派")
        {
        write(HIY"你领悟了少林寺上乘的武功秘籍，觉得颇有所获!\n"NOR);
                for(int i=0; i<sizeof(skill_status); i++)                                      
                {
                        if (k=i)
                        {
                        me->improve_skill(sname[i],random(myint+mykar)+1);
                  if((random(random(mykar)+1000))>999)
                       {
                        me->add("wuying",random(2));
                          }
                        me->add("jingli",-100);
                        me->start_busy(3);
                        }
                }
        return 1;
        }
        else
        {
                write(HIY"你领悟了佛家的真理,觉得颇有所获!\n"NOR);
                me->start_busy(10);
                me->add("potential",1);
                me->add("combat_exp",random(2)+1);
        }
        return 1;
}

int valid_leave(object me, string dir)
{
        object ob;

        if ( present("huizhen zunzhe", environment(me)) )
        if ( present("shaolin wuji", me)
        ||   objectp(ob = present("corpse", me)) && present("shaolin wuji", ob) )
        {
                if (dir == "south" )
                {
                        return notify_fail("慧真说道: 武功秘籍只许在藏经阁内研习，不得携带外出 !\n");
                }
        }
        return ::valid_leave(me, dir);
}
