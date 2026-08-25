// color_map
#include <ansi.h>
nosave private string *asam=({"●","◆","▲","■","★"}) ;
nosave private mixed * colors=
({ 
	RED,GRN,BLU,MAG,ORG,CYN, WHT,
  BRED+GRN,BRED+BLU,BRED+MAG,BRED+ORG,BRED+CYN, BRED+WHT,
BGRN+RED,BGRN+BLU,BGRN+MAG,BGRN+ORG,BGRN+CYN, BGRN+WHT,
  	BBLU+RED,BBLU+GRN,BBLU+MAG,BBLU+ORG,BBLU+CYN, BBLU+WHT,
	BWHT+RED,BWHT+GRN,BWHT+BLU,BWHT+MAG,BWHT+ORG,BWHT+CYN, 
	BYEL+RED,BYEL+GRN,BYEL+BLU,BYEL+MAG,BYEL+ORG,BYEL+CYN, 
	BMAG+RED,BMAG+GRN,BMAG+BLU,BMAG+MAG,BMAG+ORG,BMAG+CYN, 


 });
nosave private mapping mappos =([
 "/sgdomain/txt/maps/northwest.map":
({"taiyuan","yanmenguan","xiliang","shangdang","didao","anding","jieting","longxi","tianshui",
 "qinchuan","chencang","xianyang","jingyang","hongnong","mianchi","luoyang",
  "changan","huayin","tongguan","hangu",
	}),
 "/sgdomain/txt/maps/southwest.map":
({
"qishan","wuzhangyuan","wuguan","xiabian","wan","hanzhong","bowangpo",
"dingjunshan","yangpingguan","jiange","shangyong","xinye","chanxi",
"xiangyang","changbanpo","fucheng","zitong","mianzhuguan","yongan","yiling",
"chengdu","jiangling","jianning","jiangzhou",
"yunnan","wuling","gongan","huarong","lingling"
}),
"/sgdomain/txt/maps/northeast.map":
({"daixian", "jicheng", "yijing", "beiping", "bailangshan", "xiangping",
"nanpi","jinyang", "qinghe", "pingyuan", "jinan", "bohai", "huguan",
"jieqiao","ye", "baima", "beihai", "guandu", "puyang","chenliu", "dingtao",
"langya", "hulaoguan", "xuchang", "qiao", "xuzhou", "xiaopei", "xiapi",
"guangling"}),
"/sgdomain/txt/maps/southeast.map":
({"runan", "shouchun", "hefei", "huaiyin", "lujiang", "ruxukou", "jianye",
"jiangxia", "wujun", "qiantang","chibi", "xisaishan", "danyang", "poyang", "kuaiji",
"changsha", "chaisang", "guiyang", "yuzhang", "guilin", "nanhai", "luling"}),
"/sgdomain/txt/maps/main.map":
({
"daixian", "jicheng", "yijing", "beiping", "bailangshan", "xiangping",
"xiliang", "nanpi",
"didao", "jieting", "anding", "taiyuan", "yanmenguan", "jingyang",
"qinghe", "pingyuan",
"jinan", "bohai", "longxi", "tianshui", "qinchuan", "shangdang", "ye",
"jieqiao", "baima",
"beihai", "chencang", "xianyang", "jingyang", "huguan", "guandu",
"chenliu", "dingtao",
"puyang", "changan", "huayin", "tongguan", "hangu", "hongnong", "mianchi",
"luoyang", "langya",
"qishan", "wuzhangyuan", "wuguan", "hulaoguan", "xuchang", "qiao",
"xuzhou", "xiaopei",
"xiapi", "guangling", "xiabian", "hanzhong", "wan", "runan",
"dingjunshan", "yangpingguan",
"bowangpo", "shouchun", "jiange", "shangyong", "xinye", "hefei",
"huaiyin", "fucheng", "zitong",
"chanxi", "xiangyang", "changbanpo", "mianzhuguan", "lujiang", "ruxukou",
"jianye", "chengdu",
"yongan", "yiling", "jiangxia", "danyang", "jiangzhou", "jiangling",
"chibi", "xisaishan",
"wujun", "qiantang","jianning", "wuling", "gongan", "huarong", "changsha",
"chaisang", "poyang", "yunnan",
"lingling", "guiyang", "yuzhang", "kuaiji", "guilin", "nanhai",
"luling"
}), ]); 

mapping get_colormap() {
	mapping ret=([]);
	mapping dis=([]);
	string *nids;
	int num,*inx;
	int i,sum;
	string mdis="";
	nids=COUNTRY_D->list_countries();
	if(!sizeof(nids)) return ret;
	foreach(string nid in nids) {
		num=COUNTRY_D->get_country(nid,"population");
		while(dis[num]) {
			num++;
		}
		dis[num]=nid;
	}
	inx=keys(dis);
	inx=sort_array(inx,-1);
	sum=sizeof(inx);
	for(i=0;i<sum;++i) {
		ret[dis[inx[i]]]=i;
		mdis+=colors[i]+COUNTRY_D->get_country(dis[inx[i]],"name")+
			NOR+" ";
	}
	mdis+="\n";
	write(mdis);
	ret += (["han mo":20,]);
	return ret;

}

string add_color(string inp,string map) {
	mapping color_map;
	string *sep;
	string ret="";
	int i,sum;

	if(!mappos[map]) return inp;
	sum=sizeof(mappos[map]);
	sep=explode(inp,"CT");
	if(sizeof(sep)!=(sum+1)) return "this map got bugs\n";

	color_map=get_colormap();
	//tell_user("huaer",sprintf("color_map = %O\n",color_map));

	ret=sep[0];
	for(i=0;i<sum;++i){
		if(stringp(AREA_D->get_area(mappos[map][i],"nation")))
		{
			ret+=colors[color_map[AREA_D->get_area(mappos[map][i],"nation")]]+
				asam[AREA_D->get_area(mappos[map][i],"level")-1]+NOR;
			ret+=sep[i+1];
		}
		else
		{
			//tell_user("huaer",sprintf("city = %O\n",mappos[map][i]));
			//tell_user("huaer",sprintf("level = %O\n",AREA_D->get_area(mappos[map][i],"level")));
			ret+=colors[color_map["han mo"]]+
				asam[AREA_D->get_area(mappos[map][i],"level")-1]+NOR;
			ret+=sep[i+1];
		}
	}
	return ret+"\n";
}
