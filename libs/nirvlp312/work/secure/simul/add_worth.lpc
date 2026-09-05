void add_worth(int value, object ob) {
  mixed old;

  switch(explode(file_name(previous_object()), "/")[1]) {
    default:
      raise_error("Illegal call of add_worth.\n");
    case "obj":
    case "room":
    case "secure":
  }
  if (!ob) {
    if (!(ob = previous_object(1))) return;
  }
  if (intp(old = get_extra_wizinfo(ob)))
    set_extra_wizinfo(ob, old + value);
}

