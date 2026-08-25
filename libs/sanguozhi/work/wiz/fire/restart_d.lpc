private string *wj_area=({"qinchuan", "yunnan", "lingling", "xinye", "luling",
"poyang", "jinyang", "qinghe", "kuaiji", "beihai" });

private mapping ct_list=([]);

void create() {
ct_list["ma teng"]=([ "xiliang" : ({ "ma chao", "pang de", "ma tie" }),
		"didao" : ({ "ma dai", "ma xiu"})
	    ]);
ct_list["han sui"]=([ "longxi" : ({ "zhang heng", "yang qiu" }),
		"tianshui" : ({ "liang xing", "cheng yi" }),
		"jieting" : ({ "cheng yin" }),
		"qishan" : ({ "ma wan"}),
	    ]);
ct_list["dong zhuo"]=([ "changan" : ({"li su", "li ru", "dong cheng", 
				"zhang liao","zhu juan"}),
		"chencang" : ({ "song xian", }),
		"xianyang" : ({ "lv bu", "chen gong" }),
		"jingyang" : ({ "wei xu" }),
		"huayin" : ({ "guo si" }),
		"tongguan" : ({ "hou cheng"}),
		"wuzhangyuan" :({"gao shun" }),
		"wuguan" : ({ "fan chou"}),
		"hangu" : ({"zhang ji",}),
		"hongnong" : ({ "hua xiong", "wang yun"}),
		"mianchi" : ({"zhong you"}),
		"luoyang" : ({"lu zhi", "huangfu song", "yang biao"}),
		"huguan" : ({"zhang xiu"}),
		"hulaoguan" : ({"xu rong"}),
	]);
ct_list["he jin"]=([
		"taiyuan" : ({ "pan feng", "han fu" }),
		"shangdang" : ({ "xin pi" }),
		"yanmenguan" : ({"xin ping"}),
	]);
ct_list["zhang lu"]=([
		"hanzhong" : ({ "yan pu", "zhang song"}),
		"xiabian" : ({ "zhang wei"}),
		"yangpingguan" : ({ "zhang yin"}),
	]);
ct_list["liu zhang"]=([
	"chengdu" : ({ "zhang song" , "deng xian", "li hui", "xu jing" }),
	"dingjunshan" : ({ "zhang ren",}),
	"jiange" : ({"lei tong"}),
	"zitong": ({"wu lan", "zou jing"}),
	"fucheng" : ({ "huang quan"}),
	"mianzhuguan" : ({ "fei shi"}),
	"jianning" : ({ "wu yi", "dong he"}),
	"jiangzhou": ({"yang huai",}),
	"yongan" : ({"yan yan", "liu ba"}),
	]);
ct_list["liu biao"]=([
	"xiangyang" : ({ "liu zong", "kuai liang", "zhang yun", "huo jun" }),
	"shangyong" : ({ "cao mao", "kuai yue" }),
	"chanxi" : ({ "wen pin", "fu yi" }),
	"changbanpo" : ({ "gan ning", "su fei"}),
	"jiangxia" : ({ "liu qi", "huang zu"}),
	]);
ct_list["liu bei"]=([
	"jiangling" : ({ "zhuge liang", "wei yan", "liu feng", "yi ji"}),
	"yiling" : ({"zhang fei", "zhang bao"}),
	"gongan" : ({ "huang zhong", "yin mo"}),
	"huarong" : ({"guan yu", "xu shu", "wang fu"}),
	"wuling" : ({"zhao yun", "ma liang", "jian yong"}),
	]);
ct_list["liu du"]=([
	"changsha" : ({"xing daorong", "liu xian"}),
	"guiyang" : ({"pan rui"}),
	"guilin" : ({"gong zhi"}),
	"nanhai" : ({ "bao long"}),
	"chibi" : ({ "zhao fan"}),
	]);
ct_list["yuan shu"]=([
	"wan" : ({"ji ling", "lei bo"}),
	"runan" : ({"yuan yin",}),
	"bowangpo" : ({"lv fan"}),
	]);
ct_list["sun jian"]=([
	"chaisang" : ({ "zhou yu", "zhu zhi", "zhang zhao", "lu ji"}),
	"yuzhang" : ({"sun quan", "huang gai"}),
	"xisaishan" : ({ "lv meng", "han dang"}),
	"danyang" : ({"sun jing", "sun yu"}),
	"lujiang" : ({"sun ce", "li yi"}),
	"ruxukou": ({"lu xun", "ling cao"}),
	]);
ct_list["liu you"]=([
	"shouchun" : ({"chen heng", "chen wu"}),
	"hefei": ({"yan xing"}),
	"huaiyin" : ({"ze rong"}),
	"jianye" : ({"taishi ci"}),
	"wujun" : ({"zhang ying"}),
	]);
ct_list["cao cao"]=([
	"xuchang" : ({"guo jia", "xun you", "xun yu", "dian wei", 
		"cao ren", "xiahou en", "man chong" }),
	"qiao" : ({ "yu jin", "liu ye" }),
	"dingtao" : ({"cao ang", "che zhou"}),
	"puyang" : ({"xu huang", "chan jiao"}),
	"baima" : ({"cao hong", "cao chun"}),
	"ye": ({"xiahou chun", "cheng yu"}),
	"chenliu" : ({"xiahou yuan", "chen qun"}),
	"guandu" : ({"li dian", "yue jin"}),
	]);
ct_list["yuan shao"]=([
	"nanpi" : ({"yan liang", "wen chou", "zheng he", "chunyu qiong", "ju shou"}),
	"daixian" : ({ "guo tu"}),
	"jicheng" : ({"yuan tan", "tian feng"}),
	"yijing" : ({"chen zhen"}),
	"jieqiao" : ({ "gao lan"}),
	"pingyuan" : ({"yuan shang", "feng ji"}),
	"jinan" : ({"yuan xu", "chen lin"}),
	"bohai" : ({"shen pei"}),
	]);
ct_list["tao qian"]=([
	"xuzhou" : ({"chen gui", "chen deng", "sun gan"}),
	"xiaopei" : ({"zang ba"}),
	"xiapi" : ({"cao bao"}),
	"guangling" : ({"mi fang"}),
	"langya" : ({"mi zhu"}),
	]);

ct_list["gongsun zan"]=([
	"beiping" : ({"gongsun gong", "yan gang"}),
	"bailangshan" : ({"gongsun yue"}),
	"xiangping" : ({"gongsun du}),
	]);
}

void test_one() {
}

mixed area_test() {
	string *a_area=({});
	string *ks,*ars;
	foreach(string a in wj_area) {
		if(member_array(a,a_area)!=-1)
			return "area " + a + " used already\n";
		if(!AREA_D->area_exist(a)) return "area "+a+" not exist\n";
		a_area+=a;
	}
	ks=keys(ct_list);
	foreach(string k in ks) {
		ars=keys(ct_list[k]);
		foreach ( string a in ars) {
			if(member_array( a , a_area)!=-1)
				return "area "+a+" used already\n";
			if(!AREA_D->area_exist(a)) return "area "+a+" not exist\n";
			a_area+=a;
		}
	}
	return sizeof(a_area);;
	
	
}
