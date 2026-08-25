// name.c used for random npc
#include <ppl.h>

private string *surname =({"赵","钱","孙","李","周","吴","郑","王","冯","陈","武",
"卫","唐","马","杨","张","胡","公孙","欧阳","司马","全","郝",
"林","黄","洪","黑","白","史","温","冷","任","东方","孤独",
"朱","段","关","庞","魏","严","韩","汪","程","章","毛","周",
"刘","翁","邓","姜","蒋","江","萧","乔","贾","沙","万","茅",
"郭","钟","寥","夏侯","石","陆","鲁","蔡","典","丁","董","甘",
"高","顾","何","太史","田",});

private string *cgname=({"文","双","天","明","康","羽","宇","宁","江","清",
"云","纪","诗","进","歆","良","兰","恩","莹","秋","英","香",
"枫","靖","瑜"});

private string *fmgname=({"雪","蓉","宁","双","龙","柔","筝","素","芙","襄",
"玉","箐","晴","文","妮","天","霏","茜","昭","盼","红","娟",
"花","婵"});

private string *mgname=({"富","禄","寿","喜","庆","松","冲","千","干","里",
"用","超","宝","正","迁","骏","葵","飞","年","祥","空","盖",
"赦","晋","通","光","鹿","铁","玩","腾","龙","祖","忠",
"雄","儒","逊","德","策","谦","朗","延","钦","褚","综","怀",
"术","禁","尚","横","卫","范"});

string get_surname() {
	return surname[random(sizeof(surname))];
}
int get_gender(int typ) {
	switch(typ) {
	case YOUNGWOMAN:
	case MIDWOMAN:
	case OLDWOMAN:
		return 2;
	default: return 1;
	}
}
int get_age(int typ) {
	switch(typ) {
	case YOUNGWOMAN:
	case YOUNGMAN:
		return 10+random(10);
	case MIDWOMAN:
	case MIDMAN:
		return 20 + random(20);
	default: return 40+random(20);
	}
}
int get_rongmao(int typ) {
	return 10+random(20);
}

string get_given_name(int typ) {
	string *tmp;
	string nam;
	switch(typ) {
		case YOUNGWOMAN:
			tmp=cgname+fmgname;
			nam=tmp[random(sizeof(tmp))];
			switch(random(3)) {
				case 0:  return nam+nam;
				case 1: return "小"+nam;
				default: return nam+"儿";
			}
		case MIDWOMAN:
			tmp=cgname+fmgname;
			nam=tmp[random(sizeof(tmp))];
			return nam;
		case OLDWOMAN:
			tmp=cgname+fmgname;
			nam=tmp[random(sizeof(tmp))];
			switch(random(3)) {
				case 0:  return nam+"婆";
				case 1: return nam+"老太";
				default: return nam;
			}
		case YOUNGMAN:
			tmp=cgname+mgname;
			nam=tmp[random(sizeof(tmp))];
			switch(random(3)) {
				case 1: return "小"+nam;
				default: return nam;
			}
		case MIDMAN:
		case OLDMAN:
			tmp=cgname+mgname;
			nam=tmp[random(sizeof(tmp))];
			return nam;

	}
}
string get_id(int typ) {
	switch(typ) {
		case YOUNGWOMAN: return "girl";
		case YOUNGMAN : return "youngman";
		case MIDWOMAN : return "woman";
		case MIDMAN : return "man";
		case OLDWOMAN : return "oldwoman";
		case OLDMAN : return "oldman";
	}
	return "unknown";
}
string get_desc (int typ) {
	switch(typ) {
		case YOUNGWOMAN: return "小姑娘";
		case YOUNGMAN : return "年青人";
		case MIDWOMAN : return "中年女子";
		case MIDMAN : return "中年男子";
		case OLDWOMAN : return "老妇人";
		case OLDMAN : return "长者";
	}
	return "unknown";
}
string get_dress(int typ) {
	/*switch(typ) {
		case YOUNGWOMAN: return "ladydress";
		case YOUNGMAN : return "buyi";
		case MIDWOMAN : return "biyuzan";
		case MIDMAN : return "changpao";
		case OLDWOMAN : return "xpao";
		case OLDMAN : return "ypiao";
	}
	return "unknown";*///目前只录了布衣，待以后添加。
	return "buyi";
}


int get_salary(int typ) {
	switch(typ) {
		case YOUNGWOMAN: return 40;
		case YOUNGMAN : return 15;
		case MIDWOMAN : return 30;
		case MIDMAN : return 30;
		case OLDWOMAN : return 20;
		case OLDMAN : return 20;
	}
	return 30;
}

