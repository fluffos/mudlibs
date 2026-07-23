// grep.c

#define BUFFER_SIZE     1024
inherit F_CLEAN_UP;

int help(object me);
void searchstr(object me,string file,string str,int location,string buf);
void donext(string arg,object me,string file,string str,int location,string buf);

int main(object me, string arg)
{
        string file,str;

        seteuid(geteuid(me));
        if (!arg || sscanf(arg,"%s %s",str,file)<2) 
                return notify_fail("指令格式 : grep <字符串> <档案> \n");
        if( file_size(file) < 0 ) {
                file = LOG_DIR+file;
                if( file_size(file) < 0 )
                        return notify_fail("没有这个档案。\n");
        }

        searchstr(me,file,str,file_size(file),"");
        return 1;
}

void searchstr(object me,string file,string str,int location,string buf)
{
        string * s;
        int i,j,count;

        count = 0;
        while (1) {
                i = location;
                location -= BUFFER_SIZE;
                if (location<0)
                        location=0;
                else
                        i = BUFFER_SIZE;
                s = explode(read_bytes(file,location,i)+buf,"\n");
                buf = s[0]+"\n";
                        
                if (location<=0) j=0; else j=1;
                for(i=sizeof(s)-1;i>=j;i--) {
                        if( strsrch(s[i],str,1)>=0 ) {
                                tell_object(me,s[i]+"\n");
                                count++;        
                        }
                }

                if (location<=0) {
                        tell_object(me,"\n搜索结束。\n");
                        return;
                }

                if (count>20) {
                        count = 0;
                        tell_object(me,"== 未完继续 == (ENTER 继续下一页，q 离开)");
                        input_to("donext",me,file,str,location,buf);
                        return;
                }
        }
        return;
} 

void donext(string arg,object me,string file,string str,int location,string buf)
{
        if( arg[0]!='q' )
                searchstr(me,file,str,location,buf);
        else
                tell_object(me,"查询终止。\n");
}

int help(object me)
{
write(@HELP
指令格式 : grep <字符串> <档案>
 
在档案中寻找指定的字符串。
HELP
    );
    return 1;
}
