#include <ansi.h>
inherit NPC;
void create()
{
        set_name("青青", ({ "qing qing" }) );
        set("gender", "女性");
        set("age",25);
        set("env/wimpy",90);
        set("combat_exp", 1000000);
        set("long",
                "一个身材很苗条的女人，穿着身淡青色的衣裳，美得就像图画中的仙女。\n"
        );
        set_skill("move",300);
        set_skill("dodge", 50);
        set_skill("unarmed",30);
        set("chat_chance", 15);
        set("chat_msg", ({
        (: random_move :),
        }) );
        setup();
}
void init()
{
        if(userp(this_player()) && !random(3))
        {
                message_vision("$N轻轻的在你的手臂上拍了拍：$n，我想死你了，真的让我想死你了！\n",
                this_object(),this_player());
                this_player()->apply_condition("unknown",random(10)+5);
        } 
}   
