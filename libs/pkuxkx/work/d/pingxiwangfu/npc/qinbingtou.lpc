//made by goodtaste
// date: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
void re_rank(object);   

string ask_for_zili();
string ask_for_fanqing();
void create()
{
	set_name("亲兵头", ({ "qin bingtou" , "tou"  }));
        
	set("long",
	"他一副凶神恶煞的样子，警觉的审视着每一个进出王府的人\n"
         );
	
	set("gender", "男性");
	
	set("age", 27);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 19);
	set("con", 20);
	set("dex", 20);
	set("per", 20);
        set("qi",800);
	set("max_qi",800);
	
	set("neili", 150);
	set("max_neili", 150);
	set("jiali", 10);
	set("combat_exp", 100000+random(20000));
	set("random_npc",1);
        set_skill("sword",80);
        set_skill("unarmed",80);
        set_skill("parry",60);
        set_skill("force", 70);
	set_skill("dodge", 70);
        set_temp("apply/attack", 60);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 60);
	set("inquiry", ([
                     
                "自立为王" :(:ask_for_zili:),
                "反清复明" :(:ask_for_fanqing:)
			
	     ]) );
	setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();


}
string ask_for_zili()
{
  object me ,ob;
  me = this_player();
  command("say 原来是来与王爷共谋大业的壮士，快请，快请!\n");
 if (ob = present("tongxingling", this_player()))
                return "你有一个通行令就够了。\n";
                    ob = new(__DIR__"obj/tongxingling");
                    ob->move(this_player());
                    message_vision("亲兵头给了$N一枝通行令。\n", me);
                    me->set_temp("qinbing_asked", 1);
                return "王爷正需要壮士这样的人才，快去吧.\n"; 
     
}  


string ask_for_fanqing()
{
  object me ,ob;
  me = this_player();
 command("kill " + me->query("id"))    ;
return "小子找死!\n";
}  















