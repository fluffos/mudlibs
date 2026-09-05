// Npc: /kungfu/class/shaolin/qing-fa.c
// Date: YZC 96/01/19
// modified by iszt@pkuxkx, 2007-02-08

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include <title.h>

string ask_for_join();
string ask_for_join();
string ask_for_leave();

void create()
{
	set_name("清法比丘", ({
		"qingfa biqiu",
		"qingfa",
		"biqiu",
	}));
	set("long",
		"他是一位体格强健的壮年僧人，他生得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : (: ask_for_leave :),
	]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 500);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang-quan", 50);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	create_family("少林派", 40, "弟子");

	setup();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void init()
{
	add_action("do_kneel", "kneel");
	add_action("do_decide", "decide");
}

string ask_for_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？";

	if(!undefinedp(me->query("marry/lover")))
		return "阿弥陀佛！施主尘缘未了，还是罢了吧。";
			if( (string)me->query("gender") != "男性" )

		return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去后山庵里受戒。";

	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。";
}
string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("class")!="bonze" )
		return "阿弥陀佛！施主并未出家，何故跟贫僧开这等玩笑？";

	if( (string)me->query("family/family_name") != "少林派")
		return "阿弥陀佛！施主非我少林弟子，还俗的事情贫僧作不得主。";

	me->set_temp("pending/leave_bonze", 1);
		return "阿弥陀佛！如果" + RANK_D->query_respect(me) + "真想离我佛门而去，就请下决心(decide)吧！";
}

int do_decide()
{
	string* skillname;
	int lev;
	mapping skills;
	int i;
	object me = this_player();
//	object body;
	
	if (me->query_temp("pending/leave_bonze") != 1)
		return 0;
	message_vision("清法比丘对$N说道：「阿弥陀佛！从此施主就不再是我少林门下了，请好自为之！」\n",me);
	tell_object(me,HIR "你决定叛出少林门下！\n" NOR);
	me->delete_temp("pending/leave_bonze");
  me->expell_family("少林派");
	me->delete("shaolin/old_name");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);

//1000exp以下，如果过阵获得过属性，还俗时扣除，防止偷属性。 by all
	if (me->query("xiantian/str/luohan")==2 && me->query("combat_exp") < 1000)
		{
			me->add("str",-2);
			me->add("xiantian/str/luohan",-2);
			me->add("int",-2);
			me->add("xiantian/int/luohan",-2);
			me->add("con",-2);			
			me->add("xiantian/con/luohan",-2);
			me->add("dex",-2);			
			me->add("xiantian/dex/luohan",-2);
		}		
	return 1;
}
		
int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "虚", "空", "明", "净" });
//       ({ "虚", "空", "明", "圆", "净", "悟", "法" });
	string name, new_name,color;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	if( me->query("class") == "officer")
		return notify_fail("你已身在官场，永远也不能回头了。\n");

	message_vision(
		"$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
		me, this_object() );
	me->restore_face(FACE_ORIGIN);
	name = me->query("name");
	color=COLOR_D->get_color(name);
	name=COLOR_D->uncolor(name);
	new_name = prename[random(sizeof(prename))] + name[0..0];
	new_name = color+new_name+NOR;
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("smile");
	me->set("shaolin/old_name",name);
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set_face( FACE_FACT, me->query("name") );
	me->set("class", "bonze");
	if(me->query("family/family_name")=="少林派")
	{
		me->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  me->set_title(TITLE_RANK, me->query("title"));
	}
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);

	return 1;
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主，贫僧可不敢开这等玩笑。");
		return;
	}
	if( (string)ob->query("family/family_name") != "少林派" && ob->query("is_shaolin"))
	{
		command ("say 阿弥陀佛！" + RANK_D->query_respect(ob) +"既然已经叛出少林，那又何必回少林。");
		return;
	}
	if( !ob->query("family")&&ob->query("combat_exp")>5000&&!ob->query("reborn/chushi"))  
	{
		command ("say 阿弥陀佛！本寺不收经验太高的普通百姓！\n");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』吧。");
	}
	command("buddhi qingfa biqiu");
	command("recruit " + ob->query("id"));
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
		ob->set("is_shaolin", 1);
	  if (this_player()->query("class")=="bonze")
  		ob->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
  	else
  		ob->set("title",HIR "少林" NOR + CYN "俗家弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
	}
}

void re_rank(object student)
{
	if (this_player()->query("class")=="bonze")
		student->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
	else
		student->set("title",HIR "少林" NOR + CYN "俗家弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	student->set_title(TITLE_RANK, student->query("title"));
}

