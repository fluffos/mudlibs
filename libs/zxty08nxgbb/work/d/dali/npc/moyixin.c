// moyixin.c 莫一心
inherit NPC;
int ask_me();
string ask_me1();
#include <ansi.h>
void create()
{
    set_name("莫一心", ({ "mo yixin", "mo", "yixin" }));
    set("title", "药铺老板");
    set("gender", "男性");
    set("long", "他就是医术高超的莫一心。可是他性格古怪，不是什么人都医的。\n");
    set("age", 65);
    set("int", 30);
    
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("shen_type", 0);
    set("combat_exp", 500000);
    set("attitude", "heroism");
    set_skill("unarmed", 80);
    set_skill("dodge", 80);
    set_skill("parry", 60);
    set_temp("apply/attack", 70);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 50);
        set("inquiry", ([
    "治病":(:ask_me:),
    "神药": (: ask_me1 :),
    "潜能丹": (: ask_me1 :)
        ]) );
    setup();
    add_money("gold", 1);
    carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

string value_string(int value)
{
    if( value < 1 ) value = 1;
    else    if( value < 100 )
        return chinese_number(value) + "文钱";
    else    if( value < 10000 )
        return chinese_number(value/100) + "两白银"
            + (value%100? "又" + chinese_number(value%100) + "文钱": "");
    else
        return chinese_number(value/10000) + "两黄金"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "两白银" : "")
            +( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文钱": "");
}
int ask_me()
{
        object ob;
    mapping inv;
    string str,*cond;
    int i;
        ob=this_player(); 
    inv=ob->query_conditions();
       if (((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
         && ((int)this_player()->query("eff_jing") == (int)this_player()->query("max_jing"))
    && !sizeof(inv)){
                command("say 我给你打量几眼,呃,你现在不需要治病!");
        return 1;
    }
        tell_object(ob, "\n莫一心抬头看了你几眼。\n");
    str="";
    if (sizeof(inv)){
        cond=keys(inv);
        for (i=0;i<sizeof(inv);i++){
            if (cond[i]=="drunk")
            str+="看你脸红红的，一定是喝醉了！";
            if (cond[i]=="killer"){
                command("say 官府正通缉你呢，你还是快走吧！");
                return 1;
            }
    }
    if (str==""){
        command("say 中了什么毒吧？我可不会治！");
                return 1;
    }
    ob->set_temp("count",sizeof(inv)*10);
    }
        if ( (int)this_player()->query("eff_qi") < (int)this_player()->query("max_qi") )
        {
             ob->add_temp("count",5); 
             str+="呃,你真气受了点损伤! \n";
         }
    if ( (int)this_player()->query("eff_jing") < (int)this_player()->query("max_jing") )
        {
                 ob->add_temp("count",5);
                 str+="呃,你精元受了点损伤! \n";
        }            
        str+="有"+value_string(1000* ob->query_temp("count"))+"吗？先给钱，后治病！ \n";
        command("say "+str);
                return 1;
}
int accept_object(object who, object ob)
{
    if (who->query_temp("count"))
        if (ob->query("money_id") && ob->value() >= who->query_temp("count")*1000){ 
                who->set("eff_qi",who->query("max_qi"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("eff_gin",who->query("max_gin"));
                who->apply_condition("drunk",0);
                tell_object(who, "莫一心拿出些药丸给你服下，不一会，你的气色看起来好多了。\n");
            who->set_temp("count",0);
                return 1;
            }  else
                tell_object(who, "莫一心冷冷一笑：你的诚意不够，还是请回吧！\n");
    return 0;
}
string ask_me1()
{
    return "我...我不知道！";
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
