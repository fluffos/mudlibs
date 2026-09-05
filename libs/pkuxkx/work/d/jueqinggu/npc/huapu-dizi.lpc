
#include <ansi.h>
inherit NPC;
int ask_quest();

void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"花圃弟子"+NOR);
	set("shen_type", 1);
    set("花圃",1);
	set("str", 30);
	set("gender", "男性");
	set("age", 20+random(10));
	set("combat_exp", 500000);
    set_skill("unarmed", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("force", 200);
    set_temp("apply/attack",  100);
    set_temp("apply/defense", 100);
    set_temp("apply/damage",  100);
	set("random_npc",1);
	set("attitude", "friendly");
/*	set("inquiry", ([
			"离谷" : (: ask_quest :),
            "out" : (: ask_quest :),
            "leave" : (: ask_quest :),
            "离开" : (: ask_quest :),
       	]) );
*/
	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();

}
