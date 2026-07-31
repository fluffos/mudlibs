// miejue.c Ãğ¾øÊ¦Ì«
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
//inherit F_SKILL;

string* nm1 = ({
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

string* id = ({
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

string* nm2 = ({
"ÖÒ","Ğ¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ğ¡","Ïş",
"¸ß","¿É","°¢","½ğ","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm4 = ({      //Å®ĞÔ×¨ÓÃ
"°®","´º","µ¤","·¼","·Ò","·ï","¹Ã","ºì","ºç","½¿","¾ê",
"¾Õ","À¼","á°","Àö","Àò","Á«","Áá","ÁÕ","ÄÈ","ÇÙ","ÇÛ",
"Ù»","Æ¼","æÃ","Ï¼","Ïã","ÑŞ","Ñà","Ó¢","çø","Óñ","Õä",
"Öé",
});

void create()
{
   int i = random(sizeof(nm1));
   set_name(nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))], ({id[i]}));
   set("per",35);
        set("long",
                "ËıÊÇ¶ëáÒÅÉµÄµÚÈı´úµÜ×Ó£¬¡£\n");
        set("gender", "Å®ĞÔ");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("per", 20);

        set("max_qi", 4000);
        set("max_jing", 2000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("persuading", 150);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 250);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 320);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
//        map_skill("magic","bashi-shentong");
        create_family("¶ëáÒÅÉ", 4, "³öÊ¦µÜ×Ó");
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
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