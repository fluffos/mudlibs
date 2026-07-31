// 定义刷任务的地点,将会在任务进行过程中给予标志   By lsxk@hsbbs
// 更新.h 文件删除job 结束以前的kill 记号防止其他job 中死亡给予参加HD job的人add tj By server
// job结束后。将自动取消id的通缉状态(例如chousui-zhang/qianzhu-wandushou) By Spiderii@ty
//Update by lsxk@hsbbs 2008/1/10   奖励统一调用TASKREWARD_D来计算。

#define JOB_REFRESH_PLACE "/d/xiangyang/cross2"

// 任务房间
string* xyjob_room = ({
        __DIR__"baihumen",
        __DIR__"bank",
        __DIR__"baozipu",
        __DIR__"bcx1",
        __DIR__"bcx2",
        __DIR__"bcx3",
        __DIR__"bcx4",
        __DIR__"bhmnj",
        __DIR__"bingying",
        __DIR__"bjie1",
        __DIR__"bjie2",
        __DIR__"bjie3",
        __DIR__"chalou",
        __DIR__"chalou2",
        __DIR__"chayedian",
        __DIR__"chemahang",
        __DIR__"eroad1",
        __DIR__"chengyipu",
        __DIR__"chucshi",
        __DIR__"cross1",
        __DIR__"cross2",
        __DIR__"chengyipu",
        __DIR__"damen",
        __DIR__"datiepu",
        __DIR__"dcx1",
        __DIR__"dcx2",
        __DIR__"dcx3",
        __DIR__"dcx4",
        __DIR__"dcx5",
        __DIR__"djie1",
        __DIR__"djie2",
        __DIR__"doufufang",


        __DIR__"dpailou",
        __DIR__"eroad1",
        __DIR__"feizhai",
        __DIR__"guangc",
        __DIR__"junying",
        __DIR__"mujiangpu",
        __DIR__"ncx1",
        __DIR__"ncx2",
        __DIR__"ncx4",
        __DIR__"ncx3",
        __DIR__"ncx5",
        __DIR__"njie1",
        __DIR__"njie2",
        __DIR__"njie3",
        __DIR__"nroad1",
        __DIR__"outeroad1",
        __DIR__"outnroad1",
        __DIR__"outsroad1",
        __DIR__"outwroad1",
        __DIR__"qinglongmen",
        __DIR__"shaobingpu",
        __DIR__"shuoshug",
        __DIR__"sishu",
        __DIR__"xcx1",
        __DIR__"xiaocd",
        __DIR__"xcx2",
        __DIR__"xcx3",
        __DIR__"xcx4",
        __DIR__"xcx5",
        __DIR__"xiyuan",
        __DIR__"xjie",
        __DIR__"xpailou",



        __DIR__"xuanwumen",
        __DIR__"xyudian",
        __DIR__"yamen",
        __DIR__"yaopu",
        __DIR__"yingzhang",
        __DIR__"ymzhengting",
        __DIR__"zahuopu",
        __DIR__"zhuquemen",
        __DIR__"zqmnj",
        __DIR__"zrdian",
});

void xyjob_1() //任务准备
{
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));

        if(JOB_REFRESH_PLACE->query("xyjobing")) return;

        if (!meng || !guo)
        {
        	remove_call_out("xyjob_1");
        	call_out("reset_xyjob",300 + random(180));
        	return;
        }
        CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"听说蒙古兵营正在召集人马，准备进攻襄阳！");
        CHANNEL_D->do_channel(meng, "chat", "中原的武人们！当今汉人皇帝昏庸，大蒙古方能带来天下安逸！");
        CHANNEL_D->do_channel(meng, "chat", "本将军不希望战祸连年，因此征求武林高手，攻下襄阳，宋军自然望风披靡！");
        CHANNEL_D->do_channel(guo, "chat", "汉人的问题由汉人自己解决，岂能让外族乘机入主中原？");
        CHANNEL_D->do_channel(guo, "chat", "各位英雄侠女，中原的命运就在你们手中了，请一展身手，为国家出力吧！");
        guo->set("ready_defend", 1);
        meng->set("ready_attack", 1);
        JOB_REFRESH_PLACE->set("xyjobing",1);
        remove_call_out("xyjob_1");
        call_out("xyjob_2", 200);
}

void xyjob_2() // 任务开始
{
        int at, df, a_exp, d_exp, i = 0;
        object weishi;
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
        string room;

        df = sizeof(defenders);
        at = sizeof(attackers);

        if (!guo)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"襄阳主帅郭靖已被杀，蒙古军转移攻势了！");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else if (!meng)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"蒙古军主帅蒙哥已被杀，军队溃散了！");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else if (df < 3)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"襄阳守军不足，蒙古军只留下少数兵士，便挥军他处了！");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else if (at < 3)
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"蒙古军组织精锐队人手不足，暂时放弃了襄阳的进攻！");
                remove_call_out("xyjob_2");
                call_out("reset_xyjob", 5);
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"蒙古军开始了襄阳的进攻！");
                CHANNEL_D->do_channel(meng, "chat", "目标襄阳，杀啊！有了这些武林高手，今天襄阳就是我的了！");
                CHANNEL_D->do_channel(guo, "chat", "笑话，鹿死谁手还不知道呢，让你见识见识我们中原的高手！");
                guo->set("start_defend",1);
                meng->set("start_attack",1);
                while(i < 3)
                {
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/xuanwumen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/zhuquemen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/qinglongmen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/baihumen");
                        weishi = new("/d/xiangyang/npc/weishi");
                        weishi->move("/d/xiangyang/cross2");
                        i ++ ;
                }
                reset_eval_cost();
                for(i = 0; i < at; i++)
                {
                        room = xyjob_room[random(sizeof(xyjob_room))];
                        attackers[i]->set_temp("xyjob/attack_ready",1);
                        if (attackers[i]->is_ghost() || !attackers[i]->query_temp("special_die"))
                        	continue;
                        attackers[i]->move(room);
                }
                for(i = 0; i < df; i++)
                {
                        room = xyjob_room[random(sizeof(xyjob_room))];
                        defenders[i]->set_temp("xyjob/defend_ready",1);
                        if (defenders[i]->is_ghost() || !defenders[i]->query_temp("special_die"))
                        	continue;
                        defenders[i]->move(room);
                }
                call_out("xyjob_random_move", 10);
                remove_call_out("xyjob_2");
            	call_out("xyjob_3", 300);
            	for(i = 0; i < df; i++)
                    	d_exp += defenders[i]->query("combat_exp");
                for(i = 0; i < at; i++)
                    	a_exp += attackers[i]->query("combat_exp");
                log_file("job/xyjob", sprintf("%s 襄阳攻防战开始，攻方%d人经验共%d，守方%d人经验共%d。\n",
                ctime(time())[4..19],sizeof(attackers),a_exp,sizeof(defenders),d_exp));
        }
}

void xyjob_3() // 判断胜负
{
        int i, at, df;
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
        object *attacker = filter_array(attackers, (: $1->query_temp("living") :));
        object *defender = filter_array(defenders, (: $1->query_temp("living") :));

	df = sizeof(defenders);
        at = sizeof(attackers);

        if (sizeof(attacker) > sizeof(defender))
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"听说蒙古兵攻下了襄阳城！");
                for(i = 0; i < at; i++)
                        attackers[i]->add_temp("xyjob/attack", 1);
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"听说襄阳守军杀退了蒙古军！");
                for(i = 0; i < df; i++)
                        defenders[i]->add_temp("xyjob/defend", 1);
        }

        if (!guo)
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"襄阳守军主帅郭靖殉难！");
        else
        {
                guo->delete("ready_defend");
                guo->delete("start_defend");
        }

        if (!meng)
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"蒙古军主帅蒙哥殉难！");
        else
        {
                meng->delete("ready_attack");
                meng->delete("start_attack");
        }
        remove_call_out("xyjob_random_move");
        remove_call_out("xyjob_3");
	call_out("xyjob_4", 5);
}

void xyjob_4() // 发放奖励
{
        int i, at, df, exp, nexp, pot, SJ_Credit;
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));

	at = sizeof(attackers);
	df = sizeof(defenders);

        for(i = 0; i < at; i++)
        {

/*
                exp = attackers[i]->query_temp("xyjob/attack")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*df)
                        exp = 1000 + 200*df -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                pot = exp/6 +random(exp/10);
//                SJ_Credit = exp*2/400;
//                attackers[i]->add("SJ_Credit",SJ_Credit);
                attackers[i]->add("combat_exp",exp);
                if(attackers[i]->query("potential") + pot > attackers[i]->query("max_pot"))
                        attackers[i]->set("potential", attackers[i]->query("max_pot"));
                else
                        attackers[i]->add("potential", pot);
                message_vision(HIW"\n$N获得了"+CHINESE_D->chinese_number(exp)+
                "点经验，"+ CHINESE_D->chinese_number(pot)+
                "点潜能的奖励。"NOR"\n", attackers[i]);
                attackers[i]->add("shen",-nexp);
                message_vision(HIW"\n$N觉得一股邪念自心中生起。"NOR"\n",attackers[i]);
                attackers[i]->add("job_time/襄阳攻防",1);
*/

//                SJ_Credit = (attackers[i]->query_temp("xyjob/attack") - 1) * 2;
//                if(SJ_Credit<0) SJ_Credit = 0;

                TASKREWARD_D->get_reward(attackers[i],"襄阳攻防",-1,0,0,4,attackers[i]->query_temp("xyjob/attack")-1,3400+random(101));

                attackers[i]->clear_conditions_by_type("poison");
                attackers[i]->clear_conditions_by_type("hurt");
                attackers[i]->clear_conditions_by_type("busy");
                attackers[i]->clear_conditions_by_type("zhenqi");
                attackers[i]->clear_condition("killer"); // By Spiderii@ty
                attackers[i]->remove_all_killer();
                attackers[i]->delete_temp("kill_other");
                attackers[i]->delete_temp("other_kill");
                attackers[i]->dismiss_team();
                attackers[i]->clear_condition("job_busy");
/*
                log_file("job/xyjob", sprintf("%s %s(%s)%d次攻城得到经验%d，潜能%d。\n",
                ctime(time())[4..19],attackers[i]->name(1),attackers[i]->query("id"),(int)attackers[i]->query("job_time/襄阳攻防"),exp,pot));
*/
        }
        for(i = 0; i < df; i++)
        {
/*
                exp = defenders[i]->query_temp("xyjob/defend")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*at)
                        exp = 1000 + 200*at -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
//                SJ_Credit = exp*2/400;
                pot = exp/6 +random(exp/10);
//                defenders[i]->add("SJ_Credit",SJ_Credit);
                defenders[i]->add("combat_exp",exp);
                if (defenders[i]->query("potential") + pot > defenders[i]->query("max_pot"))
                        defenders[i]->set("potential", defenders[i]->query("max_pot"));
                else
                        defenders[i]->add("potential", pot);
                message_vision(HIW"\n$N获得了"+CHINESE_D->chinese_number(exp)+
                "点经验，"+ CHINESE_D->chinese_number(pot)+
                "点潜能的奖励。"NOR"\n", defenders[i]);
                defenders[i]->add("shen",nexp);
                message_vision(HIW"\n$N的侠义正气上升了！"NOR"\n",defenders[i]);
                defenders[i]->add("job_time/襄阳攻防",1);
*/

//                SJ_Credit = (defenders[i]->query_temp("xyjob/defend") - 1) * 2;
//                if(SJ_Credit<0) SJ_Credit = 0;
                TASKREWARD_D->get_reward(defenders[i],"襄阳攻防",1,0,0,4,defenders[i]->query_temp("xyjob/defend")-1,3400+random(101));

                defenders[i]->clear_conditions_by_type("poison");
                defenders[i]->clear_conditions_by_type("hurt");
                defenders[i]->clear_conditions_by_type("busy");
                defenders[i]->clear_conditions_by_type("zhenqi");
                defenders[i]->clear_condition("killer"); // By Spiderii@ty
                defenders[i]->remove_all_killer();
                defenders[i]->delete_temp("kill_other");
                defenders[i]->delete_temp("other_kill");
                defenders[i]->dismiss_team();
                defenders[i]->clear_condition("job_busy");
/*
                log_file("job/xyjob", sprintf("%s %s(%s)%d次守城得到经验%d，潜能%d，天涯通宝%d。\n",
                ctime(time())[4..19],defenders[i]->name(1),defenders[i]->query("id"),(int)defenders[i]->query("job_time/襄阳攻防"),exp,pot));
*/
        }
        remove_call_out("xyjob_4");
        call_out("reset_xyjob", 5);
        "/cmds/std/xyjob"->xyjob_reset();
}

void reset_xyjob() // reset all
{
        int i, at, df;
        object *inv, room;
        object guo = present("guo jing", load_object("/d/xiangyang/xuanwumen"));
        object meng = present("meng ge", load_object("/d/xiangyang/yingzhang"));
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));

	at = sizeof(attackers);
	df = sizeof(defenders);

        for(i = 0; i < at; i++)
        	attackers[i]->clear_condition("job_busy");
        for(i = 0; i < df; i++)
		defenders[i]->clear_condition("job_busy");

        "/cmds/std/xyjob"->xyjob_reset();
        JOB_REFRESH_PLACE->delete("xyjobing");

        if (guo)
        {
                guo->delete("ready_defend");
                guo->delete("start_defend");
        }
        else
        {
                guo = new("/kungfu/class/gaibang/guojing");
                guo->move("/d/xiangyang/xuanwumen");
        }

        if (meng)
        {
                meng->delete("ready_attack");
                meng->delete("start_attack");
        }
        else
        {
                meng = new("/d/xiangyang/npc/mengge");
                meng->move("/d/xiangyang/yingzhang");
        }

        room = load_object("/d/xiangyang/xuanwumen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/zhuquemen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/baihumen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/qinglongmen");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        room = load_object("/d/xiangyang/cross2");
        inv = all_inventory(room);
        i = sizeof(inv);
        while (i--)
                if (inv[i]->query("id") == "weishi")
                        destruct(inv[i]);
        reset_job();
}

int xyjob_attack_check(object ob)
{
        if (userp(ob) && ob->query_temp("xyjob/mg_attack") && ob->query_temp("living"))
		return 1;
	return 0;
}

int xyjob_defend_check(object ob)
{
        if (userp(ob) && ob->query_temp("xyjob/xy_defend") && ob->query_temp("living"))
		return 1;
	return 0;
}

void xyjob_random_move() // 随机分配
{
        int i, j, at ,df;
        object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
        object *attacker = filter_array(attackers, (: $1->query_temp("living") :));
        object *defender = filter_array(defenders, (: $1->query_temp("living") :));
        object *obj, *at_rooms = ({}), *df_rooms = ({});

	at = sizeof(attacker);
	df = sizeof(defender);

        for (i = 0; i < at; i ++)
        {
                foreach (object room in at_rooms)
                	if (room == environment(attacker[i]))
                		continue;
        	at_rooms += ({environment(attacker[i])});
        }
        for (i = 0; i < df; i ++)
        {
        	foreach (object room in df_rooms)
                	if (room == environment(defender[i]))
                		continue;
                df_rooms += ({environment(defender[i])});
        }

	at = sizeof(at_rooms);
	df = sizeof(df_rooms);

	for (i = 0; i < at; i ++)
	{
		obj = all_inventory(at_rooms[i]);
		obj = filter_array(obj, (: xyjob_attack_check :));
		if (sizeof(obj) > 3)
			for (j = 0;j < sizeof(obj);j ++)
			{
				if (obj[j]->is_fighting())
					continue;
				obj[j]->move(xyjob_room[random(sizeof(xyjob_room))]);
				tell_object(obj[j], "襄阳就在眼前，请勿在此耽搁，速去拿下城池！\n");
			}
        }
	for (i = 0; i < df; i ++)
	{
		obj = all_inventory(df_rooms[i]);
		obj = filter_array(obj, (: xyjob_defend_check :));
		if (sizeof(obj) > 3)
			for (j = 0;j < sizeof(obj);j ++)
			{
				if (obj[j]->is_fighting())
					continue;
				obj[j]->move(xyjob_room[random(sizeof(xyjob_room))]);
				tell_object(obj[j], "敌人正在攻城，请勿在此耽搁，速去歼灭敌人！\n");
			}
        }
       	remove_call_out("xyjob_random_move");
	call_out("xyjob_random_move", 10);
}
