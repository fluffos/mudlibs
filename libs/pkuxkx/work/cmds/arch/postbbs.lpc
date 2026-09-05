//postbbs
//cmd for arch
//made by jason@pkuxkx 2001-10-10

#define ERR     "命令格式：postbbs 文件名 文章标题\n"

int main(object me,string arg)
{
        string file,title;
        object bbsd;
        if(!arg||arg=="") 
                return notify_fail(ERR);
        if(sscanf(arg,"%s %s",file,title)!=2)
                return notify_fail(ERR);
        if(file_size(me->query("cwd")+file)<0)
                return notify_fail("无法打开文件！请保证文件位于当前目录下！\n");
        if(!stringp(title)||title==""||sizeof(title)>24)
                return notify_fail("标题为空或者超过24字节\n");
        BBS_D->doPost(1,me->query("cwd")+file,title);
        write("Ok!\n");
        return 1;
}
