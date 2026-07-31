// ding.c 丁春秋
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();


string ask_me();
string ask_du1();
string ask_du2();
string ask_du3();
string ask_du4();
string ask_du5();
void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", "星宿老怪");
	set("long", 
		"他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
		"可是他看起来形貌清奇，仙风道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 14000);
	set("max_neili", 14000);
	set("max_neili", 14000);
	set("jiali", 100);
	set("combat_exp", 2500000);
	set("score", 400000);

	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("huagong-dafa", 300);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 300);
	set_skill("dodge", 200);
	set_skill("zhaixinggong", 300);
	set_skill("strike", 200);
	set_skill("chousui-zhang", 300);
	set_skill("claw", 200);
	set_skill("sanyin-wugongzhao", 300);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("poison", 300);
	set_skill("tianshan-zhang", 300);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.zhaohuo" :),                
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
                (: perform_action, "strike.zhaohuo" :),
        }) );
	set("book_count", 1);
	set("zhen_count", 8);
	set("san_count", 3);
	set("wx_count", 6);
	set("xcs_count", 4);
	set("inquiry", ([
		"毒经" : (: ask_me :),
		"星宿毒经" : (: ask_me :),
		"碧磷针" : (: ask_du1 :),
		"三笑逍遥散" : (: ask_du2 :),
		"逍遥三笑散" : (: ask_du2 :),
		"无形散" : (: ask_du3 :),
		"雪蚕丝" : (: ask_du4 :),
		"铜钹" : (: ask_du5 :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                "抢劫" : (: ask_job() :)
	]));

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);


	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");

	setup();
//      carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }
        if ((int)me->query("combat_exp") < 10000) {
                command("say 你这点微末道行如何能学到老仙的神妙功夫。");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一副等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说老仙什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// 星宿老仙，德配天地，威震寰宇，古今无比

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "好吧，这本「星宿毒经」你拿回去好好钻研。";
}
string ask_du3()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<50)
		return "你的毒技火候未到，用不了这种东西。";
	if (this_player()->query_temp("xxi3"))
		return "我刚给过你这种东西了。";

	if (query("wx_count") < 1)
		return "你来晚了，无形散都发完了。";
	add("wx_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/wuxing");
	ob->move(this_player());
	this_player()->set_temp("xxi3",1);
	return "好吧，那你就先用这个无形散吧。";
}

string ask_du4()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<50)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("xcs_count") < 1)
		return "你来晚了，雪蚕丝都发完了。";
	if (this_player()->query_temp("xxi4"))
		return "我刚给过你这种东西了。";

	add("xcs_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/xuecan-si");
	ob->move(this_player());
	this_player()->set_temp("xxi4",1);
	return "好吧，那你就先用这些雪蚕丝吧。";
}
string ask_du5()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_temp("xxi5"))
		return "我刚给过你这种东西了。";

	ob = new("/d/xingxiu/npc/jobobj/tongbo");
	ob->move(this_player());
	this_player()->set_temp("xxi5",1);
	return "好吧，那你就先用这个铜钹吧。这是本门必修之课";
}

string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<50)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("zhen_count") < 1)
		return "你来晚了，碧磷针都发完了。";
	if (this_player()->query_temp("xxi1"))
		return "我刚给过你这种东西了。";

	add("zhen_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/blzhen");
	ob->move(this_player());
	this_player()->set_temp("xxi1",1);
	return "好吧，那你就先用这些针吧。";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("san_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	if (this_player()->query_temp("xxi2"))
		return "我刚给过你这种东西了。";

	add("san_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/sanxiao");
	this_player()->set_temp("xxi2",1);
	ob->move(this_player());
	return "好吧，这包毒药你拿回去善加利用吧。";
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

        if( me->query("family/family_name") != "星宿派")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

      if( (int)me->query_skill("huagong-dafa",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "抢商人的事没那么容易，你还是练高修为再来吧");
                return 1;
}
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
                      return 1;
            }
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你的潜能太少了.找不到什么好货!!");
                return 1;
        }

        if (me->query("kill_xingxiu") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "和我志同道合，有财大家一起发。");
                command("say " + me->query("id") + " 听说在『" + quest["short"]             + "』附近有个富商路过，快去吧！\n" NOR);
                me->set("kill_xingxiu", 1);
                me->set("quest/quest_type", "抢");
                me->set("quest/quest", "富商");
                me->set("task_time", time() + 310);
                me->apply_condition("menpai_busy",7);
                ob = new(__DIR__"meinv",1);
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
        
        if (me->query("kill_xingxiu") == 1) {
                command("pk1");
                command("say 你害得富商没抓到,坏我派发展大事,扣你150点POT.");
                me->delete("kill_xingxiu");
                me->apply_condition("menpai_busy",6);
//                call_out("delete", 1);
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
   if(obj->query("id") == "fu shang" && obj->query_temp("owner/id") != me->query("id")){
       command("consider "+(string)me->query("id"));
       command("say 我不是叫你抓这个人的!");
       return 0;
       }

   if(obj->query("id") == "fu shang" && me->query("kill_xingxiu") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say 嘿嘿.干得好！\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 我要钱干什么?");
       return 0;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 7;
if (kar >300) kar=300;
   exp = 550 + kar;
   pot = 450 + random(kar);

   if(obj) destruct(obj);
//   if(ob) destruct(ob);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIR"$N对$n说道：你这次做得极为出色！我就指点你两手本门的奇功吧.\n"NOR,ob, me);
                  message_vision(HIC "\n由于$N成功的抢到了商人，被奖励：\n"
                + chinese_number(exp ) + "点实战修为，\n"
                + chinese_number(pot ) + "点潜能，\n"
                + chinese_number(50) + "点评价作为答谢。\n" NOR, me);
                me->add("combat_exp", exp );
                me->add("potential", pot );
                me->add("score",50);
                me->add("shen",-200);
                me->delete("quest");
                destruct(present("fu shang",ob));
                me->apply_condition("guojob2_busy",10);
                me->apply_condition("huang_busy",10);
                me->delete("kill_xingxiu");
   message_vision(HIM"$N说完就把商人身上的钱财，搜了出来，然后把商人关进了后面的山洞......\n"NOR,ob);
   return;      
}