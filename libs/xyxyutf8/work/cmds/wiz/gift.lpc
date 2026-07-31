 //gift.c
//by diablo@xyxy#include <ansi.h>

inherit F_CLEAN_UP;

string display_attr(string gift, int value,int effective);
string type;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    mapping my;
    string ob_id, flag;
    string str1, str2, str3, str4, str5;
    int i;
    object ob;
 //       if (! SECURITY_D->valid_grant(me, "(wizard)")) return 0;
 
    seteuid(getuid(me));

    if (!arg) ob=me;
    if (!ob) ob = present(arg, environment(me));
    if (!ob) ob = find_player(arg);
    if (!ob) ob = find_living(arg);
    if (!ob) return notify_fail("你要察看谁的状态？\n");
    my = ob->query_entire_dbase();
str1 = "  〖姓名〗  "+ob->name()+"  〖性别〗  "+ob->query("gender")+"  〖ＩＤ〗  "+ob->query("id");
str2 = "  〖容貌〗  "+ob->query("per")+"  〖胆识〗  "+ob->query("cor")+"  〖定力〗  "+ob->query("cps")+"  〖福缘〗  "+ob->query("kar");
str3 = "  〖体格〗  "+ob->query("str")+"  〖筋骨〗  "+ob->query("con")+"  〖悟性〗  "+ob->query("int")+"  〖灵性〗  "+ob->query("spi");
str4 = "  〖ＰＫ〗  "+ob->query("PKS")+"  〖ＮＫ〗  "+ob->query("MKS")+"  〖备注〗  "+ob->query("");
str5 = "  〖捐钱〗  "+(ob->query("donation")/1000000)+"  〖阳寿〗  "+ob->query("life/life_time")+"  〖参果〗  "+ob->query("rsg_eaten");
tell_object(me, "你要查的信息如下:\n"+str1+"\n"+str2+"\n"+str3+"\n"+str4+str5+"\n");

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式：gift [-o] <对象名称>
 
这个指令可以显示你或指定对象（含怪物）的天赋。

-o (original) 显示最初天赋（不算literate等的效果）。
see also : score
HELP
    );
    return 1;
}

