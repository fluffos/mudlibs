inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You make a horned gesture with your hands and yell: \"$Y$Hook 'em Horns!$N$\"$N$\n", "#CMN# makes a horned gesture with #MP# hands and yells: \"$Y$Hook 'em Horns!$N$\"$N$\n");
       target("You make a horned gesture at #CTN# and yell: \"$Y$Hook 'em Horns!$N$\"$N$\n", "#CMN# makes a horned gesture at #CTN# and yells: \"$Y$Hook 'em Horns!$N$\"$N$\n", "#CMN# makes a horned gesture at you and yells: \"$Y$Hook 'em Horns!$N$\"$N$\n");
       afar("$Y$[$N$afar$Y$]$N$ You make a horned gesture at #CTN# and yell: \"$Y$Hook 'em Horns!$N$\"$N$\n", "$Y$[$N$afar$Y$]$N$ #CMN# makes a horned gesture at you and yells: \"$Y$Hook 'em Horns!$N$\"$N$\n");
    }
}

int
cmd_hookem(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
