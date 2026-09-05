inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You point at everyone and yell:  HEY, BITCHHOLES(tm)!!! CUT IT OUT!!!$N$\n", "#CMN# points at everyone and yells:  HEY, BITCHHOLES(tm)!!! CUT IT OUT!!!$N$\n");
       target("You point at #CTN# and yell:  HEY, BITCHHOLE(tm)!!! CUT IT OUT!!!$N$\n", "#CMN# points at #CTN# and yells:  HEY, BITCHHOLE(tm)!!! CUT IT OUT!!!$N$\n", "#CMN# points at you and yells:  HEY, BITCHHOLE(tm)!!! CUT IT OUT!!!$N$\n");
       afar("You point #CTN# and yell:  HEY, BITCHHOLE(tm)!!! CUT IT OUT!!!$N$\n", "[afar] #CMN# points at you and yells:  HEY, BITCHHOLE(tm)!!!  CUT IT OUT!!!$N$\n");
    }
}

int
cmd_bitchhole(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
