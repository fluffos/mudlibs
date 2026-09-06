/* Contains the selling functions */
string QueryOwner();

void init()
{
  string uid;

  if((uid = getuid(this_player())) == QueryOwner() ||
     ({string})"/secure/master"->valid_write(object_name(),uid,"sell",this_player()))
    add_action("sell","sell");
}

int sell(string str)
{
  if(!str) {
    notify_fail("What do you want to sell?\n");
    return 0;
  }
  if(str != "house" && str != "here") {
    notify_fail("Go to the next shop to sell that there.\n");
    return 0;
  }
  write("Are you sure you want to sell your house? (y/n) ");
  input_to("sell2");
  return 1;
}

int sell2(string str)
{
  object seller;

  if(str != "y" && str != "yes") {
    notify_fail("You didn't sell your home.\n");
    return 0;
  }
  seller = load_object("/p/houses/common/room/seller");
//  export_uid(seller);
  if(!({int})seller->sell())
    notify_fail("Something strange happended. You couldn't sell your house.\n\
Ask Sique to help you!\n");
  return 0;
}

string QueryOwner() { return 0; }
