
#include <ansi.h>
inherit F_CLEAN_UP;
#define DEATH_PERIOD 1200
int main(object me, string arg)
{
	object pet;
	object *ob_list;
	int i;
	string id,name;
	string file;
	if(me->query("jing")<50) return notify_fail("你精气不够。\n");
	if(me->is_busy()) return notify_fail("你现在不可以吹口哨。\n");
	if(me->is_ghost()) return notify_fail("鬼魂不可以吹口哨。\n");
	if(!me->query("marks/pet")) return notify_fail("你没有自己的宠物。\n");
        write("你轻轻地吹了声口哨．．．\n");
//	if(environment(me)->query("NONPC")) return 1;
	file = me->query_save_file();
	file += ".pet.o";
	ob_list = children("/clone/npc/pet");
	for(i=0; i<sizeof(ob_list); i++) 
		if(ob_list[i]->query("possessed") == me)
			pet = ob_list[i];
	if(!pet && file_size(file) > 0 )
	{
		seteuid(getuid());
		pet = new("/clone/npc/pet");
		pet->set("owner",me->query("id"));
		pet->restore();
		id = pet->query("id");
		name = pet->query("name");
		pet->set("id",id);
		pet->set_name(name,({id}));
		pet->set("possessed",me);
		pet->setup();

	}
	me->add("jing",-50);
        if (present(pet, me))
        return notify_fail("你不是正骑着吗?\n");
	if(pet && environment(pet) != environment(me) 
	&& time() - (int)pet->query("deathstamp") > 1200
	&& !pet->is_fighting())
	{
	pet->move(environment(me));
	pet->reset_action();
	pet->set_temp("owner",me);
        pet->set("ownmake",1);
        pet->set("no_drop",1);
	pet->set_temp("ownername",me->query("name"));
	pet->set("double_attack", me->query("double_attack"));
	pet->set("szj", me->query("szj"));

	pet->set("str", (me->query("str") > 60 ? 60 : me->query("str")));
	pet->set("int", (me->query("int") > 60 ? 60 : me->query("int")));
	pet->set("con", (me->query("con") > 60 ? 60 : me->query("con")));
	pet->set("dex", (me->query("dex") > 60 ? 60 : me->query("dex")));
	pet->set("kar", (me->query("kar") > 60 ? 60 : me->query("kar")));
	pet->set("combat_exp", (int)me->query("combat_exp") * 1 / 4);
	pet->set("max_neili", (int)me->query_skill("force") * 15);
	pet->set("neili", pet->query("max_neili"));
	pet->set("max_qi", (int)me->query_skill("force") * 20);
	pet->set("eff_qi", pet->query("max_qi"));
	pet->set("qi", pet->query("max_qi"));
	pet->set("max_jing", (int)me->query_skill("force") * 5);
	pet->set("eff_jing", pet->query("max_jing"));
	pet->set("jing", pet->query("max_jing"));
	pet->set("food", (pet->query("str") + 10) * 10);
	pet->set("water", (pet->query("str") + 10) * 10);
if ((int)pet->query_skill("puyaogedou") < 200)
{
pet->set_skill("puyaogedou", (int)me->query_skill("force")*2/3);
}
	pet->delele("is_rided_by");
	message_vision("$N不知从哪里窜到$n面前．\n",pet,me);	
// let pet be our protector
	if(me->is_fighting())
	{
	object *enemy;
	enemy = me->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        pet->kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(pet);
                        else enemy[i]->kill_ob(pet);
						    }
		    }
//        me->remove_all_killer();
	}
	
	pet->set_leader(me);
	}
	else
		if (pet) 
	{pet->save();
        message_vision("$N一闪就不见了。\n",pet);
	pet->delele("is_rided_by");
	destruct(pet);
	}
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : whistle

详解请看帮助文件中的《宠物篇》
HELP
        );
        return 1;
}
