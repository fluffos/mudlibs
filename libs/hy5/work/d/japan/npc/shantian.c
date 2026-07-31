#include <ansi.h>
inherit F_DEALER;
inherit NPC;
void create()
{
  set_name("山田英树",({"shantian yingshu","shantian","yingshu"}));
   set("gender","男性");
   set("age",47);
   set("title","神户朝野书屋");
   set("combat_exp",20000);
   set_skill("unarmed",10);
   set_skill("dodge",10);
   set_skill("force",10);
   set_skill("parry",10);
   set_skill("literate",10);
   
   
set("vendor_goods", ({
    __DIR__"obj/force_book.c",
    __DIR__"obj/blade_book.c",
    __DIR__"obj/sword_book.c",
    __DIR__"obj/dodge_book.c",
    __DIR__"obj/unarmed_book.c",
	}));
   
   
   setup();
   add_money("silver",30);
   carry_object("/clone/misc/cloth")->wear();
carry_object("/clone/weapon/gangjian")->wield();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}