// xiangke.c 进香客
// by iceland

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

      set_name(name, ({"jinxiang ke","jinxiangke","ke"}));
	set("long",@LONG
他是一名进香客，满脸虔诚的样子，手中拿了些藏香、蜡烛等物，脖子上还挂着个香袋。
LONG
	);

	set("gender", "男性");
	set("attitude", "heroism");
	set("title" , "进香客");
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
	set("combat_exp", random(1000)+1000);
	set("unique", 15);

	setup();
        carry_object(ARMOR_D("pipao"))->wear();
        carry_object(ARMOR_D("9xie"))->wear();
        carry_object(FOOD_D("suyou"));
}
