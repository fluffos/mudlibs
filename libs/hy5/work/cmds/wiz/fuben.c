       // This program is a part of NITAN MudLIB 
       // Written by Lonely@IsMUD.net (16/05/2009)  
       // fuben.c 副本管理指令 
        
#include <ansi.h> 
        
inherit F_CLEAN_UP; 
        
int help (object me);
string appromix_time(int n, int flag) 
{ 
             string s; 
             string os; 
             int odd; 
             int bn; 
      
             if (n <= 0) 
                     return flag ? "马上就" : "马上"; 
      
             bn = 1; 
             if (n < bn * 60) 
             { 
                     // bn 单位是秒钟 
                     s = "秒钟"; 
                     odd = 0; 
             } else 
             if (bn *= 60, n < bn * 60) 
             { 
                     // bn 单位是分钟 
                     s = "分钟"; 
                     os = "秒钟"; 
                     odd = n % bn; 
                     n /= bn; 
             } else 
             if (bn *= 60, n < 24 * bn) 
             { 
                     // bn 单位是小时 
                     s = "小时"; 
                     os = "分钟"; 
                     odd = (n % bn) / 60; 
                     n /= bn; 
             } else 
             if (bn *= 24, n < 30 * bn) 
             { 
                    // bn 单位是天 
                     s = "天"; 
                     os = "小时"; 
                     odd = (n % bn) / (60 * 60); 
                     n /= bn; 
             } else 
             if (n < 365 * bn) 
             { 
                     // bn 单位是天 
                     s = "个月"; 
                     os = "天"; 
                     odd = (n % (30 * bn)) / bn; 
                     n /= 30 * bn; 
             } else 
             { 
                     // bn 单位是天 
                     s = "年"; 
                     os = "个月"; 
                     odd = (n % (365 * bn)) / (bn * 30); 
                     n /= 365 * bn; 
             } 
      
             s = chinese_number(n) + s; 
             if (odd) 
                     s += "零" + chinese_number(odd) + os; 
      
             if (flag) s += "以后"; 
             return s; 
}  
int main(object me,string arg) 
{ 
              int i, j; 
              string cmd; 
              string fbname; 
              string owner; 
              mixed  ks,os; 
              mapping all, data, temp; 
              string msg = ""; 
               
//              if( !SECURITY_D->valid_grant(me, "(wizard)") ) 
//                      return 0; 
       
              if( !arg ) {  
                      help( me );  
                      return 1; 
              } 
      
              if( sscanf(arg,"%s %s %s",cmd, fbname, owner) != 3 && 
                  sscanf(arg,"%s %s",cmd, fbname) != 2 ) 
                      cmd = arg; 
               
              all  = FUBEN_D->query_fuben_all(); 
              data = FUBEN_D->query_fuben_data();          
              if( !stringp(fbname) ) { 
                      if( !all ) return notify_fail("泥潭现在没有任何副本。\n"); 
                     msg += "泥潭现在开启的副本空间如下：\n"; 
                      msg += "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"; 
                      ks = keys(all); 
                      for( i=0;i<sizeof(ks);i++ ) {  
                              temp=all[ks[i]]; 
                             if( mapp(temp) && sizeof(temp) ) { 
                                      os = keys(temp); 
                                      for( j=0;j<sizeof(os);j++ )  
                                              msg += sprintf("副本名称：%-33s剩余时间：%s\n",  
                                                      data[ks[i]]["name"]+"<"+ks[i]+">("+os[j]+")",  
                                                      appromix_time(temp[os[j]] - time(),0));  
                              } 
                                       
                      } 
                      me->start_more(msg); 
                      return 1; 
              } else { 
                      if( cmd == "open" ) { 
                              FUBEN_D->open_fuben(me, fbname); 
                              return 1; 
                      } else if( cmd == "close" ) { 
                              FUBEN_D->close_fuben(me, fbname); 
                              return 1; 
                      } 
       
                     if( fbname != "all" && (undefinedp(data[fbname]) || 
                          undefinedp(all[fbname])) ) 
                              return notify_fail("泥潭现在没有这个副本。\n"); 
                               
                      if( cmd == "list" ) { 
                              msg += sprintf("泥潭现在开启的%s副本空间如下：\n", (fbname=="all")?"所有":data[fbname]["name"]); 
                              msg += "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n";                                                
                              if( fbname == "all" ) { 
                                      ks = keys(data); 
                                      for( i=0;i<sizeof(ks);i++ ) { 
                                              msg += sprintf("副本名称：%-23s组队要求：%-8s任务时间：%s\n",  
                                                     data[ks[i]]["name"]+"<"+ks[i]+">",  
                                                     (!undefinedp(data[ks[i]]["team"]))?"必须":"任意", 
                                                     appromix_time(to_int(data[ks[i]]["time"]),0));  
                                      } 
                              } else { 
                                      temp = all[fbname]; 
                                      ks = keys(temp); 
                                      for( i=0;i<sizeof(ks);i++ ) { 
                                              msg += sprintf("副本名称：%-33s剩余时间：%s\n",  
                                                     data[fbname]["name"]+"<"+fbname+">("+ks[i]+")",  
                                                     appromix_time(temp[ks[i]] - time(),0));  
                                      } 
                              } 
                              me->start_more(msg); 
                              return 1; 
                      } else if( cmd == "dest" ) { 
                              if( !stringp(owner) ) { 
                                      ks = keys(all[fbname]); 
                                      for( i=0;i<sizeof(ks);i++ )  
                                              FUBEN_D->clear_fuben(fbname, ks[i]); 
                                      write("OK.\n"); 
                                      return 1; 
       
                              } else { 
                                      FUBEN_D->clear_fuben(fbname, owner); 
                                     write("OK.\n"); 
                                     return 1; 
                             } 
      
                     } else { 
                             help(me); 
                             return 1; 
                     } 
             } 
             return 1; 
     } 
      
int help (object me) 
{ 
                           write(@HELP 
     指令格式 : fuben list [副本名称] 
                fuben dest  副本名称  [副本主人] 
      
     fuben list                    查看当前游戏中所有的副本详细信息 
     fuben list 副本名称           查看指定副本的详细信息 
     fuben open|dest all|副本名称  查看指定副本的详细信息 
     fuben dest 副本名称           销毁指定类型副本的所有副本 
     fuben dest 副本名称 副本主人  销毁指定类型副本的某人副本 
HELP
        );
                           return 1; 
}