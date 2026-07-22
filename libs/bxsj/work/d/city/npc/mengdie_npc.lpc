
inherit FIGHTER;
inherit F_UNIQUE;
#include <ansi.h>
#include <skills_pfm.h>
void do_copy(object ob);
string *valid_types =
({
	"claw",
	"cuff",
	"finger",
	"hand",
	"leg",
	"strike",
});

void create()
{
	mapping name;
	int sex = random(3);
	name = RNAME_D->get_random_name(random(3));
	set_name(name["name"], name["id"]);
	set_name(query("name"), ({ query("id"),"dls dizi"}));
	set("gender", (sex?"男性":"女性"));
	set("long", "神秘人，你尽力地去去看清，却还是一片模糊。\n");
	set("age", 25+random(100));
	set("attitude", "peaceful");
	set("rank_info/rank","神秘人");
	set("rank_info/self_rude","神秘人");
	set("rank_info/self","小生");
	set("rank_info/rude","神秘人");
	set("rank_info/respect","神秘人");
	set("rank_info/color","HIW");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_qi", 500);
	set("max_jing", 500);
	set("eff_jingli",400);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 20);
	set("combat_exp", 8000+random(500));
//一些武功绝技被设定因为quest取消，特意增加该变量
//目前设定不允许使用的是tanzhi-shentong的pfm qiankun
    set("quest_cancel",1);

	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	set("inquiry", ([
		"name" : random(2)?"什么叫名字？":"呵呵，人生如梦，名字早就忘记了。",
		"名字" : random(2)?"什么叫名字？":"呵呵，人生如梦，名字早就忘记了。",
		"拜师" : "嗯....，小生注定一声漂泊，还是算了吧。",
    ]));

	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
}
init()
{
	int i,p;
    mapping pmap;
	object me=this_object();
	if(query("set_ok")) return;
	set("set_ok",1);
	pmap = me->query_skill_prepare();
	if (!pmap)
	{
		i=sizeof(valid_types);
		p=0;
		while (i--)
		{
			if (!me->query_skill(valid_types[i], 1)) continue;
			if (me->query_skill_mapped(valid_types[i]))continue;
			if(p>=2) continue;
			p=p+1;
			me->prepare_skill(valid_types[i], me->query_skill_mapped(valid_types[i]));
		}
	}	
	remove_call_out("dest");
	call_out("dest",120);
}
void die()
{
	object ob,me;
	object *obs;
	int i;
	ob=this_object();

    if(ob->query("kill_object") && ob->query("quest/level"))
	{
        me=ob->query("kill_object");
	}
	if(me && present(me,environment(ob)))
	{
		i=ob->query("quest/level");
		i=i*i;
		me->add_temp("quest/special/score",i);
		me->add("quest/special/score",i);
		tell_object(me,HIR"\n你成功的击退"+ob->short(1)+HIR"，获得奖励分数"+i+"。*_* \n"NOR);
		log_file("quest/SPECIAL", sprintf("%s(%s) 蝶梦楼比武获得分数奖励：%d。经验：%d。\n", me->name(1),me->query("id"),i,me->query("combat_exp")) );
	}
	obs = deep_inventory(ob);       
	obs = filter_array(obs,(:$1->query("imbued"):));
	i = sizeof(obs);
	while(i--)
	{
		obs[i]->move(environment(ob));
		message_vision(YEL"$N丢下一"+obs[i]->query("unit")+obs[i]->name()+NOR+YEL"。\n"NOR,ob);
	}
	message_vision(HIY"\n突然一阵风散，$N原来站着的地方竟然一点痕迹也没有留下。\n"HIM"刚才的一切如梦幻般，全然消逝在风中。\n"NOR,this_object());
	destruct(this_object());
}
void unconcious()
{
  die();
}
void dest()
{
	message_vision(HIR"\n突然一阵风散，$N原来站着的地方竟然一点痕迹也没有留下。"HIM"刚才的一切如梦幻般，全然消逝在风中。\n"NOR,this_object());
	destruct(this_object());
}
void do_copy(object ob)
{
        object *inv;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i;
		string* u_pfm=({});		
        set_name(ob->name(), ({ ob->query("id")}) );
        set("title", ob->query("title") );
        set("long", ob->query("long") );
        set("gender", ob->query("gender") );
        set("per", ob->query("per") );
        set("age", ob->query("age") );
		set("family/family_name",ob->query("family/family_name"));
		set("family/master",ob->query("family/master"));
        set_temp("apply/damage",  30 + random(100) );
        set_temp("apply/attack",  30 + random(100) );
        set_temp("apply/armor",   30 + random(100) );

// copy skills

        if( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        set_skill(sname[i], skill_status[sname[i]]);
                }
        }

// copy skill maps

        if( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        map_skill(mname[i], map_status[mname[i]]);
                }
        }

// copy skill prepares

        if( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

// copy weapon & armor

        inv = all_inventory(ob);
        i = sizeof(inv);
        while (i--) {
                if( inv[i]->query("weapon_prop/damage") > 100
                || inv[i]->query("unique")
                || inv[i]->query("imbued")
                || inv[i]->query("treasure")
                || inv[i]->query("armor_prop/armor") > 100 ) continue;
				inv[i]->set("copy_object",1);
                if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wield();
                        set("weapon", base_name(inv[i]));
                }
                if( inv[i]->query("armor_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                        set("armor", base_name(inv[i]));
                }
        }

        hp_status = ob->query_entire_dbase();

        set("str", hp_status["str"]);
        set("int", hp_status["int"]);
        set("con", hp_status["con"]);
        set("dex", hp_status["dex"]);

        set("max_qi",    hp_status["max_qi"]);
        set("eff_qi",    hp_status["max_qi"]);
        set("qi",        hp_status["max_qi"]);
        set("max_jing",  hp_status["max_jing"]);
        set("eff_jing",  hp_status["max_jing"]);
        set("jing",      hp_status["max_jing"]);
        set("max_neili", hp_status["max_neili"]);
        set("eff_jingli", hp_status["max_jingli"]);
        set("max_jingli", hp_status["max_jingli"]);
        set("jingli",     hp_status["max_jingli"]*2);
        set("neili",     hp_status["max_neili"]*2);
        set("jiali",     hp_status["jiali"]*2);
        if( query("jiali") > 200 ) set("jiali", 200 );
        set("combat_exp",hp_status["combat_exp"]);

		if(query("family/family_name")=="武当派")
		{
			u_pfm=u_pfm + ({(: exert_function, "yinyun" :)});             //氤氲紫气pfm:氤氲内聚
			u_pfm=u_pfm + ({(: exert_function, "taiji" :)});             //太极
			u_pfm=u_pfm + ({(: perform_action, "dodge.zong" :)});         //踢云纵pfm:纵   
			u_pfm=u_pfm + ({(: perform_action, "strike.bingdi" :)});  //震山绵掌pfm:花开并蒂
			u_pfm = u_pfm + ({(: perform_action, "cuff.ji" :)});				//太极拳pfm:挤
			u_pfm = u_pfm + ({(: perform_action, "cuff.zhannian" :)});			//粘黏
			u_pfm = u_pfm + ({(: perform_action, "cuff.zhen" :)});				//震
			u_pfm = u_pfm + ({(: perform_action, "cuff.luanhuan" :)});			//乱还决
			u_pfm = u_pfm + ({(: perform_action, "cuff.yinyang" :)});			//阴阳决
			u_pfm = u_pfm + ({(: perform_action, "cuff.gangrou" :)});			//刚柔决
			u_pfm = u_pfm + ({(: perform_action, "cuff.dongjing" :)});			//动静决
			u_pfm = u_pfm + ({(: perform_action, "cuff.an" :)});				//按
			u_pfm = u_pfm + ({(: perform_action, "sword.chan" :)});				//太极剑pfm：缠
			u_pfm = u_pfm + ({(: perform_action, "sword.sanhuan" :)});			//三环套月
			u_pfm = u_pfm + ({(: perform_action, "sword.lian" :)});				//连
			set("wd/raozhi",1);
			u_pfm = u_pfm + ({(: perform_action, "sword.raozhi" :)});			//绕指柔剑
		}
		if(query("family/family_name")=="嵩山派")
		{
			u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   //寒冰真气pfm：寒冰
			u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     //聚寒
			u_pfm=u_pfm + ({(: perform_action, "hand.junji" :)});        //嵩阳手pfm：竣极
			u_pfm=u_pfm + ({(: perform_action, "hand.yinyang" :)});      //阴阳
			u_pfm=u_pfm + ({(: perform_action, "whip.luan" :)});          //嵩阳鞭pfm：乱
			u_pfm = u_pfm + ({(: perform_action, "strike.hanbing" :)});     //寒冰神掌pfm：寒冰
			u_pfm = u_pfm + ({(: perform_action, "sword.feiwu" :)});        	//嵩山剑法pfm：飞舞
			u_pfm = u_pfm + ({(: perform_action, "sword.leiting" :)});			//雷霆一击
			u_pfm = u_pfm + ({(: perform_action, "sword.longfeng" :)});			//龙飞	
			u_pfm = u_pfm + ({(: perform_action, "sword.songyang" :)});			//嵩阳
		}
		if(query("family/family_name")=="丐帮")
		{
			u_pfm=u_pfm + ({(: exert_function, "huntian" :)});          //混天气功pfm：powerup
			u_pfm=u_pfm + ({(: perform_action, "whip.huixuan" :)});       //回风鞭pfm：回风
			u_pfm=u_pfm + ({(: perform_action, "staff.feizhi" :)});       //莲花刀法pfm：奇门三才	
			u_pfm = u_pfm + ({(: perform_action, "strike.paiyun" :)});         //降龙掌pfm：排云双掌
			u_pfm = u_pfm + ({(: perform_action, "strike.xiao" :)});		//啸
			u_pfm = u_pfm + ({(: perform_action, "strike.kanglong" :)});	//亢龙无悔
			u_pfm = u_pfm + ({(: perform_action, "stick.chan" :)});       	//打狗棒法pfm：缠
			u_pfm = u_pfm + ({(: perform_action, "stick.chuo" :)});			//戳
			u_pfm = u_pfm + ({(: perform_action, "stick.shuangjue" :)});	//棒掌双绝
			u_pfm = u_pfm + ({(: perform_action, "stick.tiao" :)});			//挑
			u_pfm = u_pfm + ({(: perform_action, "stick.zhuan" :)});		//转
			u_pfm = u_pfm + ({(: perform_action, "stick.wugou" :)});		//天下无狗
		}
		if(query("family/family_name")=="华山派")
		{
			u_pfm=u_pfm + ({(: exert_function, "zixia" :)});            //紫霞功pfm：zixia    
			u_pfm=u_pfm + ({(: perform_action, "blade.sanshenfeng" :)});       //反两仪刀法pfm：华岳三神峰
			u_pfm=u_pfm + ({(: perform_action, "strike.wuji" :)});       //混元掌pfm：混元无极
			u_pfm = u_pfm + ({(: perform_action, "sword.feijian" :)});     	//华山剑法pfm：飞剑
			u_pfm = u_pfm + ({(: perform_action, "sword.junzi" :)});		//君子
			u_pfm = u_pfm + ({(: perform_action, "sword.kuaijian" :)});		//快剑
			u_pfm = u_pfm + ({(: perform_action, "sword.lianhuan" :)});		//连环
			u_pfm = u_pfm + ({(: perform_action, "sword.sanqingfeng" :)});	//三清风
			u_pfm = u_pfm + ({(: perform_action, "sword.shijiushi" :)});	//十九式
			u_pfm = u_pfm + ({(: perform_action, "sword.shunv" :)});		//淑女
			u_pfm = u_pfm + ({(: perform_action, "sword.wushuang" :)});		//无双
			u_pfm = u_pfm + ({(: perform_action, "sword.xiyi" :)});			//希夷
			u_pfm = u_pfm + ({(: perform_action, "sword.yangwu" :)});		//仰吾
			u_pfm = u_pfm + ({(: perform_action, "sword.kuangfeng" :)});    //独孤九剑pfm：狂风
			u_pfm = u_pfm + ({(: perform_action, "sword.pobian" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.pojian" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.pozhang" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.poqi" :)});	
			u_pfm = u_pfm + ({(: perform_action, "sword.poqiang" :)});	
			u_pfm = u_pfm + ({(: perform_action, "sword.posuo" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.zongjue" :)});		//总决

		}
		if(query("family/family_name")=="铁掌帮")
		{
			u_pfm=u_pfm + ({(: exert_function, "focus" :)});          //铁掌气功pfm：focus
			u_pfm=u_pfm + ({(: perform_action, "dodge.piao" :)});     //水上漂pfm:漂
			u_pfm = u_pfm + ({(: perform_action, "strike.duoming" :)});     //铁掌掌法pfm：夺命铁爪
			u_pfm = u_pfm + ({(: perform_action, "strike.heisha" :)});     //铁掌掌法pfm：黑 砂 掌
			u_pfm = u_pfm + ({(: perform_action, "strike.heyi" :)});     //铁掌掌法pfm：阴阳合一
			u_pfm = u_pfm + ({(: perform_action, "strike.honglei" :)});     //铁掌掌法pfm：轰雷双掌
			u_pfm = u_pfm + ({(: perform_action, "strike.judu" :)});     //铁掌掌法pfm：聚    毒
			u_pfm = u_pfm + ({(: perform_action, "strike.pangen" :)});     //铁掌掌法pfm：枯树盘根
			u_pfm = u_pfm + ({(: perform_action, "strike.pushan" :)});     //铁掌掌法pfm：铁蒲扇掌
			u_pfm = u_pfm + ({(: perform_action, "strike.qinna" :)});     //铁掌掌法pfm：铁掌擒拿
			u_pfm = u_pfm + ({(: perform_action, "strike.rubairen" :)});     //铁掌掌法pfm：入 白 刃
			u_pfm = u_pfm + ({(: perform_action, "strike.tianlei" :)});     //铁掌掌法pfm：天 雷 气
			u_pfm = u_pfm + ({(: perform_action, "strike.xuanfeng" :)});     //铁掌掌法pfm：旋风快掌
			u_pfm = u_pfm + ({(: perform_action, "strike.zhangdao" :)});     //铁掌掌法pfm：铁掌掌刀
			u_pfm = u_pfm + ({(: perform_action, "strike.tiezhang" :)});     //铁掌掌法pfm：铁掌
			u_pfm=u_pfm + ({(: perform_action, "blade.daozhang" :)});   //柳叶刀法pfm：刀掌
			u_pfm=u_pfm + ({(: perform_action, "axe.lihun" :)});  		//裂天斧pfm：离魂
		}
		if(query("family/family_name")=="大轮寺")
		{
			u_pfm=u_pfm + ({(: exert_function, "longxiang" :)});   //龙象般若功pfm：龙象
			u_pfm=u_pfm + ({(: exert_function, "shield" :)});      //气盾
			u_pfm=u_pfm + ({(: perform_action, "hand.tianyin" :)});  //大手印pfm：阿修罗天印

			u_pfm = u_pfm + ({(: perform_action, "strike.fen" :)});     //火焰刀pfm：棼
			u_pfm = u_pfm + ({(: perform_action, "strike.ran" :)});     //火焰刀pfm：棼
			u_pfm = u_pfm + ({(: perform_action, "strike.daoqi" :)});     //火焰刀pfm：棼
			u_pfm = u_pfm + ({(: perform_action, "blade.jixue" :)});        	//pfm 祭血
			u_pfm = u_pfm + ({(: perform_action, "blade.shendao" :)});			//神刀穿心
			u_pfm = u_pfm + ({(: perform_action, "hammer.wushuai" :)});        	//天人五衰
			u_pfm = u_pfm + ({(: perform_action, "hammer.dazhuan" :)});			//大转
		}
		if(query("family/family_name")=="古墓派")
		{
			u_pfm=u_pfm + ({(: exert_function, "xinjing" :)});  //玉女心经pfm：xinjing
			u_pfm = u_pfm + ({(: perform_action, "cuff.shexin" :)});		//美女拳法pfm:摄心
			u_pfm=u_pfm + ({(: perform_action, "sword.suxin" :)});      //玉女素心剑pfm：素心
			u_pfm=u_pfm + ({(: perform_action, "sword.qixing" :)});     	//全真剑法pfm：七星聚顶
			u_pfm=u_pfm + ({(: perform_action, "sword.sanqing" :)});   	    //三清风
			u_pfm = u_pfm + ({(: perform_action, "strike.anran" :)});     //黯然销魂掌pfm：黯然
			u_pfm = u_pfm + ({(: perform_action, "strike.jishi" :)});     //黯然销魂掌pfm：嫉世
			u_pfm = u_pfm + ({(: perform_action, "strike.xiaohun" :)});     //黯然销魂掌pfm：销魂
			u_pfm = u_pfm + ({(: perform_action, "sword.haichao" :)});        	//玄铁pfm：海潮
			u_pfm = u_pfm + ({(: perform_action, "sword.wujian" :)});			//无剑
			set("gmsanwu",1);
			u_pfm = u_pfm + ({(: perform_action, "whip.sanwu" :)});        	//银索金铃pfm：三无三不手
		}
		if(query("family/family_name")=="姑苏慕容")
		{		
			u_pfm=u_pfm + ({(: exert_function, "shenyuan" :)});   		//神元功pfm：神元
			u_pfm=u_pfm + ({(: perform_action, "parry.xingyi" :)});     //斗转星移pfm：星移
			u_pfm=u_pfm + ({(: perform_action, "strike.riyue" :)});        //星移掌pfm：日月同辉
			u_pfm = u_pfm + ({(: perform_action, "finger.ci" :)});     //参合指pfm：刺
			u_pfm=u_pfm + ({(: perform_action, "blade.daoying" :)});     //慕容刀法pfm：刀影掌
			u_pfm = u_pfm + ({(: perform_action, "sword.lianhuan" :)});        	//慕容剑法pfm：连环
			u_pfm = u_pfm + ({(: perform_action, "sword.sanhua" :)});			//散花
		}
		if(query("family/family_name")=="神龙教")
		{
			u_pfm=u_pfm + ({(: exert_function, "wudi" :)});   		//毒龙大法pfm：无敌
			u_pfm=u_pfm + ({(: perform_action, "whip.chan" :)});          //灵蛇鞭法pfm：缠绕
			u_pfm=u_pfm + ({(: perform_action, "whip.sandou" :)});        //灵蛇鞭法pfm：缠绕
			u_pfm = u_pfm + ({(: perform_action, "strike.bujue" :)});     //化骨绵掌pfm：不绝
			u_pfm = u_pfm + ({(: perform_action, "dagger.diqing" :)});        	//腾龙匕法pfm：狄青降龙
			u_pfm = u_pfm + ({(: perform_action, "dagger.feiyan" :)});			//飞燕回翔
			u_pfm = u_pfm + ({(: perform_action, "dagger.guifei" :)});			//贵妃回眸	
			u_pfm = u_pfm + ({(: perform_action, "dagger.luda" :)});			//鲁达拔柳
			u_pfm = u_pfm + ({(: perform_action, "dagger.xiaolian" :)});		//小怜横陈
			u_pfm = u_pfm + ({(: perform_action, "dagger.zixu" :)});			//子胥举鼎
		}
		if(query("family/family_name")=="星宿派")
		{
			u_pfm=u_pfm + ({(: exert_function, "judu" :)});   //聚毒
			u_pfm = u_pfm + ({(: perform_action, "staff.feizhi" :)});        	//天山杖法pfm：飞掷
			u_pfm = u_pfm + ({(: perform_action, "strike.biyan" :)});     //抽髓掌pfm：碧焰
			u_pfm = u_pfm + ({(: perform_action, "strike.huoqiang" :)});     //抽髓掌pfm：火墙
			u_pfm = u_pfm + ({(: perform_action, "strike.huoqiu" :)});     //抽髓掌pfm：火球
			u_pfm = u_pfm + ({(: perform_action, "strike.yinhuo" :)});     //抽髓掌pfm：银火
		}
		if(query("family/family_name")=="娥眉派")
		{
			u_pfm=u_pfm + ({(: exert_function, "fengyun" :)});   //临济十二庄pfm：风云
			u_pfm=u_pfm + ({(: exert_function, "riyue" :)});	 //日月
			u_pfm=u_pfm + ({(: exert_function, "tiandi" :)});    //天地 
			u_pfm=u_pfm + ({(: exert_function, "wuwo" :)});      //无我
			u_pfm=u_pfm + ({(: exert_function, "yinyang" :)});   //阴阳  
			if(random(5)==1)
			u_pfm=u_pfm + ({(: exert_function, "youming" :)});   //幽冥  
			u_pfm=u_pfm + ({(: exert_function, "zhixin" :)});    //之心 
			u_pfm=u_pfm + ({(: perform_action, "blade.feiyang" :)});          //雁行刀法pfm：飞扬
			u_pfm=u_pfm + ({(: perform_action, "blade.huanying" :)});         //雁行刀法pfm：幻影
			u_pfm = u_pfm + ({(: perform_action, "sword.jue" :)});        		//回风拂柳剑pfm：绝
			u_pfm = u_pfm + ({(: perform_action, "sword.liaoyuan" :)});			//燎原
			u_pfm = u_pfm + ({(: perform_action, "sword.mie" :)});				//灭
			u_pfm = u_pfm + ({(: perform_action, "hand.foguang" :)});     //截手九式pfm：寒冰

		}
		if(query("family/family_name")=="明教")
		{	
			u_pfm=u_pfm + ({(: exert_function, "tougu" :)});	 //圣火神功pfm:透骨
			u_pfm=u_pfm + ({(: exert_function, "yinfeng" :)});	 //阴风		
			u_pfm = u_pfm + ({(: perform_action, "strike.xixue" :)});		//寒冰绵掌pfm:吸血
			u_pfm = u_pfm + ({(: perform_action, "blade.shenghuo" :)});		 //烈焰刀pfm:圣火
			u_pfm=u_pfm + ({(: exert_function, "powerup" :)});	 //powerup	
			u_pfm = u_pfm + ({(: perform_action, "cuff.qishang" :)});     //七伤拳pfm：七伤
			u_pfm = u_pfm + ({(: perform_action, "cuff.duanhun" :)});     //七伤拳pfm：断魂
			u_pfm = u_pfm + ({(: perform_action, "dagger.duo" :)});        	//圣火令法pfm：夺
			u_pfm = u_pfm + ({(: perform_action, "dagger.ji" :)});			//击
			u_pfm = u_pfm + ({(: perform_action, "dagger.tisha" :)});			//踢沙	
			u_pfm = u_pfm + ({(: perform_action, "dagger.xinmo" :)});			//心魔
		}
		if(query("family/family_name")=="桃花岛")
		{
			u_pfm=u_pfm + ({(: exert_function, "maze" :)});     //布阵
			u_pfm=u_pfm + ({(: exert_function, "qimen" :)});     //奇门五行
			u_pfm=u_pfm + ({(: perform_action, "dodge.wuzhuan" :)});			//随波逐流pfm:五转
			u_pfm=u_pfm + ({(: perform_action, "strike.pikong" :)});        //落英神剑掌pfm：劈空
			u_pfm=u_pfm + ({(: perform_action, "leg.kuangfeng" :)});        //旋风扫叶腿pfm：狂风
			u_pfm = u_pfm + ({(: perform_action, "sword.feiying" :)});        	//玉箫剑法pfm：飞影
			u_pfm = u_pfm + ({(: perform_action, "sword.qimen" :)});			//奇门
			u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)});     //弹指神通pfm：乾坤一指
			u_pfm = u_pfm + ({(: perform_action, "finger.shentong" :)});     //弹指神通pfm：神通
			u_pfm = u_pfm + ({(: perform_action, "sword.feiying" :)});        	//玉箫剑法pfm：飞影
			u_pfm = u_pfm + ({(: perform_action, "sword.qimen" :)});			//奇门
		}
		if(query("family/family_name")=="天龙寺")
		{		
			u_pfm=u_pfm + ({(: exert_function, "xinjing" :)});   
			u_pfm = u_pfm + ({(: perform_action, "finger.sandie" :)}); 			//一阳指pfm：阳关三叠
			u_pfm = u_pfm + ({(: perform_action, "finger.yizhisanmai" :)}); 	//一指三脉
			u_pfm=u_pfm + ({(: perform_action, "sword.fenglei" :)});          	//段家剑法pfm：风雷四击
			u_pfm = u_pfm + ({(: exert_function, "rong" :)}); 					//枯荣禅功pfm：荣
			u_pfm = u_pfm + ({(: perform_action, "strike.jiuchong" :)});		//九重天
			u_pfm = u_pfm + ({(: perform_action, "whip.cibei" :)});        		//慈航鞭pfm：慈悲字诀
			u_pfm = u_pfm + ({(: perform_action, "axe.jingtian" :)});        	//盘根错结斧pfm：惊天断云斧
		}
		if(query("family/family_name")=="少林派")
		{	
			u_pfm=u_pfm + ({(: exert_function, "jingang" :)});   							//易筋经pfm：金刚不坏体神功
			u_pfm = u_pfm + ({(: perform_action, "strike.sanhua" :)});
			u_pfm = u_pfm + ({(: perform_action, "finger.fuxue" :)});    
			u_pfm = u_pfm + ({(: perform_action, "finger.wofo" :)});    		//一指禅pfm：皈依我佛
			u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)}); 		//一指乾坤
			u_pfm = u_pfm + ({(: perform_action, "claw.canyun" :)}); 			//龙爪功pfm：风卷残云
			u_pfm = u_pfm + ({(: perform_action, "hand.qianshou" :)});    		//如来千叶手pfm：千手如来
			u_pfm = u_pfm + ({(: perform_action, "leg.ruying" :)});    			//如影随形腿pfm：如影随形
			u_pfm = u_pfm + ({(: perform_action, "strike.chaodu" :)}); 			//般若掌pfm：超度连环诀
			if(random(5)==1)
				u_pfm = u_pfm + ({(: perform_action, "strike.yipai" :)});   		//一拍两散
			u_pfm = u_pfm + ({(: perform_action, "cuff.fumo" :)});    			//大金刚拳pfm：金刚伏魔
			u_pfm = u_pfm + ({(: perform_action, "whip.fumoquan" :)});        	//日月鞭法pfm：金刚伏魔圈
			u_pfm = u_pfm + ({(: perform_action, "whip.chanrao" :)});        	//天缠地绕 
			u_pfm = u_pfm + ({(: perform_action, "blade.fentian" :)});			//燃木刀法pfm：举火焚天
			u_pfm = u_pfm + ({(: perform_action, "blade.fenwo" :)});        	//焚我
			u_pfm = u_pfm + ({(: perform_action, "club.leidong" :)});			//韦陀杵pfm：雷动九天
			u_pfm = u_pfm + ({(: perform_action, "club.chaodu" :)});        	//超度极乐 
		}
		if(query("family/family_name")=="昆仑派")
		{
			u_pfm=u_pfm + ({(: exert_function, "xuantian" :)});   							//玄天无极功
			u_pfm=u_pfm + ({(: exert_function, "wuji" :)});     							//
			u_pfm = u_pfm + ({(: perform_action, "strike.diezhang" :)});     //昆仑掌法pfm：昆山叠掌
			u_pfm = u_pfm + ({(: perform_action, "sword.xunlei" :)});     //昆仑掌法pfm：昆山叠掌
			u_pfm = u_pfm + ({(: perform_action, "sword.hundun" :)});     //昆仑掌法pfm：昆山叠掌
			u_pfm = u_pfm + ({(: perform_action, "leg.chuanyun" :)});     //昆仑掌法pfm：昆山叠掌
		}
		if(query("family/family_name")=="九阴真经传人")
		{
			u_pfm=u_pfm + ({(: exert_function, "yihuen" :)});   
			u_pfm=u_pfm + ({(: exert_function, "zongjue" :)});   							//九阴总诀
			u_pfm=u_pfm + ({(: perform_action, "dodge.huanyinbu" :)});      				//九阴身法pfm：幻阴步
			u_pfm=u_pfm + ({(: perform_action, "claw.jiuyin" :)});			//九阴白骨爪pfm：九阴三绝爪
			u_pfm=u_pfm + ({(: perform_action, "strike.cuixin" :)});
			u_pfm=u_pfm + ({(: perform_action, "whip.chanrao" :)});   	   //九阴银龙鞭pfm：缠绕诀			
			u_pfm=u_pfm + ({(: perform_action, "whip.feilong" :)});        //飞龙  
			u_pfm = u_pfm + ({(: perform_action, "strike.shenzhang" :)});   //九阴神掌pfm：神掌夺魄
			u_pfm = u_pfm + ({(: perform_action, "strike.yinyang" :)});		//阴阳双掌   
			u_pfm = u_pfm + ({(: perform_action, "strike.sanjue" :)});      //九阴神爪pfm：九阴三绝爪
			u_pfm = u_pfm + ({(: perform_action, "sword.xuanyin" :)});      //玄阴剑法pfm：玄阴诀 	
			u_pfm = u_pfm + ({(: perform_action, "sword.zhan" :)});			//斩字诀	
		}
		if(query("family/family_name")=="蛤蟆功传人")
		{
			set("oyf/hamagong",3);
			u_pfm = u_pfm + ({(: perform_action, "strike.hama" :)});        	
			u_pfm = u_pfm + ({(: exert_function, "nizhuan" :)});        	
		}
		if(query("family/family_name")=="东方不败的传人")
		{	
			u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   //寒冰真气pfm：寒冰
			u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     //聚寒
			u_pfm = u_pfm + ({(: perform_action, "sword.cimu" :)});        	
			u_pfm = u_pfm + ({(: perform_action, "dodge.feiying" :)});        	
			u_pfm = u_pfm + ({(: perform_action, "sword.jue" :)});        	
		}
		if(query("family/family_name")=="金蛇剑法的传人")
		{
			u_pfm = u_pfm + ({(: perform_action, "sword.kuangwu" :)});        	
     	}
		set("chat_chance_combat", 100);
		set("chat_msg_combat", u_pfm);

}
