// qulingf.c -黄药师

#include <ansi.h>

inherit NPC;

#include "/new_quest/qtaohua.h"
#include "/new_quest/quest.h"

void consider();

void create()
{
	set_name("曲灵风", ({ "quling feng", "feng", "quling" }) );

	set("nickname",  RED "桃花岛" NOR);
	set("title", GRN "大弟子" NOR);
	set("gender", "男性");
	set("age", 40);
	set("long",
            "他是黄药师的四弟子，是桃花岛四大弟子\n"
	    "“陈、梅、曲、陆”中的曲灵风，最得\n"
            "黄药师宠爱，资质最好，功夫也最高，\n"
            "琴棋书画无所不能。他看起来二十多岁，\n"
	    "相貌俊美，面如冠玉， 中等身材。\n" 
	);
	set("attitude", "peaceful");

	set("str", 20);
	set("con", 20);
	set("int", 20);
	set("dex", 20);
	set("per", 28);

	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("max_qi", 2000);
	set("max_jing", 1000);

	set("combat_exp", 500000);
	set("score", 20000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
	


        set_skill("force", 110);
	set_skill("bihai-shengong", 110);
    set_skill("luoying-xinfa", 120);
        set_skill("dodge", 110);
        set_skill("baguabu", 110);
        set_skill("strike", 100);
        set_skill("luoying-zhang",110);
        set_skill("hand",100);
        set_skill("fuxue-shou", 110);
        set_skill("parry", 110);
        set_skill("sword", 100);
        set_skill("yuxiao-jian", 100);
        set_skill("literate", 50);
        set_skill("qimen-bagua", 100);

        map_skill("force", "bihai-shengong");
        map_skill("dodge", "baguabu");
        map_skill("hand", "fuxue-shou");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
      ]));

        
        prepare_skill("hand","lanhua-shou");
        prepare_skill("strike", "luoying-zhang");

        create_family("桃花岛", 2, "大弟子");
        set("class", "平民");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}



void attempt_apprentice(object ob)  
{       
         if ((string)this_player()->query("family/family_name")=="桃花岛")
         {if (this_player()->query_skill("qimen-bagua",1)<50)
            { command("say 我门派不传之密奇门八卦,你领悟不够。");
             return;
             }
            else {command("say 好吧，我就代师傅收下你了。");
                 command("recruit " + ob->query("id"));
                 }
          }
         
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        	if((string)ob->query("gender")!="女性")
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"仆人" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"女仆" NOR);
			return;
		}
       
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        
        command("exert tanzhi " + target->query("id"));
}
