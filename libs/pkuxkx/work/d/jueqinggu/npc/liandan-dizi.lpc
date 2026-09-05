
#include <ansi.h>
inherit NPC;
int ask_quest();
int msg();
void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    int i=random(2);
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"炼丹弟子"+NOR);
	set("shen_type", 1);
	set("str", 30);
	set("gender", i?"男性":"女性");
	set("age", 10+random(20));
	set("combat_exp", 69000);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("force", 200);
    set("eff_qi",1000);
    set("max_qi",1000);
    set("qi",1000);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
    set_temp("apply/damage",  10);
	set("attitude", "friendly");
	set("random_npc",1);
    set("chat_chance", 3);
        set("chat_msg", ({
                (: msg :),   
        }) );
	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();
   

}

int msg()
{   if (random(100)>49)
    {
        message_vision(this_object()->query("name")+"使劲鼓风，生怕炉火熄灭。\n",this_object());
        return 1;
    }
    else
    {
        message_vision(this_object()->query("name")+"观察了一下炉火，放心地打起瞌睡来了。\n",this_object());
        return 1;
    }
}



