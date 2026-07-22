string *banned_cast=({"chuqiao","qimen","qiankun","zhuang","huanying","townportal","escape","tuoqiao",
 "tudun","shuidun","huodun","ygbh","wuxing","yundun","huadun","jile","seal","move","fengshi"});

int do_cast(string arg) 
{

    
    if(!arg) return 0;
    while(sscanf(arg,"%s %*s",arg)==2);
    if(member_array(arg,banned_cast)==-1) 
    	return 0;
    write("此乃天界，岂容你乱来？! \n");
    return 1;
}
int do_fly()
{
	
    write("此乃九重天，你能飞到哪去？ \n");
    return 1;	
	
}
