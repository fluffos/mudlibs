
inherit NPC;
inherit F_MASTER;

void create()
{
                object armor;
        set_name("日后", ({ "master queen", "master","queen" }) );
        set("gender", "女性" );
        set("age", 46);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("常春岛", 7, "掌门");
        set("long",
                "日后乃铁血大旗门第七代掌门人云翼之妻，因看不惯铁血大旗门人对其\
n"
                "妻子的无情，开创常春岛一派，以收容世上所有伤心女子。\n"
                );
        set("force_factor", 30);
        set("max_gin", 200);
        set("max_kee", 500);
        set("max_sen", 300);
        set("eff_gin", 200);
        set("eff_kee", 500);
        set("eff_sen", 300);
        set("gin", 200);
        set("kee", 500);
        set("sen", 300);
        set("max_atman", 200);
        set("atman", 200);
        set("max_force", 1000);
        set("force", 1000);
        set("max_mana", 300);
        set("mana", 300);
        set("attitude", "peaceful");
          set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("dormancy",100);
        set_skill("cuff", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 80);
        set_skill("literate", 120);
        set_skill("dodge", 100);
        set_skill("ill-quan", 80);
        set_skill("fy-sword", 100);
        set_skill("jiayiforce", 80);
        set_skill("tie-steps", 130);

        map_skill("cuff", "ill-quan");
        map_skill("cuff", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

                setup();
            armor=new(__DIR__"obj/corclot");
                armor->set_name("天青丝衣",({"cloth"}) );
                armor->move(this_object());
                armor->wear();

}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
	object student;
	int exp;
	student=ob;
	exp=(int) ob->query("combat_exp");
        if((int) ob->query("combat_exp")<100000) return;
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
        }
        if( exp <= 3200 ) {
                student->set("title","常春岛弟子");
                return ;
        } else if ( exp <= 12800 ) {
                student->set("title","常春岛小侠女");
                return ;
        } else if ( exp <= 51200 ) {
                student->set("title","常春岛侠女");
                return ;
        } else if ( exp <= 153600 ) {
                student->set("title","常春岛大侠女");
                return ;
        } else if ( exp <= 345600 ) {
                student->set("title","常春岛仙女");
                return ;
        } else if ( exp <= 518700 ) {
                student->set("title","常春岛神女");
                return ;
        } else if ( exp <= 8624400 ) {
                student->set("title","常春岛圣女");
                return ;
        } else
                student->set("title","常春岛副掌门");
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {      command("say 我只收女弟子！");
          }
        else {

                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
		ob->delete("betrayer");
        }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
        add("apprentice_availavble", -1);
}

void init()
{
   add_action("give_quest", "quest");

}


int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一摇头，说道： 给我-
钱干什么？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N叹了口气，说道： 你-
好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}


