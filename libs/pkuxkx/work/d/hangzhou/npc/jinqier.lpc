// 金乞儿  by hubo

inherit NPC;
inherit F_DEALER;
inherit BANKER;

void create()
{
	set_name("金乞儿", ({"jin qier", "jin"}));
	set("title", "钱庄老板");
	set("nickname", "爱财如命");
set("start_room","/d/hangzhou/qianzhuang");
	set("gender", "男性");
	set("attitude", "friendly");
	set("chat_chance", 2);
	set("chat_msg", ({
	"金乞儿骄傲的说道：本老板的名字代表了我的一生\n",
	"金乞儿笑着说道：在本店存钱无利息，无手续费，办理股票开户\n"
	"金乞儿微微一笑，说道：本店还办理不同面额货币的兑换业务。\n"
	}));

	set("shen_type",1);set("score",200);setup();
	add_money("silver", 10);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	      npc::init();
        banker::init();	
}

