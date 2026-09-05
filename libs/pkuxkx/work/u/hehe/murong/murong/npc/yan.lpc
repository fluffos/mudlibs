//yan.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("严妈妈", ({ "yan mama", "mam", "yan" }));
    set("gender", "女性");
    set("age", 50);      
	set("title",BLU	"花肥房管事"NOR);
	set("str", 25);
    set("int", 26);
    set("con", 26);
    set("dex", 26);
    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "peaceful");
	set("max_qi",1000);
    set("max_jing",1000);
	set("no_get","你没办法拿起这个人");
    set("neili",1000);
    set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

	set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling-shenfa",70);
    set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);
    set_skill("blade",70);
	
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    setup();
	carry_object(__DIR__"obj/menkey");
//	carry_object(__DIR__"obj/qingyi")->wear();
//    carry_object(__DIR__"obj/shoes")->wear(); 
    set("inquiry", ([
		"name" : "我是曼佗罗山庄的花房管事。\n",
        "here" : "这里是花肥房，专门把夫人让处死的人做花肥。\n",
        "rumors" : "最近一个姓段的小子从我手里跑了。\n",
        ]));           
}
