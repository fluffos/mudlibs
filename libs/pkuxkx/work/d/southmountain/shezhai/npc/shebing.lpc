#include <ansi.h>
inherit NPC;
int ask_here();
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title", HIC+"畲族士兵"+NOR);
    set("gender", "男性");
    set("age", 20+random(20));
    set("long", "他是一个雄健的畲族士兵，正在这里巡逻。\n");
    set("attitude","heroism");
    set("generation",0);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",800);
    set("jing",800);
    set("shen_type",1);
	set_skill("spear",100);
    set("combat_exp",100000);
	set("random_npc", 1);

	set("NoBusyAsking",1);
	set("inquiry", ([
	"山寨" : (:ask_here:),
	"here" : (:ask_here:),
    	]));
	/*set("chat_chance", 20);
		set("chat_msg", ({
                (: random_move :),
		}) );*/
    setup();
    carry_object("/clone/armor/pifeng")->wear();
	carry_object("/clone/weapon/spear/muqiang")->wield();
}
int ask_here()
{
	object me=this_player();
	me->add_busy(1);
	command("say 你为什么要打探我们山寨的消息？我不会告诉你的。");
	return 1;
}
