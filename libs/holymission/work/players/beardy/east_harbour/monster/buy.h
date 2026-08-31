#define S_T_PRICE 400
#define C_T_PRICE 1000

int mybuy(string str)
{ if(!str) return 0;

  if(str=="ticket")
  { write("What do you want, a single ticket or a commutation ticket ?\n");
    return 1;
  }

  if(str=="single ticket")
  { if(this_player()->query_money()>=S_T_PRICE)
    { write("You buy a single ticket.\n"+
          "It costs you "+S_T_PRICE+" coins.\n");
      this_player()->add_money(-1*S_T_PRICE);
        move_object(clone_object("/players/beardy/east_harbour/obj/sticket"),this_player());
    }
    else
      write("You don't have enough money.\n" +
            "The price are "+S_T_PRICE+" coins.\n");
    return 1;
  }

  if(str=="commutation ticket")
  { if(this_player()->query_money()>=C_T_PRICE)
    { write("You buy a commutation ticket.\n" +
            "It costs you "+C_T_PRICE+" coins.\n");
      this_player()->add_money(-1*C_T_PRICE);
       move_object(clone_object("/players/beardy/east_harbour/obj/cticket"),this_player());
    }
    else
      write("You don't have enough money.\n" +
            "The price are "+C_T_PRICE+" coins.\n");

    return 1;
  }
  return 0;
}
