// randomnpc.c 随机npc

inherit NPC;
#include <ansi.h>
string* names = ({
"地痞","流氓","泼皮","无赖","乞丐",
});
string* ids = ({
"di pi","liu mang","po pi","wu lai","qi gai",
});

void create()
{
        int i=random(5);
        set_name(names[i], ({ ids[i]}));
        set("gender", "男性");
        set("age", 25+random(20));
        set("long", "他长得奸嘴猴腮的，一看就不像是个好人。\n");        
        set("combat_exp", 7000+random(50000));
        set("shen_type", -1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20+random(100));
        set_temp("apply/defense", 20+random(100));
        set("inquiry", ([
        "name" : "小名不足挂齿！", 
        "here" : "不知道！", 
        "rumors" : "你问错人了！", 
        ]) );
        set("chat_chance",10);
        set("chat_msg", ({
//                (: random_move :),
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
