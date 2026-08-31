#include <std.h>

inherit DAEMON;

void set_first_sentence(string s);
void set_last_sentence(string s);
void set_day_sentences(string *list);
void set_night_sentences(string *list);
void set_day_sentances(string *list);
void set_night_sentances(string *list);
void set_item_list(mapping stuff);
void set_properties(mapping stuff);
void set_smell(string str);
void set_listen(string str);
void set_reset_list(string *list);
void set_short(string str);
void set_how_long(int i);
void set_mob_cap(int i);

string get_first_sentence();
string get_last_sentence();
string get_day_long();
string get_night_long();
mapping get_items();
string get_smell();
string get_listen();
string *get_reset_list();
string get_short();
mapping get_properties();
int get_mob_cap();

string *DayLong, *NightLong, *Resets, Smell, Listen, Short;
string First, Last;
mapping Items, Properties;
int descriptlength, MobCap;

void create() {
  ::create();
  NightLong = ({});
  MobCap = 4;
}

void set_first_sentence(string s) { First = s; }
void set_last_sentence(string s) { Last = s; }
string get_first_sentence() { return First; }
string get_last_sentence() { return Last; }

int get_mob_cap() { return MobCap; }

void set_mob_cap(int i) { MobCap = i; }

void set_day_sentances(string *list) {
  DayLong = list;
}

void set_day_sentences(string *list) {
    DayLong = list;
}

void set_night_sentences(string *list) {
    NightLong = list;
}

void set_how_long(int i) { descriptlength = i; }

void set_night_sentances(string *list) {
  NightLong = list;
}

void set_item_list(mapping stuff) {
  Items = stuff;
}

void set_smell(string str) { Smell = str; }

void set_listen(string str) { Listen = str; }

void set_short(string str) { Short = str; }

void set_reset_list(string *list) { Resets = list; }

void set_properties(mapping blah) { Properties = blah; }

mapping get_properties() { return Properties; }

string get_day_long() {
    int x, i;
    string ret;
    int *flag;
    flag = ({});

    i = sizeof(DayLong);
    while(i--) {
      flag += ({0});
    }

    ret = "";

    for(i=0;i < descriptlength;i++) {
        x = random(sizeof(DayLong));
        if(flag[x] == 0) {
            ret += DayLong[x]+"  ";
            flag[x] = 1;
        }
    }

    if (First) ret = First + " " + ret;
    if (Last) ret = ret + " " + Last;

    return ret;
}

string get_night_long() {
    int x, i;
    string ret;
    int *flag;
    flag = ({});

    if(sizeof(NightLong) == 0)
      return get_day_long();

    i = sizeof(NightLong);
    while(i--) {
      flag += ({0});
    }

    ret = "";

    for(i=0;i < descriptlength;i++) {
        x = random(sizeof(NightLong));
        if(flag[x] == 0) {
            ret += NightLong[x]+"  ";
            flag[x] = 1;
        }
    }

    if (First) ret = First + " " + ret;
    if (Last) ret = ret + " " + Last;

    return ret;
}

mapping get_items() { return Items; }

string get_smell() { return Smell; }
string get_listen() { return Listen; }
string *get_reset_list() { return Resets; }
string get_short() { return Short; }
