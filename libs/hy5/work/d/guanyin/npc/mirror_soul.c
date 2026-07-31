#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIW"镜魂"NOR, ({ "mirror soul", "soul" }) );
        set("long", "一个魔气缭绕的黑影。。。\n");
        set("age", 19);
        set("gender", "女性");
        set("attitude", "heroism"); 
        set("max_jing", 2000);
        set("max_qi", 2000);
        set("max_jing", 2000); 
        set("str", 80);
        set("con", 70);
        set("cor", 40);
        set("spi", 40);
        set("int", 20);
        set("cps", 90);
        set("kar", 80);
        set("per", 50); 
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/dodge", 100);
        set_temp("apply/parry", 100);
        set_temp("apply/armor", 120);
        set_skill("parry", 150); 
        set("combat_exp", 3000000);
        setup();
} 
int is_ghost() {        return 1; }  
void die()
{
        object master,room;
        
        room=find_object("/d/guanyin/bedroom");
        if (!objectp(room)) {
                room=load_object("/d/guanyin/bedroom");
        }
        master = find_living("shi guanyin");   //modify master guanyin to shi guanyin
        
   if(master) 
        if(environment(master))
        {
                master->set("agi",10);
                master->set("max_qi",100);
                master->set("eff_qi",100);
                master->set("qi",1);

        }
        :: die();
}      
