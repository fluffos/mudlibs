// Updated by Lonely


inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
        set_name(HIR"烈火孽龙"NOR, ({ "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 200);
        set("long", 
"这是一条全身赤红，吸天地之间的火气而长大的孽龙！
它全身散发着赤红色的火焰。\n");
        
        set("str", 248);
        set("con", 252);
        set("dex", 222);

        set("dodge", 999);
        set("force", 999);
        set("unarmed", 999);
        set("parry", 999);
        set("max_qi", 99999);
        set("max_jing", 99999);
        set("max_neili", 901000);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(30)+10);
        set("chat_msg_combat", ({
                (: big_blowing :)
        }) );

        set("combat_exp", 901100000+random(600110000));
        set("bellicosity", 30000 );
        
        set_temp("apply/attack", 1560+random(400));
        set_temp("apply/damage",1500+random(400));
        set_temp("apply/armor", 1500+random(400));

        setup();
} 
int big_blowing()
{
        remove_call_out("hurting");
        message_vision( HIR "\n\n烈火孽龙深深地吸入一口气，全身转为鲜红的火色，整个龙腹胀大了几倍！！\n\n" NOR,
                        this_object());
        call_out("hurting", random(1)+1);


        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n烈火孽龙吐出一股炽可焚金的火焰．．整个天地似乎都被燃烧着！！！\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
                dam = random(1000)+100;
                if(dam <0) dam = 0;
                inv[i]->receive_wound("qi",dam);
                COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
void die()
{
        object obj;
        object killer;
        int exp,userexp;
        
         if(objectp(killer=this_object()->query_last_damage_from()))
        {
                userexp=killer->query("combat_exp");
                exp=((int)killer->query("literate")*4)+random(10000)+40000+(userexp)/60000;
                obj = new("/quest/tulong/obj/drug");
                obj->move(killer, 1);
                obj = new("/quest/tulong/obj/drug");
                obj->move(killer, 1);

                if (!killer->query_temp("m_success/孽龙"))
                {
                        killer->set_temp("m_success/孽龙",1);
                        killer->add("combat_exp",exp);
                        killer->add("potential",20000);
                        message("channel:chat", HBMAG"【精灵神界】"+killer->query("name")+"成功地杀死了恶龙，解开了封印!得到经验无数经验和潜能.\n"NOR,users());
                }
                
                tell_object(killer, HIR "\n\n一团火焰猛地升腾，一个声音说道：谢谢你解开了第七个封印，这两颗龙元就作为谢礼吧！！！\n" NOR); 
                message_vision("一道红光从天而降，照耀着$N。\n", killer);
                tell_object(killer, HIM "\n忽然你发现你已经来到了一个陌生的房间\n" NOR);
                killer->move("/d/jyszhuang/mishi2");
                message_vision("红光退去，你突然发现好象少了一个人。\n", this_object());
        }
        message_vision("$N化作一缕清风而去。\n", this_object());
        destruct(this_object());
} 

