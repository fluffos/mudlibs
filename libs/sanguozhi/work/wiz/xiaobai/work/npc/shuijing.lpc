// written by yuner and fire 
// modified by suicide at Aug 31 2000
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <sanguo.h>
#include <localtime.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
inherit M_GREETER;
private *name_list=({ });

//! 查查今天什么日子，看要不要送礼
int check_date( object who );

//! 国庆节的礼物
void gift_nationalday( object who );

string *query_channel_list() {
    return ({ "plyr_gossip" });
}

void greet(object o)
{
write("\n%^CYAN%^水镜先生笑脸盈盈走过来，和蔼地说道：\n欢迎到舍下做客！如果是第一次来一定要看看新手指南哦(look board)？！\n"+
      "另外有什么事需要我帮助的话尽管问我(ask shuijing about all)。\n");
if (CHAR_D->char_exist(o->query_primary_id())) return;
else 
write("%^CYAN%^看你象初来乍到，我可以送只小狗给你给你引路，想要的话就(ask shuijing about pet)。\n");
    
}



void do_greet(object o) 
{
call_out("greet",1,o);
}


void learn_sj(object who)
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("jbsj",20);
  switch(p_res)
  {
	case TOO_TIRED:
this_object()->targetted_action("$N对$T笑道：“你太累了，休息会儿再来学%^H_GREEN%^水淹之计%^RESET%^吧。”\n",who);
		return;
   	case LESS_LITERATE:
                        this_object()->targetted_action("$N对$T道：你的文学修养不够，有些道理听不明白的。\n",this_body());
			return;
	case TOO_EASY:
this_object()->targetted_action("$N对$T笑道：“老朽正想向你求教%^H_GREEN%^水淹之计%^RESET%^呢。”\n",who);
		return;
	case LESS_EXP:
		this_object()->targetted_action("$N对$T笑到：“经验不够，只怕神仙也教不会你呀。”\n",who);
		return;
	case CAN_LEARN:
        this_object()->targetted_action("$N向$T详解了%^H_GREEN%^水淹之计%^RESET%^的用法。\n",who);
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
    set_in_room_desc("\n%^H_YELLOW%^水镜先生%^RESET%^(shuijing xiansheng)");
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
//        add_question("luoyang","luoyang");
	add_question("newyear","newyear");
	add_question("pet","pet");
	add_question("valentine","valentine");

// edc 
//	add_question("compensation", "compensation");
////

// xiaobai: 送礼物(通用)
	add_question( "gift", "gift" );
//// xiaobai

    add_pattern("%s走了过来。", (: "say " + $1 + "，请进，欢迎到舍下做客！
先读读(read)书简吧？" :) );
    add_pattern("%s进入LIMA。", (: "say " + $1 + "，请进，欢迎到舍下做客！
先读读(read)书简吧？" :) ); 
        init_greet();
}

// 查查今天什么日子，看要不要送礼
int check_date( object who )
{
    string p_id;
	mixed *local;
	int nRet = 0;

    // 检查是否定居角色，只有定居角色才有礼物
    p_id=who->query_primary_id();
    if(!CHAR_D->char_exist(p_id))
    {
   		this_object()->targetted_action("$N对$T笑到："+
            "是定居了的角色呀，好，好。。。\n",who);
        
    }
    else
    {
		this_object()->targetted_action("$N对$T笑到："+
            "只有定居的玩家才有新年红包，$R还没有定居，快先去定居吧。\n",who);
        return 0;
    }

    local = localtime( time() );    
    // 国庆节
    if ( local[LT_MON]==0 && ( local[LT_DAY] > 0 || local[LT_DAY] < 8 ) )
    {
        if( CHAR_D->get_char( p_id, "nationalday_year" ) < local[LT_YEAR] )
        {
            nRet = 1;
            
            // 记录领国庆礼物的年份
            CHAR_D->set_char( p_id, "nationalday_year", local[LT_YEAR] );
            
            // 给礼物
            gift_nationalday( who );
        }
        else
        {
             this_object()->targetted_action("$N对$T笑到："+
                 "$R的国庆加中秋节礼物已经领过了，千万不要太贪心阿。\n",who);
        }
               
    }

    return nRet;

}  // end check_date

//! 国庆节的礼物
void gift_nationalday( object who )
{
    string p_id;
    int num,offset;
    object ob;
    
    p_id=who->query_primary_id();
                
    this_object()->targetted_action("$N对$T笑到："+
        "国庆节加中秋，大家都该高高兴兴，定居了的玩家都有礼物，当然有$R一份。\n",who);
  	num =  2000 + random( 3000 );
    CHAR_D->add_honor_point( p_id, num );
    
    who->simple_action("$N得到了"+chinese_number(num)+
    	"点三国奖点。\n");
    num=10;
    MONEY_D->add_poket_money( who, num*10000 );
    who->simple_action("$N得到了"+chinese_number(num)+
    	"两黄金。\n");
    ob=new("/sgdomain/obj/other/shoyu");
    ob->move(who);
    who->simple_action("$N得到了汉帝亲笔手喻。\n");
    who->responda("jump shuijing");
	ob=new( "/sgdomain/object/other/firework" );
	ob->move( who );
	who->simple_action("$N得到了一枚烟花。\n");
    this_object()->targetted_action("$N对$T笑到："+
        "中秋佳节，人月两圆。\n",who);
    ob = OBJ_D->clone_obj( "mooncake" );
	ob->move( who );
	who->simple_action("$N得到了一个又大又圆的月饼。\n");
    who->responda("mobai shuijing");

}  // end gift_nationalday

void newyear_gift(object who) {
	string p_id;
	int num,offset;
	object ob;
	mixed *local;
// this_object()->targetted_action("$N对$T笑到："+
//"新年早过了，红包都发完了。\n",who);
//return;
	p_id=who->query_primary_id();
	if(!CHAR_D->char_exist(p_id)) {
			this_object()->targetted_action("$N对$T笑到："+
"只有定居的玩家才有新年红包，$R还没有定居，快先去定居吧。\n",who);
 			return;
	}
/*	if(CHAR_D->get_char(p_id,"hon")>=50) {
			this_object()->targetted_action("$N对$T笑到："+
"$R的新年红包已经领过了。\n",who);
 			return;
	}
*/
        local = localtime(time());
        
        if (local[LT_MON]!=0)
        {
         this_object()->targetted_action("$N对$T笑到："+
         "$R来晚一步，新年已经过了，还是等来年吧。\n",who);
         return;
        }
        if(CHAR_D->get_char(p_id,"new_year")>=local[LT_YEAR])
        {
         this_object()->targetted_action("$N对$T笑到："+
         "$R的新年红包已经领过了，千万不要太贪心阿。\n",who);
         return;
        }
        
        
	this_object()->targetted_action("$N对$T笑到："+
        "新年到了，汉帝说了，定居了的玩家都有红包，当然有$R一份。\n",who);
        
       	num=2688;
	CHAR_D->add_honor_point(p_id,num);
	who->simple_action("$N得到了"+chinese_number(num)+
		"点三国奖点。\n");
	num=50;
	MONEY_D->add_poket_money(who,num*10000);
	who->simple_action("$N得到了"+chinese_number(num)+
		"两黄金。\n");
	ob=new("/sgdomain/obj/other/shoyu");
	ob->move(who);
	who->simple_action("$N得到了汉帝亲笔手喻。\n");
	CHAR_D->set_char(p_id,"new_year",local[LT_YEAR]);
	who->responda("jump shuijing");
	
}

void valentine_gift(object who)
{
	string p_id;
	int num,offset;
	object ob;
	mixed *local;
// this_object()->targetted_action("$N对$T笑到："+
//"新年早过了，红包都发完了。\n",who);
//return;
	p_id=who->query_primary_id();
	if(!CHAR_D->char_exist(p_id)) {
			this_object()->targetted_action("$N对$T笑到："+
"只有定居的玩家才有情人节礼物，$R还没有定居，快先去定居吧。\n",who);
 			return;
	}
/*	if(CHAR_D->get_char(p_id,"hon")>=50) {
			this_object()->targetted_action("$N对$T笑到："+
"$R的新年红包已经领过了。\n",who);
 			return;
	}
*/
        local = localtime(time());
        
        if ((local[LT_MON]!=1) || (local[LT_MDAY]!=14))
        {
         this_object()->targetted_action("$N对$T笑到："+
         "$R来晚一步，情人节已经过了，还是等来年吧。\n",who);
         return;
        }
        if(CHAR_D->get_char(p_id,"love_year")>=local[LT_YEAR])
        {
         this_object()->targetted_action("$N对$T笑到："+
         "$R的情人节礼物已经领过了，千万不要太贪心阿。\n",who);
         return;
        }
        
        
	this_object()->targetted_action("$N对$T笑到："+
        "新年到了，汉帝说了，定居了的玩家都有情人节礼物，当然有$R一份。\n",who);
        CHAR_D->set_char(p_id,"love_year",local[LT_YEAR]);
       	num=2688;
	CHAR_D->add_honor_point(p_id,num);
	who->simple_action("$N得到了"+chinese_number(num)+
		"点三国奖点。\n");
	num=50;
	MONEY_D->add_poket_money(who,num*10000);
	who->simple_action("$N得到了"+chinese_number(num)+
		"两黄金。\n");
	ob=new("/sgdomain/obj/other/shoyu");
	ob->move(who);
	who->simple_action("$N得到了汉帝亲笔手喻。\n");
	CHAR_D->set_char(p_id,"new_year",local[LT_YEAR]);
	who->responda("jump shuijing");
	ob=new("/wiz/chun/rose");
	ob->move(who);
	who->simple_action("$N得到了一枝鲜艳火红的玫瑰，赶快去送给你心爱的人吧。\n");
	who->responda("jump shuijing");
	who->set_gini("lin");
	who->simple_action("$N看你今天这么寂寞，送你一个丫鬟吧，至于怎么召唤她，你自己摸索吧。\n");
	who->responda("mobai shuijing");

}

// 一切从简, copy/paste from valentine_gift(), deadline: 09/2001
// edc
void compensation_honour(object who) {
	string p_id;
	int num,offset;
	object ob;
	mixed *local;
	int old_hon, age;

	p_id=who->query_primary_id();
	if(!CHAR_D->char_exist(p_id)) {
		this_object()->targetted_action("$N对$T笑到："+
		"只有定居的玩家才有补偿，$R还没有定居，快先去定居吧。\n",who);
 			return;
	}

        local = localtime(time());
        
        if ( (local[LT_MON]>8) ||
        	( ( local[LT_MON] == 8 ) && ( local[LT_MDAY] >= 10) )
        	|| (local[LT_YEAR]>2001) )
        {
         this_object()->targetted_action("$N眼圈红红地对$T说到："+
         	"$R来晚一步，补偿奖点已经发放完毕，好可怜哦~\n",who);
         return;
        }
        
        // isComensate: 1   补偿 07/2001 restart 的损失 10K honour
        // 以后如果有类试问题, 可以把这个值置成其它数字
        if(CHAR_D->get_char(p_id,"isCompensate") == 1)
        {
         this_object()->targetted_action("$N对$T笑到："+
         	"$R的补偿奖点已经领过了，千万不要太贪心阿。\n",who);
         return;
        }
        
        
	this_object()->targetted_action("$N对$T点了点头道："+
        	"发补偿奖点，当然有$R一份。\n",who);
        CHAR_D->set_char(p_id,"isCompensate",1);
       	
        old_hon=CHAR_D->get_char(p_id,"hon");
	age = CHAR_D->get_char(p_id, "age"); // different age, different honour back
	if (( age > 14) && (age < 16))
		num = 5000;
	else if ( age <= 14 )
		num = 1000;
	else
		num = 10000;
        CHAR_D->set_char(p_id,"hon",old_hon+num);

	who->simple_action("$N得到了"+chinese_number(num)+
		"点三国奖点。\n");
	who->responda("great shuijing");

}
////

void special_answer(object who, string matt)
{
	int p_money;
	string p_id;
	object ob;
	string s_tmp;
	switch(matt)
	{
// edc
		case "compensation" :
			compensation_honour(who);
			return;
////
		case "newyear" :
			newyear_gift(who);
 			return;
                case "valentine" :
			valentine_gift(who);
 			return;
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
		case "gift" : // xiaobai: 礼物
			check_date(who);  // 查一下今天什么日子，送合适的礼物
			return ;
		case "pet" :
		        who->set_gini("dog");
		        if (present("gini lamp",who)) 
		        {
		        this_object()->other_action("$N对你说道：我送给你的小狗是不是不见啦，不要急，你一吹你身上的哨子(gini)它就会回到你身边的。\n",who);
                        return;
                        }
		           	
		        GINI_D->gini_birth(who);
			this_object()->other_action("$N对你说道：这只老夫心爱的小狗就送给你了，要是不懂怎么和它交流可以用(gini help)察看。\n",who);
			return;
//                case "luoyang" :
//                        this_object()->simple_action("$N笑到：“我做了个梦：梦中仙人曰：\n
//        先购火把，厨房点燃，找到石磨，用力推之，
//        下到密洞，得到天书，习得奇术，需要十级，
//        遁甲密法，天地精华，此去洛阳，无翅可飞也。”\n");
//                        return;
	}
}
