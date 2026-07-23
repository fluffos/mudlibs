  void unconcious()
{
  die();
}

void powerup()
{
object me = this_object();
string title = WHT"【"NOR HIY" 圣 战 "NOR HIB" 冥 界 "NOR WHT"】"NOR;
title+=HIC+me->query("name")+HIC"("+capitalize(me->query("id"))+")："HIC; 
random(2)?
message("channel:music",title+"燃烧吧，小宇宙！\n"NOR,users()):
message("channel:chat",title+"三途河！给我力量！\n"NOR,users());
me->set("kee",query("max_kee"));
me->set("eff_kee",query("max_kee"));
me->set("sen",query("max_sen"));
me->set("eff_sen",query("max_sen"));
me->set("force",query("max_force")*2);
me->set("mana",query("max_mana")*2);
me->clean_condition();
return;
}
 
