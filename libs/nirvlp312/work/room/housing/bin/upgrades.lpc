#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

/* Global Variables */
mapping Upgrades;

status
main(string arg, object room, object master)
{
  string *t;
  int i;

  i = sizeof(t = m_indices(Upgrades));

  if (!i)
  {
    this_object()->reset(0);
    return main(arg, room, master);
  }

  if (!arg || !strlen(arg))
  {
    int j, siz;
    string *curr;
    
    siz = sizeof(curr = (string *)master->query_upgrades());
    j = 0;
    
    if (siz)
      write(HIK+"Current Upgrades:\n"+NORM+NORM
        + (string)HOUSED->dump_upgrades(master)+"\n");
        
    write(HIK+"Available Upgrades:\n"+NORM+NORM);
  
    while(i--)
      if (!siz || member_array(t[i], curr) < 0)
      {
        write(pad((string)UTILITYD->comma_number(Upgrades[t[i]]), 11)
          + " -  "+t[i]+"\n");
        j++;
      }
      
    if (!j)
      write("No other upgrades currently available.\n");
    
    write("\nUse "+HIW+"upgrades "+HIK+"<name>"+NORM+NORM+" to purchase an upgrade.\n");
    write("See "+HIW+"hinfo upgrades"+NORM+NORM+" for information regarding upgrades.\n");
    return 1;
  }
  
  if (!member(Upgrades, arg))
  {
    notify_fail("Invalid upgrade to purchase.\nUse "+HIW+"upgrades"+NORM+NORM+" to see available upgrades and their costs.\n");
    return 0;
  }
  
  if ((int)this_player()->query_bank_balance() < Upgrades[arg])
  {
    notify_fail(HIK+"You lack the funds to purchase this upgrade."+NORM+NORM
      +"\nUpgrade:  "+arg
      +"\nCost:     "+Upgrades[arg]
      +"\nYou have: "+(int)this_player()->query_bank_balance()
      +"\nYou can see the problem.\n");
    return 0;
  }

  if (!((status)master->add_upgrade(arg)))
    return 0;

  this_player()->add_bank_balance(-Upgrades[arg]);
  write("You have purchased the following upgrade: "+HIK+arg+NORM+NORM+".\n");
  write("See "+HIW+"hinfo upgrades"+NORM+NORM+" for information regarding upgrades.\n");        
  write(Upgrades[arg]+" coins have been withdrawn from your bank account.\n");
  master->save_info();
  return 1;
}

void reset(status arg) {
  int i, price;
  string *t;
  string desc, text;

  if (arg)
    return;

  text = read_file(UPGRADES);
  i = sizeof(t = explode(text, "\n"));
  Upgrades = ([ ]);

  while(i--)
  {
    sscanf(t[i], "%s::%d", desc, price);
    Upgrades += ([ desc : price ]);
  }
}
