
inherit NPC;
inherit F_MASTER;
void re_rank(object);
void create()
{
        set_name("铁中棠", ({ "master tie", "master","tie" }) );
        set("gender", "男性" );
        set("age", 22);
        set("int", 30);
        set("per", 15);
        set("apprentice_available", 50);
        create_family("铁血大旗门", 8, "掌门");
        set("long",
                "铁中棠是铁血大旗门的传人。\n"

                );
        set("force_factor", 100);
        set("max_gin", 350);
        set("max_kee", 600);
        set("max_sen", 350);
        set("eff_gin", 350);
        set("eff_kee", 600);
        set("eff_sen", 350);
        set("gin", 350);
        set("kee", 600);
        set("sen", 350);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 2000);
        set("force", 4000);
        set("max_mana", 300);
        set("mana", 300);
        set("attitude", "peaceful");
          set("combat_exp", 2000000);
        set("score", 3000);
        set_skill("dormancy",200);
        set_skill("cuff", 150);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 120);
        set_skill("literate", 150);
        set_skill("dodge", 200);
        set_skill("ill-quan", 200);
          set_skill("fy-sword", 200);
        set_skill("cloudsforce", 200);
        set_skill("tie-steps", 200);

        prepare_skill("cuff", "ill-quan");
        map_skill("cuff", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "cloudsforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

	set("shen_type",1);
                setup();
        carry_object(__DIR__"obj/tieflag");
                carry_object("obj/cloth")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if (ob->query_temp("mark/can_apprentice_master_tie"))
        if( (string)ob->query("gender") != "男性" )
          {      command("say 我只收男弟子！");
          }
        else {

                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
         }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
        re_rank(ob);
        add("apprentice_availavble", -1);
}

void init()
{
   add_action("give_quest", "quest");

}
int accept_object(object me, object obj)
{
        if(obj->query("id")=="silk book" && me->query_temp("mark/silkbook"))
        {
                me->set_temp("mark/can_apprentice_master_tie",1);
                me->delete_temp("mark/silkbook");
                command("say 灵光，灵光她还好吗？\n");
                return 1;
        }
        return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 3200 ) {
                student->set("title","铁血大旗门弟子");
                return ;
        } else if ( exp <= 12800 ) {
                student->set("title","铁血大旗门小侠");
                return ;
        } else if ( exp <= 51200 ) {
                student->set("title","铁血大旗门少侠");
                return ;
        } else if ( exp <= 153600 ) {
                student->set("title","铁血大旗门大侠");
                return ;
        } else if ( exp <= 345600 ) {
                student->set("title","铁血大旗门奇侠");
                return ;
        } else if ( exp <= 518700 ) {
                student->set("title","铁血大旗门元老");
                return ;
        } else if ( exp <= 8624400 ) {
                student->set("title","铁血大旗门长老");
                return ;
        } else
                student->set("title","铁血大旗门副掌门");
                return ;
}

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}


