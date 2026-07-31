// kang.h for kangqw job Amis@xajh2 2005-6-9 

#include <ansi.h>
#define POS "/adm/daemons/poistiond.lpc"
string ask_fenglu();
string ask_shengqian();
string ask_shengqian()
{
	object me,ob;
	string rank,rank2,guanzhi;
	int position,pos;
	string  *rank_zhengjiu = ({
	BLU"【修武校尉】"NOR,	BLU"【  把 总 】"NOR,	BLU"【 营翎长 】"NOR});
	string  *rank_congba = ({
	YEL"【奋武佐校尉】"NOR,	YEL"【护军校尉】"NOR,	YEL"【骁骑校尉】"NOR});
	string  *rank_zhengba = ({
	YEL"【奋武校尉】"NOR,	YEL"【 千  总 】"NOR});
	string  *rank_congqi = ({
	YEL"【武信佐骑尉】"NOR,	YEL"【游牧副尉】"NOR});
	string  *rank_zhengqi = ({
	YEL"【武信骑尉】"NOR,	YEL"【游牧正尉】"NOR,	YEL"【 恩骑尉 】"NOR});
	string  *rank_congliu = ({
	GRN"【武略佐骑尉】"NOR,	GRN"【 卫千总 】"NOR,	GRN"【内务府翎长】"NOR});
	string  *rank_zhengliu = ({
	GRN"【武略骑尉】"NOR,	GRN"【蓝翎侍卫】"NOR,	GRN"【 门千总 】"NOR,	GRN"【 营千总 】"NOR,	
	GRN"【副招讨使】"NOR,	GRN"【 百  户 】"NOR});
	string  *rank_congwu = ({
	MAG"【武德佐骑尉】"NOR,	MAG"【四等侍卫】"NOR,	MAG"【委署参领】"NOR,	MAG"【守御千总】"NOR,	
	MAG"【 副军校 】"NOR,	MAG"【 副千户 】"NOR});
	string  *rank_zhengwu = ({
	MAG"【武德骑尉】"NOR,	MAG"【三等侍卫】"NOR,	MAG"【陵寝防御】"NOR,	MAG"【分管佐领】"NOR,	
	MAG"【 正军校 】"NOR,	MAG"【 千  户 】"NOR,	MAG"【河防守备】"NOR,	MAG"【 云骑尉 】"NOR});
	string  *rank_congsi = ({
	CYN"【宣武都尉】"NOR,	CYN"【二等护卫】"NOR,	CYN"【包衣佐领】"NOR,	CYN"【宣慰副使】"NOR,	
	CYN"【 副参领 】"NOR,	CYN"【四品典仪】"NOR});
	string  *rank_zhengsi = ({
	CYN"【前锋侍卫】"NOR,	CYN"【二等侍卫】"NOR,	CYN"【步军协尉】"NOR,	CYN"【信驳总管】"NOR,	
	CYN"【南苑总管】"NOR,	CYN"【 骑都尉 】"NOR,	CYN"【 副参领 】"NOR,	CYN"【 云麾使 】"NOR});
	string  *rank_congsan = ({
	WHT"【包衣营总】"NOR,	WHT"【一等护卫】"NOR,	WHT"【察哈尔参领】"NOR,	WHT"【五旗参领】"NOR,	
	WHT"【护军参领】"NOR,	WHT"【骁骑参领】"NOR,	WHT"【指挥同知】"NOR,	WHT"【驻防协领】"NOR});
	string  *rank_zhengesan = ({
	WHT"【火器营翼长】"NOR,	WHT"【一等侍卫】"NOR,	WHT"【步军翼尉】"NOR,	WHT"【护军统领】"NOR,	
	WHT"【圆明园总管】"NOR,	WHT"【察哈尔总管】"NOR,	WHT"【轻车都尉】"NOR,	WHT"【 正参将 】"NOR});
	string  *rank_conger = ({
	HIB"【武功将军】"NOR,	HIB"【 副总兵 】"NOR,	HIB"【 协都统 】"NOR});
	string  *rank_zhenger = ({
	HIB"【武显将军】"NOR,	HIB"【前锋营统领】"NOR,	HIB"【 副都统 】"NOR,	
	YEL"【 总  兵 】"NOR,	HIB"【 銮仪使 】"NOR});
	string  *rank_congyi = ({
	HIW"【继威将军】"NOR,	HIW"【驻防将军】"NOR,	HIW"【 提  督 】"NOR,	
	HIW"【八旗都统】"NOR,	HIW"【察哈尔都统】"NOR});
	string  *rank_zhengyi = ({
	HIR+"【 大将军 】"+NOR,HIR+"【领侍卫内大臣】"+NOR});

	me=this_player(); 
	//rank = RANK_D->query_rank(me);
	pos = me->query("mark/guanzhi");
	
	if (!me->query("mark/achievement"))
	return "你又非我朝廷中人，何出此言啊？";
	
/*说明：
me->query("mark/achievement")表示功绩、也就是贡献度
me->query("mark/guanzhi") 表示品级 数字对应几品 一共是九品十八级
me->query("rank_info/title2") 是title上显示的rank称呼
*/

		if ( me->query("mark/achievement")>25000 )
			{ 
				rank2 = rank_zhengyi[random(sizeof(rank_zhengyi))]; 
				guanzhi = HIR+"正一品"+NOR;position=	18;	    }
		else if ( me->query("mark/achievement")>18000 )
			{ 
				rank2 = rank_congyi[random(sizeof(rank_congyi))]; 
				guanzhi = HIR+"从一品"+NOR;position=	17;		
			}
		else if ( me->query("mark/achievement")>13000 )
			{ 
				rank2 = rank_zhenger[random(sizeof(rank_zhenger))];  
				guanzhi = HIR+"正二品"+NOR;position=	16; 		
			}
		else if ( me->query("mark/achievement")>10000 )
			{ 
				rank2 = rank_conger[random(sizeof(rank_conger))]; 
				guanzhi = HIR+"从二品"+NOR;position=	15;		
			}
		else if ( me->query("mark/achievement")>8000 )
			{ 
				rank2 = rank_zhengesan[random(sizeof(rank_zhengesan))]; 
				guanzhi = HIR+"正三品"+NOR;position=	14;		
			}
		else if ( me->query("mark/achievement")>5500 )
			{ 
				rank2 = rank_congsan[random(sizeof(rank_congsan))]; 
				guanzhi = HIR+"从三品"+NOR;position=	13;		
			}
		else if ( me->query("mark/achievement")>4000 )
			{ 
				rank2 = rank_zhengsi[random(sizeof(rank_zhengsi))]; 
				guanzhi = HIR+"正四品"+NOR;position=	12;		
			}
		else if ( me->query("mark/achievement")>3000 )
			{ 
				rank2 = rank_congsi[random(sizeof(rank_congsi))]; 
				guanzhi = HIR+"从四品"+NOR;position=	11;		
			}
		else if ( me->query("mark/achievement")>2000 )
			{ 
				rank2 = rank_zhengwu[random(sizeof(rank_zhengwu))]; 
				guanzhi = HIR+"正五品"+NOR;position=	10;		
			}
		else if ( me->query("mark/achievement")>1500 )
			{ 
				rank2 = rank_congwu[random(sizeof(rank_congwu))]; 
				guanzhi = HIR+"从五品"+NOR;position=	9;	
			}
		else if ( me->query("mark/achievement")>1000 ) 		
			{ 
				rank2 = rank_zhengliu[random(sizeof(rank_zhengliu))]; 
				guanzhi = HIR+"正六品"+NOR;position=	8;		
			}
		else if ( me->query("mark/achievement")>500 ) 
			{ 
				rank2 = rank_congliu[random(sizeof(rank_congliu))]; 
				guanzhi = HIR+"从六品"+NOR;position=	7;	
			}
		else if ( me->query("mark/achievement")>300 ) 
			{ 
				rank2 = rank_zhengqi[random(sizeof(rank_zhengqi))]; 
				guanzhi = HIR+"正七品"+NOR;position=	6;		
			}
		else if ( me->query("mark/achievement")>160) 
			{ 
				rank2 = rank_congqi[random(sizeof(rank_congqi))]; 
				guanzhi = HIR+"从七品"+NOR;position=	5;	
			}
		else if ( me->query("mark/achievement")>80) 
			{ 
				rank2 = rank_zhengba[random(sizeof(rank_zhengba))];  
				guanzhi = HIR+"正八品"+NOR;position=	4;		
			}
		else if ( me->query("mark/achievement")>40) 
			{ 
				rank2 = rank_congba[random(sizeof(rank_congba))]; 
				guanzhi = HIR+"从八品"+NOR;position=	3;	
			}
		else if ( me->query("mark/achievement")>20) 
			{ 
				rank2 = rank_zhengjiu[random(sizeof(rank_zhengjiu))]; 
				guanzhi = HIR+"正九品"+NOR;position=	2;
			}
		else if ( me->query("mark/achievement")>10 ) 
			{ rank2 = BLU+"【修武佐校尉】"+NOR; guanzhi = HIR+"从九品"+NOR;position=	1;	}
		else 
		return "你为朝廷效力日子尚浅，功劳微薄，现在就着急想升官发财了？还是多用点心为皇上效力吧！\n";	
		
    me->set("mark/guanzhi", position);  
    if (!POS->query_sortall(me)) return "朝廷官职并无你的记录。";
		if ( me->query("mark/guanzhi") < pos )
		{
			// for save file
			if (!POS->query_sortall(me)) return "朝廷官职并无你的记录。";
			//save over
			me->set("rank_info/title2", rank2);
			message_vision("康亲王对$N怒喝道: 你屡次亏负朝廷，还有何面目见我？皇上已降旨把你降为"+rank2+"了！\n", me);
			return "以后再若如此，定不轻饶！\n";
		}
		if ( me->query("mark/guanzhi") > pos )
		{
			// for save file
			if (!POS->query_sortall(me)) return "朝廷官职并无你的记录。";
			//save over
			me->set("rank_info/title2", rank2);
			return "好吧，皇上其实早有诏书在此，特封你"+rank2+"之职，位居"+guanzhi+"，以后你可要好好干啊！\n";
		}
		
		else return "你现居"+me->query("rank_info/title2")+"之职，可要多为朝廷出力，替皇上分忧啊！";

}

string ask_fenglu()
{
	object me,ob,qian;
	int sil,sil1,sil2,guanzhi,fenglu;
	me=this_player(); 
	guanzhi= me->query("mark/guanzhi");
	
	if (!me->query("mark/guanzhi"))
	return "你又非我朝廷中人，还想要什么俸禄？快给本王滚出去！";

		if ( me->query("mark/guanzhi")==18 )
			{ sil1=800;		}
		else if ( me->query("mark/guanzhi")==17 )
			{ sil1=500; }
		else if ( me->query("mark/guanzhi")==16 )
			{ sil1=400; }
		else if ( me->query("mark/guanzhi")==15 )
			{ sil1=300;		}
		else if ( me->query("mark/guanzhi")==14 )
			{ sil1=280;		}
		else if ( me->query("mark/guanzhi")==13 )
			{ sil1=250;	}
		else if ( me->query("mark/guanzhi")==12 )
			{ sil1=230; 	}
		else if ( me->query("mark/guanzhi")==11 ) 
			{ sil1=220;	}
		else if ( me->query("mark/guanzhi")==10 ) 
			{ sil1=200;	}
		else if ( me->query("mark/guanzhi")==9 )
			{ sil1=150;		}
		else if ( me->query("mark/guanzhi")==8 )
			{ sil1=100;		}
		else if ( me->query("mark/guanzhi")==7 )
			{ sil1=70; }
		else if ( me->query("mark/guanzhi")==6 )
			{ sil1=50; }
		else if ( me->query("mark/guanzhi")==5 )
			{ sil1=40;		}
		else if ( me->query("mark/guanzhi")==4 )
			{ sil1=30;		}
		else if ( me->query("mark/guanzhi")==3 )
			{ sil1=20;	}
		else if ( me->query("mark/guanzhi")==2 )
			{ sil1=10;}
		else if ( me->query("mark/guanzhi")==1 ) 
			{ sil1=5;	}

			sil2 = sil1*(10+guanzhi);
			sil = sil1+sil2;
		me->set("kqwfenglu",sil);		
		fenglu = (int)me->query("kqwfenglu",sil);
	
		
	if ( (int)me->query_condition("money_time") < 1 )
	{
		if (fenglu < 1000)
		{
			qian=new("/clone/money/silver");
			qian->set_amount(fenglu);
			qian->move(me);
			write("你得到了"HIW+fenglu+"两白银！\n"NOR);
		}
		else
		{
			fenglu = (int)((fenglu/100)-(int)(fenglu * 2 /1000));
			qian=new("/clone/money/gold");
			qian->set_amount(fenglu);
			qian->move(me);	
			write("除去赋税，你得到了"+fenglu+YEL"两黄金！\n"NOR);		
		}
		
		me->apply_condition("money_time", 480);		
		return "这是你本月应得的俸禄，拿去吧，以后可要继续好好为朝廷效力！";
	}
	else {
		write("康亲王悄声道：你目前的俸禄是每月"+HIW+"正俸 "+CHINESE_D->chinese_number(sil1)+"两"NOR+"，"+HIW+"养廉银 "+CHINESE_D->chinese_number(sil2)+"两"+NOR+"！\n");
		return "以后你可要继续努力才能对得起皇上的厚恩啊！";
	}
	
}
