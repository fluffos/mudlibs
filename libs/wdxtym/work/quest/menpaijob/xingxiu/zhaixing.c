// zhaixing.c 摘星子
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();

string ask_me();
string ask_book();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "星宿派大师兄");
	set("long", 
		"他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
		"他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 5700);
	set("max_jing", 5700);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 30);
	set("combat_exp", 500000);
	set("score", 40000);

	set_skill("force", 170);
	set_skill("huagong-dafa", 150);
	set_skill("throwing", 170);
	set_skill("feixing-shu", 180);
	set_skill("dodge", 170);
	set_skill("zhaixinggong", 200);
	set_skill("strike", 180);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 180);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 170);
	set_skill("poison", 170);
	set_skill("staff", 170);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"炼心弹"    : (: ask_me :),
		"秘籍"      : (: ask_book :),
		"天山器法"  : (: ask_book :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                "抢劫" : (: ask_job() :)
	]));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("dan_count") < 1)
		return "你来晚了，没有练心弹了。";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "这些练心弹够你用的了吧。";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "好吧，这本书你拿回去好好看看吧。";
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
                me->add("potential",-50);
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
   if(me->query_temp("xxjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say 你任务怎么做的，杀了几个敌人？");
       return 0;
       }
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

   exp = 620 + kar;
   pot = 520 + random(kar);

   if(obj) destruct(obj);
//   if(ob) destruct(ob);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
                me->apply_condition("guojob2_busy",10);
                me->apply_condition("huang_busy",10);
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
                me->delete("kill_xingxiu");
                me->delete_temp("xxjob2");
   message_vision(HIM"$N说完就把商人身上的钱财，搜了出来，然后把商人关进了后面的山洞......\n"NOR,ob);
   return;      
}