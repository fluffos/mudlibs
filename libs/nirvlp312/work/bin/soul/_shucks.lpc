inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You kick your foot in the dirt and say, \"Aww shucks.\"$N$\n", "#MN# kicks #MP# foot in the dirt and says, \"Aww shucks.\"$N$\n");
       target("You kick you foot in the dirt and say, \"Aww shucks\" to #TN#.\n", "#MN# kicks #MP# foot in the dirt and says, \"Aww shucks\" to #TN#.\n", "#MN# kicks his foot in the dirt and says, \"Aww shucks\" to you.\n");
       afar("$Y$[afar]$N$ You kick your foot in the dirt and say, \"Aww shucks\" to #TN#.\n", "$Y$[afar]$N$ #MN# kicks #MP# foot in the dirt and says, \"Aww shucks\" to you.\n");
    }
}

int
cmd_shucks(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
