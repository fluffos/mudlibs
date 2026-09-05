nosave string *cmds;
#define SAVE "players/pestilence/closed/dark/members/"
#define tpn      ENV()->query_real_name()

init() {
  object s;
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
   save_object(SAVE+tpn);
}
  }
  if(tp->query_level() < 20) {
    tp->set_guild_name("Dark Order");
}
/*
        if(tp->query_guild_rank() != g_level) tp->add_guild_rank(g_level - tp->query_guild_rank());
  tp->save_character();
  }
*/
            

add_action("stun","stun");
add_action("mud_who","who3");
add_action("score","score");
add_action("distraught","distraught");
add_action("distraught","dist");
add_action("dhelp","dhelp");
add_action("wound","wound");
add_action("alignment","align");
add_action("alignment","alignment");
add_action("enrage","enrage");
add_action("stalk","stalk");
add_action("fatal","fatal");
add_action("punch","punch");
add_action("save_me","dsave");
add_action("decorpse","drain");
add_action("darken","darken");
add_action("demon","demon");
add_action("torment","torment", 2);
add_action("darkness","darkness");
add_action("guild_leave","leave_guild");
add_action("guild_leave","guild_leave");
   add_action("slash", "slash", 2);
add_action("restore_me","drestore");
add_cmds();
add_action("offwield","offwield");
add_action("enrage","enrage");
add_action("guild_update","gupdate");
add_action("guild_quit","leave_guild");
add_action("guild_login","login");
}
