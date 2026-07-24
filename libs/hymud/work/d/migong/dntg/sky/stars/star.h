//Cracked by Roath

//鬼金星官
inherit NPC;
#include "action.h"
#include "party.h"

mapping *menpai=({
(["mp":"wudang",]),
(["mp":"lingjiu",]),
(["mp":"taohua",]),
(["mp":"tiandihui",]),
(["mp":"mingjiao",]),
(["mp":"gumu",]),
(["mp":"huashan",]),
(["mp":"gaibang",]),
(["mp":"quanzhen",]),
(["mp":"dali",]),
(["mp":"tiezhang",]),
(["mp":"murong",]),
(["mp":"kunlun",]),
(["mp":"lingxiao",]),
(["mp":"wdjiao",]),
(["mp":"jiuyin",]),
(["mp":"noname",])
});
string *ns = ({	"force",
		"dodge",
		"parry",
		"unarmed",
		"strike",
		"cuff",
		"finger",
		"claw",
		"hand",
		"leg",
		"sword",
		"blade",
		"whip",
		"hammer",
		"staff",
		"axe",
		"literate",
		"shenzhao-jing",
});

mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);

string *title=({"虚日星君",
		"斗木星君",
		"女土星君",
		"牛金星君",
		"壁水星君",
		"室火星君",
		"危月星君",
		"昂日星君",
		"奎木星君",
		"胃土星君",
		"娄金星君",
		"参水星君",
		"觜火星君",
		"毕月星君",
		"星日星君",
		"井木星君",
		"柳土星君",
		"鬼金星君",
		"轸水星君",
		"翼火星君",
		"张月星君",
		"房日星君",
		"角木星君",
		"氐土星君",
		"亢金星君",
		"箕水星君",
		"尾火星君",
		"心月星君",
});

string *long=({
"面如蓝碘多威武，赤发金睛恶如虎\n呼风唤雨不寻常，斩将封为虚日鼠\n", 
"九扬纱巾头上盖，腹内玄机无比赛\n降龙伏虎似平常，斩将封为斗木豸\n",
"跨虎登山观鹤鹿，驱邪捉怪神鬼哭\n只因无福了仙家，斩将封为女土蝠\n",
"五岳三山任意游，访玄参道守心修\n空劳炉内金丹汞，斩将封为牛金牛\n",
"五行妙术体全殊，合就玄中自丈夫\n悟道成仙无造化，斩将封为碧水狳\n",
"截教传来转玉枢，玄机两记用功夫\n丹砂鼎内龙降虎，斩将封为室火猪\n",
"发似朱砂脸似靛，浑身上下金光现\n天机玄妙总休言，斩将封为危月燕\n",
"铁树开花怎得齐，阴神行乐跨虹霓\n只因无福为仙侣，斩将封为昂日鸡\n",
"三柳钢须一尺长，炼就三花不老方\n蓬莱仙岛无心恋，斩将封为奎木狼\n",
"顶上详光五彩气，包罗万象多伶俐\n无分无缘成正果，斩将封为胃土雉\n",
"离龙坎虎相匹遇，炼就神丹成不朽\n无缘顶上现三花，斩将封为娄金狗\n",
"出世虔诚悟道言，勤修苦炼反离魂\n移山倒海任吾意，斩将封为参水猿\n",
"不恋尘华止自修，降龙伏虎任悠游\n空为数载丹砂力，斩将封为觜火猴\n",
"道术精奇盖世无，修真炼性握兵符\n长生妙诀贪尘劫，斩将封为毕月乌\n",
"修成大道真潇洒，妙法玄机有真假\n不能成仙却凡尘，斩将封为星日马\n",
"修成道气精光焕，巨口獠牙红发乱\n碧游宫内有声名，斩将封为井木犴\n",
"采练阴阳有异方，五行撰簇配中黄\n不归阐教归截教，斩将封为柳土獐\n",
"腹内珠玑贯八方，包罗万象道汪洋\n只因杀戒难逃躲，斩将封为鬼金羊\n",
"箬冠道服性聪敏，炼就白气无心损\n只因无福了长生，斩将封为轸水蚓\n",
"秘授口诀伏妖邪，顶上灵云天地遮\n三花聚顶难成就，斩将封为翼火蛇\n",
"腹内玄机修二六，炼就阴阳超凡俗\n谁知无气未朝元，斩将封为张月鹿\n",
"三昧真火空中露，霞光前后生百步\n万仙阵内逞英雄，斩将封为房日兔\n",
"一字青纱脑后飘，道袍水合束丝绦\n原神一现神龟灭，斩将封为角木狡\n",
"赤发红须性情俄，游尽三山并五岳\n包罗万象枉徒劳，斩将封为氏土狍\n",
"金丹炼就脱樊笼，五遁三除大道通\n未灭三尸吞六气，斩将封为亢金龙\n",
"自从修炼玄中妙，不恋金章共紫诰\n通天教主是吾师，斩将封为箕水豹\n",
"碧玉霞冠形容古，双手善把天地补\n无心访道学长生，斩将封为尾火虎\n",
"面如赤枣落腮胡，撒豆成岳盖世无\n两足登云如挚电，斩将封为心月狐\n",
});

void create()
{
	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
  int gd,sk;
        	string tt, ll;
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(17);
        gd=random(2);
        sk=random(10);

//	int ID=random(26);
	tt = title[ID];
	ll = long[ID];

        set_name("星君", ({"xing jun", "star"}));
	set("title", tt);
	set("long", ll);
	set("gender", "男性");
	set("class", "xian");
	set("age", 20);
	set("per", 30);
	set("no_check", 1);	
	set("combat_exp", 1000000);
	set("daoxing", 1000000);

	set("combat_exp",3000000+random(20000000));
	set_temp("apply/attack",30);
	set_temp("apply/defense",30);
	set_temp("apply/armor",250);
	set_temp("apply/damage",250);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=4000+random(4000);
a=6000+random(9000);
d=30+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("neili",a);
        set("max_neili",a);
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=200+random(500);
        e=200+random(500);
	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//删除自己所有功夫
}
        this_object()->change_combat_mode();
set("chat_chance_combat", 100);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        
f=1+random(8);        
	setup();

	if (ob->query("gender")=="女性")
	{
	carry_object("/clone/cloth/female"+f+"-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	}
else {
	carry_object("/clone/cloth/male"+f+"-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}        
        if (stringp(ob->query_skill_mapped("sword"))) 
	carry_object(__DIR__"weapon/sword")->wield();
	if (stringp(ob->query_skill_mapped("blade"))) 
	carry_object(__DIR__"weapon/dao")->wield();
	if (stringp(ob->query_skill_mapped("whip"))) 
	carry_object(__DIR__"weapon/bian")->wield();
	if (stringp(ob->query_skill_mapped("hammer"))) 
	carry_object(__DIR__"weapon/hammer")->wield();
	if (stringp(ob->query_skill_mapped("staff"))) 
	carry_object(__DIR__"weapon/ban")->wield();
	if (stringp(ob->query_skill_mapped("axe"))) 
	carry_object(__DIR__"weapon/axe")->wield();

	add_money("silver",50+random(50));
}
       

mixed get_auto_actions(string action)
{
	int i, flag = 0;

	for (i = 0; i < sizeof(pfm); i++)
		if (pfm[i]["party"] == query("party")) {
			flag = 1;
			break;
		}
	if (!flag)
		return ({ });
	if (arrayp(pfm[i][action]))
		return pfm[i][action];
	else
		return ({ });
}

void change_combat_mode(object me, int mode)
{
	switch (mode) {
	case 0:
		delete("chat_chance_combat");
		delete("chat_msg_combat");
		set("jiali", 1);
		break;
	case 1:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform2"));
		set("jiali", 1);
		break;
	default:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		return;
	}
	set("combat_mode", mode);
//	me->set("guard/status/combat_mode", mode);
}

void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
if (!environment(this_object()))
   return;
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}

int chat()
{
	int i, ratio, chance, rnd, flag = 0;
	string *msg, *emotes, cmd;
	object *inv, *killer;

	if (!is_busy() 
	&& living(this_object())
	&& environment(this_object()) )
	{
		if (arrayp(msg = get_auto_actions("powerup")))
			for (i = 0; i < sizeof(msg); i++)
				if (functionp(msg[i]))
					evaluate(msg[i]);
	}


	if (query("neili") > 100 && query("max_neili") > 200 && !is_busy()
	&& living(this_object())
	&& environment(this_object()) 
	) {
		if (query("eff_jing") && query("jing") * 100 / query("eff_jing") <= 80)
			command("exert regenerate");

		if (query("eff_qi") && query("qi") >= 0 && query("qi") * 100 / query("eff_qi") <= 80)
			command("exert recover");

		if (query("eff_qi") && query("qi") >= 0
		&& query("max_qi") && !is_fighting() && !query("mute")
		&& query_skill_mapped("force")
		&& query("eff_qi") < query("max_qi")
		&& query("eff_qi") >= query("max_qi") / 3)
			command("exert heal");

		if (query("max_neili")
		&& query("neili") * 100 / query("max_neili") <= 80
		&& !is_fighting()
		&& query_skill_mapped("force")) {
			i = 1 + (int)query_skill("force") / 15 * (1 + (int)query_skill("force") / 100);
			command(sprintf("dazuo %d", i));
		}

	}

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( query_temp("is_unconcious") ) return 0;
		if(!living(this_object()) ) return 0;
		if(!environment(this_object())  ) return 0;

		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}

	return 1;
}


void init()
{
	object ob;
	ob=this_player();
	::init();
	
	if( wizardp(ob) && !this_object()->query("have_name") ){
		tell_object(ob,"如果此星君尚未命名，请用(setname 姓名)。\n");
	}
	add_action("setname", "setname");
	return;
}

int setname(string arg)
{
	object ob;
	ob=this_player();

	if(!wizardp(ob))
		return notify_fail("什么？\n");

	if(!arg)
		return notify_fail("请用(setname 姓名)。\n");

	tell_object(ob, "姓名改动成功。\n");
	this_object()->set("have_name", 1);
	this_object()->set("name", arg);
	//this_object()->save();
	return 1;
}
