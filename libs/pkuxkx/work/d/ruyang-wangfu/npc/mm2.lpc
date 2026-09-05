//mm2.c -- 汝阳王府妙龄女子
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("妙龄女子", ({ "nv zi", "nvzi", "miao" }));
  set("long", "她是一名正值妙龄的女子，娴静、幽然，宛如一块温润的美玉。\n");
	
	set("gender", "女性");
	set("age", 18);
	set("attitude", "peaceful");
		
	set("shen_type", 1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	set("per", 33);
	
  set("combat_exp", 10000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);      
  
  set("chat_chance", 2);
  set("chat_msg", ({
  			HIG"一名妙龄女子从你身旁匆匆走过，留下一缕淡淡的体香，\n在微风中慢慢飘散......\n\n"NOR,
        }));

	setup();
	carry_object(__DIR__"obj/skirt-green")->wear();
}

void init()
{
	object ob;
  ::init();
  if ( interactive(ob = this_player()) && living(this_object()) ) 
  set_heart_beat(1);       
}
