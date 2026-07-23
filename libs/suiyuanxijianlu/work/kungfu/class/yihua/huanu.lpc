
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
	set_name("移花宫花奴", ({ "hua nu", "hua", "nu"}));
	set("long",
	    "这是个容貌动人的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n"+
	    "真是绝代佳人.\n");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("parry", 170);
	set_skill("sword",200);
	set_skill("unarmed",200);

	set_skill("jueqing-zhang",180);
	set_skill("mingyu-shengong",200);
	set_skill("yihua-jiemu",180);
	set_skill("yifeng-jian",180);

	map_skill("unarmed", "jueqing-zhang");
	map_skill("force", "mingyu-shengong");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
	map_skill("sword", "yifeng-jian");

	prepare_skill("sword","yifeng-jian");
	create_family("移花宫",3,"花奴");
	setup();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
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
       if ((string)ob->query("family/family_name") == "移花宫") 
             {
               message_vision("花奴冲着$N点点头，微微笑了笑。\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("花奴冲着$N微笑说：移花宫的功夫可是天下第一。\n",ob);
               return;
              }
}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="女性")
   {
		message_vision("花奴垂目沉思片刻, 说道：“好吧, 我就收下你了。不过不能让宫主知道,不然我可保不了你”\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "huanu")
			ob->set("class", "huanu");
       return;}
   else
      {
		message_vision("花奴瞪着你看了半天,说道：“移花宫向来不收男弟子,你再叫我就去告诉宫主!”\n",ob);
       return;}
}
