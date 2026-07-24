int do_study(string arg)
{
	string *skill_name = ({
               "strike",          //趙客縵胡纓
               "sword",           //吳鉤霜雪明
               "dodge",           //銀鞍照白馬
               "throwing",        //颯沓如流星
               "pixie-jian",      //十步殺一人 sword
               "shenxing-baibian",//千里不留行 dodge
               "lingboweibu",     //事了拂衣去 dodge
               "shenkong-xing",   //深藏身與名 dodge
               "unarmed",         //閑過信陵飲 cuff or strike or unarmed
               "taiji-jian",      //脫劍膝前橫 sword
               "parry",           //將炙啖朱亥
               "blade",           //持觴勸侯嬴
               "count",           //三杯吐然諾 force 暫時先count吧
               "cuff",            //五獄倒為輕 cuff or strike or unarmed
               "staff",           //眼花耳熱后   魯達禪杖
               "claw",            //競氣素霓生 cuff or strike or unarmed
               "hammer",          //救趙揮金錘 sword
               "hand",            //邯鄲先震驚 force
               "array",           //千秋二壯士
               "force",           //亙赫大梁城 force
               "finger",          //縱死俠骨香   指法
               "club",            //不慚世上英   齊眉棍
               "whip",            //誰能書閣下
               "taixuan-gong"     //白首太玄經
        });
        object me, where;
        int jing_cost, learn_pot, item;
        string skillname;

        me = this_player();
        if( !arg || ( arg != "wall" ) )
                return notify_fail("你要學什么\呀？\n");
        if ((int)me->query("combat_exp")<50000)
                return notify_fail("你的經驗太低, 沒法領悟石壁內容。\n");
        if ((int)me->query_skill("literate",1)<1)
                return notify_fail("你暈了吧! 還是先去學點文化吧。\n");
        jing_cost = 30 + random(me->query_int());
        if( me->query("jing") < jing_cost)
                return notify_fail("你現在太累了，休息一會兒再來吧。\n");
        me->receive_damage("jing",jing_cost);
	where = environment(me);
	switch (file_name(where))
	{
		case "/d/xiakedao/shiroom01": item = 0; break;
		case "/d/xiakedao/shiroom02": item = 1; break;
		case "/d/xiakedao/shiroom03": item = 2; break;
		case "/d/xiakedao/shiroom04": item = 3; break;
		case "/d/xiakedao/shiroom05": item = 4; break;
		case "/d/xiakedao/shiroom06": item = 5; break;
		case "/d/xiakedao/shiroom07": item = 6; break;
		case "/d/xiakedao/shiroom08": item = 7; break;
		case "/d/xiakedao/shiroom09": item = 8; break;
		case "/d/xiakedao/shiroom10": item = 9; break;
		case "/d/xiakedao/shiroom11": item = 10; break;
		case "/d/xiakedao/shiroom12": item = 11; break;
		case "/d/xiakedao/shiroom13": item = 12; break;
		case "/d/xiakedao/shiroom14": item = 13; break;
		case "/d/xiakedao/shiroom15": item = 14; break;
		case "/d/xiakedao/shiroom16": item = 15; break;
		case "/d/xiakedao/shiroom17": item = 16; break;
		case "/d/xiakedao/shiroom18": item = 17; break;
		case "/d/xiakedao/shiroom19": item = 18; break;
		case "/d/xiakedao/shiroom20": item = 19; break;
		case "/d/xiakedao/shiroom21": item = 20; break;
		case "/d/xiakedao/shiroom22": item = 21; break;
		case "/d/xiakedao/shiroom23": item = 22; break;
		case "/d/xiakedao/shiroom24": item = 23; break;
		default: break;
	}

        message_vision("$N正在專研石壁上的圖案和注釋。\n",me);

        if (me->query_skill(skill_name[item],1)<0)
        {
          write("你望著石壁冥思苦想了一會，發覺上面的東西對你來說太深奧了。\n");
          return 1;
        }
        if (me->query_skill(skill_name[item],1)>=250)
        {
          write("你望著石壁冥思苦想了一會，發覺上面的東西對你來說太淺薄了。\n");
          return 1;
        }
        if (item == 4)
        {
                if ((string)me->query("gender") != "無性" )
                {
                        write("可是壁上是辟邪劍法圖譜，欲練神功\，必先自宮。\n");
                        return 1;
                }
        }
	else
        {
                if( !SKILL_D(skill_name[item])->valid_learn(me) )
                return SKILL_D(skill_name[item])->valid_learn(me);
        }
        if((int)(me->query_skill(skill_name[item],1) * 
                 me->query_skill(skill_name[item],1) * 
                 me->query_skill(skill_name[item],1)) /10 >= me->query("combat_exp"))
        {
                write("你對著石壁冥思苦想了一會，毫無收獲。\n");
                return 1;
        }
	learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int"))
            - (int)(me->query_skill("literate",1)/2);
	if (learn_pot > 0)
        {
                me->improve_skill(skill_name[item], learn_pot);
                write("你對著石壁冥思苦想了一會，似乎"+CHINESE_D->chinese(skill_name[item])+"有些心得。\n");
        }
        else write("你對著石壁冥思苦想了一會，可是成見太深，似乎沒啥心得。\n");
        return 1;
}
