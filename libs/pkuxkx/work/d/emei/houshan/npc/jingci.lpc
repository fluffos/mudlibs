//
//create bye cuer
//modifed by Zine Em newbie job
inherit NPC;
#include "/d/emei/bonus.h"
#include <ansi.h>
int peiyao();
int liandan();
int ask_job();
int ask_fail();
int ask_finish();
void create()
{
        set_name("静慈师太", ({
                "jingci shitai",
                "jingci",
                "shitai",
        }));
        set("long",
                "她是一位和蔼的中年师太。\n是负责管理药王洞的人。\n据说对配药和炼制霹雳弹颇有造诣。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set("score", 100);
		set("bonus",2);
        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("yanxing-dao", 100);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yanxing-dao");
        prepare_skill("blade", "yanxing-dao");
        
        create_family("峨嵋派", 4, "弟子");

        set("inquiry",([
            "配药" : ( : peiyao :),
            "霹雳弹" : ( : liandan : ),
            "help" : (: ask_job :),
            "帮助" : (: ask_job :),
            "fail" : (: ask_fail :),
            "失败" : (: ask_fail :),
            "finish": (: ask_finish :),
            "完成": (: ask_finish :),
             ]));

        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/cloth")->wear(); 
}

int ask_fail()
{
	object me=this_player();
	object ob=this_object();
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->is_busy()||ob->is_fighting())
	{
		tell_object(me,ob->name()+"正忙着呢。\n");
		return 1;
	}
	if (me->query("family/family_name")!="峨嵋派")
	{
		command("say 阁下不是峨嵋派弟子，请回吧。");
		return 1;
	}
	if (!me->query("emnewbiejob/start"))
	{
		command("say 我没有给你任务啊，你是不是记错了？");
		return 1;
	}
	if (me->query("emnewbiejob/jingci/start"))
	{
		punish(me);
		command("say 既然如此，罢了。");
		command("sigh");
		me->delete("emnewbiejob/start");
        me->delete("emnewbiejob/jingci/start");
		me->delete_temp("emnewbiejob");
		return 1;
	}
	else
	{
		command("say 谁交给你的任务，就找谁去放弃吧。");
		return 1;
	}
}

int ask_finish()
{
    object ob=this_object();
    object me=this_player();
    object cy;
    if (me->query("family/family_name")!="峨嵋派")
    {
        command("say 外派弟子？");
        return 1;
    }
    if (!me->query_temp("emnewbiejob/jingci/start"))
    {
        command("say 我没给过你任务。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("emnewbiejob/jingci/task")==1)
    {
        if (!present("caoyao",me))
        {
            tell_object(me,"你做好的药剂呢？\n");
            return 1;
        }
        cy=present("caoyao",me);
        if (!cy->query("is_caoyaoed")||cy->query("owner")!=me->query("id"))
        {
            command("say 这个我不需要，你自己留着吧。");
            return 1;
        }
        else
        {   
            tell_object(me,"你交给"+ob->name()+"一件"+cy->name()+"。\n");
            command("say 不错不错，这样就对了。"); 
			bonus(me);
			me->delete("emnewbiejob/start");
            me->delete("emnewbiejob/jingci/start");
            me->delete_temp("emnewbiejob");//奖励
            destruct(cy);
            return 1;
        }
    }
    if (me->query_temp("emnewbiejob/jingci/task")==2)
    {
        if (!present("pili dan",me))
        {
            tell_object(me,"你做好的霹雳弹呢？\n");
            return 1;
        }
        cy=present("pili dan",me);
        if (!cy->query("is_pilidan")||cy->query("owner")!=me->query("id"))
        {
            command("say 这个我不需要，你自己留着吧。");
            return 1;
        }
        else
        {   
            tell_object(me,"你交给"+ob->name()+"一件"+cy->name()+"。\n");
            command("say 不错不错，这样就对了。"); //奖励
            bonus(me);
			me->delete("emnewbiejob/start");
            me->delete("emnewbiejob/jingci/start");
            me->delete_temp("emnewbiejob");//奖励
            destruct(cy);
            return 1;
        }
    }
    else
    {
        command("say 我没给过你任务。");
        return 1;
    }
}
int ask_job()
{
    object ob=this_object();
    object me=this_player();
    int n;
    object tool;
    string * taskname=({"配药","霹雳弹"});
    if (me->query("family/family_name")!="峨嵋派")
    {
        command("say 外派弟子？");
        return 1;
    }
    if (!me->query_temp("emnewbiejob/jingci/start"))
    {
        command("say 我这里暂时不需要人，你去别处看看吧。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢\n");
        return 1;
    }
    if (me->query_temp("emnewbiejob/jingci/task"))
    {
        command("say 快去快回。");
        return 1;
    }
    n=random(sizeof(taskname));
    me->set("emnewbiejob/jingci/start",1);
    me->set_temp("emnewbiejob/jingci/task",n+1);
    if (n==0)
    {
        command("say 近年峨嵋弟子从我这里拿的药材极多，已经有点入不敷出，你去帮我配药吧。");
        command("say 草药在后山可以找到(search)，在这里门口晒干(shai)后分拣(fenjian)出合适的，再回到这里捣药(daoyao)就可以了。");
    }
    if (n==1)
    {
        command("say 近年峨嵋弟子大量需求霹雳弹，已经有点入不敷出，你去帮我做一点吧。");
        command("say 拿着我这把小铲子，在后山山洞铲(chan)一些硫磺粉，在前山花园铲一些硝石粉，灌(guan)入这个小球里就可以制成霹雳弹了。");
        tool=new(__DIR__"obj/xiaochan");
        tool->move(me);
        message_vision("$N给了$n一把小铲子。\n",ob,me);
        tool=new(__DIR__"obj/xiaoqiu");
        tool->move(me);
        message_vision("$N给了$n一个小木球。\n",ob,me);
    }
    return 1;
}


int peiyao()
{
 object me = this_player();
 object ob = this_object();
 object obj;
 int i;     
 if(!objectp(present("caoyao 3",me)))
 {command("say 你的身上没有那么多草药。");
  return 1;
 }
 for(i=0;i<3;i++)
  {
   obj=present("caoyao",me);
   destruct(obj);
  }
 command("smile");
 command("say 好吧，我就给你配药了。");
 obj=new(__DIR__"obj/zhongyao");
 obj->move(me); 
 message_vision("静慈师太给$N一包中药。\n",me); 
 return 1;
}

int liandan()
{
 object me = this_player();
 object ob = this_object();
 object obj;
 int i;     
 if(!objectp(present("liu huang",me)))
 {command("say 你的身上没有炼制霹雳弹用的硫磺。");
  return 1;
 }
 obj=present("liuhuang",me);
 destruct(obj);
 command("smile");
 command("say 好吧，我就给你炼制一粒霹雳弹。");
 obj=new(__DIR__"obj/pilidan");
 obj->move(me);    
 message_vision("静慈师太给$N一粒霹雳弹。\n",me); 
 return 1;
}
