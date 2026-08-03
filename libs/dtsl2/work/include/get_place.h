// kouzhong by dtsl

string get_place(string str)
{
	string *place = explode(str, "/");

	str = "";

	if(place[0] == "d")
	switch(place[1]){
		case "baling":		str = "巴陵";		break;
		case "cahc":	str = "长安皇城";		break;
		case "changan":		str = "长安城";		break;
		case "changbaishan":		str = "长白山";		break;
		case "chanyuan":		str = "静念禅院";		break;
		case "yangzhou": 		str = "扬州城";		break;
		case "chengdu":		str = "成都";	break;
		case "dajianglian":		str = "大江联";		break;
		case "death":	str = "地府";		break;
		case "dingxiang":		str = "定襄";		break;
		case "dongming":		str = "东溟";		break;
		case "emeishan":		str = "峨眉山";		break;
		case "feima-muchang":	str = "飞马牧场";		break;
		case "gaoli":		str = "高丽";		break;
		case "huashan":		str = "华山";		break;
		case "haisha":		str = "海沙帮";		break;
		case "hangzhou":		str = "杭州城";		break;
		case "hefei":		str = "合肥";		break;
		case "hengshan":		str = "恒山";		break;
		case "jingzhai":	str = "慈航静斋";		break;
		case "jiujiang":	str = "九江";		break;
		case "leshou":		str = "乐寿";		break;
		case "lingnan":		str = "宋家堡";		break;
		case "liyang":		str = "历阳";	break;
		case "luoyang":		str = "洛阳";	break;
		case "luoyange":		str = "洛阳东";		break;
		case "mangshan":	str = "邙山";		break;
		case "mayi":		str = "马邑";		break;
		case "yangzhoubei":		str = "扬州北";		break;
		case "outyang" :		str = "扬州外城";		break;
		case "pengliang":	str = "彭凉";		break;
		case "saiwai":	str = "塞外";		break;
		case "shanhaiguan":		str = "山海关";		break;
		case "slwg":		str = "石龙武馆";		break;
		case "suiye":		str = "碎叶";	break;
		case "taishan":		str = "泰山";		break;
		case "taiyuan":	str = "太原";		break;
		case "tujue":		str = "突厥";		break;
		case "wuyishan":	str = "武夷山";		break;
		case "xiangyang":		str = "襄阳";		break;
		case "xingyang":	str = "荥阳";		break;
		case "yjp":		str = "弈剑派";		break;
		case "xuchengn":	str = "许城";		break;
		case "yuyang":	str = "鱼阳";		break;
		case "yinkui":		str = "阴癸派";		break;
//		case "zhiye":		str = "郊外";		break;
		default:		str = "中原神州";	break;
	}
	return str;
}
