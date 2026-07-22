// body guard 保镖
// by emnil@sj          2/9/2k
// Modify By River@SJ

inherit NPC;
inherit F_UNIQUE;

#include <ansi.h>

void checkfight();
int do_copy(object target,int mode);

string *title1 = ({ "镖头", "护院", "保镖"});

void create()
{
	string weapon = "null" , menpai, title;
	mapping name;
	int i;

	i = random(3) + 1;
	title = "龙门镖局  " + title1[random(sizeof(title1))];
	name = RNAME_D->get_random_name(i);

	set_name(name["name"], name["id"]);
	set("title", HIW+title+NOR);
	set("gender", (i==0?"女性":"男性"));
	set("age", 20 + random(40));
	set("long", "这是位威风凛凛的保镖，身体壮实，一看就是武功高手！\n");

	set("combat_exp", 5000000);
	set("meitude","peaceful");
	set("str", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 31);
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 20000);
	set("neili", 20000);
	set_temp("apply/armor", 50);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);

	set("no_ansuan",1);
	set("no_bark", 1);
	set("no_quest", 1);

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
	set_skill("literate", 500);
	set_skill("whip", 500);
	set_skill("dagger", 500);

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
                        set("chat_chance_combat", 50);
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
                        set("chat_chance_combat", 50);
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
                        set("chat_chance_combat", 48);
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
                        set("chat_chance_combat", 55);
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
                        set("chat_chance_combat", 52);
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
                        set("chat_chance_combat", 47);
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
                        set("chat_chance_combat", 47);
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
                        set("chat_chance_combat", 55);
                        set("chat_msg_combat", ({
                                (: exert_function, "huntian" :),
                                (: perform_action, "stick.chuo" :),
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
                        set("chat_chance_combat", 45);
                        set("chat_msg_combat", ({
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
                        map_skill("force", "    bihai-chaosheng");
                        map_skill("dodge", "suibo-zhuliu");
                        map_skill("sword", "yuxiao-jian");
                        map_skill("parry", "yuxiao-jian");
                        map_skill("finger", "tanzhi-shentong");
                        prepare_skill("finger", "tanzhi-shentong");
                        set("chat_chance_combat", 54);
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
                        map_skill("force", "    bihai-chaosheng");
                        map_skill("dodge", "suibo-zhuliu");
                        map_skill("sword", "yuxiao-jian");
                        map_skill("parry", "tanzhi-shentong");
                        map_skill("finger", "tanzhi-shentong");
                        prepare_skill("finger", "tanzhi-shentong");
                        set("chat_chance_combat", 49);
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
                        map_skill("force", "    shenyuan-gong");
                        map_skill("dodge", "yanling-shenfa");
                        map_skill("sword", "murong-jianfa");
                        map_skill("parry", "douzhuan-xingyi");
                        map_skill("finger", "canhe-zhi");
                        prepare_skill("finger", "canhe-zhi");
                        set("chat_chance_combat", 46);
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
                        map_skill("force", "    yunu-xinjing");
                        map_skill("dodge", "yunu-shenfa");
                        map_skill("sword", "xuantie-jianfa");
                        map_skill("parry", "xuantie-jianfa");
                        map_skill("strike", "anran-zhang");
                        prepare_skill("strike", "anran-zhang");
                        set("chat_chance_combat", 50);
                        set("chat_msg_combat", ({
                                (: perform_action, "sword.haichao" :),
                        }));
                        weapon = "sword";
                        menpai = "古墓";
			if (random(2)) set("env/玄铁剑法","海潮"); else set("env/玄铁剑法","汹涌");
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
                        set("chat_chance_combat", 50);
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
                        set("chat_chance_combat", 45);
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
                        map_skill("dagger", "shenghuo-lingfa");
                        map_skill("parry", "qiankun-danuoyi");
                        map_skill("cuff", "shenghuo-lingfa");
                        prepare_skill("cuff", "shenghuo-lingfa");
                        set("chat_chance_combat", 50);
                        set("chat_msg_combat", ({
                                (: exert_function, "yinfeng" :),
                                (: perform_action, "dagger.ji" :),
                                (: perform_action, "dagger.xinmo" :),
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
                        map_skill("dagger", "shenghuo-lingfa");
                        map_skill("parry", "hanbing-mianzhang");
                        map_skill("strike", "hanbing-mianzhang");
                        prepare_skill("strike", "hanbing-mianzhang");
                        set("chat_chance_combat", 35);
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
                        map_skill("parry", "duanjia-jianfa");
                        map_skill("strike", "qingyan-zhang");
                        prepare_skill("strike", "qingyan-zhang");
                        set("chat_chance_combat", 50);
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
                        set_skill("cihang-bian", 500);
                        map_skill("force", "kurong-changong");
                        map_skill("dodge", "tianlong-xiang");
                        map_skill("parry", "cihang-bian");
                        map_skill("strike", "kurong-changong");
                        prepare_skill("strike","kurong-changong");
                        set("chat_chance_combat", 46);
                        set("chat_msg_combat", ({
                               (: perform_action, "strike.rong" :),
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
                        set("chat_chance_combat", 50);
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
                        set("chat_chance_combat", 50);
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
                        set("chat_chance_combat", 50);
                        set("chat_msg_combat", ({
                                (: perform_action, "strike.jiuchong" :),
                        }));
                        menpai = "大理天龙寺";
                        break;

                default: // others      BUG!!!
                        set("long","武功设置错误，BUG！！！");
        }

	set("long" , query("long") + sprintf("这位高手似乎来自%s。\n",menpai) );
	set("weapon" , weapon);

	set_temp("no_return",1);
	set("i_am_guard",1);
	set("owner","i_am_no_owner");
	setup();

	if( weapon!="null" ) carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", random(99));

	if( clonep() ) call_out("dest" , 15*60);
}

void init()
{
	::init();
	add_action("do_yell","yell");
}

int do_yell(string arg)
{
	object me = this_player();

	if( (int)environment(this_object())->query("incity") || !arg || arg!="guard" )
		return 0;
	if( !me || !userp(me) || me->query("id")!=(string)query("owner") )
		return 0;

	if (strsrch(file_name(environment(me)),"/cmds/leitai/bwdh") >= 0) {
		write("在试剑山庄内，可没人能保护你了。\n");
		return 1;
	}
	command("guard " + me->query("id"));
	return 1;
}

void dest()
{
	remove_call_out("dest");
	if( living(this_object()) )
		message_vision("$N保镖的时间结束了，慢慢离开此地。\n",this_object());
	destruct(this_object());
}

int do_copy(object ob,int lvl)
{
	mapping skills;
	string *sk;
	int i;

	set("owner",ob->query("id"));

	set("combat_exp" , lvl*lvl/10*lvl*12/10 );
	set("max_qi", (int)ob->query("max_qi")*15/10 );
	set("eff_qi", (int)ob->query("max_qi")*15/10 );
	set("qi", (int)ob->query("max_qi")*15/10 );

	set("max_jing",(int)ob->query("max_jing"));
	set("eff_jing",(int)ob->query("max_jing"));
	set("jing",(int)ob->query("max_jing"));

	set("max_neili",(int)ob->query("max_neili") );
	set("neili",(int)ob->query("max_neili")*2 );

	set("max_jingli",(int)ob->query("max_jingli")*15/10);
	set("eff_jingli",(int)ob->query("eff_jingli")*15/10);
	set("jingli",(int)ob->query("eff_jingli")*15/10);

	skills = query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]] = lvl;
	}
	set("jiali",(int)query_skill("force")/2);
}

void kill_ob(object ob)
{
	call_out("checkfight",2);
}

int accept_fight(object ob)
{
	command("say 在下正在工作中，恕不奉陪。");
	return 0;
}

void checkfight()
{
	object me = this_object() , w;
	string weapon;

	remove_call_out("checkfight");
	if( !objectp(me) || !living(me) || !me->is_fighting() )
		return;

	weapon = me->query("weapon");
	if( stringp(weapon) && weapon!="" && weapon!="null" && !me->query_temp("weapon") ) {
		command("emote 又拿出把兵器。");
		w = new(BINGQI_D(weapon));
		w->move(me);
		w->wield(me);
	}
	call_out("checkfight",3);
}
