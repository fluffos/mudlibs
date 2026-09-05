inherit "obj/food";
int fart;

reset(arg) {
  if(arg) return;
  set_name("samples");
  set_alias("bag");
  set_alt_name("samples");
  set_weight(2);
  set_value(1500);
/* 30 hp is more than a half heal!! see the intox chart. this item MUST
COST THE PLAYER 3000 coins per CHARGE!!! or as it is now 30,000 coins. -Bp */
 /* why doesnt this go down with loss of charges???  */
  set_strength(30);
set_short("Bag of tissue samples");
set_eater_mess("You stick your hand inside the bag and pull out a\n"+
               "nice, juicy sample of flesh and woof it down.\n");
set_eating_mess(" hand disappears into the bag of tisue samples and\n"+
                "pulls out a skin colored piece of flesh to eat.\n");
fart=10;
}
long() {
write("This is a bag containing many different samples of flesh.\n"+
      "Right now the bag contains "+fart+" tissue samples.\n");
       }
init()
{
::init();
add_action("do_eat", "eat");
}
do_eat(str)

{
if(fart<1)
{
write("The bag is empty and disappears.\n");
destruct(this_object());
return 1;
}
if(!str) return;
if(!call_other(this_player(), "eat_food", 30)) {
   write("Ha! To full!\n");
return 1;
}
if(str == "tissue")
{
write("You reach inside the bag and pull out a skin colored tissue\n"+
      "sample and woof it down.\n");
this_player()->heal_self(30);

fart -=1;
return 1;
}
}

query_save_flag() { return 1; }
/* added by mizan */
