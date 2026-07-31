#include <command.h>
#include <ansi.h>

inherit NPC;

int do_copy(object me,int maxpot);
int do_back(object me);

string* nm1 = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ",
"½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ðí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ð","Îº","ÌÕ","½ª","ÆÝ","Ð»","×Þ","Ó÷",
"°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ð","ÞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ý","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø",
"µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂÞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶",
"Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ð¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ",
"Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ÐÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô",
"ÓÝ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","³ð","ºò","ÔÀ","Ë§",
"Ë¾Âí","ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ð","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦",
"Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ","×ÚÕþ","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå",
"ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ðù","Áîºü","ÖÓÀë","ÓîÎÄ","³¤Ëï","Ä»ÈÝ",
"Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕý","ÈÀæá",
"¹«Á¼","ÍØÖº","¼Ð¹È","Ô×¸¸","¹ÈÁº","³þ½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ",
"¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù","ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÁºÇð",
"×óÇð","¶«ÃÅ","Î÷ÃÅ","°ÛÉÍ","ÄÏ¹Ù",
"çÃ","¿º","¿ö","ºó","ÓÐ","ÇÙ","ÉÌ","Ä²","ÙÜ","¶ú","Ä«","¹þ",
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
"ÖÒ","Ð¢","Àñ","Òå","ÖÇ","ÓÂ","ÈÊ","¿ï","ÏÜ","Áî","¸£","Â»","´ó","Ð¡","Ïþ",
"¸ß","¿É","°¢","½ð","ÊÀ","¿Ë","Êå","Ö®","¹«","·ò","Ê±","Èô","Çì","ÎÄ","Îä",
"¶à","²Å","³¤","×Ó","ÓÀ","ÓÑ","×Ô","ÈË","Îª","Ìú","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm4 = ({      //Å®ÐÔ×¨ÓÃ
"°®","´º","µ¤","·¼","·Ò","·ï","¹Ã","ºì","ºç","½¿","¾ê",
"¾Õ","À¼","á°","Àö","Àò","Á«","Áá","ÁÕ","ÄÈ","ÇÙ","ÇÛ",
"Ù»","Æ¼","æÃ","Ï¼","Ïã","ÑÞ","Ñà","Ó¢","çø","Óñ","Õä",
"Öé",
});

void create()
{
      string weapon;
   int i = random(sizeof(nm1));
   set_name(nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))], ({id[i]}));
   set("per",35);
        set("gender", "Å®ÐÔ");
        set("age", random(30) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        //set("long", "Ò»¸ö´©×ÅºÚÉ«Ò¹ÐÐÒÂµÄÈË¡£\n");
        set("combat_exp", 80000 + random(40000));
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("literate", 100);
        set_skill("mahayana", 150);
        set_skill("buddhism", 150);
        set_skill("jinding-zhang", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("huifeng-jian", 100);
        set_skill("yanxing-dao", 100);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 10);
        set_temp("apply/damage", 150);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
        }) );
              set("max_qi", 450);
        set("eff_jingli", 400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        ob = this_object();
        i=me->query_skill("force",1);
//        i = i +10+ random(10);
//        if( i < 100) i = 100;

        ob->set("combat_exp", (me->query("combat_exp")));
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("huifeng-jian", i*3/4);
        ob->set_skill("zhutian-bu", i*3/4);
        ob->set_skill("jinding-zhang", i*3/4);
        ob->set_skill("linji-zhuang", i*3/4);
        set_skill("linji-zhuang",i*3/4);
        	ob->set("qi", 5000+i*30);
        ob->set("jing", me->query("eff_jing")+5000);
        ob->set("eff_jing", me->query("eff_jing")+5000);
		ob->set("max_qi", 1000+i*28);
        ob->set("eff_jingli", me->query("eff_jingli")*2/3);
        ob->set("max_neili", 1000+i*15);
        //ob->set("jiali", i/6);
        ob->reincarnate();
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
if (me->query("combat_exp") >3500000)
{
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
        }) );
}

		call_out("do_back", 200,  ob);
        return 1;
}

int do_back(object me)
{
  tell_room(environment(me), me->query("name")+"´Ò´ÒÃ¦Ã¦µÄÀë¿ªÁË¡£\n", ({me}));
  destruct(me);
  return 1;
}


void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;

if (me)
{
        message_vision(HIR "\nÎåÅÉÊ×Áìµ¹ÔÚµØÉÏ£¬ÕõÔúÁË¼¸ÏÂ¾ÍËÀÁË¡£\n" NOR,me);
        message_vision(HIG "\nÄã´ÓÎåÅÉÊ×ÁìµÄÉíÉÏÕÒµ½ÁËÎåÅÉÁîÆì¡£\n" NOR,me);
        if (me->query("mjjob") == 1
        && this_object()->query_temp("hostmj")== me->query("id")){
               zhi=new("/quest/menpaijob/mingjiao/mijian");
               zhi->set_temp("host",me->query("id"));
               zhi->move(me);
                me->add("score",50);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "ÎåÅÉÊ×ÁìµÄÊ¬Ìå" NOR);
        corpse->set("long","ËûÊÇÒ»¸öÔø¾­µÀÃ²°¶È»µÄÎåÅÉÊ×Áì£¬\nÈ»¶ø£¬ËûÒÑ¾­ËÀÁË£¬Ê£ÏÂÒ»¾ß³óÂªµÄÊ¬Ìå¡£\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);
        me->add("MKS", 1);
}
        destruct(this_object());
}
