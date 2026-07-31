 // /u/beyond/mr/npc/murong-fu.c  慕容复
// this is made by beyond
// update 1997.6.23
inherit NPC;
inherit F_MASTER;
string ask_bo();
string ask_skill();
string ask_wang();
string ask_dan();
string ask_dan1();
string ask_ge();
string ask_sword(); 
string ask_book();
string ask_book2();
object ob = this_object();

void create()
{
	set_name("慕容复",({"murong fu","murong","fu"}));
        set("title","姑苏慕容公子");
        set("nick","以彼之道 还施彼身");
	set("long", 
              "他就是天下号称以彼之道，还彼之身的姑苏慕容复。\n"
              "他脸上带着不可一世的笑容。\n");
        set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
       set("per", 30);
	
	set("max_qi", 3500);
	set("max_jing", 3000);
	set("neili", 13500);
	set("max_neili", 13500);
	set("jiali", 50);
	set("combat_exp", 2000000);
     set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
        set_skill("strike",170);
        set_skill("finger",170);
        set_skill("dodge",180);
        set_skill("force", 170);
	set_skill("canhe-zhi", 200);
	set_skill("murong-jianfa",250);       
        set_skill("shenyuan-gong", 250);
	set_skill("yanling-shenfa", 250);   
	set_skill("xingyi-zhang",250);
        set_skill("douzhuan-xingyi", 250);
	set_skill("parry", 180);
	set_skill("sword", 160);
	set_skill("literate", 250);
        set_skill("murong-daofa", 250);
        set_skill("blade",160);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");
        
        create_family("姑苏慕容",2,"弟子");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "dodge.yanling" :),                
                (: perform_action, "dodge.yanling" :),                
        }));
               	set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容复。\n",
                        "here" : "这里是大名鼎鼎的燕子坞，难道你没有听说过？\n",
                        "rumors" : "家父突染恶疾，我连他老人家最后一面都没见到，此事顶有蹊跷！\n",
                        "姑妈" : "我的姑妈住在曼佗罗山庄，那里有闻名天下的娘缳玉洞。\n",
                        "还施水阁" : (: ask_ge :),
                        "慕容博" : (: ask_bo :),
                        "领悟" : (: ask_book :),
                        "王语嫣" : (: ask_wang :),
                        "宝剑" : (: ask_sword :),
                       	"斗转星移"  : (: ask_skill :),
                        "归元丹" : (: ask_dan :),
//         "玉露清新散" : (: ask_dan1 :),
                        "图解" : (: ask_book2 :)
                ]));
        set("dan_count", 6);
       	set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 10);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
int count = 0;
void reset()
{
    count = 1 - count;
    if (count) return;
        set("dan_count", 6);
        set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 10);
}
void init()
{
        ::init();
        add_action("do_jiaoliang", "jiaoliang");
}
void attempt_apprentice(object ob)
{
if (ob->query_skill("parry", 1) < 100) {
		command("say 我姑苏慕容以彼之道、还施彼身对招架要求甚高，小兄弟似乎不宜学习。");
    command("say " + RANK_D->query_respect(ob) + "的功力不够，还是请回吧。");
		return;
	}

        if (ob->query_skill("shenyuan-gong", 1) < 100) {
		command("say 我姑苏慕容以彼之道、还施彼身对内功心法要求甚高，小兄弟似乎不宜学习。");
    command("say " + RANK_D->query_respect(ob) + "的功力不够，还是请回吧。");
		return;
	}

            command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 苍天在上，让我姑苏慕容又得一良材，为复兴我大燕多了一份力量。");
        command("chat 朗声说道：公子我又收一良材，大燕兴复指日可待啦！");
        command("chat* haha"); 
	command("recruit " + ob->query("id"));
	ob->set("title","姑苏慕容第三代弟子");
}

 

string ask_wang()
{
mapping fam;
// obiect ob;
        if (!fam = this_player()->query("family") || fam["family_name"] !="姑苏慕容")
        return RANK_D->query_respect(this_player()) +
        "与本派素无来往，不知此话从何谈起？";
        return "语嫣是我表妹，一直被姑妈管的很严，连我都很长时间没有见到她了。\n";
}

string ask_skill()
{
mapping fam; 
// object ob;
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
		return "斗转星移是我慕容家的绝学，最是注重招架和身法。\n";

}

string ask_ge()
{
mapping fam; 
// object ob
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
		return "还施水阁是我慕容收藏天下秘籍之所在，在我的书.....\n";
}

string ask_sword()
{
mapping fam; 
// object ob;
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
		return "碧玉剑是老爷子仙逝后的遗物，我让阿朱姑娘收起来好好保管！\n";
}

string ask_book()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
   if ( fam["master_name"] != "慕容博" && fam["master_name"] != "慕容复")
      	return RANK_D->query_respect(this_player()) + 
		"功力不够，何以谈及领悟？";

	if (  present("douzhuan xingyi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有斗转星移的武籍了嘛，怎么又来要了？ 真是贪得无餍！";

	if (query("book_count") < 1) return "对不起，斗转星移的武籍已经被别人要走了。";

	ob = new(__DIR__"obj/shu1");
	ob->move(this_player());

	add("book_count", -1);

	message_vision("$N得到一本斗转星移的武功秘籍。\n",this_player());
	return "好吧，看你为慕容家忠心耿耿，这本书就赐于你吧。";

}

string ask_book2()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
         if ( fam["master_name"] != "慕容博" && fam["master_name"] != "慕容复")
      	return RANK_D->query_respect(this_player()) + 
		"功力不够，何以谈及领悟？";
        if ( (int)this_player()->query_skill("douzhuan-xingyi",1)<50)
             return RANK_D->query_respect(this_player()) + 
		"功力不够，何以谈及领取图解？";
	if (  present("douzhuan xingyi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有斗转星移的武籍了嘛，怎么又来要了？ 真是贪得无餍！";

	if (query("book2_count") < 1) return "对不起，斗转星移的武籍已经被别人要走了。";

	ob = new(__DIR__"obj/shu2");
	ob->move(this_player());

	add("book2_count", -1);

	message_vision("$N得到一本斗转星移的武功秘籍。\n",this_player());
	return "好吧，看你为慕容家忠心耿耿，这本书就赐于你吧。";

}
 
string ask_dan()
{
	mapping fam; 
      object ob,me; 
               me = this_player();
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

      if ( (int)this_player()->query_condition("medicine" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

      if ( (int)this_player()->query("max_neili" ) < 400)
		return RANK_D->query_respect(this_player()) + 
		"功力不够，灵药多吃有害无宜，过段时间再来吧。";
           if ((int)me->query("max_neili") >= (int)me->query_skill("force")*10)
  return RANK_D->query_respect(this_player()) + "怎麽老想吃要呢,你武功已经不凡,去打坐提高修为吧.";
	if (  present("guiyuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";

	if (query("dan_count") < 1) return "对不起，归元丹已经被别人要走了。";

             ob = new("/clone/medicine/guiyuan-dan");
	ob->move(this_player());

	add("dan_count", -1);

	message_vision("$N获得一颗归元丹。\n",this_player());
	return "好吧，此丹集天下灵气于一身，你服后会功力大增，我就赐于你吧。";

}

string ask_dan1()
{
	mapping fam; 
        object ob,me;
me = this_player();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

        if ( (int)this_player()->query("max_neili" ) < 100)
		return RANK_D->query_respect(this_player()) + 
		"功力不够，灵药多吃有害无宜，过段时间再来吧。";

	if (  present("qingxin san", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";
	if (query("dan1_count") < 1) return "对不起，玉露清新散已经发完了";

	ob = new(__DIR__"obj/qingxin-san");
	ob->move(this_player());

	add("dan1_count", -1);

	message_vision("$N获得一颗玉露清新散。\n",this_player());
	return "好吧，此药集天下灵气于一身，你服后会功力大增，我就赐于你吧。";

}

string ask_bo()
{
        mapping fam; 
//        object ob;
	if ((int)this_player()->query_temp("marks/失败")) 
 return" 慕容复眼中发出两道寒光，直射" + this_player()->name() + "一字一字说道：已经较量过了，你怎麽还
不回去安心练功呢!";
		 
	 
         if (!(fam =this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
		return "你与本派素无来往，不知此话从何谈起？";
  
       if ((int)this_player()->query_temp("marks/bai_bo") && fam["master_name"] == "慕容博") 
         return "你已经是家父的弟子了，不用再向我学了!";

           this_player()->set_temp("marks/jiao", 1);
 return "慕容复眼中发出两道寒光，直射" + this_player()->name() + "一字一字说道：家父现在身处少林，那里
藏龙卧虎，你武功未成，最好不要去自去其辱，如果你有信心能接下我十招，就和我较量一下。(jiaoliang) ";
                
	 
}

int do_jiaoliang()
{
	object me, obj, jiaxin;
	int current_qi, count;

	me = this_object();
	obj = this_player();
        jiaxin = new("d/mr/obj/jiaxin");
	current_qi = (int)me->query("qi");

	say(obj->name() + "对慕容复说：好吧，那就让师傅指点几招 。\n");
             set("max_qi", 3500);
            set("jiali", 100);
             set("neili", 3500);
             set("max_neili", 3500);
             set("max_jing", 2000);
        if( obj->query_temp("marks/jiao") ) {
                obj->set_temp("marks/jiao", 0);
		count = 0;
		while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 30) { 
			if ( !present(obj, environment()) )
				return 1;
                        COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"));
			if (((int)me->query("qi")*100/current_qi)< 30 || ++count > 10) {
				say(
"慕容复对" + obj->name() + "说道： 不想我慕容世家又出良材，我这就写封家信， 你马上动身前去少林，\n"
"把它交给他老人家。希望你能不负众望，振兴慕容世家，光复大燕国。\n"
				);
      				jiaxin->move(obj);
				obj->set_temp("marks/bai_bo", 1);
			        message_vision("$N交给$n一封家信\n", me, obj);
				return 1;
			}
	                 COMBAT_D->do_attack(me, obj);
		}
	 	say(
"慕容复对着" + obj->name() + "冷冷说道：你武功未成，就好高务远,\n"
"你还是安心练功去吧!\n"
		);
               this_player()->set_temp("marks/失败", 1);
         }
	return 1;
} 
