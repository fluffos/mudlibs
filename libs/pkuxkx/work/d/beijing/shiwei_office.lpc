#include <ansi.h>
inherit ROOM;
#include <title.h>
void create()
{
        set("short", HIY"厅堂"NOR);
        set("long",
HIC"这里是侍卫总管多隆大人办公之所。时常可以看见侍卫们
进进出出来讨令。正中央红木桌上端坐着的就是多大人啦。\n"NOR
        );

        set("exits", ([
                "south" : __DIR__"jiaochang",
        ]));
        set("objects", ([
                __DIR__"npc/duolong" : 1,
        ]));

        setup();
        //replace_program(ROOM);
}

int change_title(object me,int pin)
{
    string title;
    string * province=({"两广","两江","四川","直隶"});
    string * pin9=({"外委把总","兰翎长","协领"});
    string * pin8=({"典仪","亲军校","前锋校","护军校","骁骑校","千总"});
    string * pin7=({"七品典仪","盛京游牧副尉","城门史","马厂协领","把总","安抚使司佥事"});
    string * pin6=({"卫千总","安抚使司副使","内务府六品兰翎长","六品典仪","门千总","营千总","宣抚使司佥事","安抚使司同知","副招讨使","百户","兰翎侍卫","整仪尉"});
    string * pin5=({"关口守御","防御","守备","宣慰使司佥事","宣抚使司同知","千户","分管佐领","监守信礮官","步军校","步军副尉","三等侍卫","治仪正","守御所千总","河营协办守备","安抚使","招讨使","宣抚使司副使","副千户","四等侍卫","委署前锋参领","委署护军参领","委署鸟枪护军参领","委署前锋侍卫","下五旗包衣参领","五品典仪","印物章京","三等护卫"});
    string * pin4=({"贝勒府司仪长","侍卫领班","指挥佥事","宣慰使司同知","二等侍卫","云麾使","副护军参领","副前锋参领","副骁骑参领","太仆寺马厂驼厂总管","宣抚使","宣慰使司副使","二等护卫","四品典仪","城门领","包衣副护军参领","包衣副骁骑参领","包衣佐领","防守尉","佐领","都司"});
    string * pin3=({"城守尉","骁骑参领","王府长史","参将","指挥使","一等侍卫","火器营翼长","健锐营翼长","前锋参领","护军参领","游击","五旗参领","协领","宣慰使","指挥同知","包衣护军参领","包衣骁骑参领","王府一等护卫"});
    string * pin2=({"副将","散秩大臣","副都统","总兵","右翼前锋营统领","左翼前锋营统领","八旗护军统领","銮仪使"});
    string * pin1=({province[random(sizeof(province))]+"将军",province[random(sizeof(province))]+"都统",province[random(sizeof(province))]+"提督","提督九门步军巡捕五营统领","内大臣","领侍卫内大臣","掌銮仪卫事大臣"});
    string * jue3=({"忠诚伯"});
    string * jue2=({"延恩侯","同安侯"});
    string * jue1=({"忠襄公","承恩公","孝愍公","海澄公","忠锐公","辅国公","镇国公","鹿鼎公"});
    switch (pin)
	{
	case 9:
	if (me->query("gender") == "男性")
	title = YEL+pin9[random(sizeof(pin9))]+NOR;
	else if(me->query("gender") == "女性")
	title = YEL+pin9[random(sizeof(pin9))]+NOR;
	else
	title = HIM"尚膳监太监"NOR;
	break;

	case 8:
	//rank_name = ({ YEL"清兵千总"NOR, YEL"清兵守备"NOR,});
	//title = rank_name[random(sizeof(rank_name))];
	title=YEL+pin8[random(sizeof(pin8))]+NOR;
    break;

	case 7:
	//title = HIC"侍卫营侍卫"NOR;
	title=HIY+pin7[random(sizeof(pin7))]+NOR;
    break;

	case 6:
	//rank_name = ({ RED"侍卫营佐领"NOR, RED"侍卫营参将"NOR,});
	//title = rank_name[random(sizeof(rank_name))];
	title=WHT+pin6[random(sizeof(pin6))]+NOR;
    break;

	case 5:
	//title = MAG"侍卫营副都统"NOR;
	title=HIW+pin5[random(sizeof(pin5))]+NOR;
    break;

	case 4:
	/*rank_name = ({
		BLU"侍卫营都统"NOR,
		BLU"侍卫营云骑尉"NOR,
		BLU"侍卫营骑都尉"NOR,
		BLU"前锋营都统"NOR,
		BLU"前锋营云骑尉"NOR,
		BLU"前锋营骑都尉"NOR,
		});
	title = rank_name[random(sizeof(rank_name))];*/
    title=CYN+pin4[random(sizeof(pin4))]+NOR;
	break;

	case 3:
	//title = CYN"御前侍卫总管"NOR;
	title=HIY+jue3[random(sizeof(jue3))]+" "+HIB+pin3[random(sizeof(pin3))]+NOR;
    break;

	case 2:
	/*rank_name = ({
		HIR"平西将军"NOR,
		HIR"镇南将军"NOR,
		HIR"征东将军"NOR,
		HIR"抚远将军"NOR,
		});
	if (ob->query("gender") == "男性")
		title = rank_name[random(sizeof(rank_name))];
	else
		title = HIR"巾帼英雄"NOR;*/
    title=HIY+jue2[random(sizeof(jue2))]+" "+RED+pin2[random(sizeof(pin2))]+NOR;
	break;

	case 1:
	/*rank_name = ({
		HIY"鹿鼎公"NOR,
		HIY"镇国公"NOR,
		HIY"辅国公"NOR,
		});
	if (ob->query("gender") == "男性")
		title = rank_name[random(sizeof(rank_name))];
	else
		title = HIY"女元帅"NOR;*/
        if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
        {
            title=HIY+jue1[random(sizeof(jue1))]+" "+HIR+pin1[random(sizeof(pin1))]+NOR;
        }
    
	break;
	}
	title = HIG+ "朝廷" + chinese_number(pin) + "品官员 "NOR + title;
	me->set("title", title);
	//title系统记录玩家title by seagate@pkuxkx
	me->set_title(TITLE_RANK, title);
    me->set("chaoting/newtitle",1);
    tell_object(me,"恭喜你！你的新官衔是"+title+"\n");
    return 1;
}

void init()
{
    object me=this_player();
    int pin;
    if ((string)me->query("class")== "officer"&&!me->query("chaoting/newtitle")&&me->query("chaoting/officer")&&me->query("pin")&&!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
    {
        pin=(int)me->query("pin");
        change_title(me,pin);
    }
}
