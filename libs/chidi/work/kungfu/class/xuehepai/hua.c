// made by lks

#include <ansi.h>

inherit BHNPC;
int ask_me();
inherit F_MASTER;
#include "/kungfu/class/xuehepai/xiao.h"
#include "/kungfu/class/xuehepai/huajob.h"
#include "/kungfu/class/xuehepai/cloth.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("华危楼",({"hua weilou","hua"}));
        set("nickname",WHT"震天叟"NOR);
       set("shen_type",-1);
        set("gender","男性");
        set("int",30);  
        set("con",30);
        set("str",30);
        set("dex",30);
        set("bac",40);
        set("age",40);
        set("gu",1);
        set("attitude","peaceful");
        set("combat_exp",5000000);
        set("shen",1000);
        set("long",
"英俊潇洒,但始终看不破一个情字，最后也殉情了。\n"
        );
        set("neili",20000);
        set("jingli",18000);
        set("max_neili",20000);
        set("max_jingli",18000);
        set_skill("literate",1000);
        set_skill("cuff",450);
        set_skill("parry",350);
        set_skill("dodge",350);
        set_skill("jieniu-dao",350);
        set_skill("blade",350);
        set_skill("youran-bu",350);
        set_skill("tianhe-jian",350);
        set_skill("sword",350);
        set_skill("force",150);
        set_skill("tao",300);
        set_skill("feixue-quan",350);
        set_skill("huaxue-dafa",350);
        map_skill("blade","jieniu-dao");
        map_skill("force","huaxue-dafa");
        map_skill("dodge","youran-bu");
        map_skill("cuff","feixue-quan");
        map_skill("sword","tianhe-jian");
        prepare_skill("cuff","feixue-quan");
        
       create_family("血河派",13,"弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        set("chat_chance", 2);
        set("chat_msg", ({
                (: heal_ob :),
        }));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "xisui" :),
                (: exert_function, "xuewu" :),
                (: recover_ob :),
        }) );
       set("inquiry",([
                 "job" : (: ask_job :),
       ]));
}

        
void heal_ob()
{
        command("yun heal");
        command("yun heal");
        command("yun heal");
        command("yun recover");
        return;
}

void recover_ob()
{
        command("yun recover");
        return;
}

/*
int ask_me()
{
           object ob;
           mapping fam;

           object me=this_player();

           fam=(mapping)me->query("family");

           if (!fam || fam["family_name"]!="血河派")
           {
                  command("say 你与本派并无瓜葛，此话从何说起？");
                  return 1;
           }
           else if (fam["master_id"]!="hua weilou")
           {
                  command("say 你不是我的弟子。");
                  return 1;
           }
           if (me->query("combat_exp")<300000)
           {
                  command("say 你的实战经验太低了。");
                  return 1;
           }
           if (!query("gu"))
           {
                 command("say 震天鼓已经被拿走了。");
                 return 1;
            }
                  command("say 好吧，我把震天鼓交给你。");
                   set("gu",0);
                  ob=new("/d/longmen/xuehepai/obj/gu");
                  ob->move(me);
                  return 1;
}

*/

