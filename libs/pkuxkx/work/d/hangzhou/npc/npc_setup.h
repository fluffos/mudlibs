// Code of ShenZhou
//npc_setup.h
//wzfeng 2000 7
//vast modified for pkuxkx 2003.6
/*
void Set_Npcattrib(int Basic_Attrib,int Random_var,
		   int Maxqi,int Random_Maxqi,
		   int Maxjing,int Random_Maxjing,
		   int Maxjingli,int Random_Maxjingli,
		   int Maxneili,int Random_Maxneili,
		   int Exp,int Random_Exp )
void Set_Npcskills(int Basic_skill,int Random_skill,mapping S_skills)
void skills_setup_none(int skill,int r_s,string family)
void skills_setup_weapon(int skill,int r_s,string family)
*/
string *menpai = ({"武当派", "少林派", "全真派", "峨嵋派", "天龙寺", "华山派", "天地会",
		   "白驼山", "星宿派", "日月神教", "丐帮", "明教", "古墓派", "灵鹫宫", "桃花岛"});
void Set_Npcattrib(int Basic_Attrib,int Random_var,
		   int Maxqi,int Random_Maxqi,
		   int Maxjing,int Random_Maxjing,
		   int Maxjingli,int Random_Maxjingli,
		   int Maxneili,int Random_Maxneili,
		   int Exp,int Random_Exp )
{
	int Mneili = Maxneili+random(Random_Maxneili), max;
	set("str", Basic_Attrib+random(Random_var));
	set("int", Basic_Attrib+random(Random_var));
	set("con", Basic_Attrib+random(Random_var));
	set("dex", Basic_Attrib+random(Random_var));

	set("max_qi", Maxqi+random(Random_Maxqi));
	set("max_jing", Maxjing+random(Random_Maxjing));
	set("max_jingli", Maxjingli+random(Random_Maxjingli));
	set("max_neili", Mneili);
	set("combat_exp", Exp+random(Random_Exp));

	max =query("max_jing");
	set("eff_jing",max);
	set("jing",max);
	max = query("max_qi");
	set("eff_qi",max);
	set("qi",max);
	max =query("max_neili");
	set("eff_neili",max);
	set("neili",max);
	max = query("max_jingli");
	set("eff_jingli",max);
	set("jingli",max);
	return;
}

void Set_Npcskills(int Basic_skill,int Random_skill,mapping S_skills)
{
	int i,jiali ;
	mixed S_name;

	if(i=sizeof(S_skills))
	{
		S_name=keys(S_skills);
		for(i=0;i<sizeof(S_name);i++)
		{
			set_skill(S_name[i], Basic_skill+random(Random_skill) );//基本技能
			set_skill(S_skills[S_name[i]], Basic_skill+random(Random_skill) );//对应的特殊技能
			map_skill(S_name[i],S_skills[S_name[i]]);//enable之
		}
	}
	set_skill("literate", Basic_skill+random(Random_skill));
	jiali=(Basic_skill+Basic_skill/2)/2;
	set("jiali",jiali);
	return;
}
//kind choose weapon or no weapon (=1 menas weapon.skill is skills lvl. r_s is random add skills rate
//family is which family skills that npc would use it.
void skills_setup_none(int skill,int r_s, string family)
{
	//object weapon;
	mapping S_skills= ([ ]);
	if (family == "random_menpai")
	family = menpai[random(sizeof(menpai))];
	switch(family)
	{
		case "武当派":
		{
			S_skills["dodge"]="tiyunzong";
			S_skills["parry"]="taiji-quan";
			S_skills["force"]="taiji-shengong";
			S_skills["cuff"]="taiji-quan";
			S_skills["claw"]="taiji-zhao";
			S_skills["sword"]="taiji-jian";
			S_skills["blade"]="taiji-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","taiji-quan");
			set("chat_msg_combat", ({
						(: perform_action, "cuff.zhen" :),
						}));
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
		}
		case "星宿派":
		{
			S_skills["dodge"]="zhaixinggong";
			S_skills["parry"]="tianshan-zhang";
			S_skills["force"]="huagong-dafa";
			S_skills["hand"]="zhaixing-shou";
			S_skills["strike"]="xingxiu-duzhang";
			S_skills["staff"]="tianshan-zhang";
			S_skills["sword"]="mintian-jiushi";
//			set_skill("poison",skill+random(r_s));
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xingxiu-duzhang");
			set("chat_msg_combat", ({
				(: perform_action, "strike.sandu" :),
				}));
			carry_object("/d/baituo/obj/baipao")->wear();
			break;
			}
		case "华山派":
		{
			S_skills["dodge"]="huashan-shenfa";
			S_skills["parry"]="dugu-jiujian";
			S_skills["force"]="huashan-neigong";
			S_skills["strike"]="hunyuan-zhang";
			S_skills["cuff"]="poyu-quan";
			S_skills["sword"]="huashan-jianfa";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","poyu-quan");
			prepare_skill("strike","hunyuan-zhang");
			set("chat_msg_combat", ({
					(: perform_action, "strike.wuji" :),
			}));
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "桃花岛":
		{
			S_skills["dodge"]="luoying-shenfa";
			S_skills["parry"]="yuxiao-jian";
			S_skills["force"]="bihai-shengong";
			S_skills["hand"]="fuxue-shou";
			S_skills["finger"]="tanzhi-shengong";
			S_skills["sword"]="yuxiao-jian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","tanzhi-shengong");
			prepare_skill("hand","fuxue-shou");
		 	set("chat_msg_combat", ({
					(: perform_action, "hand.fuxue" :),
					(: perform_action, "finger.tan" :),
			}));
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "丐帮":
		{
			S_skills["dodge"]="xiaoyaoyou";
			S_skills["parry"]="xianglong-zhang";
			S_skills["force"]="huntian-qigong";
			S_skills["strike"]="xianglong-zhang";
			S_skills["staff"]="dagou-bang";
			S_skills["hand"]="shexing-shou";
			S_skills["blade"]="liuhe-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xianglong-zhang");
			set("chat_msg_combat", ({
				(: perform_action, "strike.leiting" :),
			}));
			carry_object("/d/gaibang/obj/gaibang-bag");
			carry_object("/d/city/obj/cloth")->wear();
			break;
			}
		case "峨嵋派":
		{
			S_skills["dodge"]="zhutian";
			S_skills["parry"]="tiangang-zhi";
			S_skills["force"]="linji-zhuang";
			S_skills["strike"]="jinding-mianzhang";
			S_skills["finger"]="tiangang-zhi";
			S_skills["sword"]="fuliu-jian";
			S_skills["strike"]="jinding-mianzhang";
			S_skills["throwing"]="pili-dan";
			S_skills["blade"]="yanxing-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","tiangang-zhi");
			prepare_skill("strike","jinding-mianzhang");
			set("chat_msg_combat", ({
					(: perform_action, "finger.lingkong" :),
			}));
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "白驼山":
		{
			S_skills["dodge"]="chanchu-bufa";
			S_skills["parry"]="lingshe-zhangfa";
			S_skills["force"]="hamagong";
			S_skills["strike"]="hamagong";
			S_skills["cuff"]="shentuo-zhang";
			S_skills["staff"]="lingshe-zhangfa";
			S_skills["hand"]="shexing-diaoshou";
			set_skill("poison",skill+random(r_s));
			Set_Npcskills(skill,r_s,S_skills);
			set_temp("hmg_dzjm", 1);
			prepare_skill("strike","hamagong");
			set("chat_msg_combat", ({
				(: perform_action, "strike.puji" :),
			}));
			carry_object("/d/baituo/obj/baipao")->wear();
			break;

			}

		case "全真派":
		{
			S_skills["dodge"]="fx-step";
			S_skills["parry"]="yiyang-zhi";
			S_skills["force"]="xiantian-gong";
			S_skills["finger"]="yiyang-zhi";
			S_skills["cuff"]="kongming-quan";
			S_skills["sword"]="quanzhen-jian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","chunyang-quan");
			prepare_skill("strike","sanhua-juding");
			set("chat_msg_combat", ({
					(: perform_action, "finger.fuxue" :),
					(: perform_action, "finger.qiankun-yizhi" :),
					(: perform_action, "cuff.hubo" :),
			}));
			carry_object("/d/quanzhen/npc/obj/robe")->wear();
			break;

			}
		case "古墓派":
		{
			S_skills["dodge"]="xianyun";
			S_skills["parry"]="xuantie-jian";
			S_skills["force"]="jiuyin-shengong";
			S_skills["strike"]="xiaohun-zhang";
			S_skills["sword"]="yunu-jianfa";
			S_skills["cuff"]="meinu-quan";
			S_skills["throwing"]="qianmie-shou";
			S_skills["whip"]="changhen-bian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xiaohun-zhang");
			set("chat_msg_combat", ({
				(: perform_action, "strike.anran" :),
			}));
			carry_object("/d/gumu/npc/obj/white")->wear();
			break;

			}
		case "天龙寺":
		{
			S_skills["dodge"]="lingbo-weibu";
			S_skills["parry"]="liumai-shenjian";
			S_skills["force"]="beiming-shengong";
			S_skills["finger"]="liumai-shenjian";
			S_skills["sword"]="mintian-jiushi";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","liumai-shenjian");
			set("chat_msg_combat", ({
					(: perform_action, "finger.qifa" :),
					(: perform_action, "finger.qifa2" :),
				}));
			carry_object("/d/baituo/obj/baipao")->wear();
			break;
			}
		case "少林派":
		{
			S_skills["dodge"]="shaolin-shenfa";
			S_skills["parry"]="jingang-quan";
			S_skills["force"]="hunyuan-yiqi";
			S_skills["strike"]="banruo-zhang";
			S_skills["finger"]="nianhua-zhi";
			S_skills["whip"]="riyue-bian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","nianhua-zhi");
			set("chat_msg_combat", ({
					(: perform_action, "finger.fuxue" :),
					(: perform_action, "cuff.jingang" :),
			}));
			carry_object("/d/shaolin/obj/xuan-cloth")->wear();
			break;
			}
		case "日月神教":
		{
			S_skills["dodge"]="pixie-jian";
			S_skills["parry"]="riyue-jian";
			S_skills["force"]="kuihua-shengong";
			S_skills["strike"]="kaishan-zhang";
			S_skills["claw"]="ryingzhua-gong";
			S_skills["sword"]="pixie-jian";
			S_skills["blade"]="riyue-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","kaishan-zhang");
			prepare_skill("claw","ryingzhua-gong");
			set("chat_msg_combat", ({
					(: perform_action, "sword.cimu" :),
					(: perform_action, "sword.cixue" :),
					(: perform_action, "sword.xuanmu" :),
					(: perform_action, "blade.lianhuan" :),
			}));
			carry_object("/d/baituo/obj/baipao")->wear();
			break;
			}
		case "明教":
		{
			S_skills["dodge"]="datengnuo-bufa";
			S_skills["parry"]="shenghuo-lingfa";
			S_skills["force"]="jiuyang-shengong";
			S_skills["strike"]="hanbing-zhang";
			S_skills["claw"]="myingzhua-gong";
			S_skills["sword"]="shenghuo-lingfa";
                        S_skills["blade"]="lieyan-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","hanbing-zhang");
			prepare_skill("claw","myingzhua-gong");
			set("chat_msg_combat", ({
					(: perform_action, "strike.shixie" :),
					(: perform_action, "dodge.tisha" :),
			}));
			carry_object("/d/mingjiao/obj/changpao")->wear();
			break;
			}
		case "灵鹫宫":
		{
			S_skills["dodge"]="yueying-wubu";
			S_skills["parry"]="liuyang-zhang";
			S_skills["force"]="bahuang-gong";
			S_skills["strike"]="liuyang-zhang";
			S_skills["throwing"]="liuyang-zhang";
			S_skills["hand"]="zhemei-shou";
			S_skills["sword"]="tianyu-qijian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("throwing","liuyang-zhang");
			prepare_skill("hand","zhemei-shou");
			set("chat_msg_combat", ({
					(: perform_action, "throwing.zhong" :),
					(: perform_action, "throwing.lianzhong" :),
					(: perform_action, "hand.duo" :),
					(: perform_action, "hand.tanmei" :),
			}));
			carry_object("/d/lingjiu/obj/doupeng")->wear();
         		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");

			break;
			}
		case "天地会":
		{
			S_skills["dodge"]="lingding-piao";
			S_skills["parry"]="yunlong-zhua";
			S_skills["force"]="cangming-gong";
			S_skills["whip"]="jiulong-bian";
			S_skills["claw"]="yunlong-zhua";
			S_skills["hand"]="fulong-shou";
			S_skills["sword"]="danxin-jian";;
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("claw","yunlong-zhua");
			prepare_skill("hand","fulong-shou");
			set("chat_msg_combat", ({
					(: perform_action, "hand.an" :),
					(: perform_action, "claw.ningxue" :),
			}));
			carry_object("/clone/armor/jinzhuang")->wear();
			break;
			}
	}


}

void skills_setup_weapon(int skill,int r_s,string family)
{
	//object weapon;
	mapping S_skills= ([ ]);
	if (family == "random_menpai")
	family = menpai[random(sizeof(menpai))];
	switch(family)
	{
		case "武当派":
		{
			S_skills["dodge"]="tiyunzong";
			S_skills["parry"]="taiji-quan";
			S_skills["force"]="taiji-shengong";
			S_skills["cuff"]="taiji-quan";
			S_skills["claw"]="taiji-zhao";
			S_skills["sword"]="taiji-jian";
			S_skills["blade"]="taiji-dao";
			Set_Npcskills(skill,r_s,S_skills);
		        prepare_wskill("blade","taiji-dao");
		        prepare_wskill("sword","taiji-jian");
			prepare_skill("cuff","taiji-quan");
			set("chat_msg_combat", ({
						(: perform_action, "sword.chan" :),
						(: perform_action, "cuff.zhen" :),
						}));
		        carry_object("/clone/weapon/changjian")->wield();
		        carry_object("/clone/weapon/gangdao")->wield();
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
		}
		case "星宿派":
		{
			S_skills["dodge"]="zhaixinggong";
			S_skills["parry"]="tianshan-zhang";
			S_skills["force"]="huagong-dafa";
			S_skills["hand"]="zhaixing-shou";
			S_skills["strike"]="xingxiu-duzhang";
			S_skills["staff"]="tianshan-zhang";
			S_skills["sword"]="mintian-jiushi";
//			set_skill("poison",skill+random(r_s));
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xingxiu-duzhang");
			set("chat_msg_combat", ({
				(: perform_action, "strike.sandu" :),
				(: perform_action, "parry.handu" :),
				}));
		        carry_object("/d/xingxiu/obj/bingpozhang")->wield();
			carry_object("/d/baituo/obj/baipao")->wear();
			break;
			}
		case "华山派":
		{
			S_skills["dodge"]="huashan-shenfa";
			S_skills["parry"]="dugu-jiujian";
			S_skills["force"]="huashan-neigong";
			S_skills["strike"]="hunyuan-zhang";
			S_skills["cuff"]="poyu-quan";
			S_skills["sword"]="huashan-jianfa";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","poyu-quan");
			prepare_skill("strike","hunyuan-zhang");
			set("chat_msg_combat", ({
					(: perform_action, "sword.feilong" :),
					(: perform_action, "sword.jianzhang" :),
					(: perform_action, "strike.wuji" :),
			}));
		        carry_object("/clone/weapon/changjian")->wield();
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "桃花岛":
		{
			S_skills["dodge"]="luoying-shenfa";
			S_skills["parry"]="yuxiao-jian";
			S_skills["force"]="bihai-shengong";
			S_skills["hand"]="fuxue-shou";
			S_skills["finger"]="tanzhi-shengong";
			S_skills["sword"]="yuxiao-jian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","tanzhi-shengong");
			prepare_skill("hand","fuxue-shou");
		 	set("chat_msg_combat", ({
					(: perform_action, "sword.chan" :),
					(: perform_action, "sword.xiaohua" :),
					(: perform_action, "hand.fuxue" :),
					(: perform_action, "finger.tan" :),
			}));
		        carry_object("/clone/weapon/changjian")->wield();
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "丐帮":
		{
			S_skills["dodge"]="xiaoyaoyou";
			S_skills["parry"]="xianglong-zhang";
			S_skills["force"]="huntian-qigong";
			S_skills["strike"]="xianglong-zhang";
			S_skills["staff"]="dagou-bang";
			S_skills["hand"]="shexing-shou";
			S_skills["blade"]="liuhe-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","xianglong-zhang");
			set("chat_msg_combat", ({
				(: perform_action, "strike.leiting" :),
				(: perform_action, "staff.chan" :),
			}));
			carry_object("/d/gaibang/obj/gaibang-bag");
		        carry_object("/d/city/obj/zhubang")->wield();
			carry_object("/d/city/obj/cloth")->wear();
			break;
			}
		case "峨嵋派":
		{
			S_skills["dodge"]="zhutian";
			S_skills["parry"]="tiangang-zhi";
			S_skills["force"]="linji-zhuang";
			S_skills["strike"]="jinding-mianzhang";
			S_skills["finger"]="tiangang-zhi";
			S_skills["sword"]="fuliu-jian";
			S_skills["strike"]="jinding-mianzhang";
			S_skills["throwing"]="pili-dan";
			S_skills["blade"]="yanxing-dao";
			Set_Npcskills(skill,r_s,S_skills);
		        prepare_wskill("sword","fuliu-jian");
		        prepare_wskill("blade","yanxing-dao");
			prepare_skill("finger","tiangang-zhi");
			prepare_skill("strike","jinding-mianzhang");
			set("chat_msg_combat", ({
					(: perform_action, "finger.lingkong" :),
					(: perform_action, "sword.fuliu" :),
					(: perform_action, "sword.miejian" :),
					(: perform_action, "blade.heji" :),
			}));
		        carry_object("/clone/weapon/changjian")->wield();
		        carry_object("/d/city/obj/gangdao")->wield();
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "白驼山":
		{
			S_skills["dodge"]="chanchu-bufa";
			S_skills["parry"]="lingshe-zhangfa";
			S_skills["force"]="hamagong";
			S_skills["strike"]="hamagong";
			S_skills["cuff"]="shentuo-zhang";
			S_skills["staff"]="lingshe-zhangfa";
			S_skills["hand"]="shexing-diaoshou";
			set_skill("poison",skill+random(r_s));
			Set_Npcskills(skill,r_s,S_skills);
			set_temp("hmg_dzjm", 1);
			prepare_skill("strike","hamagong");
			set("chat_msg_combat", ({
					(: perform_action, "strike.puji" :),
					(: perform_action, "staff.saoluoye" :),
			}));
		        carry_object("/d/baituo/obj/shezhang")->wield();
			carry_object("/d/baituo/obj/baipao")->wear();
			break;

			}

		case "全真派":
		{
			S_skills["dodge"]="fx-step";
			S_skills["parry"]="yiyang-zhi";
			S_skills["force"]="xiantian-gong";
			S_skills["finger"]="yiyang-zhi";
			S_skills["cuff"]="kongming-quan";
			S_skills["sword"]="quanzhen-jian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","chunyang-quan");
			prepare_skill("strike","sanhua-juding");
			set("chat_msg_combat", ({
					(: perform_action, "finger.fuxue" :),
					(: perform_action, "finger.qiankun-yizhi" :),
					(: perform_action, "cuff.hubo" :),
					(: perform_action, "sword.jianqi" :),
					(: perform_action, "sword.jianzhen" :),
					(: perform_action, "sword.qixing" :),
					(: perform_action, "sword.ding" :),
					(: perform_action, "sword.sanqing" :),
					(: perform_action, "sword.tonggui" :),
			}));
		        carry_object("/d/city/obj/gangjian")->wield();
			carry_object("/d/quanzhen/npc/obj/robe")->wear();
			break;

			}
		case "古墓派":
		{
			S_skills["dodge"]="xianyun";
			S_skills["parry"]="xuantie-jian";
			S_skills["force"]="jiuyin-shengong";
			S_skills["strike"]="xiaohun-zhang";
			S_skills["sword"]="yunu-jianfa";
			S_skills["cuff"]="meinu-quan";
			S_skills["throwing"]="qianmie-shou";
			S_skills["whip"]="changhen-bian";
			Set_Npcskills(skill,r_s,S_skills);
			set("suxin", 1);
			set("hubo", 1);
			prepare_skill("strike","xiaohun-zhang");
			set("chat_msg_combat", ({
				(: perform_action, "strike.anran" :),
				(: perform_action, "parry.xiongyong" :),
				(: perform_action, "sword.suxin" :),
			}));
		        carry_object("/d/city/obj/gangjian")->wield();
			carry_object("/d/gumu/npc/obj/white")->wear();
			break;

			}
		case "天龙寺":
		{
			S_skills["dodge"]="lingbo-weibu";
			S_skills["parry"]="liumai-shenjian";
			S_skills["force"]="beiming-shengong";
			S_skills["finger"]="liumai-shenjian";
			S_skills["sword"]="mintian-jiushi";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","liumai-shenjian");
			set("chat_msg_combat", ({
					(: perform_action, "finger.qifa" :),
					(: perform_action, "finger.qifa2" :),
				}));
		        carry_object("/d/city/obj/gangjian")->wield();
			carry_object("/d/baituo/obj/baipao")->wear();
			break;
			}
		case "少林派":
		{
			S_skills["dodge"]="shaolin-shenfa";
			S_skills["parry"]="jingang-quan";
			S_skills["force"]="hunyuan-yiqi";
			S_skills["strike"]="banruo-zhang";
			S_skills["finger"]="nianhua-zhi";
			S_skills["whip"]="riyue-bian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("finger","nianhua-zhi");
			set("chat_msg_combat", ({
					(: perform_action, "finger.fuxue" :),
					(: perform_action, "cuff.jingang" :),
					(: perform_action, "sword.sanjue" :),
			}));
		        carry_object("/d/city/obj/gangjian")->wield();
			carry_object("/d/shaolin/obj/xuan-cloth")->wear();
			break;
			}
		case "日月神教":
		{
			S_skills["dodge"]="pixie-jian";
			S_skills["parry"]="riyue-jian";
			S_skills["force"]="kuihua-shengong";
			S_skills["strike"]="kaishan-zhang";
			S_skills["claw"]="ryingzhua-gong";
			S_skills["sword"]="pixie-jian";
			S_skills["blade"]="riyue-dao";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("strike","kaishan-zhang");
			prepare_skill("claw","ryingzhua-gong");
			set("chat_msg_combat", ({
					(: perform_action, "sword.cimu" :),
					(: perform_action, "sword.cixue" :),
			}));
		        carry_object("/d/city/obj/gangjian")->wield();
			carry_object("/d/baituo/obj/baipao")->wear();
			break;
			}
		case "明教":
		{
			S_skills["dodge"]="datengnuo-bufa";
			S_skills["parry"]="shenghuo-lingfa";
			S_skills["force"]="jiuyang-shengong";
			S_skills["strike"]="hanbing-zhang";
			S_skills["claw"]="myingzhua-gong";
			S_skills["sword"]="shenghuo-lingfa";
                        S_skills["blade"]="lieyan-dao";
			Set_Npcskills(skill,r_s,S_skills);
		        prepare_wskill("sword","shenghuo-lingfa");
                        prepare_wskill("blade","lieyan-dao");
			prepare_skill("strike","hanbing-zhang");
			prepare_skill("claw","myingzhua-gong");
			set("chat_msg_combat", ({
					(: perform_action, "sword.fenxin" :),
					(: perform_action, "strike.shixie" :),
					(: perform_action, "dodge.tisha" :),
			}));
		        carry_object("/clone/weapon/changjian")->wield();
		        carry_object("/d/city/obj/gangdao")->wield();
			carry_object("/d/mingjiao/obj/changpao")->wear();
			break;
			}
		case "灵鹫宫":
		{
			S_skills["dodge"]="yueying-wubu";
			S_skills["parry"]="liuyang-zhang";
			S_skills["force"]="bahuang-gong";
			S_skills["strike"]="liuyang-zhang";
			S_skills["throwing"]="liuyang-zhang";
			S_skills["hand"]="zhemei-shou";
			S_skills["sword"]="tianyu-qijian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("throwing","liuyang-zhang");
			prepare_skill("hand","zhemei-shou");
			set("chat_msg_combat", ({
					(: perform_action, "sword.fenfei" :),
					(: perform_action, "throwing.zhong" :),
					(: perform_action, "throwing.lianzhong" :),
					(: perform_action, "hand.duo" :),
					(: perform_action, "hand.tanmei" :),
			}));
			carry_object("/d/lingjiu/obj/doupeng")->wear();
		        carry_object("/clone/weapon/changjian")->wield();
         		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");
        		carry_object("/d/lingjiu/obj/jiudai");

			break;
			}
		case "天地会":
		{
			S_skills["dodge"]="lingding-piao";
			S_skills["parry"]="yunlong-zhua";
			S_skills["force"]="cangming-gong";
			S_skills["whip"]="jiulong-bian";
			S_skills["claw"]="yunlong-zhua";
			S_skills["hand"]="fulong-shou";
			S_skills["sword"]="danxin-jian";
			Set_Npcskills(skill,r_s,S_skills);
		  prepare_wskill("sword","danxin-jian");
		  prepare_wskill("whip","jiulong-bian");
			prepare_skill("claw","yunlong-zhua");
			prepare_skill("hand","fulong-shou");
			set("chat_msg_combat", ({
					(: perform_action, "sword.xian" :),
					(: perform_action, "sword.xunlei" :),
					(: perform_action, "whip.baibi" :),
					(: perform_action, "hand.an" :),
					(: perform_action, "claw.ningxue" :),
			}));
		        carry_object("/clone/weapon/changjian")->wield();
		        carry_object("/d/gumu/obj/changbian")->wield();
			carry_object("/clone/armor/jinzhuang")->wear();
			break;
			}
	}


}

