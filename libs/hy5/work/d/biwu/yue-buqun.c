// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// 岳不群
// 此npc上的xunshan设置不当！
// 星星lywin改于2000/6/11

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();

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
        set("str", 126);
        set("con", 130);
        set("dex", 130);
        set("int", 128);

        set("neili", 54400);
        set("max_neili", 54400);
        set("jiali", 30);
        set("max_qi",52200);
        set("max_jing",52200);

        set("combat_exp", 52000000);
        set("shen", -200000);
        set_temp("xunshan", 1);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.feilong" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
            "巡山": (: do_xunshan :),
            "job" : (: do_xunshan :),
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 1000);
        set_skill("force", 1000);
        set_skill("parry", 1000);
        set_skill("dodge", 1200);
        set_skill("literate", 1200);
        set_skill("huashan-sword", 980);
        set_skill("zixia-shengong", 980);
        set_skill("huashan-ken", 980);
        set_skill("feiyan-huixiang", 980);
        set_skill("pixie-sword",380);
        set_skill("zhengqijue",380);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set_temp("apply/attack", 400);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
        create_family("华山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
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
        set_temp("xunshan",1);
        set("apprentice_available", 3);
}
int do_xunshan()
{
        object me = this_player();
        if ( me->query_temp("xunshan"))
        {
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
               me->delete_temp("xunshan");                      
               me->add("combat_exp", random(100));
               me->add("potential", random(40));
               return 1;
        }
        else
        {
               if ( query_temp("xunshan") < 1)
               {
                      message_vision("$N对着$n说：今天已经有人巡山去了。你明天再来吧。\n", this_object(), me);
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
                      return 1;
               }
        }
}
