//made by goodtaste
// data: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("护院武师", ({ "hu yuan"}));
        
	set("long",
	"他身材魁梧，太阳高鼓，一看就知道是个武林高手\n"
         );
	
	set("gender", "男性");
	
	set("age", 25);
	set("attitude", "heroism");
	set("shen_type", -1);
        set("shen",-40);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 700);
        set("qi", 700);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 80);
        set("combat_exp", 550000+random(100000));
        set_skill("sword",140);
        set_skill("huashan-jianfa",170);
        set_skill("force", 170);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 140);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 140);
        map_skill("sword","huashan-jianfa");
	map_skill("dodge","huashan-shenfa");
	map_skill("parry","huashan-jianfa");
	map_skill("force","taiji-shengong");
        
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();



}
