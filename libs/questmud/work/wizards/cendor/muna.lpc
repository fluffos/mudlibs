object *find_all_living(string name) {
  object ob, *all;
  closure live;
  int i;

  live = unbound_lambda(({'live_name}),({#'set_living_name,'live_name}));
  for(all = ({}),i = 0; (ob = find_living(name)) && i < 45; i++) {
    if(member_array(ob, all) != -1) break;
    all += ({ ob, });
    funcall(bind_lambda(live,ob),"DUMMY");
  }
  for(i = sizeof(all); i--; ) {
    funcall(bind_lambda(live,all[i]),name);
  }
  return all;
}

