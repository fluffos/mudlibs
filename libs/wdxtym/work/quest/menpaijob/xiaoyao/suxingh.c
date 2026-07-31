// suxingh.c
// shilling 97.2
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
mixed names = ({
        ({
        "xiangzhong","dongxian_ge","maipo_tang","bosi_xiaoqu","xiaoao_jianghu",
        "shanpo_yang","dielian_hua","caisang_zi","wusu_nian","dongxian_ge",
        "san_tai","yujie_xing","zuichui_bian","shuidiao_getou","yuanyuan_qu",                
        "wanghai_chao","wenshi_jian","yinma_changcheng","chunjiang_huayueye","jiangjin_jiu", 
        "yu_meiren","baixue_ge",
        }),
        ({
         "宋兵","流氓","偏将","裨将","佐将","小贩","男孩","郭芙","老先生",
		 "小孩","书店老板","武三通","穷汉","铁匠","朱子柳","店小二","宋兵",
		 "静玄师太","静照师太","宋远桥","莫声谷","陆乘风","韩宝驹","黄药师","余沧海",
		 "殷野王","胡青牛","尹志平","小龙女","刘承风","欧阳锋","白衣少女","九翼道人",
		 "阿紫","玉磬子","玉音子","岳夫人","岳不群","令狐冲","玄苦大师","清善比丘",
		 "独臂神尼","庄夫人","双儿","吴六奇","木婉清","萧远山","李沅芷","向问天",
		 "曲洋","黑白子","程瑶迦","程瑶迦","沐剑屏","天柏道人","本尘","本观",
		 "天山童姥","韦一笑","谢逊","澄坚","陆乘风","张翠山","宋青书","玄贞道长",
		 "石破天","苏星河","逍遥子","朱丹臣","简长老","封不平",
        }),
        });

int ask_job();
int ask_fail();
string ask_me();
string ask_lian();
string ask_book();
string ask_book2();
void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聪辩老人");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 55);
	set("con", 50);
	set("int", 55);
	set("dex", 55);
	set("per", 50);

	set("no_clean_up",1);

	set("long",
"此人就是号称聪辩老人的苏星河，据说他能言善辩， \n"
"是一个武林中的智者，而他的武功也是无人能知。\n");

	set("combat_exp", 6500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"秘密地道" :(:ask_me:),
		"秘籍"     :(:ask_book:),
		"练琴"     :(:ask_lian:),
		"曲谱"     :(:ask_book2:),
                "任务" : (: ask_job() :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
	]) );

	set("max_qi", 15400);
	set("max_jing", 11400);
	set("neili", 39500);
	set("max_neili",39500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("blade", 250);
	set_skill("strike", 250);
	set_skill("sword", 250);
	set_skill("hand", 250);
	set_skill("qingyun-shou", 280);
	set_skill("panyang-zhang", 280);
	set_skill("liuyue-jian", 280);


	set_skill("lingboweibu", 280);
	set_skill("beiming-shengong", 280);
	set_skill("ruyi-dao", 300);
	set_skill("liuyang-zhang", 280);
	set_skill("zhemei-shou", 280);
	set_skill("literate", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),             
	}) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);
	create_family("逍遥派", 2, "弟子");
	set("title","逍遥派第二代大弟子");
	setup();
	carry_object("d/xiaoyao/npc/obj/cloth")->wear();
	carry_object("d/xiaoyao/npc/obj/blade")->wield();
}


void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在学问上多下点功夫？");
 return;
 	}

	command("say 好吧，我就收下你了，今后要多加努力啊！");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要秘籍就得加入逍遥派。";
	}
	command("sigh");
	return"本派的武功秘籍藏在一个很秘密的地方，我也没去过。";
}
string ask_lian()
{
	object me,ob,ob1;
      string where;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"你非我派弟子，不用学什么琴艺！";
	}
if (ob->query_temp("singsong"))
	  return    HIW"我不是叫你去。\n"+
           "          练习(chang)。\n"+
           "          一下"+ob->query_temp("singsong")+"这首歌吗?"NOR; 


	  where=names[0][random(22)];
	  ob->set_temp("singsong",where);
	command("nod");
	  return    HIC"我们逍遥派，讲究琴棋书画。\n"+
           "          你拿本曲谱去练习(chang)。\n"+
           "          一下"+where+"这首歌吧。"NOR; 
}

string ask_book2()
{
	object me,ob,ob1;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要曲谱就得加入逍遥派。";
	}
	if (this_player()->query_temp("xys"))
		return "我刚给过你这种东西了。";

	command("nod");
	ob1 = new("/quest/menpaijob/xiaoyao/newjob/qupu");
	ob1->move(this_player());
	this_player()->set_temp("xys",1);

	return"这本曲谱你拿去用吧。";
}

string ask_me()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要知道密道就得加入逍遥派。";
	}
	command("sigh");
	return"本派的密道在华山之上，很是艰险。你有兴趣可以去看看。";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
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

        if( me->query("family/family_name") != "逍遥派")
           {
                      message_vision("$N对着$n大喝一声：本派弟子才能做任务。你是哪来的奸细？\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "找本派的掌门信物是很难的，你还是练高修为再来吧");
                return 1;
}
      if( (int)me->query_skill("beiming-shengong",1) < 50)
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
                command("say 你连本钱都没有，我怎么放心要你去找本派的掌门信物？");
                return 1;
        }

        if (me->query("kill_xiaoyao") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "能为逍遥派出力，真是太好了。");
                command("say " + me->query("id") + " 七宝指环在在『" + quest["short"]             + "』出现，快去吧！\n" NOR);
                me->set("kill_xiaoyao", 1);
                me->set("quest/quest_type", "寻");
                me->set("quest/quest", "七宝指环");
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
        
        if (me->query("kill_xiaoyao") == 1) {
                command("sigh");
                command("say 你这身手也来找本派的七宝指环!");
                me->apply_condition("menpai_busy",12);
me->delete("kill_xiaoyao");
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
   if(obj->query("id") == "zhi huan" && me->query("kill_xiaoyao") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say 不错啊，但这活我没叫你干啊。");
       return 1;
       }
  if(obj->query("id") == "zhi huan" && obj->query("byname") !=me->query("name")) {
       command("pat " + me->query("id"));
       command("say 这不是你找的吧！");
       return 1;
       }
   if(obj->query("id") == "zhi huan" && me->query("kill_xiaoyao") == 1)
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
   pot = 380 + random(kar);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！我就指点你两手功夫吧.\n"NOR,ob, me);
                  message_vision(HIC "\n由于$N成功的找回七宝指环，被奖励：\n"
                + chinese_number(exp) + "点实战修为，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(50) + "点评价作为答谢。\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_xiaoyao");
                destruct(present("zhi huan",ob));
   return;      
}