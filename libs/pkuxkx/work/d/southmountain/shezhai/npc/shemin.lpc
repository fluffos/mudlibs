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
    set("title", "畲民"+NOR);
    set("gender", "男性");
    set("age", 10+random(50));
    set("long", "他是畲寨里一个普通民众，一辈子没有离开过这里。\n");
    set("attitude","heroism");
    set("generation",0);
    set("max_qi",80);
    set("eff_qi",80);
    set("qi",80);
    set("max_jing",80);
    set("jing",80);
    set("shen_type",1);
    set("combat_exp",10000);
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
    carry_object("/clone/cloth/cloth")->wear();
}
int ask_here()
{
	object me=this_player();
	me->add_busy(1);
	command("say 我们山寨可大了，听说比汉人的都城临安府还要大很多。");
	return 1;
}
