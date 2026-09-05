#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define master "/obj/wiz_tool_master.c"
#define to this_object()
#define ep environment(to)
#define eep environment(ep)

id(str) { return str == "wiz_tool" || str == "tool" || str == "wiztool"; }

short() { return capitalize(ep->query_real_name())+"'s "+
          "Wiztool"; }

long() { 
   write("This is a general all-purpose wiztool.\n"+
         "Commands:\n"+
         "wlog <action>#<reason>      writes a log of your actions\n"+
         "rules                       lists wizard rules & guidelines\n"+
         "I <name>                    inventory of name\n"+
         "IR <name>                   inv of room that name is in\n"+
         "hand <name> <path>          hands name object of path\n"+
         "place <name> <path>         moves name to path\n"+
         "church <name>               moves name to church\n"+
         "                            note:no name meansyourself\n"+
         "trans <name>                moves name to you\n"+
         "peace                       forces all combat to stop\n"+
         "money                       gives you 80k coins\n"+
         "heal <name>                 heal someone in the room\n"+
         "                            note: no name is yourself\n"+
         "set_level <name> <#>        sets the level of name\n"+
         "set_extra_level <name> <#>  sets the extra level of name\n"+
         "set_home <name> <path>      sets the home of name to path\n"+
         "add_xp <name> <#>           adds # xp to name\n"+
         "set_stat <name> <what> <#>  sets the stat what of name to #\n"+
         "idest <name> <object>       dests object from name's inv\n");
}

drop() { destruct(to); return 1; }
get() { if(tl > 20) return 1;  else destruct(to); return 1;}

init() {
  if(tl < 21) { destruct(to); return 1; }
  add_action("wizard_log", "wlog");
  add_action("wizard_rules", "rules");
  add_action("inv","I");
  add_action("invr","IR");
  add_action("hand","hand");
  add_action("place","place");
  add_action("idest","idest");
  add_action("church","church");
  add_action("trans","trans");
  add_action("peace","peace");
  add_action("money","money");
  add_action("heal","heal");
  add_action("add_xp","add_xp");
  add_action("set_ex","set_extra_level");
  add_action("set_stat","set_stat");
  add_action("set_level","set_level");
  add_action("set_home","set_home");
 }

wizard_log(str) { master->wizard_log(str); return 1; }
wizard_rules() { master->wizard_rules(); return 1; }
inv(str) { master->inv(str); return 1; }
invr(str) { master->invr(str); return 1;}
hand(str) { master->hand(str); return 1; }
place(str) { master->place(str); return 1; }
church(str) { master->church(str); return 1; }
trans(str) { master->trans(str); return 1; }
idest(str) { master->idest(str); return 1; }
heal(str) { master->heal(str); return 1; }
set_ex(str) { master->set_ex(str); return 1; }
money() { master->money(); return 1; }
peace() { master->peace(); return 1; }
set_stat(str) { master->set_stat(str); return 1; }
set_level(str) { master->set_level(str); return 1; }
add_xp(str) { master->add_xp(str); return 1; }
set_home(str) { master->set_home(str); return 1; }

