// fanseng.c 护法喇嘛
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

      set_name(name, ({"hufa lama","lama"}));
	set("long",@LONG
他是大轮寺的护法喇嘛，身材硕壮，神情肃穆，两眼警惕的巡视着四周。
LONG
	);

	set("gender", "男性");
	set("attitude", "heroism");
	set("title" , HIW"大轮寺护法喇嘛"NOR);
	set("age", random(20)+20);
	set("shen_type", -1);
	set("str", random(20)+25);
	set("int", 20);
	set("con", random(20)+20);
	set("dex", random(20)+20);
	set("max_qi", 700);
	set("eff_jing", 300);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", random(40000)+80000);
	set("score", 5000);
	set("unique", 15);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
        set_skill("blade",60);
        set_skill("staff",60);
        set_skill("hammer",60);
	setup();
        set("chat_chance", 1);

        set("chat_msg", ({
		name+"上下打量了你一眼。\n",
                name+"伸了个懒腰，露出肌肉发达的双臂。\n",
        }) );
        switch(random(4)){
              case 0:
              carry_object( BINGQI_D("leaden-falun"))->wield();
              break;
              case 1:
              carry_object( BINGQI_D("jingangzuan"))->wield();
              break; 
              case 2:
              carry_object( BINGQI_D("xinyuedao"))->wield();
              break;
              case 3:
              carry_object( BINGQI_D("iron-falun"))->wield();
              break;

            }
        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();

}
