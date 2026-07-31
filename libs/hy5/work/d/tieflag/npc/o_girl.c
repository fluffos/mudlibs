// orange.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(HIY"³ÈÒÂ¹¬Å®"NOR, ({ "orange lady","lady" }) );
        set("nickname",WHT"ÆøÈôÓÎË¿"NOR);
        set("long", "ËýÉí´©ÇáÉ´ÈáË¿£¬°××ãÈçËª£¬ÇàË¿Æ®Ñï¡£\n");
        set("age", 26);
        set("gender", "Å®ÐÔ");
        set("attitude", "peaceful");
        set("combat_exp", 4400000);  
        set("str",40);
        set("no_busy",10);
        
        set("resistance/gin",random(90));
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
        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("dodge", 200);

        set_skill("tie-steps",180);
        

        map_skill("dodge","tie-steps");
        map_skill("dodge","tie-steps"); 
        setup();
        armor=new(__DIR__"obj/corclot");
        armor->set_name(HIY"³ÈË¿ÒÂ"NOR,({"orange cloth","cloth"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corclasp");
        armor->set_name(HIY"³ÈË¿ïí"NOR,({"orange bangle","bangle"}) );
        armor->move(this_object());
        armor->wear();  
        armor=new(__DIR__"obj/corgirt");
        armor->set_name(HIY"³ÈË¿´ø"NOR,({"orange belt","belt"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corhat");
        armor->set_name(HIY"³ÈË¿Ã±"NOR,({"orange hat","hat"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corboot");
        armor->set_name(HIY"³ÈË¿Ð¬"NOR,({"orange boot","boot"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corribb");
        armor->set_name(HIY"³ÈË¿½í"NOR,({"orange ribbon","ribbon"}) );
        armor->move(this_object());
        armor->wear();
}   
