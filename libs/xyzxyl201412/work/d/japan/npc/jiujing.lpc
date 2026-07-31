inherit NPC;
#include <ansi.h>
inherit F_DEALER;
//string query_save_file() { return DATA_DIR + "npc/酒井太郎"; }
void create()
{
   set_name("酒井太郎",({"jiujing tailang","jiujing","tailang"}));
  set("title","神户铁匠铺");
// set("area_file","/d/japan/tiejiangpu");
//  this_object()->init_bhnpc();

set("vendor_goods", ({
       __DIR__"obj/fusangjian",
       __DIR__"obj/fusangdao",
       __DIR__"obj/duanbi",
       __DIR__"obj/hujia",
       __DIR__"obj/toukui",
	}));
	setup();
}
void init()
{       
        object ob;

        ::init();
	if(interactive (ob=this_player()) && !is_fighting() )
{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");

 }



void greeting(object ob)
{

         if( !ob || environment(ob) != environment() ) 
		return;
         if(random(10)>5)
        say(name()+"上前道："+ ob->query("name") +
      "你的要买些什么的？\n");
 }
