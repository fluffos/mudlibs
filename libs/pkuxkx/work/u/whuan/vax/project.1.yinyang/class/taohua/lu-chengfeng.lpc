#include <ansi.h>
inherit NPC;
inherit F_QUESTMASTER;
void create()
{
set_name("陆乘风",({"lu chengfeng","lu","chengfeng"}));
    set("nickname",HIC"仗义行侠"NOR);
    set("title",GRN"归云庄"NOR+YEL"庄主"NOR);
    set("long","他是一位威风凛凛，面容冷峻的人.\n");
    set("gender","男性");
    set("age",54);
    set("attitute", "peaceful");
    set("shen-type", 1);
    set("str", 25);
    set("int", 28);
    set("con", 30);
    set("dex", 29);
    set("max_qi", 3000);
    set("qi", 3000);
    set("max_jing", 1500);
    set("jing", 1500);
    set("max_neili", 2000);
    set("neili", 2000);
    set("jiali", 150);
    set("combat_exp", 400000);
    set_skill("force", 100);
    set_skill("bihai-shengong", 120);
    set_skill("luoying-xinfa", 120);
    set_skill("dodge", 100);
    set_skill("luoying-shenfa", 120);
    set_skill("parry",100);
    set_skill("sword",100);
    set_skill("yuxiao-jian",120);
    set_skill("hand",100);
    set_skill("fuxue-shou",120);
    set_skill("finger",100);
    set_skill("literate",100);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("parry","yuxiao-jianfa");
     map_skill("sword","yuxiao-jian");
    map_skill("hand","fuxue-shou");
 prepare_skill("hand","fuxue-shou");
    create_family("桃花岛",2,"弟子");
    setup();
	  carry_object("/d/guiyunzhuang/npc/obj/lvshan")->wear();
	  carry_object("/d/guiyunzhuang/npc/obj/cleansword")->wield();
    set("chat_chance",5);
    set("chat_msg", ({
"我自从建立[归云庄]以来,从没享受过人间福分,如今人过半百,真是[岁月似水]啊!\n",
"师傅当年苦苦教我武功,如今报答他恩师的唯一方法只有把桃花岛武功发扬光大.\n"}));
}
void attempt_apprentice(object ob)
{
    if((string)ob->query("family/family_name")!="桃花岛")
    {
	command("say我不收外派弟子");
	command("say"+RANK_D->query_respect(ob)+"要想拜派,可先拜我儿陆冠英.\n");
	return;
    }
    if((int)ob->query_skill("bihai-shengong",1) < 30)
    {
command("say " + RANK_D->query_respect(ob) + "是否应该在碧海神功上多下功夫？");
	return;
    }
    if((int)ob->query("shen") < 0)
    {
	command("say 多行不义必自毙。");
	command("say " + RANK_D->query_respect(ob) + "师傅最恨那些小人了，我不想让师傅生气，你还是请回吧。");
	return;
    }
    if((int)ob->query("betrayer") > 1)
    {
	command("say " + RANK_D->query_respect(ob) + "还是请回吧。师傅恨死叛徒了。");
	return;
    }
if((string)ob->query("gender")==("无性"))
      {
      command("say 你的碧海神功火候不够，无法领悟我的高深武功。 ");
      command("say " + RANK_D->query_respect(ob) + "还是请回吧。");
      return;
  }
    command("say 好吧" + RANK_D->query_respect(ob) + "我就收下你了。 \n");
    command("recruit "+ob->query("id"));
    if((string)ob->query("gender")==("男性"))
        this_player()->set("title",GRN"桃花岛"NOR+YEL"善使"NOR);
	else
	   this_player()->set("title",GRN"桃花岛"NOR+YEL"女善使"NOR);
     
}
void init()
{
         object ob=this_player();
         mapping fam;
add_action("give_wsquest","quest");
    ::init();
	if((int)ob->query("shen")<-10000&&(string)ob->query("family/master_id")=="lu chengfeng")
         {
         command("say 你又在败坏师傅的名声，我要为师傅清理门户。 \n");
	command("expell "+ob->query("id"));
         }
         if ((int)ob->query("PKS")>3&&(string)ob->query("family/master_id")=="lu chengfeng")
         {
         command("say 我师傅虽然人称黄老邪，可桃花岛的人从不乱杀人。 ");
         command("expell " + ob->query("id"));
         }
	if(present("hanxiu cao",this_player())&&(string)ob->query("family/master_id")=="lu chengfeng")
	{
		command("expell "+ob->query("id"));
		command("say  你居然敢偷吃"GRN"含羞草"NOR",我怎可容你,你师兄王铁就因此被我逐出师门。\n");
	}
	if(present("shouyin",this_player()))
	{
		this_object()->set_leader(ob);
               this_object()->kill_ob(ob);
               ob->fight(this_object());
	}
}
void heal()
{    
     object ob=this_player();
     if(ob->query("eff_qi") < ob->query("max_qi"))
     {
     command("exert heal");
     command("enforce 100");
     return;
     }
     if(ob->query("qi") < ob->query("eff_qi"))
     {
     command("exert recover");
     return;
     }
     if(ob->query("jing")<ob->query("max_jing"))
     {
     command("exert regererate");
     return;
     }
}
