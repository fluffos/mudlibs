/*
 * blood.c -- written by Chameloid for Tubmud
 * adapted for the latest version of liquid, Coogan, 16-Feb-98
 *
 */

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <persistence.h>
#include <colours.h>

inherit "complex/liquid";

void configure() {
  liquid::configure();
  set_persistence(__FILE__, PER_KEEP_VARS);
  set_name("blood");
  set_id(({ "blood", "liquid" }));
  set_short("some blood");
  set_long("It's red, as blood usually is.\n");
  set_colour(COLOUR_RED);
  set_taste("coppery");
  set_drying_rate(300);
}

