 // garrison.c
#include <ansi.h> 
inherit NPC;
void create()
{
    set_name("狱卒长", ({ "yuzu zhang", "yu zu zhang" }) );
    set("long",
            "狱卒虽小，但也不要轻易惹倒他们，他们是有组织的一群人。\n");
    
    set("attitude", "heroism");
    set("str", 27);
    set("cor", 26);
    set("cps", 25);
    set("combat_exp", random(10000));
    
    set_skill("unarmed", 70+random(50));
    set_skill("staff", 70+random(50));
    set_skill("parry", 70+random(50));
    set_skill("dodge", 70+random(50));
    set_skill("move", 100+random(50));
    
    set_temp("apply/attack", 70);
    set_temp("apply/dodge", 70);
    set_temp("apply/parry", 70);
    set_temp("apply/damage", random(100));
    set_temp("apply/armor", 70);
    set_temp("apply/move", 100);
    set("chat_chance", 1);
    set("chat_msg", ({
"狱卒长低声道：“这点响银，还不够老子打酒喝。”\n",
    }) );
    setup(); 
    carry_object("/clone/misc/cloth")->wear();
} 
void destory_this()
{
        message_vision("$N不耐烦道：“还没想好吗？那就慢慢想吧！想好了再叫我。”\n",this_object());
        message_vision("$N悻悻然拂袖而去。 \n",this_object());
        destruct(this_object());
        return;
} 
void release_player(object player)
{
        message_vision("$N说：“想出去？嘿嘿。。。\n",this_object());
        message_vision("$N看看左右没人，低声对$n说道：”有钱就可以放你出去，你付得起吗？“ \n",this_object(),player);
        message_vision("$N做了一个手势，低声道：”这个数，黄金50两。我直接从你帐户上转，愿不愿意？(ACCEPT YES/NO)”  \n",this_object());
        add_action("do_accept","accept");
        call_out("destory_this",20);
}
int do_accept(string arg)
{
        object player;
        int amount;
        player = this_player();
        remove_call_out("destory_this");
        if (arg == "yes")
        {
                amount = player->query("deposit");
                if (amount < 500000)
                {
                        message_vision("$N气急败坏对$n大骂道：“我查过了，你这个穷鬼根本没那么多钱！敢耍我，在这儿慢慢等死吧！” \n",this_object(),player);
                        message_vision("$N悻悻然拂袖而去。 \n",this_object());
                        destruct(this_object());
                }else
                {
                        amount = amount - 500000;
                        player->set("deposit",amount);
                        message_vision("$N带着讨好的笑对$n说：“我就说这位"+ RANK_D->query_respect(player) + "是聪明人！跟我走。”\n",this_object(),player);
                        message_vision("$N将$n提出了牢房。 \n",this_object(),player);
                        player->move("/d/jinan/dayu");
                        player->set("vendetta/authority", 0);
                        player->delete("marks/crime");
                        message_vision("$N满心伤痕的出了牢房。 \n",player);
                        destruct(this_object());
                }
                return 1;
        }
        if (arg == "no")
        {
           message_vision("$N冷哼道：“真是要钱不要命的家伙，看你能在这儿撑到几时。” \n",this_object(),player);
                message_vision("$N悻悻然拂袖而去。 \n",this_object());
                destruct(this_object());
                return 1;
        }
        return notify_fail("你只可ACCEPT YES OR NO \n");
}    
