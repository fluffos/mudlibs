// File         : master.c
// Modified by  : kiden@pkuxkx

#include <ansi.h>
varargs void wield_weapon(string weapon);
void powerup();
void full_me();
inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
void die();

void create()
{
        set_name("武学大宗师", ({ "zong shi", "grand master"}) );
        set("gender", "男性" );
        set("age", 22+random(22));
        set("long", "他是镇守关卡的武学大宗师，想要出师得过了他这一关。\n");
        set("per",30);
        set("kar",30);
        set("str",30);
        set("con",30);
        set("dex",30);
        set("int",30);
        set("attitude", "peaceful");
        set("rank_info/respect", "老前辈");
        set("chat_chance_combat", 100);
        family_skill(this_object(), "shaolin", 700+random(100), 1);
        set("max_qi",  12000+random(3000));
        set("eff_qi",  12000+random(3000));
        set("qi",      12000+random(3000));
        set("max_jing",12000+random(3000));
        set("eff_jing",12000+random(3000));
        set("jing",    12000+random(3000));
        set("max_jingli",12000+random(3000));
        set("jingli", 12000+random(3000));
        set("max_neili", 12000+random(3000));
        set("neili", 12000+random(3000));
        set("jiali",300);
        set("combat_exp",60000000+random(20000000));
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        wield_weapon();
}

void init()
{
//        command("look "+this_player()->query("id"));
        if (environment(this_object())->query("no_fight"))
        ::random_move();
}


void unconcious()
{
        die();
}

void die()
{
        object me = get_damage_origin_object();
        if(!objectp(me) || !present(me, environment()))
        {
                ::die();
                return;
        }
        message_vision("$N闯过了第一关。\n", me);
        me->add("combat_exp",100000);
        me->add("potential",10000);
        me->add("repute",1000);
        me->set("reborn/stage1",1);
        ::die();
}

int accept_fight(object ob)
{
    return 0;
}


void powerup()
{
        object me = this_object();
        CHANNEL_D->do_channel(this_object(), "bd", "addoil", 1);
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        return;
}

void full_me()
{
        object me = this_object();
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        return;
}


varargs void wield_weapon(string weapon)
{
        if(!weapon && query("use_weapon1"))
                wield_weapon(query("use_weapon1"));
        if(!weapon && query("use_weapon2"))
                wield_weapon(query("use_weapon2"));
        if(!weapon)
                return;
        switch(weapon)
        {
        case "sword":
                carry_object("/clone/weapon/changjian")->wield();
                break;
        case "blade":
                carry_object("/clone/weapon/gangdao")->wield();
                break;
        case "staff":
                carry_object("/clone/weapon/gangzhang")->wield();
                break;
        case "whip":
                carry_object("/clone/weapon/changbian")->wield();
                break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");                
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");                
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
        case "zhen":
                set("gender", "无性");
                carry_object("/d/city/obj/flower_shoe");
                carry_object("/d/city/obj/pink_cloth");
                carry_object("/d/city/obj/goldring");
                carry_object("/d/city/obj/necklace");
                carry_object("/d/quanzhou/obj/xiuhua")->wield();
                carry_object("/d/riyuejiao/obj/xiuhuajia");
                break;
        case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
                break;
        case "hammer":
                carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
                break;
        default:
                break;
        }
        return;
}

void start_busy(mixed new_busy, mixed new_interrupt)
{
        if(intp(new_busy) && new_busy > 15)

                ::start_busy(14+random(3));
}
