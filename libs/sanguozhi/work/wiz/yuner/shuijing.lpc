// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
private *name_list=({ });
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void learn_sj(object who)
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("jbsj",30);
  switch(p_res)
  {
	case TOO_TIRED:
		this_object()->targetted_action("$N对$T笑到：“你太累了，休息会儿再来学基本水计吧。”\n",who);
		return;
	case TOO_EASY:
		this_object()->targetted_action("$N对$T笑到：“老朽正想向你求教基本水计呢。”\n",who);
		return;
	case LESS_EXP:
		this_object()->targetted_action("$N对$T笑到：“经验不够，只怕神仙也教不会你呀。”\n",who);
		return;
	case CAN_LEARN:
  		this_object()->targetted_action("$N向$T详解了基本水计之法。\n",who);
  		p_st=SG_SKILL_D->query_get("jbsj");
  		who->simple_action(p_st);
  		return;
	default :
		write("不知为什么他不教你，问问巫师吧。\n");
  }
  return;
}
void setup()
{
    set_name("shuijing xiansheng", "水镜先生");
    set_gender(1);
    set_proper_name("水镜先生");
    set_in_room_desc("水镜先生(shuijing xiansheng)");
    add_id("shuijing");
    add_id("sx");
    add_id("xiansheng");
    set_age(70);
    set_long("     
      一个五十开外的老者，仙风道骨，
精神烁烁， 两眼充满了智慧的光芒。
要是有什么不懂的，可以试着问问他。 ");
	add_question("name","name" );
	add_question("here","here");
	add_question("news","news");
	add_question("rumors","rumors");
	add_question("help","help");
	add_question("money","money");
	add_question("shouming","shouming");
	add_question("jbsj","jbsj");
	add_question("luoyang","luoyang");
    add_pattern("%s走了过来。", (: "say " + $1 + "，请进，欢迎到舍下做客！
先读读(read)书简吧？" :) );
    add_pattern("%s进入LIMA。", (: "say " + $1 + "，请进，欢迎到舍下做客！
先读读(read)书简吧？" :) ); 
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
			this_object()->targetted_action("$N对$T笑到："+
"“不敢当，不敢当，老朽乃一山野村民，哪有什么尊姓大名呀。”\n",who);
 			return;
 		case "here" :
			this_object()->simple_action(
"$N说到“这里是三国时代，不知您想问些什么？(help,money,shouming)");
			return;
		case "help" :
			this_object()->simple_action("$N微微一笑。\n");
			this_object()->simple_action("$N说道：“是新玩家吧，问我可问对了。”\n"+
"要想了解三国世界，得先读读新闻(news)。\n");
			return;
		case "news" :
			this_object()->targetted_action("$N对$T笑到："+
"当今正逢乱世，小兄弟心怀大志，当可成一番霸业。\n",who);
			return;
		case "rumors" :
			this_object()->targetted_action("$N对$T小声说到："+
"听说三国网络游戏创作组正在招收新巫师，有兴趣的话感快去报名吧。\n",who);
			return;
			
		case "money" :
			this_object()->targetted_action(
"$N对$t遗憾地说到：“老朽这点家底已全给分完了，$c要是不弃，可到南面\n"+
"张大户家看看能不能找点差干干，详情请用(help digsoil)查看．\n",who);
                        return;
			p_money=who->query_amt_money("bank");
			p_money=p_money+who->query_all_con_money();
			if (p_money>50000)
			{
				this_object()->targetted_action(
"$N对$t说到：“小兄弟家资颇丰，只怕看不上老朽这点钱吧。”\n",who);
				return;
			}
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				this_object()->targetted_action(
"$N对$t遗憾地说到：“老朽这点家底已全给小兄弟了，唉 . . .”\n",who);
				return;
			}
			name_list+=({ p_id });
			ob=new(M_GOLD);
			ob->set_m_num(3);
			ob->move(who);
			this_object()->targetted_action(
"$N对$t说到：“你我忘年之交，也算有缘，这点薄资望能助小兄弟早成霸业。\n",who);
			this_object()->targetted_action("$N给$t一些黄金\n",who);
			return;
		case "shouming" :
			p_money=who->query_shouming();
			s_tmp=chinese_number(p_money);
			this_object()->simple_action("$N掐指算了算\n");
			this_object()->targetted_action(
"$N对$t小声说到：“$R乃有福之人，当可有寿"+s_tmp+"年。”\n",who);
			return;
		case "jbsj" : // 基本水计
			learn_sj(who);
			return ;
			
		case "luoyang" :
			this_object()->simple_action("$N笑到：“我做了个梦：梦中仙人曰：\n
	先购火把，厨房点燃，找到石磨，用力推之，
	下到密洞，得到天书，习得奇术，需要十级，
	遁甲密法，天地精华，此去洛阳，无翅可飞也。”\n");
			return;
	}
}
