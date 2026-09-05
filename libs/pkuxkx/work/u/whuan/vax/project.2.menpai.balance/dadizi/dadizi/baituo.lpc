#define CLASS_ID "baituo"
// 设置CLASS_ID 就行了，其他大弟子文件只有第一行不同的

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;

//classn[]
mapping classn = ([
"shaolin"	:	"少林派",
"wudang"		:	"武当派",
"gaibang"	:	"丐帮",
"baituo"		:	"白驼山",
"xingxiu"	:	"星宿派",
"huashanq"	:	"华山派",
"huashanj"	:	"华山派",
"emei"		:	"峨嵋派",
"mingjiao"	:	"明教",
"riyue"		:	"日月神教",
"gumu"		:	"古墓派",
"lingjiu"	:	"灵鹫宫",
"quanzhen"	:	"全真派",
"tianlong"	:	"天龙寺",
"taohua"		:	"桃花岛",
"murong"		:	"姑苏慕容",
"tiandi"		:	"天地会",
"shenlong"	:	"神龙教",
]);

//locaten[]
mapping locaten = ([
"shaolin"	:	"/d/shaolin/guangchang1",
"wudang"		:	"/d/wudang/sanqing",
"gaibang"	:	"/d/city/gbxiaowu",
"baituo"		:	"/d/baituo/dating",
"xingxiu"	:	"/d/xingxiu/xxh2",
"huashanq"	:	"/d/huashan/buwei1",
"huashanj"	:	"/d/huashan/buwei1",
"emei"		:	"/d/emei/dadian",
"mingjiao"	:	"/d/mingjiao/dadian",
"riyue"		:	"/d/riyuejiao/yading",
"gumu"		:	"/d/gumu/dating",
"lingjiu"	:	"/d/lingjiu/zhengting",
"quanzhen"	:	"/d/quanzhen/gongmen",
"tianlong"	:	"/d/dali/dadian",
"taohua"		:	"/d/taohuadao/dating",
"murong"		:	"/d/murong/yketing",
"tiandi"		:	"/d/beijing/qingmutang",
"shenlong"	:	"/d/city/duchang",
]);

string cls;
string classname;
string huashan_suffix;
	
void create()
{
	huashan_suffix = "";
	cls = CLASS_ID ; // class id
	classname = classn[cls];
	if (cls == "huashanq")
		huashan_suffix = "气宗";
	if (cls == "huashanj")
		huashan_suffix = "剑宗";

	set("channel_id", classname + "大弟子");
	seteuid(getuid());

	if (!restore()) {
	set_name(classname+"大弟子", ({ "da dizi", "dizi" }) );
	set("title", classname+"大弟子" );
	set("long","这位是"+classname+"大弟子。\n");
	if (cls == "lingjiu" || cls =="gumu" || cls =="emei")
		set("gender", "女性" );
	else
		set("gender", "男性" );
	set("age", 30);
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 1500);
	set("eff_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1300);
	set("jing", 1300);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 40);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 1000000);

	set_skill("force",  600);
	set_skill("unarmed",600);
	set_skill("dodge",  600);
	set_skill("parry",  600);
	set_skill("sword",  600);

	set("armor", "/clone/armor/tiejia");

	setup();

	carry_object("/clone/armor/tiejia")->wear();
	}
	else {
		set("id", "da dizi");
		set_name(query("name"), ({ query("id") }));
		setup();
		if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
        if( this_object()->query("armor") ) carry_object(this_object()->query("armor"))->wear();
                else carry_object("/clone/armor/tiejia")->wear();
	}
}


int accept_fight(object ob)
{
	object me, jujing,heluo,yan,tianjie,gelao,heishou,qingzhu,tiandi,qisha;
	string name1, name2,name3,name4,name5,name6,name7,name8,name9;

	me  = this_object();

	if ( this_player()->query("id") == DADIZI_D->query_name(cls) )
		return notify_fail("你已经是该派大弟子了。\n");

	if (DADIZI_D->query_free(cls) == 0)
		return notify_fail("刚刚有人当选大弟子，你过一会儿再来。\n");
		
	//if (SECURITY_D->get_status(this_player()) != "(player)" )
	//	return notify_fail("巫师和超级玩家不能抢大弟子之位！\n");

	if ( ob->query("family/family_name")!=classn[cls] )
		return notify_fail("你并不是本派弟子！\n");
	
	if (cls != "shaolin" && cls != "emei")
	{	// 非和尚 尼姑 ，有足够储蓄 才能竞选
		if ((int)ob->query("balance") < 300*10000)
		{
			return notify_fail("你没有足够的储蓄，怎么能竞选弟子？！即便是打赢了也怕是付不起其他弟子的生活补贴吧。\n");
		}
	}
	
	if ( me->is_fighting() )
		return notify_fail("已经有人正在挑战！\n");

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}


int checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) {
		if ( (me->query("qi")*100 / my_max_qi) <= 80 )
			command("exert recover");

		call_out("checking", 1, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1;

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say 果然厉害！\n");
		if (DADIZI_D->set_name(cls, this_player()->query("id")))
		{
			// 成功加入
			command("say 恭喜你成为本派大弟子！");
			command("rumor 听说" + ob->query("name") + "战胜了"+query("name") +"，成为了"+classn[cls]+huashan_suffix+"大弟子！\n");
			if (cls != "shaolin" && cls != "emei")
			{	// 和尚 尼姑 ，出家人不能要钱的
				// command("say 请交纳生活补助基金 100 两黄金！");
				// 暂时不收钱， 看看再说
				command("rumor "+classn[cls]+huashan_suffix+"中有贡献的弟子，请按门派贡献向"+ob->query("name")+"领取生活补贴！\n");
			}
		}
		else
		{
			// bug ?
			command("say 但是总是感觉哪里不对劲！");
		}
		remove_call_out("do_copy");
		call_out("do_copy", 1, me, ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say 看来" + RANK_D->query_respect(ob) +
			"还得多加练习，方能在本派中出人头地 !\n");
		return 1;
	}

	return 1;
}

string ask_me()
{

	object ob = this_player();
	int scores = (int)ob->query("score");
	int m_gold, m_silver;
	int newscore;
	
	if ( ob->query("family/family_name")!=classn[cls] )
		return "你并不是本派弟子！\n";
	
	if ( huashan_suffix == "气宗" && ob->query_skill("zixia-shengong")< 200
		|| huashan_suffix == "剑宗" && ob->query_skill("dugu-jiujian")< 200)
		return "连华山派看家功夫都没学好啊，你看起来不像本派弟子！\n";
	
	if ( ob->query("mark/salary") == DADIZI_D->query_name(cls))
		return "你已经领过这一轮的生活补贴了！\n";
		
	if ( scores < 2000 )
		return "你的门派贡献还不够！\n";
	
	if ( scores > 100000 )
		scores = 100000;  // not to large , but I do not think One would reach this
	
	m_gold = scores/2000;
	m_silver = (scores%2000)/20;
	
	ob->set("mark/salary", DADIZI_D->query_name(cls));
	ob->add_money("gold", m_gold);
	ob->add_money("silver", m_silver);
	
	newscore = scores*95/100;
	ob->set("score", newscore);
	tell_object(ob,"你的门派忠诚降低了"+chinese_number(scores - newscore)+"点。\n");
	
	return "你为本派做了不少贡献，这是你的生活补贴："+chinese_number(m_gold)+"两黄金，"+chinese_number(m_silver)+"两白银！\n";
}

int do_clone(object me, object ob)
{
    object *inv, newob;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	seteuid( geteuid(me) );

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
 }

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}

/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
	set("weapon", 0);
	set("armor", 0);

/* wield and wear weapon & armor */

              //carry_object("/clone/weapon/changjian")->wield();
              //me->set("weapon", "/clone/weapon/changjian");
              carry_object("/clone/armor/tiejia")->wear();
              me->set("armor", "/clone/armor/tiejia");



/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("age", hp_status["age"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);
	if (cls != "shaolin" && cls != "emei")
	{	// 和尚 尼姑 ，出家人不能要钱的
		me->set("inquiry", ([
		    "生活补贴" : (: ask_me :),
		    "salary" : (: ask_me :),
		]));
	}
	
	save();

	tell_object(ob, "状态储存完毕。\n");

    //    newob = new("/clone/npc/dadizi/"+cls);
    //   newob->move(locaten[cls]);
	//destruct(me);

	return 1;
}


int do_kill()
{
	command("say 喝道：呔！你要想清楚！敢和我们全派作对？");
	return 1;
}

void init()
{
	object me = this_object();

//	add_action("do_recopy",  "recopy");
//	add_action("do_recover", "recover");
	add_action("do_kill", "kill");
}

int do_copy(object me, object ob)
{
	object ob1, ob2;
	string bangzhu;

	seteuid(getuid());

	me->set("winner", ob->query("id"));
	me->add("generation", 1);

	me->set("name",  ob->query("name") );
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");

	me->set("mud_age", ob->query("mud_age"));
	me->set("shen", ob->query("shen"));
	me->set("luohan_winner", ob->query("luohan_winner"));
	me->set("dai", ob->query("dai"));
	me->set("is_beggar", ob->query("is_beggar"));

	me->set("betrayer",ob->query("betrayer"));
        me->set("family",ob->query("family"));

	me->set("short", me->query("title") + " " + me->query("name") + "(da dizi)");

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

	