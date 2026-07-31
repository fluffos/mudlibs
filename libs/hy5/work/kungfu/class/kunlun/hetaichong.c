// hetaichong.c (kunlun)
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();
string ask_su();
int ask_job();
int ask_fail();
#include "/quest/givegift.c"

void create()
{
	set_name("何太冲", ({ "he taichong", "he" }));
	set("title", "昆仑派掌门");
	set("nickname", "铁琴先生");
	set("long",
		"他就是昆仑派掌门、名扬江湖的铁琴先生何太冲。\n"
		"虽然年纪已大，但仍然看得出他年轻时英俊潇洒。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 55);
	set("int", 55);
	set("con", 55);
	set("dex", 55);

	set("max_qi", 22500);
	set("max_jing", 22000);
	set("neili", 43000);
	set("max_neili", 43000);
	set("jiali", 50);
	set("combat_exp", 8200000);
	set("score", 40000);

	set_skill("taiji-shengong", 180);
	set_skill("art", 280);
	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 320);
	set_skill("dodge", 240);
	set_skill("taxue-wuhen", 320);
	set_skill("strike", 320);
	set_skill("kunlun-zhang", 320);
	set_skill("parry", 265);
	set_skill("sword", 275);
	set_skill("liangyi-jian", 325);
	set_skill("xunlei-jian", 325);
	set_skill("mantian-huayu", 325);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-quan", 320);
set_skill("qixian-jian", 320);
	set_skill("goplaying", 280);
	set_skill("luteplaying", 280);

        set_skill("finger", 180);
	set_skill("hand", 180);	
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),            			
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
(: perform_action, "strike.yixing" :),  
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );

	create_family("昆仑派", 4, "掌门人");
	set("class", "taoist");

	set("inquiry",
		([
			"心法" : (: ask_me :),
			"苏习之" : (: ask_su :),
			"追杀" : (: ask_ding :),
		                "任务" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                "job" : (: ask_job() :),
                "fail" : (: ask_fail() :),

		]));
		

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object("/d/kunlun/obj/sword.c")->wield();
	carry_object("/d/kunlun/obj/pao2.c")->wear();
}

void attempt_apprentice(object ob)
{
/*	 if((int)ob->query("shen")<0){
	 command("say 我昆仑乃是堂堂名门正派，"+RANK_D->query_respect(ob)+
				"的品德实在令人怀疑。");
	 command("say "+RANK_D->query_respect(ob)+
				"还是先回去做点善事吧。");
	 return;
	 }
*/
	 if(ob->query("gender")=="女性"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"老夫可不敢收女弟子，你去找我夫人去吧。");
	 return;
	 }

//          if(ob->query("appren_hezudao", 1) == 1) {
//	 command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
//	 return;
//	 }
    
	if(ob->query_skill("xuantian-wuji",1)<100){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"你的玄天无极功太差，我可不想收你。");
	 return;
	 }
	 command("say 好吧，我便收下你，只是你投入我门下之后，须得安心学艺。");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		  if (query("book_count") < 1)
					 return "你来晚了，本派心经已被你师兄拿走了。";
//          if(ob->query("gender")!="女性"||ob->query("per")<23)
//        	     	 return "本派心经不在我这里。";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "我这里有本「心法」，是有关吐呐吸气的，你拿回去好好钻研，有空多来找我哦";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		
		 if(this_player()->query_skill("mantian-huayu",1) < 60)
           return "你如此自愿为师门效力，不枉我平时一番栽培，速速去吧";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有吗，怎么又来要了？";
		  if (query("ding_count") < 1)
					 return "丧门钉已给了我派去追杀苏习之的人，你就不用去了。";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "你如此自愿为师门效力，不枉我平时一番栽培，这把丧门钉你就拿去吧。";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "昆仑派")
					 return RANK_D->query_respect(this_player()) +
					 "与本派素无来往，不知此话从何谈起？";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "你还待在这里做什么，还不快去追苏习之";
		  return "苏习之这家伙竟然敢偷看本派的两仪神剑，我派弟子必当将其追杀。";
}

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/quest/where")->query_quest();

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

        if( me->query("family/family_name") != "昆仑派")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "你还是练高经验再来吧");
                return 1;
}
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("何太冲对着$N摇了摇头说：你等会再来!\n", me);
                      return 1;
            }

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
                      return 1;
            }
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你连本钱都没有，我怎么放心要你去找治我爱妾病的药？");
                return 1;
        }
      if( (int)me->query_skill("xuantian-wuji",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }

        if (me->query("kill_kunlun") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "如果能找回治我爱妾病的药，我好好好谢谢你的。\n");
                command("say " + me->query("id") + "本派叛徒带着药在『" + quest["short"]  + "』出现，快去吧！\n");
                me->set("kill_kunlun", 1);
                me->set("quest/quest_type", "寻");
                me->set("quest/quest", "奇药");
                me->set("task_time", time() + 310);
me->apply_condition("menpai_busy",8);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
        ob->set("qi", me->query("max_qi")* 4 / 5);
        ob->set("eff_qi", me->query("max_qi")* 4 / 5);
        ob->set("max_qi", me->query("max_qi")* 4 / 5);
        ob->set("jing", me->query("max_jing")* 4 / 5);
        ob->set("eff_jing", me->query("max_jing")* 4 / 5);
        ob->set("max_jing", me->query("max_jing")* 4 / 5);
        ob->set("neili", me->query("neili")* 4 / 5);
        ob->set("max_neili", me->query("max_neili")* 4 / 5);
                
                ob->set("force_factor", random(10));   
me->start_busy(3);
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_kunlun") == 1) {
                command("sigh");
                command("say 唉，我爱妾的病....扣你80点POT.");
                me->apply_condition("menpai_busy",6);
me->delete("kill_kunlun");
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
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 我要钱干什么?");
       return 0;
       }
   if(obj->query("byname") !=me->query("name")) {
       command("pat " + me->query("id"));
       command("say 这包药不是你找的吧！");
       return 1;
       }

   if(me->query("kill_kunlun") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say 不错啊，但这活我没叫你干啊。");
       return 1;
       }
       if(ob->is_busy())
{
       //command("pat " + me->query("id"));
       command("say 我正在忙！");
       return 0;
       }    
   if(obj->query("id") == "qi yao" && me->query("kill_kunlun") == 1 && !ob->is_busy())
   {
   	ob->start_busy(2);
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
   kar = random(me->query("kar")) * 10;
if (kar >600) kar=600;
if (kar <150) kar=150;
   exp = 550 + kar;
   pot = 380 + random(kar);
   if(obj) destruct(obj);
/*
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！我就指点你两手功夫吧.\n"NOR,ob, me);
exp=exp/2+88;
addnl(me,"exp",exp);

                me->add("score",50);
                me->delete("quest");
                me->delete("kill_kunlun");
                destruct(present("qi yao",ob));
*/
   return;      
}