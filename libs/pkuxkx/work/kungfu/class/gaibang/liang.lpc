// sample master.c code

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "丐帮九袋长老");
        set("title",MAG "丐帮" NOR + YEL "九袋" NOR+ MAG "长老" NOR);
        set("nickname", GRN "传功长老" NOR);
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。\n"
		"丐帮武功向来较强，近来梁长老一力整顿，更是蒸蒸日上。\n");

	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 400);
	set("max_jing", 400);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 120);
	
	set("combat_exp", 1200000);
	
	set_skill("force", 120); 
	set_skill("huntian-qigong", 125); 
        set_skill("strike", 125);
	set_skill("xianglong-zhang", 120); 
	set_skill("dodge", 123); 
	set_skill("xiaoyaoyou", 120); 
	set_skill("parry", 120); 
	set_skill("staff", 110); 
	set_skill("dagou-bang", 120); 
	set_skill("begging", 110); 
	set_skill("checking", 120);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	create_family("丐帮", 18, "九袋长老");
	set("shen_type",1);set("score",1000);setup();
	carry_object("/d/gaibang/obj/jing_cloth")->wear();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting() && environment(this_object())->query("short") == "树洞下")
	{
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "丐帮") && !wizardp(ob))
		{
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	message_vision("\n粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +
		"从小门里飞了出来。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
		command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<8)
        {
               	command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<800){
             command("heng"+ob->query("id"));
             command("say 你这种不忠不义之人,老夫绝不收你!");
             return;
        }
        if (ob->query("dai")== 8 )
        {
        	if ((int)ob->query("str") < 25) {
                	command("say 我们丐帮的武艺一向以刚猛为主，" +
                	RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
                	return;
	        }

        	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	        "能好好学习本门武功，将来在江湖中闯出一番作为。");
          command("recruit " + ob->query("id"));
          this_player()->set("title",MAG "丐帮" NOR + YEL +"八袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
          return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}
