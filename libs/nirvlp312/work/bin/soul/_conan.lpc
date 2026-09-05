inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask, \"Conan, what is best in life?\"#RET#Conan replies, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n", "#CMN# asks, \"Conan, what is best in life?\"#RET#Conan replies, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n");
       target("You ask, \"#CTN#, what is best in life?\"#RET#CTN# replies, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n", "#CMN# asks, \"#CTN#, what is best in life?\"#RET#CTN# replies, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n", "#CMN# asks, \"#CTN#, what is best in life?\"#RET#You reply, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n");
       afar("$HK$[afar]$N$ You ask, \"#CTN#, what is best in life?\"#RET#CTN# replies, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n", "$HK$[afar]$N$ #CMN# asks, \"#CTN#, what is best in life?\"#RET#You reply, \"Crush your enemies, see them driven before you, and hear the lamentations of the women.\"$N$\n");
    }
}

int
cmd_conan(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
