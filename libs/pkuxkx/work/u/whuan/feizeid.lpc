void random_feizei()
#include <ansi.h>
{
	int exp;
	object feizei;
	object room;
	string *places, place, skill, value;
	mapping rooms = ([
	"/d/xiangyang/xycenter":"襄阳城",
	"/d/xiangyang/sgate":"襄阳城",
	"/d/xiangyang/ngate":"襄阳城",
	"/d/xiangyang/wgate":"襄阳城",
	"/d/xiangyang/egate":"襄阳城",
	"/d/luoyang/center":"洛阳城",
	"/d/luoyang/dongmen":"洛阳城",
	"/d/luoyang/ximen":"洛阳城",
	"/d/luoyang/nanmen":"洛阳城",
	"/d/luoyang/beimen":"洛阳城",
	"/d/dalicheng/northgate":"大理城",
	"/d/dalicheng/dalicheng9":"大理城",	
	"/d/dalicheng/southgate":"大理城",
	"/d/quanzhou/zhongxin":"泉州城",
	"/d/quanzhou/nanmen":"泉州城",
	"/d/quanzhou/beimen":"泉州城",
	"/d/quanzhou/jiaxing":"嘉兴城",
	"/d/quanzhou/jxnanmen":"嘉兴城",
  "/d/city/guangchang":"扬州城",
  "/d/city/ximen":"扬州城",
  "/d/city/nanmen":"扬州城",
  "/d/city/dongmen":"扬州城",
  "/d/city/beimen":"扬州城",
  "/d/suzhou/xidajie1":"苏州城",
  "/d/suzhou/ximen":"苏州城",
  "/d/suzhou/nanmen":"苏州城",
  "/d/suzhou/dongmen":"苏州城",
  "/d/suzhou/beimen":"苏州城",
  "/d/beijing/tianqiao":"北京城",
  "/d/beijing/qianmen1":"北京城",
  "/d/beijing/guangqudajie":"北京城",
  "/d/beijing/chongwenmen":"北京城",
  "/d/beijing/chaoyangdajie":"北京城",
  "/d/beijing/dongzhidajie":"北京城",
  "/d/beijing/zhonglou":"北京城",
  "/d/beijing/xizhidajie":"北京城",
  "/d/beijing/fuchengdajie":"北京城",
  "/d/beijing/xuanwumen":"北京城",
  "/d/lingzhou/center":"灵州城",
  "/d/lingzhou/dongmen":"灵州城",
  "/d/lingzhou/nanmen":"灵州城",
  "/d/dalunsi/zanpugc":"赞普广场",
  "/d/shaolin/ruzhou":"汝州城",
	]);

	places = keys(rooms);
	place = places[random(sizeof(places))];
	if(objectp(room = load_object(place)) &&
	objectp(feizei = new("/d/beijing/npc/feizei")))
	{
		switch (random(15))
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			exp = 10000 + random(80000);
			break;
			case 5:
			case 6:
			case 7:
			case 8:
			exp = 100000 + random(400000);
			break;
			case 9:
			case 10:
			case 11:
			exp = 5000000 + random(450000);
			break;
			case 12:
			case 13:
			exp = 1000000 + random(4000000);
			break;
			case 14:
			exp = 5000000 + random(4000000);
			break;
		}
	if (exp < 100000)
	{
		feizei->Set_Npcattrib(20, 10,
		   			500, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			50000, 50000 );
		if (random(2) == 0)
		feizei->skills_setup_none(10, 90, "random_menpai");
		else
		feizei->skills_setup_weapon(10, 90, "random_menpai");
		skill = WHT"毛头小贼"NOR;
		value = HIY"尚可"NOR;
		feizei->set("bao_value", ( 3 + random(6) ) * 10000);
	}
	else if (exp < 500000)
	{
		feizei->Set_Npcattrib(20, 10,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			100000, 200000 );
		if (random(2) == 0)
		feizei->skills_setup_none(50, 100, "random_menpai");
		else
		feizei->skills_setup_weapon(50, 100, "random_menpai");
		skill = MAG"飞贼小头目"NOR;
		value = HIY"中等"NOR;
		feizei->set("bao_value", ( 5 + random(8) ) * 10000);
	}
	else if (exp < 1000000)
	{
		feizei->Set_Npcattrib(20, 10,
		   			1000, 2000,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			200000, 500000 );
		if (random(2) == 0)
		feizei->skills_setup_none(80, 120, "random_menpai");
		else
		feizei->skills_setup_weapon(80, 120, "random_menpai");
		skill = HIB"飞贼头目"NOR;
		value = HIY"不菲"NOR;
		feizei->set("bao_value", ( 8 + random(9) ) * 10000);
	}
	else if (exp < 5000000)
	{
		feizei->Set_Npcattrib(20, 10,
		   			1500, 2500,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			300000, 2000000 );
		if (random(2) == 0)
		feizei->skills_setup_none(100, 150, "random_menpai");
		else
		feizei->skills_setup_weapon(100, 150, "random_menpai");
		skill = RED"飞贼首领"NOR;
		value = HIY"可观"NOR;
		feizei->set("bao_value", ( 15 + random(11) ) * 10000);
	}
	else
	{
		feizei->Set_Npcattrib(20, 10,
		   			2000, 2500,
		   			1000, 1000,
		   			1000, 1000,
		   			1000, 1000,
		   			2000000, 5000000 );
		if (random(2) == 0)
		feizei->skills_setup_none(150, 180, "random_menpai");
		else
		feizei->skills_setup_weapon(150, 180, "random_menpai");
                skill = HIR"江洋大盗"NOR;
		value = HIY"连城"NOR;
		feizei->set("bao_value", ( 20 + random(16) ) * 10000);
	}
	feizei->set("catcher","auto create");
	feizei->move(room);
	}
        message("channel:baowei", HIW"【官府通告】"CYN + rooms[place] + CYN"中今夜有" + skill + CYN"横行，据说此贼带有价值" + value + CYN"的财宝！\n"NOR,users() );
}
