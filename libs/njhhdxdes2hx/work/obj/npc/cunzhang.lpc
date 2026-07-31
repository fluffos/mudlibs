#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
string smoking();

void create()
{
	set_name("老村长", ({ "cunzhang" }) );
	set("gender", "男性" );
	set("age", 76);
        set("long","这是一个干瘦的老头儿, 他是远近闻名的色鬼。\n");
	set("force",10000);
	set("max_force", 10000);
	set("combat_exp", 200000);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set("chat_chance",15);
	set("chat_msg", ({
		(: smoking :),
		"老村长边数着金子边自言自语：一户十两, 十户百两, 这房地产生意真发呀!!!\n",
		"老村长得意的哼起了小调：提起那宋老三, 两口子卖大烟…\n",
	}));
	set("vendor_goods", ([
		"户口卡" : "/d/hua/obj/hukou",
	]));
	
	set("shen_type",-1);
	setup();
	
	carry_object("/obj/cloth")->wear();
	carry_object("/d/hua/obj/smokepipe")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	if (ob->query("gender") == "女性")
		message_vision("老村长一见$N走进来两只眼睛泛着绿光, 说道：这位" + RANK_D->query_respect(ob)+"想找住处吗? 我家宽敞, 到我家来吧。\n"
"说话间口水流出老长…, 噢, 好恶心耶!!!\n", ob);
	else
		say("老村长一见有人进来, 眼睛笑成了一条缝：这位" + RANK_D->query_respect(ob)+"想在本村安家吗? 我代表全村表示欢迎! \n");
}

string smoking()
{
	command("smoke pipe");
	return "\n";
}
