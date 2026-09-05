//mm.h -- 汝阳王府美女们
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("花季少女", ({ "shaonv", "shua" }));
  set("long", "这是一名花季少女，典型的一个美人坯子。\n");
	
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
  
  set("chat_chance", 25);
  set("chat_msg", ({
  			"一名妙龄女子从你身旁匆匆走过，留下一缕淡淡的体香，在微风中慢慢飘散……\n",
  			"一名花季少女急匆匆地跑了过去，秀美的长发在微风中飘舞开来，如浪花般在你的眼中荡漾……\n",
				"一位美貌女郎朝着你款款走来，她目光流转，似乎朝你微微一笑，霎时间，你眼中的世界充满了光彩……\n",
				"窗边，一个秀丽的身影飘然而过，稍顷，屋内琴声渐起，似空谷猿啼，又若幽林鸟鸣，听着这犹如天籁的琴声，你静如止水的心湖竟也微微泛起了涟漪……\n",
        }));

	setup();
//	carry_object(__DIR__"obj/puren-fu")->wear();
}
