// fealty.c 
// by Suicide on August 2, 2000
// used for one player swear fealty to another.

int is_real_taishou(string my_id)
{string my_area,leader;
 mixed grant;
 my_area = CHAR_D->get_char(my_id,"area");
 leader  = AREA_D->get_area(my_area,"leader");
 if (leader ==my_id) return 1;
 if (grant=CHAR_D->get_char(leader,"grant"))
    if (grant["leader"]==my_id) return 1;
 return 0;
}

void start(string arg)
{
        string my_id,f_id,msg,my_na,my_area;
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->char_exist(my_id))
        {
                write("你现在还不是角色无法宣誓效忠？！\n");
                return;
        }
        if (arg=="")
           {if ((f_id=CHAR_D->get_char(my_id,"fealty"))!=my_id)
               printf("你现在宣誓效忠的是%s(%s)。\n",
                      CHAR_D->get_char(f_id,"name"),f_id);
	    else
	     write("你现在没有效忠任何人啊？！\n");
	   }
        else
          {
          if (arg=="none") 
             if ((f_id=CHAR_D->get_char(my_id,"fealty"))!=my_id)
             {msg=sprintf("%s由于对%s不满，决定脱离%s的派系。",
	      CHAR_D->get_char(my_id,"name"),
	      CHAR_D->get_char(f_id,"name"),
	      CHAR_D->get_char(f_id,"name"));
	      CHAR_D->set_char(my_id,"fealty",0);
	      CHANNEL_D->deliver_tell("rumor","system",msg);     
	      return;
	     }
          	
          if(!CHAR_D->char_exist(arg))
            {write("你要宣誓效忠的角色不存在啊，你是不是搞错了？！\n");
             return;}
          my_na   = CHAR_D->get_char(my_id,"nation");
          my_area = CHAR_D->get_char(my_id,"area");
          if (((CHAR_D->get_char(my_id,"ranknation")>0)||     //国家官员和太守只能向国王
               (is_real_taishou(my_id)))&&
               (my_na!=arg)&&
              (COUNTRY_D->get_country(my_na,"gs")!=arg))
             write("对方既不是你的主公又不是你国的国师，还犯不着宣誓效忠吧！？\n"); 
          else
            {msg=sprintf("%s受到%s的感召，决定加入%s的派系。",
	     CHAR_D->get_char(my_id,"name"),
	     CHAR_D->get_char(arg,"name"),
	     CHAR_D->get_char(arg,"name"));
	     CHAR_D->set_char(my_id,"fealty",arg);
	     CHANNEL_D->deliver_tell("rumor","system",msg);     
	    }
          }
}