 inherit NPC;
void smart_fight();
void smart_attack();  
void create()
{
       set_name("云松", ({ "yun song", "song" }) );
       set("nickname", "红衣喇嘛");
        set("gender", "男性" );
        set("age", 32);
        set("int", 30);
        set("class","lama");
        create_family("大昭寺", 21, "弟子");
        set("long",
        "云松乃是葛伦高僧的关门小弟子，修行甚勤。葛伦以之为门下\n"
        "众弟子榜样。\n"
                );
        set("chat_chance", 1);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("chat_msg", ({
                "云松叹了口气道：赤松大师兄，不知道现在怎么样了。。\n",
        }) ); 
        set("inquiry", ([
                "舍利子": "嗯....舍利子一定是我师妹胭松盗走的。\n",
                "胭松": "胭松在布达拉宫城的大招寺里。",
        ]) );
        set("attitude", "peaceful");
        set("mana",4000);
        set("max_mana",4000);
        

        set_skill("staff", 100);

        set_skill("unarmed", 100);
        set_skill("lamaism", 10);

        set_skill("force", 100);

        set_skill("spells",100);
        set_skill("parry",100);

        
        set("combat_exp", 1500000);
        

        setup();
        carry_object(__DIR__"obj/redclothh")->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}   
