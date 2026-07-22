// jiangong.c 监工

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
        set_name(name, ({"jian gong", "jiangong" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "他是吐蕃织造作坊的监工，长得白白胖胖，显得一惯养尊处优。\n");
	set("title" , "吐蕃织造作坊监工");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("combat_exp", 10000);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 23);
        set("int", 21);
        set("attitude","heroism");
	set("unique", 1);

        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		name+"眼睛盯着一个女工，不怀好意的冷笑了几声。\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
        add_money("silver", 80);
}
