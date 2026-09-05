#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
void heal();
void create()
{
        set_name("李秋水", ({ "li qiushui", "li" }));
        set("title",MAG "天山" NOR + BLK "童老" NOR );
        set("long",
                "她脸上蒙着一块丝巾，隐隐约约可以发现有几道纵横交错的伤痕。\n"
		+"有人说她就是当年令正派人士深恶痛绝的天山童姥，但从身材上\n"
		+"看又和传说有点不符，但从来也没人敢向她询问这件事情。\n");

        set("gender", "女性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 8000);
        set("qi",10000);
        set("max_jing", 10000);
        set("jing",10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 200);
        set("combat_exp", 15000000);
        set("score", 800000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        set("inquiry", ([
            
                "丁春秋" :
                "你问他干吗，他是我的师侄",
                    ]) );
        set_skill("force", 500);
        set_skill("huagong-dafa", 350);
        set_skill("dodge", 500);
        set_skill("zhaixinggong", 500);
        set_skill("strike", 500);
        set_skill("xingxiu-duzhang", 500);
        set_skill("xiaowuxiang-gong", 500);
        set_skill("hand", 500);
        set_skill("zhaixing-shou", 500);
     set_skill("sword",500);
     set_skill("mintian-jiushi",500);
        set_skill("parry", 500);
        set_skill("staff", 500);
        set_skill("tianshan-zhang", 500);
     	set_skill("literate", 200);
        map_skill("force", "xiaowuxiang-gong");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "tianshan-zhang");
 map_skill("sword","mintian-jiushi");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
	create_family("星宿派",1,"毒姑");
        set("class", "taoist");
        setup();
        carry_object("/d/xingxiu/obj/bingpozhang")->wield();
}
void init()
{
        object me;
        me=this_player();
if ((int)me->query("shen") >=0 && (string)me->query("family/master_id")=="li qiushui")
        {
                command("say 你多次杀我同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ me->query("id"));
        }
}
void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100000) {
                command("say 我越看你越象白道派来卧底的。");
                return;
        }
        if ((int)me->query("score") < 1500)
                {
                message_vision("李秋水露出一副不信任的样子. \n", me);
                command("say 你对本门尽心了吗？");
            return;
        }
	if((int)me->query_skill("tianshan-zhang",1)<120)
		{command("say 你是否应该在天山杖上多下点功夫.\n");
		return;
	}
    if((int)me->query_skill("huagong-dafa",1)<130)
		{command("say 你是否应该在化功大法上多下点功夫.\n");
		return;
}

		
  
        command("recruit " + this_player()->query("id"));
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",HIR "星宿派" NOR + GRN +"魔头" NOR);
        else
                this_player()->set("title",HIR "星宿派" NOR + GRN +"毒姑" NOR);
}
     
     

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(3) )
        {
            case 0:
            command("perform parry.handu " + target->query("id"));
             break;
            case 1:
            command("unwield zhang");
            command("perform strike.sandu " +target->query("id"));
            command("wield zhang");
             break;
            command("exert shield");
            command("exert powerup");
            case 0:
             break;
             }
}
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert lifeheal li qiushui");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}
