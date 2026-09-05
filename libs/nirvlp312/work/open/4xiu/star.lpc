#include <ansi.h>
#define PAIN "/players/pain/NEW/items/star_daemon"
#define P_DIR "players/pain/NEW/items/star_info/"
#define tpn this_player()->query_name()

int muff;
int clr;

set_muff(str) { muff = str; }
query_muff() { return muff; }

set_color(str) { clr = str; }
query_color() { return clr; }

init_arg()
{
  tail("/players/pain/NEW/items/star_news");
/*
call_out("stuff",20);
*/
}


id(str)
{
  object teee,yeee;
  yeee=environment(this_object());
  if(yeee)
    teee=environment(yeee);
  if(teee)
  {
    if(present("star",teee))
      return str == "ND" || str == "tattoo" || str == "star_tattoo";
  }
  return str == "ND" || str == "tattoo" || str == "star" || str == "star_tattoo";
}


long()
{
  if(present("star",environment(this_player()))) return 0;
  write("A small, gold star tattoo above you right inner ankle bone.\n"+
    "This tattoo marks you as a progressively minded individual.\n"+
    "You feel a bond with the others like you. You're quite special.\n"+
    "Use <"+YELLOW+"hstar"+END+"> for more help.\n");
}


get() { return 1; }
drop(){ return 1;}

query_auto_load(){ return "players/pain/NEW/items/star.c:";}

init()
{
  string junk;
  add_action("star", "star");
  add_action("punt", "punt");
  add_action("hstar","hstar");
  add_action("suck","suck");
  add_action("get_rid_of_star", "get_rid_of_star");
  add_action("star_news", "star_news");
  add_action("replace", "s_replace");
  add_action("replace_all", "replace_all");
  add_action("alive","s_who");
  add_action("st","stt");
  add_action("se","ste");
  add_action("model","model");
  add_action("hush","hush");
  add_action("share","share");
  add_action("color","color");
  if(environment() && (environment()->query_level() < 1))
    return destruct(this_object());
}


squeal(arg) { PAIN->squeal(arg); return 1; }
mgrin(arg) { PAIN->mgrin(arg); return 1; }
grumble(arg) { PAIN->grumble(arg); return 1; }
star(arg) { PAIN->star(arg); return 1; }
drool(arg) { PAIN->drool(arg); return 1; }
mango(arg) { PAIN->mango(arg); return 1; }
dream(arg) { PAIN->dream(arg); return 1; }
nudge(arg) { PAIN->nudge(arg); return 1; }
mutter(arg) { PAIN->mutter(arg); return 1; }
punt(arg) { PAIN->punt(arg); return 1; }
cmd_say(arg) { PAIN->cmd_say(arg); return 1; }
nog(arg) { PAIN->nog(arg); return 1; }
fnog(arg) { PAIN->fnog(arg); return 1; }
hnog(arg) { PAIN->hnog(arg); return 1; }
laf(arg) { PAIN->laf(arg); return 1; }
flaf(arg) { PAIN->flaf(arg); return 1; }
ravish(arg) { PAIN->ravish(arg); return 1; }
caress(arg) { PAIN->caress(arg); return 1; }
girn(arg) { PAIN->girn(arg); return 1; }
ffear(arg) { PAIN->ffear(arg); return 1; }
hstar() { PAIN->hstar(); return 1; }
ick() { PAIN->ick(); return 1; }
yuck() { PAIN->yuck(); return 1; }
quiver(arg) { PAIN->quiver(arg); return 1; }
jump() { PAIN->jump(); return 1; }
jazz() { PAIN-> jazz(); return 1; }
suckle() { PAIN->suckle(); return 1; }
blow() { PAIN->blow(); return 1; }
horny() { PAIN->horny(); return 1; }
tongue(arg) { PAIN->tongue(arg); return 1; }
agree(arg) { PAIN->agree(arg); return 1; }
foff(arg) { PAIN->foff(arg); return 1; }
swiggle(arg) { PAIN->swiggle(arg); return 1; }
wibble(arg) { PAIN->wibble(arg); return 1; }
lake(arg) { PAIN->lake(arg); return 1; }
snort() { PAIN->snort(); return 1; }
face(arg) { PAIN->face(arg); return 1; }
boot(arg) { PAIN->boot(arg); return 1; }
lambada(arg) { PAIN->lambada(arg); return 1; }
roll() { PAIN->roll(); return 1; }
mood() { PAIN->mood(); return 1; }
toss() { PAIN->toss(); return 1; }
kissme(arg) { PAIN->kissme(arg); return 1; }
nasty() { PAIN->nasty(); return 1; }
mosh() { PAIN->mosh(); return 1; }
rave() { PAIN->rave(); return 1; }
bummer() { PAIN->bummer(); return 1; }
sucks() { PAIN->sucks(); return 1; }
boring() { PAIN->boring(); return 1; }
wonder() { PAIN->wonder(); return 1; }
sdance(arg) { PAIN->sdance(arg); return 1; }
tstick(arg) { PAIN->tstick(arg); return 1; }
get_rid_of_star() { destruct(this_object()); return 1; }
star_news() { PAIN->star_news(); return 1; }
replace() { PAIN->replace(); destruct(this_object()); return 1; }
replace_all() { PAIN->replace_all(); return 1; }
thigh(arg) { PAIN->thigh(arg); return 1; }
toe(arg) { PAIN->toe(arg); return 1; }
tell(arg) { PAIN->tell(arg); return 1; }
sleep() { PAIN->sleep(); return 1; }
chortle() { PAIN->chortle(); return 1; }
thwak(arg) { PAIN->thwak(arg); return 1; }
phair(arg) { PAIN->phair(arg); return 1; }
noogie(arg) { PAIN->noogie(arg); return 1; }
flirt(arg) { PAIN->flirt(arg); return 1; }
romance(arg) { PAIN->romance(arg); return 1; }
cower() { PAIN->cower(); return 1; }
roar() { PAIN->roar(); return 1; }
howl() { PAIN->howl(); return 1; }
woo() {PAIN->woo(); return 1; }
wish() { PAIN->wish(); return 1; }
boggle() { PAIN->boggle(); return 1; }
flex() { PAIN->flex(); return 1; }
cheer(arg) { PAIN->cheer(arg); return 1; }
fear(arg) { PAIN->fear(arg); return 1; }
lag() { PAIN->lag(); return 1; }
kiss(arg) { PAIN->kiss(arg); return 1; }
alive() { PAIN->alive(); return 1; }
st(arg) { PAIN->pt(arg); return 1; }
se(arg) { PAIN->pe(arg); return 1; }
wedgie(arg) { PAIN->wedgie(arg); return 1; }
model(arg) { PAIN->model(arg); return 1; }
kinky(arg) { PAIN->kinky(arg); return 1; }
cuff(arg) { PAIN->cuff(arg); return 1; }
suck(arg) { PAIN->suck(arg); return 1; }
grok() { PAIN->grok(); return 1; }
whip(arg) { PAIN->whip(arg); return 1; }
share(arg) { PAIN->share(arg); return 1; }

color()
{
  if(query_color() == 0)
  {
    write("~*~ Color Disabled ~*~\n");
    set_color(1);
    return 1;
  }
  if(query_color() == 1)
  {
    write(GREEN+"~*~"+END+" Color Enabled "+GREEN+"~*~"+END+"\n");
    set_color(0);
    return 1;
  }
}


hush()
{
  if(query_muff() == 0)
  {
    write("~*~ You decide to no longer listen to the others ~*~\n");
    set_muff(1);
    return 1;
  }
  if(query_muff() == 1)
  {
    write("~*~ You will again be able to listen to the others ~*~\n");
    set_muff(0);
    return 1;
  }
}


stuff()
{
  if(!environment(this_object())) return 1;
  p_save();
  call_out("stuff",100);
  return 1;
}


p_save()
{
  if(this_player())
    save_object(P_DIR+this_player()->query_real_name());
  return 1;
}


extra_look()
{

/* verte fixed this to display "You have" etc. */
  if(environment() == this_player())
    write("You have a small " + YELLOW + "gold star" + END + " tattoo on " +
      "your inside right ankle.\n");
  else write(environment()->query_name() + " has a small " +
      YELLOW + "gold star" + END + " tattoo on " +
      possessive(environment()) + " inside right ankle.\n");
}
