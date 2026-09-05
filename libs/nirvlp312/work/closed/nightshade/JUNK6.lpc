inherit "obj/treasure";
int blood;
reset(arg) {
if (arg) return;
set_short("Bag of gods blood");
set_weight(1);
set_alias("bag");
set_value(5000);
}
long() {
write("This is a bag containing the blood of an unknown god.\n"+
      "It was acquired at great expense and therefore is quite\n"+
      "expensive. It does contain amazing healing properties\n"+
      "considering its sourse.\n");
   }
init()
{
add_action("do_inject", "inject");
}
do_inject(str)
{
if(id(str))
{
if(!call_other(this_player(), "drink_alcohol",13))
{
write("You have to much blood in you already!\n");
return 1;
}
if(call_other(this_player(), "drink_alcohol", 20))
{
say(call_other(this_player(), "query_name") + " winces as they insert the needle into a vein.\n");
write("You wince as you stick the needle into a swollen vein but feel\n"+
"a slight buzz as the blood rushes into you.\n");
call_other(this_player(), "heal_self", 200);
destruct(this_object());
return 1;
}
}
else {return 0; }
}
