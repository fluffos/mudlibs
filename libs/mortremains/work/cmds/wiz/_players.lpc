// _players.c - Player status checking command..
// Made so you can easily observe what weapons / weapon classes
// players have, but mostly because I was bored.
// Written by Chronos@DarkTowers, 8-8-95.
// Rewritten to fit new lib by Chronos@NK, 4-10-98.

#undef TP
object get_weapon(object TP) ;
int no_weapons(object ob) ;
int query_wc(object ob) ;

#define BREAK "=============================================================================="

int cmd_players(string str) {
  int flag;
  int i, SHOW_WIZ, level, ac, wc, wiz, players;
  string name;  
 object *all_users,  weapon;
  if (str == "-wizards" || str == "-w") SHOW_WIZ++;
  all_users=users();
  printf("Name            Lvl\tWC\tAC\tWielded weapon.\n");
  write(BREAK+"\n");
  for(i=0;i<sizeof(all_users);i++) {
  if (wizardp(all_users[i]) && !SHOW_WIZ) continue;
  if ((int)all_users[i]->query("invisible")>1) continue ;
    level = (int)all_users[i]->query_level();
    name = all_users[i]->query("cap_name");
  if (wizardp(all_users[i])) name += " [W]";
  if (all_users[i]->query("invisible")) name = "#" + name ;
   wc = query_wc(all_users[i]) ;
    ac = (int)all_users[i]->query("armor_class");
  flag = no_weapons(all_users[i]);
   if (flag) weapon=get_weapon(all_users[i]);
   else weapon = 0;
    if (flag) printf("%15-s %d\t%d\t%d\t%s",
        name, level, wc, ac, (string)weapon->query("short"));
 else printf("%15-s %d\t%d\t%d\tFists, Unarmed skill is %d.",
    name, level, wc, ac, (int)all_users[i]->query_skill("Unarmed"));
   if (weapon && weapon->query("nosecond")) write("-@");
  if (flag==2) write("-*");
   write("\n");
  if (wizardp(all_users[i])) wiz++;
    else players++;
  }
  write(BREAK+"\n");
  if (!players) write("No players to display!\n");
  write("                ");
  write("  [ # denotes that an individual is currently invisible.     ]\n");
  write("                ") ;
  write("  [ * denotes that a player is wielding two weapons at once. ]\n");
  write("                ");
  write("  [ @ denotes that a player is wielding a two-handed weapon. ]\n") ;
  return 1;
}

string help() {
  return @ENDHELP
Syntax: players [-w]

Players shows you all the players on the mud along with info like
level, weapon class, armor class, and current wielded main weapon.

The -w flag includes wizards in the display.

Another fine utility brought to you by Chronos!  :D
ENDHELP
  ;
}

int no_weapons(object ob) {
  int i;
  if (ob->query("weapon1")) i++;
  if (ob->query("weapon2")) i++;
  return i;
}

object get_weapon(object TP) {
   object ob;
  if ((int)this_player()->query("handedness")==2) {
  if (TP->query("weapon2")) ob=TP->query("weapon2");
  else ob = TP->query("weapon1");
  }
  else {
   if (TP->query("weapon1")) ob = TP->query("weapon1");
  else ob = TP->query("weapon2");
  }
  return ob;
}



int query_wc(object ob) {
  int work1, work2 ;
  object x ;
  if (!ob) return 0 ;

  x = ob->query("weapon1") ;
  if (x) work1 = x->query("weapon") ;
  x = ob->query("weapon2") ;
  if (x) 
  work2 = x->query("weapon") ;
  if (!work1 && !work2) return 0 ;
  if (work1>work2) return work1 ;
  if (work2>work1) return work2 ;
  return work1 ;
}

