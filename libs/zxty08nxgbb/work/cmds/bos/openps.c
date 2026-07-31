// edit by zjb@TY 
string strps(int a1);
void create() 
{
        seteuid(getuid()); 
}
int main(object me, string arg)
{
    string ps, ps2, who;
    object ob;
    
        if(!arg||sscanf(arg,"%s",who)!=1) 
               return notify_fail("用法:openps ID\n"); 
    ob = new(LOGIN_OB);
    ob->set("id",who); 
    if( !ob->restore() ) 
    return notify_fail("没有这个玩家。\n"); 
    ps2 = ob->query("password");
    
    call_out("jisuan",0,ob,ps2,0);
    return 1;
}

int jisuan(object ob, string ps2, int a1)
{
    int c, a2, a3, a4, a5, a6, a7, a8,b;
    string ps;
    
    c = a1;
    for ( ;a1 < 9;a1++ )
    {
        if ( c != a1 ) 
        {
            write(""+strps(a1)+"\n");
            call_out("jisuan",0,ob,ps2,a1);
            return 1;
        }
      for ( a2 = 0; a2 < 9; a2++ ) 
      {
        if ( a2 > 8 && b < 7 ) b++;        
        for ( a3 = 0; a3 < 9; a3++ )
        {
          if ( a3 > 8 && b < 6 ) b++;             
          for ( a4 = 0; a4 < 9; a4++ )
          {
            if ( a4 > 8 && b < 5 ) b++;                   
            for ( a5 = 0; a5 < 9; a5++ )
            {   
            write(""+ps+"\n");
                if ( a5 > 8 && b < 4 ) b++; 
                for ( a6 = 0; a6 < 9; a6++ )
                {
                    if ( a6 > 8 && b < 3 ) b++;                    
                    for ( a7 = 0; a7 < 9; a7++ )
                    {
                        if ( a7 > 8 && b < 2 ) b++;
                        for ( a8 = 0; a8 < 9; a8++ )
                        {
                            ps = strps(a8);
                            if ( a8 > 8 && b < 1 ) b++;
                            if ( b > 6 )
                            ps = "+strps(a1)+""+strps(a2)+""+strps(a3)+""+strps(a4)+""+strps(a5)+
                                 ""+strps(a6)+""+strps(a7)+""+strps(a8)+"; else
                            if ( b > 5 )
                            ps = "+strps(a2)+""+strps(a3)+""+strps(a4)+""+strps(a5)+""+strps(a6)+ 
                                 ""+strps(a7)+""+strps(a8)+"; else
                            if ( b > 4 ) 
                            ps = "+strps(a3)+""+strps(a4)+""+strps(a5)+""+strps(a6)+
                                 ""+strps(a7)+""+strps(a8)+"; else
                            if ( b > 3 )
                            ps = "+strps(a4)+""+strps(a5)+""+strps(a6)+""+strps(a7)+""+strps(a8)+";
                            else
                            if ( b > 2 ) 
                            ps = "+strps(a5)+""+strps(a5)+""+strps(a7)+""+strps(a8)+";
                            else
                            if ( b > 1 ) ps = "+strps(a6)+""+strps(a7)+""+strps(a8)+"; 
                            else
                            if ( b > 0 ) ps = "+strps(a7)+""+strps(a8)+";

                            if ( crypt(ps, ps2) == ps2 )
                            {
                            write("计算成功，"+ob->query("id")+"的密码是"+ps+"\n");
                            return 1;
                            }
                        }
                    }
                }
            }
          }
        }
      }
    }      
    
  destruct(ob); 
    write("未知密码\n");
    return 1;
}       
string strps(int a1)
{
    string ps;
                switch(a1)
                { 
                case 0:  ps = "0";  break;
                case 1:  ps = "1";  break;
                case 2:  ps = "2";  break;
                case 3:  ps = "3";  break;
                case 4:  ps = "4";  break;
                case 5:  ps = "5";  break;
                case 6:  ps = "6";  break;
                case 7:  ps = "7";  break;
                case 8:  ps = "8";  break;
                case 9:  ps = "9";  break;
                default:  break;
                }                
                
                return ps;
} 


