#ifndef _COMBAT_MSG_H_
#define _COMBAT_MSG_H_

static string *guard_msg = ({
	CYN "$N注视着$n的行动，企图寻找机会出手。\n" NOR,
	CYN "$N正盯着$n的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N缓缓地移动着，想要找出$n的破绽。\n" NOR,
        CYN "$N聚精会神地盯着$n，寻找最佳出招机会。\n" NOR,
	CYN "$N目不转睛地盯着$n的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N慢慢地移动着，伺机出手。\n" NOR,
});

static string *catch_hunt_human_msg = ({
	HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
	HIW "$N对着$n大喝：「可恶，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
	HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR,
});

static string *catch_hunt_beast_msg = ({
	HIW "$N怒吼一声，扑了过来攻击$n！\n" NOR,
	HIW "$N对着$n大吼，想杀死$n！\n" NOR,
	HIW "$N发出连串低吼，突然暴起攻击$n！\n" NOR,
});

static string *catch_hunt_bird_msg = ({
	HIW "$N对着$n一声怒鸣，飞冲了过来！\n" NOR,
	HIW "$N怒鸣几声，突然暴起攻击$n！\n" NOR,
	HIW "$N一声锐鸣，猛然向$n发起攻击！\n" NOR,
});

static string *winner_msg = ({
	CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
	CYN "\n$N双手一拱，笑着说道：承让！\n\n" NOR,
        CYN "\n$n向后一纵，说道：阁下武艺果然高明，这场算是在下输了！\n\n" NOR,
	CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
	CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

static string *winner_animal_msg = ({
	CYN "\n$N退在一旁，警戒地向$n盯视！\n\n" NOR,
	CYN "\n$N退守开来，但仍然毫不放松地盯着$n！\n\n" NOR,
	CYN "\n$N退了几步，但随时可能再冲过来！\n\n" NOR
});

string damage_msg(int damage, string type)
{
	string str;

	if( damage <= 0 ) return "结果对$n没有造成任何伤害。\n";

	switch( type ) {
		case "擦伤":
		case "割伤":
		case "刀伤":
			if( damage < 20 ) return "结果只是轻轻地划破$p的皮肉。\n";
			if( damage < 80 ) return "结果在$p$l划出一道细长的血痕。\n";
			if( damage < 160 ) return "结果「嗤」地一声，在$n身上划出一道伤口！\n";
			if( damage < 320 ) return "结果「嗤」地一声，在$n身上划出一道血淋淋的伤口！\n";
			if( damage < 500 ) return "结果「嗤」地一声，在$n身上划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
			return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
		case "刺伤":
		case "剑伤":
			if( damage < 20 ) return "结果只是轻轻地刺破$n的皮肉。\n";
			if( damage < 80 ) return "结果在$n$l刺出一个创口。\n";
			if( damage < 160 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
			if( damage < 320 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
			if( damage < 500 ) return "结果「噗嗤」地一声，$w刺进了$n的$l，殷红的鲜血随即喷了出来！\n";
			return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
		case "瘀伤":
		case "击伤":
			if( damage < 20 ) return "结果只是轻轻地碰到$n，比拍苍蝇稍微重了点。\n";
			if( damage < 80 ) return "结果在$n的伤处造成一处瘀青。\n";
			if( damage < 150 ) return "结果一击命中，$n的伤处登时肿了一块老高！\n";
			if( damage < 220 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
			if( damage < 340 ) return "结果「砰」地一声，$n退了两步！\n";
			if( damage < 460 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
			if( damage < 580 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			if( damage < 700 ) return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
			return "只听见$n一声惨叫，整个身体象断了线的风筝一样飞了出去！！\n";
		case "内伤":
			if( damage < 20 ) return "结果只是把$n打得退了半步，毫发无损。\n";
			if( damage < 80 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
			if( damage < 150 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
			if( damage < 220 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
			if( damage < 340 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
			if( damage < 460 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			if( damage < 580 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
			return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		case "震伤":                
			if( damage < 100 ) return "结果$n受到$N的劲力一震，闷哼一声。\n";
			if( damage < 200 ) return "结果$n被$N以劲力一震，「嘿」地一声退了两步。\n";
			if( damage < 350 ) return "结果$n被$N以劲力一震，胸口有如受到一记重锤，连退了五六步！\n";
			if( damage < 450 ) return "结果$N的劲力一下震得$n连退了好几步，差一点摔倒！\n";
			if( damage < 600 ) return "结果$n被$N的劲力震得全身气血倒流，口中鲜血狂喷而出！\n";
			return "结果$n被$N的劲力震得眼前一黑，内脏碎裂，身子凭空飞了出去！！\n";
		case "拉伤":
			if( damage < 20 ) return "结果只是轻轻地划过了$n的皮肤。\n";
			if( damage < 70 ) return "结果在$n的$l抽出一道细长的血印。\n";
			if( damage < 160 ) return "结果「啪」地一声$w将$n的$l皮肤扯开，形成一道尺许长的伤口！\n";
			if( damage < 280 ) return "只听$n「啊」地一声吐出一口鲜血，原来$p$l内的骨头已经被$w的劲力抽裂！\n";
			if( damage < 400 ) return "结果随着「咔」地一声，$w已将$n$l处的骨头硬生生地抽断，断骨从肉里冒了出来！\n";
			return "结果$n一声惨嚎，$w已从$p$l处撕下了一大片血淋淋的皮肉，鲜血溅得满地！！\n";
		case "砸伤":
		case "挫伤":
			if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
			if( damage < 80 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
			if( damage < 160 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
			if( damage < 320 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
			if( damage < 500 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
			return "结果$w一下打在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
		case "抓伤":
			if( damage < 20 ) return "结果只是在$n$l处轻轻刮过，没有什么伤害。\n";
			if( damage < 70 ) return "结果$n皱了皱眉，$p的$l已经被拉出了一道浅浅的血痕。\n";
			if( damage < 120 ) return "结果拉下来$n$l的一点皮肉，疼得$p「哇哇」怪叫了起来！\n";
			if( damage < 190 ) return "结果「唰」地一声，$n的$l上顿时被抓出五道血痕，鲜血流了出来！\n";
			if( damage < 260 ) return "结果$n疼得大叫一声，$p$l上被抓出了几道深深的血沟，鲜血直流！\n";
			if( damage < 380 ) return "结果只听见$n一声惨嚎，$N的手爪已在$p的$l处刺出了五个血肉模糊的窟窿！\n";
			if( damage < 500 ) return "结果「啊」地一声惨叫，$n身上$l处被$N抓下了一大片皮肉，鲜血横飞满地！！\n";
			return "结果$n一声凄惨的嘶叫，$l处被连皮带肉扯下一大块，露出了白森森的骨头！！\n";
                case "摔伤":
                case "撞伤":
			if( damage < 20 ) return "结果$n脚下不稳，在地上擦破了点儿皮。\n";
			if( damage < 80 ) return "结果「啪」地一声，$n在地上摔了个屁礅。\n";
			if( damage < 160 ) return "结果$n一不小心，被$N重重摔倒在地！\n";
			if( damage < 320 ) return "结果$n被一下摔倒在地，「噗地」一声喷出了一大口鲜血！\n";
                        if( damage < 500 ) return "结果被$N这一下摔在地上，骨头「卡嚓」一声断了！\n";
			return "结果只听见$n一声惨嚎，被$N摔得血肉横飞，惨不忍睹！！\n";
		default:
			if( !type ) type = "伤害";
			str =  "结果对$n造成非常可怕的严重";
			if( damage < 500 ) str = "结果对$n造成极其严重的";
			if( damage < 400 ) str = "结果对$n造成十分严重的";
			if( damage < 300 ) str = "结果对$n造成相当严重的";
			if( damage < 200 ) str = "结果对$n造成颇为严重的";
			if( damage < 130 ) str = "结果对$n造成一处严重";
			if( damage < 80 ) str = "结果对$n造成一处";
			if( damage < 40 ) str = "结果对$n造成轻微的";
			if( damage < 10 ) str =  "结果对$n只是勉强造成一处轻微";
			return str + type + "！\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio >=100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio >= 90 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio >= 80 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio >= 70 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio >= 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio >= 50 ) return HIR "气息粗重，动作开始散乱，看来所受的伤着实不轻。" NOR;
	if( ratio >= 40 ) return HIR "已经伤痕累累，正在勉力支撑着不倒下去。" NOR;
	if( ratio >= 30 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio >= 20 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio >= 10 ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
	return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
	if( ratio >= 99 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio >= 88 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio >= 77 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio >= 66 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio >= 55 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio >= 44 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio >= 33 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑着不倒下去。" NOR;
	if( ratio >= 22 ) return HIR "看起来已经力不从心了。" NOR;
	if( ratio >= 11 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

#endif
