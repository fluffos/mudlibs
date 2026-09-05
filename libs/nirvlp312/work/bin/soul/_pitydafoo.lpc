inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pity da foo' that be antagonizin' you!\n", "$MN$ pities da foo' that be antagonizin' $MO$!\n");
       target("You pity dat foo' #TN#, 'cause #TS# be antagonizin' you!\n", "$MN$ pities dat foo' #TN#!\n", "$MN$ pities you fo' a foo', 'cause you be antagonizin' him!\n");
       afar("From afar, you pity dat foo' #TN#, 'cause #TS# be antagonizin' you!\n", "From afar, $MN$ pities you fo' a foo', 'cause you be antagonizin' him!\n");
    }
}

int
cmd_pitydafoo(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
