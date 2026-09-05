#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        string tmpstr;
        string id,  type, name,reason,cname;
        int pt;

        if( me!=this_player(1) ) return 0;
        if( !arg || (sscanf(arg, "%s %s %s %d because %s as %s", id,type,name,pt,reason,cname)!=6 && sscanf(arg, "%s %s %s because %s as %s", id,type,name,reason,cname)!=5 ))
                return notify_fail("指令格式 : reward <某人> <property> <属性名> <点数> because <原因> as <属性中文名>\n或者reward <某人> skill <技能名> <级别>  because <原因> as <技能中文名\n或者reward <某人> specialskill <特技名>  because <原因> as <特技中文名");
        if(!wizardp(me))
                return 0;

        seteuid(ROOT_UID);
        if(objectp(find_player(id)))
        {
            ob = find_player(id)->query_temp("link_ob");
            if(!objectp(ob)) return notify_fail("没有这个玩家。\n");
        }
        else
        {
            ob = new(LOGIN_OB);
            ob->set("id", id);
            if( !ob->restore() ) return notify_fail("没有这个玩家。\n");
        }
        if(type == "property")
        {
            ob->set("reward/property/"+name+"/number",pt);
            ob->set("reward/property/"+name+"/reason",reason);
            ob->set("reward/property/"+name+"/cname",cname);
        }
        else if(type == "skill")
        {
            ob->set("reward/skill/"+name+"/number",pt);
            ob->set("reward/skill/"+name+"/reason",reason);
            ob->set("reward/skill/"+name+"/cname",cname);
        }
        else if(type == "specialskill")
        {
            ob->set("reward/specialskill/"+name+"/number",1);
            ob->set("reward/specialskill/"+name+"/reason",reason);
            ob->set("reward/specialskill/"+name+"/cname",cname);
        }
        else
        {
           return notify_fail("指令格式 : reward <某人> <property> <属性名> <点数> because <原因> as <属性中文名>\n或者reward <某人> skill <技能名> <级别>  because <原因> as <技能中文名\n或者reward <某人> specialskill <特技名>  because <原因> as <特技中文名");
        }
        ob->save();

        if(!objectp(find_player(id)))
        {
            destruct(ob);
        }
        write("奖励发放成功，玩家登陆后会收到奖励。\n日志写入成功...\n");

        log_file("GIVE_REWARD", ctime(time()) + "  " + me->query("id") + ": reward "+arg + "\n");
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : reward <某人> <property> <属性名> <点数> because <原因> as <属性中文名>\n或者reward <某人> skill <技能名> <级别>  because <原因> as <技能中文名\n或者reward <某人> specialskill <特技名>  because <原因> as <特技中文名>
HELP
    );
    return 1;
}
