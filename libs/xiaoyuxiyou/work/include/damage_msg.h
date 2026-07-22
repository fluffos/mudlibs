#include "ansi.h"

nosave mapping family =([
		"南海普陀山"	:	1,
		"阎罗地府"		:	-1,
		"方寸山三星洞"	:	1,
		"月宫"			:	1,
		"大雪山"		:	-1,
		"五庄观"		:	1,
		"东海龙宫"		:	1,
		"将军府"		:	1,
		"火云洞"		:	-1,
		"陷空山无底洞"	:	-1,
		"蜀山派"		:	1,
		"盘丝洞"		:	-1,
		"百花谷"		:	1,
		"散仙派"		:	1,
]);

nosave string *head_damage_me_msg = ({
        HIR "$n"HIR"觉得头有一点发晕。\n" NOR,
        HIB "$n"HIB"觉得一阵晕眩，身体晃了一下。\n" NOR,
        BLU "$n"BLU"只得眼冒金星，浑身发飘。\n" NOR,
});

nosave string *body_damage_me_msg = ({
        HIR "$n"HIR"只觉$l隐隐作痛，体内真气受到一点振荡。\n" NOR,
        HIB "$n"HIB"只觉$l生疼，体内真气一阵乱窜。\n" NOR,
        BLU "$n"BLU"只觉得$l处剧痛，连带着体内真气一阵外泄。\n" NOR,
});

nosave string *guard_msg = ({
        CYN"$N"CYN"注视着$n"CYN"的行动，企图寻找机会出手。\n"NOR,
        CYN"$N"CYN"正盯着$n"CYN"的一举一动，随时准备发动攻势。\n"NOR,
        CYN"$N"CYN"缓缓地移动脚步，想要找出$n"CYN"的破绽。\n"NOR,
        CYN"$N"CYN"目不转睛地盯着$n"CYN"的动作，寻找进攻的最佳时机。\n"NOR,
        CYN"$N"CYN"慢慢地移动着脚步，伺机出手。\n"NOR,
});

nosave string *catch_hunt_msg = ({
        HIW"$N"HIW"和$n"HIW"仇人相见份外眼红，立刻打了起来！\n"NOR,
        HIW"$N"HIW"对着$n"HIW"大喝：「可恶，又是你！」\n"NOR,
        HIW"$N"HIW"和$n"HIW"一碰面，二话不说就打了起来！\n"NOR,
        HIW"$N"HIW"一眼瞥见$n"HIW"，「哼」的一声冲了过来！\n"NOR,
        HIW"$N"HIW"一见到$n"HIW"，愣了一愣，大叫：「我宰了你！」\n"NOR,
        HIW"$N"HIW"喝道：「$n"HIW"，我们的帐还没算完，看招！」\n"NOR,
        HIW"$N"HIW"喝道：「$n"HIW"，看招！」\n"NOR,
});

nosave string *winner_msg = ({
        CYN"\n$N"CYN"哈哈大笑，说道：承让了！\n\n"NOR,
        CYN"\n$N"CYN"双手一拱，笑着说道：承让！\n\n"NOR,
        CYN"\n$N"CYN"胜了这招，向后跃开三尺，笑道：承让！\n\n"NOR,
        CYN"\n$n"CYN"脸色微变，说道：佩服，佩服！\n\n"NOR,
        CYN"\n$n"CYN"向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n"NOR,
        CYN"\n$n"CYN"向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n"NOR,
        CYN"\n$N"CYN"双手一拱，笑著说道：知道我的利害了吧！\n\n" NOR,
        CYN"\n$N"CYN"胜了这招，向后跃开三尺，叹道：真是拔剑四顾心茫然！\n\n" NOR,
        CYN"\n$n"CYN"向后退了几步，说道：这场比试算我输了，下回看我怎么收拾你！\n\n" NOR,
        CYN"\n$n"CYN"向后一纵，恨恨地说道：君子报仇，十年不晚！\n\n" NOR,
        CYN"\n$n"CYN"脸色一寒，说道：算了算了，就当是我让你吧！\n\n" NOR,
        CYN"\n$n"CYN"纵声而笑，叫道：“你运气好！你运气好！”一面身子向后跳开。\n\n" NOR,
        CYN"\n$n"CYN"脸色微变，说道：佩服，佩服！\n\n" NOR,
});

nosave mapping damage_msgs = ([
        "擦伤"  : ({
                "结果只在$p$l擦出一条淤青的痕迹。\n",
                "结果$p$l给擦出一条细长的划痕。\n",
                "结果「嗤」的一声，$p$l现出一抹长长的伤痕，沁出点点的鲜血！\n",
                "结果鲜血从$p$l新增的擦痕处「哗」的流溅而出！\n",
                "结果只听$n一声闷哼，捂住一条深长伤口，鲜血止不住的从指缝流出！\n",
                "结果只见$n$l皮肉翻转，血肉模糊，一条长长的伤口处隐隐可见皑皑白骨！\n",
                }),
        "抓伤"  : ({
                "结果只在$p$l抓出一条红肿的血迹。\n",
                "结果$p$l给抓出一条细长的血痕。\n",
                "结果$p$l的衣襟给抓得片片飞散，隐约可见悚然的血印！\n",
                "结果$p$l处的衣襟给抓出一道长长的口子，鲜血止不住的向外直淌！\n",
                "结果从$n$l破碎的衣襟可见一条又长又深的伤口向外淌着鲜血！\n",
                "结果只见$n闷哼一声，连连后退，$l衣襟破碎，血肉模糊，！\n",
                }),
        "割伤"  : ({
                "结果只是轻轻地划破$p的皮肉。\n",
                "结果在$p$l划出一道细长的血痕。\n",
                "结果「嗤」地一声划出一道伤口！\n",
                "结果「嗤」地一声划出一道血淋淋的伤口！\n",
                "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n",
                "结果只听见$n一声惨嚎，$p的$l被划出一道深及见骨的可怕伤口！\n",
                }),
        "砍伤"  : ({
                "结果$w从$n$l旁带过，劲风吹得$p的衣襟「嗍嗍」直响。\n",
                "结果在$n$l砍出一道细长的血痕。\n",
                "结果「噗嗤」一声劈出一道血淋淋的伤口！\n",
                "结果只听「噗」地一声，$n的$l被劈得血如泉涌，痛得$p咬牙切齿！\n",
                "结果「噗」地一声砍出一道又长又深的伤口，溅得$N满脸鲜血！\n",
                "结果只听见$n一声惨嚎，$p的$l被劈开一道深及见骨的可怕伤口！\n",
                }),
        "劈伤"  : ({
                "结果只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n",
                "结果在$n$l砍出一道细长的血痕。\n",
                "结果「噗嗤」一声劈出一道血淋淋的伤口！\n",
                "结果只听「噗」地一声，$n的$l被劈得血如泉涌，痛得$p咬牙切齿！\n",
                "结果「噗」地一声砍出一道又长又深的伤口，溅得$N满脸鲜血！\n",
                "结果只听见$n一声惨嚎，$p的$l被劈开一道深及见骨的可怕伤口！\n",
                }),
        "枪伤"  : ({
                "结果$w「噗」的一声，将$p$l处的皮肉挑了小口。\n",
                "结果「嗤」的一声，血花飞溅中$p$l已经多出一个醒目的创口。\n",
                "结果$w「噗」地一声刺入了$n$l寸许！\n",
                "结果「噗」地一声$w扎进$n的$l，使$p不由自主地退了步！\n",
                "结果「噗嗤」地一声，$w已在$p$l扎出一个血肉模糊的血窟窿！\n",
                "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！\n",
                }),
        "刺伤"  : ({
                "结果只是轻轻地刺破$p的皮肉。\n",
                "结果在$p$l刺出一个创口。\n",
                "结果「噗」地一声刺入了$n$l寸许！\n",
                "结果「噗」地一声刺进$n的$l，使$p不由自主地退了步！\n",
                "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n",
                "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！\n",
                }),
        "筑伤"  : ({
                "结果只是轻轻地一触，在$n的皮肤上留下一点白痕。\n",
                "结果在$p的$l留下几道血痕。\n",
                "结果一下子筑中，$n立刻血流如注！\n",
                "结果「哧」地一声，$n顿时鲜血飞溅！\n",
                "结果这一下「哧」地一声，$n被筑得浑身是血！\n",
                "结果「哧」重重地砸中，$n被筑得千疮白孔，血肉四处横飞！\n",
                }),
        "掌伤"  : ({
                "结果拍个正着，可惜劲道只比拍苍蝇稍微重了点。\n",
                "结果「啪」的一声，$p的$l立刻瘀青了一块。\n",
                "结果「砰」地一声，$n退了两步，面色变得十分难看！\n",
                "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n",
                "结果一掌正拍在$p$l，$n连退数步，面色刹时变得苍白！\n",
                "结果只听见「砰」地一声巨响，$n口中鲜血喷出，整个人横飞了出去！\n",
                }),
        "拳伤"  : ({
                "结果捣了正着，可惜力道只比拍苍蝇稍微重了点。\n",
                "结果打了个正着，$n的$l登时肿了一块老高！\n",
                "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n",
                "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n",
                "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n",
                "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！\n",
                }),
        "瘀伤"  : ({
                "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n",
                "结果在$p的$l造成一处瘀青。\n",
                "结果一击命中，$n的$l登时肿了一块老高！\n",
                "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n",
                "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n",
                "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！\n",
                }),
        "撞伤"  : ({
                "结果在$p的$l撞出一个小臌包。\n",
                "结果撞个正着，$n的$l登时肿了一块老高！\n",
                "结果「砰」地一声，$n给撞得连腰都弯了！\n",
                "结果这一下「轰」地一声撞得$n眼冒金星，差一点摔倒！\n",
                "结果重重地撞中，$n眼前一黑，「哇」地一声吐出一口鲜血！\n",
                "结果只听见「轰」地一声巨响，$n像一捆稻草般飞了出去！\n",
                }),
        "砸伤"  : ({
                "结果只是轻轻地碰到，等于给$n搔了一下痒。\n",
                "结果砸个正着，$n的$l登时肿了一块老高！\n",
                "结果砸个正着，$n闷哼一声显然吃了不小的亏！\n",
                "结果「砰」地一声，$n疼得连腰都弯了！\n",
                "结果这一下「轰」地一声砸得$n眼冒金星，差一点摔倒！\n",
                "结果只听见「轰」地一声巨响，$n被砸得血肉模糊，惨不忍睹！\n",
                }),
        "震伤"  : ({
                "结果在$n身上一触即逝，等于给$n搔了一下痒。\n",
                "结果$n晃了一晃，吃了点小亏。\n",
                "结果$n气息一窒，显然有点呼吸不畅！\n",
                "结果$n体内一阵剧痛，看起来内伤不轻！\n",
                "结果「嗡」地一声$n只觉得眼前一黑，双耳轰鸣不止！\n",
                "结果只听见「嗡」地一声巨响，$n「哇」地一声吐出一口鲜血，五脏六腑都错了位！\n",
                }),
        "内伤"  : ({
                "结果在$n身上一触即逝，等于给$n搔了一下痒。\n",
                "结果$n晃了一晃，吃了点小亏。\n",
                "结果$n气息一窒，显然有点呼吸不畅！\n",
                "结果$n体内一阵剧痛，看起来内伤不轻！\n",
                "结果「嗡」地一声$n只觉得眼前一黑，双耳轰鸣不止！\n",
                "结果只听见「嗡」地一声巨响，$n「哇」地一声吐出一口鲜血，五脏六腑都错了位！\n",
                }),
        "鞭伤"  : ({
                "结果$w只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n",
                "结果在$n$l抽出一道轻微的紫痕。\n",
                "结果「啪」地一声在$n$l抽出一道长长的血痕！\n",
                "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！\n",
                "结果「啪」地一声爆响！这一下好厉害，只抽得$n皮开肉绽，血花飞溅！\n",
                "结果只听见$n一声惨嚎，$w重重地抽上了$p的$l，$n顿时血肉横飞，十命断了九条！\n",
                }),
        "抽伤"  : ({
                "结果$w只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n",
                "结果在$n$l抽出一道轻微的紫痕。\n",
                "结果「啪」地一声在$n$l抽出一道长长的血痕！\n",
                "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！\n",
                "结果「啪」地一声爆响！这一下好厉害，只抽得$n皮开肉绽，血花飞溅！\n",
                "结果只听见$n一声惨嚎，$w重重地抽上了$p的$l，$n顿时血肉横飞，十命断了九条！\n",
                }),        
        "反震伤" : ({
                "结果$N受到$n的内力反震，闷哼一声。\n",
                "结果$N被$n的反震得站立不稳，摇摇晃晃。\n",
                "结果$N被$n以内力反震，「嘿」地一声退了两步。\n",
                "结果$N被$n的震得反弹回来的力量震得半身发麻。\n",
                "结果$N被$n的内力反震，胸口有如受到一记重击，连退了五六步！\n",
                "结果$N被$n内力反震，眼前一黑，狂吐鲜血，身子象断了线的风筝向後飞去！！\n",
                }),
        "点穴"  : ({
                "结果$n痛哼一声，在$p的$l造成一处淤青。\n",
                "结果一击命中，$N点中了$n$l上的穴道，$n只觉一阵麻木！\n",
                "结果$n闷哼了一声，脸上一阵青一阵白，登时觉得$l麻木！\n",
                "结果$n脸色一下变得惨白，被$N点中$l的穴道,一阵疼痛遍布整个$l！\n",
                "结果$n一声大叫，$l的穴道被点中,疼痛直入心肺！\n",
                "结果只听见$n一声惨叫，一阵剧痛夹杂着麻痒游遍全身，跟着直挺挺的倒了下去！\n",
                }),
        "其他"  : ({                
                "结果造成轻微的伤势！\n",
                "结果造成一处严重伤势！\n",
                "结果造成颇为严重的伤势！\n",
                "结果造成相当严重的伤势！\n",
                "结果造成极其严重的伤势！\n",
                "结果造成非常可怕的严重伤势！\n",
                }),
]);

nosave string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。"NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。"NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。"NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。"NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。"NOR;
	if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤着实不轻。"NOR;
	if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑着不倒下去。"NOR;
	if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。"NOR;
	if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。"NOR;
	if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。"NOR;
	return RED "受伤过重，已经有如风中残烛，随时都可能断气。"NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。"NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。"NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。"NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。"NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。"NOR;
	if( ratio > 40 ) return HIR "似乎非常疲惫，看来需要好好休息了。"NOR;
	if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑着不倒下去。"NOR;
	if( ratio > 20 ) return HIR "看起来已经力不从心,马上要支持不住了。"NOR;
	if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。"NOR;
	return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。"NOR;
}

string sen_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来头脑清醒，一点也不迷糊。"NOR;
	if( ratio > 90 ) return HIG "拍了拍自己的脑袋，似乎有点不太得劲。"NOR;
	if( ratio > 80 ) return HIY "看起来有些迷糊了。"NOR;
	if( ratio > 60 ) return HIY "的确有点迷糊了，但还辨得出东西南北。"NOR;
	if( ratio > 40 ) return HIR "两眼发直，口角流涎，神智开始混乱。"NOR;
	if( ratio > 20 ) return HIR "迷迷糊糊，摇摇晃晃，已经辨不出东西南北了。"NOR;
	if( ratio > 10 ) return RED "神智已经处在极度混乱中,再也支持不住了。"NOR;
	return RED "心智已经完全迷失，随时都有可能背过气去。"NOR;
}                       

varargs string damage_msg(int damage, string type,object who)
{
	int data,per;
	string str=0;

	if( stringp(str=this_object()->query_damage_msg(damage,type)) )
    	return str;
	if( damage == 0 ) 
    	return "结果没有造成任何伤害。\n";
		
	if( member_array(type,keys(damage_msgs))==-1 )
    	type = "其他";
	if( who && objectp(who) )
	{
		data = (int)who->query("kee");
		if( data<=0 )
			return damage_msgs[type][5];
		per = damage*100/data;
		if( per<10 ) 
        	return damage_msgs[type][0];
		else if( per<20 ) 
        	return damage_msgs[type][1];
		else if( per<40 ) 
        	return damage_msgs[type][2];
		else if( per<60 ) 
        	return damage_msgs[type][3];
		else if( per<80 ) 
        	return damage_msgs[type][4];
		else
        	return damage_msgs[type][5];
	}    	
	if( damage<10 ) 
        return damage_msgs[type][0];
	else if( damage<20 ) 
        return damage_msgs[type][1];
	else if( damage<40 ) 
        return damage_msgs[type][2];
	else if( damage<60 ) 
        return damage_msgs[type][3];
	else if( damage<80 ) 
        return damage_msgs[type][4];
	else    
		return damage_msgs[type][5];
}

nosave string *danger_limbs = ({
        "头部", "颈部", "胸口", "后心","小腹",
});

nosave mapping limb_damage = ([
// 人类身体部位
        "头部"  :   100,
        "颈部"  :   90,
        "胸口"  :   90,
        "后心"  :   80,
        "左肩"  :   50,
        "右肩"  :   55,
        "左臂"  :   40,
        "右臂"  :   45,
        "左手"  :   20,
        "右手"  :   30,
        "腰间"  :   60,
        "小腹"  :   70,
        "左腿"  :   40,
        "右腿"  :   50,
        "左脚"  :   35,
        "右脚"  :   40,
//  动物身体部位
        "身体"  :   80,
        "前脚"  :   40,
        "后脚"  :   50,
        "腿部"  :   40,
        "尾巴"  :   10,
        "翅膀"  :   50,
        "爪子"  :   40,
]);

nosave mapping KillMsg = ([
        "slash"         : "斩",         "slice"         : "砍",
        "chop"          : "劈",         "hack"          : "劈",
        "thruse"        : "刺",         "pierce"        : "刺",
        "wave"          : "鞭",         "whip"          : "抽",
        "impale"        : "戳",         "rake"          : "筑",
        "bash"          : "砸",         "crush"         : "砸",
        "slam"          : "挫",         "throw"         : "射",
        "shoot"         : "射",         
]);

varargs void report_status(object ob, int effective)
{
	string str;
	if( str=ob->query_report_status() )
		message_vision( "( $N"+str+" )\n",ob);
	else if( effective ) 
                message_vision( "( $N" + eff_status_msg((int)ob->query("eff_kee") * 100 /(1+(int)ob->query("max_kee")))+ " )\n", ob);
        else    message_vision( "( $N" + status_msg((int)ob->query("kee") * 100/(1+(int)ob->query("max_kee")) ) + " )\n", ob);
}

varargs void report_sen_status(object ob, int effective)
{
	string str;
	if( str = ob->query_report_sen_status() )
		message_vision( "( $N"+str+" )\n",ob);
	else	message_vision( "( $N" + sen_status_msg((int)ob->query("sen") * 100 /(1+(int)ob->query("max_sen")) ) + " )\n", ob);
}