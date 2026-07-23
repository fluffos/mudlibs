
#define SAVE_MAILF "/u/rcwiz/mail_center/to_user_mails/" + user + ".m"
#define TEMP_FILE  "/u/rcwiz/mail_center/MAIL_SYSTEM_TEMP_FILE_" + user + ".tmp"

mixed get_info(string user, string info, string flag, int num)
{
        int i = 0, n_temp = 0;
        string str_temp, msg;
        string who_send, topic, time, is_new, msg_txt;
        
        switch(info)
        {    
             // 计算邮件数量
             case "mailnum" :
                  while(str_temp = read_file(SAVE_MAILF, i, 1))
                  {
                        if (strsrch(str_temp, "MAIL_TO_START", 1) >= 0)n_temp ++;
                        i ++;    
                  }
                  return n_temp;      

             // 计算新邮件数量
             case "newmail" : 
                  i = 3;
                  while(str_temp = read_file(SAVE_MAILF, i, 1))
                  {
                        if (strsrch(str_temp, "MAIL_TO_START", 1) >= 0)
                        {                          
                              sscanf(str_temp, "MAIL_TO_START={WHO_SEND_MAIL:%*s:"
                                               "MAIL_TOPIC:%*s:SEND_TIME:%*s:MAIL_"
                                               "IS_NEW:%s}", str_temp);
 
                              // 未读新邮件标记
                              if (str_temp == "1")n_temp ++;
                        }
                        i ++;    
                 }                
                 return n_temp;
             
             // 读取指定邮件信息
             case "head" :
                  i = 3; msg = "";
                  while(str_temp = read_file(SAVE_MAILF, i, 1))
                  {
                        if (strsrch(str_temp, "MAIL_TO_START", 1) >= 0)
                        {
                              sscanf(str_temp, "MAIL_TO_START={WHO_SEND_MAIL:%s:"
                                               "MAIL_TOPIC:%s:SEND_TIME:%s:MAIL_"
                                               "IS_NEW:%s}", 
                                               who_send, topic, time, is_new);
                              if (num)n_temp ++;
                        }
                        // 找到欲读邮件头，分离信息
                        if (n_temp == num)
                        {
                              if (flag == "topic")return topic;
                              if (flag == "who_send")return who_send;
                              if (flag == "time")return time;   
                              if (flag == "is_new") return is_new;   
                              else return "内部参数错误！\n";
                        } 
                        i ++;
                  }

             case "txt" :  
                  i = 3; msg = "";
                  while(str_temp = read_file(SAVE_MAILF, i, 1))
                  {
                        if (strsrch(str_temp, "{MAIL_TEXT:", 1) >= 0)
                              if (num)n_temp ++;

                        // 找到欲读邮件正文，分离信息
                        if (n_temp == num)
                        {     
                              msg = str_temp;
                              i += 1;
                              while(str_temp = read_file(SAVE_MAILF, i, 1))
                              {
                                    if (strsrch(str_temp, "}=MAIL_TO_END", 1) != -1)
                                            break;
                                    msg += str_temp;
                                    i ++;
                              }
                              sscanf(msg, "{MAIL_TEXT:%s", msg);
                              return msg;
                        }                             
                        i ++;
                  }

             // 待扩展 ...
             case "refuse" : 
             case "reply" :
             case "reply_msg" :
             case "no_name" : 
             
             default : return 0;            

        } // end switch
       
}

void write_info(string user, string info, string result, int num)
{
        int i = 0, n_temp = 0;
        string str_temp;
        string who_send, topic, time;
        switch(info)
        {
              case "is_new" :
                   i = 2;
                   str_temp = read_file(SAVE_MAILF, 1, 1);
                   write_file(TEMP_FILE, str_temp, 1);
                   while(str_temp = read_file(SAVE_MAILF, i, 1))
                   {
                         if (strsrch(str_temp, "MAIL_TO_START", 1) >= 0)
                                 n_temp ++;
                         if (n_temp != num)
                         {
                                 if (! read_file(SAVE_MAILF, i + 1, 1))
                                          break; 
                                 write_file(TEMP_FILE, str_temp, 0);
                         }
                         else 
                         {    
                                 who_send = get_info(user, "head", "who_send", num);
                                 topic = get_info(user, "head", "topic", num);
                                 time = get_info(user, "head", "time", num);
                                 str_temp = "MAIL_TO_START={WHO_SEND_MAIL:" + who_send;
                                 str_temp += ":MAIL_TOPIC:" + topic + ":SEND_TIME:";
                                 str_temp += time + ":MAIL_IS_NEW:0}\n";

                                 write_file(TEMP_FILE, str_temp, 0);
                                 n_temp ++;
                         }           
                         i ++;
                   }
                   rm(SAVE_MAILF);
                   cp(TEMP_FILE, SAVE_MAILF);
                   rm(TEMP_FILE);

              // 待扩展 ...
              case "refuse" : 
              case "reply" :
              case "reply_msg": 
              case "no_name" :
        }       
}
