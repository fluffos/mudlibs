// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// 岳不群
// 此npc上的xunshan设置不当！
// 星星lywin改于2000/6/11

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();
string ask_me();
string ask_feng();

void create()
{
        set_name("岳不群", ({ "yue buqun", "yue" }) );
        set("title", "华山派掌门");
        set("nickname", "君子剑");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "岳不群自幼执掌华山派，乃当今武林中一等一的高手。\n");
        set("attitude", "peaceful");
        set("str", 56);
        set("con", 50);
        set("dex", 50);
        set("int", 58);

        set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", -200000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
	    "剑宗" : (: ask_me :),
	    "气宗" : (: ask_me :),
	    "宁中则" : "她是我夫人。\n",
	    "岳灵姗" : "她是我女儿。\n",
	    "紫霞功" : "那是本门至高无上的内功心法。\n",
	    "紫霞神功" : "那是本门至高无上的内功心法。\n",          
	    "思过崖" : "那是本派弟子修行思过之处。\n", 
	    "风清扬" : (: ask_feng :),
            "巡山": (: do_xunshan :),
            "job" : (: do_xunshan :),
        ]) );

        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        create_family("华山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
}

string ask_me()
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( !myfam || myfam["family_name"] != "华山派" )
		return "咱们豪无渊源，你问这事干嘛？\n";

	say("岳不群指着身后的匾额，语重心长地说道：“华山不幸曾分为气剑二宗。咱\n");
	say("们气宗奉气为主，以剑为辅，以气运剑，无坚不摧。而气宗则倒行逆施重剑\n");
	say("轻气。二宗各持己见，终于水火不容，同门操戈！华山因此式微。你即入我\n");
	say("门，盼你能洁身自爱，重振华山！记得当年匾额上写的是「剑气冲霄」，结\n");
	say("果剑宗虽剑路纵横，变化无方，可仍然败在我宗「紫霞神功」之下，数十年\n");
	say("来不复再现，实异不胜正也。”\n");
me->set_temp("mb",1);
	return "切记！切记！\n";
}

string ask_feng()
{
	say("岳不群的脸色突然便得很难看，皱着眉头。\n");
	return "他是本门的一个前辈，一向不过问本门事务，我也不清楚他的下落。\n";
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 老夫今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say 我华山派以剑法为主，依我看"+RANK_D->query_respect(ob)+"不适合于学剑法。");
        else {
                command("say 好，好，好，很好。");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}
void reset()
{
        set_temp("xunshan",200);
        set("apprentice_available", 3);
}
int do_xunshan()
{
        object me = this_player();
object killer;int k,exp,pot;

        if ( me->query_temp("xunshan"))
        {
              if(me->query_temp("killhuashan")<3)
               {
                      message_vision("$N对着$n说：听说外面的敌人并没有被消灭!!\n", this_object(), me);
                      return 1;
               }

              if(me->query_condition("huaxunshan")>0)
               {
                      message_vision("$N对着$n说：你巡山的时间还没过呢!\n", this_object(), me);
                      return 1;
               }

              if(me->query_condition("guojob2_busy")>0)
               {
                      message_vision("$N对着$n说：你休息一会再来!\n", this_object(), me);
                      return 1;
               }

               if (!me->query_temp("xunshan/chaoyang"))
               {
                      message_vision("$N对着$n说：你朝阳峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N对着$n说：你莲花峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N对着$n说：你云台峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N对着$n说：你怎么没去舍身崖？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N对着$n说：你到了思过崖去了？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N对着$n说：你到玉女峰后面华山小筑去看过了？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               message_vision("$N对着$n说：不错，辛苦了。你这就去休息去吧。\n", this_object(), me);
               me->delete_temp("killhuashan");                      
               me->delete_temp("xunshan");                      
               if (me->query("combat_exp")<800000)
               {
               me->add("combat_exp", 80);
               me->add("potential", 50);
               }
exp= random(270) + 250;
pot= random(200) + 180;
               me->add("combat_exp",exp);
               me->add("potential",pot);
   tell_object(me, "你被奖励了"+chinese_number(exp)+"点经验值！\n"+chinese_number(pot)+"点潜能\n");
               return 1;
        }
        else
        {
               if ( query_temp("xunshan") < 1)
               {
                      message_vision("$N对着$n说：今天已经有人巡山去了。你明天再来吧。\n", this_object(), me);
                      return 1;
               }
      if( (int)me->query_skill("zixia-shengong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
               if( me->query("family/family_name") != "华山派")
               {
                      message_vision("$N对着$n大喝一声：本派弟子才能巡山。你是哪来的奸细？休怪我剑下不留情！\n", this_object(), me);
                      this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add_temp("xunshan", -1);
                      message_vision("$N对着$n说：本派弟子例当巡山。你，很好，很好！这就去吧。\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
	              me->apply_condition("huaxunshan",8);
if (me->query("combat_exp") >800000)
{
        message_vision(HIR"听说华山附近的树林中有不明身份的蒙面人，你随便去探查一下！\n"NOR, me);
killer=new(__DIR__"killer",1);
killer->set_temp("owner/id",me->query("id"));
killer->set("id",me->query("id")+"-mengmian");
killer->set_temp("owner/id",me->query("id"));
killer->set("id",me->query("id")+"-mengmian");
killer->set("name",HIB"蒙面人"NOR);
if ((int)me->query_skill("force",1) > 10)
{
k=(int)me->query_skill("force",1);
}
else k=10;
killer->set("int",me->query("int"));
killer->set("str",me->query("str"));
killer->set("con",me->query("con"));
killer->set("dex",me->query("dex"));


        killer->move("/d/huashan/hsforest"+(random(19)+1));
        killer->set("combat_exp",me->query("combat_exp"));
        killer->set("qi", me->query("max_qi"));
        killer->set("eff_qi", me->query("max_qi"));
        killer->set("max_qi", me->query("max_qi"));
        killer->set("jing", me->query("max_jing"));
        killer->set("eff_jing", me->query("max_jing"));
        killer->set("max_jing", me->query("max_jing"));
        killer->set("neili", me->query("max_neili"));
        killer->set("max_neili", me->query("max_neili"));
         killer->set_skill("tmzhang", k);
        killer->set_skill("staff", k);
         killer->set_skill("tmjian", k);
         killer->set_skill("tmdao", k);
         killer->set_skill("pmshenfa", k);
          killer->set_skill("strike",k);
         killer->set_skill("blade", k);
          killer->set_skill("sword", k);
          killer->set_skill("parry", k);
        killer->set_skill("literate",k);
          killer->set_skill("dodge", k);
          killer->set_skill("unarmed", k);
          killer->set_skill("whip", k);
          killer->set_skill("force", k);
         killer->set_skill("tmzhang", k);
         killer->set_skill("tmdafa", k);
}
                      return 1;
               }
        }
}
