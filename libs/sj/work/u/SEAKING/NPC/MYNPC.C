// meng-zhu.c 武林盟主
// colored the title of 武林盟主(player) ,   ReyGod, 1/15/1997
#include <ansi.h>


#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "meng-zhu"


inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;


string query_save_file()
{
    return MENGZHU;
}


void create()
{
    seteuid(getuid());


    if (!restore()) {
    set_name("天空", ({ "zhan shen", "zhan", "shen" }) );
    set("title", "超级战神" );
    set("gender", "男性" );
    set("age", 40);
      set("long","他就是鼎鼎大名的当今星际战神。\n");
    set("attitude", "heroism");
    set("generation",0);
    set("winner","NONE");


    set("str", 25);
    set("con", 25);
    set("int", 25);
    set("dex", 25);


    set("max_qi", 500);
    set("eff_qi", 500);
    set("qi", 500);
    set("max_jing", 300);
    set("jing", 300);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 40);
    set("shen_type", 0);


    set("no_clean_up",1);
    set("combat_exp", 800000);


    set_skill("force",  200); 
    set_skill("unarmed",200);
    set_skill("sword",  200);
    set_skill("dodge",  200);
    set_skill("parry",  200);

   
    setup();

   }
    else {
        set("id", "zhanshen");
        set_name(query("name"), ({  "zhan shen", "zhan", "shen" }));
        setup();
        if( this_object()->query("my_weapon") ) carry_object(this_object()->query("my_weapon"))->wield();
        if( this_object()->query("my_armor") )  carry_object(this_object()->query("my_armor"))->wear();        
    }
}

