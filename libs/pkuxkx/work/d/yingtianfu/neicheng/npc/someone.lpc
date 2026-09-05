//吏部尚书

#include <ansi.h>
inherit NPC;

void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title", HIW"大明 客卿"NOR);
    set("gender", "男性");
    set("age", 50);
    
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
    set_temp("ming/increasecredit",1+random(5));
    
	
    setup();
   
}
void unconcious()
{
        die();
}

void die()
{
    this_object()->fullme();
    return;
}
