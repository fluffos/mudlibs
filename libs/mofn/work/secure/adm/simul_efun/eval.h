void reset_eval_cost() {
  if(ACCESS_H -> has_permission(PO, "efun", "reset_eval_cost", PERM_EXECUTE))
    efun::reset_eval_cost();
}

int set_eval_limit(int limit) {
  if(limit == -1 ||
     ACCESS_H -> has_permission(PO, "efun", "set_eval_limit", PERM_EXECUTE))
    return efun::set_eval_limit(limit);
}
