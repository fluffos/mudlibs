string *dests=({"walhalla","/players/beardy/port/pwalhalla",
                "town"    ,"/players/beardy/port/ptown",
                "magi"    ,"/players/beardy/port/pmagi",
                "island"  ,"/players/beardy/port/pisland",
                "ezo"     ,"/players/patience/ezo/coast/c1",
                "shore"   ,"/players/beardy/port/pshore"});

int myrent(string str)
{ int flag,i,j,time,times,place;
  object *env, dummy2;
  int journeytime;
  string dummy;

  flag=0;

  if(!str)
  { write("rent what ?\n");
    return 1;
  }

  sscanf(str,"boat to %s",dummy);  

  env = all_inventory(this_player());
    for(i=0,j=sizeof(env); i<j; i++) 
    {
       if((env[i]->query_name()=="single ticket" || env[i]->query_name()=="commutation ticket") && (stringp(env[i]->short())))
       { flag=1;
        place=i;
         break;
       }
    }
    if(flag==1)
    { for(i=0,j=sizeof(dests);i<j;i++)
      { if(dests[i]==dummy)
        { flag=-1;
          break;
        }
      }
      if(flag==-1)
      { write("You take the boat to "+dummy+" .\n");
        transfer(this_player(),"/players/beardy/port/ship");
        journeytime=20+random(20);
        call_out("ending",journeytime,i);
        i--;
        if(env[place]->query_name()=="single ticket")
        { dummy2=env[place];
          destruct(dummy2);
        }
      }
      else
       write("Illegal destination\n");
      return 1;
    }
    else
      write("You have not ticket.\n");
  return 1;
}

int ending(int i)
{ write("I hope you had a nice journey.\n");
  transfer(this_player(),dests[++i]);
  return 1;
}
