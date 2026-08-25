
private string *wj_area=({"qinchuan", "yunnan", "lingling", "xinye", "luling",
"poyang", "jinyang", "qinghe", "kuaiji", "beihai" });

private mapping pl_leader=([]);
private mapping ct_list=([]);

private mapping cl_caption=([]);

private string *chars;

void test_one() {
	
}

mixed clear_players() {
	string *chs;
	return "don't call this function untill yu know what you are doing\n";
	chs=CHAR_D->check_char("type",TYPE_PLAYER);
	foreach(string c in chs) 
		CHAR_D->remove_char(c);
	return "done\n";
}
string stat_me() {
	string *ks,*as,k,a;
	string ret;
	int i,sum,j,sum2;
	ret="重新启动后势力分布：\n";
	ret+="======================================================\n";
	ret+="玩家国；由下列地区太守担任，目前的分配是：\n";
	i=0;
	foreach(string aaa in wj_area) {
		i++;
		if(i==6) ret+="\n";
		ret+=AREA_D->get_area(aaa,"name")+"："+
			CHAR_D->get_char(AREA_D->get_area(aaa,"leader"),"name")+"  ";
	}
	ret+="\n=================================================\n";
	ks=keys(ct_list);
	sum=sizeof(ks);
	ret+="NPC国：首都为国君所在地。\n";
	for(i=0;i<sum;++i) {
		k=ks[i];
		ret+="国君："+CHAR_D->get_char(k,"name")+"      领地和官员：\n";
		as=keys(ct_list[k]);
		sum2=sizeof(as);
		for(j=0;j<sum2;++j) {
			a=as[j];
			ret+="     "+AREA_D->get_area(a,"name")+"：";
			foreach(string c in ct_list[k][a]) {
				ret+=CHAR_D->get_char(c,"name")+" ";
			}
			ret+="\n";
		}
	}
	return ret;	
}

mixed area_init1() {
	string *as;
	int l;
	string *cl;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"safe",l*10+20);
		AREA_D->set_area(a,"population",l*1000);
		
	}
	cl=COUNTRY_D->list_countries();
	if(sizeof(cl)) {
		foreach(string cc in cl) 
			{string msg;
			 msg = "%^H_GREEN%^【重新启动】"+
			       COUNTRY_D->get_country(cc,"name")+
			       "王朝在统一天下后，经历了短暂的和平，又土崩瓦解了。\n";
			 tell(users(),msg);
			 HIS(msg);
			COUNTRY_D->remove_country(cc);
			}
	
	}
}

mixed area_init2() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"gold",l*100);
		AREA_D->set_area(a,"st",0);
		AREA_D->set_area(a,"food",l*3000);
		
	}
}

mixed area_init3() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"troop",0);
		AREA_D->set_area(a,"troop",(["footman":l*100]));
		AREA_D->set_area(a,"morale",50);
		AREA_D->set_area(a,"train",50);
		
	}
}

mixed area_init4() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"taxlocal",30);
		AREA_D->set_area(a,"taxnation",10);

		AREA_D->set_area(a,"bussiness",50);
		AREA_D->set_area(a,"business",50);
		AREA_D->set_area(a,"industry",50);
		AREA_D->set_area(a,"agriculture",50);
		AREA_D->set_area(a,"importance",0);
		AREA_D->set_area(a,"bl",0);
		AREA_D->set_area(a,"base",0);
		
	}
}
mixed get_player_leader() {
/*	string ld;

	foreach(string a in wj_area) {
		ld=AREA_D->get_area(a,"leader");
		if(!CHAR_D->char_exist(ld)) {
			tell(users(),"%^H_GREEN%^【重新启动】"+AREA_D->get_area(a,"name")+
				"没有太守。重新启动终止。\n");
			error("stop");
			pl_leader[a]=ld;
		}
		tell_user("fire",a+":"+ld+" ");
		
	}
*/


	pl_leader=([
	"qinchuan":"group",
	"yunnan":"rulin",
	 "lingling":"ywl",
	 "xinye":"yangjian",
	"luling":"rickal",
	"poyang":"locker",
	"jinyang":"noise",
	"qinghe":"flag",
	"kuaiji":"chw",
	"beihai":"liuxiong", ]);

}
void init_char1() {
	foreach(string c in chars) {
		CHAR_D->set_char(c,"nc",0);
		CHAR_D->set_char(c,"lc",0);
		CHAR_D->set_char(c,"lo",0);
		CHAR_D->set_char(c,"nation",0);
		CHAR_D->set_char(c,"ranklocal",0);
		CHAR_D->set_char(c,"ranknation",0);
//		CHAR_D->set_char(c,"localcontribution",0);
		CHAR_D->set_char(c,"ps",0);
		CHAR_D->set_char(c,"grant",0); //删除临时太守信息
		CHAR_D->set_char(c,"hon",0);
	}

}
void build_npc_country(string k) {
	string *as,ctp;
	as=keys(ct_list[k]);
	foreach(string a in as) {
		if(member_array(k,ct_list[k][a])!=-1) {
			ctp=a; break;
		}
	}
	CHAR_D->set_char(k,"area",ctp);
	COUNTRY_D->add_country(k,ctp);
	foreach(string a in as) {
		AREA_D->set_area(a,"nation",k);
		foreach(string c in ct_list[k][a]) {
			if(c==k) continue;
			(EV_POSITION)->give_position(c,R_SG,a);
		}
		AREA_D->set_area(a,"population",
			AREA_D->get_area(a,"population")*20);
		AREA_D->set_area(a,"safe",80);
if (!AREA_D->get_area(a,"leader")) //对没有太守的城市
   AREA_D->auto_head(a);           //自动挑选NPC太守

	}

}
void build_npc_country_all() {
	string *ks;
	ks=keys(ct_list);
	foreach(string k in ks){
		call_out("build_npc_country",random(20),k);
	}
}
void find_npc(string a) {
	int t=0;
	string c;
	while(t<2) {
		c=chars[random(sizeof(chars))];
		if(CHAR_D->get_char(c,"is_tmp")) continue;
		if(CHAR_D->get_char(c,"type")==TYPE_PLAYER) continue;
		if(CHAR_D->get_char(c,"ranklocal")) continue;
		(EV_POSITION)->give_position(c,R_SG,a);
		t++;
	}
}
void build_char_country(string k,string a) {
	CHAR_D->set_char(k,"area",a);
	COUNTRY_D->add_country(k,a);
	call_out("find_npc",25,a);
}

void build_char_country_all() {
	foreach(string a in wj_area){
		call_out("build_char_country",random(20),pl_leader[a],a);
	}
}

void build_random_country(string a) {
	string *nbs,nb;
	nbs=AREA_D->get_area(a,"neighbor");
	nb=nbs[0];
	AREA_D->set_area(a,"nation",AREA_D->get_area(nb,"nation"));
	call_out("find_npc",25,a);
}

void build_random_country_all() {
	foreach(string a in wj_area){
		call_out("build_random_country",random(20)+25,a);
	}
}


void restart() {
//	write("现在不要启动啦。\n");
//	return;
	tell(users(),"%^H_GREEN%^【重新启动】三国开始重新启动。\n");
	area_init1();
	tell(users(),"%^H_GREEN%^【重新启动】地区人口，安定初始化完毕。\n");
	area_init2();
	tell(users(),"%^H_GREEN%^【重新启动】地区黄金，粮草初始化完毕。\n");
	area_init3();
	tell(users(),"%^H_GREEN%^【重新启动】地区部队，士气，训练初始化完毕。\n");
	area_init4();
	tell(users(),"%^H_GREEN%^【重新启动】地区工，农，商，税，重点，基地，黑名单初始化完毕。\n");


//	no player countries this time
//	get_player_leader();
//	tell(users(),"%^H_GREEN%^【重新启动】玩家国王选择完毕。\n");


	chars=CHAR_D->list_chars();
	init_char1();
	tell(users(),"%^H_GREEN%^【重新启动】角色地区贡献，国家贡献，忠诚，职务清除完毕。\n");

//	build_char_country_all();  // no player countries

	build_npc_country_all();
	build_random_country_all();
	DAY_D->add_generation();
}
mixed char_test() {
	string *ks,*as,*bs;
	string *chars;
	chars=({});
	ks=keys(ct_list);
	foreach(string a in ks) {
		as=keys(ct_list[a]);
		foreach(string aa in as) {
			bs=ct_list[a][aa];
			foreach(string aaa in bs) {
				if(member_array(aaa,chars)!=-1)
					return "char " + aaa + " used already\n";
				if(!CHAR_D->char_exist(aaa)) return "char "+aaa+" not exist\n";
				chars+=({aaa});
			}
		}
	}
	return sizeof(chars);

}
mixed area_test() {
	string *a_area=({});
	string *ks,*ars;
	foreach(string a in wj_area) {
		if(member_array(a,a_area)!=-1)
			return "area " + a + " used already\n";
		if(!AREA_D->area_exist(a)) return "area "+a+" not exist\n";
		a_area+=({a});
	}
	ks=keys(ct_list);
	foreach(string k in ks) {
		ars=keys(ct_list[k]);
		foreach ( string a in ars) {
			if(member_array( a , a_area)!=-1)
				return "area "+a+" used already\n";
			if(!AREA_D->area_exist(a)) return "area "+a+" not exist\n";
			a_area+=({a});
		}
	}
	ars=AREA_D->list_areas()-a_area;
	if(sizeof(ars))
		return ars[0]+" not assign to any place\n";
	return 1;
	
}

void create() {

ct_list["ma teng"]=([ "xiliang" : ({"ma teng", "ma chao", "pang de", "ma tie" }),
		"didao" : ({ "ma dai", "ma xiu"})
	    ]);
ct_list["han sui"]=([ "longxi" : ({"han sui", "zhang heng", "yang qiu" }),
		"tianshui" : ({ "liang xing", "cheng yi" }),
		"jieting" : ({ "cheng yin" }),
		"qishan" : ({ "ma wan"}),
	    ]);
ct_list["dong zhuo"]=([ "changan" : ({"dong zhuo","li su", "li ru", "dong cheng", 
				"zhang liao"}),
		"anding" : ({"zhu juan"}),
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
		"taiyuan" : ({"he jin", "pan feng", "han fu" }),
		"shangdang" : ({ "xin pi" }),
		"yanmenguan" : ({"xin ping"}),
	]);
ct_list["zhang lu"]=([
		"hanzhong" : ({"zhang lu", "yan pu", "yang song"}),
		"xiabian" : ({ "zhang wei"}),
		"yangpingguan" : ({ "zhang yin"}),
	]);
ct_list["liu zhang"]=([
	"chengdu" : ({"liu zhang", "zhang song" , "deng xian", "li hui", "xu jing" }),
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
	"xiangyang" : ({"liu biao", "liu cong", "kuai liang", "zhang yun", "huo jun" }),
	"shangyong" : ({ "cao mao", "kuai yue" }),
	"chanxi" : ({ "wen pin", "fu yi" }),
	"changbanpo" : ({ "gan ning", "su fei"}),
	"jiangxia" : ({ "liu qi", "huang zu"}),
	]);
ct_list["liu bei"]=([
	"jiangling" : ({"liu bei", "zhuge liang", "wei yan", "liu feng", "yi ji"}),
	"yiling" : ({"zhang fei", "zhang bao"}),
	"gongan" : ({ "huang zhong", "yin mo"}),
	"huarong" : ({"guan yu", "xu shu", "wang fu"}),
	"wuling" : ({"zhao yun", "ma liang", "jian yong"}),
	]);
ct_list["liu du"]=([
	"changsha" : ({"liu du", "xing daorong", "liu xian"}),
	"guiyang" : ({"pan rui"}),
	"guilin" : ({"gong zhi"}),
	"nanhai" : ({ "bao long"}),
	"chibi" : ({ "zhao fan"}),
	]);
ct_list["yuan shu"]=([
	"wan" : ({"yuan shu", "ji ling", "lei bo"}),
	"runan" : ({"yuan yin",}),
	"bowangpo" : ({"lv fan"}),
	]);
ct_list["sun jian"]=([
	"chaisang" : ({"sun jian", "zhou yu", "zhu zhi", "zhang zhao", "lu ji"}),
	"yuzhang" : ({"sun quan", "huang gai"}),
	"xisaishan" : ({ "lv meng", "han dang"}),
	"danyang" : ({"sun jing", "sun yu"}),
	"lujiang" : ({"sun ce", "li yi"}),
	"ruxukou": ({"lu xun", "ling cao"}),
	]);
ct_list["liu you"]=([
	"shouchun" : ({"liu you", "chen heng", "chen wu"}),
	"hefei": ({"yan xing"}),
	"huaiyin" : ({"ze rong"}),
	"jianye" : ({"taishi ci"}),
	"wujun" : ({"zhang ying"}),
	]);
ct_list["cao cao"]=([
	"xuchang" : ({"cao cao", "guo jia", "xun you", "xun yu", "dian wei", 
		"cao ren", "xiahou en", "man chong" }),
	"qiao" : ({ "yu jin", "liu ye" }),
	"dingtao" : ({"cao ang", "che zhou"}),
	"puyang" : ({"xu huang", "chen jiao"}),
	"baima" : ({"cao hong", "cao chun"}),
	"ye": ({"xiahou chun", "cheng yu"}),
	"chenliu" : ({"xiahou yuan", "chen qun"}),
	"guandu" : ({"li dian", "le jin"}),
	]);
ct_list["yuan shao"]=([
	"nanpi" : ({"yuan shao", "yan liang", "wen chou", "zhang he", "chunyu qiong", "ju shou"}),
	"daixian" : ({ "guo tu"}),
	"jicheng" : ({"yuan tan", "tian feng"}),
	"yijing" : ({"chen zhen"}),
	"jieqiao" : ({ "gao lan"}),
	"pingyuan" : ({"yuan shang", "feng ji"}),
	"jinan" : ({"yuan xu", "chen lin"}),
	"bohai" : ({"shen pei"}),
	]);
ct_list["tao qian"]=([
	"xuzhou" : ({"tao qian", "chen gui", "chen deng", "sun gan"}),
	"xiaopei" : ({"zang ba"}),
	"xiapi" : ({"cao bao"}),
	"guangling" : ({"mi fang"}),
	"langya" : ({"mi zhu"}),
	]);

ct_list["gongsun zan"]=([
	"beiping" : ({"gongsun zan", "gongsun gong", "yan gang"}),
	"bailangshan" : ({"gongsun yue"}),
	"xiangping" : ({"gongsun du"}),
	]);
}
