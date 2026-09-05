inherit NPC;
inherit F_MASTER;
void heal(); 
string ask_me();
#include <ansi.h>
void create()
{
        set_name("黛绮丝", ({ "dai qisi", "dai" }));
        set("nickname", MAG"紫衫龙王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","她是明教四大法王之一－－紫衫龙王黛绮丝。身着一件紫衫。\n"
                   "她高鼻深目，肤白如雪，明艳不可方物。当年由于对韩千叶一 \n"
                   "役有功，所以其它三王都愿尊她为四大法王之首。\n");
         set("gender", "女性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("chat_chance", 100);
        set("chat_msg", ({

                (: heal :),
        }));
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 500000);

   
         set("inquiry", ([
                "金花" : (: ask_me :),
        ]) );
        set("hua_count",20);
        set_skill("force", 110);
        set_skill("shenghuo-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("parry", 120);
         set_skill("feihua-shou",180);
        set_skill("datengnuo-bufa", 100);
      set_skill("throwing",180);
        set_skill("literate", 100);

        set_skill("shenghuo-shengong", 50);
        map_skill("force", "shenghuo-xinfa");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("throwing", "feihua-shou");
        prepare_skill("throwing","feihua-shou");
        create_family("明教", 20, "弟子");
        setup();
carry_object("/clone/weapon/changjian")->wield();
carry_object("/d/mingjiao/obj/zishan")->wear();
}
void attempt_apprentice(object ob)
{
 /*        if( (string)ob->query("gender") != "女性" )
        {
                command ("say 我不收男徒，你还是请回吧！");
                return;
        }
*/   
      if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 我不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");

                return;
        }
       if((int)ob->query("score")<500){
          command("sigh");
          command("say 对师门不忠之人,我怎么能相信你呢?\n");
          return;
               }

        


      if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say 你的九阳神功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
/*       if ((int)ob->query("shen") >-10000)
        {
                command("say 我最看不过眼满肚子伪善道德的人。");
                command("say " + RANK_D->query_respect(ob) + "若能杀他" +
                        "几个伪君子，我一定收你。");
                return;

        }
*/
        if((int)ob->query("betrayer")>=10)
        {
   command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
     command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                      ob->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
}
void re_rank(object student)
{
                        student->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
}   
string ask_me()
{
        mapping fam;
        object ob;
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
if((string)this_player()->query("family/master_id") != "dai qisi"&&(string)this_player()->query("family/master_id") != "zhang wuji")
        return "你不是我的徒弟，金花乃我防身之物，不能给你。";
        if (query("hua_count") < 1)
                return "你来晚了，我已经给完了。";
        add("hua_count", -1);
        ob = new("/d/mingjiao/npc/obj/jinhua");
        ob->move(this_player());
        return "好吧，这个金花拿回去好好保管，切莫乱使。";
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))

        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

