inherit NPC;
inherit F_VENDOR;
string query_save_file() { return DATA_DIR+"npc/周小妹";}

void create()
{

	set_name("周小妹", ({ "xiao mei", "xiaomei", "xiaomei" }) );
	set("gender", "女性" );
	set("age", 22);
	set("long",
		"这位周小妹正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		__DIR__"obj/tea"

	}));


	set("area_name","景德镇碧桐园茶馆");
	set("area_file","/d/jindezheng/tea-room.c");

	setup();
	add_money("silver",5);
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
object ob;
::init();
if (interactive(ob=this_player())&&!is_fighting()) {
remove_call_out("greeting");
call_out("greeting",1,ob);
}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
void greeting(object ob)
{
 if (!living(ob)||environment(ob)!=environment()) return;
command("say 这位客官可要来一碗铁观音,听一会子书?\n");
return;
}


