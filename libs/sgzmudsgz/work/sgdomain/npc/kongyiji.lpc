// by fire on Dec 29 1997
// kongyiji.c  孔一己
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit CHINESE_DA;
private *name_list=({ });
int learn_zgxy(object who)  //治国修养
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("sk_meili",30);
  switch(p_res)
  {
	case TOO_TIRED:
		this_object()->targetted_action("$N对$T笑到：“你太累了，休息会儿再来学吧。”\n",who);
		return 0;
	case TOO_EASY:
		this_object()->targetted_action("$N对$T笑到：“你该找个更高明的老师了。”\n",who);
		return 0;
		case LESS_LITERATE:
 this_object()->targetted_action("$N对$T道：你的文学太差，听不懂这些。\n",this_body());
			return 0;
	case CAN_LEARN:
  		this_object()->targetted_action("$N向$T详解了治国之道。\n",who);
  		p_st=SG_SKILL_D->query_get("sk_meili");
  		who->simple_action(p_st);
  		return 1;
	default :
		write("你经验不够。\n");
//            write("返回数是"+p_res);
  }
  return 0;
}
int learn_bfxy(object who)  //兵法修养
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("sk_zhimou",30);
  switch(p_res)
  {
	case TOO_TIRED:
		this_object()->targetted_action("$N对$T笑到：“你太累了，休息会儿再来学吧。”\n",who);
		return 0;
                case LESS_LITERATE:
 this_object()->targetted_action("$N对$T道：你的文学太差，听不懂这些。\n",this_body());
                        return 0;
	case TOO_EASY:
		this_object()->targetted_action("$N对$T笑到：“你该找个更高明的老师了。”\n",who);
		return 0;
	case CAN_LEARN:
  		this_object()->targetted_action("$N向$T详解了用兵之道。\n",who);
  		p_st=SG_SKILL_D->query_get("sk_zhimou");
  		who->simple_action(p_st);
  		return 1;
	default :
		write("你经验不够。\n");
//		write("不知为什么他不教你，问问巫师吧。\n");
  }
  return 0;
}
void setup()
{
    set_name("kong yiji", "孔一己");
    set_proper_name("孔一己");
    set_in_room_desc("孔一己(kong yiji)");
    set_gender(1);
    set_age(40);
    add_id("kong");
    
	add_question("name","name" );
	add_question("bfxy","bfxy");
	add_question("rumors","rumors");
	add_question("zgxy","zgxy");
	add_question("money","money");
    set_sg_rongmao(-1);
   set_accept_money(1);
}
string long() {
	return "孔一己看上去蔫蔫的，似乎没太睡醒。\n";
}
void special_answer(object who, string matt)
{
	int p_money;
	string p_id;
	object ob;
	string s_tmp;
	switch(matt)
	{
		case "name" :
			this_object()->targetted_action("$N对$T一本正经地说到："+
"“吾乃孔子三十八代长孙，秀才孔一己也。”\n",who);
 			return;
		case "rumors" :
			this_object()->targetted_action("$N对$T说到："+
"兵荒马乱，祸国殃民，汝不学点本事，何以为生呀。\n",who);
			return;
			
		case "money" :
			this_object()->targetted_action(
"$N对$t说到：“学者不图钱财，但也得糊口呀，学费五两纹银。”\n",who);
			return;
		case "bfxy" :
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				if(learn_bfxy(this_body()))
					name_list-=({ p_id });
			}
			else
			{
				
				this_object()->targetted_action(
"$N对$t说到：“你想学呀，有孔方兄的介绍信吗？\n",who);
			}
			return;
		case "zgxy" :
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				if(learn_zgxy(this_body()))
					name_list-=({ p_id });
			}
			else
			{
				
				this_object()->targetted_action(
"$N对$t说到：“你想学呀，有孔方兄的介绍信吗？\n",who);
			}
			return;
	}
}
void receive_money(object who, int number,string str)
{
	string p_id;
	int p_val;
	p_val=NORMAL_D->query_money_value(number,str);
	if (p_val>=500)
	{
		p_id=this_body()->query_userid();
		name_list+=({ p_id });
		this_object()->targetted_action("$N对$t笑到：“终于还有好读书之人。”\n",who);
	}
	else 
		this_object()->targetted_action("$N对$t嘲笑到：这点钱，够干什么？\n",who);
	return;
}
