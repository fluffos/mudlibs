 // blue.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(BLU"À¶ÒÂ¹¬Å®"NOR, ({ "blue lady","lady" }) );
        set("nickname",WHT"ÉíËÆ¸¡ÔÆ"NOR);
        set("long", "ËýÉí´©ÇáÉ´ÈáË¿£¬°××ãÈçËª£¬ÇàË¿Æ®Ñï¡£\n");
        set("age", 26);
        set("gender", "Å®ÐÔ");
        set("attitude", "peaceful");
        set("combat_exp", 4400000);  
        set("str",40);
        
        set("no_busy",10);
        
        set("resistance/gin",20+random(20));
        set("resistance/kee",40+random(20));
        set("resistance/sen",random(80));
                        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",100+random(60));
        set("mana",1500);
        set("max_mana",1500); 
        set("marks/Îò³öÁéÏ¬",1);
        set_temp("xinyoulingxi", 1);
        
        set_skill("force", 180);
        set_skill("unarmed", 200);
        set_skill("dodge", 150);
        set_skill("parry",200);

        set_skill("tie-steps",150);
        

        map_skill("dodge","tie-steps");
        map_skill("dodge","tie-steps"); 
        setup();
        armor=new(__DIR__"obj/corclot");
        armor->set_name(BLU"À¶Ë¿ÒÂ"NOR,({"blue cloth","cloth"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corclasp");
        armor->set_name(BLU"À¶Ë¿ïí"NOR,({"blue bangle","bangle"}) );
        armor->move(this_object());
        armor->wear();  
        armor=new(__DIR__"obj/corgirt");
        armor->set_name(BLU"À¶Ë¿´ø"NOR,({"blue belt","belt"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corhat");
        armor->set_name(BLU"À¶Ë¿Ã±"NOR,({"blue hat","hat"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corboot");
        armor->set_name(BLU"À¶Ë¿Ð¬"NOR,({"blue boot","boot"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corribb");
        armor->set_name(BLU"À¶Ë¿½í"NOR,({"blue ribbon","ribbon"}) );
        armor->move(this_object());
        armor->wear();
}      
