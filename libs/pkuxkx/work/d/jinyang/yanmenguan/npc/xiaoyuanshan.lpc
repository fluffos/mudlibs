//Zine xiaoyuanshan

#include <ansi.h>
inherit NPC;
void exer();
#include "yanmen_xiao_npc.h"
int check_for_start();
void create()
{ 
        set_name("萧远山",({"xiao yuanshan","xiao","yuanshan"}));
        set("long","他是大辽的一名军将。\n");
        set("gender", "男性" );
        set("zyhb", 1);
        set("age", 34);
        set("per",32);
        set("int",40);
        set("con",40);
        set("dex",40);
        set("str",40);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("max_qi", 150000);
        set("eff_qi", 150000);
        set("qi", 150000);
        set("max_jing", 30000);
        set("jing", 30000);
        set("neili", 50000);
        set("max_neili",50000);
        set("jiali", 200+random(200));        
        set("combat_exp", 10000000);
        set_skill("luohan-quan", 500);
        set_skill("literate",500);
        set_skill("cuff", 500); 
        set_skill("buddhism",2000);
        set_skill("dodge", 500);
        set_skill("finger",500);
        set_skill("yizhi-chan",500);
        set_skill("parry", 500);
        set_skill("force", 500);
        set_skill("yanqing-quan",500);
        set_skill("yanling-shenfa", 500);
        set_skill("hunyuan-yiqi", 500);
        set_skill("shenyuan-gong",500);
        set_skill("canhe-zhi",500);
        set_skill("halberd",500);
        set_skill("leizhendang",500);
        set_skill("jiuyin-shengong",500);
        map_skill("force","jiuyin-shengong");
        map_skill("finger","canhe-zhi");
        map_skill("cuff", "luohan-quan");  
        map_skill("dodge","yanling-shenfa");
        map_skill("parry","canhe-zhi");
        map_skill("halberd","leizhendang");
        prepare_skill("cuff", "luohan-quan");
        set("chat_chance_combat", 150);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("yanmen_npc",1);
        set("medicine",10);
        set("family/family_name","少林派");
        set("yanqing",1);
        set_temp("yanmen/permit",1);
        set("special_skill/chainless", 1);
        set("special_skill/might", 1);
        set("special_skill/energy",1);
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        carry_object("/clone/weapon/fangtianji")->wield();
        carry_object("/clone/weapon/fangtianji")->wield();
        call_out("check_for_start",1);
}

int goodbye()
{
    object ob=this_object();
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object env=environment(ob);
    object *all_user=all_inventory(env);
    object xiao,mrs_xiao,guanjia,jiading,yahuan;
    string *list=ctrl->query("list");
    xiao=ctrl->query("yanmen/xiao");
    mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    guanjia=ctrl->query("yanmen/guanjia");
    jiading=ctrl->query("yanmen/jiading");
    yahuan=ctrl->query("yanmen/yahuan");
    command("say 人手不足啊，还是不要让我夫妇的事连累了大家。");
    command("wave");
    message_vision("$N转身离去。",xiao);
    message_vision("$N转身离去。",mrs_xiao);
    message_vision("$N转身离去。",guanjia);
    message_vision("$N转身离去。",jiading);
    message_vision("$N转身离去。",yahuan);
    destruct(mrs_xiao);
    destruct(guanjia);
    destruct(jiading);
    destruct(yahuan);
    destruct(xiao);
    return 1;
}

int init_move(object xiao,object mrs_xiao,object guanjia,object jiading,object yahuan)
{
    xiao->check_for_moving();
    xiao->check_status();
    mrs_xiao->check_for_moving();
    mrs_xiao->check_status();
    guanjia->check_for_moving();
    guanjia->check_status();
    jiading->check_for_moving();
    jiading->check_status();
    yahuan->check_for_moving();
    yahuan->check_status();
}

int check_for_start()
{
    object ob=this_object();
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object env=environment(ob);
    object *all_user;
    object xiao,mrs_xiao,guanjia,jiading,yahuan,high_player;
    string *list=ctrl->query("list");
    int high_exp,i,rollcall=0;
    if (env)
    {
        all_user=all_inventory(env);
    }
    xiao=ctrl->query("yanmen/xiao");
    mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    guanjia=ctrl->query("yanmen/guanjia");
    jiading=ctrl->query("yanmen/jiading");
    yahuan=ctrl->query("yanmen/yahuan");
    high_exp=(int)ob->query("combat_exp");
    for (i=0;i<sizeof(all_user);i++)
    {
        if (userp(all_user[i])&&all_user[i]->query_temp("yanmen/permit"))
        {
            rollcall+=1;
        }
        if (all_user[i]->query("combat_exp")>high_exp)
        {
            high_exp=(int)all_user[i]->query("combat_exp");
            high_player=all_user[i];
        }
    }
    if (rollcall>=8||ob->query("wiz_test"))
    {
        command("say 既然人已经到齐了，那么有劳各位壮士护送我夫妇了。");
        message_vision("$N准备开始过雁门关了。\n",ob);
        xiao->do_copy(high_player);
        mrs_xiao->do_copy(high_player);
        guanjia->do_copy(high_player);
        jiading->do_copy(high_player);
        yahuan->do_copy(high_player);
        mrs_xiao->syn_for_xiao();
        guanjia->syn_for_xiao();
        jiading->syn_for_xiao();
        yahuan->syn_for_xiao();
        call_out("init_move",60,xiao,mrs_xiao,guanjia,jiading,yahuan);
        return 1;
    }
    call_out("check_for_start",1);
    return 1;
}

void exer()
{
    object *enemy,target,weapon,weapon2;
    object obj;
    object ob=this_object();
    if (!living(this_object()))
    return;
    command("exert recover");
    command("special chainless");
    if (!ob->query("might"))
    {
        ob->query("might",1);
        command("special might");
    }
    command("qudu");
    enemy = query_enemy();
    target = enemy[random(sizeof(enemy))];
	weapon = this_object()->query_temp("weapon");
    weapon2 = this_object()->query_temp("secondary_weapon");
    command("exert powerup");
    command("exert yihun "+target->query("id"));
	if (!weapon)
    {
        obj=new("/obj/gem/weapon");
        obj->gen_weapon(8,9900,9999,"halberd");
        obj->move(this_object());
        command("wield all");
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
        weapon->set("no_drop_to_room",1);
    }
    if (!weapon2)
    {
        obj=new("/obj/gem/weapon");
        obj->gen_weapon(8,9900,9999,"halberd");
        obj->move(this_object());
        command("wield all");
        weapon2 = this_object()->query_temp("secondary_weapon");
        weapon2->set("no_get",1);
        weapon2->set("no_drop_to_room",1);
    }
    switch( random(5) )
        {
            case 0:
            command("wield all");
            command("perform halberd.leishen " +target->query("id"));
            break;
            
            case 1:
            command("unwield all");
            command("prepare none");
            command("enable finger yizhi-chan");
            command("prepare finger");
            command("perform finger.jingmo " +target->query("id"));
            command("wield all");
            break;  
            
            case 2:
            command("unwield all");
            command("prepare none");
            command("enable finger canhe-zhi");
            command("prepare finger");
            command("perform finger.canshang");
            command("wield all");
            break;
            case 3:
            command("unwield all");
            command("prepare none");
            command("enable cuff yanqing-quan");
            command("prepare cuff");
            command("perform cuff.yanqing " +target->query("id"));
            command("wield all");
            break;
            case 4:
            command("unwield all");
            command("prepare none");
            command("enable finger canhe-zhi");
            command("prepare finger");
            command("perform finger.dianxue " +target->query("id"));
            command("wield all");
            break;
        }
           
}

int chalu(object ob)
{
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object env=environment(ob);
    object mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    if (environment(mrs_xiao)==env)
    {
        command("consider");
        command("say 前方岔路变多，我和夫人还是兵分两路分散追兵，比较好。");
    }
}

int continue_move()
{
    object ob=this_object();
    object env=environment(ob);
    if (env&&env->query("road_no")==1)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==2)
    {
        command("south");
    }
    if (env&&env->query("road_no")==3)
    {
        command("south");
    }
    if (env&&env->query("road_no")==4)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==5)
    {
        command("southeast");
    }
    if (env&&env->query("road_no")==6)
    {
        command("south");
        call_out("chalu",1,ob);
    }
    if (env&&env->query("road_no")==7)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==8)
    {
        command("south");
    }
    if (env&&env->query("road_no")==10)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==12)
    {
        command("south");
    }
    if (env&&env->query("road_no")==14)
    {
        command("west");
    }
    gene_enemy(ob);
    ob->set("yanmen/last_go",time());
}

