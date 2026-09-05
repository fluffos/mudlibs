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
    set("title", HIC"采药人"+NOR);
    set("gender", "男性");
    set("age", 30);
    set("long", "他是在东天目山间活动的采药人，也收购药材。\n");
    set("attitude","heroism");
    set("generation",0);
    set("max_qi",180);
    set("eff_qi",180);
    set("qi",280);
    set("max_jing",80);
    set("jing",80);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
	set("random_npc", 1);

	set("NoBusyAsking",1);
	set("inquiry", ([
	"东天目山" : (:ask_here:),
	"here" : (:ask_here:),
    	]));
	set("chat_chance", 20);
		set("chat_msg", ({
                (: random_move :),
		}) );
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
int ask_here()
{
	object me=this_player();
	me->add_busy(2);
	command("say 那你问我可算问对人了，我在这住了十来年了。");
	command("say 东天目山盛产各种药材，只要找对(lookfor)地方，就可以采集(gahter)。");
	return 1;
}
void init()
{
	add_action("do_sell","sell");
}
void pay_player(object who, int amount)
{
	object ob;

	if( amount < 1 ) amount = 1;
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}
int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖什么药给采药人？\n");
            if (!ob->query("drugcode"))
			{
				command("say 我只收购药材。\n");
				return 1;
			}
	message_vision("$N把身上的" + ob->query("name") + "卖给了$n。\n",this_player(),this_object());
	value=ob->query("value");
	pay_player(this_player(), value);
	destruct(ob);

	return 1;
}