// shenlong-wudi.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIY"\n忽听得呼哨一声，$N已跳在一旁，其余众人齐往他身后挤去，迅速之极的排成一个方阵。\n\n"NOR,
	HIY"\n$n见对方几个箭步，便各自站定了方位，十余人既不推拥，亦无碰撞，足见平日\n"
	    +"习练有素，著实花过了不少功夫。\n\n"NOR,
	HIY"\n$n奋勇上前，突然间方阵中四招齐出，二攻其肩，二攻其足，配合得甚是巧妙，\n"
	    +"中间二人则架开了他的攻击。\n\n"NOR,
	HIY"\n$N右手举起，高声叫道：“洪教主万年不老，永享仙福，寿与天齐！”。\n\n"NOR,
	HIY"\n十余汉子一齐举起兵刃，状若颠狂，大呼：“洪教主寿与天齐，寿与天齐！”\n\n"NOR,
	HIY"\n$N高举右手，又呼：“洪教主神通广大，我教战无不胜，攻无不克，无坚不摧，无敌不破。\n"
	    +"敌人望风披靡，逃之夭夭。”。\n\n"NOR,
	HIY"\n$n等听得对方每念一句，心中就是一凛，但觉这些人的行为希奇古怪，从所未有，\n"
	    +"临敌之际，居然大声念起书来。。\n\n"NOR,
	HIY"\n$n却听$N和众人越念越快，十余人齐声念诵：“洪教主神通护佑，众弟子勇气百倍，\n"
	    +"以一当百，以百当万”。突然间纵声大呼，疾冲而出。。\n\n"NOR,
	HIY"\n$n见对方这些人在这顷刻间，竟然武功大进，比先前劲力加了数倍，如痴如狂，乱砍乱杀。\n\n"NOR,
	HIY"\n众汉子齐呼：“洪教主神通广大，寿与天齐，寿与天齐！”呼喊完毕，突然一齐坐倒，\n"
	    +"各人额头汗水有如泉涌，呼呼喘气，显得疲累不堪。\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 10;
}

void create()
{ 
	seteuid(getuid()); 
}

string type() { return "array"; }

int valid_learn(object me) 
{
	if( me->query_skill("dulong-dafa",1) < 150)
		return notify_fail("你的毒龙大法级别不够，无法学习神龙无敌阵。\n");
	if( me->query_skill("shenlong-yaoli",1) < 150)
		return notify_fail("你的神龙药理学级别不够，无法领悟神龙无敌阵。\n");
	if( me->query_int() < 34 )
		return notify_fail("你的悟性太低，无法领悟神龙无敌阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("神龙无敌阵只能通过学习(learn)来提高。\n");
}
