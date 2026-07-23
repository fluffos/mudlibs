 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int tell_him();
void create()
{
    set_name("关玉门", ({ "master yumen", "master"}) );
    set("nickname", HIW "生裂虎豹"NOR);
    set("gender", "男性" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 45);
    set("per", 15);
    set("agi", 300);
    set("str", 50);
    set("int",30);
        set("max_jing",16000);
        set("max_qi",16000);
    set("ill_boss",5);
    set("attitude","friendly");
    set("max_neili", 3000);
    set("neili", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
            set("neili",16000);
        set("max_neili",16000);
        set_skill("dodge", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",360);
	set_skill("demon-steps",300);
	set_skill("demon-strike",300);
	set_skill("demon-force",300);
	set_skill("blade",350);
	set_skill("demon-blade",350);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("parry","demon-blade");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);	
    set("long", "
一条高大魁伟的汉子，却瘦骨支离，好象瘦的只剩下皮包骨头一样。
他非但走不稳，连站好象都站不稳，但嘴里却总是吃个不停。\n");
    create_family("财神庙", 7, "当家");
    set("rank_nogen",1);
    set("ranks",({"脚夫","伙计","信差","趟子手","执旗手","镖师","镖头",
                      "副总镖头","总镖头",HIW"特使"NOR,
                      RED"令主"NOR,HIY"大当家"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
 
    set("combat_exp", 7000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "关玉门瞄了瞄胡金袖：如果能让我把金狼牙找回来，这次在老卜面前可长面子了．．．\n",
            }) ); 
    set("inquiry",  ([
                "wolf tooth" : (: tell_him :),
                "金狼牙" : (: tell_him:),
                ]) );

    set_skill("move", 160);
    set_skill("parry",120);
    set_skill("dodge", 320);
    set_skill("force", 380);
    set_skill("literate", 300);
    set_skill("unarmed",220);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
        }) );
   setup();
   carry_object(__DIR__"obj/dagger")->wield();
   carry_object("/clone/misc/cloth")->wear(); 
} 



void init()
{       
//	  object ob;
        ::init();
  /*              if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }*/
        add_action("do_killing", "kill");
} 



int tell_him()
{
    object me;
    me =this_player();
    tell_object(me,"关玉门豪气地拍了拍手：哈，听说老卜有只萧十一郎遗传下来的金狼牙，不知道现在丢哪了……\n");
    return 1;
} 

int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIY"金狼牙"NOR)
        {
                obj = new(__DIR__"obj/xiruobook");
                message_vision(CYN"$N说道：多谢多谢，这次终於可以在老卜面前威风一次了。没什麽好东西给你，这书我看不懂，就送你吧！\n"+"$N将"NOR + obj->name() + CYN"塞入$n手中。\n", 
                            this_object(),this_player() );

                        book = new(__DIR__"obj/xiruobook");
                        if(book) book->move(this_player());
                        
                        
                if(!me->query("m_success/金狼牙"))
                {
                        me->add("score",1000);
                        me->set("m_success/金狼牙",1);
                }
           return 1;       
        }
        else {return notify_fail("关玉门哈哈大笑：这破玩意你大爷我多着呢！\n");}
            
        return 1;
} 

 