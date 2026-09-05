inherit NPC;
#include <ansi.h>
#include <combat.h>
string* types = ({"水蟒","闪电貂"});
string* ids = ({"shui mang","light diao"});
string* races = ({"野兽","野兽"});
string* items = ({"shedan","diaopi"});

void create()
{
    set_name("野兽",({"monster"}));
    setup();
}

void attack()
{
    string type = query("type");
    object* enemies = query_enemy();
    object ob;
    int level = query("level");
    string msg;
    
    if(!arrayp(enemies) || sizeof(enemies) == 0)
    {
        remove_call_out("attack");
        call_out("attack",1);          
        return;
    }
    ob = enemies[random(sizeof(enemies))];    
    if(type == "水蟒")
    {
        if(level>random(20))
        {
            message_vision("水蟒卷起粗长的身躯，把$N紧紧的缠绕起来。\n",ob);    
            ob->add_busy(2);
        }
    }
    else if(type == "闪电貂")
    {        
        if(level>random(20))
        {
            message_vision("闪电貂迅疾无比，$N错愕之间，已经连连受挫。\n",ob);   
            msg = "$N一口咬向$n的$l\n"; 
            COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"), TYPE_REGULAR,msg);
            msg = "$N一爪攻向$n的$l\n"; 
            COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"), TYPE_REGULAR,msg);
            msg = "$N狠狠的抓向$n的$l。\n"; 
            COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"), TYPE_REGULAR,msg);
        }        
    }
    remove_call_out("attack");
    call_out("attack",3);    
}

void smart_fight()
{
    if(is_busy()) return;
    if(query("qi") < query("eff_qi"))
    {
        command("exert recovery");
    }    
    
    if(query("eff_qi") < query("max_qi"))
    {
        command("exert heal");
    } 
       
}
void init_me()
{
 
    
    //等级从1开始，对应50w exp，每一级增加5M exp    
    string item;
    int type = random(2);
    int level = query("level");    
    int baseexp = 500000;
    int stepexp = 5000000;     
    int exp =  baseexp + (level-1)*stepexp;
    object ob;
           
    
    seteuid(getuid());
    set("combat_exp",exp);
    set_skill("unarmed",level*100);
    set_skill("parry",level*100);
    set_skill("dodge",level*100);
    set_skill("force",level*100);
    set_skill("chuforce",level*100);
    map_skill("force","chuforce");
    
    set("max_neili",1500*level);
    set("neili",1500*level);
    set("max_qi",1500*level);
    set("eff_qi",1500*level);
    set("qi",1500*level); 
    set("chat_combat_chance",80);
    set("chat_combat_msg",
        ({(:smart_fight:)}));
        
    set_name(types[type],({ids[type],"monster"}));
    set("type",types[type]);
    set("race",races[type]);
    set("jiaofei/maze/monster",1);
    item = items[type];
    
    set("age",level*10);
    
    ob = new(__DIR__"obj/"+item);    
    ob->set("value",random(level*20000));    
    ob->move(this_object());
    
    
    
    remove_call_out("attack");
    call_out("attack",1);
    
}

//一晕倒就死，这样靠别人帮忙难了
void unconcious()
{
    die();
}

void die()
{
    object ob = get_damage_origin_object();
    int exp,pot;
    int tmp;
    float f;
    if(objectp(ob) && userp(ob))
    {
        message_vision("$N哀鸣一声，死了。",this_object());
        tmp = ob->query("combat_exp") - query("combat_exp");
        if(tmp > 0)
        {
            f = 1.0*tmp / (1.0*ob->query("combat_exp"));
            if(f>0.3)//player经验不能高于怪兽的30%
            {
                ::die();
                return;
            }
        }
        exp = query("level")*200;
        pot = query("level")*50;
        tell_object(ob,sprintf(YEL"你在战斗中获得了%d点经验和%d点潜能。"NOR,exp,pot));
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
   		ob->add("exp/zhaoze",exp);
   		ob->add("pot/zhaoze",pot);        
    }
    ::die();    
}
