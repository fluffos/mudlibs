// Zine 江南quest
#include <ansi.h> 
inherit NPC; 

int ask_drug();
void create()
{
	set_name("苗人", ({ "miao ren","ren"}));
        
	set("long",
	"他是一个苗人，一看就不是善茬，最好不要招惹。\n"
         );
	
	set("gender", "男性");
	
	set("age", random(10)+45);
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
    set_temp("mlnopoison",1);
	set("combat_exp", 650000+random(100000));
	set("uni_target", 1);
    set("inquiry", ([
			"drug" : (: ask_drug :),
            "毒" : (: ask_drug :),
            "毒药" : (: ask_drug :),
            
       	]) );    
        setup();
        carry_object("/d/city/obj/cloth")->wear();

}

int ask_drug()
{
    object ob=this_object();
    object me=this_player();
    object drug;
    if (me->query_temp("jn/step4e"))
    {
        me->delete_temp("jn/step4e");
        me->set_temp("jn/step4f",1);
        tell_object(me,ob->query("name")+"交给你一瓶毒药。\n");
        drug=new("/d/miaojiang/obj/drug");
        drug->set("owner",me->query("id"));
        drug->move(me);
        tell_object(me,"苗人一转眼不见了。\n");
        destruct(ob);
		return 1;
    }
    else
    {
        command("slash");
		return 1;
    }
}


int visible(object ob)
{
    if(query("uni_target") != ob) return 0;
    return 1;
}