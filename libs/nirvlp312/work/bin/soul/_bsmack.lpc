inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You $HR$smack$N$ yourself (somehow) with a pudgy baby!!\n", "#CMN# $HR$smacks$N$ #MO#self upside the head with a pudgy baby!!\n");
       target("You $HR$smack$N$ #CTN# upside the head with a pudgy baby!!\n", "#CMN# $HR$smacks$N$ #CTN# upside the head with a pudgy baby!!\n", "#CMN# $HR$smacks$N$ you upside the head with a pudgy baby!!\n");
       afar("From afar, you somehow manage to smack #CTN# upside the head with a pudgy baby!\n", "From afar, #CMN# somehow manages to smack you upside the head with a pudgy baby!\n");
    }
}

int
cmd_bsmack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
