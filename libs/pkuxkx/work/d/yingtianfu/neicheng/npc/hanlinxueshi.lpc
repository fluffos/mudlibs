//翰林学士 Zine 

#include <ansi.h>
inherit NPC;
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"

int ask_task();
int ask_finish();
void create()
{
    set_name("翰林学士", ({"hanlin xueshi", "xueshi","shi"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的翰林学士。\n");
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
     
	
	]));

    setup();
   
}

int ask_task()
{
    object me=this_player();
    object ob=this_object();
    string *book=({"史记","汉书","后汉书","三国志","晋书","宋书","南齐书","梁书","陈书","魏书","北齐书","周书","隋书","南史","北史","旧唐书","新唐书","旧五代史","新五代史","宋史","辽史","金史"});
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/hanlinyuan/start"))
    {
        if (me->query_temp("mingtasks/hanlinyuan/target"))
        {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
        }
        n=random(sizeof(book));
        message_vision("$N看着$n，捻须笑道：我翰林院正在修撰元史，需要二十二史作为参考，你去找一本"+book[n]+"回来吧。\n",ob,me);
        tell_object(me,"扬州天月书肆、北京荣宝斋、成都青羊宫、洛阳望星楼、晋阳南市、岳阳洞庭湖附近经常有人卖书。\n");
        me->set_temp("mingtasks/hanlinyuan/book",book[n]);
        me->set_temp("mingtasks/hanlinyuan/target",n+1);
        me->set_temp("mingtasks/hanlinyuan/initime",time());
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/hanlinyuan/start"))
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
        command("say 你只是一个芝麻小官，恐怕不能胜任。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/hanlinyuan/target"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(book));
		if (me->query("mingpin")<4)
		command("say 我翰林院正在修撰元史，需要二十二史作为参考，大人如能找到一本"+book[n]+"，不胜感激。");
		else
        message_vision("$N看着$n，捻须笑道：我翰林院正在修撰元史，需要二十二史作为参考，你去找一本"+book[n]+"回来吧。\n",ob,me);
        tell_object(me,"扬州天月书肆、北京荣宝斋、成都青羊宫、洛阳望星楼、晋阳南市、岳阳洞庭湖附近经常有人卖书。\n");
        me->set_temp("mingtasks/hanlinyuan/book",book[n]);
        me->set_temp("mingtasks/hanlinyuan/target",n+1);
        me->set_temp("mingtasks/hanlinyuan/initime",time());
        return 1;
    }
}

int dest(object book)
{
	if(book)
	destruct(book);
	return 1;
}

int accept_object(object me, object book)
{
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/hanlinyuan/start") 
        &&book->query("ming/history")==me->query_temp("mingtasks/hanlinyuan/target")&&
        time()-me->query_temp("mingtasks/hanlinyuan/initime")<=900)
    {
        me->add_busy(1);
	    call_out("dest",1,book);
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/hanlinyuan/start"))
        return notify_fail("我说过要你帮忙吗？\n");
	if( time()-me->query_temp("mingtasks/hanlinyuan/initime")>900)
	    return notify_fail("你未免也太慢了吧？大伙都收工了你才回来。\n");
	if (book->query("ming/history")!=me->query_temp("mingtasks/hanlinyuan/target"))
	    return notify_fail("你找回来的是"+me->query_temp("mingtasks/hanlinyuan/book")+"吗？\n");
	message_vision("翰林学士接过$N手里的"+book->query("name")+"，翻了几页，连道：不错不错，就是它了。\n",me);
	me->add_busy(1);
	call_out("dest",1,book);
    command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
    me->delete_temp("mingtasks");
    me->add("ming/credit",6+random(5));
	return 1;
}