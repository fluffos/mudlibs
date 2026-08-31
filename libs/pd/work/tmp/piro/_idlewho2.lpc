
//      /bin/user/_idlewho.c

#include <std.h>
#include <daemons.h>

/*the number of groups with different idle times that the list will be
  split into*/
#define NUMGROUPS (6)

/* the formula that will be used to segregate users into the different groups.
   each group will have an idle time frame twice as large as the previos one.
   For example, if the segregation standard is 2.5 minutes, the first group 
   will be those with idle times 2.5 and below, the second will be those with
   idle times 5.0 and below, the third will be those with idle times 10.0 and
   below, and so on. */
#define SEGREGATION_STANDARD (2.5 * 60)

inherit DAEMON;

int cmd_idlewho(string str) {
  object *allPlayers = users(); //, *visPlayers;
  mixed *playerGroups = ({});
  int i, visPlayers = 0, x;
  int groupThreshold[NUMGROUPS];
  
  //initialize group data - create empty groups and set group thresholds
  for (int i=0; i<NUMGROUPS; i++) {
    playerGroups += ({ ({}) });
    groupThreshold[i] = to_int(SEGREGATION_STANDARD * pow(2,(i-1)));
  }  

  // sort each player into their specific group identity based off idle time
  for(i = 0; i < sizeof(allPlayers); i++) {
    /* iterate through the group identitities until the player's idle time
     * is less than the max idle time for that specific group, or until the
     * max number of groups is reached. Once either has happened, break the
     * loop and enter the player into the group with the current group
     * identity */
    //possible bug: syntax: isVisible() ?
    if(allPlayers[i]->isVisible() || wizardp(this_player())) {  
    
      for(x = 1; x < NUMGROUPS; x++) {
        if(query_idle(allPlayers[i]) < groupThreshold[x] ) )
          break;
      }
      visPlayers++;
      playerGroup[x - 1] += {{ allPlayers[i] }};
    }  
  }

  /* players organized into their respective groups. Insert data here to
   * micro-organize each group into smaller groups if desired */
   
  // print idle information
      
  write("%^RESET%^%^BLUE%^"
          +"+=+=+=+=+=+=+=+=+=+=+=+=+=+=+%^BOLD%^( %^WHITE%^Primal Darkness"
          +" %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
  
  for(i = 0; i < NUMGROUPS; i++) {
    if(sizeof(playerGroup[i]) <= 0)
      continue;
   
    //possible bug: syntax: ^ ?
    write("%^RESET%^%^BOLD%^%^BLACK%^");
    write("Idle time: "+ groupThreshold[i]/60 +
          ((i==(NUMGROUPS-1))?"+":"") + " minutes.");
    write("%^RESET%^");
    
    for(x = 0; x < sizeof(playerGroup[i]); x++) {
      string line;
      
      /* Paste all of the specific user's data into string variable 'line'
       * before writing it to the requesting user. */
      if(archp(playerGroup[i][x])) {
        line = "%^BLUE%^[%^BOLD%^Admin %^RESET%^%^BLUE%^]%^BOLD%^ ";
      }  
      else if(wizardp(playerGroup[i][x])) {
        line = "%^MAGENTA%^[%^BOLD%^Immrtl%^RESET%^%^MAGENTA%^] ";
      }  
      else {
        line = "%^CYAN%^[%^BOLD%^Player%^RESET%^%^CYAN%^] ";
      }
      line += sprintf("%44s ", playerGroup[i][x]->query_title());
      
      line += "%^RESET%^%^WHITE%^";
      if(wizardp(playerGroup[i][x])) {
        if(adminp(playerGroup[i][x]))
          line += "%^BOLD%^";
        line += sprintf("%21s", playerGroup[i][x]->query_position());
      }  
      else {
        line += sprintf("%^BOLD%^%10s %^CYAN%10s\n",
                playerGroup[i][x]->query_class(),
                playerGroup[i][x]->query_subclass());
      }  
         
      write(line);
    }  
  }
  
  write("%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
       +"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
  write("%^WHITE%^%^BOLD%^"+visPlayers+" player"+ (visPlayers!=1 ? "s":"")
          +" online.\n");

  return 1;
}

void help() {
  write("Syntax: <idlewho>\n\n"
    "Like the /who command, organized instead by idle time"
    "\n\nSee also: who, finger"
  );
}

