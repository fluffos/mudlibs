// ma.c 马善均

inherit NPC;
#include <title.h>
// inherit F_MASTER;
#include <ansi.h>
#include "/new_quest/qzhengpai.h"
#include "/new_quest/quest.h"

void create()
{
	set_name("马善均", ({ "ma shanjun", "ma","shanjun" }));
	set("title", HIR "红花会"HIG"分舵舵主" NOR);
	set("long", 
"此人老成持重，是红花会杭州分舵的舵主，有很多事情可以直接向他汇报。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 19);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("combat_exp", 500000);

	set_skill("literate", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 80);

	set_skill("bingchuan-xinfa", 80);
	set_skill("zhuangzi-mengwu", 80);
	set_skill("luojia-dao", 80);
	
	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
	map_skill("blade", "luojia-dao");
	map_skill("parry", "luojia-dao");

	set("env/wimpy", 20);
	create_family("红花会", 4, "弟子");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        add_action("do_baoxin", "baoxin");
}

int do_baoxin()
{
        object me = this_player();
        object ob;
        
        if (me->query_temp("hhh_wt1") != 1)
        	return 0;
        
        if (me->query_temp("hhh_wt1") == 1)
        	write(HIW"你向马善均报告了发现文泰来行踪的消息。\n"NOR);
        	write(HIW"马善均紧握你手说道：大侠，太感谢你了，是不宜迟，快去向总舵主汇报。\n"NOR);
        	write(HIR"马善均从怀里拿出一朵大红花送给你，说：带着这个才能进红花会。拜托了。\n"NOR);
        	me->set_temp("hhh_wt1",2);
        	ob = new("/d/hangzhou/obj/honghua");
          ob->move(this_player());
          
          return 1;
      	
}
        
void attempt_apprentice(object ob)
{
	command("say whuan说红花会还在调试中，暂不开放！");
	return;
	if (((string)ob->query("family/family_name") != "红花会" && (int)this_player()->query("combat_exp")>100 )&&(int)this_player()->query("reborn/chushi")<1)
         {   
                  command("say 我派只收无家可归的孤儿。");
            return;
        }

        if((int)ob->query("betrayer")>=2)
        {
            command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
            return;
        }
        else if ((string)ob->query("gender")=="无性")
        {
            command("say 朝廷阉狗，我派岂能收你");
            return;
        }
           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (ob->query("age")<20)
                {
                        ob->set("title",HIR "红花会" NOR + HIY +"娃娃兵" NOR);
//title系统记录玩家title by seagate@pkuxkx
	                      ob->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"娃娃兵" NOR);
                        return;
                }
                else
                {
                        ob->set("title",HIR "红花会" NOR + HIY +"小队长" NOR);
//title系统记录玩家title by seagate@pkuxkx
	                      ob->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"小队长" NOR);
                        return;
                }
}
void re_rank(object student)
{
                if (student->query("age")<20)
                {
                        student->set("title",HIR "红花会" NOR + HIY +"娃娃兵" NOR);
//title系统记录玩家title by seagate@pkuxkx
	                      student->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"娃娃兵" NOR);
                        return;
                }
                else
                {
                        student->set("title",HIR "红花会" NOR + HIY +"小队长" NOR);
//title系统记录玩家title by seagate@pkuxkx
	                      student->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"小队长" NOR);
                        return;
                }
}

