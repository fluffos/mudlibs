inherit "/obj/monster";

#define TH(x) transfer(clone_object(x),this_object())

void add_stuff()
{
TH("players/goldsun/7-islands/diamond/obj/icicle");
TH("players/goldsun/7-islands/diamond/obj/amulet");
TH("players/goldsun/7-islands/diamond/obj/fur");
command("wear amulet");
if (random(3)<1) command("wield icicle");
command("wear fur");
}

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name(NAME[i]);
set_race("native");
set_short("A rich native");
set_gender(i+1);
set_long("
set_level(14+random(10));
set_wc(9+level);
set_ac(4);
set_size(3);
set_al(30);
add_money(level*2500);
add_stuff();
}

