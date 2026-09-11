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
                    "population" :-20,
                    "st"         :-20,
                    "industry"       :-20
                  ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_RED%^%^H_YELLOW%^【天道】"+AREA_D->get_area(city,"name")+
               "发生"+chinese_number(r)+"级强烈地震，该城遭到严重损毁。%^RESET%^\n";
 tell(users(),msg);
 //SGSYS(msg);
}
