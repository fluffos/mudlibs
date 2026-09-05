
/*
 * FuzzyBeast.c Version 1.0
 * Mizan@Nirvana
 */

inherit "obj/monster";

string short_desc;
string long_desc;
int long_num;
int short_num;

reset(arg) {
  if(arg) return;
  ::reset(arg);
  if(short_desc || long_desc) {
  long_num=random(sizeof(long_desc)-1);
  short_num=random(sizeof(short_desc)-1);
  set_short(short_desc[short_num]);
  set_long(long_desc[long_num]);
 }
}

