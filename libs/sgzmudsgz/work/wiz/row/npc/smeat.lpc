// smeat by row
// this is used for the job of 切肉
#include <mudlib.h>
#include <ansi.h>
#define JOBID "choppork"
inherit OBJ;
inherit M_CHOPPABLE;
inherit M_INPUT;
inherit M_GETTABLE;

string *desc = ({"这是一小块上好的%^B_WHITE%^%^H_RED%^猪肋%^RESET%^，肥薄肉厚，骨头都被剔干净了。\n"+
"不过一整块是没有人要的，需要用刀加工成大小均匀的%^B_WHITE%^%^H_RED%^猪肋排%^RESET%^来。\n(chop meat with tigudao)\n",
"这是一小块上好的%^B_WHITE%^%^H_RED%^猪肋%^RESET%^，肥薄肉厚，骨头都被剔干净了。\n可以看得出这块肉被人切过。\n(chop meat with tigudao)\n",
"这是一小块上好的%^B_WHITE%^%^H_RED%^猪肋%^RESET%^，肥薄肉厚，骨头都被剔干净了。\n不过被人切了这么许多刀后，已经没剩下多少了。\n(chop meat with tigudao)\n"});

int status;

void setup()
{
	set_id("meat", "%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^","xiao zhulei");
	set_in_room_desc("一块%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^(small meat)");
	status=10;
	set_unit("块");
	set_size(SMALL);
	set_can_drop(0);
	set_can_drop("把肉丢了就拿不到工钱了。\n");
	set_can_give(0);
}
string long()
{
	if(status<3)
	return desc[2];
	if(status<7)
	return desc[1];
	if(status<11)
	return desc[0];
}
void chop(object o)
{
	object tigudao,smeat;
	object ob;
	int m_hp;
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	all_inventory(this_body());
	tigudao=present("tigudao",this_body());
	smeat=present("meat",this_body());
	this_body()->simple_action(
	"$N挥舞着%^H_CYAN%^剔骨刀%^RESET%^一刀砍去，可是不巧剁在一根硬骨头上，刀『啪』地一声断了。\n"+
	"张屠户闻声赶来，劈手将$N手中的肉夺了过去，粗声道：你胡闹什么？！俺的肉可不是拿来玩儿的。\n");
	destruct(tigudao);	
	destruct(smeat);
	return;
	}
	if (status<11)
	{
	if (status==0)
	{
	smeat=present("meat",this_body());
	this_body()->simple_action(
	"$N举起%^H_CYAN%^剔骨刀%^RESET%^想再切几块，却发现肉已经用完了。\n");
	destruct(smeat);
	return;
	}
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{
	write("你太累了，休息一会儿吧。\n");
	return;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	status=status-1;
	switch(random(5))
	{
	case 0:
	this_body()->start_busy(3,"你正忙着切肉呢。\n");
	this_body()->simple_action("$N举起%^H_CYAN%^剔骨刀%^RESET%^对准%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^"+
	"猛地就是一下，可没想到力道使岔了，切下一块厚薄不一的肉片来。\n唉，张屠户肯定不会要这样子的肋排的，扔了吧。\n\n");
	break;
	case 5:
	this_body()->start_busy(3,"你正忙着切肉呢。\n");
	this_body()->simple_action("$N举刀切了下去，糟了，差点儿割到自己的手指，$N一慌，不小心把刚切下的肉碰掉在地上的臭水塘里。\n"+
	"完了，张屠户卖肉的声誉极好，他是不会要这种脏肉的，还是扔了吧。\n\n");
	break;
	default:
	this_body()->start_busy(3,"你正忙着切肉呢。\n");
	this_body()->simple_action( ({"$N用并不熟练的手法操着%^H_CYAN%^剔骨刀%^RESET%^，小心翼翼地从%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^上切下一块肉片\n"+
	"嗯，厚薄均匀，肥瘦适中，是一块合格的%^B_WHITE%^%^H_RED%^猪肋排%^RESET%^。\n\n",
	"$N左手将%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^按在案台上，右手攥紧%^H_CYAN%^剔骨刀%^RESET%^，慢慢地切下一片肉来。\n"+
	"嗯，厚薄均匀，肥瘦适中，是一块合格的%^B_WHITE%^%^H_RED%^猪肋排%^RESET%^。\n\n",
	"$N一边看着张屠户的手势，一面学着从%^B_WHITE%^%^H_RED%^小猪肋%^RESET%^上切下一片肉来，还挺象那么一回事。\n"+
	"嗯，厚薄均匀，肥瘦适中，是一块合格的%^B_WHITE%^%^H_RED%^猪肋排%^RESET%^。\n\n"}) );
	ob=new(__DIR__"pork");
	ob->move(this_body());
	break;
	}
	}
}