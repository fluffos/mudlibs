mixed get_alert_msg(string city,int times)
{
return 1; //NO_ALERT
}
int can_do_fate(string city)
{mapping cond = ([
                  "safe":160
                  ]);
 return FATE_D->get_damage_level(city,cond,1);
}
void do_fate(string city,int r)
{
 string msg;
 mixed * objname=({"玉佩","玉环","玉珏","铜斛","铜雀",
 "铜鼎","银杯","金印","和氏璧","玉玺"}) ;
 mapping effect = ([
                    "agriculture":10,
                    "industry"   :10,
                    "business"   :10,
                    "population" :20
                   ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_MAGENTA%^%^H_CYAN%^【谣言】某人："+AREA_D->get_area(city,"name")+
 "百姓挖出前朝的"+ chinese_number(r)+"级宝物"+objname[r-1]+
        "纷纷视为祥瑞，因此实力大涨。%^RESET%^\n";
 tell(users(),msg);
 //SGSYS(msg);
}
