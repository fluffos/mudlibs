// hong.c 洪安通

#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

string ask_du1();
int ask_du();
int ask_job();
int ask_fail();
int i;
void create()
{
	set_name("洪安通", ({ "hong antong", "hong" }));
	set("title",  HIY"神龙教"NOR"教主" );
	set("nickname", HIR "永享仙福" NOR);
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 65);
	set("int", 60);
	set("con", 60);
	set("dex", 68);

	set("max_qi", 18000);
	set("eff_qi", 18000);
	set("max_jing", 13000);
	set("eff_jing", 13000);
	set("neili", 18000);
	set("max_neili", 18000);
	set("jiali", 100);
	set("combat_exp", 9500000);
	set("score", 400000);

        set_skill("force", 250);
	set_skill("shenlong-xinfa", 380);
        set_skill("dodge", 200);
	set_skill("yixingbu", 380);
        set_skill("hand", 250);
	set_skill("shenlong-bashi", 380);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 380);
        set_skill("parry", 250);
set_skill("claw", 300);
set_skill("strike", 300);
set_skill("cuff", 320);
        set_skill("staff", 200);
        set_skill("sword", 300);
        set_skill("zhaosheshu", 380);
        set_skill("yangsheshu", 380);
	set_skill("shedao-qigong", 380);
	set_skill("literate", 200);
	set_skill("dulong-shenzhua", 380);
	set_skill("xuanming-zhang", 380);
  set_skill("qingshe-sword", 380);
	set_skill("diwangquan", 380);

        set_skill("leg",200);
        set_skill("shenlong-tuifa",380);
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shedao-bashi");
        map_skill("staff", "shedao-qigong");

	map_skill("strike", "xuanming-zhang");
	map_skill("claw", "dulong-shenzhua");
	map_skill("cuff", "diwangquan");
	prepare_skill("strike", "xuanming-zhang");
	prepare_skill("cuff", "diwangquan");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: command("zhaoshe") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.wanshe" :),
                (: perform_action, "strike.lang" :),
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.yingxiong" :),
                (: perform_action, "cuff.sanzhao" :),
                (: perform_action, "cuff.sheshen" :),
                (: perform_action, "cuff.superbashi" :),
                (: perform_action, "cuff.sxbb" :),
                      }) );
if (random(2)==0)
{
i=1;
        map_skill("sword", "qingshe-sword");
        map_skill("parry", "qingshe-sword");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: command("zhaoshe") :),
                (: perform_action, "sword.jiang" :),
                (: perform_action, "sword.psxf" :),
                (: perform_action, "sword.qscd" :),
                (: perform_action, "sword.slj" :),
                (: perform_action, "strike.lang" :),
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.yingxiong" :),
                (: perform_action, "cuff.sanzhao" :),
                (: perform_action, "cuff.sheshen" :),
                (: perform_action, "cuff.superbashi" :),
                (: perform_action, "cuff.sxbb" :),
                      }) );
}
	create_family("神龙教",1,"教主");

        set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"洪安通" :  "\n你不想活了是不是?\n",
		"教主" :  "\n我就是神龙教教主。\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
                "疗毒" : (: ask_du() :),
                "jiedu" : (: ask_du() :),
                "任务" : (: ask_job() :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
		"钓杆" : (: ask_du1 :),
		"diaogan" : (: ask_du1 :),
       ]) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);

	setup();
if (i==1)
{
        carry_object("/clone/box/baowu/48")->wield();
}
else
{
        carry_object("/d/baituo/obj/shenshezhang")->wield();
}
//	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say 我越看你越象白道派来卧底的。");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me);
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me);
                return 0;
        } else {
                command("say 我洪安通比起古往今来的圣人怎么样啊？");
                message_vision("洪安通微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
	return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说我什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "万年不老") >=0 && (strsrch(arg, "永享仙福") >=0
         || strsrch(arg, "寿与天齐") >=0 || strsrch(arg, "文武仁圣") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
			this_object()->set_leader(this_player());
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player());
        }
        return 1;
}

// 万年不老,永享仙福,寿与天齐,文武仁圣

void die()
{
message_vision("\n$N奇道：“咦,居然有人能杀了我,....”说完睁着两眼倒地死了。\n", this_object());
	::die();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_flatter", "flatter");
}

void greeting(object ob)
{
	object obj;
	return;
}

void attempt_apprentice(object ob)
{
    if (ob->query("party/party_name") != "神龙教" ) {
        command("say 你不是本教教众, 想来找死啊!");
	return;
    }
    if ((int)ob->query_skill("shenlong-xinfa",1) < 60 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
	return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 60 ) {
        command("say 你的本门杖法太低了,还是努努力先提高一下吧!");
	return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
	return;
    }
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
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

        if( me->query("family/family_name") != "神龙教")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "找42章经是很难的，你还是练高修为再来吧");
                return 1;
}
      if( (int)me->query_skill("shenlong-xinfa",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
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
                command("say 你连本钱都没有，我怎么放心要你去找42章经？");
                return 1;
        }

        if (me->query("kill_shenlong") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "能为我教出力，真是太好了。");
                command("say " + me->query("id") + " 42章经在『" + quest["short"]             + "』出现，快去吧！\n" NOR);
                me->set("kill_shenlong", 1);
                me->set("quest/quest_type", "寻");
                me->set("quest/quest", "42章经");
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

int ask_du()
{

        object me = this_player();
        if( me->query("family/family_name") != "神龙教")
           {
                      message_vision("$N对着$n大喝一声：你是哪来的奸细？\n", this_object(), me);
                      return 1;
            }
if (me->query_condition("chanchu_poison"))
{
me->clear_condition("chanchu_poison");
command("say 你的蟾蜍毒我帮你冶好了.");
}
else if (me->query_condition("wugong_poison"))
{
me->clear_condition("wugong_poison");
command("say 你的蜈蚣毒我帮你冶好了.");
}
else if (me->query_condition("snake_poison"))
{
me->clear_condition("snake_poison");
command("say 你的蛇毒我帮你冶好了.");
}
else if (me->query_condition("ice_poison"))
{
me->clear_condition("ice_poison");
command("say 你的寒冰绵掌伤我帮你冶好了.");
}
else if (me->query_condition("juehu_hurt"))
{
me->clear_condition("juehu_hurt");
command("say 你的绝户手伤我帮你冶好了.");
}
else     command("say 你身上没有我能冶的毒.");
            command("say 好了，就这样吧.");
                return 1;
}

int ask_fail()
{
        object me = this_player();

        if (me->query("kill_shenlong") == 1) {
                command("sigh");
                command("say 你这身手也来找42章经!");
                me->delete("kill_shenlong");
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
   if(obj->query("id") == "42jing shu" && me->query("kill_shenlong") == 1
   && obj->query("byname") ==me->query("name"))
   {
       command("nod "+(string)me->query("id"));
       command("say 干得好！\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 我要钱干什么?");
       return 0;
       }
//   if(me->query("kill_shenlong") == 0 ){
//       command("hehe "+(string)me->query("id"));
//       command("say 不错啊，但这活我没叫你干啊。");
//       return 1;
//       }
//   else return 0;
}

void destroying(object obj, object ob, object me)
{
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 15;
if (kar >300) kar=300;
if (kar <150) kar=150;
   exp = 520 + kar;
   pot = 480 + random(kar);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！我就指点你两手功夫吧.\n"NOR,ob, me);
                  message_vision(HIC "\n由于$N成功的找回42章经，被奖励：\n"
                + chinese_number(exp) + "点实战修为，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(50) + "点评价作为答谢。\n" NOR, me);
 destruct(present("42jing shu",ob));
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_shenlong");
   return;
}
string ask_du1()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "神龙教")
		return RANK_D->query_respect(this_player()) +
		"与本教素无来往，不知此话从何谈起？";
	if (this_player()->query_temp("sld"))
		return "我刚给过你这种东西了。";

	ob = new(__DIR__"obj/diaogan");
	ob->move(this_player());
	this_player()->set_temp("sld",1);
	return "好吧，那你就先用这把钓杆吧。";
}