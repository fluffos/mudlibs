// gaibang npc code

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void halt();
void create()
{
        set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
        set("title",MAG "丐帮" NOR + YEL "三袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 27);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮三袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 100);
        set("chat_msg", ({
              (: halt :),
        }));

        set("max_qi", 720);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 34);

        set("combat_exp", 20000);

        set_skill("force", 50);
        set_skill("huntian-qigong", 55);
	set_skill("blade", 55);
	set_skill("liuhe-dao", 55);
        set_skill("hand", 55);
        set_skill("shexing-shou", 55);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 55);
        set_skill("parry", 63);
        set_skill("begging", 50);
        set_skill("stealing", 60);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
	map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 24, "弟子");
        setup();
        carry_object("/d/city/obj/gangdao")->wield();
		carry_object("/d/gaibang/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
	if ((string)ob->query("family/family_name")!="丐帮")
	{
              command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob) + "先要从一袋弟子做起。");
		return;
	}
	if ((int)ob->query("score")<200){
           command("say 不行.本帮弟子都是忠心为帮的,我看你对本帮还不够忠心.");
           return;}  
        if (ob->query("dai")<2)
	{
               command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
		return;
	}
        if (ob->query("dai")== 2 )
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你了。");
                command("recruit " + ob->query("id"));
                if (this_player()->query("is_beggar"))
                  this_player()->set("title",MAG "丐帮" NOR + WHT + "污衣派" + YEL +"二袋" NOR + MAG "弟子" NOR);
                else    
                	this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"二袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");


        if((obj->query("id") == "qingzhu ling")
	&& ((string)ob->query("family/family_name")== "丐帮"))
        {	
	   if (ob->query("dai")==3)
	   {
                ob->set_temp("fight_ok_3",1);
                command("say 好，既然已得到简长老许可，我们就来验证一下武功。");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                return 1;
	    }
	    else
	    {
		command("say "+ RANK_D->query_respect(ob) +"袋位不对，我们不能比划。");
	    	return 0;
	    }
	}
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
         object me,obj,*usr
;
         int i;
                  me=this_object();
         usr=users();
        for (i=0; i<sizeof(usr); i++) {
             obj=usr[i];
       if ((environment(obj) == environment(ob) )&&( obj->name() != ob->name() ))
                   return notify_fail("我们还是到个没人的地方在比吧。\n");
             }

        if ( !ob->query_temp("fight_ok_3") ) return 0;
        if (me->is_fighting())
	{
		command("say 我正在没空，" + RANK_D->query_respect(ob) + "可以等会儿再比。");
		return 0;
	}
       me->interrupt_me();
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

       	remove_call_out("checking");
        call_out("checking", 1, me, ob);

        ob->delete_temp("fight_ok_3");
        me->set("bihua",1);

        return 1;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

    	if ( !present(ob, environment()) ) return 1;

        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在本帮诸多弟子中出人头地 !\n");
                return 1;
        }

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
                command("say 青出於蓝胜於蓝，不愧是丐帮的佳弟子 ! 恭喜你了 !\n");
                message_vision("$N交给$n一个青竹令。\n", me, ob);
                ob->set_temp("have_win",1);
                obj=new("/d/gaibang/obj/qingzhu-ling2");
                obj->move(ob);
                return 1;
        }


        return 1;
}

void halt()
{
        this_object()->delete("bihua");
        return ;
}
