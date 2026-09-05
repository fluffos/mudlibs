inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chog angrily.$N$\n", "#CMN# chogs angrily.$N$\n");
       target("You chog angrily at #CTN#.$N$\n", "#CMN# chogs angrily at #CTN#.$N$\n", "#CMN# chogs angrily at you.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ You chog angrily at #CTN#.$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# chogs angrily at you.$N$\n");
    }
}

int
cmd_achog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
