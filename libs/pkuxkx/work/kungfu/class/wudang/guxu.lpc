#include <ansi.h>
// guxu.c 谷虚
#include <title.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
void heal();
void do_answer(string);
string ask_for_leave();

void create()
{
        set_name("谷虚道长", ({ "guxu daozhang", "guxu" }));
		set("start_room","/d/wudang/sanqing");
        set("long",
                "他就是俞莲舟的弟子谷虚道长。\n"
                "他今年四十岁，主管武当派的俗事。\n");
       set("title",RED "武当派" NOR + GRN +"道长" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));


        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 60);
        set("combat_exp", 120000);
        set("score", 8000);

        set_skill("force", 80);
        set_skill("literate", 80);
        set_skill("taiji-shengong", 80);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 80);
        set_skill("cuff", 80);
        set_skill("taiji-quan", 80);
//      set_skill("taiji-quan", 60);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("taiji-jian", 80);
        set_skill("taoism", 60);
//      set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");

        set("inquiry",
                ([
                        "道德经" : (: ask_me :),
                        "还俗" : (: ask_for_leave :),
                ]));

        set("book_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{

        object ob;
        mapping fam;

        add_action("do_decide", "decide");
        add_action("do_leave",  "leave");
        ::init();

        ob = this_player();
if((int)ob->query("shen")<=-100&&ob->query("family/master_id")=="guxu daozhang")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("class")!="taoist" )
		return "你并非三清弟子，何故跟贫道开这等玩笑？";

	if( (string)me->query("family/family_name") != "武当派")
		return "你非我武当弟子，还俗的事情贫道作不得主。";

	me->set_temp("pending/leave_taoist", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我武当而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_taoist") != 1)
		return 0;
	message_vision("谷虚道长对$N说道：「从此你就不再是我武当门下了，请好自为之！」\n",me);
	tell_object(me,HIR "你决定叛出武当门下！\n" NOR);
	me->delete_temp("pending/leave_taoist");
  me->expell_family("武当派");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}

void attempt_apprentice(object ob)
{

        if ( this_player()->query("class")=="bonze")
        {
                command("say 我派不收佛门弟子，" + RANK_D->query_respect(ob) + "请现还俗了在来。");
                return;
        }
        if ( this_player()->query("class")=="eunach")
        {
                command("say 我派不收太监，" + RANK_D->query_respect(ob) + "请会吧。");
                return;
        }
        
	if( !ob->query("family")&&ob->query("combat_exp")>5000&&!ob->query("reborn/chushi")) 
	{
		command ("say 本派不收经验太高的普通百姓！\n");
		return;
	}

	if ((string)ob->query("class") != "taoist")
	{
		command("say 我派只收道士，"+ RANK_D->query_respect(ob) + "是否愿意入我三清。");
		command("say 如果你决定了。请告诉我(decide)。");
	       	ob->set_temp("prepare/taoist", 1);
	        return;
	}
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if (this_player()->query("age")<20)
	      {
	        if((string)this_player()->query("gender")!="女性")
            this_player()->set("title",RED "武当派" NOR + GRN +"道童" NOR);
          else
	          this_player()->set("title",RED "武当派" NOR + GRN +"小道姑" NOR);
        }
	      else 
	      {
	        if((string)this_player()->query("gender")!="女性")
            this_player()->set("title",RED "武当派" NOR + GRN +"道士" NOR);
          else
	          this_player()->set("title",RED "武当派" NOR + GRN +"道姑" NOR);
	      }
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的道德真经不在此处。";
        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好钻研。";
}



int do_decide()
{

	object ob=this_player();
        if( !this_player()->query_temp("prepare/taoist") )
                return 0;
	
        this_player()->delete_temp("prepare/taoist");

        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return 0;
        }
  	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return 1;		
	}	 
        this_player()->set("class", "taoist");
	command("say 好吧，贫道就收下你了。");
	command("say 如今你已经是三清弟子，以后做事可要好好做人，否则我派无法留你。");
	command("recruit " + ob->query("id"));
        if (this_player()->query("age")<20)
        {
          if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "武当派" NOR + GRN +"道童" NOR);
          else
                this_player()->set("title",RED "武当派" NOR + GRN +"小道姑" NOR);
        }
        else 
        {
          if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "武当派" NOR + GRN +"道士" NOR);
          else
                this_player()->set("title",RED "武当派" NOR + GRN +"道姑" NOR);
        }
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
	return 1;
}

void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        me->set("class", "taoist");
	command("say 好吧，贫道就收下你了。");
	command("say 如今你已经是三清弟子，以后做事可要好好做人，否则我派无法留你。");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
        	if (me->query("age")<20)
        	{
                 me->set("title",RED "武当派" NOR + GRN +"小道姑" NOR);
        	}
        	else 
        	{
           	     me->set("title",RED "武当派" NOR + GRN +"道姑" NOR);
        	}
//title系统记录玩家title by seagate@pkuxkx
	        me->set_title(TITLE_RANK, me->query("title"));
	}
return;
}
void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 30");
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
