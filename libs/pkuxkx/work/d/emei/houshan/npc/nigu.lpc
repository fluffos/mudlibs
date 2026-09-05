//
//create bye cuer
inherit NPC;
#include <ansi.h>
int ask_job();
int ask_finish();
int ask_fail();
#include "/d/emei/bonus.h"
void create()
{
        set_name("杂役尼姑", ({
                "zayi nigu",
                "za yi",
                "zayi",
				"nigu"
        }));
        set("long",
                "她是一位负责后山杂役的尼姑。\n"
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
		set("bonus",3);
        set("no_get",1);
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
        
        create_family("峨嵋派", 5, "弟子");

        set("inquiry",([
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
                               
int removeusing(object where)
{
    if (!where->query("using"))
    {
        return 1;
    }
    if (where->query("startdasao")&&find_player(where->query("startdasao")))
    {
        call_out("removeusing",60,where);
        return 1;
    }
    else
    {
        this_object()->add("room_count",-1);
        where->set("long",where->query("old_long"));
        where->set_temp("mixed_long",where->query("long"));
        tell_room(where,"这里又变得静悄悄的了。\n");
        where->delete("using");
        where->delete("startdasao");
        return 1;
    }
}
int ask_job()
{
    object me=this_player();
    object ob=this_object();
    object where,wh,saoba;
    int i;
    string desc;
	if (me->query("family/family_name")!="峨嵋派")
	{
		command("say 你不是我派弟子，我就不劳动你的大驾了。");
		return 1;
	}
    if (ob->query("room_count")>=3)
    {
        message_vision("$N道：此刻我不需要帮手，你迟点再来吧。\n",ob);
        return 1;
    }
    if (me->query("emnewbiejob/qingjie/start"))
    {
        message_vision("$N道：你上次说好帮我，还没完成呢。\n",ob);
        return 1;
    }
    while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
          where->query("using"))
        {where=TASK_D->random_room("/d/emei/houshan/");}
    if (!where)
    {
        message_vision("$N道：此刻我不需要帮手，你迟点再来吧。\n",ob);
        return 1;
    }
    where->set("using",1);
    where->set("old_long",where->query("long"));
    ob->add("room_count",1);
    for (i=0;i<random(10)+8;i++)
    {
        wh=TASK_D->random_place();
        if (!desc)
        {
            desc=wh->query("short");
        }
        else
        {
            desc=desc+wh->query("short");
        }
    }
    desc=desc+"\n";
    where->set("long",desc);
    where->set_temp("mixed_long",where->query("long"));
    call_out("removeusing",240,where);
    saoba=new(__DIR__"obj/saoba");
    saoba->set("owner",me->query("id"));
    saoba->move(me);
    me->set_temp("emnewbiejob/qingjie/where",base_name(where));
    me->set_temp("emnewbiejob/qingjie/task",1);
    me->set("emnewbiejob/qingjie/start",1);
    message_vision("$N道：好像有个家伙在我们后山范围乱涂乱画，你拿着我的扫把去把污迹打扫一下吧。\n",ob);
    tell_object(me,ob->name()+"给了你一把扫把，你可以去脏乱的地方打扫(dasao)一下。\n");
    return 1;
}
void unconcious()
{
    die();
}
void die()
{
    object ob=this_object();
    ob->fullme();
    message_vision("$N道：这年头，连杂役尼姑都有人暗杀！\n",ob);
    return;
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    object saoba;
    if (!me->query("emnewbiejob/qingjie/start"))
    {
        message_vision("$N道：我不记得我给过你什么任务了。\n",ob);
        return 1;
    }
	if (!me->query_temp("emnewbiejob/qingjie/finish"))
    {
        command("say 你清扫完毕了吗？");
        return 1;
    }
    if (!present("sao ba",me))
    {
        command("say 我的扫把你带回来了吗？");
        return 1;
    }
    saoba=present("sao ba",me);
    if (!saoba->query("is_saoba")||saoba->query("owner")!=me->query("id"))
    {
        command("say 你带回了我的扫把吗？");
        return 1;
    }
    else
    {
        ob->add("room_count",-1);
        command("smile"); //奖励
        command("say 太好了。"); 
        bonus(me);
		me->delete("emnewbiejob/start");
        me->delete("emnewbiejob/qingjie/start");
		me->delete_temp("emnewbiejob");
        destruct(saoba);
        return 1;
    }
}

int ask_fail()
{
    object me=this_player();
    object ob=this_object();
    object saoba,where;
    string roomname;
    if (!me->query("emnewbiejob/qingjie/start"))
    {
        message_vision("$N道：我不记得我给过你什么任务了。\n",ob);
        return 1;
    }
    if (present("sao ba",me))
    {saoba=present("sao ba",me);}
	punish(me);
    command("say 罢了，求人不如求己，我还是自己来吧。");
    if (me->query_temp("emnewbiejob/qingjie/where"))
    {
        roomname=me->query_temp("emnewbiejob/qingjie/where");
        where=load_object(roomname);
        removeusing(where);
    }
	me->delete("emnewbiejob/start");
    me->delete("emnewbiejob/qingjie/start");
    me->delete_temp("emnewbiejob");
    if (saoba&&saoba->query("is_saoba")&&saoba->query("owner")==me->query("id"))
    {destruct(saoba);}
    ob->add("room_count",-1);
    return 1;
}
