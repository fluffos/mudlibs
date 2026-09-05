//鸿胪寺卿 Zine 

#include <ansi.h>
inherit NPC;

#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_task();
int ask_finish();
void create()
{
    set_name("鸿胪寺卿", ({"honglusi qing", "qing"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的鸿胪寺卿。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     "帮助": (: ask_task :),
     "help": (: ask_task :),
     "完成": (: ask_finish :),
     "finish": (: ask_finish :),
	
	]));

    setup();
   
}

int ask_finish()
{
    object me=this_player();
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/honglusi/finished"))
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 你不是大明官员，完成什么？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/honglusi/finished"))
    {
        command("say 你把国书送到哪里去了？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/honglusi/start"))
    {
        command("say 你确定在我这里接过活？\n");
        return 1;
    }
    if (time()-me->query_temp("mingtasks/honglusi/initime")>=300)
    {
        command("say 国事紧急，你却拖沓如此，还不退下领罚！\n");
        return 1;
    }
    else
    {
        command("jump");
        command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
        me->delete_temp("mingtasks");
        me->add("ming/credit",6+random(5));
        return 1;
    }
}

int ask_task()
{
    object me=this_player();
    object ob=this_object();
    object letter;
    string *country=({"大清","大理国","西夏国"});
    string *place=({"礼部府衙","大殿","皇宫正殿"});
    string *target=({"/d/beijing/libuyamen2","/d/dalicheng/wangfu4","/d/lingzhou/zhengdian"});
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/honglusi/start"))
    {
        if (me->query_temp("mingtasks/honglusi/target"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        letter=new("/d/yingtianfu/neicheng/obj/letter");
        n=random(sizeof(country));
        message_vision("$N从桌上拿出一封国书，郑重交给$n，道：我国欲与"+country[n]+"修好关系，你赶紧把这封国书递交(dijiao)到"+place[n]+"，不得有误。\n",ob,me);
        me->set_temp("mingtasks/honglusi/target",target[n]);
        me->set_temp("mingtasks/honglusi/tocountry",country[n]);
        me->set_temp("mingtasks/honglusi/initime",time());
        letter->set("owner",me->query("id"));
        letter->move(me);
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/honglusi/start"))
    {
        command("say 我这里暂时没有什么事，你去别的衙门看看哪里需要帮忙吧。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query("mingpin")>6)
    {
        command("say 你只是一个芝麻小官，派你出使，未免让人讥笑我大明无人。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/honglusi/target"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        letter=new("/d/yingtianfu/neicheng/obj/letter");
        n=random(sizeof(country));
		if (me->query("mingpin")<4)
		message_vision("$N从桌上拿出一封国书，郑重交给$n，道：我国欲与"+country[n]+"修好关系，大人请赶紧把这封国书递交(dijiao)到"+place[n]+"去。\n",ob,me);
		else
        message_vision("$N从桌上拿出一封国书，郑重交给$n，道：我国欲与"+country[n]+"修好关系，你赶紧把这封国书递交(dijiao)到"+place[n]+"，不得有误。\n",ob,me);
        me->set_temp("mingtasks/honglusi/target",target[n]);
        me->set_temp("mingtasks/honglusi/tocountry",country[n]);
        me->set_temp("mingtasks/honglusi/initime",time());
        letter->set("owner",me->query("id"));
        letter->move(me);
        return 1;
    }
}