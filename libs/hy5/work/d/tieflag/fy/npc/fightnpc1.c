#include <ansi.h>
inherit NPC;
void auto_smart_fight();
void ask_help();
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{ 
         set_name("小厮",({"fighter"}));
        set("title",YEL"探花楼"NOR);
        set("long", "这是探花楼用来愉悦客人的幻象。\n");        
            set("str",30);
        set("force_factor",90);
        set("age",10+random(10)); 
        set("combat_exp", 1000000);
        set("dungeon_npc","test");
                
        set("max_atman", 500);
        set("atman", 500);
        set("max_mana", 500);
        set("mana", 500);
        set("max_neili",800);
        set("neili",800);
        set("force_factor",60);
        set("no_fly",1);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);

        setup();

        carry_object("/clone/misc/cloth")->wear();

} 
void die(){
        object book;
        int i;
        message_vision(HIR"\n$N惨叫一声倒了下去，化作一阵轻烟消失了。\n"NOR,this_object());     

        destruct(this_object());        
}   
