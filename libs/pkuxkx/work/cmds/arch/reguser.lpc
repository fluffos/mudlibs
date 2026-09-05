// register.c
// Created by Xiang@XKX

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int register_user(string wizid, string id, string name, string email)
{
        object ob, body;

        if( objectp(body = find_player(id)) && geteuid(body)==id ) {
                ob = body->query_temp("link_ob");
                if( !ob ) return 0;
                ob->set("registered", 1);
                ob->set("name",name);
                ob->set("email", email);
                ob->set("registered_by", wizid);
                ob->save();
        }
        else {
                ob = new(LOGIN_OB);
                ob->set("id", id);
                if (!ob->restore())
                        return 0;
                ob->set("registered", 1);
                ob->set("name",name);
                ob->set("email", email);
                ob->set("registered_by", wizid);
                ob->save();
                destruct(ob);
        }
        return 1; 
}

int main(object me, string arg)
{
        string id, name, email;

        if (!arg || sscanf(arg, "%s %s %s", id, name, email) != 3) {
                return notify_fail("指令格式：register <id> <name> <email>\n");
        }
        switch(register_user(me->query("id"), id, name, email)) {
        case 0: return notify_fail("登记失败。\n"); break;
        default: return notify_fail(id + " 已经成功地被您登记了。\n"); break;
        }
}

int help(object me)
{
        write(@HELP
指令格式：register <id> <name> <email>

这个指令是用来给还没有登记过的用户登记用的。
HELP
        );
        return 1;
}
