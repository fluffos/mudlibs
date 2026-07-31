#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/温方海"; }
void create()
{
string OBJ_DIR;


        OBJ_DIR="/d/jindezheng/obj";
	set_name("温方海", ({ "wenfanghai", "wenfanghai", "wenfanghai" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位温方海正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		OBJ_DIR+"/guanyin",
		OBJ_DIR+"/shuijinpin",
		OBJ_DIR+"/erping",
OBJ_DIR+"/haierzheng",
OBJ_DIR+"/qiankunhu",
	
	}));
	set("area_name","景德镇温记老店");
	set("area_file","/d/jindezheng/china-shop.c");
	set("ziyuan","瓷器");
	set("jizhi",80);
	set("kaifa",20);



	setup();
 carry_object(__DIR__"obj/fucloth")->wear();
 carry_object("/clone/weapon/changjian")->wield();
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
  if (!ob||environment(ob)!=environment()) return;
  switch(random(3))    {
   case 0:
       command("say 欢道光临本店。");
       break;
   case 1:
       command("say 这位"+RANK_D->query_respect(ob)+",本店的瓷器在景德镇首曲一指.\n");
       break;
   case 2:
       command("say 这几天买瓷器的人真多,该让瓷窑多招些人了!\n");
       break;
       }
  return;
}
