// qiyunao

inherit NPC;
void create()
{
  
       set_name("齐云敖", ({ "qi yunao", "qi" }));
       set("nickname", "五毒教左使");
       set("long", 
               "他就是五毒教左使，一身用毒的本领极为可怕。\n"
               "他的一张脸上没有任何表情。\n");
        set("gender", "男性");
       set("age", 36);
       set("attitude", "friendly");
       set("shen", -8000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
	set("unique", 1);
       set("startroom","/d/miaojiang/haozhai");
         set("env/wimpy", 60);
             set("chat_chance", 30);
             set("chat_msg", ({
               "齐云敖冷冷巡视着周围过往的人。\n",
                 (: random_move :)
                    }) );
       set("max_qi", 1500);
       set("max_jing", 1500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 100);
       set("combat_exp", 900000);
 
       set_skill("force", 150);
        set_skill("yinyun-ziqi", 150);
       set_skill("dodge", 150);
      
       set_skill("tiyunzong", 160);
       set_skill("finger", 150);
       set_skill("qianzhu-wandushou", 160);
       set_skill("parry", 140);
       set_skill("sword", 140);
       set_skill("poison", 140);
       set_skill("literate", 80);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("finger", "qianzhu-wandushou");
       map_skill("parry", "qianzhu-wandushou");
       prepare_skill("finger", "qianzhu-wandushou");
     

       set("inquiry", ([
//               "秘籍" : (: ask_me :),
               "袁承志" : "教主一直挂怀着他，好久没有音信了。",
               "含沙射影" : "它是天下最毒辣的暗器。",
                
       ]));

//       wupin = random(2)?"/u/dubei/miaojiang/obj/txjdd":"/clone/weapon/blade";

       setup();
       carry_object(random(2)?"/d/miaojiang/obj/txjdd":"/clone/weapon/changjian");
       carry_object("/clone/armor/cloth")->wear();
 

}
 
 
 

 
