// Room: /d/diaoyudao/shulin8.c 树林
// whuan 2008-5-3
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "平地");
        set("long", @LONG
这是树林中的一块平地，湮没在树林中，真不容被发现。几缕阳光从树叶中洒下来，
照在地上。平地的中央有几个人，似乎有一个年老的婆婆。
LONG
        );

        set("exits", ([
                 "out" : __DIR__"shulin8",
        ]));
        set("objects", ([
                "/d/lingxiao/npc/shipopo":1,
                "/d/lingxiao/npc/baiaxiu":1,	

        ]));
        set("outdoors", "diaoyudao");
        setup();
}
void init()
{       
        object ob,ob1,ob2;
        object room=load_object(__FILE__);
        ob1=load_object("/d/lingxiao/npc/shipopo");
        ob2=load_object("/d/lingxiao/npc/baiaxiu");
        
        if (interactive(ob = this_player()))
        {
        	 ob->set_temp("watch",4);
           remove_call_out("observe");
           call_out("observe",1,ob);        	
        }
        else 
        {
           destruct(ob1);
           destruct(ob2);
           return;
       }         	
}

int valid_leave(object me,string dir)
{       
        object room=load_object(__FILE__);
        if(dir=="west")
                return ::valid_leave(me,dir);
}

int observe(object me)
{       
        int dur=(int)me->query_temp("watch");
        object ob1,ob2;
        ob1=load_object("/d/lingxiao/npc/shipopo");;
        ob2=load_object("/d/lingxiao/npc/baiaxiu");
        
        if(objectp(ob1)){
                if (dur==4){
                        me->start_busy(5);
                        write(HIY"你一走进平地，看到地上坐着一个老婆婆和一个小姑娘，旁边
站着一个老头，却不知道是谁。你定了定神，闪在树后居然没人发现。你
仔细看了看，却发现这位婆婆居然是史小翠，也就是你的师娘，旁边那位
小姑娘正是白万剑之爱女阿绣了。她们似乎身受重伤，坐在地上喘气不止。\n"NOR);
                        me->add_temp("watch",-1);
                        call_out("observe",5,me);
                        return 1;
                }

                if(dur==3){
                        me->start_busy(5);
                        write(HIY"只听到史婆婆厉声说道：“丁不四，你何必苦苦相逼？”丁不四
道：“我只让您去碧螺山盘桓数日而已。”是婆婆大声说道：“不去不去！打
死也不去。”\n"NOR);
                        me->add_temp("watch",-1);       
                        call_out("observe",5,me);
                        return 1;
                }
        
                if (dur==2){
                        me->start_busy(5);
                        write(HIY"丁不四道：“接你到碧螺山去好好调养。你这次走
火，非同小可。”史婆婆道：“我死也不上碧螺山。我又没输给你，干么迫我到你
的狗窝去？”丁不四道：“咱们约好了在长江比武，我输了到你家磕头，你输了便
到我家里。是你自己练功走火也好，是你斗不过我也好，总而言之，这一次你非上
碧螺山走一遭不可。我几十年来的心愿，这番总算得偿，妙极，妙极！”史婆婆怒
发如狂，叫道：“不去，不去，不……”越叫越凄厉，陡然间一口气转不过来，竟
尔晕了过去。\n"NOR);
                        me->add_temp("watch",-1);       
                        call_out("observe",5,me);
                        return 1;
                }      
                if (dur==1){
                        me->start_busy(5);
                        write(HIY"你忍不住闪身出来，插口道：“她既不愿去，你怎能勉强人家？”丁不四大怒：“哪
里来的野小子，要你多管闲事，看老子教训你。”说毕伸手变打。你勉强招架了几招，挨不知
道多少拳脚。\n"NOR);
                        me->add_temp("watch",-1);       
                        call_out("observe",5,me);
                        return 1;
                }  
                if(dur==0){
                        write(HIW"史婆婆这时候悠悠醒转，大声喊道：“住手！”丁不四立刻跳出战圈。你走到
史婆婆旁边，史婆婆悄声对你说：“你抱住我和阿绣，用雪山的独门轻功从树顶逃走。”
说毕，史婆婆掏出一件物事甩在丁不四身前，只听轰的一声地上尘土飞扬，你赶紧抱住
史婆婆和阿绣从树顶逃走。丁不四大声喝喊，却哪里追赶的上。只一会儿，你来到树林
边，跃下树来。史婆婆不住的打量你，大声称赞到：“料不到老不死居然收了你这种弟子。
只可惜功夫太差。”阿绣插嘴道：“奶奶，你不如教他两招？”史婆婆沉吟良久，道：“你
愿意跟我学功夫吗？(answer 愿意/不愿意)”\n"NOR);
                        me->set("jinwudao/phase2",1);
//                        me->delete("jinwudao/phase1");
                        me->add_temp("can_learn_jwd",1);
                        ob1->move(__DIR__"shulinout");
                        ob2->move(__DIR__"shulinout");
                        me->move(__DIR__"shulinout");

                        return 1;
                }
        }
}


