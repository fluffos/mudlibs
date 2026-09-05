//翰林学士 Zine 

#include <ansi.h>
inherit NPC;
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int askforhelp();
int ask_task();
int ask_finish();
void create()
{
    set_name("太医院使", ({"taiyi yuanshi", "yuanshi","shi"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的太医院使。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",4);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
    set("chat_chance", 5);
        set("chat_msg", ({
                
                (:askforhelp:),
        }) );
    
	set("inquiry", ([
	
     "帮助": (: ask_task :),
     "help": (: ask_task :),
     
	
	]));

    setup();
    carry_object("/d/yingtianfu/neicheng/obj/guanyin2");
}

int askforhelp()
{
    if (random(100)>95)
    {
        command("daming 太医院研究出的经络图，与前人认识大不相同，可提高修炼内功的效率。\n");
    }
        
}

int ask_task()
{
    object me=this_player();
    object ob=this_object();
    string *drug=({"鸡血藤","薄荷","鱼腥草","常山","当归","丁香","茯苓","覆盆子","合欢","荆芥","地骨皮","蛇床子","生甘草"});
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/taiyiyuan/start"))
    {
        if (me->query_temp("mingtasks/taiyiyuan/target"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(drug));
        message_vision("$N苦着脸，对$n道：我这里缺少药材，你去找一味"+drug[n]+"回来吧。\n",ob,me);
        me->set_temp("mingtasks/taiyiyuan/drug",drug[n]);
        me->set_temp("mingtasks/taiyiyuan/target",n+1);
        
        return 1;
    } 
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/taiyiyuan/start"))
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
    if (me->query_temp("mingtasks/taiyiyuan/target"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(drug));
		if (me->query("mingpin")<4)
		command("say 我这里缺少药材，大人能帮我找一味"+drug[n]+"吗？");
		else
        message_vision("$N苦着脸，对$n道：我这里缺少药材，你去找一味"+drug[n]+"回来吧。\n",ob,me);
        me->set_temp("mingtasks/taiyiyuan/drug",drug[n]);
        me->set_temp("mingtasks/taiyiyuan/target",n+1);
        
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
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/taiyiyuan/start")
        &&book->query("drugcode")==me->query_temp("mingtasks/taiyiyuan/target")) 
    {
        me->add_busy(1);
	    call_out("dest",1,book);
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/taiyiyuan/start"))
        return notify_fail("我说过要你帮忙吗？\n");
	
	if (book->query("drugcode")!=me->query_temp("mingtasks/taiyiyuan/target"))
	    return notify_fail("你找回来的是"+me->query_temp("mingtasks/taiyiyuan/book")+"吗？\n");
	message_vision("太医院使接过$N手里的"+book->query("name")+"，放在鼻边嗅嗅，高兴地道：不错不错，就是它了。\n",me);
	me->add_busy(1);
	call_out("dest",1,book);
    command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
    me->delete_temp("mingtasks");
    me->add("ming/credit",2+random(10));
	return 1;
}