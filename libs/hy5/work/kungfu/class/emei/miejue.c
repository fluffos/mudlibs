// miejue.c 灭绝师太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("灭绝师太", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。\n");
        set("gender", "女性");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );
        set("inquiry",([
                "剃度"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "出家"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "还俗"  :  (: ask_for_quit :),
        ]));

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("per", 20);

        set("max_qi", 4000);
        set("max_jing", 2000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("persuading", 550);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 500);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 250);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
//        map_skill("magic","bashi-shentong");
        create_family("峨嵋派", 3, "掌门人");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
   mapping ob_fam;
   mapping my_fam  = ob->query("family");

   string name, new_name;
   name = ob->query("name");

   if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
   {
      command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
      return;
   }
   switch (random(2))
   {
        case 1: break;
        default:
           if ((string)ob->query("class")!="bonze" )
           {
               command ("say 阿弥陀佛！贫尼不收俗家弟子。");
               return;
           }
           else
           {
               command ("say 阿弥陀佛！贫尼不收弟子。");
               return;
           }
   }
   if ((int)ob->query_skill("mahayana",1)<90||(int)ob->query_skill("linji-zhuang",1)<90)
   {
      command("say 你本门的功夫修为还太低。");
      return;
   }
   if ((int)ob->query("shen") < 50000)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   if ((string)ob->query("class")=="bonze" )
   {
        name = ob->query("name");
        new_name = "静" + name[2..3];
        ob->set("name", new_name);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第四代弟子!");
   }

   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派")) 
        return ("你和峨嵋没有渊源，贫尼不敢给你还俗。\n");
    if( (string)me->query("class")!="bonze" )
        return "阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say 阿弥陀佛！善哉！善哉！你一心要还俗，我也不挽留。\n");
        command ("say 我将废去你部分武功。请跪下(kneel)听宣。\n");
        return "如果不愿还俗的，就安心在此修炼吧。\n";
}

int do_kneel()
{
}

