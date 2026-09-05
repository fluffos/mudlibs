inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: Who is the King here?$N$\n", "#CMN# says: Who is the King here?$N$\n");
       target("You point at #CTN# and says: #CTS# must be the King.  #CTS# ain't got shit all over #TO#.$N$\n", "#CMN# points at #CTN# and says: #CTS# must be the King.  #CTS# ain't got shit all over #TO#.$N$\n", "#CMN# points at you and says: YOU must be the King.  You ain't got shit all over yourself.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ You point at #CTN# and says: #CTS# must be the King.  #CTS# ain't got shit all over #TO#.$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# points at you and says: YOU must be the King.  You ain't got shit all over yourself.$N$\n");
    }
}

int
cmd_king(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
