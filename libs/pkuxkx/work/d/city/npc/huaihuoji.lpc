// holder
// created by Zine 30 Sep 2010

inherit NPC;
#include <ansi.h>

int ask_yao();

void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title",CYN"卷走林震南财物的伙计"NOR);
	set("gender", "男性" );
	set("long", "一个贼眉鼠眼的家伙。\n");
	set("str", 20);
	set("int", 20);
	set("dex", 20);
	set("kar", 20);       
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("eff_jingli", 10);
	set("neili", 10);
	set("max_neili", 10);
	set("jiali", 200);
	set("shen_type", 1);
    
	
	set("combat_exp", 10000);
    set("inquiry", ([
            
			"要" : (: ask_yao :),
            "yao" : (: ask_yao :),
			"财物" : (: ask_yao :),
			"treasure" : (: ask_yao :),
			
			
            
       	]) );
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	call_out("dest",180);
    
}

int ask_yao()
{
    object me=this_player();
    object ob=this_object();
    object caiwu;
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if(query("owner") != me->query("id"))
    {
    	return notify_fail(this_object()->query("name")+"很疑惑地问你：请问阁下是丐帮的吗？\n");
    }
    else
    {
        if (random(10)>6)
        {
            return notify_fail(this_object()->query("name")+"很疑惑地问你：请问阁下是丐帮的吗？\n");
        }
        else
        {
            caiwu=new(__DIR__"obj/caiwu");
            if (caiwu)
            {
                caiwu->set("owner",me->query("id"));
                caiwu->move(me);
                message_vision(this_object()->query("name")+"把一包财物砸向你，一转眼不见了。\n",ob);
                if (ob)
                {
                    destruct(ob);
                }
            }
            return 1;
        }
    }
}


int dest()
{
	tell_room(environment(),this_object()->query("name")+"一闪身就不见了。\n");
	destruct(this_object());
	return 1;
}

