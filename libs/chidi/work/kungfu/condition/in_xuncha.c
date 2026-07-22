// in_xuncha.c
// by QingP

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

void get_exp(object);
void get_money(object);
void clear_cancl(object);

int update_condition(object me, int duration)
{
	mapping myfam = (mapping)me->query("family");

	if ( duration < 1 ){
		if ( me->query("in_xuncha") && myfam["family_name"] == "星宿派" )
	        	call_out("get_exp", 0, me);
	        else call_out("get_money", 0, me);
	        return 0;
	}
        
        me->apply_condition("in_xuncha", duration - 1);

	return 1;
}

void get_exp(object ob)
{
        int pot, exp;

	exp = random(20) + 1;
        pot = 10 + random(ob->query_str()) / 2;

        if ( !(ob->query_temp("in_cancl")) && ob->query("in_xuncha") ) {
                if (ob->query("do_xuncha")<11) {
                        ob->add("combat_exp",exp);
                        ob->set("do_xuncha",ob->query("do_xuncha") + 1);
		}
		else {
                        ob->set("combat_exp",ob->query("combat_exp") + 30 + random(10));
                        if(((int)ob->query("learned_points") + 120) > (int)ob->query("potential")
                        && ((int)ob->query("potential") - (int)ob->query("learned_points")) < (120 - pot)){
                                ob->add("potential",pot);
                        }
                        else{
                        	pot = ob->query("learned_points") + 120 - ob->query("potential");
                        	ob->add("potential",pot);
                        }
                }

                ob->delete("in_xuncha");   
                ob->set("title",ob->query("oldtitle"));
                ob->delete("oldtitle");
               	ob->apply_condition("after_xuncha", 7);

                ob->set_temp("in_cancl",1);
                call_out("clear_cancl",199,ob);
                tell_object(ob, sprintf("你得到了%s点潜能，%s点经验。\n",chinese_number(pot),chinese_number(exp)));
                tell_object(ob, NOR"你巡查星宿海的时间到了，可以离开了。\n"NOR);
                return;
                }
        return;
}

void get_money(object ob)
{
        object mo;
        int amount;

 	if (!(ob->query_temp("in_cancl")) && ob->query("work_xuncha") ) {
                ob->delete("work_xuncha");
                ob->set("title",ob->query("oldtitle"));
                ob->delete("oldtitle");
               	ob->apply_condition("after_xuncha", 7);
                mo=new("/clone/money/silver");
                amount=random(70)+1;
                mo->set_amount(amount);
                mo->move(ob);

                ob->set_temp("in_cancl",1);
                call_out("clear_cancl",199,ob);

                tell_object(ob, sprintf("你得到了%s两银子作为酬劳。\n",chinese_number(amount)));
                tell_object(ob, NOR"你巡查星宿海的时间到了，可以离开了。\n"NOR);
                return;
        }
        return;
}

void clear_cancl(object ob)
{
  ob->delete_temp("in_cancl");
}