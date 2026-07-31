// NPC jiuyi.c// update by firefox
//	2001-10-23
#include <ansi.h>
inherit NPC;
string ask_me();
string ask_jiu();
string ask_zhishang();
string ask_steal();
string ask_xiongshewan();
string ask_dahui();
int kill(string arg); 

void create()
{
	set_name("乌老大", ({ "wu laoda", "wu"}));
	set("long",
@LONG他就是名动江湖的乌老大，由于谋反童姥未遂而被囚禁于此。
LONG	    	   );
//	set("title", "西夏一品堂高手");
	set("gender", "男性");
//	set("nickname", HIR "雷动于九天之上" NOR);
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
	set("max_qi",1000);
	set("eff_qi",100);
 	set("qi", 100);
// 	set("qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);
	set("combat_exp", 1000000);
	set("score", 100000);
	set("no_get",1);
	set("no_fight",1);
	set("inquiry", ([
		"白云熊胆丸" : (: ask_me :),
		"解救" : (: ask_jiu :),
		"治伤" : (: ask_zhishang :),	
		"九转熊蛇丸" : (: ask_xiongshewan :),
		"盗取" : (: ask_steal :),
		"万仙大会" : (: ask_dahui :),
	]));
	set("chat_chance", 3);
        set("chat_msg", ({"乌老大喃喃道：白云熊胆丸可真是好东西！\n",        }) );
	set("wan_count", 1);
	setup();
}

void init()
{
	::init();
	add_action("do_kill","kill");
}

string ask_me()
{
	mapping fam;
 	object ob;	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) +"你怎敢要灵鹫宫之镇派宝物呢？";
	if (query("wan_count") < 1)
		return "不好意思，已经有人捷足先登了，你下次再来吧。\n";
	add("wan_count", -1);
	ob = new("/clone/drug/xiongdan-wan");
	ob->move(this_player());
	return "唉，看在你舍身救我的份上，这颗白云熊胆丸就给你吧。\n";
}

string ask_jiu()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫" || 
		!this_player()->query_temp("apply/name/蒙面人"))
		return "你是何方神圣，灵鹫宫岂是尔等来去自如之地，何言救我！\n";
	this_player()->set_temp("xiongshe_quest",1);
	command("thank "+this_player()->query("id"));
	return "现在我已遍体鳞伤，只怕动一动便有性命之危！\n";
}

string ask_zhishang()
{
	if (this_player()->query_temp("xiongshe_quest")) {
		this_player()->set_temp("xiongshe_quest",2);
		return "我这伤除了本派圣药九转熊蛇丸可以医治外，只怕平一指大夫也难以救治！\n";
	}
}
string ask_xiongshewan()
{
	if (this_player()->query_temp("xiongshe_quest")>=2) {	
		this_player()->set_temp("xiongshe_quest",3);
		return "九转熊蛇丸是我派疗伤圣药，有起死回生之功效。由童姥亲自收藏，如何弄得到！\n";
	}
}
string ask_steal()
{
	if (this_player()->query_temp("xiongshe_quest")>=3) {		
		this_player()->set_temp("xiongshe_quest",4);
		return "要盗取灵药是比登天还难，我曾盗得一颗以备在万仙大会时使用，可惜没带在身上。\n";
	}
}
string ask_dahui()
{
	if (this_player()->query_temp("xiongshe_quest")>=4) {
		command("whipse "+this_player()->query("id")+
			" 万仙大会是我们三十六洞洞主、七十二岛岛主不堪受制于天山童姥，为解除生死符之苦，\n"+
			"杀死天山童姥而共同举办的重要大会。此事事关重大，朋友可千万不可对人言。\n");
		message_vision("$N对乌老大说道：“你等好大的胆子，竟想谋害童姥，我这就去回禀童姥。你等候童姥发落吧！\n",this_player());
		command("ah "+this_player()->query("id"));
		this_player()->set_temp("xiongshe_quest",5);
		message_vision("$N见已骗得乌老大道出万仙大会的秘密，便露出了真面目。\n",this_player());
		return "你……你到底是敌是友？";
	}		
}
int do_kill(string arg)
{
	object ob;
	if ( !arg || !(ob=present(arg,environment(this_object())))) return 0;
	if ( this_player()->query_temp("xiongshe_quest")==6) {
		environment(this_object())->delete("no_fight");
		message_vision("$N对乌老大说道：“叛贼，受死吧！\n",this_player());
		write(HIG"只见青光一闪，你手中宝剑已从乌老大胸前对穿而出，嗖的一声又飞回你的手中！\n"NOR);
		this_player()->set_temp("xiongshe_quest",7);
		ob->die();
		return 1;
	} else {
		if (ob->query("name")=="乌老大"){
			write("你是来审讯的，乌老大死了你如果向童姥交待？\n");}
		return 0;	
	}
} 