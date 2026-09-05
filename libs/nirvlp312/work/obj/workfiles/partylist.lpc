/*----- Created by Cosmo on 1/20/00 ----*/

#include "/players/cosmo/closed/ansi.h"
#define SYM "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define PATH "obj/"

string *leader;  /* Array of party leader's name */
int *score;      /* Array of total party exp */
string *date;    /* Array of date of which score occurred */
string *members; /* Array of arrays of party members */

id(str) {
  return str == "list" || str == "top" || str == "top parties" ||
    str == "list of top parties" || str == "top list";
}

reset(arg) {
int x;

  if(arg) return;
  leader=allocate(15);
  score=allocate(15);
  date=allocate(15);
  members=allocate(15);
  for (x=0; x<15; x++)
    members[x]=allocate(6);
  restore_object(PATH+"partylist");
}

short() { return "A list of the top parties"; }

long() {
int x;
  restore_object(PATH+"partylist");
  say(this_player()->query_name()+" reads the top list.\n");
  write("\n"+HIR+SYM+NORM+"\n");
  write("\t     "+YEL+"Top Parties (since 1/21/2000)"+NORM+"\n");
  write(HIR+SYM+NORM+"\n");
  write(BOLD+"     LEADER'S NAME   EXPERIENCE  DATE"+NORM+"\n");
  for (x=0; x<sizeof(score); x++)
    if (score[x])
      write(pad(x+1+".",5)+pad(leader[x],16)+pad(score[x],12)+date[x]+"\n");
  write(HIR+SYM+NORM+"\n");
  write("Use "+BOLD+"read <#>"+NORM+" to see the names of party members.\n");
}

get() {
  write("It is firmly attached to the wall.\n");
  return 0;
}

init() { add_action("read", "read"); }

read(string str) {
int x, y;
  if(!str) { notify_fail("Read what?\n"); return 0; }
  if(id(str)) {
    say(this_player()->query_name()+" reads the top list.\n");
    long();
    return 1;
  }
  else {
    if(sscanf(str, "%d", x)) switch(x) {
      case 1..15:
        if(!members[x-1][0]) { notify_fail("No members.\n"); return 0; }
        say(this_player()->query_name()+" checks the members of party "+x+".\n");
        write("\n"+HIR+SYM+NORM+"\n");
        write("Members of "+BOLD+leader[x-1]+"'s"+NORM+" Party:\n");
        for(y=0; y < sizeof(members[x-1]); y++) {
          if(leader[x-1] != members[x-1][y])
            write(members[x-1][y]+"\n");
        }
        write(HIR+SYM+NORM+"\n");
        return 1;
      default: return 0;
    }
    else return 0;
  }
}

UpdateList(string chief, int exp, string *member_names) {
int size, x, y;
string *blah;

  /* size should always equal 15 */
  size=sizeof(score);

  /* Do nothing if the new score doesn't qualify for the list */
  if (exp < score[size-1]) return 0;

  /* Determine the current position for the new high score */
  for (x=0; x<size; x++)
    if (exp >= score[x]) break;

  /* Redefine the arrays with the new information */
  /* by bumping everything down one... */
  for (y=size-1; y>x; y--) {
    leader[y] = leader[y-1];
    score[y] = score[y-1];
    date[y] = date[y-1];
    members[y] = members[y-1];
  }
  /* ... and then inserting the new data */
  leader[x] = chief;
  score[x] = exp;
  blah = ctime(time());
  date[x] = extract(blah,4,9) + extract(blah,19,23);
  members[x] = member_names;

  /* Save everything */
  save_object(PATH+"partylist");
  return 1;
}
