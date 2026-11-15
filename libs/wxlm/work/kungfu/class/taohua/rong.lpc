// rong.c 黄帮主

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黄帮主", ({"huang rong", "huang", "rong"}));
	set("title", "桃花岛主独生爱女");
	set("gender", "女性");
	set("age", 18);
	set("long", @LONG
这是桃花岛主的独生女儿。由于岛主夫人早死，岛主对这个女儿备加疼爱。
她生性跳脱飞扬，喜欢四处乱跑。
LONG );

    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 18);
    set("int", 36);
    set("con", 21);
    set("dex", 26);

    set("qi", 800);
    set("max_qi", 800);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 0);
	
    set("combat_exp", 200000);
    set("score", 100000);
	
    set_skill("force", 80);
    set_skill("bibo-shengong", 80);
    set_skill("luoying-xinfa", 80);
    set_skill("unarmed", 80);
    set_skill("xuanfeng-leg", 80);      // 旋风扫叶腿
    set_skill("strike", 80);	    // 基本掌法
    set_skill("luoying-shenzhang", 80);
    set_skill("dodge", 150);
    set_skill("anying-fuxiang", 100);
    set_skill("parry", 85);
    set_skill("literate",180);	   // 读书识字
    set_skill("sword", 80);
    set_skill("luoying-shenjian",80);

    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("strike" , "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
	
    create_family("桃花岛", 2, "弟子");

    set("inquiry", ([
	"黄岛主" : "爹爹呀, 不在厅里麽? ",
	"郭大侠"   : "怎么? 你有我靖哥哥的消息吗? ",
    ]));

    setup();
    carry_object("/d/taohua/obj/ruanwei")->wear();
    carry_object("/d/taohua/obj/shudai")->wear();
}

