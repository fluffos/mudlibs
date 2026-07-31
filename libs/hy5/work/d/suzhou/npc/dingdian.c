 // by Xiaoyao

inherit NPC;
#include <ansi.h>
void destroying(object, object);

void create()
{
        set_name("老犯人", ({ "fan ren", "fanren" }));
        //set("long", "这人满脸虬髯，头发长长的直垂至颈，衣衫破烂不堪，简直如同荒山中的野人。\n");
        set("gender", "男性");
        set("age", 35);
        set("unique", 1);
set("no_get",1);
        set_skill("unarmed", 520);
        set_skill("dodge", 520);
        set_skill("parry", 530);
        set_skill("force", 550);
	set_skill("taixuan-gong", 850);
        set_skill("shenzhao-jing", 380);
        map_skill("dodge","taixuan-gong");
        map_skill("force","taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed","taixuan-gong");
        set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );

	set("inquiry", ([
		"丁典" : "“唉……”，丁大哥，前段时间给抓去江陵了。\n",

	]));
        
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        set("combat_exp", 9900000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/armor/cloth")->wear();
}


