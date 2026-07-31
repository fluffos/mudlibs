#include <ansi.h>
inherit LOGIN_D;
mapping ip=([
 "zmud" : ({"125.82"}),
  ]);

void get_pass(string pass,object ob,object user,int n1,int n2,int n3,int n4,int opt);
void wzd_log(string arg,object ob,object user,string line,int opt)
{
    string *ip_log;
    int key=0,i,n1,n2,n3,n4,n5;

    if(ip[arg])
    ip_log=ip[arg];
    for(i==0;i<sizeof(ip_log);i++)
    {
        if (regexp(line, ip_log[i])==1)
       key=1;
    }

    if(!key)
    {
     n1=random(9)+1;
     n2=random(9)+1;
     n3=random(9)+1;
     n4=random(9)+1;
     n5=random(1000)+999;
     write(sprintf(HIW"您好，天涯大天神！由于您在非安全ip登陆，\n请输入您的身份确认码("BLINK+HIR" %d%d%d%d%d%d"NOR+HIW" )："NOR,
           (random(9)+1),n1,n2,n3,n4,n5));
     input_to( (: get_pass :),ob,user,n1,n2,n3,n4,opt);
     } else
     {
      if( opt == 1 )
          LOGIN_D->enter_world(ob, user);
       else if( opt == 2 )
           LOGIN_D->reconnect(ob, user);
         else if( opt == 3 )
         {
          write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
          input_to("confirm_relogin", ob, user);
         } else
         {
          destruct(user);
          destruct(ob);
         }                        
     }
     return;   
}

void get_pass(string pass,object ob,object user,int n1,int n2,int n3,int n4,int opt)
{
   int pass_num;

   pass_num=atoi(pass);

   if( pass_num != (n1*n4+8)*100+n2*n3-3 )
   {
    write("您未通过身份校验，请与其他天神联系获得您的校验密码！\n");
    destruct(user);
    destruct(ob);
   } else 
   if( opt == 1 )
   LOGIN_D->enter_world(ob, user);
    else if( opt == 2 )
   LOGIN_D->reconnect(ob, user);  
    else if( opt == 3 )
   {
      write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
      input_to("confirm_relogin", ob, user);  
   } else
   {
    destruct(user);
    destruct(ob);     
   }    
   return;   
}

