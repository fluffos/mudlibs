// hehongyao.c
// ∫Œ∫Ï“©
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();
string* names = ({
"’‘","«Æ","ÀÔ","¿Ó","÷‹","Œ‚","÷£","Õı","∑Î","≥¬","Ò“","Œ¿",
"ΩØ","…Ú","∫´","—Ó","÷Ï","«ÿ","”»","–Ì","∫Œ","¬¿"," ©","’≈",
"ø◊","≤‹","—œ","ª™","Ω","Œ∫","Ã’","Ω™","∆›","–ª","◊ﬁ","”˜",
"∞ÿ","ÀÆ","Òº","’¬","‘∆","À’","≈À","∏","ﬁ…","∑∂","≈Ì","¿…",
"¬≥","Œ§","≤˝","¬Ì","√Á","∑Ô","ª®","∑Ω","…µ","»Œ","‘¨","¡¯",
"µÀ","±´"," ∑","Ã∆","∑—","¡Æ","·Ø","—¶","¿◊","∫ÿ","ƒﬂ","Ã¿",
"ÃŸ","“Û","¬ﬁ","ª™","∫¬","⁄˘","∞≤","≥£","¿÷","¥Ù"," ±","∏∂",
"∆§","±Â","∆Î","øµ","ŒÈ","”‡","‘™","≤∑","πÀ","”Ø","∆Ω","ª∆",
"∫Õ","ƒ¬","–§","“¸","“¶","…€","’ø","ÕÙ","∆Ó","√´","”Ì","µ“",
"√◊","±¥","√˜","≤ÿ","º∆","∑¸","≥…","¥˜","Ã∏","ÀŒ","√©","≈”",
"–‹","ºÕ"," Ê","«¸","œÓ","◊£","∂≠","¡∫","∑Æ","∫˙","¡Ë","ªÙ",
"”›","ÕÚ","÷ß","ø¬","Í√","π‹","¬¨","”¢","≥","∫Ú","‘¿","Àß",
"Àæ¬Ì","…œπŸ","≈∑—Ù","œƒ∫Ú","÷Ó∏","Œ≈»À","∂´∑Ω","∫’¡¨","ª ∏¶",
"Œæ≥Ÿ","π´—Ú","Â£Ã®","π´÷Œ","◊⁄’˛","Âß—Ù","¥æ”⁄","µ•”⁄","Ã´ Â",
"…ÍÕ¿","π´ÀÔ","÷ŸÀÔ","‘Ø–˘","¡Ó∫¸","÷”¿Î","”ÓŒƒ","≥§ÀÔ","ƒª»›",
"ÀæÕΩ"," ¶ø’","Úßø◊","∂Àƒæ","Œ◊¬Ì","π´Œ˜","∆·µÒ","¿÷’˝","»¿Ê·",
"π´¡º","Õÿ÷∫","º–π»","‘◊∏∏","π»¡∫","≥˛Ω˙","—÷∑®","»Í€≥","Õø«’",
"∂Œ«ß","∞Ÿ¿Ô","∂´π˘","ƒœπ˘","∫Ù—”","πÈ∫£","—Ú…‡","Œ¢…˙","¡∫«",
"◊Û«","∂´√≈","Œ˜√≈","∞€…Õ","ƒœπŸ",
"Á√","ø∫","øˆ","∫Û","”–","«Ÿ","…Ã","ƒ≤","Ÿ‹","∂˙","ƒ´","π˛",
"⁄€","ƒÍ","∞Æ","—Ù","Ÿ°","µ⁄","ŒÂ","—‘","∏£","ÿ·","÷”","◊⁄",
"¡÷"," Ø",
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
//----“‘œ¬ª∂”≠ÃÌº”£¨nm2–Ë“™“ª∂®µƒø’◊÷£¨“‘±„≤˙…˙≥ˆµ•√˚--------------
string* nm2 = ({
"÷“","–¢","¿Ò","“Â","÷«","”¬","» ","øÔ","œ‹","¡Ó","∏£","¬ª","¥Û","–°","œ˛",
"∏ﬂ","ø…","∞¢","Ω"," ¿","øÀ"," Â","÷Æ","π´","∑Ú"," ±","»Ù","«Ï","Œƒ","Œ‰",
"∂‡","≤≈","≥§","◊”","”¿","”—","◊‘","»À","Œ™","Ã˙","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"∞‘","∞◊","∞‡","±Û","±ˆ","≤˝","≥¨","≥œ","¥®","∂¶","∂®","∂∑",
"∑®","∑…","∑Á","∑Ê","∏÷","Ó∏","π·","π‚","∫£","ª¢","ª™",
"∫∆","∫Í","º√","º·","Ω°","Ω£","Ω≠","Ω¯","Ω‹","ø°","øµ",
"¡º","˜Î","√Ò","√˜","√˘","ƒ˛","≈‡","∆Ù","«ø","»Ÿ","…Ω",
"Ã©","ÃŒ","Õ¶","Œ∞","Œı","œÈ","–€","–Ò",
"“„","Ë§","”","”Ó","‘¿","÷€",
});

string ask_jianxi();
string ask_finish();
void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));

        set("title","ŒÂ∂æΩÃ≥§¿œ");
        set("gender", "≈Æ–‘");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 14000);
        set("max_jing", 14000);
        set("neili", 14000);
        set("max_neili", 14000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("wudu-shengong", 200);
        set_skill("dodge", 190);
        set_skill("wudu-yanluobu", 150);
        set_skill("unarmed", 160);
        set_skill("qianzhu-wandushou", 160);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 180);
        set_skill("poison", 160);
        set_skill("literate", 80); 
        set_skill("finger",160);
        set_skill("shedu-qiqiao",160);
//      set_skill("hammer", 100);
//      set_skill("jinshe-chui", 150 );
//      set_skill("huoyan-dao", 200);
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "finger.sandu" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "finger.sandu" :),
                (: perform_action, "dodge.snake" :),
        }) );


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//      map_skill("hammer", "jinshe-chui");
//      map_skill("strike","huoyan-dao");

        create_family("ŒÂ∂æΩÃ", 11, "≥§¿œ");

        setup();

        carry_object("d/wudujiao/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("d/wudujiao/npc/obj/wuxing");

        add_money("gold",10);
}


void die()
{
int i,pot,exp;
	object killer;
	exp= random(80)+80;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"ƒ„±ªΩ±¿¯¡À\n"+chinese_number(exp)+"µ„ µ’Ω–ﬁŒ™\n"
		+chinese_number(pot)+"µ„«±ƒ‹\n");
if (killer)
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}