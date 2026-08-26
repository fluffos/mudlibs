#include <uid.h>

int alignment;

void
add_alignment(int a) {
  string al_title;
  if(!intp(a)) {
    write("Bad type argument to add_alignment.\n");
    return;
  }
  alignment = ((alignment *9) /10) + a;
  if (alignment > 10 * 100)
    al_title = "saintly";
  else if (alignment > 10 * 20)
    al_title = "good";
  else if (alignment > 10 * 4)
    al_title = "nice";
  else if (alignment > - 10 * 4)
    al_title = "neutral";
  else if (alignment > - 10 * 20)
    al_title = "nasty";
  else if (alignment > - 10 * 100)
    al_title = "evil";
  else
    al_title = "demonic";
  if (!wizardp(TO))
  this_object()->set("al_title",al_title);
}

int query_alignment(){ return alignment; }

int set_alignment(int x) {
  alignment = 0;
  if (x<-100) x = -100;
  if (x>100) x = 100;
  add_alignment(x);
  return 1;
}

int query_align_title() { return this_object()->query("al_title"); }

int query_align() { return alignment ; }
