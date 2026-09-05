/*****************************************************************************
      /complex/tool.c -- an item which is also a tool -- Ugh Oct-01
******************************************************************************/
inherit "basic/tool";
inherit "complex/item";

void create() {
  tool::create();
  item::create();
}

status handle_event(mapping e, string t, int p) {
  return
    tool::handle_event(e,t,p) ||
    item::handle_event(e,t,p);
}
