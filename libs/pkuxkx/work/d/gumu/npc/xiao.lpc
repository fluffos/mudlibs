// xiao.c 执萧少女
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;
/*string ask_me();
void consider();*/
void create()
{
        set_name("执箫少女", ({ "xiao","shaonu" }));
        
         set("title",GRN "古墓派" NOR + YEL +"使女" NOR);
        set("long",
                "她是神雕大侠收养的孤儿\n"
                "她手中拿着一把两尺长的箫，幽幽地吹着。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 20);
        set("max_qi", 400);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);
    set("combat_exp", 5000);
        set("score", 500);
/*set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "name"   : "我就是阿紫呀！！",
        ]) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
  */   
	 set_skill("force", 40);
        set_skill("yunu-xinfa", 40);
	set_skill("cuff", 40);
	set_skill("meinu-quan", 40);
        set_skill("dodge", 50);
        set_skill("xianyun", 40);
        set_skill("parry", 40);
//        set_skill("sword", 40);
//	set_skill("throwing",70);
//	set_skill("qianmie-shou",70);
        set_skill("literate", 40);

       

        map_skill("force", "yunu-xinfa");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "meinu-quan");
 //       map_skill("whip", "chang");

	prepare_skill("cuff", "meinu-quan");

       

        create_family("古墓派" , 6, "弟子");
        setup();
        carry_object(__DIR__"obj/xiao")->wield();
        carry_object(__DIR__"obj/white")->wear();
}
