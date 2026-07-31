#include <ansi.h>

inherit NPC;
void greeting(object ob);
void create()
{
        set_name("田伯光",({"tian boguang","tian"}));
        set("nickname", HIM "万里独行"NOR);
        set("gender", "男性");
        set("age", 35);
        set("long", 
                "他就是恶名昭彰的淫贼田伯光。\n"
                "其轻身功夫及一手快刀闻名于江湖。\n"
                );

        set("max_qi",5000);
        set("neili",5000);
        set("max_neili",5000);
        set("jiali",500);
        set_skill("unarmed", 200);
        set_skill("dodge", 1000);
        set_skill("parry", 200);
        set_skill("blade", 200);
        set("combat_exp", 10000000);
        set_skill("wuhu-duanmendao", 200);
        map_skill("blade","wuhu-duanmendao");        
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 100);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
            (: perform_action, "blade.duan" :),
        }) );

        set("chat_chance", 1);
        set("chat_msg", ({
"田伯光道：好！够劲儿！\n",
        }) );

        setup();
        
        carry_object("/d/city2/obj/jinduan")->wear();
        carry_object("/d/city/obj/gangdao")->wield();
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ((string)ob->query("gender")=="女性")
        {
           switch(random(4))
           {
                case 0:command("rose "+(string)ob->query("id"));break;
                case 1:command("kiss "+(string)ob->query("id"));break;
                case 2:command("love "+(string)ob->query("id"));break;
                case 3:command("fang "+(string)ob->query("id"));break;
           }
     
        }
        else
      message_vision("$N贼兮忒忒地说道：这位"+RANK_D->query_respect(ob)+",咱哥俩一起去泡妞如何。\n",this_object());
        return;
}

void init(object ob)
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
