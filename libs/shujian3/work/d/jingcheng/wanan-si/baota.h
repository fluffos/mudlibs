//baota.h

int do_jiejiu(string arg);

void init()
{
        object me = this_player();
        add_action("do_jiejiu", "jiejiu");
        if (!me->query_temp("day_jobs/was_job") && userp(me) && !wizardp(me))
        {
                message_vision("什么人竟然擅闯万安寺？快放箭！\n");
                message_vision("一阵乱箭射来，$N连中数箭，落荒而逃。\n", me);
                me->move("/d/nanyang/kedian1");
                me->unconcious();
        }
}

int valid_leave(object me, string dir)
{
        object ob = present("yuanbing shouwei", environment(me));
        if (ob)
                return notify_fail("元兵守卫冲到你面前大叫：哪里走！\n");
        if (!query("save"))
                return notify_fail("还没救人就走了？不是吧你？来做什么的？\n");
        if (dir == "up" && me->query_temp("day_jobs/was_job/floor") > FLOOR)
                return notify_fail("你已经逃出来了，还上去做什么？\n");

        return ::valid_leave(me, dir);
}
string do_gift(object me, int mun)
{
        int exp,pot;
        
        if (me && mun)//以层数给奖励
        {	   
                if (mun > 9)
                        exp = 400;
                else
                if (mun > 6)
                        exp = 300;
                else
                        exp = 200;
                
                if (me->query_team())
                        exp = exp * 2 / 3;
                
                exp = me->add_exp_combat(exp,"苦头陀","万安寺营救");
                pot = exp/6;
                me->apply_condition("job_busy", 5);
                me->set("job_name", "万安寺营救");
                tell_object(me,sprintf(HIW"你获得了"+CHINESE_D->chinese_number(exp)+                      
                                "点经验，"+ CHINESE_D->chinese_number(pot)+
                                "点潜能的奖励。\n"NOR"\n", me));

                me->add( "potential", pot );
                log_file("job/was", sprintf("%s %s(%s)%d次万安寺"+mun+"层营救任务得到经验%d，潜能%d。\n",
                                ctime(time())[4..19],me->name(1),me->query("id"),(int)me->query("job_time/万安寺副本"),exp,pot));
                if (mun>=13) {
                        me->clear_conditions_by_type("poison");//清除所有毒
                        me->clear_conditions_by_type("hurt");//清除所有内伤
                        me->clear_condition("was_job");
                        me->delete_temp("day_jobs/was_job");
                        /*确保玩家不死,全部恢复到最佳状态*/
                        me->reincarnate();
                        me->move("/d/nanyang/kedian1");
                }
        }
        
        return HIY"辛苦了。"NOR"\n";
}
string do_gift_ob(object me, string id, int mun) 
{
        object ob;
        /*物品奖励发放*/
        if (me && id) {
                        ob = new(id);
                if (ob && ob->move(me)){
                        log_file("job/was_gift", sprintf("%s %s(%s)%d次万安寺"+mun+"层营救任务得到奖励%s。\n",
                                ctime(time())[4..19],me->name(1),me->query("id"),(int)me->query("job_time/万安寺副本"),ob->short()));
                        return "恭喜你获得奖励：" + ob->short()+"！\n";
                }
                else {
                        log_file("job/was_gift", sprintf("%s %s(%s)%d次万安寺"+mun+"层营救任务奖励(%s)出错失败！\n",
                                ctime(time())[4..19],me->name(1),me->query("id"),(int)me->query("job_time/万安寺副本"), id));
                        return "你未得到物品("+id+")奖励，请联系巫师。\n";
                }
        } else
                return "参数不齐全，请联系巫师。\n";
}

int do_jiejiu(string arg)
{
        int jilu, rss; 
        object me = this_player(), ob = present("yuanbing shouwei", environment(me));
        object obj, *team, ob_rz;
        object *obs = all_inventory();
        if (query("save"))
                return notify_fail("已经解救成功，向上前进吧。\n");
        if (ob)
                return notify_fail("这里还有守卫在，如何进行解救？\n"); 
        if (!me->query_temp("day_jobs/was_job/asked"))
                return notify_fail(SAVE_NPC + "已经不需要你解救了。\n"); 
        
        ob_rz = present("npc rz", environment(me));
        
        if (!ob_rz)
                return notify_fail(SAVE_NPC+"已经被解成功救了，继续前进吧。\n"); 
        
        if (team = me->query_team())
                rss = sizeof(team);
                
        if (rss < 1) rss = 1; 
        
        message_vision(HIC"$N见守卫已经全部杀光，便上前打开牢门，将" + SAVE_NPC + "解救出来。"NOR"\n", me);
        
        foreach(ob in obs) {
                if (userp(ob))
                {
                        if (ob->query_temp("day_jobs/was_job/floor") < FLOOR)
                                ob->set_temp("day_jobs/was_job/floor", FLOOR);
                        //奖励
                        do_gift(ob, FLOOR);
                                 
                        jilu = random(100);
                        //物品爆出几率，和组队人数有关
                        if (FLOOR < 7 && jilu < (30/rss))
                                do_gift_ob(me, "/clone/shizhe/shi", FLOOR);
                        else
                        if (FLOOR >= 7 && jilu < (40/rss))
                                do_gift_ob(me, "/clone/shizhe/shi", FLOOR);
                }
        } 
        set("save", 1); 
        write(SAVE_NPC+"躬身道：“多谢了”！\n说完，"+SAVE_NPC+"一拐一瘸地走下了万安寺。\n");
        destruct(ob_rz);
        
        //CHANNEL_D->do_channel( this_object(), "rumor",sprintf("万安寺第"+FLOOR+"层关押者被解救出来了！"));
                
        if (FLOOR>=13) 
                CHANNEL_D->do_channel( this_object(), "rumor",sprintf("万安寺众人全部被解救出来了！"));
        
        return 1;
}

int query_floor()
{
        return FLOOR;
}

void check_death(object ob)
{
//        ob->delete_temp("day_jobs/was_job");
}

void setup_shouwei(int num)
{
        object ob;
        
        while (num--)
                new(NPC_D("jingcheng/yuanbing-shouwei"))->move(this_object());
        
        ob = new(NPC_D("jingcheng/npc_rz"));
        if (ob) {
                ob->set("name", SAVE_NPC);
                ob->move(this_object());
        }
}
