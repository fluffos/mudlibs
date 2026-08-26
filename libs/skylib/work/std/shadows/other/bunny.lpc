inherit "/std/effect_shadow";

protected void real_eat(object ob);
protected void do_eat_carrot();

mixed move(mixed dest, string messin, string messout) {
  int ret;

  ret = player->move(dest, messin, messout);
  if (ret == 0) {
    call_out((: do_eat_carrot :), 0);
  }
  return ret;
} /* move() */

protected void do_eat_carrot() {
  object ob;

  foreach (ob in all_inventory(player)) {
    if (ob->query_edible() && (ob->query_name() == "carrot")) {
      call_out((: real_eat :), 1, ob);
    }
  }
} /* do_eat_edible() */

protected void real_eat(object ob) {
  if (ob && player) {
    tell_object(player, "You eat " + ob->the_short() + ".\n");
    tell_room(environment(player), player->one_short() + " eats " +
              ob->the_short() + ".\n", player);
    ob->move("/room/rubbish");
  }
} /* real_eat() */

void event_enter(object ob, string mess, object from) {
  player->event_enter(ob, mess, from);
  if (ob->query_edible() && (ob->query_name() == "carrot")) {
    call_out("real_eat", 2, ob);
  }
} /* event_enter() */

int query_disguised() { return 1; }

string query_determinate(object thing) {
  if (arg())
    return "a ";
  return (string)player->query_determinate(thing);
} /* query_determinate() */

string pretty_short(object thing) {
  if (!arg()) {
    return (string)player->pretty_short(thing);
  }
  if (objectp(thing)) {
    if (creatorp(thing)) {
      return "fluffy pink rabbit ("+ (string)player->query_name() +")";
    }
  }
  return "fluffy pink rabbit";
} /* pretty_short() */

string pretty_plural(object thing) {
  if (!arg()) {
    return (string)player->pretty_short(thing);
  }
  if (objectp(thing)) {
    if (creatorp(thing)) {
      return "fluffy pink rabbits ("+ (string)player->query_name() +")";
    }
  }
  return "fluffy pink rabbits";
} /* pretty_plural() */
