// Room: /d/huashan/shulin.c
// Date: Look 99/03/25

inherit ROOM;

#include <ansi.h>
int check(object ob);
string get_place(string str);

string* msg1 = ({"忽然","突然",	"猛地",	"冷不防",});
string* msg2 = ({"从树林里","从树林深处",});
string* msg3 = ({"窜出","杀出",});
string* msg4 = ({"一把夺下","夺下","一把抢去","抢去",});
string* msg5 = ({"处",	"方向",	"处夺路","方向夺路",});

string* names = ({
"/d/village/caidi",	"/d/village/shilu1",	"/d/village/shilu2",
"/d/village/shilu3",	"/d/village/shilu4",	"/d/village/shilu5",
"/d/village/shilu6",	__DIR__"canglong",	__DIR__"celang1",
__DIR__"celang2",	__DIR__"chaoyang",	__DIR__"husun",
__DIR__"pubu",		__DIR__"qianchi",	__DIR__"qingke",
__DIR__"shaluo",	__DIR__"sheshen",	__DIR__"shulin1",
__DIR__"shulin2",	__DIR__"shulin3",	__DIR__"shulin4",
__DIR__"yuquan",	__DIR__"yunu",		__DIR__"zhenyue",
__DIR__"shanlu1",	__DIR__"xiaolu2",	__DIR__"siguoya",
__DIR__"baichi",	__DIR__"laojun",	__DIR__"houtang",
__DIR__"celang3",	__DIR__"celang4",
});

void create()
{
        set("short", "树林");
        set("long",@long
这里是华山村里的一片杨树林，如果你没有好身手，可千万不要在此地久
留，据说这里强盗出没，抢劫、杀人的事情经常发生。
long);
        set("exits",([
		"west" : __DIR__"shulin3",
	        "north" : __DIR__"shulin2",
		"east" : __DIR__"shulin1",
	]));
	setup();
}

void init(object me)
{
	object target, *living, ob, name1, ling;
	string objwhere, str;
	int i, j;

	me = this_player();
	name1 = me->query("id");
	ling = present("ling pai", me);

        if( ! (present("mengmian ren", environment(me)) ) 
	 && (int)me->query_temp("hs/jobji", 1)==1 
	 && (int)me->query_temp("hs/have", 1)==0
	 && ling
	 && (int)ling->query_temp("done", 1) < 2
	 && !(ling->query_temp("hsjob") != name1 )
	 &&  random(10) > 3 ) {

		living = livings();
		for (i=0;i < sizeof(living);i++){
			j = random(sizeof(living));
			if (j <= 1 || j == sizeof(living)-1) continue;
			if(check(living[j]) ){
				target = living[j];
				str = environment(target)->query("short");
				if( str == "武僧堂"
				 || str == HIR"心禅堂"NOR
				 || str == "金刚伏魔圈" ) continue;
				if( get_place(base_name(environment(target)))!="" )
					break;
			}
		}

		ob=new(__DIR__"npc/mmr");
		ob->set("long", ob->query("long")+ "看来就是刚才抢走"+me->query("name")+"("+capitalize(me->query("id"))+")令牌的人。\n");
		ling->move(ob);
		me->set_temp("hs/have", 1);
		ling->set_temp("mmr", name1);
		ob->set_temp("mmr", name1);

		if (me->query("combat_exp", 1) > 2000000
		 && ling->query_temp("done", 1) > 0
		 && target ) {
			ob->move(environment(target));
			me->set_temp("hs/power", 1);
			message_vision(HIW "\n" + msg1[random(sizeof(msg1))] +
				msg2[random(sizeof(msg2))] + 
				msg3[random(sizeof(msg3))] + "一个蒙面人" +
				msg4[random(sizeof(msg4))] + 
				"$N的令牌，向" HIY +get_place(base_name(environment(target)))+ str +
				HIW + msg5[random(sizeof(msg5))] + "逃去。\n\n" NOR, me);
			return;
		}
		else {
			objwhere = names[random(sizeof(names))];
			ob->move(objwhere);
			message_vision(HIW "\n" + msg1[random(sizeof(msg1))] +
				msg2[random(sizeof(msg2))] + 
				msg3[random(sizeof(msg3))] + "一个蒙面人" +
				msg4[random(sizeof(msg4))] + 
				"$N的令牌，向" HIY + objwhere->query("short") + 
				HIW + msg5[random(sizeof(msg5))] + "逃去。\n\n" NOR, me);
		}
	}
}

string *no_kill_list = ({
	"mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || member_array(ob->query("id"), no_kill_list) != -1
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("outdoors") == "昆仑翠谷"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/huashan/") == 0
	 || strsrch(room_name, "/d/village/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}

string get_place(string str)
{ 
        string *place = explode(str, "/");

        str = "";
        if(place[0] == "d")
                switch(place[1]){
//			case "baituo":          str = "西域白陀山";     break;
//			case "beijing":         str = "京城";           break;
//			case "cangzhou":        str = "河北沧州";       break;
//			case "changan":         str = "陕西长安";       break;
			case "chengdu":         str = "四川成都";       break;
			case "city":            str = "江南扬州城";     break;
			case "dali": 
				switch(place[2]) {
					case "daliwest":        str = "大理城西";       break;
					case "dalisouth":       str = "大理城南";       break;
					case "dalieast":        str = "大理城东";       break;
					case "wuliang":         str = "大理无量山";     break;
					case "dlhg":            str = "大理皇宫";       break;
					case "wangfu":          str = "大理王府";       break;
					case "yuxu":            str = "大理玉虚观";     break;
					default :               str = "西南大理国";     break;
				}
				break;
			case "death":           str = "十八层地狱";     break;
			case "emei":            str = "四川峨嵋山";     break;
			case "fairyland":       str = "昆仑山脉";       break;
			case "foshan":          str = "广东佛山镇";     break;
			case "fuzhou":          str = "南疆福州";       break;
			case "gb":              str = "丐帮分舵";       break;
			case "gumu": 
				switch(place[2]) {
					case "jqg":             str = "绝情谷";         break;
					case "xuantie":         str = "襄阳郊外";       break;
					default :               str = "终南古墓";       break;
				}
				break;
			case "hengshan":        str = "北岳恒山";       break;
			case "hj":              str = "西域回疆";       break;
/*                      case "hmy":
                                switch(place[2]) {
                                        case "pingding":        str = "山西平定州";     break;
                                        default:                str = "黑木崖";         break;
                                }
                                break;
*/			case "huanghe":
				switch(place[2]) {
					case "yyd":             str = "黄河萧府";       break;
					default :               str = "黄河地带";       break;
				}
				break;
			case "huashan":         str = "陕西华山";       break;
			case "hz":              str = "江南杭州";       break;
			case "jiaxing":         str = "江南嘉兴";       break;
//			case "kunlun":          str = "昆仑山脉";       break;
//			case "lanzhou":         str = "甘肃兰州";       break;
//                      case "meizhuang":       str = "西湖梅庄";       break;
			case "miaojiang":       str = "西南苗疆";       break;
			case "mingjiao": 
				switch(place[2]) {
					case "hdg":             str = "安徽蝴蝶谷";     break;
					case "hhd":             str = "北极冰火岛";     break;
					case "lsd":             str = "东海灵蛇岛";     break;
					default :               str = "西域明教";       break;
				}
				break;
			case "mr":		str = "姑苏慕容";       break;
			case "nanyang":         str = "南阳许家集";     break;
			case "ningbo":          str = "江南宁波";       break;
			case "putian":          str = "莆田少林";       break;
			case "shaolin":         str = "嵩山少林";       break;
			case "sld":             str = "北海神龙岛";     break;
			case "songshan":        str = "河南嵩山";       break;
			case "suzhou":          str = "苏州县城";       break;
			case "taishan":         str = "山东泰山";       break;
			case "tanggu" :         str = "天津塘沽";       break;
			case "thd": 
				switch(place[2]) {
					case "niujia":          str = "东海牛家村";     break;
					case "guiyun":          str = "太湖归云庄";     break;
					default:                str = "东海桃花岛";     break;
				}
				break;
//			case "tianshan":        str = "西域天山";       break;
			case "tiezhang":        str = "湖南铁掌山";     break;
			case "tls":             str = "大理天龙寺";     break;
			case "village":         str = "陕西小村";       break;
			case "wizard":          str = "极乐世界";       break;
			case "wudang":          str = "湖北武当山";     break;
			case "wuguan":          str = "襄阳武馆";       break;
			case "xiangyang":       str = "湖北襄阳";       break;
                        case "xingxiu": 	str = "西域星宿海";     break;
			case "xueshan":		str = "西番大雪山";     break;
	}
	return str;
}
