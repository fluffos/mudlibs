// xiaoyaozi.c 逍遥子
// zly 7/6/99

#include <ansi.h>
inherit NPC;
string ask_yaoshi();

void create()
{
	set_name("逍遥子", ({"xiaoyao zi", "zi", "xiaoyao"}));
	set("title", HIY"太岳四侠"NOR);
	set("nickname", "烟霞神龙");
        set("shen_type", 1);
	set("gender", "男性");
	set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("age", 38);
	set("long", 
"这是一个病夫模样的中年人，衣衫褴褛，咬着一根旱烟管，双目
似争似闭，嘴里慢慢喷着烟雾。\n"
	);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("max_qi", 500);
	set("qi", 500);
	set("jing",500);
	set("max_jing", 500);
        set("jingli", 600);
        set("eff_jingli", 600);        
	set("neili", 500);
	set("max_neili", 900);
	set("jiali", 1);
	
	set("combat_exp", 90000);
	
	set_skill("force", 60);		
	set_skill("huntian-qigong", 60);
	set_skill("stick" ,90);	
	set_skill("dodge", 60);			
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "逍遥子嘿嘿笑着低声自言自语道：“我要好好地藏着...”说完，警惕地望了望四周。\n",
        }) );

        set("inquiry", ([
           "钥匙"  : (: ask_yaoshi :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/yanguan")->wield();
        carry_object(__DIR__"obj/shoes")->wear();        
       

} 

string ask_yaoshi()
{
        object me=this_player();
        me->set_temp("tao",1);
        command("hehe");
        command("whisper "+me->query("id")+" 打死我也不会告诉你的。");
        return "说完，偷偷向假山那边望了一眼。\n";
}

