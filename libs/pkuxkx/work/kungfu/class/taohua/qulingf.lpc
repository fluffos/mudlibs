// qulingf.c -黄药师

#include <ansi.h>
#include <title.h>
inherit NPC;

#include "/new_quest/qzhongli.h"
#include "/new_quest/quest.h"
int ask_bagua();
void consider();

void create()
{
	set_name("曲灵风", ({ "qu lingfeng", "lingfeng", "qu" }) );

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

	set("str", 30);
	set("con", 35);
	set("int", 30);
	set("dex", 10);
	set("per", 28);

	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("max_qi", 2000);
	set("max_jing", 1000);

	set("combat_exp", 1500000);
	set("score", 20000);
        set("chat_chance_combat", 100);
        set_temp("bagua",1);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
	


        set_skill("force", 180);
	set_skill("bihai-shengong", 210);
        set_skill("dodge", 190);
        set_skill("baguabu", 150);
        set_skill("strike", 200);
        set_skill("luoying-zhang",185);
        set_skill("hand",100);
        set_skill("fuxue-shou", 110);
        set_skill("parry", 210);
        set_skill("sword", 180);
        set_skill("yuxiao-jian", 180);
        set_skill("literate", 100);
        set_skill("qimen-bagua", 120);

        map_skill("force", "bihai-shengong");
        map_skill("dodge", "baguabu");
        map_skill("hand", "fuxue-shou");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
        "铁八卦":   (: ask_bagua :),
      ]));

        
        prepare_skill("hand","fuxue-shou");
        prepare_skill("strike", "luoying-zhang");

        create_family("桃花岛", 2, "大弟子");
        set("class", "平民");

        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/city/obj/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}



void attempt_apprentice(object ob)  
{       
         if ((string)this_player()->query("family/family_name")=="桃花岛")
         {if (this_player()->query_skill("qimen-bagua",1)<60)
            { command("say 我门派不传之密奇门八卦,你领悟不够。");
             return;
             }
            if (this_player()->query_skill("bihai-shengong",1)<70)
            { command("say 我门派碧海神功,你还差得很远。");
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
        {
        	if((string)ob->query("gender")!="女性")
      			ob->set("title",RED "桃花岛" NOR + HIW +" 第三代弟子" NOR);
	        else
      			ob->set("title",RED "桃花岛" NOR + YEL +" 第三代弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));    
    		}
       
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        
        command("exert tanzhi " + target->query("id"));
}
int ask_bagua()  
{       
       object ob;
       if ((string)this_player()->query("family/family_name")=="桃花岛"){
               if (this_player()->query_skill("qimen-bagua",1)<30){ 
                      command("say 我门派不传之密奇门八卦,你领悟不够。\n");
                      return 1;
                }
                else{
                      if( query_temp("bagua")<1 ){
                            command("say 铁八卦已经交给你的"+(random(2)?("师兄"):("师姐"))+"了，你找他要吧。\n ");
                            return 1;
                      }
                      add_temp("bagua", -1);
                      ob=new(__DIR__"obj/bagua");
                      ob->move(this_player());
                      command("say 好吧，你拿去好好练功吧。\n");
                      return 1;
                }
        }         
        command("say 你与我派素无往来,问这干啥？\n");
        return 1;
}
