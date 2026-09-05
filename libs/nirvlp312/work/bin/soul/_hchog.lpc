inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chog happily.$N$\n", "#CMN# chogs happily.$N$\n");
       target("You chog happily at #CTN#.$N$\n", "#CMN# chogs happily at #CTN#.$N$\n", "#CMN# chogs happily at you.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ You chog happily at #CTN#.$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# chogs happily at you.$N$\n");
    }
}

int
cmd_hchog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
