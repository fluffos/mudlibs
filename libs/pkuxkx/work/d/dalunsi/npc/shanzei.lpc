// jianxi.c Zine 明教新手任务


#include <ansi.h>
inherit NPC;
void create()
{
        set_name("独狼",({"du lang","lang","wolf"}));
        set("race","野兽");
        set("long","这是一匹独行的巨狼，应该害了不少人的性命。\n");
        set("attitude","hateful");
        set("limbs",({"头部", "身体", "前脚", "后脚", "尾巴"}));
        set("verbs", ({ "bite", "claw", "hoof" }) );
        set("random_npc",1);
        set("age", 11);
        set("shen_type", -1);
        set("str", 50);
        set("int", 10);
        set("con", 50);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 10);
        set("combat_exp", 100000);
        set("is_xinan_block_lang",1);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
       
        setup();
        call_out("dest",600);
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
    }
}

int keep_moving(object ob,object me)
{
    object env,nextroom;
    if (!environment(ob))
    {
        return 1;
    }
    else
    {
        env=environment(ob);
    }
    if (base_name(env)=="/d/dalunsi/muchang8")
    {
        nextroom=load_object("/d/dalunsi/muchang9");
    }
    else if (base_name(env)=="/d/dalunsi/muchang9")
    {
        nextroom=load_object("/d/dalunsi/muchang8");
    }
    else
    {
        dest();
    }
    message_vision(HIW+"$N心生怯意，渐渐不敌，赶紧向"+nextroom->query("short")+"离去，$n紧紧跟上。\n"+NOR,ob,me);
    tell_room(nextroom,"却见一狼一人前后冲了过来。\n");
    ob->move(nextroom);
    me->move(nextroom);
    ob->kill_ob(me);
    me->kill_ob(ob);
    return 1;
}

void die()
{
        object ob,obj,me;
        int i,num;
	    string gem;
        ob = this_object();
        me = ob->get_damage_origin_object();
	if (ob->query("owner") != me->query("id"))
	{
		::die();
		return;
	}
    if (ob->query("killed")<1)
    {
        ob->add("killed",1);
        ob->set("eff_jing", query("max_jing"));
        ob->set("eff_qi", query("max_qi"));
        ob->set("qi", query("max_qi"));
        ob->set("jing", query("max_jing"));
        keep_moving(ob,me);
        return;
    }
    if (!ob->query("rewarded"))//防止各种情况导致npc失去心跳而不断刷奖励 Zine
    {
        message_vision("$N惨叫一声，转眼不能活了。\n",ob);
        obj = new("/obj/gem/gem");
	    i = random(20);
	      if (i < 3) gem = "yan";
        else if (i < 6) gem = "mu";
        else if (i < 9) gem = "sui";
        else if (i < 12) gem = "jin";
        else if (i < 15) gem = "bing";
        else if (i < 16) gem = "gu";
        else if (i < 17) gem = "yu";
        else if (i < 18) gem = "jiao";
        else gem = "jia";
	    obj->set_level(1,9800,gem);    
	    obj->move(ob);
        message_vision("$N把$n开膛破肚，却发现它体内有一颗"+obj->query("name")+"，也不知是何人之物，恐怕是被它连人带物囫囵吞下。\n",me,ob);
        ob->set("rewarded",1);
    }
    ::die();
}

void unconcious()
{
	die();
}


