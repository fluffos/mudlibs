//xuan-ci.c 少林寺方丈
//wirted by piao 2001-10-04
#include <ansi.h>

string ask_for_leave();
string ask_mieyao(object me);
string ask_cancel();

inherit NPC;
inherit F_MASTER;
void create()
{

        set_name("玄慈大师", ({
                "xuanci dashi",
                "xuanci",
		"dashi",
	}));
        set("gender", "男性" );
        create_family("少林寺", 2, "弟子");
        set("title",HIW"嵩山少林寺方丈大师"NOR );
        set("age", 70);
set("long",
		"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 3500);
        set("max_force", 3500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 3500);
        set("mana_factor", 20);
        set("combat_exp", 2500000);
        set("daoxing", 3000000);

        set_skill("banruo-zhang", 280);
        set_skill("jingang-leg", 280);
        set_skill("yijinjing", 300);
        set_skill("chanzong", 300);
        set_skill("literate", 300);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("shaolin-shenfa", 280);
        set_skill("parry", 280);
        map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "jingang-leg");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

        set("max_kee", 1300);
        set("inquiry", ([
    "降妖": (: ask_mieyao :),
		"下山" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
      "cancel": (: ask_cancel :),
      ]) );
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	name = ob->query("name");

        if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
        }

          if( (int)ob->query_skill("yijinjing",1) < 180)
        {
	command("say " + RANK_D->query_respect(ob) + "，你易筋经修为不够，不能越级拜师。");
                return;
        }

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林寺")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林寺") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY"嵩山少林寺罗汉堂大弟子"NOR);
}
string ask_for_leave()
{
	object me=this_player();
	if (me->query("family/family_name") == "少林寺" ) {
		command("say 你既是执意下山，贫僧却有几句话说。");
		me->set_temp("betray", 1);
		return ("脱离师门要需要有一定惩罚，你可愿意(agree)?\n");
       }
	return ("贫僧不知。\n");
}

int do_agree(string arg)
{	if (this_player()->query("family/family_name") == "少林寺" )
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N答道：弟子愿意。\n\n", this_player());
		this_player()->add("betray/shaolin", 1);
		this_player()->add("betray/count", 1);
		command("say 既是你与佛门无缘，你便下山去吧！\n");
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		this_player()->delete("family");
		this_player()->delete("class");
                this_player()->delete_skill("yijinjing");
                this_player()->set("title","普通百姓");
		this_player()->set_temp("betray", 0);
		command("say 江湖风波，善恶无形，好自为之。。。\n");
		this_player()->save();
		return 1;
	}
}
	else return notify_fail("什么？\n");
}

void init()
{
        add_action("do_kneel", "kneel");
        add_action("do_agree", "agree");
}

string ask_mieyao(object me)
{
    object who=this_player();
    if((string)who->query("family/family_name")=="少林寺") {
      command("say 灭妖除魔，乃我佛门中人之本分。");
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}

int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="少林寺")
     return notify_fail(this_object()->query("name")+"说：你又不是少林弟子，拜我干什么？\n");
    if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say 既然如此，就算了吧，不过你没有完成任务，得受些惩罚！\n");
        who->add("faith",-5);
        message_vision("$N的忠诚度下降了！\n",who);
     }
     return 1;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}

