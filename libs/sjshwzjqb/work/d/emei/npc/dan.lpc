
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name("丹辰子", ({"danchen zi", "danchen", "zi","master"}));
       set("long","峨嵋山第二代弟子中最杰出的人物之一。\n");
       set("title", WHT"峨嵋派大师兄"NOR);
       set("gender", "男性");
       set("age", 30);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "大弟子");
       set("per", 40);
	set("int", 30);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("sen", 3000);
       set("kee", 3000);
       set("max_gin", 600);
       set("max_force", 2000);
       set("max_mana", 2000);
       set("mana", 2000);
       set("force", 2000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 1800000);
       set("daoxing", 1800000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 200);
       set_skill("literate", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("spells", 200);
       set_skill("emeiforce", 200);
       set_skill("zhutian-bu", 200);
       set_skill("tianlei-sword", 200);
       set_skill("mahayana", 200);
       set_skill("jinding-zhang", 200);
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");
       map_skill("sword", "tianlei-sword");
       map_skill("unarmed", "jinding-zhang");

       create_family("峨嵋派", 2, "弟子");
 
        set("inquiry", ([
    "血魔": (: ask_mieyao :),
     "下山": (: expell_me :),
     "leave": (: expell_me :),
      "cancel": (: ask_cancel :),
]) );
setup();

        carry_object("/d/emei/obj/jiazhou")->wear();
        carry_object("/d/emei/obj/shoes")->wear();
        
}

void attempt_apprentice(object ob)
{
         if (((int)ob->query("combat_exp") < 1000000 )) 
        { 
             command("say " + RANK_D->query_respect(ob) + "的武学修为不够高深，有些绝学秘法恐怕难以领悟。\n"); 
              return;
        }

        if(((int)ob->query_skill("huifeng-sword",1) > 1))
        {
              command("say 这位" + RANK_D->query_respect(ob) + "，你还是先放弃所学的剑法，才能拜我为师。");
              return;
        }

        if(((int)ob->query_skill("tianji-sword",1) > 1))
        {
               command("say 这位" + RANK_D->query_respect(ob) + "，你还是先放弃所学的剑法，才能拜我为师。");
              return;
        }

        if(((int)ob->query_skill("leiyan-sword",1) > 1))
        {
               command("say 这位" + RANK_D->query_respect(ob) + "，你还是先放弃所学的剑法，才能拜我为师。");
              return;
        }


	 command("say 好，希望" + RANK_D->query_respect(ob) + "多加努力，把我们峨嵋发扬光大。\n");
        command("recruit " + ob->query("id"));
        ob->set("title", WHT"峨嵋派掌门大师兄"NOR);
}


string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="峨嵋派") {
                command("say 你既是执意下山，我身为峨嵋大师兄却有几句话说。");
                me->set_temp("betray", 1);
     command("say 我峨嵋山是名门正派，仙家正宗。国有国法，山有山规！");
                return ("既是要出山，却需受山规惩罚，你可愿意(agree)?");
        }
        return ("本人不知。");
}
void init()
{
      ::init();
      add_action("do_agree", "agree");
      add_action("do_fuming","fuming");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("betray/emei", 1);
                command("say 既是我峨嵋山留不住你，你便下山去吧！");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->delete("family");
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                this_player()->delete("class");
                this_player()->delete_skill("tianji-sword");
                this_player()->delete_skill("tianlei-sword");
                this_player()->delete_skill("emeiforce");
                this_player()->delete_skill("leiyan-sword");
                this_player()->set("title","普通百姓");
                this_player()->set("faith",0);
                this_player()->save();
                command("say 你从此再也不是我们峨嵋山中人，请速速下山吧。。。\n");
                this_player()->move("/d/city/center");
                tell_room( environment(this_player()),"只听劈啪！一声，一个人从峨嵋山上掉了下来，重重的摔到了地上。\n", ({this_player()}));
                return 1;
                }
        return 0;
}

string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="峨嵋派") {
    tell_room(environment(me),"丹辰子往天上一指，顿时一道光芒射出。\n");
    return "/d/obj/mieyao"->query_yao(me);
    }
    return ("本人不知。");
}


