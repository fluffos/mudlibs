//mm1.c -- 汝阳王府花季少女
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("花季少女", ({ "shao nv", "shaonv", "shua" }));
  set("long", "她是一名正值花季的少女，典型的一个美人坯子。\n");
	
	set("gender", "女性");
	set("age", 16);
	set("attitude", "peaceful");
		
	set("shen_type", 1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	set("per", 30);
	
  set("combat_exp", 10000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);      
  
  set("chat_chance", 1);
  set("chat_msg", ({
  			HIY"一名花季少女急匆匆地跑了过去，秀美的长发在微风中飘舞开来，\n如浪花般在你的眼中荡漾......\n\n"NOR,
        }));

	setup();
	carry_object(__DIR__"obj/skirt-yellow")->wear();
}

void init()
{
	object ob;
  ::init();
  if ( interactive(ob = this_player()) && living(this_object()) ) 
  set_heart_beat(1);       
}
