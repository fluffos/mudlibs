// hezudao.c (kunlun)

inherit NPC;
string* names = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ",
"½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ","Ğ»","×Ş","Ó÷",
"°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ğ","ŞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ı","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø",
"µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂŞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶",
"Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ğ¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ",
"Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ĞÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô",
"Óİ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","³ğ","ºò","ÔÀ","Ë§",
"Ë¾Âí","ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ğ","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦",
"Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ","×ÚÕş","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå",
"ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ğù","Áîºü","ÖÓÀë","ÓîÎÄ","³¤Ëï","Ä»Èİ",
"Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕı","ÈÀæá",
"¹«Á¼","ÍØÖº","¼Ğ¹È","Ô×¸¸","¹ÈÁº","³ş½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ",
"¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù","ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÁºÇğ",
"×óÇğ","¶«ÃÅ","Î÷ÃÅ","°ÛÉÍ","ÄÏ¹Ù",
"çÃ","¿º","¿ö","ºó","ÓĞ","ÇÙ","ÉÌ","Ä²","ÙÜ","¶ú","Ä«","¹ş",
"ÚÛ","Äê","°®","Ñô","Ù¡","µÚ","Îå","ÑÔ","¸£","Øá","ÖÓ","×Ú",
"ÁÖ","Ê¯",
});

string* ids = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});
//----ÒÔÏÂ»¶Ó­Ìí¼Ó£¬nm2ĞèÒªÒ»¶¨µÄ¿Õ×Ö£¬ÒÔ±ã²úÉú³öµ¥Ãû--------------
string* nm2 = ({
"ÖÒ","Ğ¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ğ¡","Ïş",
"¸ß","¿É","°¢","½ğ","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"°Ô","°×","°à","±ó","±ö","²ı","³¬","³Ï","´¨","¶¦","¶¨","¶·",
"·¨","·É","·ç","·æ","¸Ö","î¸","¹á","¹â","º£","»¢","»ª",
"ºÆ","ºê","¼Ã","¼á","½¡","½£","½­","½ø","½Ü","¿¡","¿µ",
"Á¼","÷ë","Ãñ","Ã÷","Ãù","Äş","Åà","Æô","Ç¿","ÈÙ","É½",
"Ì©","ÌÎ","Í¦","Î°","Îõ","Ïé","ĞÛ","Ğñ",
"Òã","è¤","Óğ","Óî","ÔÀ","ÖÛ",
});

void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
	set("per", 35);
	set("long",
		"Ëû¾ÍÊÇÀ¥ÂØÅÉµÄ³öÊ¦µÜ×Ó¡±¡£\n"
		"³¤Á³ÉîÄ¿£¬Êİ¹ÇÀâÀâ£¬Ô¼ÄªÈıÊ®Ëê×óÓÒÄê¼Í¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 27);
	set("int", 40);
	set("con", 40);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 100);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("combat_exp", 2500000);
	set("score", 400000);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		 (: perform_action, "strike.diezhang" :)
	}));

	set_skill("art", 280);
        set_skill("literate", 280);
	set_skill("force", 185);
	set_skill("xuantian-wuji", 380);
	set_skill("dodge", 200);
	set_skill("kunlun-shenfa", 280);
	set_skill("strike", 180);
	set_skill("kunlun-zhang", 280);
	set_skill("parry", 200);
	set_skill("sword", 210);
	set_skill("liangyi-jian", 320);
	set_skill("throwing", 250);
	set_skill("art", 200);
	set_skill("taiji-shengong", 320);
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "art");
	map_skill("sword", "liangyi-jian");
	prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.diezhang" :),
                (: command("unwield qin") :),
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "parry.tianwaifeiyin" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );
	create_family("À¥ÂØÅÉ", 2, "³öÊ¦µÜ×Ó");

        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

//	set("class", "taoist");
	setup();
	carry_object("/d/kunlun/obj/jwqin.c")->wield();
  }

void die()
{
        object ob, me, corpse;
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (me)
{
        if (userp(me))
{
if (me->query("family/family_name")!= ob->query("family/family_name")){message("vision", me->name() + "Ôö¼ÓÁË300ĞŞÎªºÍ200Ç±ÄÜ¡£\n", me);
        
        
        message("vision", me->name() + "Ôö¼ÓÁË300ĞŞÎªºÍ200Ç±ÄÜ¡£\n", me);
        me->add("combat_exp",300);
        me->add("potential",200);
        me->add("score",100);
        me->add("shen",100);
        }destruct(ob);
        return;
}
}
}
#include "heimuya_job.h";