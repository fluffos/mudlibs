
/*
 * Shadow Master (3/5/94)
 * Objects which are allowed to shadow any object that has
 * query_limited_shadow() { return 1; } is stored here.
 * master.c checks this file each shadowing attempt
 */


string *shadows;

reset(arg) {
   if(arg) 
     return;
  /* 12/17/06 Earwax: moved some of the obsolete ones out. */
  /*
                "players/sandman/paladin/obj/pr_evil",
                "players/sandman/paladin/practice/shadow",
             "players/sandman/paladin/obj/mark",
             "players/mythos/closed/guild/tlight",
             "players/mythos/healerguild/obj/shade",
             "players/mythos/healerguild/obj/blessing",
  */
   shadows = ({ 
             "players/molasar/sparring/shadow",
             "players/dune/closed/guild/objects/shadow",
             "players/pestilence/closed/destroyer/obj/shadow",
             "players/beck/Lib/Shadow",
             "players/eurale/VAMPIRES/vshadow",
             "players/guilds/shadow/shadow_shadow",
             "players/vertebraker/closed/shardak/obj/sshadow",
             "players/vertebraker/closed/shardak/obj/circle",
             "players/jaraxle/templar/doc/shield_shadow",
             "players/fred/mages/obj/lich",
             "players/fred/mages/obj/deathknight",
             "players/rumplemintz/closed/myshad",
             "players/fred/closed/bloodfist/obj/player_shadow",
             "players/vertebraker/guilds/samurai/obj/stun_shadow",
             "players/pavlik/guild/mages/objects/augury",
             "players/earwax/closed/test/tshadow",
             "players/guilds/healers/obj/shade",
             "players/guilds/healers/obj/blessing",
             "players/earwax/closed/obj/qt_shadow",
             "players/sparrow/closed/guild/obj/player_shadow",
             "players/vertebraker/guilds/wh/std/player_shadow",
             "players/dragnar/daemons/shop_shadow",
             "players/guilds/dopplegangers/obj/morph_shadow",
             });
}

/*
query_shadows() { return shadows; }
*/
nomask int query_shadows(string file) {
           return member_array(file, shadows);
}
/* Changed not to return entire array for security purposes... -Bp */
