// /adm/daemons/named.c
// 姓名生成器
// create by akuma@mudnow
// 2000/9/26
// ver 1.0


#include <ansi.h>
string *name_xing=({
		"赵","钱","孙","李","周","吴","郑","王","宋","卢","公孙","关","林","呼延",
		"杨","马","牛","吕","亲","花","柴","朱","鲁","武","张","董","徐","索","戴",
		"史","刘","穆","雷","阮","燕","解","黄","单","韩","郝","彭","魏","齐","萧",
		"欧阳","邓","凌","安","郭","蒋","薛","高","鲍","孔","金","项","童","孟",
		"侯","陈","梁","郑","龚","陶","范","包","樊","石","时","段","左","辛","于",
		"余","尉迟","曹","姬","崔","贾","顾","杜","毛","何","费","施","潘","严",
		"喻","方","颜","唐","廉","单","霍","冯","封","上官","司马","左","傅","闻",
		"荆","刑","林","令狐","独孤","闻人","南宫","申","樊","危","阳","孔","岳","邹"
		});
string *pinyin_xing=({
		"zhao","qian","sun","li","zhou","wu","zheng","wang","song","lu","gongsun","guan","lin","huyan",
		"yang","ma","niu","lv","qin","hua","chai","zhu","lu","wu","zhang","dong","xu","suo","dai",
		"shi","liu","mu","lei","ruan","yan","xie","huang","shan","han","hao","peng","wei","qi","xiao",
		"ouyang","deng","ling","an","guo","jiang","xue","gao","bao","kong","jin","xiang","tong","meng",
		"hou","chen","liang","zheng","gong","tao","fan","bao","fan","shi","shi","duan","zuo","xin","yu",
		"yu","yuchi","cao","ji","cui","jia","gu","du","mao","he","fei","shi","pan","yan",
		"yu","fang","yan","tang","lian","shan","huo","feng","feng","shangguan","sima","zuo","fu","wen",
		"jing","xing","lin","linghu","dugu","wenren","nangong","shen","fan","wei","yang","kong","yue","zou"
		});

string *name_ming1=({
		"小",
		"大","二","三","四","五","六","七","八","九","十",
		"阿",
		"团",
		"生",
		"百",
		"铁","金","水","木","火",
		"常","久","有","无","多","少",
		"明","贵","虎","豹","庆","顺","云","飞","坚","翔","超",
		"为",
		"胜","横","平","弘","天","保","群","田",
		"鹏","龙","坤","纶","羽","柯","生","亮","浪","涛","波","峦","杰","剑",
		"英","雄","潜","引","云","日","猛","威","令","云","峰","博","智","志",
		"檀","琼","冕","敬","载","露","歌","快","玄","征","轩","东","彪","秋",
		"劲","捷","永","海","景","航","晓","成","胜","惠","湘","宏","雪",
		"中","司","鼎","钟","柏","盈","慕","宇","云","天","立",
		"飞",
		});
string *pinyin_ming1=({
		"xiao",
		"da","er","san","si","wu","liu","qi","ba","jiu","shi",
		"a",
		"tuan",
		"sheng",
		"bai",
		"tie","jin","shui","mu","huo",
		"chang","jiu","you","wu","duo","shao",
		"ming","gui","hu","bao","qing","shun","yun","fei","jian","xiang","chao",
		"wei",
		"sheng","heng","ping","hong","tian","bao","qun","tian",
		"peng","long","kun","guan","yu","ke","sheng","liang","lang","tao","bo","luan","jie","jian",
		"ying","xiong","qian","yin","yun","ri","meng","wei","ling","yun","feng","bo","zhi","zhi",
		"tan","qiong","mian","jing","zai","lu","ge","kuai","xuan","zheng","xuan","dong","biao","qiu",
		"jin","jie","yong","hai","jing","hang","xiao","cheng","sheng","hui","xiang","hong","xue",
		"zhong","si","ding","zhong","bai","ying","mu","yu","yun","tian","li",
		"fei",
		});

string *name_female_ming1=({
        "莹","雪","琳","晗","涵","琴","晴","瑶","梦","茜","倩","希","夕","梅","月",
        "悦","乐","彤","珍","依","沫","玉","灵",
        "蕊","薇","梦","岚","苑","婕","馨","瑗","韵","融","园","艺","咏",
        "卿","聪","澜","纯","琬","茗","羽",
        "希","宁","欣","飘","滢","柔","竹","晓","欢","霄",
         "伊","亚","宜","可","姬","舒","影","荔","枝","思","丽","芬","芳","燕","莺",
        "媛","艳","珊","莎",
        "蓉","眉","君","琴","悦","昭","冰","枫","芸","菲","寒","锦","玲","秋",
		});

string *pinyin_female_ming1=({
        "ying","xue","lin","han","han","qin","qing","yao","meng","xi","qian","xi","xi","mei","yue",
        "yue","le","tong","zhen","yi","mo","yu","ling",
        "rui","wei","meng","lan","yuan","jie","xin","yuan","yun","rong","yuan","yi","yong",
        "qing","chong","lan","chun","wan","ming","yu",
        "xi","ning","xin","piao","ying","rou","zhu","xiao","huan","xiao",
        "yi","ya","xuan","ke","ji","shu","ying","li","zhi","si","li","fen","fang","yan","ying",
        "yuan","yan","shan","sha",
        "rong","mei","jun","qin","yue","zhao","bing","feng","yun","fei","han","jin","ling","qiu",
		});


string *name_ming2=({
		"二","三","四","五","六","七","八","九",
		"林","莘","绅","思","慕","永","勇","护","痕","浑","凝","宜","仪","亦","翼",
		"郎",
		"儿",
		"万",
		"虎","牛","豹",
		"子",
		"鹏","龙","琨","官","羽","柯","生","亮","浪","涛","波","峦","杰","剑",
		"劲","捷","永","海","景","航","晓","成","圣","辉","湘","宏","雪",
		"富","贵","福",
		"年","月","日",
		"生","天","民","明",
		"卿","龙","康","顺","彩","风","雨","云",
		"康",
		"华","颖",
		"冲","重",
		"梅",
		});

string *name_female_ming2=({
    "秀","娟","英","华","慧","巧","美","娜","静","淑","惠","珠","翠","雅","芝","玉","萍","红","月",
    "彩","春","菊","兰","凤","洁","梅","琳","素","云","莲","真","环","雪","荣","妹","霞","香",
    "瑞","凡","佳","嘉","琼","勤","珍","贞","莉","桂","娣","叶","璧","璐","娅","琦","晶","妍","茜",
    "黛","青","倩","婷","姣","婉","娴","瑾","颖","露","瑶","怡","婵","雁","蓓","纨","仪","荷","丹",
		});

string *pinyin_female_ming2=({
    "xiu","juan","ying","hua","hui","qiao","mei","na","jing","shu","hui","zhu","cui","ya","zhi","yu","ping","hong","yue",
    "cai","chun","ju","lan","feng","jie","mei","lin","su","yun","lian","zhen","huan","xue","rong","mei","xia","xiang",
    "rui","fan","jia","jia","qiong","qin","zhen","zhen","li","gui","di","ye","bi","lu","ya","qi","jing","yan","xi",
    "dai","qing","liang","ting","jiao","wan","xian","jin","yin","lu","yao","yi","chan","yan","bei","wan","yi","he","dan",
    });
string *pinyin_ming2=({
		"er","san","si","wu","liu","qi","ba","jiu",
		"lin","shen","shen","si","mu","yong","yong","hu","hen","hun","ning","yi","yi","yi","yi",
		"lang",
		"er",
		"wan",
		"hu","niu","bao",
		"zi",
		"peng","long","kun","guan","yu","ke","sheng","liang","lang","tao","bo","luan","jie","jian",
		"jing","jie","yong","hai","jing","hang","xiao","cheng","sheng","hui","xiang","hong","xue",
		"fu","gui","fu",
		"nian","yue","ri",
		"sheng","tian","min","ming",
		"qing","long","kang","shun","cai","feng","yu","yun",
		"kang",
		"hua","ying",
		"chong","chong",
		"mei",
		});

string *nick_first=({
		"南海","平原","辽东","川西","平阳","天外","独孤","飘雪","求败","无心","红粉","夕阳",
		"奇门","玄天","日月","毒龙","夜叉","葵花","纯阳","玉女","六合","天罡","天羽","八卦",
		"太乙","落英","鹰蛇","太极","回风","混沌","乾坤","九天","神门","百变","逍遥",
	});

string *nick_second=({
	  "拂穴","降魔","霹雳","阴阳","丧门","真气","修罗","碎石","九九","绵","无痕","两仪",
	  "五神","穿云","破玉","奇","迅雷","伏魔","游身","连环","无形","神","无双",
  });	
string *nick_third=({
	"钉","棒","掌","刀","拳","掌","爪","指","斧","钩","棍","杖","鞭","剑","镖","索","刀",
	"拳","手","功","锤","枪","剑","霸","刀","剑","枪","鞭","索","红","娇","虎","豹",
	"老人","客","侠","龙",
	});
string *all_color = ({HIR,HIY,HIG,HIB,HIM,HIW,HIC});

string create_color_nick()
{
                string nickname;
        nickname = all_color[random(sizeof(all_color))]
                   +nick_first[random(sizeof(nick_first))];
        nickname +=all_color[random(sizeof(all_color))]+
                  nick_second[random(sizeof(nick_second))]+
                  all_color[random(sizeof(all_color))]+
                  nick_third[random(sizeof(nick_third))]+NOR;

        return nickname;  
}

string create_name()
{
	string name,pinyin_name;
	int xing,ming1,ming2,yes1;
	xing=random(sizeof(name_xing));
	ming1=random(sizeof(name_ming1));
	ming2=random(sizeof(name_ming2));
	yes1=random(3);
	
	name = name_xing[xing];
	name+= yes1?name_ming1[ming1]:"";
	name+= name_ming2[ming2];
	
	pinyin_name = pinyin_xing[xing];
	pinyin_name+= " ";
	pinyin_name+= yes1?pinyin_ming1[ming1]:"";
	pinyin_name+= pinyin_ming2[ming2];
	
	return(sprintf("%s@%s",name,pinyin_name));
}

string create_female_name()
{
	string name,pinyin_name;
	int xing,ming1,ming2,yes1;
	xing=random(sizeof(name_xing));
	ming1=random(sizeof(name_female_ming1));
	ming2=random(sizeof(name_female_ming2));
	yes1=random(3);
	
	name = name_xing[xing];
	name+= yes1?name_female_ming1[ming1]:"";
	name+= name_female_ming2[ming2];
	
	pinyin_name = pinyin_xing[xing];
	pinyin_name+= " ";
	pinyin_name+= yes1?pinyin_female_ming1[ming1]:"";
	pinyin_name+= pinyin_female_ming2[ming2];
	
	return(sprintf("%s@%s",name,pinyin_name));
}

string create_nick()
{
	string nick1,nick2;
	nick1=nick_first[random(sizeof(nick_first))];
	nick2=nick_second[random(sizeof(nick_second))];
	return nick1+nick2;
}
