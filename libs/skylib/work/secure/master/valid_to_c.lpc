/*  -*- LPC -*-  */

int valid_compile_to_c() {
  if (previous_object() == this_object())
    return 1;
  if (previous_object() != find_object("/secure/cmds/creator/compile"))
    return 0;
  if (!interactive(previous_object(1)))
    return 0;
  if (!sizeof(filter(previous_object(-1),(: lordp($1) :))))
    return 0;
  return 1;
} /* valid_compile_to_c() */
