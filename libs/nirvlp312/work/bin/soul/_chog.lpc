inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chog.$N$\n", "#CMN# chogs.$N$\n");
       target("You chog at #CTN#.$N$\n", "#CMN# chogs at #CTN#.$N$\n", "#CMN# chogs at you.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ You chog at #CTN#.$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# chogs at you.$N$\n");
    }
}

int
cmd_chog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
