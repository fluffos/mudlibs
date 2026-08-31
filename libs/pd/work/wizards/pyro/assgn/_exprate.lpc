#include <std.h>

inherit DAEMON;

int cmd_exprate(string str) {
  int amount = 0;
  object tp = this_player();
  string line = "";
  if(str && sscanf(str, "buffersize %d", amount) != 1) {
    return notify_fail("Proper syntax: <exprate> or <exprate buffersize [amount in seconds]>\n");
  }
  if(str) {
    if(amount < 60)
      return notify_fail("You cannot set a buffer size smaller than 60 seconds.\n");
    else if(amount > 162000)
      return notify_fail("You cannot set a buffer size larger than 45 minutes.\n");
    write("Exp rate tracker buffer size set to "+amount+".");
    tp->set_exp_rate_sample_size(amount);
    return 1;
  }

  line += "%^RESET%^%^GREEN%^Exp/Second: %^BOLD%^%^CYAN%^";
  line += tp->get_exp_per_second();
  line += "  %^YELLOW%^Exp/Minute: %^CYAN%^";
  line += tp->get_exp_per_minute();
  line += "  %^RED%^Exp/Hour: %^CYAN%^";
  line += tp->get_exp_per_hour();
  write(line);
  return 1;
}

int help() {
    write("Proper syntax:\n <exprate>\n <exprate buffersize [amount in seconds]>\n\n"
      "<exprate>:\n"
      "Displays the rate at which you are currently gaining\n"
      "experience, based off how much experience you have gained\n"
      "in a specific time frame.\n\n"
      "<exprate buffersize [amount in seconds]>:\n"
      "Your exp rate will be calculated by how much exp you have\n"
      "gained in the last [amount] seconds, where [amount] can\n"
      "be modified with this command. (DEFAULT: 300)\n"
      "If your exprate is too inaccurate, or you are gaining exp\n"
      "in large increments with a large amount of time passing between\n"
      "each exp gain, set buffersize to a larger number. If it is too\n"
      "slow to update, set it to a smaller number.\n");
    return 1;
}
