//bao.c
//by hehe
//2003.3.13

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("包不同",({"bao butong","bao","butong"}));
    set("title",RED"姑苏慕容"NOR + HIY"金凤庄庄主"NOR);
    set("nickname",HIW"包三先生"NOR);
  	set("long",
    "他就是慕容复的结拜兄弟姑苏慕容金凤庄的庄主。\n");
    set("gender", "男性");
    set("age", 30);
	set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("combat_exp", 500000);
    set("shen_type", 1);
    set("attitude", "peaceful");
	set("max_qi",1000);
    set("max_jing",2000);
    set("neili",3000);
    set("max_neili",3000);
	set("jiali",50);
	set("score", 10000);

    set_skill("cuff", 140);
	set_skill("finger", 140);
	set_skill("sword", 140);
	set_skill("blade", 140);
	set_skill("parry",140);
	set_skill("dodge", 140);
	set_skill("force",140);
         set_skill("literate",140);
          set_skill("xingyi-zhang",70);
          set_skill("strike",70);
	set_skill("canhe-zhi",140);
	set_skill("murong-daofa",140);
	set_skill("murong-jianfa",140);
	set_skill("yanling-shenfa",140);
    set_skill("shenyuan-gong",140);
	set_skill("douzhuan-xingyi",140);
	set_skill("douzhuan-xingyi",140);

	map_skill("parry","douzhuan-xingyi");
	map_skill("parry","douzhuan-xiongyi");
	map_skill("finger","canhe-zhi");
	map_skill("sword","murong-jianfa");
	map_skill("blade","murong-daofa");
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
          map_skill("strike","xingyi-zhang");

	prepare_skill("finger","canhe-zhi");
	setup();
         carry_object("/d/murong/npc/obj/shoes1")->wear();
         carry_object("/d/murong/npc/obj/cloth")->wear();
    create_family("姑苏慕容",3,"弟子");
    set("inquiry", ([
		"name" : "非也，非也，我就是姑苏慕容金凤庄庄庄主包不同。\n",
        "here" : "这里是大名鼎鼎的燕子坞，难道你没有听说过？\n",
        "rumors" : "慕容公子的以彼之道，还施彼身天下闻名。\n",
        "阿珠" : "阿珠住在听香水榭，是慕容公子的贴身丫鬟，跟阿碧两个人一同侍奉公子。\n",
        "阿碧" : "阿碧姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。\n",
        "王语嫣" : "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。\n",
        "邓百川" : "邓百川是我大哥，是燕子坞青云庄的庄主。\n",
        "公孙乾" : "公孙乾是我二哥，是燕子坞赤霞庄的庄主。\n",
        "风波恶" : "风波恶是我四弟，是燕子坞玄霜庄的庄主，他就是喜欢跟别人打架。\n",
        "听香水榭" : "听香水榭是阿珠姑娘住的地方，离这里不远。\n",
        "琴韵小筑" : "琴韵小筑是阿碧姑娘住的地方，坐小舟有三九水路就到了。\n",
        "曼佗罗山庄" : "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。\n",
        "还施水阁" : "这是燕子坞的秘密之所在，我可不便对你说。\n",
	]));
    set("chat_chance",5);
    set("chat_msg",({
		"包不同道：“语嫣姑娘真是天下无不知，那天真是让我开了眼界。”\n",
		"包不同道：“阿朱姑娘喜欢收集房子旁边花朵上的露水，莫非是想喝，非也非也...”\n",
	}));
}
void attempt_apprentice(object ob)
{
    if((string)ob->query("family/family_name")!="姑苏慕容")
	{

	command("say 这位" + RANK_D->query_respect(ob) + "还是先去拜阿碧、阿朱吧！\n");
	return;
	}
    else if ((int)ob->query_skill("shenyuan-gong", 1) < 60)
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练神元功？");
		return;
	   }
	else
	{
		command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
		command("recruit "+ob->query("id"));

		return;
	}

}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
	        if(ob->query("gender")=="男性")
        		ob->set("title",RED"姑苏慕容"NOR + HIB"庄丁"NOR);
        	else if(ob->query("gender")=="女性")
        		ob->set("title",RED"姑苏慕容"NOR + HIB"婢女"NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
      	}
        return;
}
