// gtitle.h 清代官员品级
// get gf title
// creat by Lklv@SJ 2002.1.24

/*
				官员的品级

清时非常重视官员的品级。当时官员分为九品，每品里又有正，从之分，所谓九品十八级。
不能列入九品以内的，叫做未入流。列表如下：

品级                              官 职

正一品			太师，太傅，太保，大学士

从一品 	少师，少傅，少保，太子太师，太子太傅，太子太保，各部院尚书，
	督察院左，右都御史

正二品 	太子少师，太子少傅，太子少保，各省总督，各部院左，右侍郎。

从二品 	各省巡抚，内阁学士，翰林院掌院学时，各省布政使。

正三品 	督察院左，右副都于是，通政使，大理寺卿，詹事府詹事，太常寺卿，
	顺天府尹，奉天府尹，各省按察使。

从三品 	光禄寺卿，太仆寺卿，各省盐运使。

正四品 	通政司副使，大理寺少卿，詹事府少詹事，太常寺少卿，鸿胪寺卿，
	太傅寺少卿，各省道员。

从四品 	翰林院侍读学士，侍讲学士，国子监祭酒，内阁侍读学士，各省知府。

正五品 	左右春房左右庶子，光禄寺少卿，钦天监监正，六科给事中，
	各部院郎中，各府同知，直隶知州

从五品 	鸿胪寺少卿，各道监察御使，翰林院侍读，侍讲，各部院员外郎，各省知州。

正六品 	国子监司业，内阁侍读，左右春房左右中允，各部院主事，京府通判，
	京县知县，各省通判。

从六品 	左右春房左右善赞，翰林院修撰，光禄寺署正，州同

正七品 	翰林院编修，各部院七品笔贴士，顺天府学教授，训导，京县县丞，
	外县知县，各府学教授。

从七品	翰林院检讨，中书科中书，内阁中书，国子监博士，直隶州州判，州判。

正八品 	太医院御医，各部院八品笔贴士，外府经历，外县县丞，州学正，县教谕。

从八品 	翰林院典簿，府，州，县训导。

正九品 	各部院九品笔贴士，县主簿。

从九品 	翰林院侍诏，刑部司狱，州吏目，巡检。

未入流 	京，外县典吏，驿丞，和泊所所官


			武将品级

品级				官 职

正一品 	领侍卫内大臣

从一品 	将军，督统，提督

正二品 	副督统，总兵	总兵

从二品 	副将		副将

正三品 	参将		参将

从三品 	游击		游击

正四品 	都司		都司

从四品 	城门领		城门领

正五品 	守备		守备

从五品 	守御所千总

正六品 	门千总，营千总	xx州千总

从六品 	卫千总		千总

正七品 	把总		把总

从七品 	盛京游牧副尉	都尉

正八品 	外委千总	xx州铁捕

从八品 	委署骁骑尉	巡捕

正九品 	外委把总	xx州捕头

从九品 	额外外委	快捕

未入流	武官无未入流

*/

string guanfu_title(object me)
{
	int i;
	string str="没有？";

	if ( !me ) return str;

	i = (int)me->query("job_time/官府", 1);

	if ( i < 50 ) str = "官府差役";
	else if ( i < 100 )  str = HIY"从九品快捕"NOR;	//额外外委
	else if ( i < 200 )  str = HIY"正九品捕头"NOR;	//外委把总
	else if ( i < 500 )  str = HIY"从八品校尉"NOR;	//骁骑尉
	else if ( i < 1000 ) str = HIY"正八品铁捕"NOR;	//外委千总
	else if ( i < 1500 ) str = HIY"从七品都尉"NOR;	//盛京游牧副尉
	else if ( i < 2000 ) str = HIY"正七品把总"NOR;	//把总
	else if ( i < 2500 ) str = HIY"从六品卫总"NOR;	//卫千总
	else if ( i < 3000 ) str = HIY"正六品营总"NOR;	//门千总，营千总
	else if ( i < 3500 ) str = HIY"从五品千总"NOR;	//守御所千总
	else if ( i < 4000 ) str = HIY"正五品守备"NOR;	//守备
	else if ( i < 4500 ) str = HIY"从四品统领"NOR;	//城门领
	else if ( i < 5000 ) str = HIY"正四品都司"NOR;	//都司
	else if ( i < 5500 ) str = HIY"从三品游击"NOR;	//游击
	else if ( i < 6000 ) str = HIY"正三品参将"NOR;	//参将
	else if ( i < 6500 ) str = HIY"从二品副将"NOR;	//副将
	else if ( i < 7000 ) str = HIY"正二品总兵"NOR;	//副督统，总兵
	else if ( i < 7500 ) {
		switch (random(3)){	//将军，督统，提督
		case 2:
			str = HIY"从一品将军"NOR;
			break;
		case 1:
			str = HIY"从一品督统"NOR;
			break;
		case 0:
			str = HIY"从一品提督"NOR;
			break;
		}
	}

	else if ( i < 8000 ) {				//领侍卫内大臣
		random(2)?
		str = HIY"正一品大将军"NOR:str = HIY"正一品领侍卫内大臣";
	}
	else str = HIY"御前护卫总领大臣"NOR;

	return str;
}

string get_title()
{
	object me = this_player();
	int i = (int)me->query("job_time/官府", 1);
	string str;

	if ( i < 1 )
		return "这位"+RANK_D->query_respect(me)+"还没有为朝廷出过力，何谈功名呢？！\n";

	if ( stringp(me->query_temp("guanfu_title")) && !wizardp(me))
		return "这位"+RANK_D->query_respect(me)+"，好好为朝廷出力吧。\n";

	str = guanfu_title(me);
	message_vision(CYN"$N言道：我已将"+RANK_D->query_respect(me)+"的功劳报给了兵部，前日朝廷来函任命$n为"+str+"。\n"NOR, this_object(), me);
	me->set_temp("title", str);
	me->set_temp("guanfu_title", "get");
	return "如此下去，"+RANK_D->query_respect(me)+"以后的前途真是不可限量啊！\n";
}
