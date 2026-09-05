inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You drop to one knee and intone, \"What is thy bidding, my master?\"$N$\n", "#CMN# drops to one knee and intones, \"What is thy bidding, my master?\"$N$\n");
       target("You turn towards #CTN#, drop to one knee, and intone, \"What is thy bidding, my master?\"$N$\n", "#CMN# turns towards #CTN#, drops to one knee, and intones, \"What is thy bidding, my master?\"$N$\n", "#CMN# turns towards you, drops to one knee, and intones, \"What is thy bidding, my master?\"$N$\n");
       afar("You activate your holo transmitter and supplicant yourself before your true master.$N$\n", "A small $HB$blue$N$ hologram of #MN# appears before you, drops to one knee and intones, \"What is thy bidding, my master?\"$N$\n");
    }
}

int
cmd_master(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
