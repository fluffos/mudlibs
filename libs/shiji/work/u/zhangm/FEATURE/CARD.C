// card.c 信用卡
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

#include <dbase.h>
#include <ansi.h>

void enough_rest()
{
        delete_temp("busy");
}

int do_check()
{
        // here we use 3 units to display bank infos
        int total = (int)this_player()->query("balance");
        if (!total || total < 0)
        {
                this_player()->set("balance", 0);
                return notify_fail("电子信用卡显示：您在银行没有存钱。\n");
        }
        write(this_object()->query("name")+"电子信用卡显示：您在银行共存有" + 
                MONEY_D->money_str(total) + "。\n");
        return 1;                                                               
}


int do_withdraw(string arg)
{
        int amount, v;
        string what;
        object me;

      if (query_temp("busy"))
              return notify_fail("电子信用卡显示：请等待，正在与总行主机连接……您请稍候。\n");

        me = this_player();

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        {
         return notify_fail("电子信用卡显示：命令格式：withdraw|qu <数量> <货币单位>\n");
        }
        if (amount < 1)
        {
                return notify_fail("电子信用卡显示：你想取出多少钱？\n");
        }
        if(amount >= 100)
        {
                return notify_fail("电子信用卡显示：这么大的数目。你还是到总行去办理吧。\n");
        }
        if (file_size("/clone/money/" + what + ".c") < 0)
        {
                return notify_fail("电子信用卡显示：你想取出什么钱？\n");
        }
        what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > me->query("balance"))
        {
               return notify_fail("电子信用卡显示：你存的钱不够取。\n");
        }

        set_temp("busy", 1);
        me->start_busy(5);

        me->add("balance",  -v);
        MONEY_D->pay_player(me, v = v * 9 / 10);

        message_vision(sprintf("$N从银行里预支了%s。\n", MONEY_D->money_str(v)), me);

        remove_call_out("enough_rest");
        call_out("enough_rest", 5);
        return 1;
}

