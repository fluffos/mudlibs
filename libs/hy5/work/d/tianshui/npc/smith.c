// smith.c

#include <ansi.h>


inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("周铁匠", ({ "zhou", "smith" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "王铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");
        set("combat_exp", 400);
        set("inquiry", ([
		"修理铠甲" : "拿给我看看再说吧。一般的铠甲就算了。\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/hammer")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	if((string)ob->name() != YEL "连锁黄金甲" NOR){
		write("送我东西我就收下了，谢谢。\n");
		command("smile");
		return 1;
	}
	write("周铁匠惊呼道：“这不是连锁黄金甲吗？这可是一件宝甲呀！\n");
	write("听说十几年前流落番帮，这位"+RANK_D->query_respect(ob)+"怎么会得到的？\n");
	write("没想到破旧成这样了，要修这件宝甲我分文不要，请等一下。”\n");
	write("周铁匠生火拿锤开始叮叮当当的忙活起来。\n");
	who->start_busy(4);
	call_out("xiu_li",3,who,ob);
	return 1;
}

void xiu_li(object who,object ob)
{
	ob->set_name(HIY "连锁黄金甲" NOR, ({ "golden armor", "armor" }) );
	ob->set("armor_prop/armor", 300);
	ob->set("long", "一付金光闪闪的连锁铠甲，入手却很轻，不知是由什么做成的。\n");
	write("周铁匠擦擦头上的汗水说道：“可算修好了，象我这样的人见见这东西都是福气。”\n");
	command("give golden armor to "+(string)who->query("id"));
	return;
}
