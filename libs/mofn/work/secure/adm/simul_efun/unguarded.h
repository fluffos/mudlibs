mixed unguarded(function f) {
  object master_ob = master();

  if (!master_ob) {
    master_ob = previous_object();
  }
  if (origin() == ORIGIN_LOCAL) {
    return master_ob->apply_unguarded(f, 1);
  } else {
    return master_ob->apply_unguarded(f);
  }
}
