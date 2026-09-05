#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();
int ask_me_1();
int ask_me_2();
int ask_me_3();

void create()
{
        set_name("简长老", ({"jian zhanglao", "jian", "zhanglao"}));
        set("title", "丐帮九袋长老");
        set("nickname", GRN "执法长老" NOR);
        set("title",MAG "丐帮" NOR + YEL "九袋" NOR+ MAG "长老" NOR);
        set("gender", "男性");
        set("age", 50);
        set("long",
                "简长老是丐邦的执法长老，代帮主执掌法刀以及青竹令等。\n"
                "他向来嫉恶如仇，弟子中有谁犯过，出手决不容情。\n");

        set("attitude", "peaceful");

        set("str", 24);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1000);
        set("max_jing", 100);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 125); // 基本内功
        set_skill("huntian-qigong", 120); // 混天气功
        set_skill("strike", 120); // 基本掌法
        set_skill("xianglong-zhang", 115); // 降龙十八掌
        set_skill("dodge", 120); // 基本躲闪
        set_skill("xiaoyaoyou", 125); // 逍遥游
        set_skill("parry", 115); // 基本招架
        set_skill("staff", 120); // 基本棍杖

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 18, "九袋长老");

        set("inquiry", ([
                "青竹令":     (: ask_me_1 :),
                "升袋"  :     (: ask_me_2 :),
                "升级"  :     (: ask_me_2 :),
		"布袋" :   (: ask_me_3 :),
                "晋级"  :     (: ask_me_2 :)
        ]));
 
        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/gaibang/obj/jing_cloth")->wear();
}

void init()
{
        object ob;
        mapping myfam;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting() && environment(this_object())->query("short") == "暗道")
        {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "丐帮") &&
                        (!wizardp(ob))) {
                        remove_call_out("saying");
                        call_out("saying",2,ob);
                }
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

        message_vision("\n简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该"
            "随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n"
            "说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」"
            "－－叭叽\n\n", ob);
        remove_call_out("kicking");
        call_out("kicking",1,ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

        ob->move("/d/city/pomiao");
         message("vision","只听“嘭”地一声，紧接着" +  ob->query("name") +
                "从小门里飞了出来，屁股上有一个清楚的鞋印。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}

int ask_me_1()
{
	object obj;
	object ob=this_player();
	int n=ob->query("dai");
	if ((string)ob->query("family/family_name")!="丐帮")
	{
		command("say "+ RANK_D->query_respect(ob) +"非我帮中人，如何可拿青竹令。");
		return 1;
	}
        if ((int)ob->query("score")<n*100){
           command("say 小兄弟还是回去吧!你对本帮贡献不够,不能拿青竹令.");
           return 1;
            }  	
        if (ob->query("combat_exp")<(2000+500*(n-1))*n*n)
	{
		command("say "+ RANK_D->query_respect(ob) +"经验不够，不能拿青竹令。");
		return 1;
	}
	command("say 好吧，凭此令你可以和你的大师兄切磋武艺。");
        obj = new("d/gaibang/obj/qingzhu-ling1");
        obj->move(this_player());
	return 1;
}

int ask_me_2()
{
        object obj;
        object ob=this_player();
        if ((string)ob->query("family/family_name")!="丐帮")
        {
                command("say "+ RANK_D->query_respect(ob) +"非我帮中人，此话从何说起。");
                return 1;
        }
        command("say "+ RANK_D->query_respect(ob) +"把你比武获胜所得的青竹令拿来给我就可以升袋。");
	return 1;
}

int accept_object(object ob, object obj)
{
        object me = this_object();

        mapping my_fam  = me->query("family");
        mapping ob_fam  = ob->query("family");
	object obje;


        if((obj->query("id") == "qingzhu ling")
	&& ((string)ob->query("family/family_name")== "丐帮")
	&& ob->query_temp("have_win"))
        {	
		command("say 既然"+ RANK_D->query_respect(ob) +"战胜了大师兄，那就可以升袋了。");
	ob->delete_temp("have_win");
	ob->set("combat_exp", ob->query("combat_exp") + 1500 * ob->query("dai") * ob->query("dai"));
                obje=new("/d/gaibang/obj/gaibang-bag");
		ob->set("dai", ob->query("dai") + 1);
                obje->move(ob);
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
		return 1;	
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

int ask_me_3()
{
	int i;
	object ob;
	object obj= this_player();

        if ((string)obj->query("family/family_name")!="丐帮")
        {
                command("say "+ RANK_D->query_respect(obj) +"非我帮中人，此话从何谈起。");
                return 1;
        }

	if(!present("budai", obj))
        {
		command("say 不小心死了吧！");
		for(i=1; i<= obj->query("dai"); i++)
		{
			ob=new("/d/gaibang/obj/gaibang-bag");
		ob->move(obj);
		}
        }
	else
        {
            object *bag;
            bag = all_inventory(obj);
            for (i=0;i<sizeof(bag);i++)
                if (bag[i]->query("id") == "bu dai")
                  destruct(bag[i]);
            for (i=0;i<obj->query("dai");i++)
            {
                ob = new("/d/gaibang/obj/gaibang-bag");
                ob->move(obj);
            }
            command("say 我说你也太丢脸了，身为丐帮弟子却把袋子丢了。好好想一想自己的过失。这次就放过你。");
            obj->start_busy(obj->query("dai")*5);
        }

        this_object()->start_busy((10-obj->query("dai"))*5);
	return 1;
}
