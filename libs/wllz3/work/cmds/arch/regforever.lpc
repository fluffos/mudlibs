// regforever.c
// 永久注册指令

inherit F_CLEAN_UP;

private void create(){ seteuid(getuid());}

int register_user(string wizid, string name)
{
        object ob, body;

        if( objectp(body = find_player(name)) && geteuid(body)==name )
                return notify_fail("你只能在玩家离线时才能给他登记永久保留标志！\n");

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if (!ob->restore())
                return 0;
        else {
                ob->set("regforever", 1);
                ob->set("registered_by", wizid);
                ob->save();
                destruct(ob);
                return 1;
        }
}

int main(object me, string arg)
{
        string id;

        if (!arg || sscanf(arg, "%s",id) != 1) {
                return notify_fail("指令格式：regforever <id>\n");
        }
        switch(register_user(me->query("id"),id)) {
                case 0: return notify_fail("登记失败。\n"); break;
                default: return notify_fail(id + "已经成功地被您登记为永久保留id了。\n"); break;
        }
}

int help(object me)
{
        write(@HELP
指令格式：register <id> <email>

这个指令是用来给玩家登记永久保留id时使用的。如玩家无法在三个月内
上线，该id会被系统定时清除！

HELP

        );
        return 1;
}
