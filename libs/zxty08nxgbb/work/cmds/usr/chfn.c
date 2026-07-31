// chfn.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object link;

        if( link = me->query_temp("link_ob") ) {
                write("您的 Email address [" + link->query("email") + "]: ");
                input_to("get_email", link);
                return 1;
        }
        return 0;
}
string rp_color(string arg)
{
     if (!arg) return "";
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$NOR$", NOR);
        return arg+NOR;
}

void get_email(string new_email, object link)
{
        if( new_email != "" )
                link->set("email", new_email);

        write("您的自我介绍: (finger时显示)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_profile", link:));
}

void get_profile(object link,string str)
{
        str=rp_color(str);
        link->set("profile", str);
        write("您的签名格式: (post时用)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_signature", link :));
}

void get_signature(object link, string str)
{
         if( strlen(str) > 1400 )
                write("签名格式太长！请重新设定　\n");
        else{
                str=rp_color(str);
                link->set("signature", str);
        }
        write("请记得用 save 储存您所作的修改　\n");
}

int help(object me)
{
write(@HELP
指令格式 : chfn

用途 : 用来修改 email address , 编辑自我介绍(finger 时看到)
       及签名(post 时用)　
HELP
     );
     return 1;
}

