#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 5000000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_neili",4000);
        set("neili",4000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        

        set_name("献果神君",({"xianguo"}));
           set("title","十二星象");
        set("long", "“十二星相“中的“猴“。这“猴子”全身虽长着毛，股上虽也长着毛，
但那眼睛、那鼻予，却又像是人的模样。。\n");
        
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
        carry_object(__DIR__"obj/skinmask")->wear();
} 
/*
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        message_vision(CYN"$N冷冷地说：自己滚出去，还是被抬出去？\n"NOR,this_object());
}
*/  
