// go.c
// Modified by iszt@pkuxkx, 2007-03-31, removed add("qi", -10) when wearing no cloth

#include <ansi.h>
#include <color.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
  "enter":        "里",
        "out":          "外",
]);

void create()
{ 
        seteuid(getuid());
        set("channel_id","GOGOGO");
}

int main(object me, string arg)
{
        string dest, mout, min, dir,ridemsg;
        object env, prison, obj,weapon,armor,ridee,cloth;
        mapping exit;
        object *f_obs;
        object *inv,*inv1;
        object camelob;
        string str;

        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");

        if (time() - me->query_temp("pause_move/start") < me->query_temp("pause_move/duration"))
        {
                return notify_fail("你暂时不能行动。\n");
        }


        if(!random(100000)) 
        {
                me->start_busy(1);
                return notify_fail("你不小心被什么东西绊了一下，差点摔个大跟头。\n");   
        }
        if( me->query("jingli")<0 )
          return notify_fail("你现在精力不佳，走不动路。\n");
        if( me->query_temp("no_move") )
                return notify_fail("你现在不能移动！\n");
        if (me->is_ghost())
                if ( (base_name(environment(me))[0..7] != "/d/death") && (!wizardp(me)) && userp(me) )
                {
                        me->move("/d/death/gate");
                        return 1;
                }

        if( me->query_temp("pk_exp") )
                return notify_fail(RED "你的官司没有打完，不能移动！！\n" NOR);

        if (me->is_fighting())
        {
                f_obs = me->query_enemy();
                if (sizeof(f_obs) > 0)
                if (objectp(f_obs[0]))
                if (5 + random((int)me->query("dex")) <= 
                        random((int)f_obs[0]->query("dex")))
                {
                        me->start_busy(1);
                        return notify_fail("你逃跑失败。\n");
                }
        }

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        {
                                if(!env->query("outdoors"))
                                return notify_fail("哎哟，你一头撞在墙上，才发现这个方向没有出路。\n");
                                else
                          return notify_fail("这个方向没有出路。\n");
                }
                else
                        return 0;
        }
//      dest = exit[arg];
        if( !env->valid_leave(me, arg) ) return 0;
        
//支持exits目标存放object而不是string by seagate@pkuxk 2011/12/24        
        if (objectp(exit[arg]))
        	obj=exit[arg];
        else {
          if( !stringp(dest = me->query_temp("new_valid_dest")) )
                dest = exit[arg];
//whuan加入
          if( !(obj = load_object(dest)) )
                return notify_fail("你要去的区域还没有连通。\n");

          if( !(obj = find_object(dest)) ) {
                call_other(dest, "???");
          
          if( !(obj = find_object(dest)) )
                return notify_fail("无法移动。\n");}
        }

        if (!wizardp(me) && obj->query("max_user"))
        {
            int user_amount;
            inv1 = deep_inventory(obj); 
            inv1 = filter_array(inv1, (: userp($1) && !$1->query("env/invisibility") && !$1->query_temp("invis") :)); 
            user_amount=sizeof(inv1);
            if (user_amount>=obj->query("max_user"))     
            return notify_fail(HIW"那里已经有"+user_amount+"个人了，站不下再多的了。\n"NOR);
        }
        if (obj->query("no_fight")&&userp(me)&&time() - me->query("killer/time") < 15*60)
        {
            return notify_fail(RED"杀了人之后，别想躲到"+obj->query("short")+"去！\n"NOR);
        }
        me->delete_temp("new_valid_dest");

        
        if( userp(me) && me->query("killer/time") && (time() - me->query("killer/time")) < (me->query("killer/count") + 1)*15*60) 
        {
            if(me->query("jingli") < 10)
            {
                me->start_busy(5);
                write("你已经累得走不动路了。");
                return 1;
            }
        }
		if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;
        if(ridee=me->ride())
                ridemsg = ridee->query("ride_msg")+"着"+ridee->name();
        else  
                ridemsg = "";

//      if(ridee) 
//              return notify_fail("你的座骑走动不了。\n");
        min = "";
        if( me->is_fighting() ) {
                mout = "$N往" + dir + "落荒而逃了。\n";
                min = "$N跌跌撞撞地跑了过来，模样有些狼狈。\n";
        } else {
                min+=ridemsg;
                if (objectp( weapon = me->query_temp("secondary_weapon") ))
                {
                        min = min + "左手拿着" + weapon->query("name") + NOR + "，";
                        if (objectp( weapon = me->query_temp("weapon") ))
                                min = min + "右手拿着" + weapon->query("name") + NOR + "，";
                }
                else if (objectp( weapon = me->query_temp("weapon") ))
                        min = min + "手持" + weapon->query("name") + NOR + "，";
                if (objectp( armor = me->query_temp("armor/cloth") ) || objectp( armor = me->query_temp("armor/armor") ) || objectp( armor = me->query_temp("armor/surcoat") ) )
                        min = min + "身穿" + armor->query("name") + NOR;
                else    
                {
                        if( userp(me) && (!wizardp(me)) && (base_name(environment(me))[0..7] != "/d/bwdh/") )
                        {
                                if (random(2))
                                {
                                         CHANNEL_D->do_channel(this_object(),"rumor","听说"+me->name()+"在街上裸奔啊！！！！～～～～\n");
                                if(me->query("gender")=="女性"&&me->query_per()-me->query("age")>10)
                                CHANNEL_D->do_channel(this_object(),"rumor","流鼻血啊～～～～\n");
                          }
                                tell_object(me,"你发现大家都在奇怪地看着你，原来你身上没穿衣服！你不禁一阵手忙脚乱，头晕目眩...\n");
                                //me->receive_damage("jing",10,"裸奔");
                                me->start_busy(1+random(3)); 
                                me->add_temp("luoben/times",1);
                                if (me->query_temp("luoben/times")>8)
                                {
                                        message_vision(HIW"迎面过来几个衙役，对$N喊道：裸奔有伤风化，跟我们走！\n"NOR,me);
                                        message_vision("衙役给$N套上件粗布麻衣，拴上镣铐，牵到了扬州大牢里。\n",me);
                                        cloth = new("clone/misc/cloth");
                                        cloth->move(me);
                                        cloth->wear();
                                        me->set_temp("luoben/where",environment(me));
                                        prison = new("/d/wizard/prison");
                                        prison->set("short",HIR + "天字第" + chinese_number(random(100)+1) + "号牢房" + NOR);
                                        me->force_me("drop all");
                                        me->move(prison);
                                        me->start_busy(200);
                                        message_vision("衙役将牢门打开，一脚把$N踹了进来，吼道：进去好好反省反省，过两天再放你出去！\n",me);
                                        return 1;
                                }
                        }
                        if (me->query("race")=="人类")//By Zine 2011-5-16 动物也显示光着身子走了过来太奇怪了，加个判断
                        {
                            min = min + "光着身子" + NOR;
                        }
                        
                }
                mout = "$N往" + dir + "离开。\n";
                min = "$N" + min + "走了过来。\n";
        }
        if ((me->query("position") != "zmuduser") && (me->query("env/brief")))
                printf(JSP "parent.look_room(\"%s\", \"%s\", \"%s\")" NSP, 
                        "", "如果在行走中仍要看到周围描述，请unset brief\n", "");        
        if( me->query("msg_come") ) min = me->query("msg_come");
        if( me->query("msg_leave") ) {
                mout = me->query("msg_leave");
                mout = replace_string(mout, "$E", dir);
        }
        mout = replace_string(mout, "$N", me->name());
        min = replace_string(min, "$N", me->name());

        if((userp(me) || !objectp(me->query_temp("rider"))) && (!wizardp(me) || !me->query("env/invisibility"))&& (!environment(me)->query("least_msg")) )
        tell_room( environment(me), mout, ({ me }));
/*        if (wizardp(me) ) 
        	 printf("移动测试：%O\n",obj);*/
        if( me->move(obj) ) {
            if (userp(me) &&
            	  time() - me->query("killer/time") < 15*60 &&
            	  time()-me->query("killer/catch_me_info")>30 &&
            	  environment(me) )
            {
                me->set("killer/catch_me_info",time());
                message("rumor",HIM"【谣言】某人: 听说"+HIR+"杀人凶手"+HIM+me->query("name")+HIM+"在"+AREA_INFO->get_my_area(me)+"的"+environment(me)->query("short")+HIM+"附近出现过。\n"+NOR,users());
            }
            
            if( userp(me) &&
            	  me->query("killer") && 
            	  time() - me->query("killer/time") < (me->query("killer/count") + 1)*15*60 )
            {
                write("你刚刚杀了人，一想到从此江湖的追杀无穷无尽，你不禁胆颤心惊。\n");
                me->add("jingli",-1);
            }
            if (!wizardp(me))//trap
			{
				inv1=all_inventory(obj);
				inv1=filter_array(inv1, (: userp($1) && living($1) && $1->query_temp("stunt/trap/target") :));
				if (sizeof(inv1)>0)
				for (int i=0;i<sizeof(inv1);i++)
				if (inv1[i]->query_temp("stunt/trap/place")==obj&&inv1[i]->query_temp("stunt/trap/target")==me->query("id")
					&&time()<inv1[i]->query_temp("stunt/trap/time")&&inv1[i]->query("combat_exp")*3/2>me->query("combat_exp"))
				{
					me->add_busy(inv1[i]->query_temp("stunt/trap/busy_time"));
					message_vision(RED+"$N"+RED+"一不留神给$n"+RED+"狠狠拌了一跤。\n"+NOR,me,inv1[i]);
				}
			}    
            me->remove_all_enemy();
            if((userp(me) || 
            	 !objectp(me->query_temp("rider"))) && 
            	 (!wizardp(me) || 
            	  !me->query("env/invisibility")) && 
            	  (!environment(me)->query("least_msg")) )
              tell_room( environment(me), min, ({ me }) );
            
            me->set_temp("pending", 0);
            if (env != obj && objectp(env) )
              all_inventory(env)->follow_me(me, arg);
            //一个房间如果多次经过（50次左右），就检查一次是否物品过多
            //random(50)是为了减少系统消耗
            //原来此功能在reset()中，但似乎会引起定时更新时lag
            //by icer
				    //副本中不要毫毛。Jason

            if (!environment(me)->query("real_dark") && random(50) <= 1) 
            {
                inv = all_inventory(obj); 
                
                if (sizeof(inv) > 30) 
                {
                    camelob = load_object("/clone/npc/camel1"); 
                    camelob->move(obj); 
                    camelob->init();
                }
            }                        
		        if(random(10) == 0)
		        {
		        	//anti robot
					    tell_object(me,">\n");
				    }                
            return 1;
        }

        return 1;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP);
        return 1;
}
