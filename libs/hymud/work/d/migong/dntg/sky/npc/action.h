// 门派绝招列表 (by xbd)

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

mapping *pfm = ({
	([	"party": "wudang",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "taiji" :),
			(: perform_action, "zong" :),}),
		"perform": ({
			(: perform_action, "unarmed.ji" :),
			(: perform_action, "unarmed.zhen" :),
			(: perform_action, "unarmed.zhenup" :),
			(: perform_action, "unarmed.zhan" :),
			(: perform_action, "sword.chan" :),
			(: perform_action, "sword.chanup" :),
			(: perform_action, "sword.lian" :),
			(: perform_action, "sword.sui" :),}),
		"perform1": ({
			(: perform_action, "unarmed.zhenup" :),
			(: perform_action, "sword.lian" :),}),
		"perform2": ({
			(: perform_action, "unarmed.zhan" :),
			(: perform_action, "sword.chanup" :),
			(: perform_action, "sword.chan" :),}),
	]),
	([	"party": "huashan",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "unarmed.leidong" :),
			(: perform_action, "sword.wudui" :),}),
		"perform": ({
			(: perform_action, "dodge.huiyanfeiwu" :),
			(: perform_action, "strike.wuji" :),
			(: perform_action, "sword.jiushi" :),
			(: perform_action, "sword.zongjue" :),
			(: perform_action, "sword.pozhao" :),
			(: perform_action, "sword.poqi" :),
			(: perform_action, "sword.pojian" :),
			(: perform_action, "sword.pozhang" :),
			(: perform_action, "sword.feilong" :),
			(: perform_action, "sword.jianzhang" :),
			(: perform_action, "sword.jm" :),}),
		"perform1": ({
			(: perform_action, "sword.jiushi" :),
			(: perform_action, "sword.zongjue" :),
			(: perform_action, "sword.poqi" :),
			(: perform_action, "sword.feilong" :),}),
		"perform2": ({
			(: perform_action, "sword.zongjue" :),
			(: perform_action, "sword.pozhao" :),}),
	]),
	([	"party": "lingjiu",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "duzun" :),
			(: exert_function, "shield" :),}),
		"perform": ({
			(: perform_action, "dodge.lingbo" :),
			(: perform_action, "unarmed.duo" :),
			(: perform_action, "unarmed.zhemei" :),
			(: perform_action, "strike.zhong" :),
			(: perform_action, "strike.lianzhong" :),
			(: perform_action, "sword.kuangwu" :),
			(: perform_action, "sword.san" :),
			(: perform_action, "sword.yushijufen" :),
			(: perform_action, "blade.ruyi" :),
			(: perform_action, "blade.shishiruyi" :),}),
		"perform1": ({
			(: perform_action, "sword.kuangwu" :),
			(: perform_action, "sword.yushijufen" :),
			(: perform_action, "blade.ruyi" :),
			(: perform_action, "blade.shishiruyi" :),}),
		"perform2": ({
			(: perform_action, "unarmed.duo" :),
			(: perform_action, "dodge.lingbo" :),}),
	]),
	([	"party": "taohua",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "wuzhuan" :),}),
		"perform": ({
			(: perform_action, "hand.fuxue" :),
			(: perform_action, "finger.jinglei" :),
			(: perform_action, "finger.lingxi" :),
			(: perform_action, "strike.shenjian" :),
			(: perform_action, "strike.xuan" :),
			(: perform_action, "unarmed.kuangfeng" :),
			(: perform_action, "sword.taohuajian" :),
			(: perform_action, "sword.tianwai" :),
			(: perform_action, "sword.yuxiao" :),
			(: perform_action, "sword.tianwu" :),}),
		"perform1": ({
			(: perform_action, "unarmed.kuangfeng" :),
			(: perform_action, "sword.taohuajian" :),
			(: perform_action, "sword.tianwu" :),}),
		"perform2": ({
			(: perform_action, "hand.fuxue" :),
			(: perform_action, "finger.jinglei" :),}),
	]),
	([	"party": "tiandihui",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "qingshen" :),}),
		"perform": ({
			(: perform_action, "unarmed.pofuchenzhou" :),
			(: perform_action, "unarmed.zhen" :),
			(: perform_action, "claw.ningxue" :),
			(: perform_action, "hand.fuxue" :),
			(: perform_action, "sword.duoming" :),
			(: perform_action, "sword.xian" :),
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "whip.chan" :),}),
		"perform1": ({
			(: perform_action, "unarmed.pofuchenzhou" :),
			(: perform_action, "claw.ningxue" :),
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "sword.xian" :),
			(: perform_action, "sword.duoming" :),}),
		"perform2": ({
			(: perform_action, "hand.fuxue" :),}),
	]),
	([	"party": "mingjiao",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: command, "nuoyi" :),
			(: perform_action, "dodge.ruyingruhuan" :),
			(: perform_action, "unarmed.hunpofeiyang" :),
			(: perform_action, "unarmed.youyouhunduan" :),
			(: perform_action, "strike.xixueqingfu" :),
			(: perform_action, "claw.muyeyingyang" :),
			(: perform_action, "sword.duo" :),
			(: perform_action, "sword.tougu" :),
			(: perform_action, "sword.xiyanling" :),
			(: perform_action, "sword.yinfeng" :),}),
		"perform1": ({
			(: command, "nuoyi" :),
			(: perform_action, "unarmed.youyouhunduan" :),
			(: perform_action, "sword.tougu" :),
			(: perform_action, "sword.yinfeng" :),}),
		"perform2": ({
			(: perform_action, "dodge.ruyingruhuan" :),
			(: perform_action, "sword.xiyanling" :),
			(: perform_action, "sword.duo" :),}),
	]),
	([	"party": "gumu",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "unarmed.anran" :),}),
		"perform": ({
			(: perform_action, "unarmed.xiaohun" :),
			(: perform_action, "cuff.youju" :),
			(: perform_action, "cuff.wuqing" :),
			(: perform_action, "strike.luowang" :),
			(: perform_action, "sword.feihongrudian" :),
			(: perform_action, "sword.he" :),
			(: perform_action, "sword.hubo" :),
			(: perform_action, "sword.suxin" :),}),
		"perform1": ({
			(: perform_action, "unarmed.xiaohun" :),
			(: perform_action, "cuff.wuqing" :),
			(: perform_action, "sword.feihongrudian" :),
			(: perform_action, "sword.hubo" :),}),
		"perform2": ({
			(: perform_action, "strike.luowang" :),}),
	]),
	([	"party": "gaibang",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "shengang" :),
			(: perform_action, "unarmed.xianglong" :),}),
		"perform": ({
			(: perform_action, "dodge.canghaiyixiao" :),
			(: perform_action, "unarmed.leiting" :),
			(: perform_action, "unarmed.kanglongwuhui" :),
			(: perform_action, "staff.ban" :),
			(: perform_action, "staff.chan" :),
			(: perform_action, "staff.duo" :),
			(: perform_action, "staff.feng" :),
			(: perform_action, "staff.luanda" :),
			(: perform_action, "sword.zhuan" :),}),
		"perform1": ({
			(: perform_action, "unarmed.leiting" :),
			(: perform_action, "unarmed.kanglongwuhui" :),
			(: perform_action, "staff.luanda" :),}),
		"perform2": ({
			(: perform_action, "dodge.canghaiyixiao" :),
			(: perform_action, "staff.chan" :),}),
	]),
	([	"party": "quanzhen",
		"powerup": ({
			(: exert_function, "xiantiandafa" :),
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.ju" :),
			(: perform_action, "strike.lianhuan" :),
			(: perform_action, "sword.ding" :),
			(: perform_action, "sword.qixing" :),
			(: perform_action, "sword.sanqing" :),
			(: perform_action, "sword.tonggui" :),}),
		"perform1": ({
			(: perform_action, "sword.sanqing" :),
			(: perform_action, "sword.tonggui" :),}),
		"perform2": ({
			(: perform_action, "strike.ju" :),
			(: perform_action, "sword.ding" :),}),
	]),
	([	"party": "dali",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "rong" :),}),
		"perform": ({
			(: perform_action, "unarmed.liumaijingshen" :),
			(: perform_action, "finger.qiankun" :),
			(: perform_action, "unarmed.sandie" :),
			(: perform_action, "sword.ailao" :),
			(: perform_action, "sword.fenglei" :),
			(: perform_action, "sword.jingtian" :),}),
		"perform1": ({
			(: perform_action, "unarmed.liumaijingshen" :),
			(: perform_action, "sword.ailao" :),}),
		"perform2": ({
			(: perform_action, "finger.qiankun" :),
			(: perform_action, "unarmed.sandie" :),}),
	]),
	([	"party": "tiezhang",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "wu" :),
			(: perform_action, "unarmed.zhangdao" :),}),
		"perform": ({
			(: perform_action, "dodge.piaowu" :),
			(: perform_action, "unarmed.tiezhangxianglong" :),
			(: perform_action, "unarmed.tianlei" :),
			(: perform_action, "axe.duan" :),
			(: perform_action, "axe.hongtianza" :),
			(: perform_action, "axe.tiaoyan" :),}),
		"perform1": ({
			(: perform_action, "unarmed.tiezhangxianglong" :),
			(: perform_action, "unarmed.tianlei" :),}),
		"perform2": ({
			(: perform_action, "dodge.piaowu" :),
			(: perform_action, "axe.tiaoyan" :),
			(: perform_action, "axe.hongtianza" :),}),
	]),
	([	"party": "murong",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "dodge.yanling" :),}),
		"perform": ({
			(: perform_action, "parry.xingyi" :),
			(: perform_action, "parry.yihuajiemu" :),
			(: perform_action, "finger.dianxue" :),
			(: perform_action, "sword.kuangjian" :),
			(: perform_action, "sword.lianhuan" :),
			(: perform_action, "sword.qixing" :),
			(: perform_action, "blade.yingzhang" :),}),
		"perform1": ({
			(: perform_action, "parry.yihuajiemu" :),
			(: perform_action, "sword.kuangjian" :),
			(: perform_action, "sword.qixing" :),}),
		"perform2": ({
			(: perform_action, "finger.dianxue" :),}),
	]),
	([	"party": "kunlun",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "strike.liuyun" :),}),
		"perform": ({
			(: perform_action, "art.shimianmaifu" :),
			(: perform_action, "strike.yixing" :),
			(: perform_action, "strike.diezhang" :),
			(: perform_action, "unarmed.shuangjue" :),
			(: perform_action, "sword.feixue" :),
			(: perform_action, "sword.jianqin" :),
			(: perform_action, "sword.juedi" :),
			(: perform_action, "sword.ren" :),}),
		"perform1": ({
			(: perform_action, "strike.yixing" :),
			(: perform_action, "unarmed.shuangjue" :),
			(: perform_action, "sword.feixue" :),
			(: perform_action, "sword.jianqin" :),}),
		"perform2": ({
			(: perform_action, "art.shimianmaifu" :),}),
	]),
	([	"party": "lingxiao",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "dodge.snowfly" :),
			(: perform_action, "unarmed.yanxue" :),
			(: perform_action, "sword.fengxue" :),
			(: perform_action, "sword.wanmei" :),
			(: perform_action, "sword.xuehua" :),
			(: perform_action, "blade.jinwu" :),}),
		"perform1": ({
			(: perform_action, "sword.wanmei" :),
			(: perform_action, "sword.xuehua" :),
			(: perform_action, "blade.jinwu" :),}),
		"perform2": ({
			(: perform_action, "dodge.snowfly" :),
			(: perform_action, "sword.fengxue" :),}),
	]),
	([	"party": "wdjiao",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "dodge.snake" :),
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "sword.suo" :),
			(: perform_action, "whip.judu" :),}),
		"perform1": ({
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "sword.suo" :),}),
		"perform2": ({
			(: perform_action, "dodge.snake" :),}),
	]),
	([	"party": "noname",
		"powerup": ({
			(: exert_function, "taixuan" :),}),
		"perform": ({
			(: perform_action, "sword.tianwai" :),
			(: perform_action, "sword.shisan" :),
			(: perform_action, "sword.qu" :),
			(: perform_action, "sword.ci" :),
			(: perform_action, "sword.erguang" :),
			(: perform_action, "blade.lian" :),
			(: perform_action, "blade.huanying" :),}),
		"perform1": ({
			(: perform_action, "sword.shisan" :),
			(: perform_action, "blade.lian" :),}),
		"perform2": ({
			(: perform_action, "sword.qu" :),
			(: perform_action, "sword.wushuang" :),
			(: perform_action, "blade.huanying" :),}),
	]),
	([	"party": "jiuyin",
		"powerup": ({
			(: exert_function, "zongjue" :),
			(: perform_action, "dodge.huanyinbu" :),
			(: perform_action, "unarmed.fumo" :),}),
		"perform": ({
			(: exert_function, "yihun" :),
			(: perform_action, "unarmed.qiankun" :),
			(: perform_action, "claw.sanjue" :),
			(: perform_action, "strike.cuixin" :),
			(: perform_action, "strike.yinyang" :),
			(: perform_action, "sword.xuanyin" :),
			(: perform_action, "sword.zhan" :),
			(: perform_action, "whip.chanrao" :),
			(: perform_action, "whip.feilong" :),}),
		"perform1": ({
			(: perform_action, "claw.sanjue" :),
			(: perform_action, "strike.cuixin" :),
			(: perform_action, "sword.xuanyin" :),
			(: perform_action, "whip.feilong" :),}),
		"perform2": ({
			(: exert_function, "yihun" :),
			(: perform_action, "unarmed.qiankun" :),
			(: perform_action, "strike.yinyang" :),
			(: perform_action, "sword.zhan" :),
			(: perform_action, "whip.chanrao" :),}),
	]),
});


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
