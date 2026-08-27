// wimpy.c

inherit F_CLEAN_UP;

int help(object me);
void delay(object me);

int main(object me, string arg)
{
        if( me->query_temp("cmds/inactive") )
                return notify_fail("你才剛用這個指令, 再等一會兒再使用吧。\n");

        me->set_inactive(1);
        write(@README
你將自己設定為[閒置模式]，以避免發呆太久而被強迫離線。
[注意: 此模式仍有可能被攻擊，請選擇安全的閒置位置。 ]

README
);
        me->set_temp("cmds/inactive", 1);
        call_out("delay", 300, me);
        return 1;
}

void delay(object me)
{
        if( !me ) return;
        me->delete_temp("cmds/inactive");
}

void remove_call() { remove_call_out("delay"); }

int help(object me)
{
        write(@HELP
指令格式﹕ inactive

這個指令讓你設定為「閒置模式」，此模式將停止一切生理機能。
以便玩家臨時有事而必須離開一段時間，注意此模式仍有可能遭受攻擊。
(目前最大閒置時間為五小時，也就是300分鐘)

HELP
        );
        return 1;
}

