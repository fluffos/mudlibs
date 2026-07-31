 inherit NPC;
#include <ansi.h>
void create()
{
        object armor;
        set_name(RED"红教喇嘛"NOR, ({ "red lama"}) );
        set("gender", "男性" );
        set("age", 40+random(10));
        set("int", 30);
        set("long",
                "红教高僧，受葛伦之托特来调查舍利子失踪之事。\n"
                );
        set("class","lama");
        set("combat_exp", 2500000);
        set("score", 900);
        set("fle",50);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",50);
        set("atman",2500);
        set("max_atman",2500);
        set("mana",4000);
        set("max_mana",4000);
        set("resistance/kee",30);
        set("class","lama");        
        set("chat_chance", 1);
        set("chat_msg", ({
                "红教喇嘛肃然说：舍利子一日不归布达拉宫，我们就一日不能安睡！\n",
                (: random_move :),
                }) );
        
        set_skill("iron-cloth", 200);
        set_skill("staff",150);
        set_skill("cloudstaff", 160);
        set_skill("unarmed",150);
        set_skill("bloodystrike", 150);
        set_skill("force", 80);
        set_skill("spells",150);
        set_skill("parry",140);
        
        if (random(2)) set_skill("jin-gang",100);
        
        map_skill("iron-cloth","jin-gang");
        map_skill("parry","cloudstaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        
        add_temp("apply/iron-cloth", 100);
        
        setup();
        armor=new(__DIR__"obj/redclothh");
        armor->set_name(RED"镶金滚边红袍"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}  
