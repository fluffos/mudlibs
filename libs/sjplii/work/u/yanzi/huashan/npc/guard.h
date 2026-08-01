// guard.h 华山npc保护本派弟子
void init() {
  add_action("do_killing", "kill");
}
int do_killing(string arg) {
  object player, victim;
  player = this_player();
  if (!arg)
    return 0;
  if (objectp(victim = present(arg, environment(this_object())))) {
    if (victim->query("id") != this_object()->query("id")) {
      if (present("gangjian", this_object())
        || present("changjian", this_object()));
      command("wield jian");
      return 0;
    }
    if (victim->query("family/family_name") == "华山派") {
      message_vision("$N大怒，大胆狂徒，竟敢在华山动手，未免太小看我们华山派吧！受死吧！\n", this_object());
      if (present("gangjian", this_object())
        || present("changjian", this_object()));
      command("wield jian");
      this_object()->kill_ob(player);
      player->kill_ob(this_object());
      return 0;
    } else return 0;
  } else return 0;
}
void killed_enemy(object ob) {
  command("say 哈哈, 不自量力的家伙！");
  if (present("gangjian", this_object())
    || present("changjian", this_object()));
  command("unwield jian");
}
