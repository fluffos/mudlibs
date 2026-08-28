//      /adm/daemon/race_d.c
//      the daemon for setting up race info
//      from the Nightmare Mudlib
//      created by Descartes of Borg 10 june 1993


#include <databases.h>
#include <daemons.h>
#include <dirs.h>

#define LIMB_DIR DIR_DB+"/races/"
#define PROPS_DIR DIR_DB+"/racial_props/"
#define MON_DIR DIR_DB+"/mon_races/"
inherit DAEMON;

mapping races, limbs;

int query_weight(string res, int con);
int query_fingers(string res);
int query_sight_bonus(string res);
string *query_wielding_limbs(string res);
int is_race(string res);
int query_max_dam(string limb, string res);
string *query_limbs(string res);
int is_limb(string limb, string res);

void init_data() {
  string *lines, *data, *w_limbs, *b_types;
    int i, j, tmp, tmp2,trace;

    if(this_player() && wizardp(this_player()))
      trace = (string)this_player()->getenv("TRACE") == "on";


    races = ([]);
    limbs = ([]);
    b_types = ({});
    lines = read_database(RACES_DB);

    for (i = 0, tmp = sizeof(lines); i < tmp; i++)
    {
      if (sizeof(data = explode(lines[i], ":")) != 12)
        continue;

      races[data[0]] =
          (["sight":atoi(data[1]), "weight":atoi(data[2]), "fingers":atoi(data[3])]);
      races[data[0]]["wielding"] = ({});
      for (j = 0, tmp2 = sizeof(w_limbs = explode(data[4], ";")); j < tmp2; j++)
        races[data[0]]["wielding"] += ({w_limbs[j]});
      races[data[0]]["body type"] = data[11];
      if (member_array(data[11], b_types) == -1)
        b_types += ({data[11]});
      if(trace)
        write(sprintf("races[%s] %O\n",data[0], races[data[0]]));
    }
    for(i = 0, tmp = sizeof(b_types); i < tmp; i++) {
        if(!file_exists(LIMB_DIR+b_types[i])) {
            log_file("races", "Error: No such file "+LIMB_DIR+b_types[i]+"\n");
            map_delete(races, b_types[i]);
            continue;
        }
        limbs[b_types[i]] = ([]);
        for(j=0, tmp2=sizeof(lines=explode(read_file(LIMB_DIR+b_types[i]), "\n"));
          j<tmp2; j++) {
            if(lines[j][0] == '#')
	            continue;
            if(sizeof(data = explode(lines[j], ":")) != 4)
	            continue;
            if(data[1] == "0")
              data[1] = "";
            limbs[b_types[i]][data[0]] =
              ([ "ref":data[1], "max":atoi(data[2]), "attach":data[3] ]);
            if(trace)
              write(sprintf("limbs[%s][%s] %O\n",b_types[i],data[0], limbs[b_types[i]][data[0]]) );
        }

    }
}
void create() {
  daemon::create();
  call_out("init_data", 1);
}

int query_weight(string res, int con) {
    if(!res || !con || !races[res]) return 10000;
    else return ((con-10)*100 + races[res]["weight"]);
}

int query_fingers(string res) {
    if(!res || !races[res]) return 5;
    else return races[res]["fingers"];
}

int query_stat_adjustment(string stat, string res);
int query_sight_bonus(string res) {
    if(!res || !races[res]) return 0;
    else return races[res]["sight"];
}

string *query_wielding_limbs(string res) {
    if(!res || !races[res])
        return ({ "right hand", "left hand" });
    else return races[res]["wielding"];
}

int is_race(string res) {
    return (member_array(res, keys(races)) != -1);
}

int query_max_dam(string limb, string res) {
    if(!limb || !res || !races[res] || !limbs[races[res]["body type"]])
      return 2;
    if(limb == "torso") return 1;
    else if(!limbs[races[res]["body type"]][limb]) return 0;
    else return limbs[races[res]["body type"]][limb]["max"];
}

string *query_limbs(string res) {
    if(!res || !limbs[races[res]["body type"]]) return query_limbs("human");
    else return keys(limbs[races[res]["body type"]]);
}

string *query_races() { return keys(races); }

mapping query_racial_properties(string race) {
    string *props, *tmp;
    mapping ret_val;
    int i;

    if(member_array(race,keys(races)) < 0) return 0;
    race = replace_string(race," ","_");
    if(!file_exists(PROPS_DIR+race)) return 0;
    props = read_database(PROPS_DIR+race);
    i = sizeof(props);
    ret_val = allocate_mapping(i);
    while(i--) {
	if(sizeof((tmp = explode(props[i],":::"))) != 2) continue;
	ret_val[tmp[0]] = (mixed)REFS_D->resolv_str(tmp[1]);
    }
    return ret_val;
}

int is_limb(string limb, string res) {
    if(!limb || !res || !limbs[races[res]["body type"]]) return 0;
    else
      return (member_array(limb, keys(limbs[races[res]["body type"]])) != -1);
}

mapping body(object ob)
{
  mapping borg;
  string res;
  string *what;
  int i, tmp, max;

  if(!limbs || !races)
    init_data();
  borg = ([]);
  res = (string)ob->query_race();
  if (!res)
    res = "human";
  max = (int)ob->query_max_hp();

  borg["torso"] =
      (["limb_ref":"FATAL", "max_dam":max, "damage":0, "ac":0]);

  for (i = 0, tmp = sizeof(what = keys(limbs[races[res]["body type"]]));
       i < tmp; i++)
    borg[what[i]] =
        (["limb_ref":limbs[races[res]["body type"]][what[i]]["ref"],
             "max_dam":max / limbs[races[res]["body type"]][what[i]]["max"],
              "damage":0, "ac":0]);
  return borg;
}
int *do_rolls() {
  int *ret, *rolls;
  int i, low_roll, idx;

  ret = allocate(7);
  low_roll = 150;
  for(i=0 ; i < 7 ; i++) {
    ret[i] = 12 + random(50) + random(50);
    if(ret[i] < low_roll) {
      idx = i;
      low_roll = ret[i];
    }
  }
  rolls = ({});
  for(i=0; i < 7; i++)
    if(i != idx) rolls += ({ ret[i] });
  return rolls;
}

mapping query_limb_info(string limb, string res) {
    if(!res || !limbs[res]) res = "human";
    if(!limb || !limbs[res] || !limbs[res][limb]) return 0;
    return limbs[res][limb];
}

int query_stat_adjustment(string stat, string res) {
    if(!stat || !res || !races[res]) return 0;
    return races[res][stat];
}

// Monster Race related code
// by Valodin, June 28, 1993
int is_monster_race(string str)
{
  if(is_race(str))
    return 1;
  return (member_array(str, get_dir(MON_DIR)) != -1);
}

mapping monster_body(string mon_race, int max)
{
    mapping borg;
    string *what, *lines, *data;
    int i, tmp;

    borg = ([]);
    if(!mon_race || !is_monster_race(mon_race)) mon_race = "human";
    borg["torso"] =
      ([ "limb_ref": "FATAL", "max_dam": max/2+1, "damage":0, "ac":0 ]);
    if (is_race(mon_race))
      for(i=0, tmp = sizeof(what=keys(limbs[races[mon_race]["body type"]]));
	  i < tmp; i++)
        borg[what[i]] =
	  (["limb_ref":limbs[races[mon_race]["body type"]][what[i]]["ref"],
	    "max_dam": max/limbs[races[mon_race]["body type"]][what[i]]["max"],
	    "damage":0, "ac":0
	    ]);
    else
    {
      message("debug", sprintf("loading %s", MON_DIR + mon_race), find_player("parnell"));
      for (i = 1, tmp = sizeof(lines = explode(read_file(MON_DIR + mon_race),
                                               "\n"));
           i < tmp; i++)
      {
        if (sizeof(data = explode(lines[i], ":")) != 4)
          continue;
        if (data[1] == "0")
          data[1] = "";
        borg[data[0]] =
            (["limb_ref":data[1], "max_dam":max / atoi(data[2]), "damage":0, "ac":0]);
      }
    }
    return borg;
}

string *query_monster_wielding_limbs(string race)
{
  string *lines;

  if(is_race(race))
    return query_wielding_limbs(race);
  else
  {
    if(file_size(MON_DIR + race) < 0)
      return query_wielding_limbs("human");
    lines = explode(read_file(MON_DIR + race), "\n");
    lines = explode(lines[0], ":");
    return (explode(lines[1],";"));
  }
}

int query_monster_fingers(string race)
{
  string *lines;

  if(is_race(race))
    return query_fingers(race);
  else
  {
    if(file_size(MON_DIR + race) < 0)
      return query_fingers("human");
    lines = explode(read_file(MON_DIR + race), "\n");
    lines = explode(lines[0], ":");
    return (atoi(lines[0]));
  }
}

int query_max_mon_dam(string limb, string b_type) {
  string *lines, *data;
  int i, tmp;

  if(!limb || !b_type)
    return 2;
  if(limb == "torso") return 1;
  else if(!limbs[b_type])
  {
    if(file_size(MON_DIR + b_type) < 0) return 2;
    for(i = 1, tmp = sizeof(lines = explode(read_file(MON_DIR + b_type),
					    "\n")); i < tmp; i++) {
      if(sizeof(data=explode(lines[i], ":")) != 4) continue;
      if(data[0] == limb) return atoi(data[2]);
    }
    return 2;
  }
  else if(!limbs[b_type][limb]) return 2;
  else return limbs[b_type][limb]["max"];
}
