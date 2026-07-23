// 诛仙阵内不允许的命令及法术
// 本地巫师可以根据需要添加新的命令或法术,
// 比如在banned_cast里加上invocation,banned_action里加上eat,等等。
// 现有的banned清单是为保证诛仙阵的正常运行，
// 如有需要取消，务请慎重，并由巫师监控全部比武过程。
// 如发现bug，请及时报告，多谢合作。

string *banned_cast=({"chuqiao","qimen","qiankun","zhuang","huanying","townportal","escape","tuoqiao",
	"tudun","shuidun","huodun","ygbh","yundun","jile","huadun","wuxing","fengshi","move","seal"});
string *banned_action=({"practice","xiudao","move","mark","learn","study","read","bian","recall","accept","ji"});
	
int do_quit() 
{
  write("进了诛仙阵  有来无回！ \n");
  return 1;
}
	
int do_sleep() 
{
  write("算你狠，这里也敢睡大觉！ \n");
  return 1;
}
int do_ji() 
{
  write("你突然发现什么都没有发生！ \n");
  return 1;
}

int do_cast(string arg) 
{
//    object me=this_player();
    
    if(!arg) return 0;
/*    if(me->is_busy()) 
    {
    	write("你正忙着呢！\n");
    	return 1;
    }
*/    while(sscanf(arg,"%s %*s",arg)==2);
    //write(arg+"\n");
    if(member_array(arg,banned_cast)==-1) 
    	return 0;
    write("这里不可以"+arg+",不可以临阵脱逃，要与同伴通力合作! \n");
    return 1;
}
