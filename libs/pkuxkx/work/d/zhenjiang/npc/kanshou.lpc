//made by goodtaste
// data: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_hobby();
#include "/d/song/obj/askmap.h"
void create()
{
	set_name("库房看守", ({ "kanshou"}));
        
	set("long",
	"他是一名藩库的看守。\n"
         );
	
	set("gender", "男性");
	
	set("age", 30);
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
	set("loc","镇江");
    set("inquiry", ([
			"进仓" : (: ask_quest :),
            "开仓" : (: ask_quest :),
            "kaicang" : (: ask_quest :),
            "兴趣" : (: ask_hobby :),
            "hobby" : (: ask_hobby :),
       	]) );    
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();

}

int ask_hobby()
{
    object ob=this_object();
    object me=this_player();
   
    if (me->query_temp("jn/step5a"))
    {
        command("say 其实你别看我只是一个看守，我最爱看的就是书画了，尤其最推崇的是山水画。\n");
        tell_object(me,"你心生一计，也许找到画笔和纸张，自己随便在北面山画一幅风景，也能把他唬住。\n");
        tell_object(me,"你依稀记得，梦溪园里似乎有人在兜售画笔和纸张。\n");
        me->delete_temp("jn/step5a");
        me->set_temp("jn/step5b",1);
		return 1;
    }
    else
    {
        command("say 爷的兴趣爱好是看门！\n");
        return 1;
    }
}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
   
    if (!me->query_temp("jn/step5c"))
    {
        command("say 开仓？你在搞笑吗？百姓死活关我什么事？\n");
		return 1;
    }
    else
    {
        tell_object(me,ob->query("name")+"面有难色。\n");
        command("say 好吧，让你进去吧。\n");
        me->delete_temp("jn/step5c");
        me->set_temp("jn/step5d",1);
		return 1;
    }
}

int dest(object hua,object me)
{
    if (hua)
    {
        destruct(hua);
    }
    command("say 这莫不是范宽的《溪山行旅图》？\n");
    command("say 有这样的真迹，你让我干嘛都可以！\n");
    me->delete_temp("jn/step5b");
    me->set_temp("jn/step5c",1);
    return 1;
}


int accept_object(object me, object hua)
{
    
    if (this_object()->is_busy() || this_object()->is_fighting())
    {
        tell_object(me,this_object()->query("name")+"正忙着呢！\n");
        return 1;
    }
	if( hua->query("id") != "shanshui hua")
	return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    if( hua->query("owner") != me->query("id"))
	return notify_fail(this_object()->query("name")+"道：这，这？这也太烂了吧？\n");
	if (!me->query_temp("jn/step5b"))
    return notify_fail(this_object()->query("name")+"道：这是什么玩意？\n");
    
    me->add_busy(1);
    this_object()->add_busy(1);
    
    
	call_out("dest",1,hua,me);
	return 1;
}