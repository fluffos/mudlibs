inherit ITEM;

int amount = 1;

string
short()
{
  string ret;

  if (amount == 1)
      ret = "a gold piece";
  else
      ret = amount + " gold pieces";

  if (!amount)
    destruct (THOB);

  return ret;
}

string
long()
{
  return "You see "+lower_case(short())+".\n";
}

create()
{
  set_name (({ "gold", "coins", "pieces", "money", "piece", "coin" }));
}

set_amount (int num)
{
  if(num == 0)
    destruct (this_object());
  else
    return (amount = num);
}

add_amount (int num)
{
  amount += num;
}

int
get (object who)
{
  string nm = capitalize(THIS->query_name());

  who->add_money (amount);

  tell_room (environment(), nm + " gets " + short() + ".\n", ({ who }));
  tell_object (who, "You get " + short() + ".\n");

  destruct (this_object());

  return 2;
}
