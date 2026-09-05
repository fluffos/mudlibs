inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name(WHT"巨碑"NOR, ({ "board" }) );
	set("location", "/d/song/jianyuan2");
	set("board_id", "dasong_jianyuan_b");
	set("long", "这是一面巨大的石碑，供人发表各种建议、意见。\n" );
	setup();
	set("capacity", 35);
	
}
void init()
{
	add_action("score","value");
	::init();
}
int do_post(string arg)
{
	if (!this_player()->query("song/pro")||this_player()->query_temp("songtasks/jianyuan/task")!=1)
		return notify_fail("没有谏院左司谏的许可，你不能在这留言。\n");
	write("你在这里郑重的留下自己的建议。\n");
	this_player()->delete_temp("songtasks");
	return ::do_post(arg);
}

int score(string arg)
{
	object me=this_player();
	int noteno,score;
	mapping* notes=query("notes");
	if(!userp(me) || SECURITY_D->get_wiz_level(me) < 6) return 0;
	if (!arg||sscanf(arg,"%d as %d",noteno,score)!=2) return notify_fail("评分的格式是value <编号> as <评分>。\n");
	if (noteno<1||noteno>sizeof(notes)) return notify_fail("评分的帖子编号不正确。\n");
	if (score<0||score>2) return notify_fail("评分的得分必须在0-2之间，0对应差，1对应中，2对应优。\n");
	if (notes[noteno-1]["valued"]) return notify_fail("这张帖子已经被评分过了。\n");
	if (!query_temp("attempt_"+(noteno-1)))
	{
		write("你确认要给"+notes[noteno-1]["authorid"]+"的帖子『"+notes[noteno-1]["title"]+"』评分为"+score+"吗？如确定，请重复评分过程。\n");
		set_temp("attempt_"+(noteno-1),1);
		return 1;
	}
	notes[noteno-1]["valued"]=1;
	notes[noteno-1]["gain_score"]=score;
	write("你给"+notes[noteno-1]["authorid"]+"的帖子『"+notes[noteno-1]["title"]+"』评分为"+score+"。\n");
	save();
	return 1;
}
int credit(object pl,mapping index)
{
	int point=-2;
	if (index["gain_score"]==1)
	point=2;
	if (index["gain_score"]==2)
	point=4;
	DASONG_D->task_finish(pl,point);
	if (point<0)
	tell_object(pl,"因为你在谏院的帖子"+index["title"]+"收获了一个差评。\n");
	else if (point==2)
	tell_object(pl,"因为你在谏院的帖子"+index["title"]+"收获了一个中评。\n");
	else if (point==4)
	tell_object(pl,"因为你在谏院的帖子"+index["title"]+"收获一个优评。\n");
	return 1;
}
int give_players_credit()
{
	object pl;
	mapping* notes=query("notes");
	for (int i=0;i<sizeof(notes);i++)
	{
		if (notes[i]["credited"])
		continue;
		if (!notes[i]["valued"])
		continue;
		if (!pl=find_player(notes[i]["authorid"]))
		continue;
		if (!pl->query("song/pro"))
		continue;
		notes[i]["credited"]=1;
		credit(pl,notes[i]);
	}
	save();
	return 1;
}