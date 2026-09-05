#include <ansi.h>
string *pin0=({HIY"骠骑大将军"NOR});
string *pin1=({"骠骑大将军"});
string *pin2=({"辅国大将军","镇国大将军"});
string *pin3=({"冠军大将军","怀化大将军","云麾将军","归德将军"});
string *pin4=({"忠武将军","壮武将军","宣威将军","明威将军"});
string *pin5=({"定远将军","宁远将军","游骑将军","游击将军",});
string *pin6=({"昭武校尉","振威校尉",});
string *pin7=({"致果校尉","翊麾校尉"});
string *pin8=({"宣节校尉","御武校尉"});
string *pin9=({"仁勇校尉","陪戎校尉"});

string give_title(object me)
{
	string title="";
	if (!me->query("pin"))
	return "";
	switch (me->query("pin"))
	{
	case 0:
	title+=pin0[random(sizeof(pin0))];
	break;
	case 1:
	title+=pin1[random(sizeof(pin1))];
	break;
	case 2:
	title+=pin2[random(sizeof(pin2))];
	break;
	case 3:
	title+=pin3[random(sizeof(pin3))];
	break;
	case 4:
	title+=pin4[random(sizeof(pin4))];
	break;
	case 5:
	title+=pin5[random(sizeof(pin5))];
	break;
	case 6:
	title+=pin6[random(sizeof(pin6))];
	break;
	case 7:
	title+=pin7[random(sizeof(pin7))];
	break;
	case 8:
	title+=pin8[random(sizeof(pin8))];
	break;
	case 9:
	title+=pin9[random(sizeof(pin9))];
	break;
	}
	if (me->query("chaoting/wang")||me->query("chaoting/jiawang"))
	title=pin0[random(sizeof(pin0))];
	return HIR+"大宋 "+NOR+title+NOR;
}