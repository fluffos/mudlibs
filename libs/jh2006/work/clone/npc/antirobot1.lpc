//  antirobot1.c
//  By snowman@SJ 12/06/2000

#include <ansi.h>

inherit NPC;
string ans=" ";
string str = "请用 answer 回答，您身上的物品“";
string *numbers = ({
({ "①","②","③","④","⑤","⑥","⑦","⑧","⑨" }),
({ "㈠","㈡","㈢","㈣","㈤","㈥","㈦","㈧","㈨" }),
({ "１","２","３","４","５","６","７","８","９" }),
({ "⑴","⑵","⑶","⑷","⑸","⑹","⑺","⑻","⑼" }),
({ "⒈","⒉","⒊","⒋","⒌","⒍","⒎","⒏","⒐" }),
({ "一","二","三","四","五","六","七","八","九" }),
({ "1.","2.","3.","4.","5.","6.","7.","8.","9." }),
({ "(1)","(2)","(3)","(4)","(5)","(6)","(7)","(8)","(9)" }),
({ "壹","贰","叁","肆","伍","陆","柒","捌","玖" }),
});

#include "antirobot.h";
void question()
{
    	if (!ob) return;
    	message("channel", HIW+str+NOR, ob);
}

int do_answer(string arg)
{
    	object me = this_object();
    	object obj = this_player();

    	if (obj != ob) return 0;
    	if ( !arg ) return notify_fail("格式 answer <ID> \n");
    	if ( arg == ans ) {
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
    	int len;
    	object *inv, test_ob, me = this_object();
	string id;
	mixed list;
	
    	ob = obj;
    	if (environment(ob)) {
    		inv = all_inventory(ob);
    		if( !sizeof(inv) ) {
    			destruct(me);
    			return;
    		}
    		inv = filter_array(inv, (:  !$1->is_character() :));
    		if( !sizeof(inv) ) {
    			destruct(me);
    			return;
    		}
    		test_ob = inv[random(sizeof(inv))];
    		list = test_ob->parse_command_id_list();
    		len = random(sizeof(list));
    		if( len > 8 ) len = random(8);
    		id = list[len];
		me->move(environment(ob), 1);
		message_vision("$N忽然出现在$n面前！\n", me, ob);
		set_leader(ob);
		list = numbers[random(sizeof(numbers))];
		tell_object(ob, "银翼杀手略带歉意地说：“机器人稽查，例行公事，请接受一个小测试。”\n");
		str += test_ob->name(1)+HIW"”的第 "+list[len]+" 个 id 是什么？(以 "+id[0..0]+" 开头，可用 id 命令查看)\n";
		ans = id;
		timer = 180;
		call_out("test1", 60);
    	} 
    	else destruct(me);
}
