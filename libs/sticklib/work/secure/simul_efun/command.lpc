// Need to mask this efun to prevent cheating with it. -+ Doomdark 22-jan-96 +-
varargs int
command(string cmd, object x)
{
    int callee_lvl;
    if (!x) x = previous_object();
    else {
	if ((callee_lvl = (int) x->query_coder_level()) &&
	  !this_interactive()) return 0;
	if (callee_lvl && x != this_interactive() && (int) this_interactive()
	  -> query_coder_level() < callee_lvl) return 0;
    }
    efun::command(cmd, x);
}
