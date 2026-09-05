//Change to Song Dynasty General Meng Gong Zine@pkuxkx 2013-8-12
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include "ct_title.h"
#include <no1master.h>
string do_toujun();
void do_answer(string);
int do_decide();
int ask_book();
int ask_book1();
void create()
{
	set_name("孟珙", ({"meng gong", "meng", "gong"}));
	set("title", HIR+"大宋 "+CYN+"建康府诸军都统制"+NOR);
	set("long",
		"他就是建康府诸军都统制，又兼权侍卫马军行司职事。\n"
		"他是宋朝的擎天一柱，他统领着宋朝三分之二的战线。\n"
		"他正在回京述职中。\n"
	);

	set_max_encumbrance(100000000);
	set("no_get", 1);
	set("attitude","friendly");
	set("max_qi", 18000);
	set("eff_qi", 18000);
	set("qi", 18000);

	set("max_jing", 18000);
	set("eff_jing", 18000);
	set("jing", 18000);

	set("jingli", 36000);
	set("max_jingli", 36000);

	set("neili", 36000);
	set("max_neili", 36000);

	set("jiali", 380);

	set("combat_exp", 12000000);
	set_skill("force", 220);
	set_skill("dodge", 180);
	set_skill("cuff", 180);
	set_skill("hand",180);
	set_skill("parry", 180);
	set_skill("blade",180);
	set_skill("sword",180);
	set_skill("staff",180);
	set_skill("whip",180);
	set_skill("halberd",180);
	set_skill("spear",180);
//	set_skill("strategy", 200);
//	set_skill("leadership", 200);
	set_skill("literate", 100);
  set_skill("strategy", 100);
  set_skill("leadership", 100);
	set_skill("bixue-xinfa", 220);
	set_skill("longfeng-xiang", 180);
	set_skill("panlong-gun", 180);
	set_skill("taizu-changquan", 180);
	set_skill("pojun-daofa", 180);
	set_skill("huqian-jianfa", 180);
	set_skill("gehu-ji", 180);
	set_skill("lihua-qiang", 180);
	set_skill("yuejia-sanshou", 180);
	set_skill("menghu-bian", 180);
	map_skill("force", "bixue-xinfa");
	map_skill("sword", "huqian-jianfa");
	map_skill("blade", "pojun-daofa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "yuejia-sanshou");
	map_skill("hand", "yuejia-sanshou");
	map_skill("whip", "menghu-bian");
	map_skill("halberd", "gehu-ji");
	map_skill("staff", "panlong-gun");
	map_skill("spear", "lihua-qiang");
	map_skill("cuff", "taizu-changquan");

	prepare_wskill("sword", "huqian-jianfa");
	prepare_wskill("blade", "pojun-daofa");

	prepare_skill("cuff", "taizu-changquan");
	prepare_skill("hand", "yuejia-sanshou");

		set_temp("apply/armor", 200);
		set_temp("apply/damage", 250);
	set("gender", "男性");
	set("age", 35);
        set("book_count", 10);
	set("class", "officer");
	create_family("朝廷", 2, "官员");
	set("shen_type",1);set("score",5000);setup();
	carry_object("/d/city/npc/items/cloth")->wear();
	carry_object("/d/city/obj/gangjian")->wield();
	//carry_object("/clone/weapon/gangdao")->wield();

	set("inquiry", ([
	"投军" : (: do_toujun :),
	"入伍" : (: do_toujun :),
	"join" : (: do_toujun :),
	"here" : "我回到临安府已经多日，官家却还没有安排辞陛的时间，心中不安啊。",
	"黄石公三略" :(:ask_book:) ,
	"神机制敌太白阴经" :(:ask_book1:) ,
	]));

	setup_no1master();
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

	add_action("do_decide", "decide");
}
int ask_book1()
{
	object me=this_player(),ob=this_object(),book;
	if (me->is_busy())
	{
		command("say 等你忙完再来问我。");
		return 1;
	}
	else if (time()-me->query("statistics/tbyj_attempt")<3600)
	{
		command("say 你不是之前刚问过我吗？");
		return 1;
	}
	else if (!me->query_temp("tbyj_obtain/start"))
	{
		me->set("statistics/tbyj_attempt",time());
		me->set_temp("tbyj_obtain/start",1);
		command("say 如果你能在八分钟内完成一次百晓生任务，我可以把太白阴经给你。");
		return 1;
	}
	else if (!me->query_temp("tbyj_obtain/success"))
	{
		command("say 不是跟你说了八分钟完成一次百晓生任务吗？");
		return 1;
	}
	else
	{
		book=new("/d/hangzhou/obj/books/book_strategy_7");
		book->move(ob);
		command("give "+me->query("id")+" book");
		command("say 那就交给你了。");
		me->delete_temp("tbyj_obtain");
		return 1;
	}
	
}
int answer(string arg,object me,string answer)
{
	if (!me)
	return 1;
	message_vision("$N开始着手修订三略……\n",me);
	if (arg==answer)
	{
		me->add_temp("sanlue/correct",1);
		tell_object(me,"三略被你修订了一些……\n");
	}
	else
	{
		me->delete_temp("sanlue/correct");
		tell_object(me,"你似乎弄错了，"+this_object()->name()+"不愿意再把这样工作交给你。\n");
	}
	return 1;
}
int ask_book_detail(object me,string text)
{
	int start_word,finish_word,j,k;
	string sub_txt="",sub="",format_txt;
	string *pre1=({HBBLU,HBWHT,HBYEL,HBCYN,HBRED,HBMAG}),*pre2=({U,BLINK}),pre;
	start_word=random(strwidth(text)/2)*2;
	finish_word=start_word+2*(3+random(5))-1;
	if (finish_word>strwidth(text))
	finish_word=strwidth(text);
	switch (random(3))
	{
	case 0:
	j=random(sizeof(pre1));
	pre=pre1[j];
	break;
	case 1:
	k=random(sizeof(pre2));
	pre=pre2[k];
	case 2:
	j=random(sizeof(pre1));
	k=random(sizeof(pre2));
	pre=pre1[j]+pre2[k];
	}
	for (int i=0;i<strwidth(text);i++)
	{
//句号后面加换行的话，如果sub_txt跨2行，会导致颜色等效果不显示。 by all@pkuxkx
//		if (i%30==0&&i!=0)
//		format_txt=replace_string(text,"。","。"+"\n");
		if (i>=start_word&&i<=finish_word&&i%2==0)
		{
			sub_txt+=text[i..i+1];
			sub+=pre+text[i..i+1]+NOR;
		}
	}
//	format_txt=replace_string(format_txt,sub_txt,sub);
	format_txt=replace_string(text,sub_txt,sub);	
	tell_object(me,HIR+this_object()->query("name")+HIR+"拿出三略，似乎希望你帮助修正一二。\n"+NOR+format_txt);
	tell_object(me,HIG+"以上的句段，你觉得哪里不合理，比如字的颜色不同，有下划线，斜体等等，请指出\n"+NOR);
	input_to((:answer:),me,sub_txt);
	return 1;
}
int ask_book()
{
	string *texts=({"《军谶》曰：“柔能制刚，弱能制强。”柔者，德也；刚者，贼也。弱者人之所助，强者怨之所攻。柔有所设，刚有所施；弱有所用，强用所加；兼此四者，而制其宜。端末未见，人莫能知；天地神明，与物推移；变动无常，因敌转化；不为事先，动而辄随。故能图制无疆，扶成天威，匡正八极，密定九夷。如此谋者，为帝王师。故曰：莫不贪强，鲜能守微；若能守微，乃保其生。圣人存之，动应事机。舒之弥四海，卷之不盈怀；居之不以室宅，守之不以城郭；藏之胸臆，而敌国服。《军谶》曰：“能柔能刚，其国弥光；能弱能强，其国弥彰；纯柔纯弱，其国必削；纯刚纯强，其国必亡。”",
		"夫主将之法，务揽英雄之心，赏禄有功，通志于众。故与众同好，靡不成；与众同恶，靡不倾。治国安家，得人也；亡国破家，失人也。含气之类，咸愿得其志。",
		"夫为国之道，恃贤与民。信贤如腹心，使民如四肢，则策无遗。所适如支体相随，骨节相救；天道自然，其巧无间。军国之要，察众心，施百务。危者安之，惧者欢之，叛者还之，怨者原之，诉者察之，卑者贵之，强者抑之，敌者残之，贪者丰之，欲者使之，畏者隐之，谋者近之，谗者覆之，毁者复之，反者废之，横者挫之，满者损之，归者招之，服者居之，降者脱之。获固守之，获阨塞之，获难屯之，获城割之，获地裂之，获财散之。敌动伺之，敌近备之，敌强下之，敌佚去之，敌陵待之，敌暴绥之，敌悖义之，敌睦携之。顺举挫之，因势破之，放言过之，四网罗之。得而勿有，居而勿守，拔而勿久，立而勿取。为者则己，有者则士。焉知利之所在？彼为诸侯，己在天子，使城自保，令士自处。",
		"世能祖祖，鲜能下下；祖祖为亲，下下为君。下下者，务耕桑，不夺其时；薄赋敛，不匮其财；罕徭役，不使其劳；则国富而家娭，然后选士以司牧之。夫所谓士者，英雄也。故曰：罗其英雄则敌国穷。英雄者，国之干；庶民者，国之本。得其干，收其本，则政行而无怨。",
		"夫用兵之要，在崇礼而重禄。礼崇，则智士至；禄重，则义士轻死。故禄贤不爱财，赏功不逾时则下力并而敌国削。夫用人之道，尊以爵，赡以财，则士自来；接以礼，励以义，则士死之。",
		"夫将帅者，必与士卒同滋味而共安危，敌乃可加。故兵有全胜，敌有全因。昔者良将之用兵，有馈箪醪者，使投诸河，与士卒同流而饮。夫一箪之醪，不能味一河之水，而三军之士思为致死者，以滋味之及己也。《军谶》曰：“军井未达，将不言渴；军幕未办，将不言倦；军灶未炊，将不言饥。冬不服裘，夏不操扇，雨不张盖。”是谓将礼。与之安，与之危，故其众可合而不可离，可用而不可疲；以其恩素蓄，谋素合也。故蓄恩不倦，以一取万。",
		"《军谶》曰：“将之所以为威者，号令也；战之所以全胜者，军政也；士之所以轻战者，用命也。”故将无还令，赏罚必信；如天如地，乃可御人；士卒用命，乃可越境。",
		"夫统军持势者，将也；制胜破敌者，众也。故乱将不可使保军，乖众不可使伐人。攻城则不拔，图邑则不废；二者无功，则士力疲弊。士力疲弊，则将孤众悖；以守则不固，以战则奔北。是谓老兵。兵老，则将威不行；将无威，则士卒轻刑；士卒轻刑，则军失伍；军失伍，则士卒逃亡；士卒逃亡，则敌乘利；敌乘利，则军必丧。",
		"《军谶》曰：“良将之统军也，恕己而治人，推惠施恩，士力日新，战如风发，攻如河决。”故其众可望而不可当，可下而不可胜。以身先人，故其兵为天下雄。",
		"《军谶》曰：“军以赏为表，以罚为里。”赏罚明，则将威行；官人得，则士卒服；所任贤，则敌国震。",
		"《军谶》曰：“贤者所适，其前无敌。”故士可下而不可骄，将可乐而不可忧，谋可深而不可疑。士骄，则下不顺；将忧，则内外不相信；谋疑，则敌国奋。以此，攻伐则致乱。夫将者，国之命也。将能制胜，则国家安定。",
		}),text;
	object me=this_player(),book;
	if (me->query_temp("sanlue/correct")>10+random(6))
	{
		me->delete_temp("sanlue");
		book=new("/d/hangzhou/obj/books/book_strategy_5");
		book->move(me);
		message_vision("$N给了$n一本"+book->query("name")+"。\n",this_object(),me);
		return 1;
	}
	if (me->query("combat_exp")<me->query("statistics/sanlue_attempt_exp")*5&&!me->query_temp("sanlue/allow_attempt"))
	{
		command("say 三略不在我这，你先回去吧。");
		return 1;
	}
	me->set("statistics/sanlue_attempt_exp",me->query("combat_exp"));
	me->set_temp("sanlue/allow_attempt",1);
	text=texts[random(sizeof(texts))];
	ask_book_detail(me,text);
	return 1;
}


string do_toujun()
{
	object me = this_object();
	object player = this_player();
	object yaopai;
	mapping fam;
	int leave_age;
	if (player->query("class") == "officer")
		return "大人开什么玩笑？";

	if (player->query("gender") == "无性")
	return RANK_D->query_respect(player) + "要进宫做事我可管不了。";

	// we allow this player to join, check positions available

		if ((string)player->query("family/family_name") == "灵鹫宫"
			&& player->query("lingjiu/xiulian"))
		{
			player->set_temp("chaoting/bai",1);
			return RANK_D->query_respect(player) + "，你现在加入我大宋朝廷似乎会有很大损失，你能拿定主意吗？(answer)";

		}
	player->set_temp("chaoting/toujun", 1);
	return "你决定加入我大宋朝廷吗？(decide)";

}
int join_in(object me)
{
	me->set("family", ([
			"family_name"    : "朝廷",
			"enter_time"     : time(),
		]));
	me->set("chaoting/salary", me->query("mud_age"));
	me->set("score", 0);
	me->set("class", "officer");
	me->set("chaoting/officer", 1);
	me->set("pin", 9);
	me->set("title", NOR"大宋不入品官员"NOR);
//title系统记录玩家title by seagate@pkuxkx
	me->set_title(TITLE_RANK, "大宋不入品官员 ");
	message_vision("$N拍着$n的肩膀说道：现在北面战事日紧，你即加入我大宋朝廷，也要多多努力。\n", this_object(), me);
	me->save();
	return 1;
}
void do_answer(string arg)
{
	object me=this_player();
	int time;
	if (!me->query_temp("chaoting/bai")) return;
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
		command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
		command("say 好吧，"+RANK_D->query_respect(me)+"，我就同意你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14 + me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
		me->delete_temp("chaoting/bai");
		//灵鹫的肯定是女性，以下就不判断性别了
		message_vision("$N决定背叛师门，加入大宋朝廷！！\n", me);
		me->delete("family");
		join_in(me);
	}
	return;
}

int do_decide()
{
	object player = this_player();
	int time;
	string name;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
	name = player->query("name");
	if (!player->query_temp("chaoting/toujun")) return 0;
	if(player->query("class") == "officer")
		return 0;
	if(player->query("chaoting/officer") || player->query("chaoting/eunuch")) 	
		return 0; //added by whuan at 2009-1-10 to fix the bug that officer can cut and join again
  
  if(mapp(player->query("family")))
	{
		message_vision("$N必须先脱离原先的门派：" + player->query("family/family_name")+", 才能转投别的门派。\n", player);
		return 1;
		//if ( player->query("combat_exp") >= 1000 ) player->add("betrayer", 1);不需要加判师判定，直接不让拜师
  }
  else
  {
	  message_vision("$N决定加入大宋朝廷！！\n", player);
	  join_in(player);
	}
	return 1;
}
void attempt_apprentice(object ob)
{
	if(ob->query("class") != "officer")
	{
		command("say " + RANK_D->query_respect(ob) + "是否有意加入大宋朝廷呢？");
		tell_object(ob,"你若想加入我大宋朝廷，请ask meng about 入伍。\n");
		return;
	}
	command("say 好吧，我会把我这些年行军之际的心得都传授给你，你要细心记住。");
	command("recruit " + ob->query("id"));
}

void recruit_apprentice(object ob)
{
	int pin;
	string *rank_name, title;
	string *all_color = ({HIR,HIB,HIG,HIY,HIC,HIW,HIM,GRN,YEL});

	if( ::recruit_apprentice(ob) )
	pin = ob->query("pin");
	title=give_title(ob);
	ob->set("title", title);
	//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, title);
    ob->set("chaoting/newtitle",1);
//修改title请同时修改mingzhu.c里面的相应地方 - vast
}