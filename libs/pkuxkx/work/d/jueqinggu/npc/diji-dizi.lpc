
#include <ansi.h>
inherit NPC;
int ask_quest();
int msg();
void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"杂役弟子"+NOR);
	set("shen_type", 1);
    set("扫地",1);
	set("str", 30);
	set("gender", "男性");
	set("age", 46);
	set("combat_exp", 53000);
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
    set("chat_chance", 5);
        set("chat_msg", ({
                (: msg :),   
                (: random_move :),
        }) );
	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();
    call_out("dest",900);

}

int msg()
{
    message_vision(this_object()->query("name")+"认真打扫着路面。\n",this_object());
    return 1;
}

int dest()
{
    destruct(this_object());
    return 1;
}

