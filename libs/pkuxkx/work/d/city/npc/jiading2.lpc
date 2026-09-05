// jiading.c 家丁

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

int do_setwinner(string arg);
int ask_reward();
void give_reward(object me);

string query_save_file()
{
    return "/data/jiaoji/jiading";
}

void create()
{
	set_name("家丁", ({ "jia ding", "jia" }));
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 4000);      
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	set("shen_type", 1);
	set("accept_fight",0);
	set("no_get",1);
	restore();
	set("inquiry",([
	    "奖励":(: ask_reward :),
	    ]));	
	setup();	
}

void unconcious()
{
    die();
}

void die()
{
    fullme();
}

void init()
{
    if(wizardp(this_player()))
    {
        add_action("do_setwinner","win");
    }
//    add_action("do_none","perform");
}

int do_none()
{
    return 1;
}

void relay_message(string msgclass, string msg)
{
    object room;
    room = load_object("/d/city/jiaoji_kantai");
    if(objectp(room) && room != environment(this_object()))
    {
        msg = replace_string(msg,"你",query("name"));
        msg = "【较技场】" +  msg;
        tell_room(room,msg);
    }
}

int do_setwinner(string arg)
{
    if(!wizardp(this_player()) || !stringp(arg) || sizeof(arg) == 0) return 0;
    this_object()->set("winner",arg);
    this_object()->set("time",time());
    shout(HIG+"正气山庄："+NOR+"本次较技的最终获胜者是:"+HIY+arg+NOR+"!!!\n");
    save();
    return 1;
}

int ask_reward()
{
    object me = this_player();    
    
    if(me->query("family/family_name") == query("winner") && time() - query("time") < 5*86400 && 
        me->query(sprintf("jiaoji/getreward/%d",query("time"))) != 1)
    {
        me->delete("jiaoji/getreward");
        me->set(sprintf("jiaoji/getreward/%d",query("time")),1);
        me->save();
        give_reward(me);        
        return 1;
    }    
    
    return 0;
}

void give_reward(object me)
{
    mapping skills;
    string* sname;
    string skill_rw;
    int exp_rw = me->query("combat_exp")/20+100;
    int pot_rw = me->query("level")*1000+50;
    skills  = me->query_skills();
    if(sizeof(skills) > 0)
    {
        sname = keys(skills);    
        skill_rw = sname[random(sizeof(sname))];
        me->set_skill(skill_rw, me->query_skill(skill_rw, 1)+1);        
        write(HIC"你的「"+CHINESE_D->chinese(skill_rw)+"」进步了！\n"NOR);			        
    }
    
    me->add("combat_exp",exp_rw);
    me->add("potential",pot_rw);
    
    
    write(sprintf("你的经验提升了%d点。\n",exp_rw));
    write(sprintf("你的潜能增加了%d点。\n",pot_rw));
    
}