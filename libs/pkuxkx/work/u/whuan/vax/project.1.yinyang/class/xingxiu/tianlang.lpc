// tianlang.c 天狼子
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("nickname", "星宿派三师兄");
          set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
	set("long", 
		"他就是丁春秋的三弟子天狼子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);

	set_skill("force", 70);
        set_skill("handu-xinfa", 70);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 70);
              set_skill("strike", 70);
	set_skill("xingxiu-duzhang", 70);
        set_skill("hand", 80);
        set_skill("zhaixing-shou", 80);
	set_skill("parry", 70);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
               map_skill("hand", "zhaixing-shou");
              map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
              prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
}

