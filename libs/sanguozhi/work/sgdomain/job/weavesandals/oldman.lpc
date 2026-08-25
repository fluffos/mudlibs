//老汉 by row
#include <ansi.h>
#include <mudlib.h>
#include <sanguo.h>
#define PWEAVESANDALS PJOB+"weavesandals"
#define JOBID "weavesandals"
#define STRAWS PJWEAVESANDALS+"straws"
inherit LIVING;
string employee;
int starttime;
void ask_job(object usr);
void ask_pay(object usr);
void setup()
{
	set_name("lao han","老汉");
	set_in_room_desc("「"+YEL+"一切为了养家胡口"+NOR+"」老汉(lao han)");
	set_long("一位身形高大瘦削的老汉，饱经风霜的脸上刻满皱纹，粗糙的双手上遍布厚茧。\n"+
	"他正在编草鞋，或许你能帮他一些忙(ask lao han about job)。\n");
	set_gender(1);
	set_age(65);
	set_sg_rongmao(-1);
	employee="";
	starttime=0;
	add_question("job","job");
	add_question("pay","pay");
	add_question("rumors","rumors");
	add_question("here","here");
	add_question("name","name");
	add_question("weavesandals","weavesandals");
	add_ask_str("job","$N对$T道：这位老伯，有什么我可以帮你的吗？\n");
	add_ask_str("pay","$N对$T道：$R，人道是。。。\n");
	add_ask_str("weavesandals","$N对$T道：老伯，这草鞋底到底怎么编呀？\n");
}
mixed special_answer(object ob, string str)
{
	object player;
	player = this_body();
	switch(str)
	{
	case "job":
		ask_job(player);
		return;
	case "pay":
		ask_pay(player);
		return;
	case "rumors":
		this_object()->targetted_action("$N喃喃道："+
"老汉我足不出村，这世面上的情形就不太清楚了。\n",ob);
		return;
	case "name":
		this_object()->targetted_action("$N双目中闪过一道光芒："+
"若提起我的名字，恐怕辱没了他。。。。\n",ob);
		return;
	case "here":
		this_object()->targetted_action("$N道：此处乃是华阴小村，"+
"最近人来人往的还颇为热闹。\n",ob);
		return;
	case "weavesandals":
		this_object()->targetted_action("$N微微一笑，道：这你算是问对人了，"+
"老汉我编草鞋编了几十年了，这把手艺说起来还真有点名气呢。\n"+
"你仔细听着：先拔一些茅草(pull straws)；\n"+
"            再将两根茅草搓成绳子(weave mao cao)；\n"+
"            然后四段茅草绳编成鞋掌(weave maocao sheng)；\n"+
"            最后将两块鞋掌拼起来就得了(weave caoxie zhang)。\n"+
"刚开始的时侯可能会比较生疏，多做做就好啦。\n",ob);
	default:
		return;
	}
}
void ask_job(object usr)
{
	string n_id;
	int n_lasttimes,m_lasttimes;
	int p_s;
	object ob;
	n_id=usr->query_id()[0];
	if(employee==n_id)
	{
	this_object()->targetted_action(
	"$N对$T道：快去干你的活吧。\n",usr);
	return;
	}
	if(employee!="")
	{
	object e;
	e=find_body(employee);
	if(objectp(e))
	{
		if((time()-starttime)<600)
		{
		this_object()->targetted_action(
		"$N对$T道：眼下没什么可干的，你待会再来吧。\n",usr);
		return;
		}
	}
	}
	if(CHAR_D->get_char(n_id,"nation"))
	{
	this_object()->targetted_action(
	"$N局促道：$m$R定在戏弄$s，$s怎敢让$R帮忙？\n",usr);
	return;
	}
	n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
	m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
	m_lasttimes=10;
	if(n_lasttimes>m_lasttimes)
	{
	this_object()->targetted_action(
	"$N对$T道：你今天干的活够多的了，该休息休息了。\n",usr);
	return;
	}
	usr->resign_job(JOBID);
	usr->add_job(JOBID);
	employee=n_id;
	starttime=time();
	this_object()->targetted_action(
	"$N对$T道：好吧，我这里还缺一只鞋底，你若有心就帮老汉我个忙。\n"+
	"就用路边的茅草编，小心别把手割破了。\n"+
	"如果有什么不懂的就问我好了(ask lao han about weavesandals)。\n",usr);
	return;
}
void award(object usr)
{
	int isrobot;
	object ob;
	isrobot=usr->query_robot();
	if(isrobot)
	{
	this_object()->simple_action(
	"$N略一沉吟：嗯，原来如此。\n");
	this_object()->targetted_action(
	"$N给$T一张百圆纸钱。\n",usr);
	usr->simple_action("$N高兴地直乐：终于有钱了！\n");
	ob=new(PMONEY+"fmoney");
	ob->move(usr);
	}
	else
	{
	string p_id;
	p_id=usr->query_id()[0];
	CHAR_D->set_char(p_id,"reputation",
	CHAR_D->get_char(p_id,"reputation")+1);
	this_object()->simple_action("$N道：不错，不错。\n");
	this_object()->targetted_action("$N给$T二十两银子。\n",usr);
	ob=new(M_SILVER);
	ob->set_m_num(20);
	ob->move(usr);
	}
}
void ask_pay(object usr)
{
	object ob;
	string n_id;
	int p_s;
	int isrobot;
	n_id=usr->query_id()[0];
	if(employee!=n_id)
	{
		if(usr->query_job(JOBID,"beg_time"))
		{
		this_object()->targetted_action(
		"$N对$T道：已经有人替我干活了。\n",usr);
		usr->resign_job(JOBID);
		return;
		}
	this_object()->targetted_action(
	"$N对$T道：你还没干活呢。\n",usr);
	return;
	}
	all_inventory(usr);
	ob=present("di",usr);
	if(!objectp(ob))
	{
	this_object()->targetted_action(
	"$N疑惑地看了$T一眼，道：你开什么玩笑？\n",usr);
	return;
	}
	if(ob->query_count()<1)
	{
	this_object()->targetted_action(
	"$N对$T摇摇头道：你还没有完成。\n",usr);
	return;
	}
	else
	{
	this_object()->targetted_action(
	"$N接过$T递过的"+YEL+"草鞋底"+NOR+"。\n",usr);
	destruct(ob);
	this_object()->targetted_action(
	"$N对$T点点头，道：很好，但我还要给你出道题考考你。\n",usr);
	usr->finish_job(JOBID);
	employee="";
	starttime=0;
	ROBOT->robot_test(usr,(:award:));
	}
}