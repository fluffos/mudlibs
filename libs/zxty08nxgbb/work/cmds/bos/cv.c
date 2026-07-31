inherit F_CLEAN_UP;
#define MS sprintf("%c%c",13,10 )
#define CC sprintf("%c",10 ) 
int main(object me, string arg)
{
      string src, dst;
      string msg; 
      seteuid(geteuid(me));
     if(!arg)return 1;
     if(sscanf(arg, "%s %s", src, dst)!=2){
src=arg;dst=src;} 
      src = resolve_path(me->query("cwd"), src);
      if(sscanf(src,"%*s.o"))return 1;
      dst = resolve_path(me->query("cwd"), dst);
      msg=read_file(src);
   if(!msg)return notify_fail(sprintf("read file %s error!\n",src));
msg=replace_string(msg,MS,CC);
      
      write_file(dst,msg,1);
      write("convert to linux format ok!\n");
      return 1;
}

int help(object me)
{
write(@HELP
指令格式 : cv <原档名> <目标档名>
如果<目标档名>为空将覆盖原档
此指令可让你(你)转换某个档案为linux文件格式。
HELP
  );
  return 1;
}


