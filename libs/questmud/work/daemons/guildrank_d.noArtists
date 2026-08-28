/* guildrank_d for getting guild ranks and calculating the guild leader by Celtron */

#define SKILLFUN "/guilds/obj/skillfun"
#define GUILDS    6
#define SAVEFILE "/data/guildrank"

static mapping max_scores;
mapping leaders;

void reset(status arg) {
  if(arg) return;
  max_scores = ([ ]);
  leaders=([
  "fighter":0;0,
  "cleric":0;0,
  "mage":0;0,
  "abjurer":0;0,
  "necromancer":0;0,
  "witch":0;0,
  "psionic":0;0,
  "warlock":0;0
            ]);
  if(!restore_object(SAVEFILE))
    save_object(SAVEFILE);
}
void save_leaders() {
  save_object(SAVEFILE);
}

string *query_guilds() {
  string *guild;

  guild =       ({
                "fighter", "cleric", "mage", "abjurer", 
                "necromancer", "witch", "psionic", "warlock",
                }); 
 
//  guild=m_indices(leaders);
  return guild;
}

string *query_base_guild_files() {
  string *files;
  files = ({    "/guilds/fighter/fighter",
                "/guilds/channel/appr_cleric",
                "/guilds/mage/apprmage",
                "/guilds/abjurer/abjurers",
                "/guilds/necro/base_guild",
                "/guilds/witch/witch",
                "/guilds/psi/psiguild",
                "/guilds/warlock/warlock",
        });
  return files;
}

status is_member_of_guild(object player, string guild) {
  string *guilds, *files;
  int i;
  guilds = query_guilds();
  files = query_base_guild_files();
  for(i=0; i < sizeof(guilds); i++) {
    if(guilds[i] == guild)
      return 0 < player->query_guild_level(call_other(files[i], "guild_name"));
  }
  return 0;
}

string query_guild_leader(object player) {
  string tmp, *guild;
  int i;
  tmp = "";
  guild = query_guilds();
    for(i=0;i<sizeof(guild);i++) 
    {
    if(leaders[guild[i],0] == player->query_real_name())
    tmp += capitalize(player->query_pronoun())+" leads the "+guild[i]+" guild.\n";
    }
  if(tmp == "") return 0;
  return tmp;
}

reset_guild_leader(string guild, string player_name) {
  int i;
  string guilds;
  if(guild) {
    leaders[guild,0] = 0;
    leaders[guild,1] = 0;
    return 1;
  }
  if(!player_name) return 0;
  guilds = query_guilds();
  for(i=0; i < sizeof(guilds); i++) {
    if(leaders[guilds[i],0] == player_name) {
       leaders[guilds[i],0] = 0;
       leaders[guilds[i],1] = 0;
    }
  }
  save_leaders();
}

string query_leader(string guild) {
    if(leaders[guild,0]) {
        return leaders[guild,0];
    } else {
        return("no one");
    }
}

void get_leader_ob(string guild) {
  object ob;
  string item;

  if(guild == "fighter") item = "fighter_belt";
  if(guild == "mage") item = "mage_cloak";
  if(guild == "cleric") item = "cleric_amulet";
  if(guild == "abjurer") item = "abjurer_necklace";
  if(guild == "necromancer") item = "necromancer_pendant";
  if(guild == "psionic") item = "psionic_orb";
  if(guild == "warlock") item = "warlock_crown";

  write("You are given the guildmaster item.\n");
  if(!item) return;
  item = "/guilds/obj/guild_leader_eq/"+item;
  ob = clone_object(item);
  move_object(ob, this_player());
}

try_lead() {
  int i;
  string guild;

  guild = query_guilds();

// Bypass login leadertest, only check for leaderob --N

  for(i=0; i < sizeof(guild); i++)      {
    if(leaders[guild[i],0] == this_player()->query_real_name()) 
        {
        get_leader_ob(guild[i]);
        }
                                        }
return 1;
}

test_lead() {
  int score,i,tmp;
  string guild;
  string *gfiles;

  if    (       
        this_player()->query_wiz()      || 
        this_player()->query_tester()   ||
        this_player()->query_ghost()
        )
        {
        write("You are a wizard/tester/ghost.\n"); 
        return -1;
        }

  guild = query_guilds();
  gfiles = query_base_guild_files();

  // Kludge-show
  for(i=0; i < sizeof(gfiles); i++) 
     {
      if(file_name( environment( this_player() ) ) == gfiles[i]) break;
     }

        if(i == sizeof( gfiles ) ) 
        { 
         tell_object(this_player(), 
                "This isn't the right room for leading this guild.\n");
         return 1;
        }

  if(this_player()->query_tester() || this_player()->query_wiz())
  {
   tell_object(this_player(),
        "Wiz-info: "+ file_name( environment( this_player() ) ) +
        " compared to "+ gfiles[i] +"\n");
  }

    score = count_rank_score(this_player(), guild[i]);
    if(leaders[guild[i],1] < score && score > 2000 &&
       leaders[guild[i],0] != this_player()->query_real_name()) {

  // if(guild[i]!=this_player()->query_starter_guild()) return 1;

        // Update the score
        if(leaders[guild[i],0] == this_player()->query_real_name()) 
        {
        if(score>leaders[guild[i],0]) leaders[guild[i],1]=score;
        }

  // a player can only lead one guild
      if(query_guild_leader(this_player()) ) {
        write("You would be ready for the leadership but you already lead one guild.\n");
      } else {
  // mark the new guildmaster
        leaders[guild[i],1] = score;
        leaders[guild[i],0] = this_player()->query_real_name();
        write("Your supreme knowledge outranks the other guild members. All hail the new guildmaster!\n");
        get_leader_ob(guild[i]);

        save_leaders();
        return 1;
      }
    } 
  
  save_leaders();
  return 0;
}

/* returns (string)rank_name for a whole guild. (int)i is the rank_score */
get_rank_status(string guild, int i) {
  int max_sc, n;
  string ranks;
  if(!i) return 0;
  if(guild == "fighter")
    ranks = ({"a brawler", "a soldier", "a corporal", "a sergeant", "a lieutenant", "a commander", "a general",});
  if(guild == "cleric")
    ranks = ({"an initiate", "a cleric", "a preacher", "a priest", "a high priest", "a bishop", "a cardinal",});
  if(guild == "mage")
    ranks = ({"an apprentice", "a magician", "a chanter", "a mage", "an elementalist", "an adept", "an archmage",});
  if(guild == "abjurer")
    ranks = ({"an apprentice abjurer", "a spellweaver", "an enchanter", "an abjurer", "a protector", "an adept protector",
        "a master protector",});
  if(guild == "necromancer")
    ranks = ({"a child of decay", "a bringer of sorrow", "a lifebane", "a necromancer", "a soulsucker", "a tool of death",
        "a spawn of terror",});
  if(guild == "witch")
    ranks = ({"a sybil", "a hermit", "a hag", "a crone", "a witch", "a mystic", "witch of the dark wood",});
  if(guild == "psionic")
    ranks = ({"a clairsentient", "a psychokinetic", "a psychoportive", "a telepathic", "a metapsionic", "A master psionic", "A supreme psionic",});
  if(guild == "warlock")
    ranks = ({"a warlock", "a warlock", "a warlock", "a warlock", "a warlock", "a grand warlock", "a elder warlock",});
  if(!max_scores[guild]) define_max_score(guild);
  max_sc = max_scores[guild];

  /* n% of max score. ranks [0,9](no rank) ; 10% 20% 30% 40% 50% 60% 70% */
  n = i*100 / max_sc;
  n = n / 10;

  if(!n) return 0;
  n -= 1;

  if(n < 0) n = 0;
  if(n > 6) n = 6;
/*  else if (n == 6) n = 5; max rank at 80% of max score */

  return ranks[n];
}


query_rank(mixed str, string guild, status verbose) {
  object ob;
  int rank_score, i;
  string rank_status;
  if(!str) return 0;
  if(stringp(str))
    ob = find_player(str);
  else
    ob = str;
  if(!ob || ob->query_wiz()) return 0;
  if(guild && is_member_of_guild(ob, guild)) {
    rank_score = count_rank_score(ob, guild,0,verbose);
    define_max_score(guild);
    rank_status = get_rank_status(guild, rank_score);
    return make_phrase(ob, rank_status);
  }
  guild = query_guilds();
  rank_status = "";
  while(i < sizeof(guild)) {
    if(is_member_of_guild(ob, guild[i])) {
      define_max_score(guild[i]);
      rank_status += make_phrase(ob, get_rank_status(guild[i], count_rank_score(ob, guild[i],0,verbose) ) );
    }
    i += 1;
  }
  return rank_status;
}

string make_phrase(object ob, string rank_status) {
  if(!rank_status) return "";
  return capitalize(ob->query_pronoun())+" has the rank of "+rank_status+".\n";
}

define_max_score(string guild) {
  if(max_scores[guild]) return;
  max_scores += ([ guild : count_rank_score(0, guild, 1) ]);
}

string get_guild_dir(string guild) {
  switch(guild) {
    case "fighter": return "/guilds/fighter/";
    case "cleric": return "/guilds/channel/";
    case "mage": return "/guilds/mage/";
    case "necromancer": return "/guilds/necro/";
    case "abjurer": return "/guilds/abjurer/";
    case "witch": return "/guilds/witch/";
    case "psionic": return "/guilds/psi/";
    case "warlock": return "/guilds/warlock/";
  }
  return 0;
}

/* returns (int)rank for a whole guild */
count_rank_score(object player, string guild_name, status max_score, status verbose) {
  int rank_score,i;
  string files, dir;
  /* var files is allocated. get a whole dir (lazymode)  */
  dir = get_guild_dir(guild_name);
  if(!dir) return -1;
  files = get_dir(dir);
  while(i<sizeof(files)) {
    /* see if file ends with .c, so it can be loaded if it doesn't bug */
    if(files[i][(strlen(files[i])-2)..strlen(files[i])] == ".c") {
      files[i] = dir + files[i];
      /* if file is not a guild file, why bother to send for loop */
      if(this_player()->query_wiz() && verbose) write("GUILD_FILE: "+files[i]+"  ");

      if(catch(files[i]->guild_max_level() ))
        log_file("BUGGING_FILE", ctime(time())+" "+files[i]+"\n");
      else if(files[i]->guild_max_level())
        rank_score += guild_rank_score(player, files[i], max_score);
    }
    i += 1;
  }
  return rank_score;
}

/* returns (int)rank for a subguild */
guild_rank_score(object player, string file, status max_score) {
  mapping skill;
  string skill_names;
  int i, rank_score;
  skill = ([ ]);
  skill = file->get_skill_max(0, 5, file->guild_max_level());
  skill_names = m_indices(skill);
  while(i < sizeof(skill_names)) {
    if(max_score) {
      rank_score += 100 * SKILLFUN->skill_cost(skill_names[i]);
    }
    else {
         rank_score += (int)(player->query_skills(skill_names[i])) * (int)(SKILLFUN->skill_cost(skill_names[i]));
    }
    i += 1;
  }
  return rank_score;
}

/* returns the highest rank of all guilds that a player has */
query_highest_rank(object player) {
  string *guilds, rank, *str;
  int i, cond_max, tmp;
  guilds = query_guilds();
  for(i=0; i < sizeof(guilds); i++) {
    tmp = count_rank_score(player, guilds[i]); /* * 100 / (count_rank_score(player, guilds[i], 1)+1); */
    if(cond_max < tmp) {
      cond_max = tmp;
      rank = get_rank_status(guilds[i], count_rank_score(player, guilds[i]));
    }
  }
  if(!rank) return 0;
  str = explode(rank, " ");
  rank = "";
  for (i=1; i < sizeof(str); i++) {
    if(rank != "") rank += " ";
    rank += capitalize(str[i]);
  }
  return rank;
}
