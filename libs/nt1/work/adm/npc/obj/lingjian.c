// Updated by Lonely

#include <room.h>
#include <ansi.h>
inherit ITEM;
inherit F_SSERVER; 

#include "way.h"

varargs void attack_begin(object me, object target, object room, object env, string dir);
// int do_waring(object me, object ob);

void create()
{
        set_name(HIW"令箭"NOR, ({"ling jian","ling"}) );   
        set_weight(10);
        set("no_get",1);
        set("no_steal",1);
        set("no_put",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long",HIW"一枚大宋将军调兵遣将的令箭。\n"NOR);  
                set("material", "copper");
             }
        set("master","lonely");   
        set("owner","lonely");
        setup();
}


void init()
{
        object me = this_player(), ob = this_object();
        if (me->query("id") == ob->query("owner"))
        {
                add_action("do_escort", "yaliang");  
                add_action("do_move", "move");    
                add_action("do_train", "xunlian");    
                add_action("do_attack", "tuji");
                add_action("do_order", "order");   
                add_action("do_inquiry", "inquiry"); 
                add_action("do_yun", "yun");
                add_action("do_yun", "exert");
                
/*
                remove_call_out("do_waring");
                call_out("do_waring", 1, me, ob);
*/
        } 
}

/*
int do_waring(object me, object ob)
{
        if (! objectp(me) || ! objectp(ob))
                return 0;
        
        if (me->query("id") == ob->query("owner"))
        {
                add_action("do_escort", "yaliang");  
                add_action("do_move", "move");    
                add_action("do_train", "xunlian");    
                add_action("do_attack", "tuji");
                add_action("do_order", "order");   
                add_action("do_inquiry", "inquiry"); 
                add_action("do_yun", "yun");
                add_action("do_yun", "exert");
                
                remove_call_out("doing");
                call_out("do_waring", 1, me, ob);
          }
}               
*/
                
int do_yun(string arg)
{
        if (arg != "qi" && arg != "recover" && arg != "jing"
        &&  arg != "regenerate" && arg != "heal" && arg != "jingheal")
        {
                tell_object(this_player(),"你现在是一军之统帅了，一举一动请三思！\n");
                return 1;
        }
        return 0;
}

int do_escort()
{
        object me = this_player(), ob = this_object();

        if (! me->query_temp("jun_quest/escort"))
                return notify_fail("元帅并未分派你押解粮草的任务，不要擅自行动！\n");  

        if (me->query_temp("jun_quest/move"))
                return notify_fail("号令已经发布下去了！\n");   

        ob->start_move(me, ob);
        me->set("no_get", 1);
        me->set_temp("jun_quest/move", "forward");
        me->set_temp("jun_quest/last_move", "/quest/quest_jun/sying1"); 
        me->add_temp("jun_quest/reward", 10);

        message_vision(HIW "$N一挥手中令牌，大喝道：元帅有令，"
                + "即刻开赴京师押解粮草，不得有误！！\n" NOR, me);     
        return 1;
}

void start_move(object me,object ob)
{
        call_out("move_me", 4, me, ob);
}

void move_me(object me, object ob)
{
        object owner, room, master;
        mapping move_way;
        string site, temp;
        int liangcao;
        
        owner = environment(ob);
        if (! owner || ! owner->is_character()
        ||  owner->query("id") != ob->query("owner"))
        {
                destruct(ob);
                return;
        }

        room = environment(owner);
        site = file_name(room);

        if (me->query_temp("jun_quest/move") == "forward")
        {
                move_way = forward_way;
                if (site == "/d/bianliang/chengmen")
                {
                        me->start_busy(10 + random(10));   
                        message_vision(HIY "$N率领的解粮大军终于到达了京师汴梁，"
                                + "$N将粮草载上马车，又立刻开始了行军的奔程....\n" NOR, me);
                        me->set_temp("jun_quest/move", "backward");
                        move_way = backward_way;
                }
        } else 
        if (me->query_temp("jun_quest/move") == "backward")
        {
                move_way = backward_way;
                if (site == "/quest/quest_jun/sying1")
                {
                        message_vision(HIY "$N率领的解粮大军终于到达了襄阳军营，"
                                + "$N的粮草及时支援了大军的补给....\n" NOR, me);
                        me->delete_temp("jun_quest/escort");
                        me->delete_temp("jun_quest/move");  
                        me->delete_temp("jun_quest/last_move");
                        me->add_temp("jun_quest/reward", 20);
                        me->start_busy(5 + random(5));
                        me->delete("no_get");
                        master = find_player(ob->query("master"));
                        if (! master) 
                                master = find_living(ob->query("master"));
                        if (objectp(master) && environment(master) 
                        &&  master->query_condition("junquest_song"))
                        {
                                tell_object(master,
                                        HIY "押解粮草的军马到了，你的补给又增加了！\n" NOR);
                        }
                        temp = read_file("/quest/quest_jun/song/liangcao", 1, 1);
                        liangcao = atoi(temp) + 100 + random(100);
                        temp = sprintf("%d", liangcao);
                        write_file("/quest/quest_jun/song/liangcao", temp, 1);

                        remove_call_out("move_me");
                        return;
                }
        }
        if (! living(me) || me->is_fighting() || me->is_busy())
        {
                remove_call_out("move_me");
                call_out("move_me", 4, me, ob);
                return;
        }                    

        if (move_way[site])
        {
                me->set_temp("jun_quest/last_move", site);
                me->command("go " + move_way[site]);
        } else
        if (me->query_temp("jun_quest/last_move"))
                me->move(me->query_temp("jun_quest/last_move"));

        message_vision(YEL "$N率领着解粮大队人马不分昼夜地行进着.....\n", me);
        me->start_busy(2 + random(2));
        remove_call_out("move_me");
        call_out("move_me", 4, me, ob);
        return;
}

int do_attack(string arg)
{
        object me = this_player(), obb, room, env;
        string *dirs, dir, who;
        mapping exits;
        int i;

        env = environment(me);  

        if (! arg) return notify_fail("你要指挥部队朝谁发起进攻？\n");

        if (me->query_temp("jun_quest/attack"))
                return notify_fail("你的队伍正在列阵进攻，不要乱发号令了！\n"); 

        if (me->query_temp("jun_quest/group") < 1)
                return notify_fail("你的队伍已经损失殆尽，无法列阵冲锋了！\n"); 
 
        if (me->query_temp("jun_quest/train") == "infantry")
        {
                if (env->query("no_fight"))
                        return notify_fail("这里不许战斗！！\n");

                if (objectp(obb = present(arg, env)))
                {
                        if (obb->query("is_quest") || obb->query("is_robber"))
                                return notify_fail("你军务在身，还是不要轻易招惹是非的好！\n");

                        message_vision(HIW "$N大声下令道：步兵营列阵！队伍开始"
                                + "排出整齐的方阵，在一片闪烁的刀光\n中，$N指挥队伍发起"
                                + "了可怕的冲锋！\n" NOR, me);

                        me->set_temp("jun_quest/attack", 1);
                        call_out("attack_over", 10, me);
                        attack_begin(me, obb, room, env, ""); 
                        return 1;  
                } else
                        return notify_fail("无法找到目标，请用tuji sb 指挥你的队伍！\n");
        } else
        if (me->query_temp("jun_quest/train") == "cavalry")
        {
                if (sscanf(arg, "%s on %s", who, dir) == 2)
                {
                        if (mapp(exits = env->query("exits")))
                        {
                                dirs = keys(exits);
                                for (i = 0; i < sizeof(dirs); i++)
                                if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                                        dirs[i] = 0;
                                dirs -= ({ 0 });
                                if (mapp(exits) && exits[dir])
                                {
                                        if (! room = find_object(exits[dir]))
                                                room = load_object(exits[dir]);
                                        if (room)  
                                        {
                                                if (room->query("no_fight"))
                                                        return notify_fail("那里不允许撕杀！！\n");

                                                if (! objectp(obb = present(who, room)))
                                                        return notify_fail(
                                                                "无法找到目标，请用tuji sb on <方向> 指挥你的队伍！！\n");

                                                if (obb->query("is_quest") || obb->query("is_robber"))
                                                        return notify_fail("你军务在身，还是不要轻易招惹是非的好！\n");

                                                me->set_temp("jun_quest/attack", 1);
                                                call_out("attack_over", 10, me);    
                                                me->move(room);
                                                message_vision(
                                                        HIR "$N率领着一支宋军骑兵朝$n冲杀过来！\n" NOR,
                                                        me, obb);
                                                attack_begin(me, obb, room, env, "");
                                                return 1;
                                        }
                                }
                        }
                } else
                        return notify_fail("请用tuji sb on <方向> 指挥你的队伍！！\n");
        } else
        if (me->query_temp("jun_quest/train") == "archer")
        {
                if (sscanf(arg, "%s on %s", who, dir) == 2)
                {
                        if (mapp(exits = env->query("exits")))
                        {
                                dirs = keys(exits);
                                for (i = 0; i < sizeof(dirs); i++)
                                if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                                        dirs[i] = 0;
                                dirs -= ({ 0 });
                                if (mapp(exits) && exits[dir])
                                {
                                        if (! room = find_object(exits[dir]))
                                                room = load_object(exits[dir]);
                                        if (room)  
                                        {
                                                if (room->query("no_fight"))
                                                        return notify_fail("那里不允许撕杀！！\n");

                                                if (! objectp(obb = present(who, room)))
                                                        return notify_fail(
                                                                "无法找到目标，请用tuji sb on <方向> 指挥你的队伍！！\n");

                                                if (obb->query("is_quest") || obb->query("is_robber"))
                                                        return notify_fail("你军务在身，还是不要轻易招惹是非的好！\n");

                                                message_vision(HIB "$N大声下令道：神弩营准备！一排排利箭在阳"
                                                        + "光下闪闪发光——射击！！\n$N一声令下，万弩齐发！\n" NOR, me);  
                                                me->set_temp("jun_quest/attack", 1);
                                                call_out("attack_over", 10, me);    
                                                attack_begin(me, obb, room, env, dir);
                                                return 1;
                                        }
                                }
                        }
                } else
                        return notify_fail("请用tuji sb on <方向> 指挥你的队伍！！\n");
        } else
                return notify_fail("你未带一兵一卒，指挥个什么呀？\n");
}

varargs void attack_begin(object me, object target, object room, object env, string dir)
{
        object bow;
        int i;
        
        for(i = 0; i < me->query_temp("jun_quest/group"); i++)
        {
                if (objectp(target)
                &&  (me->query_temp("jun_quest/train") == "cavalry" 
                ||  me->query_temp("jun_quest/train") == "infantry"))  
                {
                        message_vision(HIR "$N指挥的三军杀声雷动，"
                                + "如狂风骤雨般朝$n发起了攻击！！\n" NOR, me, target);  
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                        me->add_temp("jun_quest/reward", 4);
                } else
                if (objectp(target)
                &&  me->query_temp("jun_quest/train") == "archer")
                {
                        bow = me->query_temp("weapon");
                        if (bow && bow->query("is_bow"))
                                bow->do_shoot(target->query("id"), me, bow, room, dir, 1);  
                        me->add_temp("jun_quest/reward", 4);
                } 
                else break;
        }

        if (me->query_temp("jun_quest/train") == "cavalry")
        {
                message_vision(HIW "一阵冲杀过后，$N率领着宋军骑兵如风"
                        + "一般消失了！\n" NOR, me);
                me->move(env);
        }                         

        return;
}

void attack_over(object me)
{
        if (objectp(me))
        {
                message_vision(HIW "$N手中令旗一挥，三军攻势一缓，重新"
                        + "开始列阵，准备发起新一轮的攻击！！\n" NOR, me); 
                me->delete_temp("jun_quest/attack");
        }
        return;
}      

int do_train()
{
        object me = this_player(), weapon;

        if (! me->query_temp("jun_quest/train"))
                return notify_fail("元帅并没有派你训练队伍吧？\n");

        if (! environment(me) || 
            file_name(environment(me)) != "/quest/quest_jun/sying1")
                return notify_fail("你必须到元帅那里领命才可以训练队伍！\n");

        if (me->query_temp("jun_quest/train_begin"))
                return notify_fail("你不是正在训练队伍吗？！\n");

        message_vision(HIW "$N接过令箭，大声道："
                + "末将遵命，末降即刻前去军营训练队伍！！\n" NOR, me);

        if (me->query_temp("jun_quest/train") == "cavalry")
                me->move("/quest/quest_jun/sying3");
        else
        if (me->query_temp("jun_quest/train") == "infantry")
                me->move("/quest/quest_jun/sying2");
        else
        if (me->query_temp("jun_quest/train") == "archer")
        {
                weapon = me->query_temp("weapon");
                if (weapon) weapon->unequip();
                me->command("wield bow");
                me->move("/quest/quest_jun/sying4");
        } else
        return notify_fail("你在做什么，擅自行动按军法论处！\n");

        me->set_temp("jun_quest/train_begin", 1);
        call_out("train_begin", 2, me);
        call_out("check_me", 2, me);
        return 1;
}


void train_begin(object me)
{
        object room, master, ob;
        string temp;
        int liangcao;
         
        ob = this_object();
        master = find_player(ob->query("master"));
        if (! master) master = find_living(ob->query("master"));

        if (! me->query_temp("jun_quest/train"))
        {
                remove_call_out("train_begin");
                me->delete_temp("jun_quest/train_begin");
                tell_object(me, "元帅并没有分派给你训练队伍的命令！\n");
                return;
        }

        temp = read_file("/quest/quest_jun/song/liangcao", 1, 1);
        liangcao = atoi(temp);
        if (liangcao <= 10)
        {
                remove_call_out("train_begin");
                me->delete_temp("jun_quest/train_begin");
                tell_object(me,"粮草不足，军队训练被迫终止！\n");

                if (objectp(master) && environment(master)
                &&  master->query_condition("junquest_song"))
                {
                        tell_object(master,
                                HIY "粮草不足，你的队伍被迫终止了训练！\n" NOR);
                }                                    
                return;
        }

        if (me->query_temp("jun_quest/group") > me->query("degree_jungong"))
        {
                remove_call_out("train_begin");
                me->delete_temp("jun_quest/train_begin");
                tell_object(me,"你带兵的能力不足，训练不了更精锐的队伍了！\n");

                if (objectp(master) && environment(master)
                &&  master->query_condition("junquest_song"))
                {
                        tell_object(master, HIY "你又训练出一营的精锐部队了！\n" NOR);
                }                                    
                return;
        }

        room = environment(me);
        if (! room || ! room->query("train")
        ||  room->query("train") != me->query_temp("jun_quest/train"))
        {
                remove_call_out("train_begin");
                me->delete_temp("jun_quest/train_begin");  
                tell_object(me, "请你到指定的兵营里面训练队伍！\n"); 
                return;
        }

        if (random(me->query("degree_jungong")) > 1)
        {
                message_vision(HIW "$N将手中令旗一挥，队伍开始集结，"
                        + "开始排列着不同的阵形，忽又散开，\n合时井然有序，分"
                        + "时杂而不乱，看来$N真乃深谙用兵之道的良将啊！\n" NOR, me);
                me->add("eff_qi", 200);
        } else
                message_vision(HIY "$N将手中令旗一挥，可是队伍好象乱哄哄的，"
                        + "根本不听$N的指挥调遣，\n$N直气得吹胡子瞪眼！！！\n" NOR, me);

        liangcao -= 2;
        temp = sprintf("%d", liangcao);
        write_file("/quest/quest_jun/song/liangcao", temp, 1);
        remove_call_out("train_begin");
        call_out("train_begin", 10, me);

        return;
}

void check_me(object me)
{
        object *ob, obb, env, room;
        string *dirs, dir;
        mapping exits;
        int group, num, i, g;

        if (! objectp(me)) return;

        group = (me->query("eff_qi") - me->query("max_qi")) / 2000; 
        me->set("qi", me->query("eff_qi"));
        
        num = group - me->query_temp("jun_quest/group");
        
        g = (int)me->query_temp("jun_quest/group");
        g = 0 - g;
    
        if (num > 0 && me->query_temp("jun_quest/train"))
        {
                tell_object(me, HIR "你的队伍精锐度提高了！\n" NOR);
                me->add_temp("jun_quest/group", num);
        }

        if (num < 0 && ! me->query_temp("jun_quest/train_begin"))
        {
                if (num < g) num = g;
                tell_object(me, HIW "你损失了" HIR + chinese_number(-num)
                        + HIW"营的士兵！\n"NOR);
                me->add_temp("jun_quest/group", num);
        }

        if (group <= 1 && !me->query_temp("jun_quest/train_begin"))
        {
                me->set_temp("jun_quest/group", 0);
        }

        env = environment(me);

        if (! me->query_temp("jun_quest/attack")
        &&  me->query_temp("jun_quest/train") == "cavalry")
        {
                if (mapp(exits = env->query("exits")))
                {
                        dirs = keys(exits);
                        for (i = 0; i < sizeof(dirs); i++)
                        if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                                dirs[i] = 0;
                        dirs -= ({ 0 });

                        if (mapp(exits))
                        {
                                dir = dirs[random(sizeof(dirs))];
                                if (! room = find_object(exits[dir]))
                                        room = load_object(exits[dir]);
                                if (room)  
                                {
                                        ob = all_inventory(room);
                                        if (sizeof(ob) > 0)
                                        {
                                                for (i = 0; i < sizeof(ob); i++)
                                                {
                                                        obb = ob[i]; 
                                                        if (obb->query_temp("jun_quest/party") == "meng")
                                                        {
                                                                me->set_temp("jun_quest/attack", 1);
                                                                call_out("attack_over", 10, me);    
                                                                me->move(room);
                                                                message_vision(
                                                                        HIR "$N率领着一支宋军骑兵朝$n冲杀过来！\n" NOR,
                                                                        me, obb);
                                                                attack_begin(me, obb, room, env, "");
                                                                break;
                                                        }
                                                }
                                        }
                                }
                        }
                } 
        } else
        if (! me->query_temp("jun_quest/attack")
        &&  me->query_temp("jun_quest/train") == "infantry")
        {
                ob = all_inventory(env);   
                if (sizeof(ob) > 0)
                {
                        for (i = 0; i < sizeof(ob); i++)
                        {
                                obb = ob[i]; 
                                if (obb->query_temp("jun_quest/party") == "meng")
                                {
                                        message_vision(HIW "$N大声下令道：步兵营列阵！队伍开始排出整齐"
                                                + "的方阵，在一片闪烁的刀光\n中，$N指挥队伍发起了可怕的冲锋！\n" NOR, me);
                                        me->set_temp("jun_quest/attack", 1);
                                        call_out("attack_over", 10, me);
                                        attack_begin(me, obb, room, env, "");   
                                        break;
                                }
                        }
                }
        } else
        if (! me->query_temp("jun_quest/attack")
        &&  me->query_temp("jun_quest/train") == "archer" 
        &&  me->query("qi") > me->query_temp("jun_quest/group") * 200
        &&  me->query("jing") > me->query_temp("jun_quest/group") * 100)
        {
                if (mapp(exits = env->query("exits")))
                {
                        dirs = keys(exits);
                        for (i = 0; i < sizeof(dirs); i++)
                        if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                                dirs[i] = 0;
                        dirs -= ({ 0 });

                        if (mapp(exits))
                        {
                                dir = dirs[random(sizeof(dirs))];
                                if (! room = find_object(exits[dir]))
                                        room = load_object(exits[dir]);
                                if (room)  
                                {
                                        ob = all_inventory(room);
                                        if (sizeof(ob) > 0)
                                        {
                                                for(i = 0; i < sizeof(ob); i++)
                                                {
                                                        obb = ob[i]; 
                                                        if (obb->query_temp("jun_quest/party") == "meng")
                                                        {
                                                                if (! me->query_temp("weapon")) 
                                                                        me->command("wield bow");
                                                                message_vision(HIB "$N大声下令道：神弩营准备！一排排利箭在阳"
                                                                        + "光下闪闪发光——射击！！\n$N一声令下，万弩齐发！\n" NOR,
                                                                        me);  
                                                                me->set_temp("jun_quest/attack", 1);
                                                                call_out("attack_over", 10, me);    
                                                                attack_begin(me, obb, room, env, dir);
                                                                break;
                                                        }
                                                }
                                        }
                                }
                        }
                } 
        }

        if (file_name(env) == "/quest/quest_jun/myuanmen1" && ! me->is_busy()
        &&  me->query_temp("jun_quest/party") == "song")
                me->command("break");
        remove_call_out("check_me");
        call_out("check_me", 1, me);
        return;
}

int do_order(string arg)
{
        object me = this_player(), ob, ling, obb;
        string who, what, dir;
        int i, n, flag;
        mapping jiang;

        if (! arg || sscanf(arg, "%s to %s", who, what) != 2)
                return notify_fail("请用 order sb to do sth. 来发布号令！\n");

        if (! objectp(ob = present(who,environment(me))))
                return notify_fail("这里没有你可以调度的这名将领！\n");

        if (ob->query_temp("jun_quest/party") != "song")
                return notify_fail("对方不是宋军，如何供你调度？！\n");

        if (! ob->query_temp("jun_quest/train")) 
                return notify_fail("这支队伍尚未训练娴熟，难堪大用！\n");

        if (ob == me)
                return notify_fail("自己命令自己？你不嫌累啊你？！\n");

        if (ob->query("degree_jungong") > me->query("degree_jungong"))
                return notify_fail("对方官衔比你高，调动不了人家！\n");

        switch(what)
        {
        case "follow":
                message_vision(HIY "$N略一沉思，而后果敢的下令道：“$n，"
                        + "本统领决定迎战蒙古大军，\n将军请即刻调派人马协助作战！\n" NOR, me, ob);
                message_vision(HIW "$N大声应道：末将遵命！愿为将军效犬马之劳！\n" NOR, ob);
                ob->set_leader(me);
                break;

        case "guard":
                message_vision(HIY "$N仔细查看了四周的地形，而后果敢的下令道：“$n听令，"
                        + "此处地势险要，\n易守难攻，还烦请将军在此处加以扼守！\n" NOR, me, ob);
                message_vision(HIW "$N大声应道：末将遵命！但存一兵一卒，决不失阵地！\n" NOR, ob);
                ob->set_leader(0);
                break;

        case "stop":
                if (ob->query_temp("jun_quest/escort"))
                        return notify_fail("对方已经另有军务了，无法调动军队！！\n");
                message_vision(HIY "$N仔细查看了四周的地形，而后果敢的下令道：“$n听令，"
                                + "立即停止队伍行进！！\n" NOR, me, ob);
                message_vision(HIW "$N大声应道：末将遵命！！\n" NOR, ob);
                ob->command("move stop");
                break;

        default:
                if (sscanf(what, "move %s", dir) == 1 
                &&  environment(me)->query("exits/" + dir))
                {
                        if (ob->query_temp("jun_quest/escort"))
                                return notify_fail("对方已经另有军务了，无法调动军队！！\n");

                        message_vision(HIY "$N仔细查看了四周的地形，而后果敢的下令道：“$n听令，"
                                + "立即率领部队\n火速行进，不得有误！！\n" NOR, me, ob);
                        message_vision(HIW"$N大声应道：末将遵命！！\n" NOR, ob);
                        ob->set_leader(0);
                        ob->command("move " + dir);
                } else   
                if (environment(me)->query("exits/" + what))   
                {
                        ob->set_leader(0);
                        ob->command("go " + what);
                } else
                        return notify_fail("身为一军之统领，请不要滥用你的军权！\n");
                 break;
        }
        return 1;
}                         

int do_inquiry()
{
        object me = this_player();
        string temp, str;
        int liangcao;  
                                                                    
        str = HIY "您目前统军情况如下：\n" NOR;
        str += me->short(1) + "\n" NOR;
        str += HIW "         目前统军：                        " + HIR
                + chinese_number(me->query_temp("jun_quest/group")) + "营\n";

        temp = read_file("/quest/quest_jun/song/liangcao", 1, 1);
        liangcao = atoi(temp);
        str += HIM "目前军中还有粮草" + chinese_number(liangcao) + "担\n" NOR; 
        write(str);
        return 1;
}  


int do_move(string dir)
{
        object me = this_player();

        if (! dir || dir == "stop")
        {
                remove_call_out("move_on");
                write("部队行进终止！\n");
                return 1;
        }

        if (environment(me)->query("exits/" + dir))
        {
                call_out("move_on", 2, me, dir);
                write("部队开始行进！\n");
                return 1;
        } else
                write("无法移动，没有指定方向的出口！\n");
        return 1;
}

void move_on(object me,string dir)
{
        if (! environment(me)->query("exits/" + dir))
        {
                remove_call_out("move_on");
                write("无法移动，没有指定方向的出口！\n");
                return;
        }

        if (me->is_fighting() || me->query_temp("jun_quest/attack"))
        {
                remove_call_out("move_on");
                call_out("move_on", 4, me, dir);
                return;
        } else
        if (me->command("go " + dir))
        {
                remove_call_out("move_on");
                call_out("move_on", 4, me, dir);
                return;
        } else
        {
                remove_call_out("move_on");
                write("无法移动，行进终止！\n");
                return;
        }
}

void owner_is_killed() { destruct(this_object()); }

