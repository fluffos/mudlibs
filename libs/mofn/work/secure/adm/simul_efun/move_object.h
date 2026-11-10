void move_object(mixed ob) {
  object tp, *obs, bing;

  if(stringp(ob))
    ob = find_object(ob);

  if(!objectp(ob))
    return;

  if(!ACCESS_H -> has_permission(PO, "file", base_name(ob), PERM_MOVE))
    return;

  evaluate(bind((: efun::move_object($(ob)):), previous_object()));

  if(ob -> no_init())
    return;

  tp = TP;

  if(living(PO)) {
    set_this_player(PO);
    ob -> init();
  }

  obs = filter(INV(ob), (: living($1) :));
  foreach(bing in obs) {
    set_this_player(bing);
    PO -> init();
  }

  set_this_player(tp);
}
