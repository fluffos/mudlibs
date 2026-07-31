// shiao.c
inherit NPC;
void create()
{
        set_name("马长老", ({ "ma zhanglao" }));
        set("title","八袋长老");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "一个红光满面的老乞丐。正坐在这里喝酒。\n"
                "  \n");
     //  set("attitude", "peaceful");
        set("str", 20);
        set("int", 30);
       /*   set("combat_exp", 4000000);
                set("chat_chance_combat", 80);
      set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );        
       */ 
        set("force", 600);
        set("max_force", 600);
        set("force_factor", 5);
        
        set("atman", 600);
        set("max_atman", 600);
        
        set("mana", 2000);
        set("max_mana", 1200);
        set("mana_factor", 5);
        
        set("inquiry", ([
                "here" : "这里是铜山村么。\n",
        ]) );
        
        set_skill("literate", 360);
        set_skill("force", 325);
        set_skill("spells", 200);
        set_skill("unarmed", 330);
        set_skill("sword", 340);
        set_skill("parry", 335);
        set_skill("dodge", 340);

        setup();
        
}
