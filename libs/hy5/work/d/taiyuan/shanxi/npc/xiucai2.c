// hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
 
void create()
{
        set_name("樊大", ({ "mr fan", "fan da" }) );
        set("gender", "男性" );
        set("age", 52);
        set("str", 30);
        set("str", 99);
        set("cor", 40);
        set("cps", 1);
        set("no_busy", 99);
                 set("reward_npc", 1);
        set("difficulty", 10);

        set("class","quanli");
            set("resistance/kee",99);
    set("resistance/sen",99);
    set("resistance/gin",99);

    set("long",
"一个穿着长袍戴着小帽的老人，蹲在里面抽旱烟。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("force",100);
        set_skill("unarmed",999);
        set_skill("dodge",99);


        
        
        //set_skill("tangforce",100);
        //set_skill("blade",180);
        //set_skill("tang-blade",180);        

        //set("skill_public",1);

        //map_skill("force", "tangforce");
        set("chat_chance", 1);
        set("chat_msg", ({
                "那老人悠悠闲闲的坐在那里，好像一直要坐到天亮的样子。\n",
                //"青枫道人凄然而笑，“这一子摆下，黑棋就不输了。”\n",  
                //"青枫道人忽然挥袖拂乱了这局残棋，悠悠慨叹，“人生岂非，也正如一局棋．输瀛又何必太认真呢？”\n",
        }));
        //set("skill_public", 1);

        setup();
           carry_object("/clone/misc/cloth")->wear();

        carry_object(__DIR__"obj/hanyan")->wield();
        
} 

int wieldblade()
{
//command("wield hanyan");
perform_action("dagger.pingshuixiangfeng");
//command("unwield piece");
return 1;
}
