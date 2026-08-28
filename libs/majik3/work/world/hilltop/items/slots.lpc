inherit ITEM; 

#define pline(x) message("0", x, THIS)
#define room(x) message("3", x, ENV(THIS), THIS)

int jackpot = 50;
int money = 0;

create_item ()
{
  set_name (({ "machine", "gnomish", "slot machine" }));
  set_short ("a Gnomish slot machine");
  restore_object ("/data/misc/slots");
  set_no_get();
}

long ()
{
  return "You can play this game by typing \"play slots\".\n"
+ "The current jackpot is "+jackpot+" gold pieces.\n";
}

init ()
{
  add_action ("do_play", "play");
  add_action ("do_kick", "kick");
}

do_kick (string str)
{
  if (str != "machine") {
    notify_fail ("Kick who?\n");
    return 0;
  }

  write ("You kick "+THOB->short()+" -- *klonk* !\n");
  tell_room (environment(), THIS->query_cap_name() +" kicks "+THOB->short()+" -- *klonk* !\n", ({THIS}));
  return 1;
}

do_play (string str)
{
  int num1, num2, num3, win = 0;
  string buf;

  string *slot_msg = ({
        "*YOU SHOULDN'T SEE THIS*",
        "^cYa mithril bar^c0",              /* 1 */
        "^cya golden dragon^c0",
        "^cLa Dwarven hammer^c0",
        "^cWa temple^c0",
        "^cgan Elven bow^c0",               /* 5 */
        "^cRa red brick^c0",
        "^cba refuse pile^c0",
        "^cGa waybread^c0",
        "^cCa Gnomish bell^c0",
        "^cpa beggar^c0",                   /* 10 */
     });

  if (str != "slots")
    return 0;

  if (THIS->query_money() < 1)
    {
      pline ("You do not have enough money to play the slots!\n");
      return 1;
    }
  else
    THIS->add_money (-1);

  jackpot++;
  money++;

  if (money < 0)
    money = 0;

  room (THIS->query_cap_name() + " pulls on the crank of the Gnomish slot machine.\n");
  pline ("You pull on the crank of the Gnomish slot machine.\n");

  num1 = random(10) + 1;
  num2 = random(10) + 1;
  num3 = random(10) + 1;

  if (num1 == num2 /* && num2 == num3 */ && money > 25) {
        if (num1 == 1) {
           win += jackpot;
           jackpot = 50;
        }
        else if (num1 == 2)
           win += money / 2;
        else if (num1 == 3)
           win += money / 5;
        else if (num1 == 4)
           win += money / 10;
        else if (num1 == 5)
           win += money / 15;
        else if (num1 == 10)
           win += money / 25;
     }

     money -= win;
     save_object ("/data/misc/slots");

     buf = sprintf("You got %s, %s, %s, ", slot_msg[num1],
             slot_msg[num2], slot_msg[num3]);
     if (win > 1)
        buf = sprintf("%syou win %d gold pieces!\r\n", buf, win);
     else if (win == 1)
        buf = sprintf("%syou win 1 gold piece!\r\n", buf);
     else
        buf = sprintf("%syou lose.\r\n", buf);

     pline(buf);
     THIS->add_money(win);

  return 1;
}
