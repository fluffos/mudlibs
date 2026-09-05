// yuan1.c 小园
// add taiji question by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小园");
        set("long", 
"这是物侧的一个不大的菜园，园篱边生有一株二人高的松\n"
"树，虽不挺拔，却也别有一番苍劲的气势。地里生着几行青菜，\n"
"绿油油的颇讨人喜欢。\n"
        );
        set("exits", ([
                "west" : __DIR__"xiaoyuan",
        ]));
        if (random(2)==1)
        set("objects", ([
                __DIR__"npc/snake" : 1,
                __DIR__"npc/bird"  : 1,
                ]));
        setup();
} 
void init()
{       object ob,ob1,ob2;
        object room=load_object(__FILE__);
        ob1=load_object(__DIR__"npc/snake");
        ob2=load_object(__DIR__"npc/bird");

        if (interactive(ob = this_player())){
                if (objectp(ob1)){ 
                        if ((string)ob->query("family/family_name") == "武当派"
                          && ob->query_skill("taiji-jian",1)>400
                          && ob->query_skill("taiji-quan",1)>400 
                          && !ob->query("taiji")){ 
                                 ob->set_temp("watch",4);
                                 remove_call_out("observe");
                                 call_out("observe",1,ob);
                                 return;
                         } else {
                                 write("只听到一阵簌簌之声，你低头一看，原来是一只青蛇被你脚步所惊，游身逃走了。\n");
                                 destruct(ob1);
                                 destruct(ob2);
                                 return;
                         } 
                }
                room->add_temp("person_in",1);
         }
}

int observe(object me)
{       
        int dur=(int)me->query_temp("watch");
        object ob1,ob2;
        ob1=load_object(__DIR__"npc/snake");
        ob2=load_object(__DIR__"npc/bird");
        
        if(objectp(ob1)){
                if (dur==4){
                        me->start_busy(5);
                        write(HIY"你刚走进园内就听到一阵动静，心中不由好奇，躲在屋侧定睛一看。\n"
                          "只见一条菜花蛇伏在地上，头直仰天；一只喜鹊停在枝上，眼睛盯着地上的蛇。\n"
                          "看来是这两个畜牲正在相斗。\n"NOR);
                        me->add_temp("watch",-1);
                        call_out("observe",5,me);
                        return 1;
                }

                if(dur==3){
                        me->start_busy(5);
                        write(HIY"突然间，喜鹊从树枝上俯冲而下，利嘴直奔菜花蛇双眼而去！\n"
                          "菜花蛇身子一曲，三角头划出一个圆弧，不见什么漂亮的招数，\n"
                          "却躲开了攻击，反而袭击喜鹊的颈项！\n"
                          "你脑中灵光一现：这不正是太极“无招犹胜有招”的精髓吗？！\n"NOR);
                        me->add_temp("watch",-1);       
                        call_out("observe",5,me);
                        return 1;
                }
        
                if (dur==2 || dur==1){
                        me->start_busy(5);
                        write(HIY"你定下心来凝神观看：只见每当鹊鸟上下飞击长蛇时，\n"
                          "蛇总是蜿蜒轻身摇首闪避，始终未被击中。\n"
                          "你暗自记住菜花蛇的动作，借以印证所学武功，但觉茅塞顿开，喜不自禁。\n"NOR);
                        me->add_temp("watch",-1);       
                        call_out("observe",5,me);
                        return 1;
                }      

                if(dur==0){
                        write(HIW"你观看蛇鹊相斗，心中愈是洞明，不由的长声大笑。\n"
                          "蛇鹊被你一惊，顿时各自逃了个无影无踪。\n"
                          "你只觉心清如水，不知不觉中，你于“太极”武学之理又进了一步。\n"NOR);
                        me->add("taiji_time",1); 
                        if( (int)me->query("taiji_time") > random((int)me->query_skill("taiji-quan")/4)
                         && (int)me->query("taiji_time") > random((int)me->query_skill("taiji-jian")/4))
                        { 
                                write(HIB"你顿悟太极之理，阴阳太极，刚到极点便是柔，天地万物刚柔并存，乃太极也！！\n"NOR);
                                me->delete("taiji_time");
                                me->add("taiji", 1);
                        }
                        destruct(ob1);
                        destruct(ob2);
                        return 1;
                }
        }
}

int valid_leave(object me,string dir)
{       
        object room=load_object(__FILE__);
        if(dir=="west")
                return ::valid_leave(me,dir);
}

