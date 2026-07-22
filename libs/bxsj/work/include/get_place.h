// River@SJ 2001.9.27

string get_place(string str)
{
	string *place = explode(str, "/");

	str = "";
	if(place[0] == "cmds") {
		switch(place[1]){
			case "leitai":
				switch(place[2]){
					case "bwdh":	str = "试剑山庄";		break;
					default:	str = "擂台";			break;
				}
			break;
		}
		return str;
	}
	if(place[0] == "d")
	switch(place[1]){
		case "baituo":		str = "白驼山";		break;
//		case "beijing":		str = "京城";		break;
		case "cangzhou":	str = "沧州城";		break;
		case "changan":		str = "长安城";		break;
		case "changle":		str = "长乐帮";		break;
		case "chengdu":		str = "成都城";		break;
		case "city": 		str = "扬州城";		break;
		case "dali":
			switch(place[2]) {
				case "daliwest":	str = "大理城西";	break;
				case "dalisouth":	str = "大理城南";	break;
				case "dalieast":	str = "大理城东";	break;
				case "wuliang":		str = "无量山";		break;
				case "dlhg":		str = "大理皇宫";	break;
				case "wangfu":		str = "大理王府";	break;
				case "yideng":		str = "桃源县";		break;
				case "yuxu":		str = "玉虚观";		break;
				default : 		str = "大理城";		break;
			}
			break;
		case "death":		str = "十八层地狱";	break;
		case "emei":		str = "峨嵋山";		break;
		case "fairyland":	str = "昆仑山";		break;
		case "foshan":		str = "佛山镇";		break;
		case "fuzhou":		str = "福州城";		break;
		case "gb":		str = "丐帮";		break;
		case "group":
			switch(place[2]){
				case "entry":		str = "";		break;
				default :		str = "中原";		break;
			}
			break;
		case "gumu":
			switch(place[2]) {
				case "jqg":		str = "绝情谷";		break;
				case "xuantie":		str = "襄阳郊外";	break;
				default : 		str = "终南山";		break;
			}
			break;
		case "hengshan":	str = "恒山";		break;
		case "hj":		str = "回疆";		break;
		case "hmy":
			switch(place[2]) {
				case "pingding":	str = "平定州";		break;
				default:		str = "黑木崖";		break;
			}
			break;
		case "huanghe":
			switch(place[2]) {
				case "yyd":		str = "萧府";		break;
				default :		str = "黄河流域";	break;
			}
			break;
		case "huashan":		str = "华山";		break;
		case "hz":		str = "杭州城";		break;
		case "jiaxing":		str = "嘉兴城";		break;
		case "kunlun":		str = "昆仑山";		break;
		case "lanzhou":		str = "兰州城";		break;
		case "meizhuang":	str = "梅庄";		break;
		case "miaojiang":	str = "苗疆";		break;
		case "mingjiao":
			switch(place[2]) {
				case "hdg":		str = "蝴蝶谷";		break;
				case "hhd":		str = "冰火岛";		break;
				case "lsd":		str = "灵蛇岛";		break;
				default :		str = "明教";		break;
			}
			break;
		case "mr":
			switch(place[2]){
				case "yanziwu":		str = "燕子坞";		break;
				case "mtl":		str = "曼佗罗山庄";	break;
				default :		str = "姑苏慕容";	break;
			}
			break;
		case "nanyang":		str = "南阳城";		break;
		case "ningbo":		str = "宁波城";		break;
		case "putian":		str = "莆田少林";	break;
		case "shaolin":		str = "嵩山少林";	break;
		case "sld":		str = "神龙岛";		break;
		case "songshan":	str = "嵩山";		break;
		case "suzhou":		str = "苏州城";		break;
		case "taishan":		str = "泰山";		break;
		case "tanggu" :		str = "塘沽城";		break;
		case "thd":
			switch(place[2]) {
				case "niujia":		str = "牛家村";		break;
				case "guiyun":		str = "归云庄";		break;
				default:		str = "桃花岛";		break;
			}
			break;
		case "tianshan":	str = "天山";		break;
		case "tiezhang":	str = "铁掌山";		break;
		case "tls":		str = "天龙寺";		break;
		case "village":		str = "华山村";		break;
		case "wizard":		str = "极乐世界";	break;
		case "wudang":
			switch(place[2]) {
				case "houshan":		str = "武当后山";	break;
				default:		str = "武当山";		break;
			}
			break;
		case "wuguan":		str = "武馆";		break;
		case "xiakedao":	str = "侠客岛";		break;
		case "xiangyang":
			switch(place[2]) {
				case "lzz":		str = "柳宗镇";		break;
				default:		str = "襄阳城";		break;
			}
			break;
		case "xingxiu":
			switch(place[2]) {
				case "yili":		str = "伊犁城";		break;
				default:		str = "星宿海";		break;
			}
			break;
		case "xueshan":
			switch(place[2]) {
				case "caoyuan":		str = "大草原";		break;
				default :		str = "大雪山";		break;
			}
			break;
//		case "zhiye":		str = "郊外";		break;
		default:		str = "中原神州";	break;
	}
	return str;
}
