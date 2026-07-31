#include <ansi.h>
inherit NPC;

void create()

{
	set_name("绿竹翁", ({ "lu zhuweng", "lu", "zhuweng"}));
        set("long", 
"此人琴棋书画无一不精，尤其善于画竹，武功如何就不得而知了。\n");
        set("gender", "男性");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
       
	set("max_qi", 2000);
	set("qi", 2000);
        set("max_jing", 1300);
	set("jing", 1300);
        set("neili", 2000);
	set("max_neili", 2000);
	set("eff_jingli", 1400);
	set("jingli", 1400);
        set("jiali", 50);
        set("combat_exp", 400000);
  
        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("force",140);        
        set_skill("tianmogong",140);
        set_skill("ding-dodge",100);
        set_skill("literate", 150);
	set_skill("tianmo-zhang", 140);
	set_skill("strike", 140);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");	
	map_skill("strike", "tianmo-zhang");
	map_skill("parry", "tianmo-zhang");
	prepare_skill("strike","tianmo-zhang");
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
