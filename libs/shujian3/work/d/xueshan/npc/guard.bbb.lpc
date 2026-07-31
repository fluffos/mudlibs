// body guard 保镖
// by emnil@sj		2/9/2k

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>

void checkfight();
int do_copy(object target,int mode);

string * name1 = ({ "马","何","东方","吴","王","张","李","薛","齐","任","黄","郭","欧阳","南宫"}); 
string * name2 = ({ "镖头","大虾","大侠","捕头","护院","保镖" }); 

void create()
{
	string weapon = "null" , menpai;
	string name = name1[random(sizeof(name1))] + name2[random(sizeof(name2))];

	set_name(name, ({ "body guard","guard" }));
	set("gender", "男性");
	set("age", 20 + random(40));
	set("long", "这是位威风凛凛的保镖，身体壮实，一看就是武功高手！\n");

	set("combat_exp", 800000);
 set("combat_exp", 5000000);
	set("meitude", "peaceful");
	set("str", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 31);
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
 set("max_neili", 20000);
	set("neili", 5000);
 set("neili", 20000);
	set_temp("apply/armor", 50);
set("eff_jing", 20000);
set("eff_jingli", 20000);
set("jingli", 20000);
set("max_jingli", 20000);

  set("no_ansuan",1);
	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("stick", 500);
	set_skill("club", 500);
	set_skill("staff", 500);
	set_skill("whip", 500);

    switch( random(22) ) {
		case 0:  // wd1
			set_skill("yinyun-ziqi", 500);
			set_skill("tiyunzong", 500);
			set_skill("taiji-jian", 500);
			set_skill("taiji-quan", 500);
			map_skill("force", "yinyun-ziqi");
			map_skill("dodge", "tiyunzong");
			map_skill("sword", "taiji-jian");
			map_skill("parry", "taiji-quan");
			map_skill("cuff", "taiji-quan");
			prepare_skill("cuff", "taiji-quan");         
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "taiji" :),
				(: perform_action, "cuff.zhan" :), 
				(: perform_action, "cuff.ji" :), 
			}));
			menpai = "武当";
			break;
		case 1:  // wd2
			set_skill("yinyun-ziqi", 500);
			set_skill("tiyunzong", 500);
			set_skill("taiji-jian", 500);
			set_skill("taiji-quan", 500);
			map_skill("force", "yinyun-ziqi");
			map_skill("dodge", "tiyunzong");
			map_skill("sword", "taiji-jian");
			map_skill("parry", "taiji-jian");
			map_skill("cuff", "taiji-quan");
			prepare_skill("cuff", "taiji-quan");         
			set("chat_chance_combat", 15);
			set("chat_msg_combat", ({
				(: perform_action, "dodge.zong" :),
				(: perform_action, "sword.chan" :), 
				(: perform_action, "sword.chan" :), 
				(: perform_action, "sword.sanhuan" :), 
				(: perform_action, "sword.lian" :), 
			}));
			weapon = "sword";
			menpai = "武当";
			break;
		case 2:  // sl1
			set_skill("yijin-jing", 500);
			set_skill("shaolin-shenfa", 500);
			set_skill("riyue-bian", 500);
			set_skill("yizhi-chan", 500);
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			map_skill("whip", "riyue-bian");
			map_skill("parry", "riyue-bian");
			map_skill("finger", "yizhi-chan");
			prepare_skill("finger", "yizhi-chan");         
			set("chat_chance_combat", 18);
			set("chat_msg_combat", ({
				(: exert_function, "jingang" :),
				(: perform_action, "whip.chanrao" :), 
				(: perform_action, "whip.fumoquan" :), 
			}));
			weapon = "whip";
			menpai = "少林";
			break;
		case 3:  // sl2
			set_skill("yijin-jing", 500);
			set_skill("shaolin-shenfa", 500);
			set_skill("damo-jian", 500);
			set_skill("yizhi-chan", 500);
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			map_skill("sword", "damo-jian");
			map_skill("parry", "damo-jian");
			map_skill("finger", "yizhi-chan");
			prepare_skill("finger", "yizhi-chan");         
			set("chat_chance_combat", 25);
			set("chat_msg_combat", ({
				(: exert_function, "jingang" :),
				(: perform_action, "sword.sanjue" :), 
			}));
			weapon = "sword";
			menpai = "少林";
			break;
		case 4:  // sl3
			set_skill("yijin-jing", 500);
			set_skill("shaolin-shenfa", 500);
			set_skill("yizhi-chan", 500);
			map_skill("force", "yijin-jing");
			map_skill("dodge", "shaolin-shenfa");
			map_skill("parry", "yizhi-chan");
			map_skill("finger", "yizhi-chan");
			prepare_skill("finger", "yizhi-chan");         
			set("chat_chance_combat", 22);
			set("chat_msg_combat", ({
				(: exert_function, "jingang" :),
				(: perform_action, "finger.wofo" :), 
				(: perform_action, "finger.qiankun" :), 
			}));
			menpai = "少林";
			break;
		case 5:  // hs1
			set_skill("zixia-gong", 500);
			set_skill("huashan-shenfa", 500);
			set_skill("huashan-jianfa", 500);
			set_skill("hunyuan-zhang", 500);
			map_skill("force", "zixia-gong");
			map_skill("dodge", "huashan-shenfa");
			map_skill("sword", "huashan-jianfa");
			map_skill("parry", "huashan-jianfa");
			map_skill("strike", "hunyuan-zhang");
			prepare_skill("strike", "hunyuan-zhang");         
			set("chat_chance_combat", 17);
			set("chat_msg_combat", ({
				(: exert_function, "zixia" :),
				(: perform_action, "sword.jianzhang" :), 
			}));
			weapon = "sword";
			menpai = "华山";
			break;
		case 6:  // hs2
			set_skill("zixia-gong", 500);
			set_skill("huashan-shenfa", 500);
			set_skill("fanliangyi-dao", 500);
			set_skill("poyu-quan", 500);
			map_skill("force", "zixia-gong");
			map_skill("dodge", "huashan-shenfa");
			map_skill("blade", "fanliangyi-dao");
			map_skill("parry", "fanliangyi-dao");
			map_skill("cuff", "poyu-quan");
			prepare_skill("cuff", "poyu-quan");         
			set("chat_chance_combat", 17);
			set("chat_msg_combat", ({
				(: exert_function, "zixia" :),
				(: perform_action, "blade.sanshenfeng" :), 
			}));
			weapon = "blade";
			menpai = "华山";
			break;
		case 7:  // gb1
			set_skill("huntian-qigong", 500);
			set_skill("bangjue", 500);
			set_skill("xiaoyaoyou", 500);
			set_skill("dagou-bang", 500);
			set_skill("xianglong-zhang", 500);
			map_skill("force", "huntian-qigong");
			map_skill("dodge", "xiaoyaoyou");
			map_skill("stick", "dagou-bang");
			map_skill("parry", "dagou-bang");
			map_skill("strike", "xianglong-zhang");
			prepare_skill("strike", "xianglong-zhang");         
			set("chat_chance_combat", 15);
			set("chat_msg_combat", ({
				(: exert_function, "powerup" :),
				(: perform_action, "stick.linglong" :), 
				(: perform_action, "stick.chan" :), 
			}));
			weapon = "stick";
			menpai = "丐帮";
			break;
		case 8:  // gb2
			set_skill("huntian-qigong", 500);
			set_skill("bangjue", 500);
			set_skill("xiaoyaoyou", 500);
			set_skill("dagou-bang", 500);
			set_skill("xianglong-zhang", 500);
			map_skill("force", "huntian-qigong");
			map_skill("dodge", "xiaoyaoyou");
			map_skill("stick", "dagou-bang");
			map_skill("parry", "xianglong-zhang");
			map_skill("strike", "xianglong-zhang");
			prepare_skill("strike", "xianglong-zhang");         
			set("chat_chance_combat", 15);
			set("chat_msg_combat", ({
				(: exert_function, "powerup" :),
				(: perform_action, "strike.hanglong" :), 
				(: perform_action, "strike.paiyun" :), 
				(: perform_action, "strike.xiao" :), 
			}));
			menpai = "丐帮";
			break;
		case 9:  // thd1
			set_skill("bihai-chaosheng", 500);
			set_skill("qimen-bagua", 500);
			set_skill("suibo-zhuliu", 500);
			set_skill("yuxiao-jian", 500);
			set_skill("tanzhi-shentong", 500);
			set_skill("lanhua-shou", 500);
			set_skill("luoying-zhang", 500);
			set_skill("xuanfeng-tui", 500);
			map_skill("force", "	bihai-chaosheng");
			map_skill("dodge", "suibo-zhuliu");
			map_skill("sword", "yuxiao-jian");
			map_skill("parry", "yuxiao-jian");
			map_skill("finger", "tanzhi-shentong");
			prepare_skill("finger", "tanzhi-shentong");         
			set("chat_chance_combat", 14);
			set("chat_msg_combat", ({
				(: exert_function, "maze" :),
				(: perform_action, "sword.yuxiao" :), 
				(: perform_action, "sword.feiying" :), 
				(: perform_action, "sword.qimen" :), 
			}));
			set("thd/perform",999);
			weapon = "xiao";
			menpai = "桃花岛";
			break;
		case 10: // thd2
			set_skill("bihai-chaosheng", 500);
			set_skill("qimen-bagua", 500);
			set_skill("suibo-zhuliu", 500);
			set_skill("yuxiao-jian", 500);
			set_skill("tanzhi-shentong", 500);
			map_skill("force", "	bihai-chaosheng");
			map_skill("dodge", "suibo-zhuliu");
			map_skill("sword", "yuxiao-jian");
			map_skill("parry", "tanzhi-shentong");
			map_skill("finger", "tanzhi-shentong");
			prepare_skill("finger", "tanzhi-shentong");         
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "maze" :),
				(: perform_action, "finger.huayu" :), 
				(: perform_action, "finger.lingxi" :), 
				(: perform_action, "finger.shentong" :), 
			}));
			set("thd/perform",999);
			menpai = "桃花岛";
			break;
		case 11: // mr1
			set_skill("shenyuan-gong", 500);
			set_skill("douzhuan-xingyi", 500);
			set_skill("yanling-shenfa", 500);
			set_skill("murong-jianfa", 500);
			set_skill("tanzhi-shentong", 500);
			map_skill("force", "	shenyuan-gong");
			map_skill("dodge", "yanling-shenfa");
			map_skill("sword", "murong-jianfa");
			map_skill("parry", "douzhuan-xingyi");
			map_skill("finger", "canhe-zhi");
			prepare_skill("finger", "canhe-zhi");         
			set("chat_chance_combat", 16);
			set("chat_msg_combat", ({
				(: exert_function, "shenyuan" :),
				(: perform_action, "parry.douzhuanxingyi" :), 
				(: perform_action, "parry.xingyi" :), 				
			}));
			weapon = "sword";
			menpai = "姑苏慕容";
			break;
		case 12: // gumu1
			set_skill("yunu-xinjing", 500);
			set_skill("yunu-shenfa", 500);
			set_skill("xuantie-jianfa", 500);
			set_skill("anran-zhang", 500);
			map_skill("force", "	yunu-xinjing");
			map_skill("dodge", "yunu-shenfa");
			map_skill("sword", "xuantie-jianfa");
			map_skill("parry", "xuantie-jianfa");
			map_skill("strike", "anran-zhang");
			prepare_skill("strike", "anran-zhang");         
			set("chat_chance_combat", 40);
			set("chat_msg_combat", ({
				(: perform_action, "sword.haichao" :), 
			}));
			weapon = "sword";
			menpai = "古墓";
         if (random(2)) set("env/玄铁剑法","海潮");
                     else set("env/玄铁剑法","汹涌");
			break;
		case 13: // emei1
			set_skill("linji-zhuang", 500);
			set_skill("anying-fuxiang", 500);
			set_skill("huifeng-jian", 500);
			set_skill("sixiang-zhang", 500);
			map_skill("force", "linji-zhuang");
			map_skill("dodge", "anying-fuxiang");
			map_skill("sword", "huifeng-jian");
			map_skill("parry", "huifeng-jian");
			map_skill("strike", "sixiang-zhang");
			prepare_skill("strike", "sixiang-zhang");         
			set("chat_chance_combat", 30);
			set("chat_msg_combat", ({
				(: exert_function, "wuwo" :),
				(: perform_action, "sword.mie" :), 
				(: perform_action, "sword.jue" :), 
			}));
			weapon = "sword";
			menpai = "娥眉";
			break;
		case 14: // emei2
			set_skill("linji-zhuang", 500);
			set_skill("anying-fuxiang", 500);
			set_skill("yanxing-daofa", 500);
			set_skill("sixiang-zhang", 500);
			map_skill("force", "linji-zhuang");
			map_skill("dodge", "anying-fuxiang");
			map_skill("blade", "yanxing-daofa");
			map_skill("parry", "yanxing-daofa");
			map_skill("strike", "sixiang-zhang");
			prepare_skill("strike", "sixiang-zhang");         
			set("chat_chance_combat", 25);
			set("chat_msg_combat", ({
				(: exert_function, "wuwo" :),
				(: perform_action, "blade.huanying" :), 
			}));
			weapon = "blade";
			menpai = "娥眉";
			break;
		case 15: // mj1
			set_skill("shenghuo-shengong", 500);
			set_skill("qiankun-danuoyi", 500);
			set_skill("piaoyi-shenfa", 500);
			set_skill("shenghuo-lingfa", 500);
			set_skill("hanbing-mianzhang", 500);
			map_skill("force", "shenghuo-shengong");
			map_skill("dodge", "piaoyi-shenfa");
			map_skill("blade", "shenghuo-lingfa");
			map_skill("parry", "qiankun-danuoyi");
			map_skill("cuff", "shenghuo-lingfa");
			prepare_skill("cuff", "shenghuo-lingfa");         
			set("chat_chance_combat", 20);
			set("chat_msg_combat", ({
				(: exert_function, "yinfeng" :),
				(: perform_action, "blade.ji" :), 
				(: perform_action, "blade.xinmo" :), 
                (: perform_action, "blade.tisha" :), 
			}));
			weapon = "tieling";
			menpai = "明教";
			break;
		case 16: // mj2
			set_skill("shenghuo-shengong", 500);
			set_skill("qiankun-danuoyi", 500);
			set_skill("piaoyi-shenfa", 500);
			set_skill("shenghuo-lingfa", 500);
			set_skill("hanbing-mianzhang", 500);
			map_skill("force", "shenghuo-shengong");
			map_skill("dodge", "piaoyi-shenfa");
			map_skill("blade", "shenghuo-lingfa");
			map_skill("parry", "hanbing-mianzhang");
			map_skill("strike", "hanbing-mianzhang");
			prepare_skill("strike", "hanbing-mianzhang");         
			set("chat_chance_combat", 12);
			set("chat_msg_combat", ({
				(: exert_function, "yinfeng" :),
				(: perform_action, "strike.xixue" :), 
			}));
			menpai = "明教";
		case 17: // dali1
			set_skill("qiantian-yiyang", 500);
			set_skill("tianlong-xiang", 500);
			set_skill("duanjia-jianfa", 500);
			set_skill("qingyan-zhang", 500);
			map_skill("force", "qiantian-yiyang");
			map_skill("dodge", "tianlong-xiang");
			map_skill("sword", "duanjia-jianfa");
			map_skill("parry", "qingyan-zhang");
			map_skill("strike", "qingyan-zhang");
			prepare_skill("strike", "qingyan-zhang");         
			set("chat_chance_combat", 30);
			set("chat_msg_combat", ({
				(: exert_function, "xinjing" :),
				(: perform_action, "sword.fenglei" :), 
			}));
			weapon = "sword";
			menpai = "天南大理";
			break;
		case 18: // tls
			set_skill("kurong-changong", 500);
			set_skill("tianlong-xiang", 500);
			set_skill("yiyang-zhi", 500);
			map_skill("force", "kurong-changong");
			map_skill("dodge", "tianlong-xiang");
			map_skill("parry", "yiyang-zhi");
			map_skill("finger", "yiyang-zhi");
			prepare_skill("finger", "yiyang-zhi");         
			set("chat_chance_combat", 26);
			set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :), 
			}));
			menpai = "大理天龙寺";
			break;
                case 19: // gumu2
                        set_skill("yinsuo-jinling", 500);
                        set_skill("yunu-jianfa", 500);
                        set_skill("yunu-shenfa", 500);
                        set_skill("meinu-quanfa", 500);
                         set_skill("yunu-xinjing", 500);
                        map_skill("force", "yunu-xinjing");
                        map_skill("dodge", "yunu-shenfa");
                        map_skill("sword", "yunu-jianfa");
                        map_skill("whip", "yinsuo-jinling");
                        map_skill("parry", "yinsuo-jinling");
                        map_skill("cuff", "meinu-quanfa"); 
                        prepare_skill("cuff", "meinu-quanfa");         
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: perform_action, "whip.yueyin" :), 
                                (: perform_action, "whip.yufeng" :), 
                        }));
                        weapon = "whip";
                        menpai = "古墓派";
                        break;
                case 20: //gumu3 
                        set_skill("anran-zhang", 500);
                        set_skill("yunu-xinjing", 500);
                        set_skill("yunu-shenfa", 500);
                        map_skill("force", "yunu-xinjing");
                        map_skill("dodge", "yunu-shenfa");
                        map_skill("parry", "anran-zhang");
                        map_skill("strike", "anran-zhang"); 
                        prepare_skill("strike", "anran-zhang");       
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: perform_action, "strike.xiaohun" :), 
                                (: perform_action, "strike.anran" :), 
                        }));
                        menpai = "古墓派";
                        break;
             
                 case 21: // tls3
                        set_skill("kurong-changong", 500);
                        set_skill("tianlong-xiang", 500);
                        set_skill("yiyang-zhi", 500);
                        map_skill("force", "kurong-changong");
                        map_skill("dodge", "tianlong-xiang");
                        map_skill("parry", "yiyang-zhi");
                        map_skill("strike", "kurong-changong");
                        prepare_skill("strike", "kurong-changong");         
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                       (: perform_action, "strike.rong" :),
                       (: perform_action, "strike.jiuchong" :),               
                        }));                           
                        menpai = "大理天龙寺";
                        break;
                        

		default: // others	BUG!!!
			set("long","武功设置错误，BUG！！！");
	}
	set("long" , query("long") + sprintf("这位高手似乎来自%s。\n",menpai) );
	set("weapon" , weapon);

    set_temp("no_return",1);
	setup();
	if( weapon!="null" ) carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", random(99));

	this_object()->start_call_out( (: call_other, this_object(), "display", this_object() :), 30);
	this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 1200);
}       

int do_copy(object target,int mode)
{
	mapping skills;
	string *sk;
	object me,ob; 
	int lv,exp,i,t;

	me = this_object();
	ob = target;
	if(mode) {
		t = 10+random(4); 
		set("long",query("long")+"最近治安不太好，这个保镖是特别从京城请来的，据说还曾经是大内高手呢！\n");
		add_money("gold", random(2));
	}
	else 
		t = 10;

	lv = (ob->query_skill("force",1)+ob->query_skill("dodge",1)+ob->query_skill("parry",1))/3;
	if ( lv < (ob->query_skill("force",1)*4/5) ) lv =ob->query_skill("force",1)*4/5;
	lv = lv * t/10;
	exp = ob->query("combat_exp") *t/10;
	exp = exp * (100+random(20))/100;

	me->set("max_qi", (int)ob->query("max_qi")*10/10*t/10 );
	me->set("eff_qi", (int)ob->query("max_qi")*10/10*t/10 );
	me->set("qi", (int)ob->query("max_qi")*10/10*t/10 );	
	me->set("max_jing",(int)ob->query("max_jing"));
	me->set("eff_jing",(int)ob->query("max_jing"));
	me->set("jing",(int)ob->query("max_jing"));
	me->set("max_neili",(int)ob->query("max_neili") );
	me->set("neili",(int)ob->query("neili")*t/10 );
	if( me->query("neili") < me->query("max_neili") )
		me->set("neili",(int)me->query("max_neili") );
	me->set("max_jingli",(int)ob->query("max_jingli"));
	me->set("eff_jingli",(int)ob->query("eff_jingli"));
	me->set("jingli",(int)ob->query("jingli"));
	if( me->query("jingli") < me->query("eff_jingli") )
		me->set("jingli",(int)me->query("eff_jingli") );	
	me->set("combat_exp",exp );	

	skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]] = lv;
	}      
	me->set("jiali",(int)me->query_skill("force")/6);	
}

void display()
{
	object me = this_object();

	if(!objectp(me->query("place"))) return;  // means BUG!!!	
	me->move(me->query("place"));
}

void dest()
{
	destruct(this_object());
}

void kill_ob(object ob)
{
	object me = this_object();

	command("!!!");
            if( ob->query("xs/girl_ob") != me->query("beauty")) {
		command("say 快逃啊！");
		if( objectp(me->query("beauty")) )
			(me->query("beauty"))->kill_ob(ob);
        this_player()->remove_killer(me);
        return;
	}
	else 
		command("say 光天化日也敢抢劫！");

	::kill_ob(ob);

	if( query("addqi")==0 && ob->query_temp("apply/damage")>100 ) {
		int qi;
		qi = query("max_qi") * 3/2;
		if(qi<3000) qi = qi*3/2;
		set("max_qi" , qi);
		set("eff_qi" , qi);
		set("qi" , qi);
		set("addqi" , 1);
	}

	call_out("checkfight",2);
}

int accept_fight(object ob)
{
	object me = this_object();

	if( ob->query("id") != me->query("target")) {
		command("haha");
		command("say 今日有公务在身，恕不奉陪。");
		return 0;       
	}
	else {
       if( (me->query("eff_qi")<(me->query("max_qi")*2/3)) || (me->query("neili")<me->query("max_neili")/2))
			return 0;
		call_out("checkfight",2);

		if( query("addqi")==0 && ob->query_temp("apply/damage")>100 ) {
			int qi;
			qi = query("max_qi") *3/2;
			if(qi<3000) qi = qi*3/2;
			set("max_qi" , qi);
			set("eff_qi" , qi);
			set("qi" , qi);
			set("addqi" , 1);
		}
		
		return 1; 
	}
}

void checkfight()
{
	object me = this_object() , w;
	string weapon;

	if( !objectp(me) || !living(me) || !me->is_fighting() )
		return;

	weapon = me->query("weapon");
	if( stringp(weapon) && weapon!="" && weapon!="null" && !me->query_temp("weapon") ) {
		command("emote 又拿出把兵器。");
		w = new(BINGQI_D(weapon));
		w->move(me);
		w->wield(me);
	}	

	call_out("checkfight",4);
}
