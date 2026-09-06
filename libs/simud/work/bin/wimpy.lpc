main(string param) {
  int num;
  if (!param || sscanf(param,"%d",num) != 1) {
    num = this_player()->query_wimpy();
    msg("You will currently wimp out when your hp drops below "+num+"%.");
    return 1;
  }
  if (num < 0 || num > 100) {
    msg("Cannot set wimpy to "+num+"%");
    return 1;
  }
  if (num == 0)
    msg("Wimpy turned off. Good luck, you brave idiot, you...");
  else
    msg("Wimpy set to "+num+"% ("+(num*this_player()->query_maxhp()/100)+" hp)");
  this_player()->set_wimpy(num);
  return 1;
}
