/* Hamlet, August 1997.  -- The manual menuing/paging system. */

inherit "/std/index";

void setup() {
  set_index_root("/doc/man/");
  set_mergedirs( ({ "local/", "mudos/" }) );
//set_save_file("/save/man.o"); /* To avoid indexing every time */
  remove_file_security(); /* All man docs should be viewable by all? */
  set_global_alias_file("_GLOBAL_ALIASES");
}
