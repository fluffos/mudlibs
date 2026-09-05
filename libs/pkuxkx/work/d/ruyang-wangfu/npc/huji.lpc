//huji.c -- 汝阳王府美艳胡姬
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("胡姬", ({ "hu ji", "huji", "hu" }));
  set("long", 
						"她上身似乎只围了条暗绿色薄如蝉翼的纱巾，下身则穿了一条\n"
						"雪白的波斯宽褶长裤，一面同样暗绿色的轻薄面纱，遮住了她\n"
						"大半幅面颊。但露出来的眸子里，总闪动着星星点点异样的光\n"
						"芒，有一种与中原迥异的别样的风情，使你不敢直视。\n" );
	
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
		
	set("shen_type", -1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	set("per", 42);
	
  set("combat_exp", 10000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);      

	setup();
	carry_object(__DIR__"obj/bosi-changku")->wear();
	carry_object(__DIR__"obj/manao-yaodai")->wear();
	carry_object(__DIR__"obj/bosi-shajin")->wear();
	carry_object(__DIR__"obj/baoshi-xianglian")->wear();
	carry_object(__DIR__"obj/fire");
}
