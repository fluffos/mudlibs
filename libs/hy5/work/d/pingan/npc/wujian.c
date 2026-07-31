// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// 岳不群
// 此npc上的xunchen设置不当！
// 星星lywin改于2000/6/11
//  hxsd发现多次xunchen会有BUG。后换一种方法。
inherit NPC;
#include <ansi.h>;
int do_xunchen();

void create()
{
        set_name("王大人", ({ "wang daren", "wang" }) );
        set("title", "平安城守将");
        set("nickname", "无敌将军");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "王大人乃是平安城的守城大将。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", 2000);
        set_temp("xunchen", 80);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
            "巡城": (: do_xunchen :),
            "job" : (: do_xunchen :),
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("huashan-sword", 100);
        set_skill("zixia-shengong", 100);
        set_skill("huashan-ken", 80);
        set_skill("feiyan-huixiang", 100);
        set_skill("pixie-sword",80);
        set_skill("zhengqijue",100);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
set_temp("xunchen",8);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void reset()
{
        set_temp("xunchen",3);
}
int do_xunchen()
{
        object *ob_list;
        int i,exp,pot;
        object me = this_player();
        if ( me->query_temp("xunchen"))
        {
        if (present("xunchen1", me)  && present("xunchen2", me)&& present("xunchen3", me)&& present("xunchen4", me))  
         {
         	exp=random(200)+120;
         	if( me->query("combat_exp",1) >300000) exp=10;
         	pot=exp*3/4;
               message_vision("$N对着$n说：不错，辛苦了。你这就去休息去吧。你的经验增加了"+exp+"点。你的潜能增加了"+pot+"点。\n", this_object(), me);
               me->delete_temp("xunchen");                      
                 destruct(present("xunchen1",me));
                 destruct(present("xunchen2",me));
                 destruct(present("xunchen3",me));
                 destruct(present("xunchen4",me));
               me->add("combat_exp", exp);
               me->add("potential", pot);
               me->add_temp("nbjob30",1);
               return 1;
         }
        else
        command("say 你的巡城报告，还没全呢!");
        return 1;
        }
        else
        {
               if ( query_temp("xunchen") < 1)
               {
                      message_vision("$N对着$n说：今天已经有不少人巡城去了。你明天再来吧。\n", this_object(), me);
                      return 1;
               }
               if( me->query("combat_exp") <30000  && me->query("nbjob")!=31)
               {
                      message_vision("$N对着$n冷笑一声：就你这点道行也想巡城！\n", this_object(), me);
                      return 1;
               }
               if( me->query("combat_exp") >300000 && me->query("nbjob")!=31 )
               {
                      message_vision("$N对着$n说到，这么点小事，不敢劳您大驾！\n", this_object(), me);
                      return 1;
               }
               else
               {
                      add_temp("xunchen", -1);
                      message_vision("$N对着$n说：好男儿例当巡城。你，很好，很好！这就去吧。\n", this_object(), me);
//                      me->set_temp("xunchen/start", 1);
//                      me->set_temp("xunchen/time", time());
                      me->set_temp("xunchen", 1);
                        ob_list = children("/d/pingan/feizi/feizei");
              for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			destruct(ob_list[i]);
               }
                      return 1;
                                    }
        }
}
