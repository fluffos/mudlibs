void unconcious()
{
  die();
}

void powerup()
{
object me = this_object();
random(2)?
message("channel:music",HIY"【黄道十二宫】"+me->query("name")+HIY"("+me->query("id")+HIY"): 燃烧吧，小宇宙！\n"NOR,users()):
message("channel:sldh",HIY"【黄道十二宫】"+me->query("name")+HIY"("+me->query("id")+HIY"): 小宇宙！爆发吧！\n"NOR,users());
me->set("kee",query("max_kee"));
me->set("eff_kee",query("max_kee"));
me->set("sen",query("max_sen"));
me->set("eff_sen",query("max_sen"));
me->set("force",query("max_force"));
me->set("mana",query("max_mana"));
me->clean_condition();
return;
}


