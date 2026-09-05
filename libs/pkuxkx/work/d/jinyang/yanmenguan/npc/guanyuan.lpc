//雁门关
//created by Zine 2 Aug 2011

#include <ansi.h>
inherit NPC;
int ask_job();

int *tester=({"juny","rippling","fflower","yhzzyahoo","ytywwqqt","betray","mimixiaojie","nol"});
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("gender", "男性" );
		set("title", HIR"大辽南院 "+HIW+"枢密使"NOR);
        set("age", 40+random(20));
        set("long", 
            "他就是大辽国掌南院枢密使"+this_object()->query("name")+"。\n");
        set("str", 30);
        set("dex", 30);
        set("con", 20);
        set("int", 60);
		set("shen_type", 1);
		set_skill("force", 50);
		set("combat_exp", 500000);
		set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
		set("uni_target",1);
		set("attitude", "friendly");
        set("inquiry", ([
            "萧远山" : "萧大人夫妇已经出发，听说有刺客行刺，真是让人担忧啊。",
			"job" : (: ask_job :),
            "护送" : (: ask_job :),
       	]) );
		
        setup();
        
		carry_object(__DIR__"obj/cloth")->wear();

}

int change_person(object me)
{
    object center=load_object("/d/jinyang/yanmenguan/center");
    object old_user;
    object env=environment(this_object());
    string *list=center->query("list");
    int i,j=0;
    if (time()-me->query("雁门关/lasttime")<5400)
    {
        tell_object(old_user,this_object()->name()+"权衡再三，这次机会还是让给别人吧。\n");
        return 1;
    }
    for (i=0;i<sizeof(list);i++)
    {
        old_user=find_player(list[i]);
        if (time()-old_user->query("雁门关/lasttime")<5400)
        {
            j=1;
            old_user->move(env);
            old_user->delete_temp("yanmen");
            tell_object(old_user,this_object()->name()+"权衡再三，这次还是让别人去做，你被顶替了。\n");
            tell_object(me,this_object()->name()+"道『我想了想，这次"+old_user->query("name")+"就不去了，你去保护萧大人吧。』\n");
            tell_object(me,this_object()->name()+"道：『你的武功尚可，希望能帮助萧大人平安过雁门关，从这里southeast就可以和萧大人汇合了。』\n");
            me->set_temp("yanmen/permit",1);
            return 1;
        }
    }
    if (j==0)
    {
        tell_object(old_user,this_object()->name()+"权衡再三，这次机会还是让给别人吧。\n");
        return 1;
    }
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    object center=load_object("/d/jinyang/yanmenguan/center");
    string *list;
    if (!wizardp(me)&&member_array(me->query("id"),tester)<0)
    {
        tell_object(me,ob->name()+"道：『萧大人不喜欢任何人参合他的事情。』\n");
        return 1;
    }
    if (!center->is_on())
    {
        tell_object(me,ob->name()+"道：『萧大人不喜欢任何人参合他的事情。』\n");
        return 1;
    }
    if (me->query_temp("yanmen/permit"))
    {
        tell_object(me,ob->name()+"道：『你不是问过我了，从这里southeast就可以和萧大人汇合了。。』\n");
        return 1;
    }
    if (center->query("yanmen/already_start"))
    {
        tell_object(me,ob->name()+"道：『萧大人已经动身了，恐怕这时候追不上他了。』\n");
        return 1;
    }
    if (me->query("combat_exp")<5000000)
    {
        tell_object(me,ob->name()+"道：『护送萧大人？依我看，你自己都需要别人护送吧。』\n");
        return 1;
    }
    if (!center->query("list"))
  	list=({});
    else
  	list=center->query("list");
    if (sizeof(list)>11)
    {
        tell_object(me,ob->name()+"道：『居然有这么多人？我来看看，从中选优吧，你稍等一下。』\n");
        call_out("change_person",2,me);
        return 1;
    }
    if (member_array(me->query("id"), list)<0 )
  	list+=({me->query("id")});
    center->set("list", list);
    me->set_temp("yanmen/permit",1);
    tell_object(me,ob->name()+"道：『你的武功尚可，希望能帮助萧大人平安过雁门关，从这里southeast就可以和萧大人汇合了。』\n");
    return 1;
}
void unconcious()
{
    die();
}

void die()
{
    object ob=this_object();
    message_vision("$N摇了摇头，似乎有什么难以理解的事情。\n",ob);
    ob->fullme();
    return;
}


