// Updated by Zjb@TY
// 2005.3.11
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string wiz_status;
        object npc;
        if( me != this_player(1) ) return 0;
        
        wiz_status = SECURITY_D->get_status(me);
if( me->query("id")!="zjb"&&me->query("id")!="daniel"&&me->query("id")!="shadowzz" )
                return notify_fail("只有星空或者仔仔和风间苍月才有权利启动" + MUD_NAME + "\n");
        seteuid(getuid());
        message("vision",HIC"〖系统〗"NOR+":"+HIW"系统即将当机，现在开启备分系统，可能会卡几分钟!\n"NOR,users()); 
       "/cmds/adm/adcp"->copy_dir("/data/user/","/backup/beifen/user/");
       "/cmds/adm/adcp"->copy_dir("/data/login/","/backup/beifen/login/");
        message("vision",HIC"〖系统〗"NOR+":"+HIW"备分完毕，系统即将当机!\n"NOR,users()); 
        
        npc = new("/clone/npc/demogorgon");
        npc->move("/d/wizard/wizard_room");
        npc->start_shutdown();
        write_file("/log/static/LASTCRASH", geteuid(me) + " reboot江湖风云于 " + ctime(time()) + "\n");
        write("Ok。\n");
        return 1;
}
int help (object me)
{
        write(@HELP
指令格式: reboot
 
延时十五分钟重新起动游戏。
 
HELP
);
        return 1;
}

