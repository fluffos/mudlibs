#ifndef GENERAL_H
#define GENERAL_H

/*** general ***/

int climb;   /* climb walls */
int swim;

/*** general ***/

int set_climb(int i) { return climb = i; }
int set_swim(int i)  { return swim = i;  }

int query_climb()    { return climb;     }
int query_swim()     { return swim;      }

void query_general_stats() {
  write("\n         -=[ General Skills ]=-\n\n");
  write(" Climb: " + climb + "  Swim: " + swim + "\n");
}

#endif /* GENERAL_H */

