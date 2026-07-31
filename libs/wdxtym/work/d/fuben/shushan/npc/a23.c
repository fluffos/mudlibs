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
	set_name(HIR"无氏族"NOR, ({ "wang zongguan", "zongguan"}) );
	set("gender", "男性");
	set("age", 45);
	set("long", "这家伙一副笑眯眯的样子，看上去人畜无害。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set_basic();
	setup();

	add_money("gold", 1);
}
void init(object me)
{
	object ob;
	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)) {
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 130);
		if (!random(3))
			ob->do_clone(me, 130);
		command("say 今天无名山庄比武大会，坏事者死！！\n");
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
          x = 3500+random(1190);  
        }
        else
        {   
         x = 3500+random(1190);
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
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了无氏族，你赢得了"+x/10+"修为,"+x*2+"潜能，"+x/6+"实战体会.\n"NOR); 
       }
	   }
           ::die(); 
}