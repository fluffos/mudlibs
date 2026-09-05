// npc: /d/city/npc/wei.c
// Jay 5/15/96
// modified by iszt@pkuxkx, 2007-02-07

#include <ansi.h>

inherit NPC;
inherit F_DEALER;


string ask_michun();

void create()
{
	set_name("韦春芳", ({ "wei chunfang", "chunfang", "wei" }) );
	set("gender", "女性" );
	set("title", "丽春院老板娘");
	set("start_room","/d/city/lichunyuan");
//	set("nickname", "鹿鼎公");
	set("age", 42);
	set("long", 
		"韦春芳是当朝鹿鼎公兼红花会总舵主韦小宝他娘，虽是徐"
		"娘半老，但风韵尤存。\n");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
        set("hooker", 1);

	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);

	set("combat_exp", 25000);

	set("max_qi", 300);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);

	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "老娘我就是韦春芳。",
		"韦小宝" : "那是我的乖儿子，长得就像你。",
		"丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
		"here" : "我们丽春院可是扬州城里头一份的找乐子去处。",
		"发泄" : (: ask_michun :),
		"救命" : (: ask_michun :),
	]) );

    set("vendor_goods", ({
            __DIR__"obj/biyuntao",
        }));


	setup();
	set("chat_chance", 20);
	set("chat_msg", ({
		"韦春芳得意地说道：当年老娘我标致得很，每天有好几个客人。\n",
		"韦春芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到丽春院来，老娘用大扫帚拍了出去?。\n",
		"韦春芳对你说道：你一双眼睛贼忒嘻嘻的，真像那个喇嘛！\n",
		"韦春芳上下打量着你：是不是有时候觉得没什么意思？我这里有很多好玩意，买几个回去吧，保你乐不思蜀。\n",
	}) );

	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
	object ob;

	::init();
    add_action("do_list","list");
    add_action("do_buy","buy");
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	if ( !objectp(me) )
		return;
	
	command("look " + me->query("id"));

	if (me->query("gender")=="无性") {
		command("say 你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，就是不伺候太监！");
		command("kick " + me->query("id"));
		message("vision", me->name() +"被韦春芳一脚踢出门外。\n",
			environment(me), ({me}));
		if(base_name(environment(this_object())) == "/d/city/lichunyuan")
		{
			me->move("/d/city/nandajie2");
			return;
		}
		message("vision", me->name() +"被人从丽春院里踢了出来，栽倒在地上，磕掉两颗门牙。\n", 
			environment(me), ({me}));
	}
	else
	{
		if (me->query("class") =="bonze") {
			command("say 呦，" + RANK_D->query_respect(me) 
		+"也来光顾我们丽春院啊。");
		command("say 想当年我接过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。");
		}
		if (me->query("gender")=="女性") {
			command("say 哎呀，这年月大姑娘也逛窑子，成何体统。");
			command("sigh");
			command("say 可惜我儿子不在，不然让他伺候你。");
		}
		command("say 楼上楼下的姑娘们，客人来了！");
	}
	return ;
}

string ask_michun()
{
	object me = this_player();
	if(me->is_busy())
		return "你先忙完你的事吧。";
	if(!me->query_condition("heat"))
	{
		command("giggle");
		return "哟，真是急色的可以。";
	}
	if(MONEY_D->player_pay(me, 10000) == 1)
	{
		me->apply_condition("heat", 0);
		me->start_busy(4);
		message_vision(HIY"韦春芳招招手，一个妓女走了出来，$N喉头低叫一声，不加思索就扑了上去……\n"
			"就在众目睽睽之下，二人云雨起来。虽是烟花之地，众人却也看得呆了。\n"
			HIR"$N纵欲完毕，体内的热毒总算清干净了。\n"NOR, me);
		CHANNEL_D->do_channel(this_object(), "rumor", me->name()+"在丽春院做的事真是荒唐之极……");
		return "怎么样？还满意么？";
	}
	return "做什么也要带银子啊，不带着银子谁给你做？一百两，也不多。";
}
