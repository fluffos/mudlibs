// robber for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void exer();
void create()
{ 
        set_name(HIM"蒙面人"NOR,({"Men In Black","killer"}));
        set("long","这是一位华山派弃徒。\n");
        set("title","拦路抢劫");
        set("gender", "男性" );
        set("age", random(30)+14);
        set("bonus",1);
        set("vendetta/authority", 1);
        set("no_use/qiankun-danuoyi",1);
        set("no_use/iron-cloth",1);       
        set("feilong",1); 
        set("busy",1);
        set("max_qi", 2000);
        set("eff_qi", 2000);
        set("qi", 900);
        set("max_jing", 900);
        set("jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("shen",-100);
        set("shen_type", -10);
        set("combat_exp", 500000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("huashan-jianfa", 300);
        set_skill("strike",300);
        set_skill("hunyuan-zhang",300);
        set_skill("cuff",300);
        set_skill("dodge", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("force",300);
        set_skill("huashan-neigong",300);
        set_skill("zixia-shengong",300);
        set_skill("huashan-shenfa",300);
        map_skill("sword","huashan-jianfa");
        map_skill("dodge","huashan-shenfa");
        map_skill("parry","huashan-jinfa");
        map_skill("strike","hunyuan-zhang");
        map_skill("force","zixia-shengong");
        prepare_skill("strike", "hunyuan-zhang");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
     
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("start_attact",1,this_object());
}
void exer()
{
        object *enemy,target,weapon;
        int i = random(50);
        
        command("exert powerup");
        command("exert recover");

        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
   
        if (target->query("jing")*100<target->query("max_jing")*30 || target->query("qi")*100<target->query("max_qi")*30)
if (1)
        {
                write(this_object()->query("name")+"越战越勇，一声长笑，招数加快十分，一把将"+target->query("name")+"打晕。随后带着逃之夭夭\n");
                target->unconcious();
                remove_call_out("hijack");
                call_out("hijack", 3, target);
                return;
        }

        if (this_object()->query("busy"))
                return;
        
        weapon = this_object()->query_temp("weapon");
        if (!weapon)
                carry_object("/d/pingxiwangfu/npc/obj/herosword")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);

        if (i < 1)
                command("perform sword.feilong " + target->query("id"));
        else if (i < 10)
                command("perform sword.jianzhang " +target->query("id"));
}

void hijack(object ob)
{
	object place = new("/u/zoom/work/death/death_room");
        ob->revive();
        ob->move(place);
        destruct(this_object());
}
