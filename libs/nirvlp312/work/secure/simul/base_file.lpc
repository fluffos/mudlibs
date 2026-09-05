string base_file(mixed arg) {
  int i;

  if (objectp(arg)) arg = object_name(arg);
  if (!stringp(arg)) raise_error("base_file(): Bad type to argument 1.\n");
  if ((i = member(arg, '#')) != -1) arg = arg[0..i-1];
  return arg;
}

