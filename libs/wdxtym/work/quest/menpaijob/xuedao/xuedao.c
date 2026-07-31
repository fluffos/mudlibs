// /kungfu/class/xueshan/xuedao.c  血刀老祖
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_girl();

int ask_job();
int ask_fail();
string ask_for_quit();
void create()
{
        set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
        );
        set("title",HIR"血刀门第四代掌门"NOR);
        set("gender", "男性");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 999);
        set("int", 999);
        set("con", 999);
        set("dex", 999);
        set("max_qi", 10000000);
        set("max_jing", 10000000);
        set("neili", 10000000);
        set("max_neili", 10000000);
        set("jiali", 1000);
        set("combat_exp", 100000000);
        set("score", 180000);

        set_skill("lamaism", 9999);
        set_skill("literate", 9999);
        set_skill("force", 9999);
        set_skill("parry", 9999);
        set_skill("blade", 9999);
        set_skill("sword", 9999);
        set_skill("dodge", 9999);
        set_skill("longxiang", 9999);
        set_skill("shenkong-xing", 9999);
        set_skill("hand", 9999);
        set_skill("cuff", 9999);
        set_skill("yujiamu-quan", 9999);
        set_skill("dashou-yin", 9999);
        set_skill("mingwang-jian", 9999);
        set_skill("xue-dao", 9999);
        set_skill("xiangmo-chu", 9999);
        set_skill("magic", 9999);
        set_skill("kwan-yin-spells", 9999);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");


if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
	set("inquiry", ([
                "美女" : (: ask_job() :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                "还俗"  :  (: ask_for_quit :),
		"水笙": (: ask_girl :),
	]) );
        set("chat_chance", 2);
	set("chat_msg", ({
"血刀老祖抬起头，若有所思的自言自语：“月亮快圆了，得下山杀个人祭祭刀了。”\n",
"血刀老祖恨恨的说：“什么时候再入中原，再闹个天翻地覆！”\n",
"血刀老祖咬牙切齿，眼露凶光的说：“下次来个斩草除根，一个活口也不留！”\n",
"血刀老祖自言自语道：“年纪大了，体力可一点也不含糊。”言下甚为得意。\n",
}) );

        create_family("雪山寺", 2, "弟子");
        set("class", "bonze");

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);


        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "雪山寺")
        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本门弟子，还是请回吧！\n");
                return;
        }
        if ((int)ob->query("shen") > -100000)
        {
                command("say 你是不是向着侠义道，连杀人都不会！\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 60)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "血刀门第五代弟子" NOR);
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
      if( (int)me->query_skill("longxiang",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }

        if( me->query("family/family_name") != "雪山寺")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "找美女的事没那么容易，你还是练高修为再来吧");
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

        if (me->query("kill_xueshan") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "和我志同道合，嘿嘿嘿。");
                command("say " + me->query("id") + " 听说在『" + quest["short"]             + "』附近有个绝世美女，快去吧！\n" NOR);
                me->set("kill_xueshan", 1);
                me->set("quest/quest_type", "抢");
                me->set("quest/quest", "绝世美女");
                me->set("task_time", time() + 310);
                me->apply_condition("menpai_busy",8);
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
        
        if (me->query("kill_xueshan") == 1) {
                command("pk");
                command("say 你害得我没有美女玩,坏我练功大事.");
                me->apply_condition("menpai_busy",8);
me->delete("kill_xueshan");
                return 1;
                }
}



int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(obj->query("id") == "mei nu" && me->query("kill_xueshan") == 1 && me->query_temp("xsjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say 你任务怎么做的，杀了几个敌人？");
       return 0;
       }
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }
  
   if(obj->query("id") == "mei nu" && me->query("kill_xueshan") == 1
   && obj->query_temp("owner/id") == me->query("id"))
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
	if (!me->query("szj/passed")
	 || me->query("szj/over200")
	 || !me->query_temp("szj/shui")
	 || (string)obj->query("id") != "shui sheng")
		return 0;

	me->delete_temp("szj");
        message("vision", me->name() + "给血刀老祖一位水笙。\n", environment(me), ({me}));
	command("pat " + me->query("id"));
        call_out("starting", 1, me, this_object(), obj);
        return 1;

//   if(me->query("kill_xueshan") == 0 ){
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
   kar = random(me->query("kar")) * 7;
if (kar >300) kar=300;
   exp = 600 + kar;
   pot = 500 + random(kar);


   if(obj) destruct(obj);
//   if(ob) destruct(ob);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIR"$N对$n说道：你这次做得极为出色！我就指点你两手吸阴补阳的奇功吧.\n"NOR,ob, me);
                  message_vision(HIC "\n由于$N成功的抢回了美女，被奖励：\n"
                + chinese_number(exp) + "点实战修为，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(50) + "点评价作为答谢。\n" NOR, me);
                me->add("combat_exp", exp );
                me->add("potential", pot );
                me->add("score",50);
                me->add("shen",-200);
                me->delete("quest");
                destruct(present("mei nu",ob));
                me->apply_condition("guojob2_busy",10);
                me->apply_condition("huang_busy",10);
 me->delete_temp("xsjob2");
                me->delete("kill_xueshan");
   message_vision(HIM"$N说完就把美女关进了后面的山洞......\n"NOR,ob);
   return;      
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "雪山寺")) 
        return ("你和雪山寺没有渊源，我不敢给你还俗。\n");
    if (me->query("combat_exp")< 1000000)
        return ("你就这点本事，我可不敢给你还俗。\n");

    if ((int)me->query_skill("lamaism", 1) < 180) 
                command("say 你修习的密宗心法不足,我可不敢给你还俗。");

    if ((int)me->query_skill("longxiang", 1) < 180) 
                command("say 你修习的龙象般若功不足,我可不敢给你还俗。");

    if (me->query("combat_exp")< 1000000)
        return ("你就这点本事，我可不敢给你还俗。\n");

    if( (string)me->query("class")!="bonze" )
        return "你已经是俗家人了。\n";

        command ("say 你一心要还俗，看来和我是同道中人。\n");
        command ("haha");
        command ("say 以后昨们有酒同吃，有女人一起。。。。。。\n");
        me->set("class", "xueshan");
}
int ask_girl()
{
	if (this_player()->query("shen") > 0) {
		command("say 老子最不喜欢和侠义人士结交，你走吧！");
		return 1;
	}
	command("say 听说水岱的女儿水笙长得挺标致的，我倒挺想见识见识。");
	command("say 她最好好象和花铁干在一起，你去把她帮我带来，怎么样？");
	command("say 你尽管放心，我是不会伤害她的。");
	this_player()->set_temp("szj/shui", 1);
	return 1;
}


void starting(object me, object ob, object obj)
{
	obj->revive(1);
	obj->reicarnate();
	obj->set("neili", obj->query("max_neili"));
	obj->set("eff_qi", obj->query("max_qi"));
	obj->set("qi", obj->query("max_qi"));
	obj->set("eff_jing", obj->query("max_jing"));
	obj->set("jing", obj->query("max_jing"));
	message_vision(HIW"$n身子动了动，口中呻吟了几声，清醒过来。\n"NOR, me, obj);
	command("grin " + obj->query("id"));
	message_vision(HIC"$n上下打量着水笙，双眼渐渐变得迷乱。\n"NOR, me, ob);
	message_vision(HIC"$n突然色性大发，一把搂住水笙，便想去扯她衣衫。\n\n"NOR, me, ob);
	me->start_busy(100);
	call_out("story1", 3, me, ob, obj);
}

void story1(object me, object ob, object obj)
{
	object room, shui, lu, liu, hua;
	room = load_object("/d/xuedao/nroad3");
	if (!objectp(shui=present("shui dai", room)) || !objectp(lu=present("Lu tianshu", room))) {
		call_out("finish", 1, me, ob, obj);
		return;
	}
	room = load_object("/d/xuedao/sroad3");
	if (!objectp(liu=present("liu chengfeng", room))) {
		call_out("finish", 1, me, ob, obj);
		return;
	}
	room = load_object("/d/xuedao/nroad6");
	if (!objectp(hua=present("Hua tiegan", room))) {
		call_out("finish", 1, me, ob, obj);
		return;
	}
	message_vision(HIW"有人长声叫道：“血刀僧，你放下我女儿，咱们两下罢休，否则你便逃到天边，我也追你到天边。”\n"NOR, me);
	message_vision(HIW"又听得四个人的声音齐声叫道：“落花流水兮——水流花落！落花流水兮——水流花落！”\n"NOR, me);
	message_vision(HIC"四人嗓音各自不同，或苍老，或雄壮，或悠长，或高亢，但内力之厚，各擅胜场。”\n"NOR, me);
	command("say 这四个家伙居然找来了，你躺着别作声，敌人功夫很强。\n");
	call_out("story2", 2, me, ob, obj, shui, lu, liu, hua);
}

void story2(object me, object ob, object obj, object shui, object lu, object liu, object hua)
{
	shui->move("/d/xuedao/shandong3");
	lu->move("/d/xuedao/shandong3");
	liu->move("/d/xuedao/shandong3");
	hua->move("/d/xuedao/shandong3");
	shui->kill_ob(ob);
	lu->kill_ob(ob);
	liu->kill_ob(ob);
	hua->kill_ob(ob);
	ob->kill_ob(shui);
	ob->kill_ob(lu);
	ob->kill_ob(liu);
	ob->kill_ob(hua);
	call_out("checking", 2, me, ob, obj);
}

void checking(object me, object ob, object obj)
{
	if (!ob) {
		me->start_busy(1);
		return;
	}
	if (present("shui dai", environment(me))
	 || present("Lu tianshu", environment(me))
	 || present("liu chengfeng", environment(me))
	 || present("Hua tiegan", environment(me))) {
		call_out("checking", 1, me, ob, obj);
		return;
	}
	message_vision(HIY"$n战罢四大高手，元气已然大伤，担心水笙会对自己不利，
于是心一横，顺手挥刀便向水笙颈中砍下。\n"NOR, me, ob);
	me->set_temp("szj/wait_baohu", 1);
	me->start_busy(1);
}

void finish(object me, object ob, object obj)
{
	message_vision(HIY"$n大喝：我就是死了也不会让你得逞的，说完，一头撞向石壁。\n"NOR, me, obj);
	obj->die();
	me->start_busy(1);
}
