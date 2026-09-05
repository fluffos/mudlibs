//近身太监
//by Zine
inherit NPC;
#include <ansi.h>
int ask_enter();
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title", HIM"东厂守卫"NOR);
	    set("gender", "无性");
        set("age", 20);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 1000000);
        set("asked",0);
        set_skill("force", 150);
        set_skill("jiuyin-shengong", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
	    set_skill("hand",140);
	    set_skill("pipa-shou",140);
        set_skill("feitian-shenfa", 140);
        set_skill("literate",20);
        map_skill("force", "jiuyin-shengong");
        map_skill("parry", "pipa-shou");
        map_skill("dodge", "feitian-shenfa");
        map_skill("hand","pipa-shou");
	    set("inquiry", ([
	
         "入内": (: ask_enter :),
         "enter": (: ask_enter :),
       
        
        ]));
        setup();
       
}

int ask_enter()
{
    object me=this_player();
    if (me->query("mingpin"))
    {
        me->set_temp("东厂进入",1);
        command("say 大人今天怎么有空来了？快请进。");
        return 1;
    }
    if (me->query("ming/tj/pin"))
    {
        me->set_temp("东厂进入",1);
        tell_object(me,"东厂守卫给你打开了门，娘娘地说道：进去吧，好姐妹\n");
        return 1;
    }
    else
    {
        tell_object(me,"东厂守卫说：这不是你应该来的地方，走吧。\n");
        return 1;
    }
}

void unconcious()
{
    die();
    return;
}

void die()
{
    object ob=this_object();
    object sw;
    if (base_name(environment(ob))=="/d/yingtianfu/neicheng/dongchang")
    {
        sw=new(__DIR__"dongchang-shouwei");
        message_vision("$N大声道：有人袭击东厂衙门，快来人呐！\n",ob);
        message_vision("一个守卫匆匆忙忙赶了过来。\n",ob);
        sw->move(environment(ob));
        ::die();
    }
    else
    {
        ::die();
    }
}
    
