inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

string ask_me(); 



void greeting(object ob);

void create()
{
    seteuid(getuid());
    set_name("燃灯大师", ({ "yideng dashi", "yideng", "dashi" }));
    set("long","燃灯大师乃江湖中人称“东邪西毒，南帝北丐”中的南帝段"
		"皇爷，当年凭着段氏“玄阳指”而独步武林，罕逢敌手。但"
		"却在中年时因一段悲情而出家为僧，之后大彻大悟，成为一"
		"位得道高僧。");
    set("title",HIY "大理段皇爷" NOR);
    set("nickname", HIY "南帝" NOR);
    set("gender", "男性");
    set("age", 71);
	set("no_get", 1);
    set("shen_type", 1);
    set("attitude", "friendly");

    set("str", 33);
    set("int", 35);
    set("con", 38);
    set("dex", 33);

    set("qi", 5800);
    set("max_qi", 5800);
    set("jing", 2700);
    set("max_jing", 2700);
    set("neili", 8000);
    set("max_neili", 8000);
    set("jiali", 120);

    set("combat_exp", 2900000);
    set("score", 455000);

    //不能学习
    set_skill("force", 280);
    set_skill("dodge", 280);
    set_skill("parry", 280);
    set_skill("cuff", 280);
    set_skill("sword", 280);
    set_skill("staff", 280);
    set_skill("finger", 280);
    set_skill("duanshi-xinfa", 280);
    set_skill("tiannan-step", 280);
    set_skill("jinyu-quan", 280);
    set_skill("duanjia-sword", 280);

    //段家可以学习
    set_skill("sun-finger", 280);

    //其它可以学习
    set_skill("literate", 200);
    set_skill("sanscrit", 200);
    set_skill("buddhism", 200);

    map_skill("force", "duanshi-xinfa");
    map_skill("dodge", "tiannan-step");
    map_skill("finger", "sun-finger");
    map_skill("cuff", "jinyu-quan");
    map_skill("strike", "wuluo-zhang");
    map_skill("parry", "sun-finger");
    map_skill("sword", "duanjia-sword");
    map_skill("staff", "duanjia-sword");

    prepare_skill("finger", "sun-finger");

    set("inquiry",([
	  "王重阳" :     "中神通王重阳名动江湖，老衲很是佩服。\n",
	  "英姑" :       "那是老衲出家前的一段孽缘，不提也罢。\n",
	  "老顽童" :     "呵呵，那人武功高强，可是心机却如顽童一般。\n",
	  "郭大侠" :       "哦，那个憨小子心地善良，忠厚老实，没黄帮主一定要吃亏。\n",
	  "黄帮主" :       "是郭大侠那憨小子的伴侣吧，人倒很是机灵。\n",
	  "传授" :       "我只能传授你 禅宗心法 (buddhism)、读书写字 (literate)和梵文 (sanscrit)，其\n它的找你的师父学习吧。\n",
	  "玄阳指" : (: ask_me :),
    ]));

    setup();
    carry_object("/clone/cloth/seng-cloth")->wear();

	create_family("段氏皇族", 11, "传人");

}

void greeting(object ob)
{
	if (! ob || environment(ob)!=environment()) return;
	if ((int)ob->query("shen") < -50000)
	{
		command("say 这位施主眼中戾气深重，劝施主好自为知。");
	} else
	if ((int)ob->query("shen") < -5000)
	{
		command("say 这位施主，切记魔从心起，其道必诛。");
	} else
	if((int)ob->query("shen") < -100)
	{
		command("say 这位施主，人行江湖，言行当正，切务走进邪魔歪道。");
	} else
	if((int)ob->query("shen") >= 0)
	{
		command("say 这位施主，光明正道任人走，望施主多加保重。");
	} else
	if((int)ob->query("shen") > 50000)
	{
		command("say 这位施主行事光明磊落，日必为武林翘楚。");
	}
	return;
}

int accept_fight(object ob)
{
	if ((ob->query("combat_exp") < 50000))
	{
	message_vision("燃灯大师微笑道：这为" + RANK_D->query_respect(ob) +
		       "，你不是老衲的对手，别作无谓之争。\n",ob);
	return 0;
	}
	message_vision("燃灯大师微笑道：这位" + RANK_D->query_respect(ob) +
		       "，老衲领教了。\n", ob);
	return 1;
}

string ask_me() 
{
	object me;

	me = this_player();

	if (me->query("shen") < 0)
		return "施主眼中戾气深重，多行善之后老衲自会传授给你。";

	if (me->query_skill("sun-finger", 1) > 280)
	       return "你的玄阳指练到了这种境界，老衲已没什么可教的了。";

	if (me->query("family/family_name") != query("family/family_name"))
	       return "不是老衲吝啬，你不是我段家之人，若由老衲之手将这绝学传于它处，恐怕不妥。";

	if (me->query("combat_exp") < 500000)
	       return "武功最注重根基，切莫贪图捷径，你把基本功练好后老衲自会传授给你。";

	me->add_temp("can_learn_sun-finger/yideng", 1);
	       return "好吧！老衲就传授玄阳指绝技给你，但切记人行江湖，言行当正，不要走进邪魔歪道！"; 
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("shen") < 0)
	{
		command("say 施主眼中戾气深重，多行善之后老衲自会传授给你！");
		return -1;
	}

	if (skill != "literate" && skill != "sanscrit" && skill != "buddhism" && skill != "sun-finger")
	{
		command("say 这些还是向你的师父学吧，我能传授一些知识给你。");
		return -1;
	}

	if (!me->query_temp("can_learn_sun-finger/yideng") && skill == "sun-finger")
	{
		command("say 玄阳指我不轻易传授。");
		return -1;
	}

	return 1;
}
