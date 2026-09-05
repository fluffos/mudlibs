#include <ansi.h>
// ding.c 丁春秋
inherit NPC;
inherit F_MASTER;
string ask_me();
int ask_li();
void consider();
void create()
{
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("title",MAG "星宿派" NOR + YEL "开山" NOR + MAG "祖师" NOR);
        set("nickname", RED "星宿老怪" NOR);
        set("long",
                "他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
                "可是他看起来形貌清奇，仙风道骨。\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 400000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
   (: perform_action, "strike.sandu" :),
   (: consider :)
        }) );
set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "虚竹" :
                "你问他干吗，他不是老仙的对手。",
                "阿紫" : "阿紫不是在外边吗？",
                "李秋水" : (: ask_li :),

     ]) );
        set_skill("force", 150);
        set_skill("huagong-dafa", 250);
        set_skill("handu-xinfa", 160);
        set_skill("dodge", 150);
        set_skill("zhaixinggong", 150);
        set_skill("strike", 150);
        set_skill("xingxiu-duzhang", 150);
        set_skill("hand", 150);
        set_skill("zhaixing-shou", 150);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("tianshan-zhang", 150);
//      set_skill("literate", 80);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
        create_family("星宿派", 1, "开山祖师");
        set("class", "taoist");
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"丁春秋骂骂咧咧的说道：虚竹这小子不是个东西，竟敢偷袭老仙。\n",
"丁春秋叹了口气「唉」，要是我的冰魄杖在就好了，虚竹那小子不是我的对手\n",
"“哪儿去了呢？”丁春秋喃喃自语：“难道又给她偷去了？\n"
"我是放的好好的啊！唉。”\n",
"想当年在逍遥派的时候，李师叔对我还是不错的! ”\n"

       }) );
//      carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
        object me, ob;
        mapping fam;
        add_action("do_flatter", "flatter");
        ::init();
        ob = this_player();
        me = this_object();
if ( (int)ob->query("shen") >0 && ((fam = ob->query("family")) && fam["master_id"] == "ding chunqiu"))
        {
                command("say 你多次杀我同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }

if (interactive(ob = this_player())&&(!is_fighting()))

       {

                if((int)ob->query("shen")>=1000)

                     {

                         remove_call_out("do_killing");

                         call_out("do_killing", 2,ob);

                         command("say 我最讨厌你们这些伪君子，去死吧! ");

                      }

       }
}

void do_killing(object ob)

{

          if (!ob || environment(ob) != environment())

                return;

                this_object()->kill_ob(ob);

 }


void attempt_apprentice(object me)
{
          if ((int)me->query("shen") > -10000) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
                }
          if ((string)me->query("family/family_name") != "星宿派")
                {
                command("say 你不是我派弟子，此话从何说起！");
                return;
                }
          if ((int)me->query("score") < 800)
                {
                message_vision("丁春秋露出一副不信任的样子. \n", me);
                command("say 你对本门尽心了吗？");
            return;
                }
                  
          if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等人拍马(flatter
)的样子。\n",
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
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
        else
                this_player()->set("title",HIR "星宿派" NOR + GRN +"妖女" NOR);
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
void consider()
{
        int i=random(4);
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        if (i==3)
                command("exert maxsuck " + target->query("id"));
        if (i==2)
                command("exert neilisuck " + target->query("id"));
        if (i==1)
                command("exert jingsuck " + target->query("id"));
        if (i==0)
                command("exert qisuck " + target->query("id"));
}
string ask_me()
{
mapping fam;
      if (!(fam = this_player()->query("family"))
          || fam["family_name"] != "星宿派")
            return RANK_D->query_respect(this_player()) +
        "也来窥探我镇派之宝吗？丁春秋哼了一声";
 if ((int)this_player()->query_temp("marks/丁") )
   return "你这恶徒，老仙不是刚告诉你了吗?\n";
if (this_player()->query_skill("tianshan-zhang",1)<40)
   return "冰魄杖是我派镇派之宝，威力极大，可" +RANK_D->query_respect(this_player()) +"天山杖法太弱，\n"
"要了也没用，"+RANK_D->query_respect(this_player()) +"还是专心练功吧\n";
                this_player()->set_temp("marks/丁", 1);
return "冰魄杖是我派镇派之宝，可不知给谁拿走了我也不知道。\n"
"我猜又是你那师姐阿紫偷的，你问问她吧。\n";
   }
int ask_li()
  {
   mapping fam;
   int i=random(3); 
     if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
        {
          command("say "+RANK_D->query_respect(this_player()) + "问李师叔干什么?");
        }
     else {
          if (i == 2)
            {
             command("say 听说李师叔来了天山，但我也不知道她老人家住在何处.");
             this_player()->set_temp("marks/李",1);
return 1;}
          if (i == 1) 
            {
             command("sigh"); 
             command("say 她是我的师叔，小无相神功天下无敌，可惜我没有学到!");
return 1;
            }
          if (i == 0)
            {
             command("say 李师叔比较喜欢漂亮的年轻人，当初我还是蛮得李师叔的欢心的.");
             command("smile");
return 1;
            }
          }
 }

void die()
{
	object obj,me,cor;
	me = this_object();
	if( objectp(obj = me->query_temp("last_damage_from")) && ((obj->query_temp("lingjiu/kill_ding")))) 
	{
		 obj->set_temp("lingjiu/killer",1);
	}
    ::die();

 return;
}
