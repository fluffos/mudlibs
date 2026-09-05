// yang.cg.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;
inherit F_QUESTMASTER;
string ask_me();
void consider();
void heal();
void create()
{
     set_name("张无忌",({"zhang wuji","zhang"}));
        set("long", "他今年二十多岁。\n");
        set("title",GRN "明教" NOR + YEL "教主" NOR);
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("per", 50);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
  set("chat_chance", 100);
    set("chat_msg", ({
                (: heal :),
        }));
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 200);
        set("combat_exp", 15000000);
        set("score", 400000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
      set("inquiry", ([
                "圣火令" : (: ask_me :),
        ]) );
       set("book_count", 1);
              set_skill("force",500);
          set_skill("jiuyang-shengong",500);
             set_skill("dodge",500);
          set_skill("datengnuo-bufa", 500);
           set_skill("hanbing-zhang",500);
             set_skill("medical-skill",300);
               set_skill("parry",500);
           set_skill("sword",500);
          set_skill("shenghuo-shengong",500);
         set_skill("qiankun-danuoyi", 500);
              set_skill("strike",300);
        map_skill("strike", "hanbing-zhang");
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("sword", "shenghuo-shengong");
        prepare_skill("strike", "hanbing-zhang");
        create_family("明教",19,"弟子");
        setup();
            carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
        carry_object("/d/mingjiao/obj/changpao")->wear();
}
void init()
{
add_action("give_wsquest","quest");
}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="明教")
        {
                command("say 你非我派弟子，我不能收你。");
                return ;
        }
        if((int)ob->query("betrayer")>=1)
        {
command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义。我怎会收你。\n")
;
                return;
        }
        if ((int)this_player()->query_int() < 30 )
        {
   command("say 学习本教秘技要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够??);
                return;
        }
        if ((int)ob->query("score")<1500){ 
  command("sigh"+ob->query("id"));
             command("say 小兄弟还是回去吧.我是不会收一个对本教不忠之人的\n");
             return;
       }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 50) {
                command("say 你的内功心法修为不够。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit "+ob->query("id"));
        ob->set("title", GRN "明教" NOR + YEL "圣使" NOR);
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(3) )
        {
            case 0:
            command("perform parry.duo " + target->query("id"));
             break;
            case 1:
            command("perform dodge.tisha " +target->query("id"));
             break;
             case 2:
            command("perform parry.fenxin " +target->query("id"));
             break;
             }
}
string ask_me()
{
        mapping fam;
        object ob;
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((string)this_player()->query("family/master_id") != "zhang wuji")
        return "你的身份太底，圣火令乃本教镇教之宝，不能给你。";
        if (query("book_count") < 1)
                return "你来晚了，本教的圣火令不在此处。";
        add("book_count", -1);
        ob = new("/d/mingjiao/obj/shenghuo-ling");
        ob->move(this_player());
        return "好吧，这个圣火令你拿回去好好保管。";
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
