
// young.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("落魄女子", ({ "young" }) );
	set("long", "这个年青女子不知姓甚名谁, 她整日徘徊在街头，好象在等待什么。\n");
      set("gender", "女性" );
	set("age", 22);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
      set("combat_exp", 5000);
      set("score", 1000);
      set_skill("dodge", 70);
      set_skill("snowwhip", 60); 
      set("force", 300);
      set("max_force", 300);
      set("force_factor", 10);
      set("chat_chance",16);
      set("chat_msg",({
              (: this_object(), "random_move" :),
      }));
        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
        (: this_object(),"random_move" :),
        (:command("say 难道你不怕遭天谴！！") :),
         }) );

      setup();
      carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me, object ob)
{
        object obb;
        int amount;
        amount = 5000;
        if(!ob->query("扬州城官兵的信") ) return 0;
        say("啊，信!夫君还....\n");
        tell_object(me,"小女子无以为报，这50两银子还望公子收下\n");
        message_vision("落魄女子给$N50两银子.\n",me);
        obb=new(SILVER_OB);
        obb->set_amount(amount/100);
        obb->move(me);
        call_out("dest_obj",0);
	return 1;
}

int dest_obj()
{
        object letter;
        letter=present("letter",this_object());
if(letter)
        destruct(letter);
        return 1;
}

