//quyang.c 曲洋
//by bing

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("曲洋", ({ "qu yang", "qu","yang" }));
        set("title",MAG "日月神教" NOR + HIY "长老" NOR);
        set("long","这老者六十来岁年纪，身负重伤，鲜血把他的衣服都染红了。
只有进气，没有出气，随便谁看一眼都知道是没救了。\n");
	set("gender", "男性");
        set("age", 63);
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 1200);
	set("eff_qi",50);
        set("max_jing", 600);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        set("combat_exp", 400000);
	set("score",1000);
        set("chat_chance", 30);
        set("chat_msg", ({
		"曲洋有气无力的呻吟道：「水......水.....」\n",
        }));
        set_skill("force", 150);
        set_skill("riyue-shengong", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
	set_skill("sword",150);
	set_skill("riyue-jian",150);
        set_skill("feitian-shenfa", 150);
        set_skill("literate",170);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","riyue-jian");
	create_family("日月神教", 21, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
       }

int accept_object(object who, object ob)
{
	object book;
	who = this_player();
	if( ob->query("liquid/remaining")>0 ) 
	{
		this_object()->start_busy(10);
		message_vision("曲洋接过" + ob->query("name") + "颤抖着喝了几口，脸上有了点血色。\n",who);
		command("say 多谢这位" + RANK_D->query_respect(who) + "了，我这里有一本《笑傲江湖之曲》，留给"  + RANK_D->query_respect(who) + 
"作个纪念。如果遇到善琴会箫之人，麻烦" + RANK_D->query_respect(who) + "传给了他。");
		book = new(__DIR__"obj/book1");
		book->move(who);
		message_vision("曲洋给了$N一本《笑傲江湖之曲》。\n",who);
		message_vision("曲洋忽然高声叫道：「那个庄稼人是，是华......」\n",who);
		call_out("destroying",0);
		return 1;
	}
	message_vision("曲洋对着$N怒目而视，说道：「你！你！......」\n",who);
	message_vision("一口气没喘上来，身子一软，躺在了地上。\n",who);
	call_out("destroying",0);
	return 1;
}

void destroying()
{
	object obj = this_object();
	obj->die();
}


