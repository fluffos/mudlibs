// the body of merchant
inherit PMODULES+"m_charnpc";
private mixed p_custom;
private string p_stage,p_for,p_what,n_id;
private int p_discount,p_count;
private int arg_time;
void trade_process();
void answer_buy(object who);
int my_bargen(int sug);
void my_cancel();
void my_deal();
void award(object o);
void setup()
{
   move_setup();
   add_question("goods","goods");
   add_question("buy","buy");
   add_ask_str("goods","$N对$T一拱手道：请问老板，你这儿还有些什么货色，让$S看看。\n");
   add_ask_str("buy","$N对$T道：把货都先搬出来看看，$S要进批货。\n");
}
string long()
{
   string p_id;
   p_id=COUNTRY_D->get_country(n_id,"name");
   return p_id+"商队，一些商人正在不断地叫买中。\n";
}
string query_title(string p_id,string c_id)
{
   string p_nationname;
   p_nationname=COUNTRY_D->get_country(CHAR_D->get_char(p_id,
	   "my_nation"),"name");
   return p_nationname+"商队("+p_id+")";
}
void answer_good(object who)
{
   string *lis;
   int i;
   string ans;
   lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");
   if(!sizeof(lis))
   {
     this_object()->simple_action(
       "$N不好意思地说到：啊，货全卖完啦。\n");
      return;
   }
   ans="$N答到：本部有以下存货：\n";
   this_object()->simple_action(ans);
ans="货物      价钱              数量     \n"+
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
   for(i=0;i<sizeof(lis);++i)
   {
     ans+=sprintf("%-10s%-16s  %s\n",
       (EV_MERCHANT)->query_m_goods(n_id,lis[i],"name"),
       CHINESE_D->chinese_value(100*
         (EV_MERCHANT)->query_m_goods(n_id,lis[i],"price")),

		 chinese_number((EV_MERCHANT)->query_m_goods(n_id,lis[i],"quantity")));
   }
  write(ans);
}
void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "goods" :
         answer_good(who);
		 return;
	  case "buy":
		 answer_buy(who);
		 return;
  }
}
void answer_buy(object who)
{
   string *lis;
   string p_id;
   p_id=who->query_id()[0];
   if(!COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation")))
   {
		this_object()->targetted_action
			("一$N对$T冷冷地说：我们只和官家做生意。\n",who);
		return;
   }
   if(p_id==p_custom)
   {
		this_object()->targetted_action
			("众$N对$T陪着笑脸道：$m$R怎么胡涂了，我们上笔生意还没谈完那。\n",who);
		return;
   }
   if(stringp(p_custom)&&find_user(p_custom)&&present(p_id,environment(this_object())))
   {
		this_object()->targetted_action
			("一$N对$T连忙陪笑脸道：$m$R请息怒，小可这边买卖一完，马上就是$R的。\n",who);
		return;
   }
   lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");
   if(!sizeof(lis))
   {
     this_object()->simple_action(
       "$N不好意思地说到：啊，货全卖完啦。\n");
      return;
   }
   p_custom=p_id;
   p_stage="begbuy";
   trade_process();
   remove_call_out("trade_over");
   call_out("trade_over",60);
}
void trade_over()
{
	object custom;
	custom=find_body(p_custom);
	if((!objectp(custom))||(environment(this_object())!=environment(custom)))
	{
		p_custom=0; return;
	}
	this_object()->targetted_action(
		"一$N对$T道：看来$R还没决定买什么，等想好再来吧。\n",find_body(p_custom));
	custom=find_user(p_custom);
	if(objectp(custom))
		custom->modal_pop();
	p_custom=0;
	return;
}
string get_action()
{
	switch(p_stage)
	{
	case "begbuy":
		return "$N对$T道：$R是为公干而买还是为自家而买呀。\n";
	case "buywhat":
		return "$N对$T道：$R看看是要买些什么。\n";
	case "howmany":
		return "$N对$T道：$R要进多少货。\n";
	case "bargen":
		return "$N对$T陪笑道：$m$R要不现在就交钱发货。\n";
	default:
		return "$N显然不知道该怎么办。\n";
	}
}
string get_prom()
{
	string *lis;
	int i,s;
	string ret="";
	lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");
	s=sizeof(lis);
	switch(p_stage)
	{
	case "begbuy":
		return "1 为地区买；2  为自己买。\n";
	case "buywhat":
		if(!s) return "BUG ！ BUG ！！！\n";
		for(i=1;i<=s;++i)
			ret+=sprintf("%d  %s；",i,
				(EV_MERCHANT)->query_m_goods(n_id,lis[i-1],"name"));
		return ret;
	case "howmany":
		ret=sprintf("进多少货：[ 1 -- %d ]\n",
			(EV_MERCHANT)->query_m_goods(n_id,p_what,"quantity"));
		return ret;
	case "bargen":
		return "请选择：1 - 9：打折；10：决定；-1：放弃。\n" ;
	default:
		return "看来有BUG了。\n";
	}
}

void trade_input(string str)

{

	string *lis;


	object o;

	int i,s;

	lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");

	s=sizeof(lis);

	switch (p_stage)

	{

	case "begbuy":

		if(str=="2")

		{	this_body()->simple_action("$N道：为自家办点...\n");

			p_for="self";

		}

		else{

			this_body()->targetted_action("$N对$T道：我这可是公干，你给快点。\n",this_object());

			p_for="area";

		}

		p_stage="buywhat";

		break;
	case "buywhat":
		i=to_int(str);
		if((i<1)||(i>s))
		{
			write("买什么？\n");
			return;
		}
		p_what=lis[i-1];
		this_body()->targetted_action("$N对$T道：先进点"+
			(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+"。\n",this_object());
		p_stage="howmany";
		break;
	case "howmany":
		{
			int price,total_price;
			i=to_int(str);
			s=(EV_MERCHANT)->query_m_goods(n_id,p_what,"quantity");
			if((i<1)||(i>s))
			{	write("买多少？\n");
				return;
			}
			this_body()->simple_action(
				"$N道：先进"+chinese_number(i)+"。\n");
			price=(EV_MERCHANT)->query_m_goods(n_id,p_what,"price");
		total_price=price*i;
			if(total_price<1000) // less than 10 gold
			{
				this_object()->simple_action(
					"众$N纷纷道：这也太小气了点吧，我们一次出货，最少要十两金子。\n");
				return;
			}
			p_count=i;
		p_stage="bargen";
			p_discount=0;
			arg_time=0;
		}
		break;
	case "bargen":
		i=to_int(str);
		if(i==-1)
	{	this_body()->simple_action(
				"$N道：算了，我不想买了。\n");
			my_cancel();return;
		}
		if(i==10)
		{	
			this_body()->targetted_action(
			"$N对$T叹道：算了，算了，和你们也不多磨嘴皮，就按这价吧。\n",this_object());
			p_discount=10; 
			o=find_user(p_custom);
			if(objectp(o))
				o->modal_pop();
			my_deal(); return;
	}
		if((i>0)&&(i<10))
		{
			i=my_bargen(i);
			if(i==1) {
				o=find_user(p_custom);
				if(objectp(o))
					o->modal_pop();
				my_deal(); return;
		}
		}
		break;
	default:
	break;
	}
	o=find_user(p_custom);
	if(objectp(o))
		o->modal_pop();
	call_out("trade_process",1);
}
void my_deal()
{
        int p_goldneed,n_bank;
	p_goldneed=
		(EV_MERCHANT)->query_m_goods(n_id,p_what,"price")*p_count*p_discount*10;

	this_object()->targetted_action(
	"$N对$T满脸堆笑道："+chinese_number(p_count)+
		(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+
		"已经准备好了，总值："+
	CHINESE_D->chinese_value(p_goldneed)+
		"就请$m$R结账吧。\n",this_body());
	p_goldneed/=10000;  // now is real use gold
	switch(p_for)
	{
	case "self":
    n_bank=this_body()->query_amt_money("bank");
                if(n_bank < p_goldneed)
		{
			this_body()->targetted_action(
                                "$N一查帐，呀，不好。钱庄里的钱不够。\n"+
                                "$N马上对$T赔笑道：不好意思，我手头有些紧，回头再买吧。\n",this_object());
			call_out("my_cancel",2);
			break;
		}
		this_body()->simple_action(
			"$N道：那好吧，就这么办了。\n");
		this_body()->targetted_action(
			"$N从$T那里买了"+chinese_number(p_count)+
		(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+"。\n",this_object());
		{
			mixed my_army;
			my_army=CHAR_D->get_char(p_custom,"myarmy");
			if(!my_army) my_army=([]);
			if(!my_army[p_what]) my_army[p_what]=0;
			my_army[p_what]+=p_count;
			CHAR_D->set_char(p_custom,"myarmy",my_army);
    n_bank=n_bank-p_goldneed;
    this_body()->set_money("bank", n_bank);
			(EV_MERCHANT)->decrease_count(n_id,p_what,p_count);
		}
		break;
	case "area":
		{
			string p_area;
			p_area=CHAR_D->get_char(p_custom,"area");
			p_goldhave=AREA_D->get_area(p_area,"gold");
			if(p_goldhave < p_goldneed)
			{
				this_body()->targetted_action(
					"$N一查帐，呀，不好。库里钱不够。\n"+
					"$N马上对$T赔笑道：不好意思，本地区钱有些紧，回头再买吧。\n",this_object());
				call_out("my_cancel",2);
				break;
		}
	if((PJOB+"localbuy/localbuy")->get_localbuy(p_custom)!=p_what)
		{
				this_body()->targetted_action(
					"$N一查帐，呀，不好。没拿到采购"+
					(EV_MERCHANT)->query_goods(p_what,"name")+
					"的工作。\n"+"$N马上对$T赔笑道：不好意思，购"+
					(EV_MERCHANT)->query_goods(p_what,"name")+
					"之事不该我管. . . .，回头再谈吧。\n",this_object());
					call_out("my_cancel",2);
					break;
			}
			this_body()->simple_action(
				"$N道：那好吧，就这么办了。\n");
			this_body()->targetted_action(
				"$N从$T那里为地区进了"+chinese_number(p_count)+
			(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+"。\n",this_object());

			this_body()->finish_job("localbuy");
			AREA_D->set_area(p_area,p_what,
				AREA_D->get_area(p_area,p_what)+p_count);
			AREA_D->set_area(p_area,"gold",p_goldhave-p_goldneed);
			(EV_MERCHANT)->decrease_count(n_id,p_what,p_count);
			{
				object o;
				o=find_user(p_custom);
				if(objectp(o))
					ROBOT->robot_test(o,(:award:));
			} 
		}
		break;
	default: 
	}
    {	
		string p_area;
		p_area=AREA_D->check_area
			("area",environment(this_object())->get_area())[0];
		p_goldneed/=5;
		if(p_goldneed)
		{
			AREA_D->set_area(p_area,"gold",
				AREA_D->get_area(p_area,"gold")+p_goldneed);
			COUNTRY_D->set_country(n_id,"gold",
				COUNTRY_D->get_country(n_id,"gold")+p_goldneed);
		}
	}

	remove_call_out("trade_over");
	p_custom=0;
	return;
}
void award(object o)
{
    int isrobot;
	string p_id;
	o=o->query_body();
	if(!objectp(o)) return;
    isrobot=o->query_robot();
    if(isrobot)
	{
		this_object()->targetted_action(
			"一个$N拍拍$T的头：傻瓜，回家睡觉去吧。\n",o);
		this_object()->simple_action(
			"众$N法出一阵哄堂大笑。\n");
		return;
	}
	p_id=o->query_id()[0];
    o->award_exp(50);
    CHAR_D->set_char(p_id,"reputation",
		CHAR_D->get_char(p_id,"reputation")+50);
    CHAR_D->set_char(p_id,"localcontribution",
      CHAR_D->get_char(p_id,"localcontribution")+2);
	CHAR_D->set_char_loyalty(p_id,n_id,
		CHAR_D->get_char_loyalty(p_id,n_id)+2);
    o->simple_action("$N为地区购物成功，$N的经验，声望和与"+
		COUNTRY_D->get_country(n_id,"name")+"的关系提高了。\n");
	if(random(2))
	{
		object ob;
		this_object()->targetted_action(
			"一$N悄声给$T说：多谢$m$R关照，这是一点小意思。\n",o);
		this_object()->targetted_action(
			"%^GREEN%^一$N偷偷给塞给$T一两金子。\n%^RESET%^",o);
		ob=new(M_GOLD);
        ob->set_m_num(1);
        ob->move(o);
	}
}


void my_cancel()
{
	object custom;
	remove_call_out("trade_over");
	this_object()->targetted_action(
		"一$N道：原来$T是在耍我们。\n",this_body());
	this_object()->targetted_action(
		"众$N纷纷道：可恶，可恶。众$N一拥而上，把$t痛打了一顿。\n",this_body());
	CHAR_D->set_char_loyalty(p_custom,n_id,
		CHAR_D->get_char_loyalty(p_custom,n_id)-2);
	this_body()->simple_action(
		"$N大喊救命，$N与"+COUNTRY_D->get_country(n_id,"name")+
		"的关系降低了。\n");

	custom=find_user(p_custom);
	if(objectp(custom))
		custom->modal_pop();
	p_custom=0;
	return;

}
int my_bargen(int sug)
{
	string p_act;
	int rel,res=0;
	this_body()->simple_action(
		"$N道：价钱太贵，我要打"+chinese_number(sug)+"折。\n");
	if(sug<p_discount)
	{
		p_act=sprintf("$N对$T怒道，你当我们是傻子，打%s折都不行，还想打%s折。\n",
			chinese_number(p_discount),chinese_number(sug));
	}
	if(sug==p_discount)
	{
		p_act=sprintf("$N道，不是都说不行了吗，还要提。\n");
	}
	if(sug>p_discount)
	{
		rel=CHAR_D->get_char_loyalty(p_custom,n_id);
		rel/=10;
		rel+=sug;
		rel-=arg_time;
		p_discount=sug;
		if((random(21)+5)<rel)
		{
			res=1;
			p_act=sprintf("$N无可奈何地道：既然$m$R如此说，那就这么定了吧。\n");
		}
		else
		{	if(random(2))
				p_act="众$N道：不行不行，要是这个价，我们全得跳黄河。\n";
			else
				p_act="众$N道：不行不行，我们已经给出最低价。\n";
		}
	}
	this_object()->targetted_action(p_act,this_body());
	arg_time++;
	return res;

}
void trade_process()
{
	string p_prom,p_act;
	object custom;
	custom=find_body(p_custom);
	if((!objectp(custom))||(environment(this_object())!=environment(custom)))
	{
		p_custom=0;
	}
	p_act=get_action();
	this_object()->targetted_action(p_act,custom);
	p_prom=get_prom();
	tell_user(p_custom,p_prom);
	custom=find_user(p_custom);
	if(objectp(custom))
		custom->modal_push((: trade_input :),">");
}
void remove()
{
	remove_call_out("trade_over");
	::remove();
}
// this is used after all other initiate
void extra_init()
{
	string p_id;
	p_id=this_object()->query_id()[0];
	n_id=CHAR_D->get_char(p_id,"my_nation");
}
void my_charaction(){
}
