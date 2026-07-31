// combatd.c
// modify by zzz year 2000
#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

mapping limb_damage = ([
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
    "身体"  :   80,
    "前脚"  :   40,
    "后脚"  :   50,
    "腿部"  :   40,
    "尾巴"  :   10,
    "翅膀"  :   50,
    "爪子"  :   40,
]);

mixed danger_limbs = ({
        "头部", "颈部", "胸口", "后心","小腹",
});

mapping *combat_action = ({
        ([      "action":               "$N挥拳攻击$n的$l",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "damage_type":  "抓伤",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一脚",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N提起拳头往$n的$l捶去",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N对准$n的$l用力挥出一拳",
                "damage_type":  "瘀伤",
        ]),
});
object *player;
int userno;


string *head_damage_me_msg = ({
        HIR "你觉得头有一点发晕。\n" NOR,
        HIB "你觉得一阵晕眩，身体晃了一下。\n" NOR,
        BLU "你只得眼冒金星，浑身发飘。\n" NOR,
});

string *body_damage_me_msg = ({
        HIR "你只觉$l隐隐作痛，体内真气受到一点振荡。\n" NOR,
        HIB "你只觉$l生疼，体内真气一阵乱窜。\n" NOR,
        BLU "你只觉得$l处剧痛，连带着体内真气一阵外泄。\n" NOR,
});

string *guard_msg = ({
	CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
	CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
	CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
	HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
	HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
	CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
	CYN "\n$N双手一拱，笑著说道：承让！\n\n" NOR,
	CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
	CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

string *catch_hunt_beast_msg = ({
	HIW "$N怒吼一声，扑了过来攻击$n！\n" NOR,
	HIW "$N对着$n大吼，想杀死$n！\n" NOR,
	HIW "$N发出连串低吼，突然暴起攻击$n！\n" NOR,
});

string *catch_hunt_bird_msg = ({
	HIW "$N对着$n一声怒鸣，飞冲了过来！\n" NOR,
	HIW "$N怒鸣几声，突然暴起攻击$n！\n" NOR,
	HIW "$N一声锐鸣，猛然向$n发起攻击！\n" NOR,
});

string *winner_animal_msg = ({
	CYN "\n$N退在一旁，警戒地向$n盯视！\n\n" NOR,
	CYN "\n$N退守开来，但仍然毫不放松地盯着$n！\n\n" NOR,
	CYN "\n$N退了几步，但随时可能再冲过来！\n\n" NOR
});

void create()
{
	seteuid(getuid());
	set("name", "战斗精灵");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "造成 " + damage + " 点" + type + "。\n";
	if( damage == 0 ) return "结果没有造成任何伤害。\n";

	switch( type ) {
		case "擦伤":
		case "割伤":
			if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
			if( damage < 50 ) return "结果在$p$l划出一道细长的血痕。\n";
			if( damage < 100 ) return "结果「嗤」地一声，在$n身上划出一道伤口！\n";
			if( damage < 200 ) return "结果「嗤」地一声，在$n身上划出一道血淋淋的伤口！\n";
			if( damage < 320 ) return "结果「嗤」地一声，在$n身上划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
			return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深可见骨的可怕伤口！！\n";
		case "刺伤":
			if( damage < 10 ) return "结果只是轻轻地刺破$n的皮肉。\n";
			if( damage < 50 ) return "结果在$n$l刺出一个创口。\n";
			if( damage < 100 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
			if( damage < 200 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
			if( damage < 320 ) return "结果「噗嗤」地一声，$w刺进了$n的$l，殷红的鲜血随即喷了出来！\n";
			return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
		case "瘀伤":
			if( damage < 20 ) return "结果只是轻轻地碰到$n，比拍苍蝇稍微重了点。\n";
			if( damage < 40 ) return "结果在$n的$l造成一处瘀青。\n";
			if( damage < 80 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
			if( damage < 100 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
			if( damage < 170 ) return "结果「砰」地一声，$n退了两步！\n";
			if( damage < 240 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
			if( damage < 320 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			if( damage < 450 ) return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
			return "只听见$n一声惨叫，整个身体象断了线的风筝一样飞了出去！！\n";
		case "内伤":
			if( damage < 20 ) return "结果只是把$n打得退了半步，毫发无损。\n";
			if( damage < 60 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
			if( damage < 100 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
			if( damage < 170 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
			if( damage < 240 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
			if( damage < 320 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			if( damage < 450 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
			return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		case "震伤":                
			if( damage < 100 ) return "结果$n受到$N的劲力一震，闷哼一声。\n";
			if( damage < 150 ) return "结果$n被$N以劲力一震，「嘿」地一声退了两步。\n";
			if( damage < 230 ) return "结果$n被$N以劲力一震，胸口有如受到一记重锤，连退了五六步！\n";
			if( damage < 340 ) return "结果$N的劲力一下震得$n连退了好几步，差一点摔倒！\n";
			if( damage < 450 ) return "结果$n被$N的劲力震得全身气血倒流，口中鲜血狂喷而出！\n";
			return "结果$n被$N的劲力震得眼前一黑，内脏碎裂，身子凭空飞了出去！！\n";
		case "拉伤":
			if( damage < 15 ) return "结果只是轻轻地划过了$n的皮肤。\n";
			if( damage < 50 ) return "结果在$n的$l抽出一道细长的血印。\n";
			if( damage < 150 ) return "结果「啪」地一声$w将$n的$l皮肤扯开，形成一道尺许长的伤口！\n";
			if( damage < 250 ) return "只听$n「啊」地一声吐出一口鲜血，原来$p$l内的骨头已经被$w的劲力抽裂！\n";
			if( damage < 350 ) return "结果随着「咔」地一声，$w已将$n$l处的骨头硬生生地抽断，断骨从肉里冒了出来！\n";
			return "结果$n一声惨嚎，$w已从$p$l处撕下了一大片血淋淋的皮肉，鲜血溅得满地！！\n";
		case "砸伤":
		case "挫伤":
			if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
			if( damage < 80 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
			if( damage < 160 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
			if( damage < 320 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
			if( damage < 450 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
			return "结果$w一下打在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
		case "抓伤":
			if( damage < 20 ) return "结果只是在$n$l处轻轻刮过，没有什么伤害。\n";
			if( damage < 40 ) return "结果$n皱了皱眉，$p的$l已经被拉出了一道浅浅的血痕。\n";
			if( damage < 80 ) return "结果拉下来$n$l的一点皮肉，疼得$p「哇哇」怪叫了起来！\n";
			if( damage < 120 ) return "结果「唰」地一声，$n的$l上顿时被抓出五道血痕，鲜血流了出来！\n";
			if( damage < 220 ) return "结果$n疼得大叫一声，$p$l上被抓出了几道深深的血沟，鲜血直流！\n";
			if( damage < 330 ) return "结果只听见$n一声惨嚎，$N的手爪已在$p的$l处刺出了五个血肉模糊的窟窿！\n";
			if( damage < 440 ) return "结果「啊」地一声惨叫，$n身上$l处被$N抓下了一大片皮肉，鲜血横飞满地！！\n";
			return "结果$n一声凄惨的嘶叫，$l处被连皮带肉扯下一大块，露出了白森森的骨头！！\n";
        case "摔伤":
			if( damage < 20 ) return "结果$n脚下不稳，在地上擦破了点儿皮。\n";
			if( damage < 80 ) return "结果「啪」地一声，$n在地上摔了个屁礅。\n";
			if( damage < 160 ) return "结果$n一不小心，被$N重重摔倒在地！\n";
			if( damage < 300 ) return "结果$n被一下摔倒在地，「噗地」一声喷出了一大口鲜血！\n";
            if( damage < 420 ) return "结果被$N这一下摔在地上，$l处的骨头「卡嚓」一声断了！\n";
			return "结果只听见$n一声惨嚎，被$N摔得血肉横飞，惨不忍睹！！\n";
        case "跌伤":
                if( damage < 100 ) return "结果$p就地一滚，没怎么伤着。\n";
                else if( damage < 200 ) return "结果「吧叽」一声，$p被摔了个屁墩。\n";
                else if( damage < 400 ) return "结果$p的$l着实地被摔了一下！\n";
                else if( damage < 800 ) return "结果$p的$l砸在地上，被摔得青紫！\n";
                else if( damage < 1600 ) return "结果在$p的$l立时肿起一大块，鲜血里透着青紫！\n";
                else return "结果$p的$l被摔得皮开肉绽，骨头从肉里戳出来！！\n";
                break;
        case "咬伤":
                if( damage < 100 ) return "结果只是轻轻地蹭了一下$p的皮肉。\n";
                else if( damage < 200 ) return "结果在$p$l咬出一排牙印。\n";
                else if( damage < 400 ) return "结果$p被咬下一片肉来！\n";
                else if( damage < 800 ) return "结果$p连皮带肉被咬下一大块！\n";
                else if( damage < 1600 ) return "结果在$p的身上咬下来血肉模糊的一大块$l肉！\n";
                else return "结果只听见$n一声惨嚎，$p的$l上的肉被一口咬掉，露出骨头！！\n";
                break;
        case "瘀伤":
        case "淤伤":
        case "挫伤":
                if( damage < 100 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
                else if( damage < 200 ) return "结果在$p的$l造成一处瘀青。\n";
                else if( damage < 400 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
                else if( damage < 800 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
                else if( damage < 1200 ) return "结果「砰」地一声，$n退了两步！\n";
                else if( damage < 1600 ) return "结果这一下「砰」地一声击得$n连退了好几步，差一点摔倒！\n";
                else if( damage < 2400 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！！\n";
                else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
                break;
        case "内伤":
                if( damage < 100 ) return "结果只是把$n打得退了半步，毫发无损。\n";
                else if( damage < 200 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
                else if( damage < 400 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
                else if( damage < 800 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
                else if( damage < 1200 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
                else if( damage < 1600 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
                else if( damage < 2400 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！！\n";
                else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
                break;
	case "震伤":
		if( damage < 100 ) return "结果$p疑惑地看了$P一眼，似乎没有感觉到什么痛处。\n";
		else if( damage < 200 ) return "结果$p身子一晃，立足不定，差点儿就要摔倒。\n";
		else if( damage < 400 ) return "结果$p立足不定，向后接连摔了两个筋斗，哇的一声，喷出一口鲜血！\n";
		else if( damage < 800 ) return "结果$p哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥！\n";
		else if( damage < 1600 ) return "结果$p身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷！\n";
		else if( damage < 2400 ) return "结果只听一声巨响，$p口中鲜血狂喷，全身骨骼碎裂！！\n";
		else return "结果只听一声巨响，$p全身骨骼碎裂，竟似被这排山倒海般的一击将身子打成了两截！！\n";
		break;
        case "擦伤":
        case "抓伤":
                if( damage < 100 ) return "结果$p只被轻轻地蹭破了一点油皮。\n";
                else if( damage < 200 ) return "结果$p的$l上被划出一道细长的血痕。\n";
                else if( damage < 400 ) return "结果「唰」地在$p的$l上蹭掉一大片皮肉！\n";
                else if( damage < 800 ) return "结果「唰」地一声擦出一道血淋淋的伤口！\n";
                else if( damage < 1600 ) return "结果「唰」地一声$p的$l上被撕下血淋淋的一片肉！\n";
                else return "结果只听见$n一声惨嚎，$p$l的皮肉尽裂，露出白森森的骨头！\n";
                break;
        case "割伤":
        case "劈伤":
        case "砍伤":
                if( damage < 100 ) return "结果只是轻轻地划破$p的皮肉。\n";
                else if( damage < 200 ) return "结果在$p$l划出一道细长的血痕。\n";
                else if( damage < 400 ) return "结果「嗤」地一声砍出一道伤口！\n";
                else if( damage < 800 ) return "结果「嗤」地一声劈出一道血淋淋的伤口！\n";
                else if( damage < 1600 ) return "结果「嗤」地一声劈出一道又长又深的伤口，溅得$N满脸鲜血！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p$l砍出一道深及见骨的可怕伤口！！\n";
                break;
        case "刺伤":
                if( damage < 100 ) return "结果只是轻轻地刺破$p的皮肉。\n";
                else if( damage < 200 ) return "结果在$p$l刺出一个创口。\n";
                else if( damage < 400 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
                else if( damage < 800 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
                else if( damage < 1600 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
                break;
        case "砸伤":
		if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
		if( damage < 60 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
		if( damage < 120 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
		if( damage < 240 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
		if( damage < 380 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
		return "只见$w重重地撞击在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
                break;
        case "鞭伤":
                if( damage < 100 ) return "结果只是在$p$l上擦了一道白印。\n";
                else if( damage < 200 ) return "结果在$p的$l上抽出一道血痕。\n";
                else if( damage < 400 ) return "结果「啪」地一声$p被抽了一道伤口！\n";
                else if( damage < 800 ) return "结果$p的$l上被抽了一道血淋淋的创口！\n";
                else if( damage < 1600 ) return "结果「啪」地一声$p被$N的$w抽了一道从头到脚的血印！\n";
                else return "结果只听见「咔嚓」一声，$p的$l的骨头被抽断，$w被染得血红！！\n";
                break;
	case "灼伤":
	case "烧伤":
		if( damage < 100 ) return "结果只是把$p的$l烫了一下。\n";
		else if( damage < 200 ) return "结果$p的$l被$w灼炙得起了个小疱。\n";
		else if( damage < 400 ) return "结果$p的$l被$w烧得红肿疼痛，痛得不住冒汗咬牙！\n";
		else if( damage < 800 ) return "结果「嗤」一声轻响，$p祗觉$l上一片热痛，已被$w烧成了暗红色，犹如焦炭！\n";
		else if( damage < 1600 ) return "结果「嗤嗤」一阵声响过去，$n神色痛楚难当，$l被$w烧得一片焦黑，青烟直冒！\n";
		else return "结果只听见$n长声惨呼，在地上不住打滚，$l已被$w烧得皮肉尽烂，焦臭四溢！！\n";
		break;
	case "冻伤":
		if( damage < 100 ) return "结果$p祗是觉得$l有些冷飕飕地，还挺凉快的。\n";
		else if( damage < 200 ) return "结果$p的$l被冻得有些麻木。\n";
		else if( damage < 400 ) return "结果$p机伶伶地打了个寒颤！\n";
		else if( damage < 800 ) return "结果$p脸色一变，神情有些僵硬，身子也冷得瑟瑟发抖！\n";
		else if( damage < 1600 ) return "结果$p身子打颤，脸色苍白，嘴唇冻得发紫，牙关格格直响！\n";
		else return "结果祗听见$n声音一哑，脸上惨白得没半分血色，颤抖不休，浑身血液似乎都结成了冰！！\n";
		default:
			if( !type ) type = "伤害";
			if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
			else if( damage < 20 ) str = "结果造成轻微的";
			else if( damage < 30 ) str = "结果造成一处";
			else if( damage < 50 ) str = "结果造成一处严重";
			else if( damage < 80 ) str = "结果造成颇为严重的";
			else if( damage < 120 ) str = "结果造成相当严重的";
			else if( damage < 170 ) str = "结果造成十分严重的";
			else if( damage < 230 ) str = "结果造成极其严重的";
			else str =  "结果造成非常可怕的严重";
			return str + type + "！\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
	if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
					 return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
				     return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}




varargs void report_status(object ob, int effective)
{
// 比武现场转播 start
//	player=users();
// 比武现场转播 end
	if( effective ) 
	{//	if(!ob->query_temp("tjj_jie"))
		message_vision( "( $N" + eff_status_msg(
		(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
// 比武现场转播 start
//		if ((string)environment(ob)->query("short") == "擂台")
//		for (userno=0; userno<sizeof(player); userno++)
//		    if ((player[userno])->query_temp("view_leitai"))
//			tell_object(player[userno], "( " + ob->name() + eff_status_msg(
//			(int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
//			+ " )\n");
// 比武现场转播 end
	}
	else
	{//	if(!ob->query_temp("tjj_jie"))
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
			+ " )\n", ob);
// 比武现场转播 start
//		if ((string)environment(ob)->query("short") == "擂台")
//		for (userno=0; userno<sizeof(player); userno++)
//		    if ((player[userno])->query_temp("view_leitai"))
//			tell_object(player[userno], "( " + ob->name() + status_msg(
//			(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
//			+ " )\n");
// 比武现场转播 end
	}
}
void fight_reward(object winner, object loser)
{
        object owner;

        if(owner=winner->query("possessed"))  winner = owner;
        winner->win_enemy(loser);
}
void fight_penalty(object winner, object loser)
{
        object owner;

        if(owner=loser->query("possessed"))  loser = owner;
        loser->lose_enemy(winner);
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power,attack,def,exp;
	int stra,dodgea,dexa;
	if( !living(ob) ) return 0;
	attack=ob->query_temp("apply/attack");
if (ob->query_temp("apply/strength") > 800)
ob->set_temp("apply/strength",800);
if (ob->query_temp("apply/intelligence") > 800)
ob->set_temp("apply/intelligence",800);
if (ob->query_temp("apply/constitution") > 800)
ob->set_temp("apply/constitution",800);
if (ob->query_temp("apply/dexerity") > 800)
ob->set_temp("apply/dexerity",800);
if (ob->query_temp("apply/attack") > 2000)
ob->set_temp("apply/attack",2000);
if (ob->query_temp("apply/defense") > 2000)
ob->set_temp("apply/defense",2000);
if (ob->query_temp("apply/damage") >8000)
ob->set_temp("apply/damage",8000);
if (ob->query_temp("apply/armor") > 8500)
ob->set_temp("apply/armor",8500);
if (ob->query_temp("apply/dodge") > 1200)
ob->set_temp("apply/dodge",1200);
if (ob->query_temp("fight/dodge") > 1000)
ob->set_temp("fight/dodge",1000);
	if (attack>200) attack = 200;
                        def = ob->query_temp("apply/defense");
			if (def>200) def = 200;
	level = ob->query_skill(skill)/2;
dodgea=ob->query_temp("fight/dodge");
if (dodgea> 200) dodgea=200;
exp=(int)ob->query("combat_exp");
if ((int)ob->query("combat_exp")> 120000000) exp=120000000;

	if( !level ) return exp / 2;
    if (level > 500) level = 500;

dexa=ob->query_dex();
if (dexa > 200) dexa=200;
stra=ob->query_str() + ob->query_temp("str")/2;
if (stra > 200) stra=200;

	switch(usage) 
	{
		case SKILL_USAGE_ATTACK:
			level += attack;
			break;
		case SKILL_USAGE_DEFENSE:
			//level = 1;
			level += def;
			if (ob->is_fighting() && skill="dodge" )
			level = level + dodgea;
			else 
			
			break;
	}
/*	if( !level ) return exp / 2;
    if (level > 500) level = 500;
dexa=ob->query_dex();
if (dexa > 200) dexa=200;
stra=ob->query_str() + ob->query_temp("str")/2;
if (stra > 200) stra=200;
*/
//if (level > 100) level=100;
if (userp(ob) && (int)ob->query("combat_exp")> 8000000)
		power = (level / 8)*level*level;
else
		power = (level / 5)*level*level;

	if (usage == SKILL_USAGE_ATTACK)
		return (power + exp) / 30 * dexa;
	return (power + exp)
		/30 * (skill == "dodge"?dexa:stra);
	if (usage == SKILL_USAGE_ATTACK)
		return (power + exp) / 30 * stra;
	else
		return (power + exp) / 30 * stra;

  }

// do_attack()
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
varargs int do_attack(object me, object victim, object weapon, int attack_type, string attack_msg, string damtype)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result,mweaponn,vweaponn;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp,n,cstra,ccona,dexa;
	int damage, damage_bonus, defense_factor,damages,wounds,attack;
	int wounded = 0;
	int flag = 0;
	
	object vweapon,nweapon;
if (victim->query_temp("weapon"))
{
        vweapon = victim->query_temp("weapon");
}
// 比武现场转播 start
//	player=users();
// 比武现场转播 end
	if (me->query_skill_mapped("parry") == "douzhuan-xingyi"
	&& ((!weapon && !vweapon) || ((weapon && vweapon)
	&& weapon->query("skill_type") == vweapon->query("skill_type"))))
		flag = 1;

	if (!living(me)) return 0;
	if (!me) return 0;
        if (!victim) return 0;
if (!victim->query_condition("killer") && environment(me)->query("no_fight")) return 0;
if (!victim->query_condition("killer") && environment(victim)->query("no_fight")) return 0;
	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
// (0) Choose skills.
	if (flag) {
		foo = me;
		me = victim;
	}
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);

	if ( sizeof(prepare) == 0) attack_skill = "unarmed";
	if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
	if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
	if ( weapon ) attack_skill = weapon->query("skill_type");
	if (flag && !me->query_skill_mapped(attack_skill)) {
		me = foo;
		flag = 0;
		prepare = me->query_skill_prepare();
		if (!prepare) prepare = ([]);
		if ( sizeof(prepare) == 0) attack_skill = "unarmed";
		if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
		if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
		if ( weapon ) attack_skill = weapon->query("skill_type");
	}
	// (1) Find out what action the offenser will take.
		me->prepare_skill("sword");	
		me->prepare_skill("blade");	
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();
		action = me->query("actions");
		if( !mapp(action) ) {
me->map_skill(attack_skill);
		me->reset_action();
			CHANNEL_D->do_channel( this_object(), "sys",
				sprintf("%s(%s): 武功为零 系统自动处理 = %O",
					me->name(1), me->query("id"), me->query("actions", 1)));
        //return combat_action[random(sizeof(combat_action))];

//        return combat_action[random(sizeof(combat_action))];
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n" + "紧跟着"+action["action"] + "!\n"; 
       if(stringp(attack_msg)) result = "\n" + attack_msg + "\n";
	// (2) Prepare AP, DP for checking if hit.
        if (martial_skill = me->query_skill_mapped(attack_skill))
                limb = SKILL_D(martial_skill)->query_attack_limb(me, victim);

        if (! limb)
        {
                limbs = victim->query("limbs");
                if (! arrayp(limbs))
                {
                        limbs = ({ "身体" });
                        victim->set("limbs", limbs);
                }
                limb = limbs[random(sizeof(limbs))];

        }



if (weapon)
{
mweaponn=weapon->query("skill_type");
}
if (vweapon)
{
vweaponn=vweapon->query("skill_type");
}
if (mweaponn=="" || !mweaponn) 
{
mweaponn="none";
}
if (vweaponn=="" || !vweaponn)
{
 vweaponn="none";
}


	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	
	        if (member_array(limb, danger_limbs) != -1) /* 向危险部位发动进攻  */
                ap -= ap / 10;                      /* 击中的可能性减小10% */

	if( ap < 1) ap = 1;
	if (userp(me) && intp(action["dodge"]))
	me->set_temp("fight/dodge", action["dodge"]);

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	if( victim->is_busy() ) dp /= 3;
	// (3) Fight!
//武器相克
if (mweaponn=="sword" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="throwing") ) dp=dp/2;
if (mweaponn=="blade" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="sword") ) dp=dp/2;
if (mweaponn=="dagger" && (vweaponn=="none" || vweaponn=="blade" || vweaponn=="sword"  || vweaponn=="throwing" || vweaponn=="whip") ) dp=dp/2;
if (mweaponn=="axe" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="blade") ) dp=dp/2;
if (mweaponn=="hammer" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="sword") ) dp=dp/2;
if (mweaponn=="club" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="hammer") ) dp=dp/2;
if (mweaponn=="staff" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="axe") ) dp=dp/2;
if (mweaponn=="none" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="axe") ) dp=dp/2;
if (mweaponn=="throwing" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="hammer") ) dp=dp/2;
if (mweaponn=="whip" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="none") ) dp=dp/2;

	if( random(ap + dp) < dp )
	{ // Does the victim dodge this hit?
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
		damage = RESULT_DODGE;
	} 
	else {
	//	(4) Check if the victim can parry this attack.
	    pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
		if( victim->query_temp("weapon") ) 
		{
			if( !weapon ) pp *= 2;
		} else 
		{
			if( weapon ) pp /= 2;
		}

		if( victim->is_busy() ) pp /= 3;
		if( pp < 1 ) pp = 1;

		if( random(ap + pp)< pp ) 
		{	parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.
			result += SKILL_D("parry")->query_parry_msg(weapon);
			damage = RESULT_PARRY;
		} else 
		{//	(5) We hit the victim and the victim failed to parry
			attack = 1;
			damage = me->query_temp("apply/damage");
if (me->query_temp("apply/strength") > 800)
me->set_temp("apply/strength",800);
if (me->query_temp("apply/intelligence") > 800)
me->set_temp("apply/intelligence",800);
if (me->query_temp("apply/constitution") > 800)
me->set_temp("apply/constitution",800);
if (me->query_temp("apply/dexerity") > 800)
me->set_temp("apply/dexerity",800);
if (me->query_temp("apply/attack") > 2000)
me->set_temp("apply/attack", 2000);
if (me->query_temp("apply/defense") >  2000)
me->set_temp("apply/defense", 2000);
if (me->query_temp("apply/damage") >  8000)
me->set_temp("apply/damage", 8000);
if (me->query_temp("apply/armor") >  8500)
me->set_temp("apply/armor", 8500);
if (me->query_temp("apply/dodge") > 1200)
me->set_temp("apply/dodge",1200);
if (me->query_temp("fight/dodge") > 1000)
me->set_temp("fight/dodge",1000);
			if ( damage > 1888 ) damage = 1888;
			damage = (4*damage + random(damage)) / 5;
		//	if( action["damage"] )
		//	damage += action["damage"] * damage / 500;//暂时关闭
		    if (weapon)
			damage += me->query_skill(attack_skill) * damage / 500;
cstra=me->query_str();
if ( me->query_skill("jiuyin-zhengong") && cstra > 500) cstra =500;
else if (cstra > 600) cstra =600;
			damage_bonus = cstra * 2;
			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
				if( force_skill = me->query_skill_mapped("force") ) {
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if( intp(foo) ) damage_bonus += foo;
				}
			}

            damage_bonus += me->query_skill(attack_skill) * damage_bonus / 1000;
			if( weapon ) damage_bonus -= damage_bonus/3 ; 
			if( martial_skill = me->query_skill_mapped(attack_skill) ) {
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			// Let weapon or monster have their special damage.
			if( weapon ) 
			{
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			} else 
			{

			if ( objectp(nweapon = me->query_temp("armor/hands")) && !weapon) {
 //tell_object(me, HIW "手套"+nweapon->query("name")+"测试效果\n" NOR);
	foo =  nweapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
else
{
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
}
			}

			if( martial_skill = victim->query_skill_mapped("dodge") ) {
				foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if( martial_skill = victim->query_skill_mapped("parry") ) {
				foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
			    if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

                if( martial_skill = victim->query_skill_mapped("force") ) {
				foo = SKILL_D(martial_skill)->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
/*
			if (foo = victim->query_temp("armor/cloth")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/armor")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/boots")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/head")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			if (foo = victim->query_temp("armor/shield")) {
				foo = foo->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

*/
			if (foo = victim->query_temp("armor/cloth")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/armor")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if (foo = victim->query_temp("armor/boots")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}

			if (foo = victim->query_temp("armor/head")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}
			if (foo = victim->query_temp("armor/shield")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}

			if (foo = victim->query_temp("armor/hands")  && weapon ) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}
			
			if (foo = victim->query_temp("armor/neck")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}			

			if (foo = victim->query_temp("armor/surcoat")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}			

			if (foo = victim->query_temp("armor/waist")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}
			
			if (foo = victim->query_temp("armor/wrists")) {
				foo = foo->ob_hit(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus = foo;
			}			
			if( damage_bonus > 0 )
			damage += (4*damage_bonus + random(damage_bonus))/5;
			if( damage < 0 ) damage = 0;
			// Let combat exp take effect
ccona=victim->query_con();
if ( me->query_skill("jiuyin-zhengong") && ccona > 500) ccona =500;
else if (ccona > 600) ccona=600;
			damage = damage * 20 / ( ccona + 16);
//武器相克系统
if (victim->query("race")!="野兽")
{
if (mweaponn=="sword" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="throwing") ) damage=damage*2;
if (mweaponn=="blade" && (vweaponn=="none" || vweaponn=="whip" || vweaponn=="sword") ) damage=damage*2;
if (mweaponn=="dagger" && (vweaponn=="none" || vweaponn=="blade" || vweaponn=="sword"  || vweaponn=="throwing" || vweaponn=="whip") ) damage=damage*2;
if (mweaponn=="axe" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="blade") ) damage=damage*2;
if (mweaponn=="hammer" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="sword") ) damage=damage*2;
if (mweaponn=="club" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="hammer") ) damage=damage*2;
if (mweaponn=="staff" && (vweaponn=="sword" || vweaponn=="blade" || vweaponn=="axe") ) damage=damage*2;
if (mweaponn=="none" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="axe") ) damage=damage*2;
if (mweaponn=="throwing" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="hammer") ) damage=damage*2;
if (mweaponn=="whip" && (vweaponn=="club" || vweaponn=="staff" || vweaponn=="none") ) damage=damage*2;
}	

                        // 根据攻击的部位影响伤害
                        if (! undefinedp(limb_damage[limb]))
                                damage = (damage * limb_damage[limb] / 100);


			damage = victim->receive_damage("qi", damage, me);
			if( random(damage) > (int)victim->query_temp("apply/armor") && ( (me->is_killing(victim->query("id"))) 
				&& ((!weapon) && !random(4) || weapon && !random(2) )
			    || ((!weapon) && !random(7) || weapon && !random(4) ) )  )
			{
				// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("qi",damage - (int)victim->query_temp("apply/armor"), me);
				wounded = 1;
			}
		result += damage_msg(damage, action["damage_type"]);
		damages = damage;
		wounds= damage - (int)victim->query_temp("apply/armor");
if (damages <0) damages=0;
if (wounds <0) wounds=0;



		if (userp(me) && me->query("env/combat_show"))
                        tell_object(me, HIW "( 你对" +
                                        victim->query("name") + HIW "造成" +
                                        damages + "点伤害，" +
                                        wounds + "点创伤。)\n" NOR);
                if (userp(victim) && victim->query("env/combat_show"))
                        tell_object(victim, HIG "( 你受到" +
                                        me->query("name") + HIG + damages + "点伤害，" +
                                        wounds + "点创伤。)\n" NOR);		

		}
	} 
	
	result = replace_string( result, "$l", limb );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "手指" );

	message_combatd(result, me, victim );


 if (attack == 1)
                {
                        int pers;

                        switch(limb)
                        {
                        // 头、颈受伤会伤一些神。
                        case "头部":
                        case "颈部":
                                damage /= 4;
                                if (damage < 1)
                                        damage = 1;
                                if (damage > 8000)
                                        damage = 8000;
                                victim->receive_damage("jing", damage, me );
                                pers = victim->query("jing")*100/victim->query("max_jing");
                                if (pers <= 30)
                                        tell_object(victim, head_damage_me_msg[2]);
                                else if (pers <= 70)
                                        tell_object(victim, head_damage_me_msg[1]);
                                else
                                        tell_object(victim, head_damage_me_msg[0]);
                                break;
                        // 击中这些部位真气会受到振荡。
                        case "胸口":
                        case "后心":
                        case "小腹":
                                if (victim->query("max_neili") && victim->query("neili"))
                                {
                                        string report_limb_msg;

                                        damage /= 4;
                                        if (damage < 1)
                                                damage = 1;
                                        if (damage > 10000)
                                                damage = 10000;
                                        if (victim->query("neili") <= damage)
                                                victim->set("neili", 0);
                                        else
                                                victim->add("neili", -damage);
                                        if (damage <= 500)
                                                report_limb_msg = body_damage_me_msg[0];
                                        else if (damage <= 1000)
                                                report_limb_msg = body_damage_me_msg[1];
                                        else
                                                report_limb_msg = body_damage_me_msg[2];
                                        report_limb_msg = replace_string(report_limb_msg, "$l", limb);
                                        tell_object(victim, report_limb_msg);
                                }
                                break;
                        }
                }

	if ( wizardp(me) && me->query("env/combat") )
	{
	if( damage > 0 )
		{
			// tell_object(me, HIG "( 武器类别" +
                        //                mweaponn + HIG + vweaponn + "\n" NOR);		

			
			tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d，伤害力：%d\n" NOR,
				ap/100, dp/100, pp/100, damage));

			tell_object(victim, sprintf( GRN "AP：%d，DP：%d，PP：%d，伤害力：%d\n" NOR,
				ap/100, dp/100, pp/100, damage));
		}
			else
			{tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d\n" NOR,
				ap/100, dp/100, pp/100));
			tell_object(victim, sprintf( GRN "AP：%d，DP：%d，PP：%d\n" NOR,
				ap/100, dp/100, pp/100));
			}
	}
	
	if( damage > 0 ) {
		report_status(victim, wounded);
		if( victim->is_busy() ) victim->interrupt_me(me);
		if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) &&
		victim->query("qi")*2 <= victim->query("max_qi")) 
		{
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			fight_reward(me, victim);
			fight_penalty(me, victim);		
			if (me->query("race") == "人类") {
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
			} else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, victim);			
/*// 比武现场转播 start
			result = winner_msg[random(sizeof(winner_msg))];
			result = replace_string(result,  "$P", me->name());
			result = replace_string(result,  "$N", me->name());
			result = replace_string(result,  "$n", victim->name());
			result = replace_string(result,  "$p", victim->name());
			if ((string)environment(me)->query("short") == "擂台")
			for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);
// 比武现场转播 end*/
		}
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);


}

//	fight()
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
void fight(object me, object victim)
{
	object ob;
	string result;
// 比武现场转播 start
//	player=users();
// 比武现场转播 end
	if( !living(me) ) return;
	
	if( !victim ) return;
	if( !me ) return;
	
        if (userp(me) && environment(me)->query("no_fight")) return;
        if( me->query_temp("combat_yield") && userp(me) && userp(victim)
                ) return;
	// If victim is busy or unconcious, always take the chance to make an attack.


			 if ((random(4)==0 || wizardp(me)) && userp(me))
{
switch (random(2))
	{
		case 0:
		if ( (me->query("max_qi") > me->query("eff_qi") || me->query("eff_qi") > me->query("qi"))
		&& random(2)==0 && (int)me->query_temp("ana_t/reqi")>=1  && (int)me->query_skill("force",1)>=1 ) {
			message_vision(HIR"只见$N的真气如白雾般笼罩全身，所受的伤似乎好了很多！\n"NOR, me);
			me->add("eff_qi",  10+(int)me->query_temp("ana_t/reqi")*me->query_skill("force")/100);
			if (me->query("eff_qi") > me->query("max_qi"))
				me->set("eff_qi", me->query("max_qi"));
			me->add("qi", 10+(int)me->query_temp("ana_t/reqi")*me->query_skill("force")/150);
			if (me->query("qi") > me->query("eff_qi"))
				me->set("qi", me->query("eff_qi"));
		}
		break;
		case 1:
		if ( (me->query("max_jing") > me->query("eff_jing") || me->query("eff_jing") > me->query("jing"))
		&& random(2)==0 && (int)me->query_temp("ana_t/rejing") >=1  && (int)me->query_skill("force",1)>=1 ) {
			message_vision(HIY"只见$N的双眼开合之间金光闪现，精神顿时大振！\n"NOR, me);
			me->add("eff_jing",  10+(int)me->query_temp("ana_t/rejing")*me->query_skill("force")/100);
			if (me->query("eff_jing") > me->query("max_jing"))
				me->set("eff_jing", me->query("max_jing"));
			me->add("jing", 10+(int)me->query_temp("ana_t/rejing")*me->query_skill("force")/150);
			if (me->query("jing") > me->query("eff_jing"))
				me->set("jing", me->query("eff_jing"));
		}
		break;
	}
}	
		

	if( victim->is_busy() || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian")
                || (me->query("double_attack") && !objectp(me->query_temp("weapon"))) 
                || me->query_temp("double_attack"))
		{
		if (me->query("double_attack") && sizeof(me->query_skill_prepare()) < 2)
			message_vision(CYN"\n$N双手分使，灵活异常，好象变成了两个人似的！\n"NOR,me);
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		   me->delete_temp("action_flag");
	     	}

	// Else, see if we are brave enough to make an aggressive action.
		} else if( me->query_temp("guarding")||
					random( (int)me->query_dex()  ) > random( (int)victim->query_dex() )) 
		{	me->set_temp("guarding", 0);
			if( !victim->is_fighting(me) ) victim->fight_ob(me);  
			do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);


		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian")
                || (me->query("double_attack") && !objectp(me->query_temp("weapon"))) 
                || me->query_temp("double_attack"))
		{
		if (me->query("double_attack") && sizeof(me->query_skill_prepare()) < 2)
			message_vision(CYN"\n$N双手分使，灵活异常，好象变成了两个人似的！\n"NOR,me);
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		   me->delete_temp("action_flag");
	     	}

	// Else, we just start guarding.
	} else 
	{
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
// 比武现场转播 start
/*		result = guard_msg[random(sizeof(guard_msg))];
		result = replace_string(result,  "$P", me->name());
		result = replace_string(result,  "$N", me->name());
		result = replace_string(result,  "$n", victim->name());
		result = replace_string(result,  "$p", victim->name());
		if ((string)environment(me)->query("short") == "擂台")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);*/
// 比武现场转播 end
		return;
	}
	return;
}

//	auto_fight()
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;
	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);
	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

	if( !userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 ) return;

	if( shen > (int)me->query("score") 
	&&	!wizardp(obj) ) {
		message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
			+ "看你实在很不顺眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)
			+ "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	if(	me->query_temp("owner") == obj->query("id")	// be trained
	||	obj->query_temp("owner") == me->query("id") 	// be trained
	)	return;

	// We found our hatred! Charge!
	if (me->query("race") == "人类") {
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	} else message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
        if (!userp(me))
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
// 比武现场转播 start
//	player=users();
// 比武现场转播 end
	switch(event) {
		case "dead":
message_vision( NOR"\n$N「啪」地一声倒在地上，嘴角溢出几丝鲜血，痛苦的挣扎了几下就死了。\n\n" NOR, ob);
// 比武现场转播 start
//			if ((string)environment(ob)->query("short") == "擂台")
//			for (userno=0; userno<sizeof(player); userno++)
//			    if ((player[userno])->query_temp("view_leitai"))
//				tell_object(player[userno], "\n"+ob->name()+"「啪」地一声倒在地上，嘴角溢出几丝鲜血，痛苦的挣扎了几下就死了。\n");
// 比武现场转播 end
			break;
		case "unconcious":
			message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
// 比武现场转播 start
//			if ((string)environment(ob)->query("short") == "擂台")
//			for (userno=0; userno<sizeof(player); userno++)
//			    if ((player[userno])->query_temp("view_leitai"))
//				tell_object(player[userno], "\n"+ob->name()+"脚下一个不稳，跌在地上一动也不动了。\n\n");
// 比武现场转播 end
			break;
		case "revive":
		        if(ob->query("blind") || ob->query("race") != "人类")
			     message_vision("\n$N身子一颤，扭动了几下，清醒了过来。\n\n", ob);
			else if(ob->query("mute"))
			     message_vision("\n$N慢慢清醒了过来，睁开眼睛站起来摇了摇头。\n\n", ob);
			else message_vision("\n$N身子动了动，口中呻吟了几声，清醒过来。\n\n", ob);
// 比武现场转播 start
//			if ((string)environment(ob)->query("short") == "擂台")
//			for (userno=0; userno<sizeof(player); userno++)
//			    if ((player[userno])->query_temp("view_leitai"))
//				tell_object(player[userno], "\n"+ob->name()+"慢慢睁开眼睛，清醒了过来。\n\n");
// 比武现场转播 end
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	int gain,gain1;
	int bls,zhenfa=0;
	object env;
	string vmark;
	string temp;
	string str,killerid,info,infot;
	string msg="莫名其妙的死了。";
	mapping quest, actions;
	int exp, pot, score, bonus,factor;
	int student_num;
	// Call the mudlib killer apply.
	killer->killed_enemy(victim);
	env = environment(victim);

	if(objectp(env))
	if ( env->query("no_death_penalty")) 
	{
	victim->set_temp("no_death_penalty",1);
	return;
	}
if (env && environment(victim)->query("no_fight")
&& killer && victim->query_condition("killer"))
{
log_file("log", "在NF的ROOM发生通辑死亡：" + base_name(environment(victim)) +"\n", 1);
log_file("log", "造成人物" + killer->query("id") + killer->query("name")+"\n", 1);
log_file("log", "死亡人物" + victim->query("id") + victim->query("name")+"\n", 1);
}
if (env && environment(victim)->query("no_fight")
&& killer && !victim->query_condition("killer"))
{
log_file("log", "在NF的ROOM发生特殊死亡：" + base_name(environment(victim)) +"\n", 1);
log_file("log", "造成人物" + killer->query("id") + killer->query("name")+"\n", 1);
log_file("log", "死亡人物" + victim->query("id") + victim->query("name")+"\n", 1);
}

if (killer)
{
killer->remove_all_enemy(victim);
killer->remove_all_killer(victim);

if (killer->query("id")=="xun bu")
{
killer->remove_all_enemy();
killer->remove_all_killer();
}
}

if (mapp(victim->query("killer_reward")) && userp(killer))
{
   BG_D->killer_rewardboss(killer, victim, victim->query("killer_reward"));
//log_file("log", "开始奖励：" + base_name(environment(victim)) +"\n", 1);
}

	if( userp(killer) || userp(victim) ) 
	{
 FAMILY_D->family_kill(killer, victim);
}

	if( userp(victim)) 
	{
/*		if (userp(killer) && killer->query_condition("killer"))
{
        	killer->add("qiushi/times",1);
		killer->add("qiushi/totaltime",killer->query("qiushi/howlong"));
		killer->set("qiushi/inage",killer->query("mud_age"));
        	killer->set("startroom","/d/death/qiushi");
                killer->set("qiushi/howlong",180);
                killer->move("/d/death/qiushi");
		killer->apply_condition("killer", 800 +
			killer->query_condition("killer"));
		killer->apply_condition("tongji_poison", 800);

		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("通缉犯%s被关进了囚室。", killer->name(1), killer->name()));
}*/
		if ( victim->query_condition("killer") && userp(killer))
		zhenfa=1;
		else if(!victim->is_killing(killer->query("id")))
		{
		killer->add("PKS", 1);
		if (userp(killer))
{
//		killer->apply_condition("killer", 120 +
//			killer->query_condition("killer"));
					if (killer->query_temp("kill_other/"+victim->query("id"))) {
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s杀害了。", victim->name(1), killer->name()));
						killer->apply_condition("killer",
							800 + killer->query_condition("killer") * 3 / 2);
if ((int)victim->query("combat_exp") < (int)killer->query("combat_exp")/2)
                                                //killer->apply_condition("tongji_poison", 800);

                                                victim->apply_condition("nokill", 800);
					} else if (victim->query_temp("kill_other/"+killer->query("id")))
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s正当防卫杀死了。",
								victim->name(1), killer->name()));
					else {
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s失手把%s杀死了。",
								killer->name(), victim->name(1)));
						killer->apply_condition("killer",
							800 + killer->query_condition("killer"));
if ((int)victim->query("combat_exp") < (int)killer->query("combat_exp")/2)
                                                //killer->apply_condition("tongji_poison", 800);
					victim->apply_condition("nokill", 800);
					}
					killer->delete_temp("kill_other/"+victim->query("id"));
					victim->delete_temp("kill_other/"+killer->query("id"));
					killer->delete_temp("other_kill/"+victim->query("id"));
					victim->delete_temp("other_kill/"+killer->query("id"));

}
		}
if (killer->query("id")=="xun bu")
{
killer->remove_all_enemy();
killer->remove_all_killer();
}
victim->remove_all_enemy();
victim->remove_all_killer();
if (!victim->query_condition("killer"))
{
		victim->clear_condition();
}
	   // CHANNEL_D->do_channel(this_object(), "rumor",str);
if (killer->query("id")!=victim->query("id"))
{
		victim->add("shen", -(int)victim->query("shen") / 10);
		if (victim->query("combat_exp")>1200000)
{
		if (victim->query("max_neili")>1000)
		{
			victim->add("max_neili", -50);
		}
}
		if (victim->query("combat_exp")>500000 ||
		victim->query_condition("killer"))
{
		victim->clear_condition();
		victim->add("combat_exp", -(int)victim->query("combat_exp") / 200);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
		((int)victim->query("learned_points") - (int)victim->query("potential"))/5 );
		victim->skill_death_penalty();
}
		victim->delete("vendetta");
		if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
                victim->set("killbyname",killer->query("id"));
		victim->save();
}
		bls = 10;
		if(objectp(killer))
		{
			msg="被"+killer->name(1);
			actions = killer->query("actions");
			switch(actions["damage_type"]) {
			case "擦伤":
		    case "割伤":
				msg+="砍死了。";
				break;
			case "刺伤":
				msg+="刺死了。";
				break;
			case "瘀伤":
				msg+="击死了。";
				break;
			case "内伤":
				msg+="震死了。";
				break;
			default:
				msg+="杀死了。";
			}
		}
		if (zhenfa==1)
{
		victim->apply_condition("killer", 0);
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("通缉犯%s被%s就地正法了。", victim->name(1), killer->name()));

                if (victim->query("combat_exp") > 800000
                && victim->query("combat_exp") > killer->query("combat_exp")/2)
{
                killer->add("potential",300);
                killer->add("combat_exp",600);
                killer->add("score",500);
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s的江湖阅历提高了!!。",  killer->name()));
		CHANNEL_D->do_channel(this_object(), "rumor",
		sprintf("%s得到了官府的奖励!", killer->name(), killer->name()));
}
}
		else 
{
		if ( victim->query_condition("killer"))
{
                victim->apply_condition("killer", 0);		

}
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s"+msg, victim->name(1)));
		//官府开始通辑罪犯！
		write_file("/log/static/KILLRECORD",sprintf("%s   杀死了   %s on %s\n", killer->name(1),victim->name(1), ctime(time()) ));
}
	} else {
		killer->add("MKS", 1);
		bls = 1;
	}


	if (userp(killer) && killer->query("combat_exp") < victim->query("combat_exp"))
	killer->add("shen", -(int)victim->query("shen") / 10);

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

	if(     ( (int)killer->query("combat_exp") < victim->query("combat_exp"))
		&& (victim->query_condition("sexman")))
	{
		tell_object(killer,"恭喜你！你为武林除了一害！\n");
		exp = 100 + random(500);
		pot = 50 + random(100);
		score = 50 + random(100);
                killer->add("combat_exp",exp);
                killer->add("potential",pot);
                killer->add("score",score);
                killer->add("shen",50);
		tell_object(killer,HIW"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
		killer->set("quest", 0 );
	}
// 下面是杀人任务 
info = read_file("/data/npc/menpai.o");
infot = read_file("/data/npc/menpai1.o");

if (userp(killer) && killer->query("family/family_name") == info
&& victim->query("family/family_name") == infot
&& !killer->query_condition("menpai_kill")
&& info
&& infot
)
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
{
if (userp(victim))
{
if ((int)killer->query("combat_exp")/2 < victim->query("combat_exp")
&& !killer->query_condition("menpai_kill"))
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
             killer->add("potential",pot);
             killer->add("combat_exp",exp);
             killer->add("score",score);
tell_object(killer,HIR"恭喜你！消灭了本门之敌！\n"NOR);
		tell_object(killer,HIR"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
killer->apply_condition("menpai_kill",3);
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);

						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

}
}
else {
exp=random(200)+110;
pot=exp/2;
score=exp/3;
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);
						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

             killer->add("potential",pot);
             killer->add("combat_exp",exp);
             killer->add("score",score);
tell_object(killer,HIR"恭喜你！消灭了本门之敌！\n"NOR);
		tell_object(killer,HIR"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
killer->apply_condition("menpai_kill",3);
}
}
}

//反方
if (userp(killer) && killer->query("family/family_name") == infot
&& victim->query("family/family_name") == info
&& !killer->query_condition("menpai_kill")
&& info
&& infot
)
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
{
if (userp(victim))
{
if ((int)killer->query("combat_exp")/2 < victim->query("combat_exp")
&& !killer->query_condition("menpai_kill"))
{
exp=random(200)+110;
pot=exp/2;
score=exp/3;
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);
						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

             killer->add("potential",pot);
             killer->add("combat_exp",exp);
             killer->add("score",score);
tell_object(killer,HIR"恭喜你！消灭了本门之敌！\n"NOR);
		tell_object(killer,HIR"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
killer->apply_condition("menpai_kill",3);
}
}
else {
exp=random(200)+110;
pot=exp/2;
score=exp/3;
             killer->add("potential",pot);
             killer->add("combat_exp",exp);
             killer->add("score",score);
tell_object(killer,HIR"恭喜你！消灭了本门之敌！\n"NOR);
		tell_object(killer,HIR"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
killer->apply_condition("menpai_kill",3);
						killer->apply_condition("killer",0);
            killer->apply_condition("tongji_poison", 0);
						killer->clear_condition("killer");
            killer->clear_condition("tongji_poison");

}
}
}
	if (userp(victim))
	{
		return;
	}

	if( interactive(killer) && (quest = killer->query("quest"))
		&& (quest["quest_type"]=="杀")
		&& ( (int)killer->query("task_time") >= time())
		&&(quest["quest"]==victim->query("name")))
	{
		tell_object(killer,"恭喜你！你又完成了一项任务！\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+25;
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2)+15;
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=victim->query("quest_factor");
		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) killer->query("combat_exp");
		bonus += exp;
		killer->set("combat_exp", bonus);
		bonus = (int) killer->query("potential");
		bonus = bonus - (int) killer->query("learned_points");
		bonus = bonus + pot;
//		if( bonus > 100000) bonus = 100000;
		bonus += (int)killer->query("learned_points");
		killer->set("potential", bonus );
		bonus = (int)killer->query("shen");
		if(bonus >= 0)
			bonus += score;
		else
			bonus -= score;
		killer->set("shen", bonus);
             killer->add("score",score);
		tell_object(killer,HIW"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
		
		if ((int)killer->query_temp("menpaikill")==1)
		{
		killer->add_temp("menpaijob",1);
		killer->delete_temp("menpaikill");	
		}
		killer->set("quest", 0 );
	}
}
//杀坏人

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
