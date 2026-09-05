inherit "obj/weapon";
object ob;
int amt;
query_save_flag() {return 1;}

long() {
if(amt > 1) {
        write("A 3 foot long Bow that looks like it could do some REAL!! damage.\n");
     write("You even wonder if you can pull back the massive string on it!\n");
return 1;}
 else {
    write("This is an ordinary bow, it is about 3 feet long\n");
    write("and looks capable of doing  damage.\n");
      return 1; }
}

decay() {
write("The Bow in your hand bursts forth with energy!\n");
   say(capitalize(this_player()->query_real_name()) +"'s Bow surges with power!\n");
set_name("bow");
set_short("A Long Bow");
}

reset(arg) {
   if(!arg) {
      ::reset(arg);
      set_name("ram-bow");
      set_alt_name("bow");
      set_short("The Ram-Bow");
      set_alias("ram-bow");
      set_class(8);
      set_hit_func(this_object());
      set_weight(4);
amt = 10;
   }
}

init() {
::init();
add_action("kill","kill");
}
kill(str) {
object ob;
ob = present(str,this_player());
if(ob->query_npc() < 1) {
write("This weapon can not be used on players.\n");
return 1;
}
}
weapon_hit(attacker) {
int dmg,dmg2,exp;

   while(amt>1){
      if (random(30) > 20) {
     if(this_player()->query_spell_point() < 7) return 0;
         write("Swish!!\n\n");
say(capitalize(this_player()->query_real_name())+"'s Bow lets go of an enormously powerful shot !!\n");
   this_player()->add_spell_point(-7);
         return 15;
         amt--;
         }
     if(this_player()->query_spell_point() < 12) return 0;
      write("You pull an arrow from your quiver and fire it into your enemies heart!!!\n\n");
say(capitalize(this_player()->query_real_name())+"'s Bow unleashes arrows faster than you can see!!!\n");
      amt--;
      write("You have "+amt+" shots left.\n");
   this_player()->add_spell_point(-12);
      return 25;
   }
   if(amt < 0) return 0;
   if(amt == 1) {
     if(this_player()->query_spell_point() < 85) return 0;
  write("You pull your final arrow from your quiver, examining it\n" +
        "you notice it has a metal tip.  Examining it closer you \n" +
        "you see the tip is lace with explosives.  As you load\n" +
       "the arrow into the bow, you feel an aura of power, pulling\n" +
          "back on the string, you fire the arrow.  It flies through\n" +
     "the air at incredible speed, striking the heart of your \n" +
       "opponent, killing him instantly!\n\n\n" +
         "KA BOOM!!!!!!!!!!!\n");
      say(capitalize(this_player()->query_real_name())+"'s "+
"Bow fires an incredible shot into its enemies heart killing\n" +
   "it instantly!!!!!\n\n\n" +
  "KA BOOM!!!!!!!!!!\n");
      amt--;
    this_player()->add_spell_point(-85);
   ob=this_player()->query_attack();
  dmg = ob->query_hp();
   ob->heal_self(-(dmg+4));
  this_player()->add_hit_point(-15);
}
if(amt ==0) {
      decay();
      amt--;
      return 5; }
}

