// lsskills.c
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, object env,string arg)
{
    int i, j, k, ii;
    string dir,str,file2;
    mixed *file;
    dir = resolve_path("/kungfu/skill");
    if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
    file = get_dir(dir, -1);
    if( !sizeof(file) ){
        if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
    else
        return notify_fail("没有任何目录。\n");
    }
    i = sizeof(file);
    while(i--) {
        if (file[i][1]==-2) file[i][0] += "/   ";
    }
    str="";
    if (sizeof(file) ){
        for(i=0, j = sizeof(file),k=0; i<j; i++,k++){
            if (! (int)SECURITY_D->valid_read(dir + file[i][0],me) ) { k--;continue; }
    file2 = resolve_path(file[i][0]);
    ii = sizeof(file[i][0]);
            str+=sprintf("%-20s%s%20s%s\n",
        to_chinese(file2[0..ii-3]),"＝＝",file2[0..ii-3],
                ((i)%2)?HBRED HIC"":HBBLU HIG""
                );
        }
    if (!k)  write("没有这个目录。\n");
    else    
        write("目录：" + dir + "\n");
        me->start_more(str);
    }else write("    没有任何档案。\n");
    write("\n");
    
    return 1;   
}
int help(object me)
{
    write(@HELP
HELP
    );
    return 1;
}

