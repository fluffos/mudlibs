int can_do_fate(string city)
{
 mapping cond = ([
                  "safe":160
                  ]);
 return FATE_D->get_damage_level(city,cond,0);
}
void do_fate(string city,int r)
{
 string msg;
 mapping effect = ([
                    "agriculture" :-30,
                  ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_RED%^%^H_YELLOW%^【天道】"+AREA_D->get_area(city,"name")+
               "忽然出现大批蝗虫，数量有"+chinese_number(r)+"百万，当地农业遭受严重损失。\n%^RESET%^";
 tell(users(),msg);
 //SGSYS(msg);
}
