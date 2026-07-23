// designed by Yu Jue

#include <ansi.h>

inherit NPC;

string key="";
string ans=" ";
string str = "银翼杀手说道：请用 answer 回答，下面这行英文中出现了正好";

#include "antirobot.h";

void question()
{
    	if (!ob) return;
    	tell_object(ob, HIW+HIW+str);
    	tell_object(ob, key+NOR);
}

int do_answer(string arg)
{
    	object me = this_object();
    	object obj = this_player();

    	if (obj != ob) return 0;
    	if (!arg || strlen(arg) > 1) return notify_fail("答案是一个字母，再仔细想想。\n");
    	if (arg==ans) {
        	message_vision("$N点了点头，说道：OK，$n继续忙吧。\n", me, ob);
        	message_vision("$N突然消失不见了。\n", me);
    	} 
    	else {
        	message_vision("$N叹了口气道："+arg+"？"+ans+"才对，这么简单都答不出？去法庭接受聆讯吧！\n", me);
        	move_to_court(ob);
    	}
    	destruct(this_object());
    	return 1;
}


void test_robot(object obj)
{
    	int len, temp, t1, t2, t3;
    	object me = this_object();

    	ob = obj;
    	if (environment(ob) && !ob->is_fighting()) {
        	me->move(environment(ob), 1);
        	message_vision("$N忽然出现在$n面前！\n", me, ob);
        	set_leader(ob);
        	tell_object(ob, "银翼杀手略带歉意地说：“机器人稽查，例行公事，请回答一个小问题。”\n");
        	temp = len = random(5)*2+7;
        	t1 = random(26);
        	while (temp--) {
            		do t2 = random(26); while (t2==t1);
            		key += "a";
            		key[<1] += t2;
        	}
        	t1 += 'a';
        	ans[0] = t1;
        	temp = random(len/2) + len/2 + 1;
        	str += chinese_number(temp)+"次的字母是？\n";
        	while (temp--) {
            		do t3 = random(len); while (key[t3]==t1);
            		key[t3] = t1;
        	}
        	key += "\n";
        	timer = 180;
        	call_out("test1", 60);
    	} 
    	else destruct(me);
}

