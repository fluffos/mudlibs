//  gamestat
#include <daemons.h>
int t1, t2, tot_time;
private void do_gamestat2();
string alig_str(string what, int x);
int cmd_gamestat() {
   if(!archp(this_player())) return 0;
   write("Do you really wish to do this?  This may take awhile to consolidate the information?");
   t1=time();
   input_to("do_gamestat");
   return 1;
}

string get_age(mixed tot) {
    int years, weeks, days, hours, min, sec;
    string str;
    object ob;


    sec = tot;

    min = sec / 60;
    sec -= min * 60;
    hours = min / 60;
    min -= hours * 60;
    days = hours / 24;
    hours -= days * 24;
    weeks = days / 7;
    days -= weeks * 7;
    years = weeks / 52;
    weeks -= years * 52;
    str = "";
    if (years)
        str += years + (years > 1 ? " years" : " year")+(weeks ? ", ":" ");
    if (weeks)
        str += weeks + (weeks > 1 ? " weeks" : " week")+(days ? ", ":" ");
    if (days)
        str += days  + (days > 1 ? " days" : " day")+(hours ? ", ":" ");
    if (hours)
        str += hours + (hours > 1 ? " hours" : " hour")+(min ? ", ":" ");

   if (min)
        str += min   + ( min > 1 ? " minutes" : " minute")+(sec ? ", ":" ");
    if (sec)
        str += sec   + (sec > 1 ? " seconds " : " second ");
    return str;
}

int do_gamestat(string s) {
   int cycle;
   if(s != "yes") return notify_fail("Gamestat failed.\n");
   write("System analyzing now...\n");
   seteuid("Root");
   do_gamestat2();
   t2 = time();
   return 1;
}

private void do_gamestat2() {
   string *dir, *dir2, path, *lines, tmp;
   int i, x, ilines, day2, yr, ttt, totsize;
   int lvl, *lvl_avg=({}), do_delete, deletect, u, avg;
   mapping races=([]), classes=([]), subclasses=([]), dat=([]);
   string day, month, time;
   set_eval_limit(10000000);
   print("Starting game stat\n");
   print("Starting to gather user information: ");
   i=sizeof(dir=get_dir("/adm/save/users/"));
   while(i--) {
     reset_eval_cost();
     if(dir[i] != "rid" && dir[i] != "bak" && dir[i] != "arrest" && dir[i] != "old" && 
		file_size("/adm/save/users/"+dir[i]) == -2) {
     dir2 = get_dir("/adm/save/users/"+dir[i]+"/");
     x=sizeof(dir2);
     while(x--) {
       u++;
       path = "/adm/save/users/"+dir[i]+"/"+dir2[x];
       if(file_size(path) < 0) continue;
       totsize += file_size(path);
       if(read_file(path)) 
       ilines = sizeof(lines = explode(read_file(path), "\n")); else { 
	 print("Unable to read file "+path+".\n");
	 continue;
       }
       while(ilines --) {
     reset_eval_cost();
         if(sscanf(lines[ilines], "level %d", lvl)==1) {
           sscanf(dir2[x], "%s.o", tmp);
           if(!member_group(tmp, "creator") && !member_group(tmp, "superuser") && !member_group(tmp, "assist")) {
             lvl_avg += ({ lvl }); 
	   }
         } else
         if(sscanf(lines[ilines], "player_age %d", ttt)==1)
           tot_time+=ttt; else
         if(sscanf(lines[ilines], "player_class \"%s\"", tmp)==1)
           classes[tmp]++; else
         if(sscanf(lines[ilines], "subclass \"%s\"", tmp)==1)
           subclasses[tmp]++; else
         if(sscanf(lines[ilines], "race \"%s\"", tmp)==1)
           races[tmp]++;
       }
     }
     }
}
   print("Complete.\n");
   print("Running system wipe: ");
   i=sizeof(dir=get_dir("/adm/save/users/"));
   while(i--) {
     reset_eval_cost();
     if(dir[i] != "rid" && dir[i] != "bak" && dir[i] != "arrest" && dir[i] != "old" &&
                file_size("/adm/save/users/"+dir[i]) == -2) {
     dir2 = get_dir("/adm/save/users/"+dir[i]+"/");
     x=sizeof(dir2);
     while(x--) {
     reset_eval_cost();
       path = "/adm/save/users/"+dir[i]+"/"+dir2[x];
       if(file_size(path) < 0) continue;
       if(read_file(path))
       ilines = sizeof(lines = explode(read_file(path), "\n")); else {
         print("Unable to read file "+path+".\n");
         continue;
       }
       do_delete=0;
       while(ilines --) {
       reset_eval_cost();
         if(sscanf(lines[ilines], "last_on \"%s\"", tmp)==1) {
	   sscanf(tmp, "%s %s %d %s %d", day, month, day2, time, yr);
           if(yr <= 2005) {
             do_delete=yr;
	   }
         }
       }
       ilines = sizeof(lines = explode(read_file(path), "\n"));
       while(ilines --) {
         if(do_delete && sscanf(lines[ilines], "level %d", lvl)==1) {
           if(do_delete == 2006 && lvl < 10) {
             rename(path, "/adm/save/users/old/"+dir2[x]);
	     do_delete=0;
	     deletect++;
           } else
           if(do_delete == 2005 && lvl < 20) {
             rename(path, "/adm/save/users/old/"+dir2[x]);
             do_delete=0;
             deletect++;
           } else
           if(do_delete <= 2004 && lvl < 30) {
             rename(path, "/adm/save/users/old/"+dir2[x]);
             do_delete=0;
             deletect++;
           }
         }
       }
     }
     }
   }
   print("Completed. ("+deletect+" deleted)\n");
   print("Running other protocols: ");
   dat["baccounts"] = sizeof(dir = get_dir("/adm/save/accounts/"));
   dat["boards"] = sizeof(dir = get_dir("/adm/save/boards/"));
   i = sizeof(dir);
   while(i--) {
     sscanf(dir[i], "%s.o", tmp);
     dat["posts"] += BBOARD_D->get_num_posts(tmp);
   }
   i = sizeof(dir = get_dir("/adm/save/letters/"));
   while(i--) {
     dat["letters"] += sizeof(get_dir("/adm/save/letters/"+dir[i]+"/"));
   }
   print("Completed.\n");
   write("Printing out collected data: \n");
   write("System stats reported as of "+ctime(gmt_time(time(), "CST")));
   i=sizeof(lvl_avg);
   while(i--) {
     avg += lvl_avg[i];
   }
   avg = (avg/sizeof(lvl_avg));
   dat["arrest"] = sizeof(get_dir("/adm/save/users/arrest/"));
   dat["rid"] = sizeof(get_dir("/adm/save/users/rid/"));
write(
"User statistics -------------------------------------\n"
"     Pre-Number of Players: "+alig_str(""+u, 6)+"Final Number: "+(u-deletect)+"\n"+
"     Rid: "+alig_str(""+dat["rid"], 6)+"Arrested: "+dat["arrest"]+"\n"
"     User cleared due to inactivity: "+deletect+"\n"
"     Total User Size on Disk: "+totsize+" bytes.\n\n"
"Class statistics ------------------------------------\n"
"     Fighters: "+alig_str(classes["fighter"]+" ", 3)+"Mages: "+alig_str(classes["mage"]+" ", 5)+
"Clergy: "+alig_str(classes["clergy"]+" ", 5)+"\n"
"     Rogues: "+alig_str(classes["rogue"]+" ", 5)+"Wanderers: "+alig_str(classes["wanderer"]+" ", 5)+"\n\n"
"Subclass statistics ---------------------------------\n"
"     Berserker: "+alig_str(subclasses["berserker"]+" ", 3)+"Paladin: "+alig_str(subclasses["paladin"]+" ", 6)+
"Ranger: "+alig_str(subclasses["ranger"]+" ", 5)+"\n"
"     Warrior: "+alig_str(subclasses["warrior"]+" ", 5)+"Necromancer: "+alig_str(subclasses["necromancer"]+" ", 2)+" "
"Pyromancer: "+alig_str(subclasses["pyromancer"]+" ", 5)+"\n"
"     Sorceror: "+alig_str(subclasses["sorceror"]+" ", 4)+"Wizard: "+alig_str(subclasses["wizard"]+" ", 7)+
"Cleric: "+alig_str(subclasses["cleric"]+" ", 5)+"\n"
"     Druid: "+alig_str(subclasses["druid"]+" ", 7)+"Kataan: "+alig_str(subclasses["kataan"]+" ", 7)+
"Monk: "+alig_str(subclasses["monk"]+" ", 5)+"\n"
"     Assassin: "+alig_str(subclasses["assassin"]+" ", 4)+"Scout: "+alig_str(subclasses["scout"]+" ", 8)+
"Thief: "+alig_str(subclasses["thief"]+" ", 5)+"\n"
"     Thug: "+alig_str(subclasses["thug"]+" ", 8)+"Paladin: "+alig_str(subclasses["paladin"]+" ", 6)+
"Bard: "+alig_str(subclasses["bard"]+" ", 5)+"\n"
"     Gypsy: "+alig_str(subclasses["gypsy"]+" ", 7)+"Jester: "+alig_str(subclasses["jester"]+" ", 7)+
"Swashbuckler: "+alig_str(subclasses["swashbuckler"]+" ", 5)+"\n\n"
"Dragon statistics -----------------------------------\n"
"     Blue: "+alig_str(subclasses["blue"]+" ", 8)+"Black: "+alig_str(subclasses["black"]+" ", 7)+
"Red: "+alig_str(subclasses["red"]+" ", 5)+"\n"
"     White: "+alig_str(subclasses["white"]+" ", 3)+"\n\n"
"Race statistics -------------------------------------\n"
"     Archangel: "+alig_str(races["archangel"]+" ", 3)+"Faerie: "+alig_str(races["faerie"]+" ", 5)+
"Gremlin: "+alig_str(races["gremlin"]+" ", 3)+"Lich: "+alig_str(races["lich"]+" ", 3)+"\n"
"     Raknid: "+alig_str(races["raknid"]+" ", 6)+"Centaur: "+alig_str(races["centaur"]+" ", 4)+
"Ferrel: "+alig_str(races["ferrel"]+" ", 4)+"Half-Elf: "+alig_str(races["half-elf"]+" ", 3)+"\n"
"     Demon: "+alig_str(races["demon"]+" ", 7)+"Giant: "+alig_str(races["giant"]+" ", 6)+
"Minotaur: "+alig_str(races["minotaur"]+" ", 2)+" Sauran: "+alig_str(races["sauran"]+" ", 3)+"\n"
"     Halfling: "+alig_str(races["halfling"]+" ", 4)+"Netherman: "+alig_str(races["netherman"]+" ", 2)+" "
"Wiemic: "+alig_str(races["wiemic"]+" ", 4)+"Dragon: "+alig_str(races["dragon"]+" ", 3)+"\n"
"     Gnoll: "+alig_str(races["gnoll"]+" ", 7)+"Human: "+alig_str(races["human"]+" ", 6)+
"Nymph: "+alig_str(races["nymph"]+" ", 5)+"Dwarf: "+alig_str(races["dwarf"]+" ", 3)+"\n"
"     Gnome: "+alig_str(races["gnome"]+" ", 7)+"Illithid: "+alig_str(races["illithid"]+" ", 3)+
"Ogre: "+alig_str(races["ogre"]+" ", 6)+"Elf: "+alig_str(races["elf"]+" ", 3)+"\n"
"     Goblin: "+alig_str(races["goblin"]+" ", 6)+"Imp: "+alig_str(races["imp"]+" ", 8)+
"Orc: "+alig_str(races["orc"]+" ", 3)+"\n"

"Random statistics -----------------------------------\n"
"     Num of Boards: "+alig_str(dat["boards"], 5)+"Posts: "+dat["posts"]+"\n"
"     Mail letters: "+alig_str(dat["letters"], 6)+"Average Level: "+avg+"\n"
"     Total Age: "+tot_time+" seconds, "+get_age(tot_time)+"\n"
"     Average Age: "+(tot_time/u)+" "+get_age(tot_time/u)+"\n"
);
}

string alig_str(string what, int x) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
        out = what[0..x-1] + " ";
        return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}
