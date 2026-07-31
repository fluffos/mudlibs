// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

//可爆出物品列表
string *random_ob = ({
    "/clone/vip/putao",
    "/clone/money/gold",
});

void create()
{
	set_name(HIY"万剑氏"NOR, ({ "li jiaotou", }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set_basic();
	setup();

	add_money("gold", 1+random(3));
}
void init(object me)
{
	object ob;
	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)) {
		command("say 小子，有点本事啊，我来会会你！！\n");
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 60);
		if (!random(3))
			ob->do_clone(me, 60);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}
void die()
{
        object nvh;
         object ob =  this_object()->query_last_damage_from();
            object *players;
         int w,x,i;
        ob->start_busy(1); 
        if (sizeof(ob->query_team()) > 1)
        {
        players = ob->query_team();
         x = 4000+random(2390);
        }
        else
        {   
         x = 4000+random(2390);
         }
         w = sizeof(players);
       for(i = 0; i<sizeof(players); i++)
         {
		 if(players[i]->query("wmszcs")<1){
       tell_object(players[i],HIR"由于你今天副本次数达到上限，你没有获得任何奖励\n"NOR); 
		 }else{
         players[i]->add("potential",x*2);
        players[i]->add("combat_exp", x/10);
        players[i]->add("experience", x/6);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了万剑氏，你赢得了"+x/10+"修为,"+x*2+"潜能，"+x/6+"实战体会.\n"NOR); 
       }
	   }
           ::die(); 
}