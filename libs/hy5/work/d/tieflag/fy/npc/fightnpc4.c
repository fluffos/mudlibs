#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
void auto_smart_fight();
object *resort_enemy(); 
void ask_help();
void magic_fight();
void do_defense(int n);
void do_remove_defense(int n);
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{ 
         set_name("供奉",({"fighter"}));
        set("title",YEL"探花楼"NOR);
        set("long", "这是探花楼用来愉悦客人的幻象。\n");
        set("str",45);
        set("force_factor",100);  
        set("age",30+random(20)); 
        set("combat_exp", 5500000);
        set("dungeon_npc","test");
        set("attitude", "aggressive");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",100);
        set("no_fly",1);
        
//      set("resistance/gin",10);
//      set("resistance/kee",10);
//      set("resistance/sen",10);
        
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
