// protect.c
// by yuer
#include <ansi.h>
inherit F_CLEAN_UP;

//mapping guarding;

int main(object me, string arg)
{

	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;
	object *enemy,ob,ob1,ob2,weapon;
	string *killer,skill_type;

	seteuid( geteuid(me) );


    if( (int)me->query_condition("protected") > 450) return notify_fail("你现在不能这么做!\n");
  if (!me->is_fighting()) return notify_fail("你没有打架,叫什么叫?\n");
	if(weapon = me->query_temp("weapon"))
	skill_type = weapon->query("skill_type");
	

//check for mengzhu
	ob1 = load_object("/clone/npc/meng-zhu");
	if ( ob1->query("winner") != me->query("id") ) 	
		{
		destruct(ob1);
		}
	else
		{
		
		ob = new("/u/yuer/npc/weishi1");
		ob->move(environment(me));
		ob->set_temp("owner",me);
		ob->set_leader(me);




	if( skill_type == "sword") ob->sword_wield();

	if( skill_type == "blade") ob->blade_wield();

	ob->data_setting(ob, me);
//		guarding["living"]=me->query("id");
 //               ob->set_temp("guarding",guarding);




		message_vision(HIB "\n$N大吼一声,卫士何在！\n" NOR, me);	
		killer = me->query_killer();
		enemy = me->query_enemy();
		for(i=0;i<sizeof(enemy);i++)	
		{
		if( present(enemy[i]->query("id"),environment(me)))
			{
				if(enemy[i]->query_temp("owner") != me){
				ob->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(ob);
				else enemy[i]->kill_ob(ob);
				message_vision(HIY "盟主卫士向$N大喝一声:你胆敢伤害盟主,是不是活的不耐烦了！\n" NOR, enemy[i]);
				}

			}
		}
		
	
		me->apply_condition("protected",100+(int)me->query_condition("protected"));
		destruct(ob1);
		return 1;
		} 
//check for shizhe

	ob1 = load_object("/clone/npc/fa-e");
	ob2 = load_object("/clone/npc/shang-shan");
	if ( ob1->query("winner") != me->query("id") && ob2->query("winner") != me->query("id")) 
		{
		destruct(ob1);
		destruct(ob2);
		
		}
	else
		{
		
		ob = new("/u/yuer/npc/weishi2");
		ob->move(environment(me));
		ob->set_temp("owner",me);
		ob->set_leader(me);
//		guarding["living"]=me->query("id");
  //              ob->set_temp("guarding",guarding);

	if( skill_type == "sword") ob->sword_wield();

	if( skill_type == "blade") ob->blade_wield();
	ob->data_setting(ob, me);


		message_vision(HIB "\n$N大吼一声,卫士何在！\n" NOR, me);	
		killer = me->query_killer();
		enemy = me->query_enemy();
		for(i=0;i<sizeof(enemy);i++)	
		{
		if( present(enemy[i]->query("id"),environment(me)))
			{
				if(enemy[i]->query_temp("owner") != me){
				ob->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(ob);
				else enemy[i]->kill_ob(ob);
				message_vision(HIY "使者卫士向$N大喝一声:你胆敢伤害使者,是不是活的不耐烦了！\n" NOR, enemy[i]);
				}

			}
		}
	
		me->apply_condition("protected",100+(int)me->query_condition("protected"));
		destruct(ob1);
		destruct(ob2);
		return 1;
		} 
//check for bangzhu

	ob1 = load_object("/clone/npc/feilong");
	ob2 = load_object("/clone/npc/jujing");
	if ( ob1->query("winner") != me->query("id") && ob2->query("winner") != me->query("id") ) 
		{
		destruct(ob1);
		destruct(ob2);

		}
	else
		{
		
		ob = new("/u/yuer/npc/weishi3");
		ob->move(environment(me));
		ob->set_temp("owner",me);
		ob->set_leader(me);
	//	guarding["living"]=me->query("id");
          //      ob->set_temp("guarding",guarding);


	if( skill_type == "sword") ob->sword_wield();

	if( skill_type == "blade") ob->blade_wield();
	ob->data_setting(ob, me);



		message_vision(HIB "\n$N大吼一声,卫士何在！\n" NOR, me);	
		killer = me->query_killer();
		enemy = me->query_enemy();
		for(i=0;i<sizeof(enemy);i++)	
		{
		if( present(enemy[i]->query("id"),environment(me)))
			{
				if(enemy[i]->query_temp("owner") != me){
				ob->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(ob);
				else enemy[i]->kill_ob(ob);
				message_vision(HIY "帮主卫士向$N大喝一声:你胆敢伤害帮主,是不是活的不耐烦了！\n" NOR, enemy[i]);
				}

			}
		}
		me->apply_condition("protected",100+(int)me->query_condition("protected"));
		destruct(ob1);
		destruct(ob2);
		return 1;
		} 
	
	return 1;

}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令让你(你)呼叫帮助.

HELP
    );
    return 1;
}
