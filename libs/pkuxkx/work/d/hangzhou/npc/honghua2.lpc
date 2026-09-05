// honghua2.c

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
        set_name("绿营会众", ({ "lvying huizhong","huizhong" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这是位手执长枪的绿营清兵，红花会在江南声势大盛，绿营也
多有会众。\n");
	set("combat_exp", 20000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set("inquiry", ([
                "红花会" : "身在曹营心在汉呀！",
                "文泰来" : (: ask_me :),
        ]) );

	setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/junfu")->wear();
	add_money("silver", 20);
}

int ask_me()
{
        object me,room;
        me = this_player();

        if( me->query_temp("hhh_wt1") != 5 ) 
             {
             write(HIM"绿营会众警惕的瞪你一眼说：该干什么干什么去。\n"NOR);
             return 1;
             }
        if( me->query_temp("hhh_wt1") == 5 )
             {
               write(HIY"绿营会众小声跟你说道：原来你是总舵主派来救人的，四当家的关在地牢里，我带你去。 \n"NOR);
               message("vision",HIY"你跟着绿营会众在花园里穿来穿去，不一会便来到地牢旁。\n"NOR, me);
               message("vision",HIY"绿营会众说：快进去救人，我先走了，小心小心！\n"NOR, me);
               
               me->move("/d/hangzhou/tidufu/td_dilao1");
               me->set_temp("hhh_wt1",6);
        
        return 1;
             }
}

