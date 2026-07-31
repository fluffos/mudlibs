// miyao.c      铜镜

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_zhao", "zhao");
}

string *per_msg_male1 = ({
        CYN "长得伟岸英挺，顾盼之间，神采飞扬。\n" NOR,
        CYN "丰姿英伟，气宇轩昂，确实是人中龙凤。\n" NOR,
});

string *per_msg_male2 = ({
        CYN "英俊潇洒，风度翩翩。\n" NOR,
        CYN "相貌出众，面目俊朗。\n" NOR,
        CYN "面貌清奇，丰姿非俗。\n" NOR,
});
string *per_msg_male3 = ({
        CYN "相貌平平，没什么好看的。\n" NOR,
        CYN "相貌凶恶，满脸横肉。\n" NOR,
        CYN "暴睛环眼，嘴脸凶顽。\n" NOR,
});
string *per_msg_male4 = ({
        CYN "长得一副姥姥不疼，舅舅不爱的模样。\n" NOR,
        CYN "长得蔫蔫的，一副无精打采的模样。 \n" NOR, 
        CYN "五短三粗，肥头大耳，大概是猪八戒的本家。 \n" NOR, 
});
string *per_msg_female1 = ({
        CYN "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 \n" NOR,
        CYN "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。 \n" NOR,
        CYN "风情万种，楚楚动人，当真是我见犹怜。 \n" NOR, 
});
string *per_msg_female2 = ({
        CYN "婷婷玉立，容色秀丽，风姿动人。 \n" NOR,
        CYN "玉面娇容花含露，纤足细腰柳带烟。 \n" NOR,
        CYN "面带晕红，眼含秋波。举手投足之间，确有一番风韵。 \n" NOR,
});
string *per_msg_female3 = ({
        CYN "虽算不上绝世佳人，也颇有几份姿色。 \n" NOR,
        CYN "长得还不错，颇有几份姿色。  \n" NOR,
});
string *per_msg_female4 = ({
        CYN "长得比较难看。 \n" NOR,
        CYN "长得………唉！  \n" NOR,
});

string *per_msg_kid1 = ({
        CYN "月眉星眼，灵气十足。\n" NOR,
        CYN "机灵活泼，神态非凡。\n" NOR,
        CYN "面若秋月，色如晓花。\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "隆额大眼，脸色红润。\n" NOR,
        CYN "胖胖嘟嘟，逗人喜欢。\n" NOR,
        CYN "细皮嫩肉，口齿伶俐。\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "身材矬矮，傻里傻气。\n" NOR,
        CYN "肥肥胖胖，小鼻小眼。\n" NOR,
        CYN "呆头呆脑，笨手笨脚。\n" NOR,
});

string *per_msg_kid4 = ({
        CYN "蓬头垢脚，脸黄肌瘦。\n" NOR,
        CYN "神如木鸡，面有病色。\n" NOR,
        CYN "五官不整，四肢不洁。\n" NOR,
});

void create()
{
	set_name(HIY "铜镜" NOR, ({"tong jing", "tong", "jing"}));
        set("unit", "面");
        set_weight(500);
	set("long", "这是一面可以照(zhao jing)出人容貌的铜镜。\n");
	set("value", 500);
        setup();
}

string per_status_msg(int age, int per, string gender)
{
	// added by snowcat 
	if (age < 16) {
		if ( per>=25 )
			return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
		else if ( per>=20 )
			return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
		else if ( per>=15 )
			return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
		else 	return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
		}
		
	if ( gender == "男性" ) {
		if ( per>=25 )
			return ( per_msg_male1[random(sizeof(per_msg_male1))]);
		else if ( per>=20 )
			return ( per_msg_male2[random(sizeof(per_msg_male2))]);
		else if ( per>=15 )
			return ( per_msg_male3[random(sizeof(per_msg_male3))]);
		else 	return ( per_msg_male4[random(sizeof(per_msg_male4))]);
		}
		
	if ( gender == "女性" ) {
		if ( per>=25 )
                        return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                else if ( per>=20 )
                        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                else if ( per>=15 )
                        return ( per_msg_female3[random(sizeof(per_msg_female3))]);
	    	else	return ( per_msg_female4[random(sizeof(per_msg_female4))]);
                }
	else return "长得怎样你没什么概念。\n";
}

int do_zhao(string arg)
{
	object me;
	string ogender, beauty;

	me = this_player();

	ogender = me->query("gender");

	if (!arg || (arg != "tong jing" && arg != "jing")) return notify_fail("你想照什么？\n");

	beauty = per_status_msg((int)me->query("age"), (int)me->query_per(), ogender);

	message_vision("$N端起铜镜仔细的端详着。\n", me);

	tell_object(me, "铜镜依稀映出你的容貌：你"+beauty);
	
	return 1;
}