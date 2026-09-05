//mm4.h -- 汝阳王府淡妆丽人
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("淡妆丽人", ({ "li ren", "liren", "li" }));
  set("long", "她本生就一副国色天香的容貌，此时仅施淡妆，仍然让人心动不已。\n");
	
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
	set("per", 39);
	
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
  			HIW"窗边，一个秀丽的身影飘然而过，稍顷，屋内琴声渐起，似空谷猿啼，又若幽林鸟鸣，\n听着这犹如天籁般的琴声，你静如止水的心湖竟也微微泛起了涟漪......\n\n"NOR,
        }));

	setup();
	carry_object(__DIR__"obj/skirt-white")->wear();
}

void init()
{
	object ob;
  ::init();
  if ( interactive(ob = this_player()) && living(this_object()) ) 
  set_heart_beat(1);       
}
