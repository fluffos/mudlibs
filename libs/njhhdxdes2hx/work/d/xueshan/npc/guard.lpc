// guard.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"门房"NOR, ({ "men fang", "guard" }) );
      	set("long", "这个门房虽然武功不高，但所有进出吹雪山庄的人无不对他毕恭毕敬的。 \n"); 

        set("attitude", "peaceful");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp", 5000);

        set("chat_chance", 5);
	set("chat_msg", ({
        	"门房慢吞吞地说：是。。想进我们吹雪山庄吗？。。\n",
	        "我们山庄耗费太大，你想进去，是不是－－－－嘿嘿.\n",
		}) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
	set_skill("dodge", 90);

        setup();
        carry_object("/d/suzhou/npc/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if ( !who->query("marks/吹雪山庄") ) {
                if( ob->value() >=10000 ) {
                        say("门房说道:里面请！\n"); 
                        who->set("marks/吹雪山庄",1);
                        return 1;
		}  
	        else {
       		         say ("鼻子里哼了一声，头掉了过去。\n"); 
			 return 1;
       		     }
		}

	else {
		say ("您太客气了\n");
        	return 1;
		}
}

      