/*
 * /basic/create.c
 *
 * This file is the basic class for all objects that want to do something
 * at their create or refresh
 *
 * If you inherit this file and override reset(), create(), or refresh(),
 * make sure that you call create::reset(arg), create::create(), and
 * create::refresh() respectively in your reset(); otherwise the sense of
 * this class is void.
 */

void refresh() { }

void create() { }

void reset(status arg) {
  if (!arg)
    create();
  else
    refresh();
}
