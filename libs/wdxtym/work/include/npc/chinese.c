// chinese name

// ¸üÐÂµÄÄÚÈÝ£º
// mapping get_cn_name() - ·µ»ØÒ»Ì×Ëæ»úÐÕÃû & ID

#include "name.h"

mapping get_cn_name();

mapping cn_sname = ([
	"°×" : "bai",
	"²Ì" : "cai",
	"²Ü" : "cao",
	"³Â" : "chen",
	"´÷" : "dai",
	"ñ¼" : "dou",
	"µË" : "deng",
	"µÒ" : "di",
	"¶Å" : "du",
	"¶Î" : "duan",
	"·¶" : "fan",
	"·®" : "fan",
	"·¿" : "fang",
	"·ç" : "feng",
	"·û" : "fu",
	"¸£" : "fu",
	"¸ß" : "gao",
	"¹Å" : "gu",
	"¹Ø" : "guan",
	"¹ù" : "guo",
	"Ã«" : "mao",
	"º«" : "han",
	"ºú" : "hu",
	"»¨" : "hua",
	"ºé" : "hong",
	"ºî" : "hou",
	"»Æ" : "huang",
	"¼Ö" : "jia",
	"½¯" : "jiang",
	"½ð" : "jin",
	"ÁÎ" : "liao",
	"Áº" : "liang",
	"Àî" : "li",
	"ÁÖ" : "lin",
	"Áõ" : "liu",
	"Áú" : "long",
	"Â½" : "lu",
	"Â¬" : "lu",
	"ÂÞ" : "luo",
	"Âí" : "ma",
	"Å£" : "niu",
	"ÅÓ" : "pang",
	"Åá" : "pei",
	"Åí" : "peng",
	"ÆÝ" : "qi",
	"Æë" : "qi",
	"Ç®" : "qian",
	"ÇÇ" : "qiao",
	"ÇØ" : "qin",
	"Çñ" : "qiu",
	"ôÃ" : "qiu",
	"³ð" : "qiu",
	"É³" : "sha",
	"ÉÌ" : "shang",
	"ÉÐ" : "shang",
	"ÉÛ" : "shao",
	"Éò" : "shen",
	"Ê¦" : "shi",
	"Ê©" : "shi",
	"ËÎ" : "song",
	"Ëï" : "sun",
	"Í¯" : "tong",
	"Íò" : "wan",
	"Íõ" : "wang",
	"Îº" : "wei",
	"ÎÀ" : "wei",
	"Îâ" : "wu",
	"Îä" : "wu",
	"Ïô" : "xiao",
	"Ð¤" : "xiao",
	"Ïî" : "xiang",
	"Ðí" : "xu",
	"Ðì" : "xu",
	"Ñ¦" : "xue",
	"Ñî" : "yang",
	"Ñò" : "yang",
	"Ñô" : "yang",
	"Ò×" : "yi",
	"Òü" : "yin",
	"Óá" : "yu",
	"ÕÔ" : "zhao",
	"ÖÓ" : "zhong",
	"ÖÜ" : "zhou",
	"Ö£" : "zheng",
	"Öì" : "zhu",

	"¶«·½" : "dongfang",
	"¶À¹Â" : "dugu",
	"Ä½ÈÝ" : "murong",
	"Å·Ñô" : "ouyang",
	"Ë¾Âí" : "sima",
	"Î÷ÃÅ" : "ximen",
	"Î¾³Ù" : "yuchi",
	"³¤Ëï" : "zhangsun",
	"Öî¸ð" : "zhuge",
	"ÉÏ¹Ù" : "shangguan",
	"ÏÄºî" : "xiahou",
	"ÎÅÈË" : "wenren",
	"»Ê¸¦" : "huangfu",
	"å£Ì¨" : "tantai",
	"¹«ÖÎ" : "gongzhi",
	"´¾ÓÚ" : "chunyu",
	"ÉêÍÀ" : "shentu",
	"¹«Ëï" : "gongsun",
	"¹«Ñò" : "gongyang",
	"ÐùÔ¯" : "xuanyuan",
	"Áîºü" : "linghu",
	"ÖÓÀë" : "zhongli",
	"ÓîÎÄ" : "yuwen",
	"Ä½ÈÝ" : "murong",
	"ÖÙËï" : "zhongsun",
	"Ë¾Í½" : "situ",
	"Ë¾¿Õ" : "sikong",
	"¶ËÄ¾" : "duanmu",
	"¹«Á¼" : "gongliang",
	"°ÙÀï" : "baili",
	"¶«¹ù" : "dongguo",
	"ÄÏ¹ù" : "nanguo",
	"ºôÑÓ" : "huyan",
	"ÑòÉà" : "yangshe",
	"¶«ÃÅ" : "dongmen",
	"ÄÏ¹¬" : "nangong",
]);

mapping cn_pname = ([
	"ai"   : "°¨°¬°§",
	"an"   : "°²÷öÚÏ",
	"ao"   : "°Â°Á°½æñ°¿",
	"ang"  : "°º°»",
	"ba"   : "°Õ°Ô",
	"bai"  : "°×°Û",
	"ban"  : "°ß°ã",
	"bang" : "°î",
	"bei"  : "±±±¶±´±¸",
	"biao" : "±í±ê±ëì®ì­",
	"bian" : "±ß±åÛÍâí",
	"bu"   : "²½²»",
	"cao"  : "²Ü²Ý²Ùäî",
	"cang" : "²Ô²Ö",
	"chang": "³£³¤²ý³¨«`",
	"chi"  : "³Ù³Ö³Ø³à³ß³Û³ã",
	"ci"   : "´Ë´Î´Ê´Ä´Ç´È",
	"du"   : "¶À¶¼",
	"dong" : "¶«¶±",
	"dou"  : "¶¼",
	"fa"   : "·¢·¦·©",
	"fan"  : "·¶·²·´·º·«Þ¬",
	"fang" : "·½·ÃÚú•P",
	"feng" : "·ç·ï·â·á·î·ã·å·æ",
	"fu"   : "·ò·û¸¥Ü½",
	"gao"  : "¸ß¸ÞÛ¬¸ä",
	"hong" : "ºéºìºêºèºçãüºë",
	"hu"   : "»¢ºöºþ»¤ºõìïä°âï",
	"hua"  : "»¯»¨»ªæèèë",
	"hao"  : "ºÅºÆð©ÝïºÆê»å°œB",
	"ji"   : "»ý¼«¼Ã¼¼»÷¼²¼°»ù¼¯¼Ç¼Í¼¾¼Ì¼ª¼Æ¼½¼À¼Ê¼®¼¨¼É¼Åö«ð¢çáÜ¸"
		 "¼»ê«Ù¥ÆæÚµóÅçÜê÷",
	"jian" : "½¥½£¼û½¨¼ä¼í¼á¼ó",
	"kan"  : "¿¯ê¬",
	"ke"   : "¿É¿Ë¿Æ¿Ìçæã¡äÛ ˜",
	"lang" : "ÀÊÀËÀÈÀÅãÏÝ¹",
	"li"   : "ÀúÀëÀïÀíÀûÁ¢Á¦ÀöÀñÀèÀõÀóÁ¤èÝÁ§",
	"lin"  : "ÁÙÁØÁÖÁÕ",
	"ma"   : "Âí", 
	"mao"  : "Ã³Ã°Ã²Ã°í®Ã¬Ã®è£",
	"miao" : "íµÃìåã",
	"nan"  : "éªÄÏ",
	"pian" : "Æ¬ôæ",
	"qian" : "Ç±Ç«Ù»ÜçÇ¬ò¯Ç§",
	"qiang": "Ç¿Ç¼ïº«o",
	"qin"  : "Ç×ÇÙÇÕÇßÜËñæ",
	"qing" : "ÇåÇìÇäÇç",
	"ran"  : "È½È»È¾È¼",
	"ren"  : "ÈÊÈÐÈÉØð",
	"sha"  : "É³É·",
	"shang": "ÉÏÉÑÉÌ",
	"shen" : "ÉîÉóÉñÉêÉ÷²ÎÝ·",
	"shi"  : "Ê¦Ê·Ê¯Ê±Ê®ÊÀÊ¿Ê«Ê¼Ê¾ÊÊìÂ",
	"shui" : "Ë®",
	"si"   : "Ë¼Ë¹Ë¿Ë¾ìëËÃËÈ",
	"song" : "ËÉËÌËÐ",
	"tang" : "ÌÃÌÆÌÄè©",
	"tong" : "Í³Í¨Í¬Í¯Í®ÙÚ",
	"tian" : "ÌìÌïãÃ",
	"wan"  : "ÍòÍðÍí",
	"wei"  : "ÎÀÎ¢Î°Î¬ÍþÎ¤Î³ì¿Î©çâÎª",
	"wu"   : "ÎâÎïÎñÎäÎçÎåÎ×ÚùØ£ÎãÎì",
	"xi"   : "Î÷Ï¯ÎýÏ´Ï¦ÙâìäÏ§",
	"xiao" : "äìÏôÐ¦ÏþÐ¤ÏöæçÐ£",
	"xiong": "ÐÜÐÛ",
	"yang" : "ÑòÑóÑôÑúÑëÑíì¾ïrÑì",
	"yi"   : "Ò×ÒâÒÀÒàÒÁÒÄÒÐÒãÒåÒËÒÇÒÕÒëÒíÒÝÒäâùìÚÒÊÒÃÞÈÞÄÜ²ñ´éóÒÙâ¢Òî",
	"yin"  : "ÒþÒòÒýÒøÒôÒúÒ÷Ø·ÓÑÌÒñ",
	"ying" : "Ó³Ó¢Ó°Ó±çøÓ¦Ó¨Û«Ó¥",
	"you"  : "ôíÓÄÓÆÓÒÓÇéàÓÏ",
	"yu"   : "ÓæÓôÔ¢ÓÚÓàÓñÓêÓïÔ¤ÓðÓßÓýÓîÓíÓòÓþè¤ÓìÓùÓåØ¹ÓÝØ®Ô¥Ô£îÚìÏí²",
	"zhi"  : "ÖÆÖÁÖµÖªÖÊÖÂÖÇÖ¾Ö±ÖÎÖ´Ö¹ÖÃÖ¥Ö¼ÖÅÜÆÖ¿Û¤ÖËïôÖÄ",
	"zhong": "ÖÐÖÒÖÓÖÔ",
	"zhou" : "ÖÜÖÝÖÛëÐÖç",
	"zhu"  : "ÖñÖ÷×¤Öì×£ÖîÖéÖøóÃ",
	"zhuo" : "×¿×Æ×Æ×¾×Áåªí½ßªìÌ×Ã",
	"zi"   : "×Ó×Ê×È×Ï×Ë×Îè÷ïö",
	"zong" : "×ÚèÈ",
	"zu"   : "×ã×å×æ×ä",
	"zuo"  : "×÷×ó×ôóÐÔä",
]);

void generate_cn_name(object ob)
{
	mapping ret;

	if (! ob) return;

	ret = get_cn_name();

	ob->set_name(ret["name"], ret["id"]);
}

mapping get_cn_name()
{
	string sname, pname, pname2, id1, id2;
	string *ks, *kp;

	ks = keys(cn_sname);
	kp = keys(cn_pname);
	sname = ks[random(sizeof(ks))];
	id1 = cn_sname[sname];
	for (;;)
	{
		pname = kp[random(sizeof(kp))];
		if (pname != id1 &&
		    ! find_living(id1 + " " + pname))
			break;
	}

	id2 = pname;
	pname = cn_pname[pname];
	pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1];
	pname = pname[0..1];
	if (random(3) == 0)
	{
		for (;;)
		{
			pname2 = kp[random(sizeof(kp))];
			if (pname2 != id1 && pname2 != pname &&
			    ! find_living(id1 + " " + pname + pname2)) break;
		}
		id2 += pname2;
		pname2 = cn_pname[pname2];
		pname2 = pname2[(random(sizeof(pname2)) & 0xFFFE)..<1];
		pname2 = pname2[0..1];
	} else
		pname2 = "";
		
	return ([ "name" : sname + pname + pname2,
		  "id"   : ({ id1 + " " + id2, id1, id2, }), ]);
}
