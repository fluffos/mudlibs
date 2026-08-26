//Healing.c 
//Originally from ICF
//Rather drastically changed by Peregrin@DarkTowers (Feb 01 1995)
// (04-28-96) Modified again by Chronos@here

int
drink_alco(int strength) {
   int con, drunk, spi;
  drunk = this_object()->query("drunk");
	con = this_object()->query("stat/constitution");
        spi = this_object()->query("stat/spirit");
  if (spi == 1) spi = 2;
  if (con == 1) con = 2;
  if (drunk>5) {
  if (drunk + strength > (spi/2 + con/2)) {
    write("You fail to reach the drink with your mouth.\n");
  return 0;
  }
} else {
  if (strength-5 > (spi/2 + con/2)) {
  write("This stuff is just too strong for you!\n");
  return 0;
  }
  }
  drunk += strength;
  if(drunk < 0)
         write("That helped your hangover a little bit.\n");
  if (drunk == 0)
         drunk = 1;
  this_object()->set("drunk",drunk);
      this_object()->receive_healing(5*strength);
    this_object()->add("spell_points", strength*2);
  return 1;
}

int
drink_soft(int strength, int coffee) {
  int soaked, con, spirit;
  soaked = this_object()->query("soaked");
	con = this_object()->query("stat/constitution");
  spirit = this_object()->query("stat/spirit");
  if (spirit == 1) spirit = 2;
 if (con == 1) con = 2;
  if (soaked) {
  if (soaked + strength > (con/2 + spirit/2)) {
    write("You can't possibly drink that much right now!\n"
     +"You feel crosslegged enough as it is.\n");
    return 0;
  }
  } else {
  if (strength > ( con/2 + spirit/2)) {
  write("That is too much for your frail constitution.\n");
  return 0;
  }
 }
  soaked += strength;
  if(soaked < 0)
    soaked = 0;
   if (soaked < 1) 
    write("You feel a bit dry in the mouth.\n");
  this_object()->set("soaked",soaked);
  if (coffee && this_object()->query("drunk") > 1)
{
  this_object()->add("drunk", -2 * coffee);
  write("The powerful brew sobers you up.\n");
  if (this_object()->query("drunk")<1) {
    write("You feel a headache coming on.\n");
    this_object()->set("drunk", 1);
  }
}
/*
       this_object()->receive_healing(strength);
	this_object()->add("spell_points", 5*strength);
*/
  return 1;
}

int
eat_food(int strength) {
  int stuffed, con, dex;
  stuffed = this_object()->query("stuffed");
	con = this_object()->query("stat/constitution");
  dex = this_object()->query("stat/spirit");   // I'm lazy.  Sue me.
   if (dex == 1) dex = 2;
  if (con == 1) con = 2;
  if (stuffed + strength > (con/2 + dex/2)){
    write("You couldn't eat another bite.\n");
    return 0;
  }
  stuffed += strength;
  if(stuffed < 0)
    stuffed = 0;
  if (stuffed == 0)
    write("Your stomach makes a rumbling sound.\n");
  this_object()->set("stuffed",stuffed);
  this_object()->receive_healing("hit_points", strength);
   this_object()->add("spell_points", 3*strength);
  return 1;
}

