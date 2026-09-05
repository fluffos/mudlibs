#include <ansi.h>
#include <title.h>
inherit NPC;

int advtise();
string ask_for_zigong();

void create()
{
	set_name("内侍总管", ({"neishi zongguan", "zongguan", "zong guan","guan"}));
	set("title", HIR"大宋"NOR);
	set("long","他是大宋内侍的总管，奉旨出来招募些手下内侍。\n");
	set("gender", "无性");
	set("rank_info/respect", "公公");
	set("attitude", "peaceful");
	set("inquiry",([
                "入宫"  : (: ask_for_zigong :),
                "join"  : (: ask_for_zigong :),
        ]));
	set("age", 50);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("kar", 20);
	set("apply/attack",  30);
	set("apply/defense", 30);
	set("max_qi", 2800);
	set("eff_qi", 2800);
	set("qi", 2800);
	set("max_jing", 1800);
	set("eff_jing", 1800);
	set("jing", 1800);
	set("jingli", 3600);
	set("max_jingli", 3600);
	set("neili", 5600);
	set("max_neili", 5600);
	set("jiali", 150);
	set("combat_exp", 50000);
	set_skill("force", 250);
	set_skill("dodge", 220);
	set_skill("cuff", 220);
	set_skill("strike",220);
	set_skill("parry", 220);
	set_skill("blade",220);
	set_skill("sword",220);
	set("chat_chance", 10);
        set("chat_msg", ({
                (: advtise :),
        }) );
	setup();
	call_out("dest",3600);
}

int dest()
{
	destruct(this_object());
	return 1;
}

void init()
{
	add_action("do_decide", "decide");
}

int advtise()
{
    object room;
    if (environment()&& random(100)>95)
    {
        room=environment(this_object());
        if (room)
        CHANNEL_D->do_channel(this_object(), "jh", "大宋内廷招募内侍，请有意者来"+TASK_D->place_belong(room)+room->query("short")+"报名。");
	}
}

string ask_for_zigong()
{
	object me = this_player();
	if(me->query("class") == "officer")
	return "你乃女真的官员，想混进我国内廷吗......";
	if (me->query("family/family_name")=="朝廷")
	return "你乃女真的官员，想混进我国内廷吗......";
	if (me->query("song/pro")=="宦")
	return "公公莫非给我开玩笑，我昨天在宫里还见着公公的。";
	if( (string)me->query("gender")=="无性" )
	tell_object(me,"这倒是巧了，原来阁下也是位无鸟之人，倒可省了一刀。\n");
	if( (string)me->query("gender") == "女性" )
	return "这年头什么稀奇事都有，好好的大姑娘也要来当太监？";
	me->set_temp("pending/zigong", 1);
	return "入宫？你可想清楚了，鸟去不能复生，你若决心已定(decide)，我也不拦你。";
}



int do_decide()
{
	object me=this_player();
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	if( !me->query_temp("pending/zigong") )
	return 0;
	me->set("song/pro","宦");
	me->set("title",HIR+"大宋 "+color[random(sizeof(color))]+"杂役太监 洒扫院子"+NOR);
	me->set("song/title","洒扫院子");
	me->set_title(TITLE_SONG1,me->query("title"));					
	if (me->query("gender")=="无性")
	{
		command("say 记住，入宫后须服三天杂役才可分配任务，离宫。");
		return 1;
	}
	message_vision(
                "$N将$n带至身后小房间。\n\n"
                "$N唤出两个小太监按住$n双手，褪下$n的中衣，挥刀而下……\n\n"
                "$n顿时惨叫一声昏了过去……\n\n",
                this_object(), me );
	CHANNEL_D->do_channel(this_object(), "jh", "这世上又多了一个落魄的丢鸟之人啊……");
	me->delete_temp("pending/zigong");
	me->set("gender","无性");
	me->add("combat_exp",1000);
	me->unconcious();
	me->move("/d/song/zayichu");
	return 1;
}

