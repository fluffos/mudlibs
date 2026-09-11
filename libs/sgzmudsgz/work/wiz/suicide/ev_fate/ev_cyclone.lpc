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
                    "population" :-5,
                    "st"         :-10,
                    "gold"   :-10
                  ]);
FATE_D->area_effect(city,effect,r);
  msg = "%^B_RED%^%^H_YELLOW%^【天道】"+AREA_D->get_area(city,"name")+
               "遭飓风侵袭，级别为"+chinese_number(r)+"，城市遭到严重破坏，百姓多有死伤。\n%^RESET%^";
 tell(users(),msg);
 //SGSYS(msg);
}
