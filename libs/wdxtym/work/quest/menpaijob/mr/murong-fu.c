 // /u/beyond/mr/npc/murong-fu.c  慕容复
// this is made by beyond
// update 1997.6.23
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
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
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
       set("per", 30);
	
	set("max_qi", 13500);
	set("max_jing", 13000);
	set("neili", 33500);
	set("max_neili", 33500);
	set("jiali", 50);
	set("combat_exp", 8000000);
        set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",280);
        set_skill("force", 170);
	set_skill("canhe-zhi", 380);
	set_skill("murong-jianfa",260);       
        set_skill("shenyuan-gong", 280);
	set_skill("yanling-shenfa", 320);   
	set_skill("xingyi-zhang",280);
        set_skill("douzhuan-xingyi", 280);
	set_skill("parry", 280);
	set_skill("sword", 260);
	set_skill("literate", 250);
        set_skill("murong-daofa", 280);
        set_skill("blade",260);
        
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
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixing" :),
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
                        "图解" : (: ask_book2 :),
                "任务" : (: ask_job() :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                ]));
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
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

	ob = new("d/mr/npc/obj/shu1");
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

	ob = new("d/mr/npc/obj/shu2");
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

             ob = new("/d/mr/obj/guiyuan-dan");
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

	ob = new("d/mr/npc/obj/qingxin-san");
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

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if( me->query("family/family_name") != "姑苏慕容")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "找大燕传国玉玺是很难的，你还是练高修为再来吧");
                return 1;
}
    if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
                      return 1;
            }
      if( (int)me->query_skill("shenyuan-gong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你连本钱都没有，我怎么放心要你去找大燕传国玉玺？");
                return 1;
        }

        if (me->query("kill_mr") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "能为大燕出力，真是太好了。");
                command("say " + me->query("id") + " 大燕传国玉玺在『" + quest["short"]             + "』出现，快去吧！\n" NOR);
                me->set("kill_mr", 1);
                me->set("quest/quest_type", "寻");
                me->set("quest/quest", "大燕传国玉玺");
                me->set("task_time", time() + 310);
                me->apply_condition("menpai_busy",8);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                 me->start_busy(3);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_mr") == 1) {
                command("sigh");
                command("say 你这身手也来找宝物!");
                me->delete("kill_mr");
                 me->delete("kill_mr");
                me->apply_condition("menpai_busy",6);
                return 1;
                }
}



int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }
   if(obj->query("id") == "mr yuxi" && obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 我要钱干什么?");
       return 0;
       }
   if(me->query("kill_mr") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say 不错啊，但这活我没叫你干啊。");
       return 1;
       }

   if(obj->query("id") == "mr yuxi" &&  obj->query("byname") !=me->query("name")) {
       command("pat " + me->query("id"));
       command("say 这不是你找的吧！");
       return 1;
       }

   if(obj->query("id") == "mr yuxi" && me->query("kill_mr") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say 干得好！\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 15;
if (kar >300) kar=300;
if (kar <150) kar=150;
   exp = 480 + kar;
   pot = 400 + random(kar);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！我就指点你两手功夫吧.\n"NOR,ob, me);
                  message_vision(HIC "\n由于$N成功的找回大燕传国玉玺，被奖励：\n"
                + chinese_number(exp) + "点实战修为，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(50) + "点评价作为答谢。\n" NOR, me);
destruct(present("mr yuxi",ob));
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_mr");
   return;      
}