// tufei for jiaofei task
// 专门负责增援

inherit NPC;              

#include <ansi.h>

void heal();
void wield_weapon(string weapon);
int set_gaibang(object me, int level, int armed);
void move_on();

int path = 0;
int position = 0;

mixed* paths = ({
    //拇指峰
    ({"/d/jiaofei/shanjiao","/d/jiaofei/shijie1","/d/jiaofei/shijie2","/d/jiaofei/shijie3","/d/jiaofei/xiaoting","/d/jiaofei/mshanlu1",
        "/d/jiaofei/mshanlu2","/d/jiaofei/mshanlu3","/d/jiaofei/mshanlu4","/d/jiaofei/mshanlu5","/d/jiaofei/mshanlu6",
        "/d/jiaofei/msimen","/d/jiaofei/mguangchang","/d/jiaofei/mdadian","/d/jiaofei/mguangchang2","/d/jiaofei/mhoushan","/d/jiaofei/mshanlu7",
        "/d/jiaofei/mshanlu8","/d/jiaofei/mshanlu9","/d/jiaofei/mshanlu10","/d/jiaofei/mfengding","/d/jiaofei/mtai",
        "/d/jiaofei/mdshanlu1","/d/jiaofei/mdshanlu2","/d/jiaofei/mdshanlu3","/d/jiaofei/zmshanlu1","/d/jiaofei/zmshanlu2","/d/jiaofei/zmshanding"
        }),
    //食指峰
    ({"/d/jiaofei/shanjiao","/d/jiaofei/shijie1","/d/jiaofei/shijie2","/d/jiaofei/shijie3","/d/jiaofei/xiaoting",
        "/d/jiaofei/jshanlu","/d/jiaofei/jiulongtang",
        "/d/jiaofei/sshanlu1","/d/jiaofei/sshanlu2","/d/jiaofei/laotuxia","/d/jiaofei/laotuxia1","/d/jiaofei/laotuxia2",
        "/d/jiaofei/sshanlu3","/d/jiaofei/sguangchang","/d/jiaofei/sdayuan","/d/jiaofei/sqinglongtang","/d/jiaofei/shouyuan",
        "/d/jiaofei/sshijie1","/d/jiaofei/sshijie2","/d/jiaofei/sshijie3","/d/jiaofei/sfengding","/d/jiaofei/stai","/d/jiaofei/sdshanlu1",
        "/d/jiaofei/sdshanlu2","/d/jiaofei/sdshanlu3","/d/jiaofei/zsshanlu1","/d/jiaofei/zsshanlu2","/d/jiaofei/zsshanding"  
    }),
    //中指峰
    ({"/d/jiaofei/shanjiao","/d/jiaofei/shijie1","/d/jiaofei/shijie2","/d/jiaofei/shijie3","/d/jiaofei/xiaoting",
        "/d/jiaofei/jshanlu","/d/jiaofei/jiulongtang",
        "/d/jiaofei/zshanlu1","/d/jiaofei/zshanlu2","/d/jiaofei/zshanlu3","/d/jiaofei/zshanlu4","/d/jiaofei/zshanlu5",
        "/d/jiaofei/zshanlu6","/d/jiaofei/zguangchang","/d/jiaofei/zguangmingdian","/d/jiaofei/zhouyuan","/d/jiaofei/zxuanya","/d/jiaofei/zshanding"        
    }),    
    //无名指峰
    ({"/d/jiaofei/shanjiao","/d/jiaofei/shijie1","/d/jiaofei/shijie2","/d/jiaofei/shijie3","/d/jiaofei/xiaoting",
        "/d/jiaofei/jshanlu","/d/jiaofei/jiulongtang",
        "/d/jiaofei/wshanlu1","/d/jiaofei/wshulin1","/d/jiaofei/wshulin2","/d/jiaofei/wshulin3","/d/jiaofei/wshulin4",
        "/d/jiaofei/wshulin5","/d/jiaofei/wshulin6","/d/jiaofei/wxiaolu1","/d/jiaofei/wxiaolu2","/d/jiaofei/wxiaolu3","/d/jiaofei/wxiaolu4",
        "/d/jiaofei/wxiaolu5","/d/jiaofei/wshijie1","/d/jiaofei/wshijie2","/d/jiaofei/wguangchang","/d/jiaofei/wdating","/d/jiaofei/whouyuan",
        "/d/jiaofei/wshijie3","/d/jiaofei/wshijie4","/d/jiaofei/wfengding","/d/jiaofei/wtai","/d/jiaofei/wdshanlu1","/d/jiaofei/wdshanlu2",
        "/d/jiaofei/wdshanlu3","/d/jiaofei/zwshanlu1","/d/jiaofei/zwshanlu2","/d/jiaofei/zwshanding"
    }),        
    //小指峰
    ({"/d/jiaofei/shanjiao","/d/jiaofei/shijie1","/d/jiaofei/shijie2","/d/jiaofei/shijie3","/d/jiaofei/xiaoting",
        "/d/jiaofei/jshanlu","/d/jiaofei/jiulongtang",
        "/d/jiaofei/xshanlu1","/d/jiaofei/xshanlu2","/d/jiaofei/xshanlu3","/d/jiaofei/xshijie1","/d/jiaofei/xshijie2",
        "/d/jiaofei/xzhuqueguan","/d/jiaofei/xqianyuan","/d/jiaofei/xzhengdian","/d/jiaofei/xhouyuan","/d/jiaofei/xfengding","/d/jiaofei/xtai",
        "/d/jiaofei/xdshanlu1","/d/jiaofei/xdshanlu2","/d/jiaofei/xdshanlu3","/d/jiaofei/zxshanlu1","/d/jiaofei/zxshanlu2","/d/jiaofei/zxshanding"        
    }),           
});

string* titles = ({
    "铁掌帮玄武堂外堂主",
    "铁掌帮青龙堂外堂主",
    "铁掌帮光明殿外殿主",
    "铁掌帮白虎堂外堂主",
    "铁掌帮朱雀堂外堂主",
    });
        
void create()
{    
    int tufeilevel = 9;    
	set_name("土匪头目", ({ "tufei leader","leader"}));
	set("gender", "男性");
	set("age", 30+random(10));
  
    set("chat_chance", 10);
	set("chat_msg", ({
	    HIR"让开！让开！总坛有险，闲杂人等一律让开！\n"NOR,
	    HIR"滚！滚！滚！\n"NOR,
        HIR"小的们！先到的有赏！\n"NOR,	    		
	}));
	
    set("level",tufeilevel);
	set("str", 50);
	set("int", 10);
	set("con", 50);
	set("dex", 25);    
	set("neili", 2500+300*tufeilevel);
	set("max_neili", 2500+300*tufeilevel);
	set("jingli", 2500+300*tufeilevel);
	set("max_jingli", 2500+300*tufeilevel);
	set("jiali", (2500+300*tufeilevel)/10);		
	set("max_qi",2500+300*tufeilevel);
	set("eff_qi",2500+300*tufeilevel);
	set("qi",2500+300*tufeilevel);   
	set("combat_exp",550000*tufeilevel);    
	//带队数量
	set("teammember",10+random(10));
	  
    setup();
    carry_object(__DIR__"obj/cloth")->wear();
    carry_object("/clone/weapon/gangzhang")->wield();  
    set_gaibang(this_object(),350,1);
  
    set("shen_type", -1);
    
    if(JIAOFEI_D->istaskstart())
    {
       remove_call_out("move_on");
        //每20s移动一次
        call_out("move_on",20);
    }
	
}
void setpath(int p)	
{
    path = p;
    set("title",titles[path]);
}

void init()
{
    add_action("do_quan","quan");
    add_action("do_answer","answer");    
}	

void kill_player(object p)
{
    /*object* allob = all_inventory(environment(this_object()));
    for(int i=0;i<sizeof(allob);i++)
    {
        if(objectp(allob[i]) && !userp(allob[i]) && allob[i]->query("id") == "tufei leader")
        {
            allob[i]->kill_ob(p);
        }
    }*/
    //只攻击一招
    COMBAT_D->do_attack(this_object(), p, this_object()->query_temp("weapon") );
}

int do_quan(string arg)
{
    object me = this_player();
    object armor;
    string* code = ({});
    
    if(JIAOFEI_D->istaskstart() != 1)
    {
        command("idiot");    
        return 1;
    }
        
    if(arg == "leader" || arg == "tufei leader")
    {
        if(me->query_temp("jiaofei/quan_number") > 0)
        {
            write("你已经劝退一路土匪援军，赶快去领赏吧，晚了可就作废了！\n");
            return 1;
        }
        
        if(!undefinedp(me->query_temp("jiaofei/code")) && time()-me->query_temp("jiaofei/code_time") < 60)
        {
            write("你还没对上口令呢！\r\n");
            return 1;
        }
        
        message("vision",me->query("name")+"出声说道：总坛未有征召，各位为何带兵来此？！\r\n",environment(me));
        message("vision",this_object()->query("name")+"回道：听闻有官兵攻山，特来相救！\r\n",environment(me));
        message("vision",me->query("name")+"说道：总坛平安无视，各位为何听信谣言? 请速速返回！\r\n",environment(me));
        armor = me->query_temp("armor/cloth");
        if(!objectp(armor) || armor->query("id") != "ruanteng siyi")
        {
            command("?");
            message("vision",this_object()->query("name")+"勃然大怒：你是哪里来的奸细？来这里阻挡我等救山！\r\n",environment(me));
            kill_player(me);
            return 1;
        }
        
        //完全根据福缘来计算几率
        if(random(me->query("kar")) > 15)
        {
            //显示随机数字要求回答，防止机器人
            write("哦？我怎么能相信你？说，今天的口令是什么！\n");            
            code = ANTIROBOT_D->generatewebimgcode();
            write(RED"系统提示你：请访问\nhttp://www.pkuxkx.net/antirobot/robot.php?filename="+code[1]+"\n来获取口令！\n"NOR);            
            me->set_temp("jiaofei/code",code[0]);
            me->set_temp("jiaofei/code_time",time());
            return 1;
        }
        else
        {
            command("think");
            message("vision",this_object()->query("name")+"勃然大怒：你是哪里来的奸细？来这里阻挡我等救山！\r\n",environment(me));
            kill_player(me);                                                                                           
        }
        return 1;
    }
    return 0;
}

int do_answer(string arg)
{
    object me = this_player();
    
    if(JIAOFEI_D->istaskstart() != 1)
    {
        command("idiot");    
        return 1;
    }    
    if(undefinedp(me->query_temp("jiaofei/code")))
    {
        write("你在说什么？我不懂。\n");
        return 1;
    }
    
    if(time() - me->query_temp("jiaofei/code_time") > 30)
    {
        me->delete_temp("jiaofei/code");
        me->delete_temp("jiaofei/code_time");
        write("这是前年的口令！你拿我开涮呢！?\n");
        return 1;
    }
    
    if(me->query_temp("jiaofei/code") != arg)
    {
        message("vision",this_object()->query("name")+"勃然大怒：你是哪里来的奸细？来这里阻挡我等救山！\r\n",environment(me));
        kill_player(me);
    }
    else
    {
        message("vision",this_object()->query("name")+"咦了一声：看来情报有误，兄弟们，回去罢！\r\n",environment(me));
        me->delete_temp("jiaofei/code");
        me->delete_temp("jiaofei/code_time");
        //给玩家记录奖励
        me->add_temp("jiaofei/quan_number",1);
        me->set_temp("jiaofei/quan_time",time());

        //move to void first, to remove actions from users
        this_object()->move(VOID_OB);
        destruct(this_object());
    }
    return 1;
}

//向下个房间前进
void move_on()
{
    object nextroom;
	object* allobs;

    if(JIAOFEI_D->istaskstart() == 1)
    {
        if(path < 0 || path >= sizeof(paths) || position < 0 || position > sizeof(paths[path]) - 1 )
        {
            //有错误消失
            command("bug");
            this_object()->move(VOID_OB);
            destruct(this_object());                    
            return;
        }

        nextroom = load_object(paths[path][++position]);
        if(objectp(nextroom))
        {
            if (environment())
            {
                message("vision",query("name")+"大喝到：情况危急，迅速前去增援！\r\n",environment(this_object()));
                message("vision",query("name")+"带领手下快速的离开了。\r\n",environment(this_object()));
            }
            move(nextroom);
            //给目的房间提示
            message("vision",query("name")+"带领着一路土匪赶来增援了。\r\n",environment(this_object()));

            //打开目的房间的机关，double目的房间土匪的damage和defense
            if(nextroom->istaskroom())
			{
				allobs = all_inventory(nextroom);
				for(int i=0;i<sizeof(allobs);i++)					
				{
					if(!objectp(allobs[i])) continue;
					if(allobs[i]->query("id") == "tufei")
					{
			            message("vision",allobs[i]->query("name")+"大叫：援军来啦！兄弟们，杀啊！说罢越发凶狠的砍杀起来。\r\n",environment());
						allobs[i]->set_temp("apply/attack",allobs[i]->query_temp("apply/attack")*2+10);
						allobs[i]->set_temp("apply/dodge",allobs[i]->query_temp("apply/dodge")*2+10);
						allobs[i]->set_temp("apply/defense",allobs[i]->query_temp("apply/defense")*2+10);
						allobs[i]->set("eff_qi",allobs[i]->query("max_qi"));
						allobs[i]->set("qi",allobs[i]->query("max_qi"));
						allobs[i]->set("eff_jing",allobs[i]->query("max_jing"));
						allobs[i]->set("jing",allobs[i]->query("max_jing"));
					}
					else if(allobs[i]->ismachine())
					{
						allobs[i]->stop();
						allobs[i]->attack();
					}
				}
				//恢复门的强度
				nextroom->restoredoorstr();
			}
            
            if(position == (sizeof(paths[path]) - 1))
            {
                JIAOFEI_D->announce(sprintf("第%d路土匪援军已经到达峰顶，加入了宝库保卫战！剿匪联军损失惨重！\n",path+1), "bd");
                //减少宝库奖励,每到达一路减少10%的奖励
                JIAOFEI_D->decreasereward(10);
                remove_call_out("move_on");
                //消失
                this_object()->move(VOID_OB);
                destruct(this_object());                  
                return;
            }
        }
        remove_call_out("move_on");
        //每30s移动一次
        call_out("move_on",30);                
    }
    else
    {
        //消失
        message("vision",query("name")+"大喝到：现在赶去已经于事无补，兄弟们，跟我撤！\r\n",environment());
        //move to void first, to remove actions from users
        this_object()->move(VOID_OB);
        destruct(this_object());        
    }

}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	return;
}

//死亡后给奖励,奖励包括经验和潜能
//exp = level*500;
//pot = level*50
//任务的主要奖励在宝库里。
void die()
{
    object me,killer;
    int exp,pot;
    me = this_object();

	if(me->query("teammember") > 0)
	{
		message("vision","眼看"+query("name")+"伤重将死，他突然抓过一名手下，手掌覆盖在他的天灵盖上，一转眼就神采熠熠。\n反观之他的手下面色死灰，已然断气了。你不禁心中大骇，世上竟有如此歹毒的功夫！\n",environment(me));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("neili",me->query("max_neili"));
		me->set("eff_neili",me->query("max_neili"));
		me->add("teammember",-1);
		return;
	}

    if (objectp(killer = me->get_damage_origin_object()))
    {
	    message("vision",query("name")+"大叫："+killer->name() + "杀了我，弟兄们，给我报仇啊！！\n",environment(me));
	    message("vision",query("name")+"临死前抱住"+killer->name() +"狠狠的咬了一口！\n",environment(me));
	    killer->add_busy(1);    	
	    
    	if(userp(killer) && JIAOFEI_D->istaskstart() == 1)
    	{        
    		message_vision(YEL"$N剿灭土匪，战功赫赫！！功成之日，朝廷必有重赏！\r\n"NOR,killer);
			killer->add_temp("jiaofei/score",query("level"));//设置一个标记，表明这个人杀过土匪了           
            JIAOFEI_D->stat_user_score_reward(killer->query("id"),query("level"));				
			JIAOFEI_D->registeruser(killer->query("id"));			
    	}
    }
    ::die();	
}

int set_gaibang(object me, int level, int armed)
{
	me->set_skill("force", level);
	me->set_skill("dodge", level);
	me->set_skill("parry", level);
	me->set_skill("staff", level);
	me->set_skill("strike", level);
	me->set_skill("huntian-qigong", level);
	me->set_skill("xiaoyaoyou", level);
	me->set_skill("dagou-bang", level);
	me->set_skill("xianglong-zhang", level);
	me->map_skill("force", "huntian-qigong");
	me->map_skill("dodge", "xiaoyaoyou");
	me->map_skill("strike", "xianglong-zhang");
	me->map_skill("staff", "dagou-bang");
	me->map_skill("parry", "dagou-bang");
	me->set("leiting",1);
	me->set("dagou-bang/zhuan",1);
	me->set("dagou-bang/tiao",1);
	me->prepare_skill("strike", "xianglong-zhang");
	if(armed)
	{
		me->set("use_weapon1", "staff");
	}
	me->set("chat_chance_combat", 100);
	me->set("chat_msg_combat", ({
		(: perform_action, "strike.leiting" :),
        (: perform_action, "strike.sanhui" :),
		(: perform_action, "staff.chan" :),
		(: perform_action, "staff.chan" :),
		(: perform_action, "staff.zhuan" :),
		(: perform_action, "staff.tiao" :),
		(: exert_function, "powerup" :),
	}));
}


void test()
{
    printf("%d\n",sizeof(paths[0]));
   printf("%d\n",sizeof(paths[1]));
      printf("%d\n",sizeof(paths[2]));    
   printf("%d\n",sizeof(paths[3]));
   printf("%d\n",sizeof(paths[4]));         
}