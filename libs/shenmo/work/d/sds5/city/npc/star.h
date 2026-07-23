void unconcious()
{
  die();
}

void powerup()
{
object me = this_object();
string title = WHT"【"NOR HIB"圣战"NOR RED"哈帝斯之城"NOR WHT"】"NOR;
title+=HIC+me->query("name")+HIC"("+capitalize(me->query("id"))+")："HIC; 
random(2)?
message("channel:music",title+"燃烧吧，小宇宙！\n"NOR,users()):
message("channel:chat",title+"三途河！给我力量！\n"NOR,users());
me->set("kee",query("max_kee"));
me->set("eff_kee",query("max_kee"));
me->set("sen",query("max_sen"));
me->set("eff_sen",query("max_sen"));
me->set("force",query("max_force"));
me->set("mana",query("max_mana"));
me->clean_condition();
if ( me->query_condition("dashouyin") )  me->apply_condition("dashouyin",0);
return;
}

