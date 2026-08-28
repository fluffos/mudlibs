mixed cmd_where() {
  string *whoa;          // Whoa is used as a string array for who-mapping. Containing the key-values...
  object *all;           // All is used to store the array of players currently online..
  string tmp;            // TMP is used to temporarily store the current location to match in the check-loops..
  mapping who;           // Who is used to store all the players and their location, player's name being the key and location the value0..
  int i, x;              // i and x are variables used in loops...


  who = ([]);                                             // Define an empty mapping for who.
  all = users();                                          // Give the variable "all" the current players online with the efun users() 

  write("\nPlayers\t\tLocation\n\n");                     // Top of the table, prints out "Players" and "Location" to understand the table...

  for (i=0;i<sizeof(all);i++) {                           // Beginning of the loop...
    who += ([ capitalize(all[i]->query_name()): file_name(environment(all[i])) ]);
  }                                                       // ... that adds players and their locations to the Map.

  for (i=0;i<sizeof(who);i++) {                           // Now we're going to go through the map startin from 0...
    whoa = m_indices(who);                                // Set whoa to be an array of the key-values..
    tmp = who[whoa[i]];                                   // TMP is going to be what we're comparing against the other values in the map. Take the value in whoa[i] and give it to TMP..
    x = i+1;                                              // X is going to be our next starting point.. the next one.. well that's +1...
    write(sprintf("%-15s %s\n",whoa[i], who[whoa[i]]) );   // Print out the current unique match (it should be unique since it's either the first or the first after a finished loop)
    while(x<sizeof(who)) {                                  // Let's make the next loop the size of the map (the map is changing in size so it's a must)
      if (tmp == who[whoa[x]]) {                             // If TMP _IS_ equal to the next player's location...
        write(sprintf("%-15s %s\n",whoa[x], who[whoa[x]]) ); // ... Let's print the player and location out...
        m_delete(who, whoa[x]);                             // ... before we delete it from the map...
        x--;                                               // Now there's one less value to go through the map, and since the next value would be x+1 we have to decrease by 1 since we removed 1 entry..
      }                                                   
      x++;                                                // Auto-incremential code for X-variable... add by 1.
    }
  }
}


