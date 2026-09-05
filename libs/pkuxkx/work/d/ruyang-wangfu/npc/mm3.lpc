//mm3.c -- 汝阳王府美貌女郎
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("美貌女郎", ({ "nv lang", "nvlang", "mei" }));
  set("long", "她的脸上总是挂着盈盈的笑意，浑身上下都透着热情、活力。\n");
	
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
		
	set("shen_type", 1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	set("per", 36);
	
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
				HIB"一位美貌女郎沿着小路款款走来，她目光流转，似乎朝你微微一笑，\n霎时间，你眼中的世界充满了光彩......\n\n"NOR,
        }));

	setup();
	carry_object(__DIR__"obj/skirt-blue")->wear();
}

void init()
{
	object ob;
  ::init();
  if ( interactive(ob = this_player()) && living(this_object()) ) 
  set_heart_beat(1);       
}

