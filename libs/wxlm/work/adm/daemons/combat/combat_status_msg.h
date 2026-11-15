string *guard_msg = ({
	append_color(CYN "$N凝神聚气，双目如电般紧盯$n，伺机而动。"NOR"\n", CYN),
	append_color(CYN "$N身形微晃，目光如炬，将$n的一举一动尽收眼底。"NOR"\n", CYN),
	append_color(CYN "$N脚踏八卦方位，暗运内力，等待$n露出破绽。"NOR"\n", CYN),
	append_color(CYN "$N气沉丹田，双目神光内敛，如猛虎般紧盯着$n。"NOR"\n", CYN),
	append_color(CYN "$N运转真气，身形飘忽不定，伺机向$n发起致命一击。"NOR"\n", CYN),
});

string *winner_msg = ({
	append_color(CYN "\n$N潇洒一笑，拱手道：承让了，今日一战令在下获益良多！"NOR"\n", CYN),
	append_color(CYN "\n$N凝神收势，抱拳笑道：承让，阁下武功着实不凡。"NOR"\n", CYN),
	append_color(CYN "\n$N飘然退后三丈，含笑道：今日与阁下切磋，当真是武林一大快事！"NOR"\n", CYN),
	append_color(CYN "\n$N收势站定，朗声道：承蒙阁下放手一战，在下感激不尽！"NOR"\n", CYN),
	append_color(CYN "\n$n踉跄后退，咬牙道：今日栽在你手里，他日必当讨教！"NOR"\n", CYN),
	append_color(CYN "\n$n身形疾退，冷声道：胜负乃兵家常事，他日必当再战！"NOR"\n", CYN),
	append_color(CYN "\n$n神色凝重，拱手道：阁下功夫精妙，在下甘拜下风。"NOR"\n", CYN),
	append_color(CYN "\n$n身形飘然而退，长叹道：今日之败，实乃技不如人，佩服佩服！"NOR"\n", CYN),
	append_color(CYN "\n$n抹去额头冷汗，正色道：阁下武功造诣，令在下叹为观止！"NOR"\n", CYN),
	append_color(CYN "\n$n凝神静气，躬身道：承蒙阁下赐教，在下获益良多。"NOR"\n", CYN),
	append_color(CYN "\n$n神色凛然，拱手道：今日一战，方知天外有天，人外有人！"NOR"\n", CYN),
	append_color(CYN "\n$N止戈入鞘，淡然道：承让了，阁下武功已臻化境，令人钦佩。"NOR"\n", CYN),
	append_color(CYN "\n$N整理衣衫，微笑道：得与阁下过招，不虚此行。"NOR"\n", CYN),
	append_color(CYN "\n$N拱手抱拳，正色道：今日一战，使我受益匪浅，多谢指教。"NOR"\n", CYN),
	append_color(CYN "\n$n退后数步，凝重道：阁下武功精深，在下自愧不如。"NOR"\n", CYN),
	append_color(CYN "\n$n揉了揉酸痛的手腕，苦笑道：阁下内力深厚，实非在下所能企及。"NOR"\n", CYN),
	append_color(CYN "\n$n深吸一口气，拱手道：今日领教阁下绝学，实在是武林幸事。"NOR"\n", CYN),
	append_color(CYN "\n$N收起内力，含笑道：承蒙手下留情，他日必当报答。"NOR"\n", CYN),
	append_color(CYN "\n$n擦去嘴角血迹，沉声道：今日败于阁下手中，也是一种缘分。"NOR"\n", CYN),
	append_color(CYN "\n$N轻轻拍去衣袖尘土，笑道：阁下武功出神入化，令人敬佩。"NOR"\n", CYN),
	append_color(CYN "\n$n扶着地面，喘息道：阁下功力深不可测，在下甘拜下风。"NOR"\n", CYN),
	append_color(CYN "\n$N收起架势，朗声道：承让了，阁下武功已达登峰造极之境。"NOR"\n", CYN),
	append_color(CYN "\n$n揉了揉发麻的手臂，感叹道：阁下内功修为，已臻化境。"NOR"\n", CYN),
	append_color(CYN "\n$N整理发髻，微笑道：今日与阁下切磋，当真是毕生难得的经历。"NOR"\n", CYN),
	append_color(CYN "\n$n拭去额头冷汗，正色道：阁下武功已达返璞归真之境，令人叹服。"NOR"\n", CYN),
	append_color(CYN "\n$N收起掌势，含笑道：承让了，阁下武功已达炉火纯青之境。"NOR"\n", CYN),
	append_color(CYN "\n$n扶着酸痛的肩膀，叹道：阁下功力精深，在下自愧弗如。"NOR"\n", CYN),
	append_color(CYN "\n$N拱手抱拳，朗声道：今日一战，使我对武学又有新的领悟。"NOR"\n", CYN),
	append_color(CYN "\n$n整理凌乱的衣衫，沉声道：阁下武功已达出神入化之境，佩服佩服。"NOR"\n", CYN),
	append_color(CYN "\n$N收起内力，微笑道：得见阁下绝学，今日不虚此行。"NOR"\n", CYN),
	append_color(CYN "\n$n揉了揉发麻的双腿，感叹道：阁下功力之深厚，令人叹为观止。"NOR"\n", CYN),
});

// message after damage info
nosave string foo_before_hit = 0;
nosave string foo_after_hit = 0;

void set_bhinfo(string msg)
{
	if (! foo_before_hit)
	{
		foo_before_hit = msg;
		return;
	}

	foo_before_hit += msg;
}

void set_ahinfo(string msg)
{
	if (! foo_after_hit)
	{
		foo_after_hit = msg;
		return;
	}

	foo_after_hit += msg;
}

string query_bhinfo() { return foo_before_hit; }

string query_ahinfo() { return foo_after_hit; }

void clear_bhinfo() { foo_before_hit = 0; }

void clear_ahinfo() { foo_after_hit = 0; }

varargs string status_msg(int ratio, int dam_type)
{
        if( !dam_type ) dam_type = 1;
        if( ratio==100 ) return HIG "精力充沛，神完气足，" NOR;
        if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力，" NOR;
        if( ratio > 90 ) return HIY "看起来可能有些不济，" NOR;
        if( ratio > 80 ) {
                if (dam_type == 3)
                        return HIY "精力有点不足，但仍攻守从容，" NOR;
                else if (dam_type == 2)
                        return HIY "神情有些恍惚，但仍应付自如，" NOR;
                else    return HIY "动作有点不太灵光，但仍有条不紊，" NOR;
        }
        if( ratio > 60 ) {
                if (dam_type == 3)
                        return HIY "行动虽然无碍，精力明显跟不上了，" NOR;
                else if (dam_type == 2)
                        return HIY "反应开始迟缓，双目无神，" NOR;
                else    return HIY "气喘嘘嘘，脸色惨白，" NOR;
        }
        if( ratio > 40 ) {
                if (dam_type == 3)
                        return HIR "精力涣散，似乎对痛痒都失去知觉，" NOR;
                else if (dam_type == 2)
                        return HIR "眼光迷离，六神无主，" NOR;
                else    return HIR "似乎十分疲惫，看来需要好好休息了，" NOR;
        }
        if( ratio > 30 ) return HIR "头重脚轻，正在勉力支撑著不倒下去，" NOR;
        if( ratio > 20 ) {
                if (dam_type == 3)
                        return HIR "看来已经麻木不仁了，" NOR;
                else if (dam_type == 2)
                        return HIR "看起来已经魂不守舍了，" NOR;
                else    return HIR "看起来已经力不从心了，" NOR;
        }
        if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜，濒于晕倒，" NOR;
      
		return RED "已经陷入半昏迷状态，神智全失，" NOR;
}

string damage_msg(int damage, string type)
{
	string str;
	if (damage == 0)
		return "结果没有造成任何伤害。\n";   
	switch (type)
	{
	case "擦伤":
	case "割伤":
		if (damage < 15)  str = "结果只是轻轻地划破$p的皮肉。"; else
		if (damage < 40)  str = "结果在$p$l划出一道细长的血痕。"; else
		if (damage < 100) str = "结果「嗤」地一声划出一道伤口！"; else
		if (damage < 200) str = "结果「嗤」地一声划出一道血淋淋的伤口！"; else
		if (damage < 400) str = "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！"; else
				  str = "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的伤口！！";
		  return str  +"\n";
		break;
	case "刺伤":
		if (damage < 15)  str = "结果只是轻轻地刺破$p的皮肉。"; else
		if (damage < 40)  str = "结果在$p$l刺出一个创口。"; else
		if (damage < 100) str = "结果「噗」地一声刺入了$n$l寸许！"; else
		if (damage < 200) str = "结果「噗」地一声深深刺进$n的$l！"; else
		if (damage < 400) str = "结果「噗嗤」地一声，$w已在$p$l刺出一个血窟窿！"; else
				  str = "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！";
		 return str  +"\n";
		break;
	case "瘀伤":
	case "震伤":
		if (damage < 15)  str = "结果只是轻轻地碰到，比拍苍蝇稍微重了点。"; else
		if (damage < 40)  str = "结果在$p的$l造成一处瘀青。"; else
		if (damage < 100) str = "结果一击命中，$n的$l登时肿了一块老高！"; else
		if (damage < 150) str = "结果一击命中，$n闷哼了一声显然吃了不小的亏！"; else
		if (damage < 200) str = "结果「砰」地一声，$n退了两步！"; else
		if (damage < 400) str = "结果这一下「砰」地一声，打得$n差一点摔倒在地！"; else
		if (damage < 800) str = "结果重重地击中，$n「哇」地一声吐出一口鲜血！"; else
				  str = "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！";
		 return str +"\n";
		break;
	case "内伤":
		if (damage < 15)  str = "结果只是把$n打得退了半步，毫发无损。"; else
		if (damage < 40)  str = "结果$n痛哼一声，在$p的$l造成一处瘀伤。"; else
		if (damage < 100) str = "结果一击命中，把$n打得痛得弯下腰去！"; else
		if (damage < 150) str = "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！"; else
		if (damage < 200) str = "结果$n闷哼了一声，脸色一下变得惨白，显然受伤不轻！"; else
		if (damage < 400) str = "结果重重地击中，$n「哇」地一声吐出一口鲜血！"; else
		if (damage < 800) str = "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！"; else
				  str = "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！";
		  return str +"\n";
		break;
	case "点穴":
		if (damage < 15)  str = "结果只是轻轻的碰到$n的$l，根本没有点到穴道。"; else
		if (damage < 40)  str = "结果$n痛哼一声，在$p的$l造成一处淤青。"; else
		if (damage < 100) str = "结果一击命中，$N点中了$n$l上的穴道，$n只觉一阵麻木！"; else
		if (damage < 200) str = "结果$n闷哼了一声，脸上一阵青一阵白，登时觉得$l麻木！"; else
		if (damage < 400) str = "结果$n脸色一下变得惨白，被$N点中$l的穴道,一阵疼痛遍布整个$l！"; else
		if (damage < 800) str = "结果$n一声大叫，$l的穴道被点中,疼痛直入心肺！"; else
				  str = "结果只听见$n一声惨叫，一阵剧痛游遍全身，跟着直挺挺的倒了下去！";
		  return str +"\n";
		break;
	case "抽伤":
		if (damage < 15)  str = "结果只是在$n的皮肉上碰了碰，好象只蹭破点皮。"; else
		if (damage < 40)  str = "结果在$n$l抽出一道轻微的紫痕。"; else
		if (damage < 100) str = "结果「啪」地一声在$n$l抽出一道长长的血痕！"; else
		if (damage < 200) str = "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！"; else
		if (damage < 400) str = "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！"; else
		if (damage < 800) str = "结果「啪」地一声爆响！这一下好厉害，只抽得$n皮开肉绽，血花飞溅！"; else
				  str = "结果只听见$n一声惨嚎，$w重重地抽上了$p的$l，$n顿时血肉横飞！";
		  return str +"\n";
		break;
	case "反震伤":
		if (damage < 15)  str = "结果$N受到$n的内力反震，闷哼一声。"; else
		if (damage < 40)  str = "结果$N被$n的反震得气血翻腾，大惊失色。"; else
		if (damage < 100) str = "结果$N被$n的反震得站立不稳，摇摇晃晃。"; else
		if (damage < 200) str = "结果$N被$n以内力反震，「嘿」地一声退了一步。"; else
		if (damage < 300) str = "结果$N被$n的震得反弹回来的力量震得半身发麻。"; else
		if (damage < 400) str = "结果$N被$n的内力反震，胸口有如受到一记重击，差点透不过气！"; else
		if (damage < 600) str = "结果$N被$n内力反震，眼前一黑，差点晕过去！！"; else
				  str = "结果$N被$n内力反震，狂吐鲜血，身子象断了线的风筝向後飞去！！";
		   return str +"\n";
		break;
	case "砸伤":
		if (damage < 10)  str = "结果只是轻轻地碰到，像是给$n搔了一下痒。"; else
		if (damage < 40)  str = "结果在$n的$l砸出一个小臌包。"; else
		if (damage < 100) str = "结果$N这一下砸个正着，$n的$l登时肿了一块老高！"; else
		if (damage < 150) str = "结果$N这一下砸个正着，$n闷哼一声显然吃了不小的亏！"; else
		if (damage < 200) str = "结果只听「砰」地一声，$n疼得连腰都弯了下来！"; else
		if (damage < 400) str = "结果这一下「轰」地一声砸得$n眼冒金星，差一点摔倒！"; else
		if (damage < 800) str = "结果重重地砸中，$n眼前一黑，「哇」地一声吐出一口鲜血！"; else
				  str = "结果只听见「轰」地一声巨响，$n被砸得血肉模糊，惨不忍睹！";
		   return str +"\n";
		break;
	default:
		if (! type) type = "伤害";
		if (damage < 50)  str = "结果只是勉强造成一处轻微"; else
		if (damage < 100)  str = "结果造成轻微的"; else
		if (damage < 200) str = "结果造成一处"; else
		if (damage < 300) str = "造成一处严重"; else
		if (damage < 500) str = "结果造成颇为严重的"; else
		if (damage < 700) str = "结果造成相当严重的"; else
		if (damage < 900) str = "结果造成十分严重的"; else
		if (damage < 1000) str = "结果造成极其严重的"; else
				  str = "结果造成非常可怕的严重";
		return  str+ type  +"！\n";
	}
}

varargs string eff_status_msg(int ratio, int dam_type)
{
        if( !dam_type ) dam_type = 1;
        if( ratio==100 ) return HIG "气血充盈，神完气足。" NOR;
        if( ratio > 95 ) return HIG "略有疲态，却也无伤大体。" NOR;
        if( ratio > 90 ) {
                if (dam_type == 3)
                        return HIY "真气有些紊乱，内息不畅。" NOR;
                else if (dam_type == 2)
                        return HIY "神思恍惚，精神受损。" NOR;
                else    return HIY "皮肉微创，尚可支撑。" NOR;
        }
        if( ratio > 80 ) return HIY "伤痕累累，却也能强撑。" NOR;
        if( ratio > 60 ) {
                if (dam_type == 3)
                        return HIY "真气外泄，内力涣散。" NOR;
                else if (dam_type == 2)
                        return HIY "七窍流血，神智不清。" NOR;
                else    return HIY "鲜血淋漓，伤势不轻。" NOR;
        }
        if( ratio > 40 ) {
                if (dam_type == 3)
                        return HIY "气息奄奄，命在旦夕。" NOR;
                else    return HIR "气血翻涌，摇摇欲坠。" NOR;
        }
        if( ratio > 30 ) return HIR "重伤濒危，苦苦支撑。" NOR;
        if( ratio > 20 ) return HIR "遍体鳞伤，命悬一线。" NOR;
        if( ratio > 10 ) return RED "血流如注，已然重伤垂死。" NOR;
        if( ratio > 5  ) return RED "气若游丝，已是命在顷刻。" NOR;
        return RED "形神俱灭，只待断气。" NOR;
}

varargs mixed report_status(object ob, int effective)
{
        int eff_ratio = 100;
        int ratio = 100;
        int k_stat, g_stat;
        int d_type = 1;
        int e_type = 1;
        string str;

        if( !ob || !ob->query("max_qi") || !ob->query("max_jing") ) return;

        k_stat = (int) ob->query("qi") * 100 / (int)ob->query("max_qi");
        g_stat = (int) ob->query("jing") * 100 / (int)ob->query("max_jing");

        if (ratio > k_stat ) {
                ratio =  k_stat;
        }
        if (ratio > g_stat ) {
                ratio =  g_stat;
                d_type = 3;
        }

        k_stat = (int) ob->query("eff_qi") * 100 / (int)ob->query("max_qi");
        g_stat = (int) ob->query("eff_jing") * 100 / (int)ob->query("max_jing");

        if (eff_ratio > k_stat ) {
                eff_ratio =  k_stat;
        }

        if (eff_ratio > g_stat ) {
                eff_ratio =  g_stat;
                e_type = 3;
        }

        str = "( $N" + status_msg(ratio, d_type) + eff_status_msg(eff_ratio, e_type) + " )\n";
        if( !effective )
                message_vision(str, ob);
        else
                return str;
}