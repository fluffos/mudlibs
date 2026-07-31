// zhao_qixian.c

inherit NPC;

string *make_msg = ({
	"我知道一个秘密，就告诉你，以后赌场上有个失手，你可要照顾照顾我。\n",
	"这个秘密就在粮库，你去找马飞虎将军，那是我的结拜大哥。\n",
	"你说是我让你去的，他会告诉你这个秘密。\n",
});

void create()
{
	set_name("赵齐贤", ({ "zhao qixian","zhao" }) );
	set("gender", "男性" );
	set("age", 32);
	set("title","边关大营副将");
	set("long", "他身材雄壮，一付英雄气概。\n");
	set("per", 25);
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("parry", 70);

	set("inquiry", ([
		"赌" : "对，就咱们两个玩几把。\n",
	]) );
	set("money_my",200);
	setup();
	add_money("silver", 2);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet","bet");
}

void greeting(object ob)
{

        if( !query("bet_another_name") && ob && environment(ob) == environment() )
		say("赵齐贤说道：“这位"+RANK_D->query_respect(ob)+"愿不愿意和我对赌两把呀？”\n");
}

int do_bet(string arg)
{
	int duzhu,a,b,c,pkar;
	object me,mtype;
	string decision;
	me = this_player();
	if(!arg)
		return notify_fail("bet big|small <amount>\n");
        sscanf(arg,"%s %d",decision,duzhu);
	if(!arg)
		return notify_fail("bet big|small <amount>\n");
        mtype = present("silver_money", me);
        if( !mtype)
		return notify_fail("你身上没有银子。\n");
	 if( (int)mtype->query_amount() < duzhu)
		return notify_fail("你身上没有那么多" + mtype->query("name") + "。\n");
        if ( (decision != "big") && (decision != "small") )
                return notify_fail("你要赌大还是赌小？\n");
	if( duzhu < 1 )
		return notify_fail("你要压多少啊？\n");
	if( duzhu < 5 )
		return notify_fail("一次最少押五两银子。\n");
	if( duzhu > 20 )
		return notify_fail("一次最多押二十两银子。\n");
	if( (int)query("money_my") <= 0 )
		return notify_fail("赵齐贤说道：“唉，钱都输没了，能不能先借我两百两银子？”\n");

	if(!query("bet_another_name"))
	{
	set("bet_another_name",me->name());
	set("bet_another_id",me->query("id"));
	}

	if(me->query("id") != query("bet_another_id") &&
		present((string)query("bet_another_id"),environment(this_object())))
		return notify_fail("赵齐贤说道：等一等，我正和"+(string)query("bet_another_name")+"对赌。\n");
	if(!present((string)query("bet_another_id"),environment(this_object())))
	{
	set("bet_another_name",me->name());
	set("bet_another_id",me->query("id"));
	set("money_my",200);
	}

	pkar = me->query("kar");
	if(random(pkar)+random(20) >= 23){
	if(decision == "big")
		{
			a=random(3)+4;
			b=random(3)+4;
			c=random(3)+4;
			message_vision("开：" + a + "   " + b + "   " + c + "   ，  大\n", me);
			message_vision(me->query("name") + "赢了" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "。\n", me);
			mtype->set_amount((int)mtype->query_amount() + duzhu);
			mtype->move(me);
			add("money_my",-duzhu);
			if( (int)query("money_my") <= 0 ) {
				say("赵齐贤说道：“唉，都输光了，能不能先借我两百两银子？”\n");
				me->set_temp("duchang/winner",1);
			}
			return 1;
		}
	if(decision == "small")
		{
			a=random(3)+1;
			b=random(3)+1;
			c=random(3)+1;
			message_vision("开：" + a + "   " + b + "   " + c + "   ，  小\n", me);
			message_vision(me->query("name") + "赢了" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "。\n", me);
			mtype->set_amount((int)mtype->query_amount() + duzhu);
			mtype->move(me);
			add("money_my",-duzhu);
			if( (int)query("money_my") <= 0 ) {
				say("赵齐贤说道：“唉，都输光了，能不能先借我两百两银子？”\n");
				me->set_temp("duchang/winner",1);
			}
			return 1;
		}
	}
	else {
	if(decision == "small")
		{
			a=random(3)+4;
			b=random(3)+4;
			c=random(3)+4;
			message_vision("开：" + a + "   " + b + "   " + c + "   ，  大\n", me);
			message_vision(me->query("name") + "输了" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "。\n", me);
			mtype->set_amount((int)mtype->query_amount() - duzhu);
			mtype->move(me);
			add("money_my",duzhu);
			return 1;
		}
	if(decision == "big")
		{
			a=random(3)+1;
			b=random(3)+1;
			c=random(3)+1;
			message_vision("开：" + a + "   " + b + "   " + c + "   ，  小\n", me);
			message_vision(me->query("name") + "输了" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "。\n", me);
			mtype->set_amount((int)mtype->query_amount() - duzhu);
			mtype->move(me);
			add("money_my",duzhu);
			return 1;
		}
	}
}

int accept_object(object me, object obj)
{
	if(!me->query_temp("duchang/winner")){
		say("这位"+RANK_D->query_respect(me)+"真是慷慨大方，谢谢了。\n");
	return 1;
	}
	if(!obj->value()){
		say("这里只赌现银，东西不收。\n");
	return 1;
	}
	if(obj->query("id") != "silver"){
		say("这里只能用银子下赌注。唉......\n");
	return 1;
	}
	if(obj->value() < 20000){
		say("就这么点钱，我又不是不还你，哼。\n");
	return 1;
	}

	me->start_busy(3);

	tell_object(environment(),"赵齐贤说道：“这位"+RANK_D->query_respect(me)+
		"赌技高超，人又如此大方，佩服！小弟交了你这个朋友了”\n");
	call_out( "make_stage", 1, me );

	return 1;
}

void make_stage(object who, int stage)
{
	tell_object(who, make_msg[stage]);
	if( ++stage < sizeof(make_msg) ) {
	call_out( "make_stage", 1, who, stage );
	return;
	} else

	tell_object(environment(),"赵齐贤说道：今天手气太差，回去休息一下换换手。\n");
	tell_object(environment(),"赵齐贤往下离开。\n");
	who->delete_temp("duchang/winner");
	who->set_temp("duchang/zhao",1);
	destruct(this_object());
    return;
}