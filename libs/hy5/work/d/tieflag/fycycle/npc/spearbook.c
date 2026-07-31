 inherit NPC;
#include <ansi.h> 
void create()
{
    set_name("雕像", ({ "statue","雕像"}) );
    
    set("str", 6000);
    set("resistance/gin",100);
    set("resistance/kee",100);
    set("resistance/sen",100);
    set("combat_exp", 10000000);
        
    set_skill("spear",400);
       
    set("no_shown",1);
    
    setup();
} 
int recognize_apprentice(object ob)
{
        if(ob->query_skill("spear",1)>=200)
                return 1;
        else 
                tell_object(ob,"你的枪术不够精深，无法进一步领略雕像的内涵。\n");
                return 0;
} 
void init(){
        add_action("do_look", "look");
        ::init();
} 
int do_look(string arg) {
        if(arg == "白玉的雕像" || arg == "雕像" || arg == "statue"){
                write("一个白玉的雕像。\n");
                return 1;
        }
        return 0;
}    
