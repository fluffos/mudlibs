//Zine 艄公，长江边收钱的，钱多船就快

inherit NPC;
#include <ansi.h>
#include "change.h";
string ask_me();
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));	
        set("title", color[random(sizeof(color))]+"老艄公"+NOR);
        set("gender", "男性");
        set("age", 60+random(10));
        set("str", 20);
        set("dex", 20);
        set("long", "他是长江边的老艄公，撑渡船几十年了。\n");
        set("combat_exp", 2000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 10);
        set_skill("force", 10);
        set_skill("sword", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);

        set("neili", 200); 
        set("max_neili", 200);
        set("jiali", 1);

        set("shen_type",1);set("score",200);setup();
       	carry_object("/clone/armor/cloth")->wear();
}

void destroy(object ob)
{
        if(ob) destruct(ob);
        return;
}


int accept_object(object me, object obj)
{            
        int i;
        
        if (!obj->query("money_id"))
                return 0;
                
        if(i = obj->value() >= 100 )
        {
                command("nod " + me->query("id"));
                command("say 大爷，你老快请上船。\n");
                me->set_temp("cjallowed", "2b");
                i=obj->value();
//                change(i,me);
                call_out("destroy", 1, obj);
                return 1;
        }
        else {
                command("say 这点？可不够哦。");
                return 0;
        }
        
}

void kill_ob(object ob)
{
      ob->remove_killer(this_object());
      remove_killer(ob);
}

#include "die.h"