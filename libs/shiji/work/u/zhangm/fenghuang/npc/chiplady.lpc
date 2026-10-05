#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";
int to_say_chip();
void create()
{
        set_name("蜜儿",({ "mill","chip lady","lady" }));
        set("level",9);
        set("title","筹码小姐");
        set("race", "人类");
        set("gender","女性");
        set("age", 19);
        set("long",@LONG
可爱美丽的小姐, 你可以拿钱跟她换筹码. ( ask mill about chip )
LONG        );
        set("attitude", "friendly");
        set("inquiry",([
           "筹码": (: to_say_chip :),
           "chip": (: to_say_chip :),
        ]));
        setup();
        seteuid(getuid());
}

void init()
{
        add_action("do_change","change");
}


int do_change(string schip)
{
        object me;
        int chip;
        me = this_player();
        if(!schip)
        {
                command("think");
                command("say "+me->query("name")+"，你要几枚筹码啊？");
                return 1;
        }
        if(sscanf(schip,"%d",chip)!=1)
        {
                command("?");
                command("say "+me->query("name")+"，你要干嘛啊？");
                return 1;
        }
        if(me->can_afford(chip*10)==0)
        {
                command("say "+me->query("name")+"，你似乎没有那麽多钱来买筹码？");
                return 1;
        }
        me->receive_money(chip*(-10));
        Game_receive_chip(chip,me);
        message_vision("$N拿出"+F_VENDOR->price_string(chip*10,me->money_type())+"给"+query("name")+"。\n",me);
        command("smile");
        command("say "+me->query("name")+"，这些是你要的筹码。");
        return 1;
}


int to_say_chip()
{
        object me = this_player();
write(@HELP
        指  令                         说    明
=====================================================================
        change <筹码数>         用身上的钱来兑换筹码
=====================================================================
HELP);
        command("say 目前是"+F_VENDOR->price_string(10,me->money_type())+"换一枚筹码。");
        return 1;
}

