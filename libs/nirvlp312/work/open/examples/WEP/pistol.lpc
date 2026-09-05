inherit "obj/weapon";

int ammo;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("pistol");
  set_alias("beretta");
  set_short("8mm Beretta");
  set_long(
"The Beretta Model 85 is medium-framed pistol with a chrome finish.\n"
  );
  set_class(12);
  set_weight(2);
  set_value(600);
  ammo=12;
  set_hit_func(this_object());
  message_hit=({
    "blew"," away",
    "blasts","",
    "shot"," with expert accuracy",
    "shot","",
    "hit","",
    "winged","",
    "grazed","",
  });
}
int weapon_hit(object attacker)
{
  object clip;
  if(ammo<=0) {
    clip=present("8mm ammo");
    if(!clip) return -3;
    ammo+=(int)clip->reload();
    write("You reload your pistol.\n");
    return -2;
  }
  if(!random(3)) {
    ammo--;
    write((string)this_player()->query_name()+" fires "+(string)this_player()->query_possessive()+" 8mm Beretta!\n");
    return 5;
  }
  return 0;
}
void long(string str) {
  ::long(str);
  write("Ammo: "+ammo+"\n");
}
