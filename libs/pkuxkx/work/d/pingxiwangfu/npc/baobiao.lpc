//made by goodtaste
// data: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
void create()
{
	set_name("保镖", ({ "bao biao","bao","biao"}));
        
	set("long",
	"他是一个忠心耿耿的保镖，你要是有什么不轨企图，还是放弃吧!\n"
         );
	
	set("gender", "男性");
	
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
        set("qi", 1000);
        set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
 set("combat_exp", 1250000+random(100000));
        set_skill("sword",180);
        set_skill("huashan-jianfa",180);
        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 180);
        map_skill("sword","huashan-jianfa");
	map_skill("dodge","huashan-shenfa");
	map_skill("parry","huashan-jianfa");
	map_skill("force","taiji-shengong");
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();



}
