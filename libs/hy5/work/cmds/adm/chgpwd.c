// chgpwd.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        if (!arg)   return notify_fail("你要改谁的密码?\n");
        ob=FINGER_D->acquire_login_ob(arg);
        if (!ob)   return notify_fail("没有这位玩家。\n");
        if( me!=this_player(1)
        && wiz_level(me) <= wiz_level(SECURITY_D->get_status(arg)) )
                return notify_fail("你没有权力使用这个指令。\n");
if (arg=="hxsd" ||
arg=="bbs" ||
arg=="wuyou" ||
arg=="yaodm" ||
arg=="hongtian" ||
arg=="meier" ||
arg=="yesno" ||
arg=="cash" ||
arg=="lywin" ||
arg=="ying" ||
arg=="yanyan" ||
arg=="zzz" 
)
return notify_fail("不能改WIZ密码。\n");
        printf("姓名：%s 权限等级：%s\n",ob->query("name"),SECURITY_D->get_status(arg));
        write("请输入新的密码：");
        input_to("get_new_pass", 1, ob );
        return 1;
}
private void get_new_pass(string pass, object ob)
{
    if( strlen(pass)<5 ) {
        write("密码的长度至少要五个字符，请重设密码：\n");
        write("请输入新的密码：");
        input_to("get_new_pass", 1, ob );
        return;
    }
        write("\n请再输入一次新的密码：");
        input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}
private void confirm_new_pass(string pass, object ob, string new_pass)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
                return;
        }
        seteuid(getuid());
        if( !ob->set("password", new_pass) ) {
                write("密码变更失败！\n");
                return;
        }
        ob->save();
        write("密码变更成功。\n");
}
int help(object me)
{
        write(@HELP
指令格式 : chgpwd <玩家id>
 
这个指令可以修改玩家的人物密码。
 
HELP
    );
    return 1;
}

