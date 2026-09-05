//made by goodtaste
// data: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_debt();
void create()
{
	set_name("总管", ({ "guan"}));
        
	set("long",
	"他精打细算，深藏不露，还是小心为好．\n"
         );
	
	set("gender", "男性");
	
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
        set("qi", 1000);
        set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000+random(100000));
	set_skill("sword",120);
        set_skill("huashan-jianfa",100);
     	set_skill("force", 100);
	set_skill("taiji-shengong", 90);
	set_skill("dodge", 100);
	set_skill("huashan-shenfa", 100);
      set_skill("parry", 90);
      map_skill("sword","huashan-jianfa");
	map_skill("dodge","huashan-shenfa");
	map_skill("parry","huashan-jianfa");
	map_skill("force","taiji-shengong");
    set("inquiry", ([
			"quest" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
            "赌债" : (: ask_debt :),
            "debt" : (: ask_debt :),
       	]) );    
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();

}

int ask_debt()
{
    object ob=this_object();
    object me=this_player();
   
    if (me->query_temp("jn/step4a")&&me->query_temp("wagon/from")=="成都"&&me->query_temp("wagon/to")=="昆明")
    {
        command("say 你去帮我把神威镖局张崇威欠我的赌债讨(taozhai)回来。\n");
        me->delete_temp("jn/step4a");
        me->set_temp("jn/step4c",1);
		return 1;
    }
    if (me->query_temp("jn/step4c"))
    {
        command("say 快去找张崇威吧。\n");
		return 1;
    }
    if (me->query_temp("jn/step4d"))
    {
        command("say 这个家伙，真是不见棺材不落泪，不找人教训教训他是不行了。\n");
        command("whisper "+me->query("id")+" 苗岭有苗人高手擅长下毒，你帮我跟他要一包毒药。");
        command("whisper "+me->query("id")+" 从东门出去，就是苗岭山林，苗疆处处剧毒，不可在山林边缘却可找到一种黄色小草。");
        command("whisper "+me->query("id")+" 服食后，苗疆毒雾难侵。");
        command("whisper "+me->query("id")+" 进入苗岭后，要出来其实并不困难，所有一切都是障眼法，你只要一直向西走，但是变换wu,wd,w就可以了。");
        command("whisper "+me->query("id")+" 唯一要注意的是不要进入东面太深，不然就很难出来了。");
        me->delete_temp("jn/step4d");
        me->set_temp("jn/step4e",1);
        me->set_temp("jn/miaoren",1);
		return 1;
    }
}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
   
    if (me->query("jiangnanquest/step4"))
    {
        command("say 一日之后，据说镇江金山寺会有盛会。\n");
		return 1;
    }
    else
    {
        if (me->query_temp("jn/step4b"))
        {
            command("say 你去帮我把神威镖局张崇威欠我的赌债讨(taozhai)回来。\n");
            me->delete_temp("jn/step4b");
            me->set_temp("jn/step4c",1);
		    return 1;
        }
        else
        {
            command("say 我女儿一天到晚说找人来帮我，却一直没见到人。\n");
		    return 1;
        }
		return 1;
    }
}

int dest(object duyao,object me)
{
    int exp=random(400);
    if (duyao)
    {
        destruct(duyao);
    }
    me->add("combat_exp",exp);
    tell_object(me,HIW+sprintf("你回忆起在西南的经历。\n你的经验增加了%d点。\n",exp)+NOR);
    tell_object(me,"恭喜：你已经完成了江南八镇Quest————西南篇！\n");
    me->set("jiangnanquest/step4",1);
    me->set("jiangnanquest/conntime",time());
    me->delete_temp("jn");
    return 1;
}


int accept_object(object me, object duyao)
{
    
    if (this_object()->is_busy() || this_object()->is_fighting())
    {
        tell_object(me,this_object()->query("name")+"正忙着呢！\n");
        return 1;
    }
	if( duyao->query("id") != "miaoren duyao")
	return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    if( duyao->query("owner") != me->query("id"))
	return notify_fail(this_object()->query("name")+"道：这是你找来的吗？\n");
	if (!me->query_temp("jn/step4f"))
    return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    
    me->add_busy(1);
    this_object()->add_busy(1);
    
    
	call_out("dest",1,duyao,me);
	return 1;
}