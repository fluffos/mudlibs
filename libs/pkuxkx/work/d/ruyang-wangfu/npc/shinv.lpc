//shinv.c -- 王府侍女
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("王府侍女", ({ "shi nv", "shi", "nv" }));
  set("long", "她是汝阳王府的侍女，是专门伺候王爷、王妃起居的。\n");
	
	set("gender", "女性");
	set("age", 18);
	set("attitude", "peaceful");
		
	set("shen_type", 1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 15);
	set("int", 15);
	set("con", 20);
	set("dex", 20);
	set("per", 20);
	
  set("combat_exp", 10000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);      

	setup();
	carry_object(__DIR__"obj/ruqun")->wear();
	carry_object(__DIR__"obj/banbi")->wear();
}
