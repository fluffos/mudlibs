// named.c
// By snowman@SJ 10/06/2000

string* f_name = ({
"°®", "°²", "°¬", "°½",
"°Ø", "°à", "±«", "±´", "±å", "²·", "°×", "°Í", "°ü", "±¦",
"²Ü", "á¯", "²ý", "³£", "³Â", "³É", "²Ì", "´Þ", "³Ù", "³Ì",
"´÷", "µË", "µÒ", "µÚ", "¶­", "ñ¼", "¶Å", "¶¡",
"·®", "·¶", "·½", "·Ñ", "·ë", "·ï", "·ü", "¸£", "¸¶", "·ç", "·â",
"¸ð", "¹Ë", "¹Ø", "¹Ü", "¹ù", "¸ß", "¹ý", "¸Ê", "¹¬",
"¹þ", "º«", "ºÂ", "ºÎ", "ºØ", "ºò", "ºú", "»¨", "»ª", "»ª", "»Æ", "»ô", "ºé",
"¼Æ", "¼Í", "½ª", "½¯", "½ð", "¼Ö", "½¹", "½­",
"¿µ", "¿º", "¿Â", "¿×", "Øá", "Ú÷",
"ÀÉ", "À×", "Àî", "Áõ", "Áº", "ÁÖ", "Áè", "Áø", "Â¬", "Â³", "ÂÀ", "ÂÞ", "Â½", "Àä", "Àè", "Áú", "ÁÎ",
"Âí", "Ã©", "Ã«", "Ã×", "Ãç", "Ã÷", "Ä«", "Ä²", "ÄÂ",
"Äß", "Äê", "ÄÏ", "Äô",
"ÅË", "ÅÓ", "Åí", "Æ¤", "Æ½",
"ÆÝ", "Æë", "Æî", "Ç®", "ÚÛ", "ÇØ", "ÇÙ", "³ð", "Çü", "Çú", "ôÃ", "Çñ",
"ÈÎ", "Èî", "Èð", "ÈÝ",
"ÉÌ", "ÉÛ", "ÙÜ", "Éò", "Ê©", "Ê¯", "Ê±", "Ê·", "Êæ", "Ë§", "Ë®", "ËÎ", "ËÕ", "Ëï", "É£", "µ¥", "É³",
"Ì¸", "ÌÀ", "ÌÆ", "ÌÕ", "ÌÙ", "Ù¡", "Ìï", "Ì·", "Í¯",
"Íò", "Íô", "Íõ", "Î¤", "Îº", "ÎÀ", "Îâ", "Îä", "Îé", "Úù", "ÎÅ", "ÎÂ",
"ÞÉ", "Ïî", "Ð¤", "Ð»", "ÐÜ", "Ðì", "Ðí", "Ñ¦", "Ïô", "ÏÄ", "Ðì",
"ÑÏ", "ÑÔ", "Ñî", "Ñô", "Ò¦", "Òæ", "Òó", "Òü", "Ó¢", "Ó¯", "ÓÈ", "Óá", "ÓÝ", "Óà", "Óí", "Ó÷", "Ôª", "Ô¬", "ÔÀ", "ÀÖ", "ÔÆ", "Ò¶",
"²Ø", "Õ¿", "ÕÂ", "ÕÅ", "ÕÔ", "Ö£", "Ö§", "ÖÓ", "ÖÜ", "Öì", "×£", "×Ú", "×Þ", "ñÒ", "×æ",

"°ÙÀï", "°ÛÉÍ",
"³þ½ú", "´¾ÓÚ", "µ¥ÓÚ",
"¶«·½", "¶«¹ù", "¶«ÃÅ", "¶ËÄ¾", "¶ÎÇ§",
"¹«Á¼", "¹«Ëï", "¹«Î÷", "¹«Ñò", "¹«Ò±", "¹ÈÁº",
"ºÕÁ¬", "ºôÑÓ", "»Ê¸¦",
"¼Ð¹È",
"ÁºÇð", "Áîºü",
"Ä½ÈÝ",
"ÄÏ¹¬", "ÄÏ¹ù",
"Å·Ñô",
"ÉÏ¹Ù", "ÉêÍÀ", "Ê¦¿Õ", "Ë¾Âí", "Ë¾Í½",
"Ì«Êå", "å£Ì¨",
"Î¢Éú", "ÎÅÈË", "Î×Âí",
"Î÷ÃÅ", "ÏÄºò", "æøæá", "ÐùÔ¯",
"ÑÖ·¨", "ÑòÉà", "Î¾³Ù", "ÓîÎÄ", "ÀÖÕý",
"Ô×¸¸", "³¤Ëï", "ÖÓÀë", "ÖÙËï", "Öî¸ð", "ò§¿×", "×ÚÕþ", "×óÇð",
});

string* f_id = ({
"ai", "an", "ai", "ao",
"bo", "ban", "bao", "bei", "bian", "bo", "bai", "ba", "bao", "bao",
"cao", "cen", "chang", "chang", "chen", "cheng", "cai", "cui", "chi", "cheng",
"dai", "deng", "di", "di", "dong", "dou", "du", "ding",
"fan", "fan", "fang", "fei", "feng", "feng", "fu", "fu", "fu", "feng", "feng",
"ge", "gu", "guan", "guan", "guo", "gao", "guo", "gan", "gong",
"ha", "han", "hao", "he", "he", "hou","hu", "hua", "hua", "hua", "huang", "huo", "hong",
"ji", "ji", "jiang", "jiang", "jin", "jia", "jiao", "jiang",
"kang", "kang", "ke", "kong", "kuai", "kuang",
"lang", "lei", "li", "liu", "liang", "lin", "ling", "liu", "lu", "lu", "lv", "luo", "lu", "leng", "li", "long", "liao",
"ma", "mao", "mao", "mi", "miao", "ming", "mo", "mou", "mu",
"ni", "nian", "nan", "nie",
"pan", "pang", "peng", "pi", "ping",
"qi", "qi", "qi", "qian", "qiao", "qin", "qin", "qiu", "qu", "qu", "qiu", "qiu",
"ren", "ruan", "rui", "rong",
"shang", "shao", "she", "shen", "shi", "shi", "shi", "shi", "shu", "shuai", "shui", "song", "su", "sun", "sang", "shan", "sha",
"tan", "tang", "tang", "tao", "teng", "tong", "tian", "tan", "tong",
"wan", "wang", "wang", "wei", "wei", "wei", "wu", "wu", "wu", "wu", "wen", "wen",
"xi", "xiang", "xiao", "xie", "xiong", "xu", "xu", "xue", "xiao", "xia", "xu",
"yan", "yan", "yang", "yang", "yao", "yi", "yin", "yin", "ying", "ying", "you", "yu", "yu", "yu", "yu", "yu", "yuan", "yuan", "yue", "yue", "yun", "ye",
"zang", "zhan", "zhang", "zhang", "zhao", "zheng", "zhi", "zhong", "zhou", "zhu", "zhu", "zong", "zhou", "zhu", "zu",

"baili", "baishang",
"chujin", "chunyu", "chanyu",
"dongfang", "dongguo", "dongmen", "duanmu", "duanqian",
"gongliang", "gongsun", "gongxi", "gongyang", "gongye", "guliang",
"helian", "huyan", "huangpu",
"jiagu",
"liangqiu", "linghu",
"murong",
"nangong", "nanguo",
"ouyang",
"shangguan", "shentu", "shikong", "sima", "situ",
"taishu", "tantai",
"weisheng", "wenren", "wuma",
"ximen", "xiahou", "xiangsi", "xuanyuan",
"yanfa", "yangshe", "yuchi", "yuwen", "yuezheng",
"zaifu", "zhangsun", "zhongli", "zhongsun", "zhuge", "zhuankong", "zongzheng", "zuoqiu",
});

string* name_m = ({
"°²", "°¬", "°½", "°¿", "°Á",
"°Ô", "°×", "°à", "±Ì", "±ó", "±ö", "²¨", "²¼", "²¿", "±í", "±¾", "±ê",
"²Å", "²Æ", "²ý", "³¤", "³¬", "³Ï", "³É", "´¨", "²ß",
"´ó", "´ï", "¶¦", "¶¨", "¶°", "¶·", "¶à", "µÂ", "¶¼", "¶È", "µ±", "´ú", "¶«", "¶¬", "¶Ï", "¶É", "µÇ", "µÐ", "¶Ë",
"·¢", "·¨", "·É", "·æ", "·ç", "·ò", "¸£", "¸£", "¸»", "¸´", "·â", "·á", "·²", "·î",
"¸Ö", "î¸", "¸ß", "¹«", "¹á", "¹â", "¹ú", "¹ý", "¹¦", "¸Õ", "¸ù", "¸ç", "¹é", "¹ð", "¹§",
"º£", "ºÆ", "ºÕ", "ºê", "»¢", "»ª", "»Ô", "ºÍ", "º×", "ºó", "ºñ", "ºÏ", "ºº", "»¯", "ºÓ", "ºò", "»¶", "ºé", "»Ò", "º¥",
"¼Ã", "êª", "¼á", "¼Æ", "½¡", "½£", "½­", "½Ü", "½ð", "½ð", "½ø", "¾¸", "¾þ", "¿¡", "½¨", "¾ü", "¾Å", "¾Ù", "¾ù", "¼ª", "¼Î", "¼×", "¼Ñ", "¼Ã",
"¿µ", "¿É", "¿Ë", "¿ï", "¿ª", "¿Õ", "¿í", "À¥", "À«", "¿­", "À¤", "¿ý", "¿ü", "åÓ",
"ÀÅ", "Àñ", "Á¼", "Á¼", "÷ë", "Áî", "Áú", "Â¡", "Â»", "Á¢", "Á¦", "Á÷", "ÁÐ", "ÂÉ", "Àë", "ÁÒ", "À×", "ÁÁ", "Â×", "ÀÊ", "Á®",
"Âú", "Ãñ", "Ã÷", "Ãù", "ÃÍ", "ÃÉ", "ÃÏ", "Ä¾", "Ä±", "Ã¯", "Âó", "ÄÁ", "Ãð", "Âõ",
"Äþ", "ÄÏ", "éª", "Äê", "ÄÜ", "Å©", "ÄÑ", "Äî", "ÄÉ", "Äæ",
"Å·",
"Åà", "Åæ", "ÆÕ", "Æ½", "Åó", "Åô", "ÆÆ", "ÆÇ", "Åà", "Æ®", "±Ù", "è±",
"Ææ", "Æô", "Ç¿", "Çì", "Ç°", "Æð", "Èº", "È¨", "ÇÚ", "Ç¬", "Èª", "Çå", "Çà", "Çï", "Ç±", "Ç«", "Æú", "Çí", "Æé",
"ÈÊ", "ÈË", "ÈÙ", "Èô", "Èð", "Èñ", "î£", "È»", "Èó", "Èç", "÷×", "áÉ",
"É½", "Ê¢", "Ê¤", "Ê±", "ÊÀ", "ÊÙ", "Êå", "Ë³", "ËÄ", "Ë¼", "ËÉ", "É­", "Éî", "Ëì", "Ëæ", "Ë¹", "ÊÀ", "Ê½", "Ê¿",
"Ì©", "ÌÎ", "Ìí", "Ìú", "Í¨", "Í¬", "Ìì", "Í¼", "ÌÃ", "ÌÚ", "ÌÎ", "ÍØ", "ìâ", "Í³", "Í¤", "Í¥", "Í¢", "Ì¹", "Í­", "Í©", "èº", "Ì¶", "ÌÏ", "ÌÄ",
"Íò", "Îª", "Î°", "ÎÄ", "Îä", "Î¬", "Íþ", "ÎÅ", "ÎÌ", "Î¾", "Îä", "Î¨", "ì¿", "Îñ", "ÎÂ", "Î¢", "Î´",
"Îõ", "ôË", "ÏÜ", "Ïé", "Ïé", "Ïþ", "ÐÂ", "Ð¢", "ÐÛ", "ÐÛ", "Ðñ", "ÙÒ", "Î÷", "ÐÅ", "ÐÀ", "Ý·", "ÐÐ",
"Ñî", "ÒÚ", "Òã", "Òå", "Òæ", "ÓÀ", "ÓÂ", "ÓÑ", "Óî", "Óð", "è¤", "ÔÀ", "ÒÇ", "Òâ", "Òä", "Òì", "Ò×", "Óê", "Ô£", "Ô¥", "Óñ", "Òú",
"Õñ", "á¿", "Ö®", "Ö¾", "ÖÇ", "ÖÒ", "ÖÛ", "Öæ", "×Ó", "×Ô", "ÖÙ", "×÷", "Ôì", "×Ú", "ÔÞ", "ÖÇ", "Ö¾", "ÖÎ",
// ¸ãÐ¦ÏµÁÐ
"³¯Î°",
"µÂ»ª",
"¸»³Ç",
"ÃÏ´ï",
"Èó·¢",
"ÍØÔÕ",
"ÎÀ½¡",
"Ð¡´º",
"ÐÇ³Û",
"Ñ§ÓÑ",
});

string* id_m = ({
"an", "ai", "ao", "ao", "ao",
"ba", "bai", "ban", "bi", "bin", "bin", "bo", "bu", "bu", "biao", "ben", "biao",
"cai", "cai", "chang", "chang", "chao", "cheng", "cheng", "chuan", "ce",
"da", "da", "ding", "ding", "dong", "dou", "duo", "de", "du", "du", "dang", "dai", "dong", "dong", "duan", "du", "deng", "di", "duan",
"fa", "fa", "fei", "feng", "feng", "fu", "fu", "fu", "fu", "fu", "feng", "feng", "fan", "feng",
"gang", "gang", "gao", "gong", "guan", "guang", "guo", "guo", "gong", "gang", "gen", "ge", "gui", "gui", "gong",
"hai", "hao", "he", "hong", "hu", "hua", "hui", "he", "he", "hou", "hou", "he", "han", "hua", "he", "hou", "huan", "hong", "hui", "hai",
"ji", "ji", "jian", "ji", "jian", "jian", "jiang", "jie", "jin", "jin", "jin", "jing", "jun", "jun", "jian", "jun", "jiu", "ju", "jun", "ji", "jia", "jia", "jia", "ji",
"kang", "ke", "ke", "kuang", "kai", "kong", "kuan", "kun", "kuo", "kai", "kun", "kui", "kui", "kui",
"lang", "li", "liang", "liang", "lin", "ling", "long", "long", "lu", "li", "li", "liu", "lie", "lv", "li", "lie", "lei", "liang", "lun", "lang", "lian",
"man", "min", "ming", "ming", "meng", "meng", "meng", "mu", "mou", "mao", "mai", "mu", "mie", "mai",
"ning", "nan", "nan", "nian", "neng", "nong", "nan", "nian", "na", "ni",
"ou",
"pei", "pei", "pu", "ping", "peng", "peng", "po", "po", "pei", "piao", "pi", "pu",
"qi", "qi", "qiang", "qing", "qian", "qi", "qun", "quan", "qin", "qian", "quan", "qing", "qing", "qiu", "qian", "qian", "qi", "qiong", "qi",
"ren", "ren", "rong", "ruo", "rui", "rui", "rui", "ran", "run", "ru", "ran", "rong",
"shan", "sheng", "sheng", "shi", "shi", "shou", "shu", "shun", "si", "si", "song", "sen", "shen", "sui", "sui", "si", "shi", "shi", "shi",
"tai", "tao", "tian", "tie", "tong", "tong", "tian", "tu", "tang", "teng", "tao", "tuo", "tao", "tong", "ting", "ting", "ting", "tan", "tong", "tong", "tao", "tan", "tao", "tang",
"wan", "wei", "wei", "wen", "wu", "wei", "wei", "wen", "weng", "wei", "wu", "wei", "wei", "wu", "wen", "wei", "wei",
"xi", "xi", "xian", "xiang", "xiang", "xiao", "xin", "xiao", "xiong", "xiong", "xu", "xi", "xi", "xin", "xin", "xin", "xing",
"yang", "yi", "yi", "yi", "yi", "yong", "yong", "you", "yu", "yu", "yu", "yue", "yi", "yi", "yi", "yi", "yi", "yu", "yu", "yu", "yu", "yin",
"zhen", "zheng", "zhi", "zhi", "zhi", "zhong", "zhou", "zhou", "zi", "zi", "zhong", "zuo", "zao", "zong", "zan", "zhi", "zhi", "zhi",

"chaowei",
"dehua",
"fucheng",
"mengda",
"runfa",
"tuozai",
"weijian",
"xiaochun",
"xingchi",
"xueyou",
});

string* name_g = ({     //Å®ÐÔ×¨ÓÃ
"°®",
"±¦îÎ", "±Ì", "°ØÖ¥",
"´º", "´ä", "³þºì",
"÷ì", "÷ìÓñ", "µ¤",
"·¼", "·Ò", "·ï", "Ü½",
"¹Ã",
"ºç", "ºì", "»¨", "»Ý", "»Û",
"½¿", "¾§", "¾²", "¾Õ", "¾ê",
"çæ",
"À¼", "á°", "Àò", "Àö", "Á«", "ÁÕ", "Áá",
"ÃÀ", "Ãô", "ÂüÓñ",
"Æ¼", "Åå",
"Ù»", "ÇÙ", "ÇÛ", "Çà", "óä", "ÇàÏ¼",
"ÈØ",
"æ©", "Êç",
"æÃ",
"Íñ",
"Ï¼", "ÏÍ", "Ïã", "ÏæÔÆ", "Îõ·ï",
"æÌÈ»", "ÑÞ", "Ñà", "Ó¢", "çø", "Ó«", "Ó¯", "Ó±", "Óñ", "æÂ",
"Õæ", "Õä", "Öé",
});

string* id_g = ({
"ai",
"baochai", "bi", "baizhi",
"chun", "cui", "chuhong",
"dai", "daiyu", "dan",
"fang", "fen", "feng", "fu",
"gu",
"hong", "hong", "hua", "hui", "hui",
"jiao", "jing", "jing", "ju", "juan",
"ke",
"lan", "lan", "li", "li", "lian", "lin", "ling",
"mei", "min", "manyu",
"ping", "pei",
"qian", "qin", "qin", "qing", "qing", "qingxia",
"rong",
"shan", "shu",
"ting",
"wan",
"xia", "xian", "xiang", "xiangyun", "xifeng",
"yanran", "yan", "yan", "ying", "ying", "ying", "ying", "ying", "yu", "yuan",
"zhen", "zhen", "zhu",
});

void create()
{
	seteuid(getuid());
	if (sizeof(f_name) != sizeof(f_id))
		write("ÐÕÊÏÓÐ´íÎó¡£\n");
	if (sizeof(name_m) != sizeof(id_m))
		write("ÄÐÃûÓÐ´íÎó¡£\n");
	if (sizeof(name_g) != sizeof(id_g))
		write("Å®ÃûÓÐ´íÎó¡£\n");
}

mapping get_random_name(int gender)
{
	string f_n, f_i, name_1, id_1, *ids;
	int i;

	i = random(sizeof(f_name));
	f_n = f_name[i];
	f_i = f_id[i];

	if (gender) {	// male
		i = random(sizeof(name_m));
		name_1 = name_m[i];
		id_1 = id_m[i];
		if ( random(10) > 6 ){
			i = random(sizeof(name_m));
			if (strlen(name_1+name_m[i]) <= 4) {
				name_1 += name_m[i];
				id_1 += id_m[i];
			}
		}
	} else {	// female
		i = random(sizeof(name_g));
		name_1 = name_g[i];
		id_1 = id_g[i];
		if (random(10) > 6) {
			i = random(sizeof(name_g));
			if (strlen(name_1+name_g[i]) <= 4) {
				name_1 += name_g[i];
				id_1 += id_g[i];
			}
		}
	}
	if (!NAME_D->valid_name(f_n + name_1))
		return get_random_name(gender);
	ids = ({ f_i+" "+id_1, f_i, id_1 });
/*
	switch (random(4)) {
		case 0:
			ids += ({ f_i });
			break;
		case 1:
			ids += ({ id_1 });
			break;
		case 2:
			ids += ({ f_i, id_1 });
	}
*/
	return ([
		"name" : f_n + name_1,
		"id" : ids,
	]);
}
