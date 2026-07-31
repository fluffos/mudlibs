// fangbilin.c 方碧琳
// create by host dec,16 1997

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("方碧琳", ({ "fang bi lin", "fang", "bilin"}));
        set("long",
      "她是一位峨嵋派的俗家女弟子，专门管理一些峨嵋俗物。\n");
        set("gender", "女性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 400);
        set("max_qi", 400);
        set("jing", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);

        set("combat_exp", 9000);
      
        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("strike",40);
      
        create_family("峨嵋派", 5,"弟子");
        setup();
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
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say("方碧琳笑吟吟地说道：这位" + RANK_D->query_respect(ob) + "请先入座，" + "我这就给您上茶。\n");
}

void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

 	obn = new("d/wudang/obj/xiangcha");
	obn->move(who);
	message_vision("方碧琳端出个一个精致的小茶壶，沏了杯香茶，放在桌上。\n",who);

 	obn = new("d/wudang/obj/mitao");
	obn->move(who);
	message_vision("方碧琳拿出一碟新鲜的水蜜桃，放在桌上．\n", who);
	
	return;
}
void attempt_apprentice(object ob)
{
   command("shake");  
   command("say 要拜师学艺，你还是找大师姐贝锦仪吧！\n");
                return;
 }
