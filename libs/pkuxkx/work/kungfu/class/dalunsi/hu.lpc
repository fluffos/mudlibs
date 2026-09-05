// sample master.c code
// xiake island master.c
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void consider();
void heal();
void create()
{
              set_name("呼巴音", ({ "hu bayin", "hubayin" ,"hu","bayin"}));
              set("long",@LONG
他长得身材魁梧，脸上两道浓眉高高翘起，一双铜铃般的大眼。仿佛一座小山
似的站在那里。
LONG
        );
              set("title", HIY "大轮寺第十二代弟子" NOR);
        set("gender", "男性");
        set("age", 39);
        set("attitude", "friendly");
        set("per", 15);
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);
        set("chat_chance", 10);
        set("chat_msg", ({
//                "a\n",
                (: heal :),
        }));
      set("inquiry", ([
//             "a" : "a\n",
      ]));



        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 150);     
        set("combat_exp",1000000);
        set("score", 2000);         
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );
        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 380);    // 混天气功
        set_skill("parry",350);
        set_skill("hand",380);
        set_skill("strike", 350);
        set_skill("liuhe-dao", 400);   // 六合刀
        set_skill("blade", 400);   // 基本刀法
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("shexing-shou",430);
        set_skill("dodge", 350);             // 基本躲闪

        set_skill("xiaoyaoyou", 350);        // 逍遥游
        set_skill("staff", 350);             // 基本棍杖
        set_skill("dagou-bang", 350);        // 打狗棒法
        set_skill("checking", 300);          // 道听途说
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang");
        
              create_family("大轮寺", 12, "弟子");
              set("class", "huanxi");
        setup();
        
              carry_object("/d/dalunsi/npc/obj/qinxiu-jiasha")->wear();
              carry_object("/d/dalunsi/npc/obj/jingang")->wield();
              add_money("silver",10);
}
void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="大轮寺")
        {
                command("say "+ RANK_D->query_respect(ob)+ "不是本寺弟子，在这里捣什么乱？！");
                return;
        }
        if ((int)ob->query("score")<500)
        {
            command("shake"+ob->query("id"));
            command("say "+RANK_D->query_respect(ob)+"如能为本寺立下点功劳,我一定收你.");
            return;
        }         
        if ((int)ob->query_skill("huanxi-chan", 1) < 50) 
        {
               command("say 欢喜禅是各项武功之本，你再勤加修炼吧。");
                command("say"+ RANK_D->query_respect(ob) +"再熬几个通宵，多多钻研钻研本门的心法吧。");
                return;
        }
       
        if ((string)ob->query("class") != "huanxi") 
        {
                message_vision("呼巴音看了看你头顶，又摸了摸自己的光头。",this_player());
                command("say 你还没出家，不能表示你是真心侍奉欢喜佛，我不能收你。");
                command("say 这位" + RANK_D->query_respect(ob) +"如能早下决心，献身侍奉我佛再来找我吧。");
                return;
        }
        command("say 好吧，你以后就是我的弟子了，可要刻苦勤修，不能偷懒呀。");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY "大轮寺第十三代弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield zhu");
            command("perform staff.chan " + target->query("id"));
            command("unwield zhu");
             break;
            case 1:
            command("perform strike.leiting " +target->query("id"));
             break;
             }
}
void heal()
{
        object ob=this_object();
        
        if (ob->query("bihua"))
                return;
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
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
