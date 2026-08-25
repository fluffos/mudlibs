mixed get_alert_msg(string city,int times)
{
return 1; //NO_ALERT
}

int can_do_fate(string city)
{mapping cond = ([
                   "agriculture":120,
                   "safe":140
                  ]);
 return FATE_D->get_damage_level(city,cond,1);
}
void do_fate(string city,int r)
{
 string msg;	
 mapping effect = ([
                    "agriculture":20,
                    "st"         :10
                  ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_MAGENTA%^%^H_CYAN%^【天道】："+AREA_D->get_area(city,"name")+
               "喜获丰收，等级为"+chinese_number(r)+"，当地百姓欢天喜地。%^RESET%^\n";
 tell(users(),msg);
 //SGSYS(msg);
}
