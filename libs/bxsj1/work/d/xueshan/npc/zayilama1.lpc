// zayilama1.c 杂役喇嘛
// by iceland

#include <ansi.h>
inherit NPC;
#include "name.h";

int give_food();

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
        set("tea_count", 40);
        set("inquiry", ([ 
	       "食物" : (: give_food :),
       ]) );

	setup();
        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int give_food()
{
       object food, me, ob;

       me = this_object();
       ob = this_player();

       if ( objectp(present("suyou cha", (ob))))  { 
	  command("say 你身上不是还有么？先吃完了再向我要吧。”");
          return 1;  } 

        if (query("tea_count") < 1)  { 
	  command("say 今天碰到个大肚汉，把食物都吃光了，厨房正在加紧做，请稍等一会。”");
          return 1;  } 

       food = new(FOOD_D("youcha"));
       food->move(ob);

       message_vision("$N交给$n一碗酥油茶。\n", me, ob);
// 98         add("tea_count", -1);
       return 1;
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return; 
        command("say "+ RANK_D->query_respect(ob) + "是不是饿了？如果饿了可以向我要食物(ask lama about 食物)。\n");
 }
