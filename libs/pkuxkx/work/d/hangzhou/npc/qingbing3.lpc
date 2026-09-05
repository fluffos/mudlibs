// qingbing.c

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
	set_name("清兵头目", ({ "qingbing tou","tou" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这是位手执长枪的绿营清兵头目。\n");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	
	set("chat_chance", 2);
	set("chat_msg", ({
//	"清兵大声说道：我没醉，我还能喝，我说的都是真的，你们居然不信。\n",
//	"清兵笑着说道：男人不喝酒，活得象条狗呀！哈哈。\n",
	"清兵头目嘿嘿一乐说道：提督府的事没我不知道的。\n",
	}));
	
	set("inquiry", ([
                "提督府" : "哈哈哈! 老子就是提督府的兵。" ,
                "消息"   : "想打听谁的消息？",
                "红花会" : "老子就不怕红花会，他们当家的我都捉过。",
                "文泰来" : (: ask_me :),
        ]) );


	setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/junfu")->wear();
	add_money("silver", 10);
}

int ask_me()
{
        object me,room;
        me = this_player();
        if (me->query("combat_exp")<3000000)  //by Zine Nov 12 2010,限制小号一步到位
        {
            return 0;
        }
        if( me->query("hhh_wtl") == 1 ) 
             {
             write("清兵头目瞪你一眼说：没完没了，你烦不烦呀。\n");
             return 1;
             }
        if( me->query_temp("hhh_wt1") == 1 ) 
             {
             write("清兵头目瞪你一眼说：不刚问完吗，少他妈废话。\n");
             return 1;
             }
        else
             {
               write(HIY"清兵头目小声跟你说道：不是我吹牛，文泰来就是我抓的，就关在提督府内。 \n"NOR);
        
               write(HIY"清兵头目突然好象意识到了什么，说道：哈哈，说着玩呢，说着玩呢。急急忙忙走出了房间。\n"NOR);
               me->set_temp("hhh_wt1",1);
        
               destruct(this_object());
        
        return 1;
             }
}