//	/std/living.c
//	from the Nightmare mudlib
//	inheritable code for living things
//	created by Descartes of Borg september 1992

#include <security.h>
#include <daemons.h>
#include <party.h>
#include <dirs.h>
#include <flags.h>
#include <rooms.h>
#include <living.h>

#define TIME_TO_HEAL 10
#define HEALING_FORMULA (stats["strength"]+stats["constitution"]+stats["dexterity"]+stats["charisma"])*6

int invis, ok_to_heal;
nosave int forced, sight_bonus, spiritual, physical;
string description;
nosave string party;
nosave string *search_path;
private string gender;
mapping stats;
nosave mapping stat_bonus;
mapping languages;
nosave mapping language_bonus;
string primary_language;
nosave private mixed *__BeforeLocked;
int __PlayerAge;
nosave private int __Locked, __LastAged;
int __PlayerKiller;
mapping language_exp;

int query_age();
void set_stats(string str, int x);
void set_alignment(int x);
void add_alignment(int x);
void adj_alignment(int x);
void adjust_biorhythms();
void set_invis();
string query_client();
int query_physical();
int query_outlaw();
int query_spiritual();
int query_alignment();
int query_stats(string str);
int query_base_stats(string stat);
int query_poisoning();
void add_poisoning(int x);
string query_gender();
void set_gender(string str);
string query_objective();
string query_possessive();
string query_subjective();
int query_intox();
int query_stuffed();
int query_quenched();
int query_invis();
string query_party();
string query_long(string unused);
protected  void init_path();

void create() {
    combat::create();
    __PlayerAge = 0;
    __LastAged = time();
}

void heart_beat() {
    int x;

    if(x = time() - __LastAged) {
        __PlayerAge += x;
        __LastAged = time();
    }
}

protected  void init_living() {
    add_action("cmd_hook", "", 1);
    add_action("cmd_lock", "lock");
    init_path();
    init_attack();
}

protected  void init_path() {
    string tmp;

    search_path = ({ DIR_MORTAL_CMDS, DIR_SECURE_MORTAL_CMDS, DIR_CLASS_CMDS });
    if(tmp = (string)this_object()->query_guild())
      search_path += ({ DIR_GUILD_CMDS+"/"+tmp });
    if(ambassadorp(this_object()) || creatorp(this_object()))
      search_path += ({ DIR_AMBASSADOR_CMDS, DIR_SECURE_AMBASSADOR_CMDS });
    if(high_mortalp(this_object()) || creatorp(this_object()))
	search_path += ({ DIR_HM_CMDS });
    if(creatorp(this_object())) {
    search_path += ({ DIR_CREATOR_CMDS, DIR_SECURE_CREATOR_CMDS });
        if(file_size(user_path(query_name()) + "bin") == -2)
            search_path += ({ user_path(query_name())+"bin" });
        if(archp(this_object()))
            search_path += ({ DIR_ADMIN_CMDS, DIR_SECURE_ADMIN_CMDS });
    }
}

protected  void init_stats() { stats = ([]); }

nomask  private  int cmd_hook(string cmd) {
    string file, verb;

    if(__Locked) {
        message("prompt", sprintf("\n(%s) Password: ", mud_name()),
          this_object());
        return 1;
    }
    if( (verb = query_verb()) != "quit" && query_paralyzed()) {
	message("my_action", sprintf("%s", (string)this_player()->query_paralyze_message()),
	  this_player());
        return 1;
    }
    if(!(file = (string)CMD_D->find_cmd(verb, search_path))) {
        if(!((int)SOUL_D->do_cmd(verb, cmd))) {
            if((int)CHAT_D->do_chat(verb, cmd)) return 1;
            else {
                if(query_client()) receive("<error>");
                return 0;
            }
        }
        else return 1;
    }
    if(!((int)call_other(file, "cmd_"+verb, cmd))) {
        if(query_client()) receive("<error>");
        return 0;
    }
    else return 1;
}

int force_me(string cmd) {
    string tmp;
    int res;

    if(creatorp(this_object()) && !((int)master()->valid_apply(({query_name()}))))
      return 0;
    forced = 1;
    res = command(cmd);
    forced = 0;
    return res;
}

void reduce_stats() {
    string *ind;
    int i;

    if(!stats) return;
    ind = keys(stats);
    for(i=0; i<sizeof(ind); i++)
	if(random(101)>50) set_stats(ind[i], query_base_stats(ind[i])-1);
}

void do_healing(int x) {
    int tmp;

    if(this_object() && this_object()->is_player()) {
        tmp = query_physical();
        if(tmp >1) tmp = 1;
        else if(tmp < -1) tmp = -1;
        add_hp(tmp);
        tmp = query_spiritual();
        if(tmp > 1) tmp = 1;
        else if(tmp < -1) tmp = -1;
        add_mp(tmp);
    }
        if(query_invis()) add_sp(-random(5));
    heal(query_heal_rate());
    if(this_object()->is_player() && !creatorp(this_object()) && query_invis())
	heal(-(random(3)));
    if(x<1) set_heal_rate(2);
    else if(x<20) set_heal_rate(3);
    else if(x<50) set_heal_rate(4);
    else if(x<85) set_heal_rate(5);
    else if(x<150) set_heal_rate(6);
    else if(x<210) set_heal_rate(7);
    else set_heal_rate(8);
    adjust_biorhythms();
    if(query_poisoning()) set_heal_rate(-(query_poisoning()/9+1));
    ok_to_heal = query_age() + TIME_TO_HEAL;
}

int calculate_healing() {
    int borg;
    string msg;

    if(query_intox()) {
	healing["intox"] --;
	if(healing["intox"] < 0) healing["intox"] = 0;
	if(!healing["intox"]) {
	    write("Suddenly you get a bad headache.");
	    add_hp(-random(6));
	}
	else if(3> random(101)) {
	    borg = random(4);
	    switch(borg) {
		case 0: msg = "stumble"; break;
		case 1: msg = "hiccup"; break;
		case 2: msg = "look"; break;
		case 3: msg = "burp"; break;
	    }
	    write("You "+msg+(msg=="look" ? " drunk." : "."));
	    say(query_cap_name()+" "+msg+"s "+(msg == "look" ? " drunk." : "."));
	}
    }
    if(query_stuffed()) {
	healing["stuffed"]--;
	if(healing["stuffed"] < 0) healing["stuffed"] = 0;
    }
    if(query_quenched()) {
	healing["quenched"]--;
	if(healing["quenched"] < 0) healing["quenched"] = 0;
    }
    if(query_poisoning() && !this_object()->is_player()) add_poisoning(-1);
    return query_intox()+query_stuffed()+query_quenched();
}

void set_party(string str) {
    party = str;
}

void add_poisoning(int x) {
    if(!healing) healing = ([]);
    healing["poisoning"] += x;
    if(healing["poisoning"] < 0) healing["poisoning"] = 0;
}

void set_stats(string str, int x) {
    if(stats[str] && stats[str] != x) {
        log_file("stats", query_name()+" went from "+stats[str]+" to "+x+
        " in "+str+" ("+ctime(time())+")\n");
        log_file("stats", "PRIV: "+query_privs(previous_object())+" ("+
        file_name(previous_object())+")\n");
    }
    stats[str] = x;
    if(str == "constitution") {
	player_data["general"]["max_hp"] = 50 + 10*stats["constitution"];
	augment_body(x);
    }
    if(str == "intelligence") magic["max points"] = 50+10*x;
    if(str == "strength")
        set_max_encumbrance(x*200);
    if(str == "dexterity") set_max_sp(x*7);
}


void delete_search_path(string dir) {
    if(member_array(dir, search_path) != -1) search_path -= ({ dir });
}

void add_exp(int x) {
    if(x>0 && query_party()) {
	PARTY_OB->calculate_exp(party, x, previous_object());
	return;
    }
    player_data["general"]["experience"] += x;
    if(x > 1000) {
	log_file("exp",
	    query_name()+" received "+x+" exp from "+ (string)previous_object()->query_name()+"\n");
	log_file("exp",
	    "(PRIV: "+query_privs(previous_object())+" "+file_name(previous_object())+": "+
	    ctime(time())+"\n");
    }
    if(creatorp(this_object()) || !this_object()->is_player()) return;
}

void fix_exp(int x, object tmp) {
    player_data["general"]["experience"] += x;
    if(x> 600) {
        log_file("exp",
	  query_name()+" received "+x+" exp in party: "+party+" from "+
	      (string)tmp->query_short()+"\n");
        log_file("exp",
	  "(PRIV: "+query_privs(tmp)+" "+file_name(tmp)+"): "+ctime(time())+"\n");
    }
    if(creatorp(this_object()) || !this_object()->is_player()) return;
}

void add_alignment(int x) {
    if(x>40) x = 40;
    else if(x<-40) x = -40;
    player_data["general"]["alignment"] += x;
    if(query_alignment() > 1500) player_data["general"]["alignment"] = 1500;
    if(query_alignment()< -1500) player_data["general"]["alignment"] = -1500;
}

void adj_alignment(int x) {
    add_alignment(x/200-x/50);
}

int add_intox(int x) {
    if(x>0) x = x*3 + x/2;
    if(x+healing["intox"] > HEALING_FORMULA) return 0;
    else healing["intox"] += x;
    if(healing["intox"] < 0) healing["intox"] = 0;
    return 1;
}

int add_stuffed(int x) {
    if(x>0) x = x*3;
    if(x+healing["stuffed"] > HEALING_FORMULA) return 0;
    else healing["stuffed"] += x;
    if(healing["stuffed"] < 0) healing["stuffed"] = 0;
    return 1;
}

int add_quenched(int x) {
    if(x>0) x = x*3;
    if(x+healing["quenched"] > HEALING_FORMULA) return 0;
    else healing["quenched"] += x;
    if(healing["quenched"] < 0) healing["quenched"] = 0;
    return 1;
}

void add_stat_bonus(string stat, int amount) {
    if(!stat_bonus) stat_bonus = ([]);
    if(stat_bonus[stat]) stat_bonus[stat] += amount;
    else stat_bonus[stat] = amount;
    if(!stat_bonus[stat]) map_delete(stat_bonus, stat);
}

string query_long(string unused) {
    object *inv;
    string *tmp;
    string pre, stuff, extra, reg, short;
    int i, x;

    if(this_object()->query_ghost()) return "An ethereal presence.\n";
    reg = "";
    pre = "You look over the "+query_gender()+" "+(string)this_object()->query_race()+".\n";
   if(combat::query_long("junk")) pre += ::query_long("junk")+"\n";
    if(description) pre += query_cap_name()+" "+description+"\n";
    if(severed) tmp = keys(severed);
    if(tmp && sizeof(tmp)) {
  	reg += query_cap_name()+" is missing a "+tmp[0];
	if(sizeof(tmp) > 1) {
	    if(sizeof(tmp) != 2) reg += ",";
	    for(i=1; i<sizeof(tmp); i++) {
		if(i== sizeof(tmp)-1) reg += " and a ";
		reg += " " +tmp[i];
		if(i != sizeof(tmp)-1) reg +=",";
	    }
	}
	reg += ".\n";
    }
    else reg += query_cap_name() + " has no missing limbs.\n";
    x = ((player_data["general"]["hp"]*100)/player_data["general"]["max_hp"]);
    reg += capitalize(query_subjective());
    if(x>90) reg += " is in top shape.\n";
    else if(x>75) reg += " is in decent shape.\n";
    else if(x>60) reg += " is slightly injured.\n";
    else if(x>45) reg += " is hurting.\n";
    else if(x>30) reg += " is badly injured.\n";
    else if(x>15) reg += " is terribly injured.\n";
    else reg += " is near death.\n";
    if(userp(this_object()) && query_outlaw())
      reg += query_cap_name() + " wears the mark of Cain.\n";
    stuff = "";
    extra = "";
    inv = all_inventory(this_object());
    if(sizeof(inv)) {
	for(i=0; i<sizeof(inv); i++) {
	    if(inv[i]->extra_look()) extra += (string)inv[i]->extra_look();
	    if(inv[i]->query_invis()) continue;
	    short = (string)inv[i]->query_short();
	    if(short && short != "") stuff += short + "\n";
	}
    }
    if(extra != "") pre = pre + extra;
    if(stuff == "") reg += capitalize(query_subjective())+" is empty handed.\n";
    else reg += capitalize(query_subjective())+" is carrying:\n"+stuff;
    reg = pre + reg;
    return reg;
}

int query_stats(string stat) {
    int x;

    if(stat_bonus) x= stat_bonus[stat];
    else x = 0;
    return stats[stat] + x;
}

int query_base_stats(string stat) {
    if(!stats || !stats[stat]) return 0;
    else return stats[stat];
}


nomask int query_forced() { return forced; }

string *query_search_path() {
    return search_path + ({});
}


int query_exp() { return player_data["general"]["experience"]; }


int query_alignment() { return player_data["general"]["alignment"]; }

int query_intox() {
    if(healing) return healing["intox"];
    else return 0;
}

int query_stuffed() {
    if(healing) return healing["stuffed"];
    else return 0;
}

int query_quenched() {
    if(healing) return healing["quenched"];
    else return 0;
}

int query_poisoning() {
    if(healing) return healing["poisoning"];
    else return 0;
}

string query_party() { return party; }

string query_al_title() {
    int al;

    al = player_data["general"]["alignment"];
    if(al > 1000) return "saintly";
    else if(al >750) return "righteous";
    else if(al >500) return "good";
    else if(al > 280) return "benevolent";
    else if(al > 135) return "nice";
    else if(al > -135) return "neutral";
    else if(al > -280) return "mean";
    else if(al > -500) return "malevolent";
    else if(al > -750) return "bad";
    else if(al > -1000) return "evil";
    else return "demonic";
}

int query_sight_bonus() { return sight_bonus; }

int query_age() { return __PlayerAge; }
string *query_all_stats() { return keys(stats); }

void set_description(string str) { description = str; }

string query_description() { return description; }

int remove() {
    int i;
    object *inv;

    inv = all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
	if(!inv[i]) continue;
	if(inv[i]->drop() && inv[i]) inv[i]->remove();
/* Some objects call remove() in drop() */
    }
    ::remove();
}

void adjust_biorhythms() {
    float freq, temps;

    temps = to_float(query_age()/1000);
    freq = to_float( (int)this_object()->query_stats("wisdom"));
    spiritual = to_int( 5.0 * sin(freq*temps) );
    freq = to_float( (int)this_object()->query_stats("strength") );
    physical = to_int( 5.0 * sin(freq*temps) );
}

int query_spiritual() { return spiritual; }

int query_physical() { return physical; }

string query_primary_lang() { return primary_language; }

void set_primary_lang(string str) { primary_language = str; }


// language system added by Valodin in August 1993

int query_temp_lang_bonus(string lang)
{
  if(!language_bonus)
    return 0;
  if(!language_bonus[lang])
    return 0;
  return language_bonus[lang];
}

int query_real_lang_prof(string lang)
{
  if(!languages)
    return 0;
  if(!languages[lang])
    return 0;
  return languages[lang];
}

int query_lang_prof(string lang)
{
  int ret;
  ret = query_real_lang_prof(lang);
  ret += query_temp_lang_bonus(lang);
  if(ret > 10) ret = 10;
  if(ret < 0) ret = 0;
  return ret;
}

int set_lang_prof(string lang, int i)
{
  if(!languages)
    languages = ([]);
  if(i > 10)
    i = 10;
  languages[lang] = i;
  return languages[lang];
}

int add_temp_lang_bonus(string lang, int i)
{
  if(!language_bonus)
    language_bonus = ([]);
  if(!language_bonus[lang])
    language_bonus[lang] = i;
  else
    language_bonus[lang] += i;
  return query_lang_prof(lang);
}

string *query_all_languages()
{
  string *ret;
  if(!languages)
    ret =  ({});
  else
    ret = keys(languages);
  if(!language_bonus)
    return ret;
  ret += keys(language_bonus);
  return distinct_array(ret);
}

int remove_language(string lang)
{
  if(!languages || !languages[lang])
    return 0;
  map_delete(languages, lang);
  return 1;
}


// each mapping element is an array of two ints
// The first is the number of language points amassed.  When this reaches
// (lang_prof + 1) ^ 4, the language prof advances and the language points
// are decreased.  The second number is the number of excess exp points
// have been spent.  When exp is spent, it is converted to lang_pts based
// on intelligence.  it takes (40 - int) exp pts to make one lang_pt
// -Valodin

void learn_language(string lang, int exp)
{
  int tot_exp, tmp, goal, lang_pts, intel_fac;

  if(!language_exp)
    language_exp = ([]);
  if(!language_exp[lang])
    language_exp[lang] = ({ 0, 0});
  tot_exp = exp + language_exp[lang][1];
  intel_fac = 40 - query_stats("intelligence");
  if(intel_fac < 1)
    intel_fac = 1;
  lang_pts = tot_exp / intel_fac;
  tot_exp = tot_exp % intel_fac;
  language_exp[lang][0] += lang_pts;
  language_exp[lang][1] = tot_exp;

  tmp = query_lang_prof(lang) + 1;
  if(tmp > 10)
    tmp = 10;

  while((goal = tmp * tmp * tmp * tmp) <= language_exp[lang][0])
  {
    set_lang_prof(lang, tmp);
    language_exp[lang][0] -= goal;
    tmp++;
    if(tmp > 10)
      tmp = 10;
  }
}

int *query_lang_exp(string lang)
{
  if(!language_exp)
    return ({ 0, 0 });
  if(!language_exp[lang])
    return ({ 0, 0});
  return language_exp[lang];
}

void set_gender(string str) {
    if(str != "male" && str != "female" && str != "neuter") return;
    gender = str;
}

string query_gender() { return (gender ? gender : "neuter"); }

string query_subjective() { return nominative(gender); }

string query_possessive() { return possessive(gender); }

string query_objective() { return objective(gender); }

protected  int cmd_lock(string str) {
    if(str != "terminal") return 0;
    __BeforeLocked = ({ environment(this_player()),
      file_name(environment(this_player())) });
    __Locked = 1;
    move(ROOM_LOCKED);
    message("prompt", "%^INITTERM%^\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
      "("+mud_name()+") Password: ", this_object());
    input_to("unlock", I_NOECHO | I_NOESC);
    return 1;
}

protected  void unlock(string str) {
    if((string)this_object()->query_password() !=
      crypt(str, (string)this_object()->query_password())) {
        message("prompt", sprintf("\n(%s) Password: ", mud_name()),
          this_object());
        input_to("unlock", I_NOECHO | I_NOESC);
        return;
    }
    __Locked = 0;
    if(!__BeforeLocked[0] || move(__BeforeLocked[0]) ||
      move(__BeforeLocked[1])) move(ROOM_START);
    this_object()->empty_cue();
    __BeforeLocked = ({});
    return;
}

int query_locked() { return __Locked; }

void set_outlaw(int x) {
    if(!userp(this_object())) return;
    log_file("pkflag", sprintf("%s had PK flag set to %d by %s, "
      " PRIV: %s\n", query_name(), x, file_name(previous_object()),
      query_privs(previous_object(0))));
    __PlayerKiller = x;
}

int query_outlaw() { return __PlayerKiller; }

string query_client() { return 0; }

