// randomnpc.c 随机npc

inherit NPC;
#include <ansi.h>
string* names = ({
"书生","刀客","剑客","豪客","镖客","僧人",
});
string* ids = ({
"shu sheng","dao ke","jian ke","hao ke","biao ke","seng ren",
});

void create()
{
        int i=random(6);
        set_name(names[i], ({ ids[i]}));
        set("gender", "男性");
        set("age", 25+random(20));
        set("long", random(2)?"他长得奸嘴猴腮的，一看就不像是个好人。\n":"他看起来器宇轩昂，让人很有好感！\n");        
        set("combat_exp", 7000+random(50000));
        set("shen_type", random(2)?-1:1);
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
                (: random_move :),
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
