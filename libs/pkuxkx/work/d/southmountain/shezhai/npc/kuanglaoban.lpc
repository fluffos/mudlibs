#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_kuang();
int ask_join();
string *types=({"小型","中型","大型","整型"});
string *mines=({"坤地","艮山","坎水","巽風"});
void create()
{
	set_name("钟清律",({"zhong qinglv","zhong","qinglv"}));
    set("title", "矿石店老板"+NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他是在畲寨里收购铁料矿石的商人，这几年生意越做越大，他也越来越有钱了。\n他既高阶出售铁料矿石，同时也低价收购。\n");
    set("attitude","heroism");
    set("generation",0);
    set("max_qi",280);
    set("eff_qi",280);
    set("qi",280);
    set("max_jing",80);
    set("jing",80);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
	set("vendor_goods", ({
			  __DIR__"obj/tieqiao",
			  __DIR__"obj/book-2",
			  __DIR__"obj/book",
              
	}));
	set("inquiry", ([
	"铁料" : (:ask_kuang:),
	"入职" : (:ask_join:),
    	]));
	set("CustomizedAskMode","铁料");
	set("NoBusyAsking",1);
    setup();
    carry_object(__DIR__"obj/rcloth")->wear();
}
int ask_join()
{
	object me=this_player();
	if (me->query("ProfessionalClass/mining"))
	{
		command("say 你已经是一位采矿师了啊。");
		return 1;
	}
	if (me->query_skill("mining",1)<50)
	{
		command("say 等你采矿学知识达到一定程度再来也不迟。");
		return 1;
	}
	if (!me->query_temp("attemptMiner"))
	{
		command("say 你真的想成为一名采矿师吗？如果确定，请再次ask zhong about 入职。");
		me->set_temp("attemptMiner",1);
		return 1;
	}
	me->delete_temp("attemptMiner");
	F_PRO->register_me(me,"mining");//set职业就是核心职业技能,skills有的,注意小写
	return 1;
}
void init()
{
	add_action("do_sell","sell");
	add_action("do_list", "list");
	add_action("do_buy", "buy");
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
		return notify_fail("你要卖什么东西给"+query("name")+"？\n");
            if (!ob->query("is_castmaterial")&&!ob->query("is_castmaterial_piece"))
			{
				command("say 我只收购铁料矿石以及材料碎片。\n");
				return 1;
			}
	message_vision("$N把身上的" + ob->query("name") + "卖给了$n。\n",this_player(),this_object());
	value=ob->query("true_value");
	if (ob->query_amount())
	value*=ob->query_amount();
	pay_player(this_player(), value);
	destruct(ob);

	return 1;
}
int which_type(string arg,object me)
{
	if (member_array(arg,types)==-1)
	{
		message_vision("$N说道：“我还是不要了。”\n",me);
		return 1;
	}
	me->set_temp("tianmuQuests/shezhai/mine_type",arg);
	message_vision("$N说道：“我要"+arg+"的。”\n",me);
	command("tell "+me->query("id")+" 好了，我都记下来了。直接给我钱，我会给你相应数量的铁料的。");
	return 1;
}
int which_mine(string arg,object me)
{
	if (member_array(arg,mines)==-1)
	{
		message_vision("$N对这些铁料并没有什么兴趣。\n",me);
		return 1;
	}
	me->set_temp("tianmuQuests/shezhai/mine",arg);
	message_vision("$N说道：“我要一些"+arg+"。”\n",me);
	command("tell "+me->query("id")+" 每种铁料又分为四类：");
	write(U+"小型"+NOR+"：适合锻造匕、盔。"+U+"中型"+NOR+"：适合锻造刀、剑、鞭。"+U+"大型"+NOR+"：适合杖、斧、枪、锤、戟。"+U+"整型"+NOR+"：适合：铠甲和盾。");
	write("你需要哪一种呢？");
	input_to((:which_type:),me);
	return 1;
}
int ask_kuang()
{
	object me=this_player(),ob=this_object();
	message_vision("$N跟$n打听着，希望收购一点铁料。\n",me,ob);
	command("tell "+me->query("id")+" 我这里有不同的铁料。");
	write(U+"坤地"+NOR+"(1金)、"+U+"艮山"+NOR+"(1.5金)、"+U+"坎水(2.5金)"+NOR+"、"+U+"巽風"+NOR+"(4金)四种级别的铁料。");
	write("你要哪一种呢？");
	input_to((:which_mine:),me);
	return 1;
}
int calc_cost(object me)
{
	int res,*costs=({10000,15000,25000,40000});
	if (!me->query_temp("tianmuQuests/shezhai/mine")||!me->query_temp("tianmuQuests/shezhai/mine_type")) return -1;
	if (member_array(me->query_temp("tianmuQuests/shezhai/mine"),mines)==-1) return -1;
	return costs[member_array(me->query_temp("tianmuQuests/shezhai/mine"),mines)];
}
int accept_object(object me, object ob)
{      
	int cost=calc_cost(me),no;
	object obj;
	if (cost<0) return notify_fail("买铁料之前要先和老板说清楚(ask zhong about 铁料)，不然给错了就不好了。\n");
	if (ob->query("money_id")) 
	{
		if (ob->value() >= cost)
		no=ob->value()/cost;
		else
		return notify_fail("你给的钱连一块"+me->query_temp("tianmuQuests/shezhai/mine")+"之材也不购买呀。\n");
		if (no>50) 
		return notify_fail(me->query_temp("tianmuQuests/shezhai/mine")+"之材的单价是"+MONEY_D->money_str(cost)+"，一次最多买五十个，你最多一次给"+this_object()->query("name")+MONEY_D->money_str(cost*50)+"。\n");
		for (int i=0;i<no;i++)
		{
			obj=new("/obj/smith/materials/material");
			obj->init_material(member_array(me->query_temp("tianmuQuests/shezhai/mine"),mines),member_array(me->query_temp("tianmuQuests/shezhai/mine_type"),types));
			obj->move(me);
		}
		message_vision("$N收下钱之后，给了$n一些"+obj->query("name")+"。\n",this_object(),me);
		ob->move(VOID_OB);
		destruct(ob);
		command("thanks");
		return 1;
	}
	return notify_fail("除了买铁料的钱，"+query("name")+"其他啥也不要。\n");
}