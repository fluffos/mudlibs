// cool 980310
// duan1.c
// Modify By River 98/11
//COOL@SJ,990828

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_join();
string ask_duan();
string strike();
string fenglu();
string ask_save();
void create()
{
	set_name("段正淳", ({ "duan zhengchun", "duan", "master" }) );
	set("title", "镇南王");
	set("nickname","风流王爷");
	set("gender", "男性" );
	set("age", 44);
	set("str", 22);
	set("con", 23);
	set("dex", 23);
	set("int", 25);
	set("per", 28);
	set("attitude", "friendly");

	set("max_qi", 3000);
	set("max_jing", 1800);
	set("eff_jingli", 1800);
	set("neili", 3000);
	set("qi", 3000);
	set("jingli", 1800);
	set("max_neili", 3000);
	set("jiali", 50);

	set("rank_info/respect", "风流王爷");
	create_family("天龙寺", 13, "俗家弟子");

	set("long",
	"段正淳是个相当高大的中年儒生，若不是跟随在他左右的铁甲卫士成群，\n"
	"你大概猜不到眼前这个温文儒雅的中年人竟是大理王爷。\n");

	set("combat_exp", 1100000);
	set("score", 50000);

	set("chat_chance_combat", 30);
	set("chat_msg_combat",({
		(: perform_action, "sword.fenglei" :),
		(: exert_function, "qi" :)
	}));

	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("force", 150);
	set_skill("cuff", 150);
	set_skill("literate", 120);
	set_skill("sword", 160);
	set_skill("duanjia-jianfa", 160);
	set_skill("strike", 150);
	set_skill("qingyan-zhang", 150);
	set_skill("qiantian-yiyang", 150);
	set_skill("duanjia-quan", 150);
	set_skill("tianlong-xiang", 150);
	set_skill("finger", 150);
	set_skill("yiyang-zhi", 160);
	set_skill("buddhism", 100);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "qingyan-zhang");
	map_skill("sword", "duanjia-jianfa");
	map_skill("cuff", "duanjia-quan");
	map_skill("force", "qiantian-yiyang");
	map_skill("strike", "qingyan-zhang");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("strike","qingyan-zhang");
	prepare_skill("cuff","duanjia-quan");

	set("inquiry", ([
		"段誉" : (: ask_duan :),
		"name": "你问这干嘛，我就是段正淳，难道你又是我情人生的孩子？",
		"here": "这里便是镇南王府。",
		"天龙寺" : "天龙寺是我段家武学的最高之地，不过，想拜天龙寺可不是那么容易的.",
		"拜天龙" : (: ask_join :),
		"拜天龙寺" : (: ask_join :),
		"掌法诀要" : (: strike :),
		"练掌法" : (: strike :),
		"俸禄" :  (: fenglu :),
		"营救" : (: ask_save :),
		"搭救" : (: ask_save :),
	]));

	setup();
	carry_object("/d/dali/npc/obj/huangpao")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

string strike()
{
	mapping fam = this_player()->query("family");
	object ob;
	if(!fam || fam["family_name"] != "天龙寺")
		return RANK_D->query_respect(this_player())+"与本派素无来往，不知此话从何谈起？";
	if(this_player()->query_skill("strike",1) > 30)
		return "你的掌法已经有一定基础了，这本书对你没什么用，还是留给别的弟子吧";
	ob = unew("/d/dali/obj/book-strike");
	if(!clonep(ob))
		return "你来晚了，本派的「掌法诀要」不在此处。";
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "你来晚了，本派的「掌法诀要」不在此处。";
	}
	ob->move(this_player());
	return "好吧，这本「掌法诀要」你拿回去好好钻研。";
}

string ask_join()
{
	object me;
	object ob;
	ob=this_player();
	me=this_object();
	if (ob->query("tls"))
		return "你已经是天龙寺出家弟子了，何故还要问此事？";

//	if (ob->query("combat_exp") > 100000)
//		return "大理段氏在大理还需要你这样的人才，就不要去天龙寺出家吧。";

	if(ob->query_temp("tls_app"))
		return "我不是已经推荐你去天龙寺了吗？怎么还不去啊？";

	if((string)ob->query("gender") == "女性" )
		return "天龙寺武功需要纯阳之体，小姑娘可不收啊! ";

	if((int)ob->query_skill("qiantian-yiyang",1) < 120  )
		return RANK_D->query_respect(ob) +"，你乾天一阳功太差,不能学习高等级的功夫!";

	if ( ob->query("job_time/大理") < 50)
		return "我看你为镇南王府做事做的还不够啊，努力做吧！";

	if ( ob->query_int() < 30 )
		return "天龙寺武学深奥，我看你的悟性似乎不够，恐怕无法领会这么高的功夫!";

	if( ob->query("marry"))
		return "你都已经结婚了，要去出家，叫你夫人怎么办？";

	ob->set_temp("tls_app",1);
	command ("say 哈哈！好样的！这位兄弟既然为我大理段氏做了这么多事,今天就推荐你去天龙寺！");
	return "我即刻修书一封，快马送到天龙寺了惑禅师那里，你速速赶去吧!";
}

string ask_duan()
{
	object ob = this_player();
	if( ob->query("quest/dali/shanlu") && ob->query("quest/dali/pass")){
		if( ob->query("family") && ob->query("family/family_name") =="天龙寺"){
			ob->set_temp("duanyu/find4",1);
			return "小儿日前身体不适，和他叔父保定帝去天龙寺了。";
		}
		else return "上次多亏"+RANK_D->query_respect(ob) +"相救，现在小儿业已康复，真是多谢"+RANK_D->query_respect(ob) +"了。";
	}
	if( ob->query("dali/fail") >= 3)
		return("这位"+RANK_D->query_respect(ob) +"还是算了，多谢"+RANK_D->query_respect(ob) +"鼎立相助，我看还是换别人试试吧。");

	if( ob->query_temp("duanyu/find1")){
		ob->set_temp("duanyu/ask",1);
		return ("小儿日前被四大恶人的南海鳄神掳走了，我们正在设法营救他，唉，求佛祖保佑! ");
	}
	else return ("小儿不爱学武，和我吵了几句就离家出走了，唉。。家门不幸啊! ");
}

string fenglu()
{
	object ob=this_player();
	mapping fam = ob->query("family");
	int gold = 0, fenglu;

	if (!fam || fam["family_name"] != "天龙寺")
		return "这位"+ RANK_D->query_respect(ob) +"不是我大理国的臣民，难道也想来拿大理的俸禄？";

	if( ob->query("tls"))
		return "这位"+ RANK_D->query_respect(ob) +"已经出家了，还要这俸禄做甚？";

	switch (fam["generation"]) {
		case 13:
			gold += 500;
		case 14:
			gold += 800;
			break;
		default:
			return "这位"+ RANK_D->query_respect(ob) +"在大理时间还太短，等过段时间才来拿吧。";
	}
	fenglu = ob->query("age") * 12 + ob->query("month");
	if (ob->query("fenglu") >= fenglu)
		return "这位"+RANK_D->query_respect(ob) +"本月不是已经拿过俸禄了，怎么还想来拿？";
	gold *= ob->query_skill("qiantian-yiyang", 1);
	if (gold < 1) return "你这个月没有俸禄。";
	ob->set("fenglu", fenglu);
	command ("pat " + ob->query("id"));
	message_vision("$N给了$n"+MONEY_D->money_str(gold)+"。\n", this_object(), ob);
	MONEY_D->pay_player(ob, gold);
	return "这是你本月的俸禄，这位"+ RANK_D->query_respect(ob) +"好好干啊！";
}

void attempt_apprentice(object ob)
{
	object me=this_object();
	mapping fam = ob->query("family");
	if( (string)ob->query("gender") == "女性" ){
		command ("say 我天龙寺武功需要纯阳之体，小姑娘我可不收啊!");
		return;
	}
	if (ob->query("tls")){
		command ("say 你已经是天龙寺出家弟子了，我不能再收你了！\n");
		return;
	}
	if( (int)ob->query_skill("qiantian-yiyang",1) < 80  ){
		command ("hmm");
		command ("say 你乾天一阳功如此之差，我可不收你?");
		return;
	}
	if(ob->query_int() < 30){
		command("say 学一阳指之人必须悟性奇高，依我看" + RANK_D->query_respect(ob) + "的资质似乎不够？");
		return;
	}
	if(fam["master_name"] == "段正明"){
		command("haha");
		command("say "+RANK_D->query_respect(ob)+"已是兄长身前的侍卫，"+RANK_D->query_self(me)+"怎能再收你为徒？");
		return;
	}
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
	command("recruit " + ob->query("id") );
	if (!ob->query("qinwang")) 
		ob->set("title","大理国镇南王府家将");
	else
		ob->set("title", HIW"大理国"+ ob->query("qinwang")+NOR);
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	 ob->set("class", "officer");
}

string ask_save()
{
	object ob;
	int i,j,x, time;
	i=random(5)+2;
	j=random(4)+3;
	ob=this_player();

	x = ob->query("combat_exp") - 1000000;
	x /= 1000000;
	time = time() - ob->query("quest/dali/time");

	if ( ob->query("shen") < 0)
		return ("我看" + RANK_D->query_respect(ob) +"面带阴邪之气，恐怕是四大恶人一伙的奸细。");

	if ( ob->query("combat_exp") < 1000000)
		return ("四大恶人都是绝顶高手,"+RANK_D->query_respect(ob) +"似乎武功不够，和四大恶人相斗会有性命之忧。");

	if ( ob->query("int") < 24 )
		return "想那四大恶人狡诈异常，这位"+RANK_D->query_respect(ob) +"过于愚钝了，我不太放心。";

	if ( ob->query("quest/dali/fail") >= 3 && ob->query("registered") < 3)
		return "上次多亏这位"+RANK_D->query_respect(ob) +"鼎力相助，这次还是算了吧。";

	if ( ob->query("quest/dali/fail") >= x )
		return "上次多亏这位"+RANK_D->query_respect(ob) +"鼎力相助，这次还是算了吧。";

	if ( ob->query("quest/dali/time") && time < 86400 )
		return "誉儿被那四大恶人擒走，这件事还需从长计议，千万不得鲁莽。";

	if (ob->query_temp("duanyu/find2"))
		return ("你怎么还不快去啊?时间紧迫！");

	if( ob->query_temp("duanyu/ask")){
		ob->set_temp("duanyu/step",-i);
		ob->set_temp("duanyu/steps",j);
		ob->set_temp("duanyu/find2",1);
		return ("既然"+ RANK_D->query_respect(ob) +"有意相助，定会如虎添翼。居我得知，誉儿被四大恶人之首\n"+
			"段延庆囚在正在无量山附近的一座石屋内，只是路上十分险恶，之前为了探明路线，\n"+
			"我已损失好几名手下。你先去大理北面去无量山路上的一个小溪那里，向北行五里，\n"+
			"再向西行"+chinese_number(j)+"里，再向北行"+chinese_number(i)+"里，然后会到一座高山，再往后就要见机行事了。\n"+
			"段正淳说道：好了，准备一下，为了不惊动对方，切记要在晚上行动，路上小心。");
	}
	else return "此话从何谈起？";
}
