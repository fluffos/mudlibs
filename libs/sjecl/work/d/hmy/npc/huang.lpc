#include <ansi.h>
inherit NPC;
void create()
{
      
	set_name("黄伯流", ({ "huang boliu", "huang", "boliu"}));
	set("nickname", "银髯蛟");        
        set("long", 
"他一部白须，直垂至胸，精神却甚矍铄。。\n");
        set("title",HIY"日月神教  "HIC"风雷堂香主"NOR);
        set("gender", "男性");
        
	set("age", 70);
	set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 2500);
        set("max_jing", 1500);
        set("eff_jingli", 1500);
        set("jiali", 50);
        set("combat_exp", 1200000);
     
        set_skill("parry",170);
        set_skill("dodge",170);
        set_skill("force",170);
        set_skill("strike",170);
        set_skill("literate", 100);      
        set_skill("ding-dodge",170);
        set_skill("huntian-qigong",170);
        set_skill("tiangang-zhang",170);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "huntian-qigong");
        map_skill("parry", "tiangang-zhang");
        map_skill("strike", "tiangang-zhang");
        prepare_skill("strike", "tiangang-zhang");
        
	create_family("日月神教",3,"弟子");
        setup();
}
