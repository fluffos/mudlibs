//made by goodtaste
// date: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
string ask_for_huadao();
void re_rank(object);   

void create()
{
	set_name("花农", ({ "hua nong" , "nong"  }));
        
	set("long",
	"一个六旬的老人，终身与花为伴，爱花如命\n"
         );
	
	set("gender", "男性");
	set("age", 69);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("combat_exp", 2000+random(2000));
	set("score", 1000);
	set("count",1);
        set("inquiry", ([
                     
                "花道" :(:ask_for_huadao:),
              ]) );
	setup();
        carry_object("/d/city/obj/cloth")->wear();
} 


string ask_for_huadao()
{
  object me ,ob;
  me = this_player();
  if (this_object()->query("count") == 0)
  	return "我身上已经没有百合花了。\n";
  command("say 人生能得几知己，我爱花一生，就是少有人明白此中真意，\n");
  command("say 只有" + RANK_D->query_respect(me) + "才知我心啊 ！");
  this_object()->delete("count");

if (present("baihe hua", this_player()))
                return "想不到你如此贪心！，哎....\n";
               command("say 小小礼物，不成敬意，请笑纳");
               command("say 此花来自西方天佛山，嗅之有延年益寿之功效，但却不可多用否则无益反害\n");
               ob = new(__DIR__"obj/baihehua");
               ob->move(this_player());
               message_vision("花农给了$N一枝百合花。\n", me);
               me->set_temp("huanong_asked", 1);  
       return "花道人道...可意会难言道...\n";
     
}  
















