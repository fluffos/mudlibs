// zayilama.c 杂役喇嘛
// by iceland

#include <ansi.h>
inherit NPC;
#include "name.h";

void create()
{
    string name,m1,m2,m3,m4;
    int i;
    i=random(4);
m1=names[i][random(sizeof(names[i]))];	
m2=names[0][random(sizeof(names[0]))];
m3=names[1][random(sizeof(names[1]))];
m4=names[2][random(sizeof(names[2]))];

switch (random(3)){
	case 0:  
        name = m1+m2; 
 	break;
	case 1: 
        name = m1+m2+m3; 
	break;
	case 2:
        name = m1+m2+m3+m4 ;  
	break;
	} 

      set_name(name, ({"zayi lama","lama","zayi"}));
	set("long",@LONG
他是大轮寺的杂役喇嘛，只会些粗浅功夫，在寺里身份最低，日常干些粗活重活。
LONG
	);

	set("gender", "男性");
	set("attitude", "heroism");
	set("title" , HIW"大轮寺杂役喇嘛"NOR);
	set("age", random(20)+20);
	set("shen_type", 0);
	set("str", random(10)+10);
	set("int", 20);
	set("con", random(10)+10);
	set("dex", random(10)+10);
	set("max_qi", 200);
	set("eff_jing", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", random(10000)+1000);
	set("unique", 15);

	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	setup();
        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();
}
