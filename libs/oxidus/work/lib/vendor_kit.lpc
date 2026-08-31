inherit STD_ITEM;

protected nosave string *__contents = ({});

void mudlib_setup() {
  add_extra_long(
    "instructions",
    "To access the contents of this kit: <open kit>"
  );

  add_command("open", "open");
}

/**
 * Command to open the kit and get the goodies.
 *
 * @param {STD_BODY} tp - This body.
 * @param {string} id - What's being tried to be opened.
 */
mixed open(object tp, string id) {
  if(!id(id))
    return 0;

  /** @type {STD_ITEM} */ object *items = map(__contents, (: new($1) :));

  tp->simple_action("$N $vopen $p a $o.", this_object());
  tp->my_action("$N $vreceive a $o.", items);

  each(items, (: $1->move($(tp)) && $1->move(top_environment($(tp))) :));

  remove();

  return 1;
}
