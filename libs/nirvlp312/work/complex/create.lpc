/*
 * /complex/create.c - version of basic/create for complex items which
 * can be configured and populated; by Alfe for Tubmud 97-Nov-26
 *
 * The functions configure(), populate(), and in a few cases also create()
 * and refresh() are meant to be overridden by the inheriter. The functions
 * create(), configure(), and populate() will be called when the object is
 * created, refresh() and again populate() are called when the reset call
 * from the driver takes place (this is valid for all clones as well as the
 * blueprint).
 */

inherit "basic/create";

void configure() {}

void populate() {}

/* The next two functions are meant to be overridden by classes
 * (like vrooms) which don't want the populate to take place in
 * every case, e.g. not in the blueprint. Ugh Mar-8-02
 */
status query_no_populate() { return 0; }

status query_no_configure() { return 0; }

void refresh() {
  "basic/create"::refresh();
  if (!query_no_populate())
    populate();
}

void create() {
  "basic/create"::create();
  if (!query_no_configure())
    configure();
  if (!query_no_populate())
    populate();
}
