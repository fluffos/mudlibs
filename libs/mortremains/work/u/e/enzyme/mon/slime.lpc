
#include <mudlib.h>
inherit MONSTER;
void reset (status arg) {
  ::reset(arg);
  if(!arg) {
    set_name("green slime");
    set_alias("slime");
    set_short("A foul smelling slime");
    set_long (
" You have inadvertantly disturbed what appears to be nothing more than a pile\n
"+
" of greenish colored slime. You can vaguely make out the remains of its former\
n"+
" victims still being slowly digested amid its flowing entrails. The smell alone
\n"+
" is almost enough to make you puke!\n");
    set_race("Slime");
    set_smell(
" You feel like you are going to puke every time you inhale.\n");
    set_level(15);
set_alignment(0);
    set_multi_attack(2);
    set_aggressive(1);
    set_hp(1100);
    set_max_hp(1100);
    set_ac(10);
    set_money(300+random(300));
  }
}
