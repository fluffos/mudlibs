
/*
 * 950730 Hunter    	added call to soul_init() after all souls have 
 *			been cloned
 * 950807 Hunter    	added test for wiz_soul to fail loading
 * 950905 Hunter	added movement soul
 * 950916 Hunter	commented out query_soul(), as it is now in 
 *			RO/living
 *	  Gandalf	temp hack - query soul returns wiz soul if no 
 *			arg, otherwise behaves as hunter intended (driver 
 *			needs fixing).
 * 951017 Hunter	changed location of wiz_effects soul
 * 951019 Hunter	removed soul_init() call, as add_soul() now does
 *			it via call_out.
 * 991126 Jenna		added a call_out to soul() to avoid errors stemming
 *			from the fact that destruct() has a 0.1 sec delay.
 */

query_souls () { return souls; }

restore_objects()
{
    int xx, ix;
    tell_object(this_object(),
	"Restoring lost inventory items (if possible).\n");
    xx = sizeof(inventory);
    for (ix = 0; ix < xx; ix++)
	if (objectp(inventory[ix])) 
        move_object(inventory[ix],myself);
    inventory = 0;	
    recalc_carry(1);

    command("wear all silent", this_object());
}
/* this was nosave , buts it hard to test it that way */

restore_souls() 
{
    object ws;
    int i, s;
    string gh;
    array newSouls;

    // set_this_player(myself);
    if (query_ghost()) gh = "ghost/";
    else gh = "";

    souls = [
	"obj/souls/executor",	/* alias soul - not trusted or suid'd */
	"obj/souls/"+gh+"emote",
	"obj/souls/"+gh+"handle",
	"obj/souls/"+gh+"communicate",  
	"obj/souls/"+gh+"perception",
	"obj/souls/"+gh+"combat",
	"obj/souls/"+gh+"support",
	"obj/souls/"+gh+"state",
	"obj/souls/movement"
	];

/*
 * Race soul hack.
 */
    if ((gh != "ghost/") && race && (file_size("obj/souls/races/" 
		+race+"/"+race+".lpc") > 0) )
	 souls += ["obj/souls/races/" + race + "/"+race] ;
    if (gh == "ghost/" && race && 
	(file_size("obj/souls/races/"+race+"/ghost"+".lpc") > 0)) {
	    souls += [ "obj/souls/races/"+race+"/ghost" ];
        }

    if (query_wiz()) {
	 souls = [ "closed/wiz_soul", 
		"obj/souls/wiz/effects" ] + souls;
        }
#if 1
/* out until someone fixes TEST_REG to compile */
        if (TEST_REGISTER -> query_apprentice (name))  
		souls += [ "obj/souls/trainers"];
#endif
    s = sizeof(souls);
    newSouls = allocate(s);
    for (i = 0; i < s; i++) 
    {
	catch ws = clone_object(souls[i]);;
	if (souls[i] == "closed/wiz_soul") {
	if (intp(ws)) {
		tell_object( this_object(), 
			"error: failed to load wiz_soul!\n");
	        }
	    else {
		set_uid_me(ws, query_wiz(), name);
		soul = ws;
	        }
	}
	else 
        {
	    if (ws) set_uid_me(ws, APPRENTICE, name);
	}
	if (ws) 
        {
	    string n = file_name(this_object()) + "/" + ws->query_soul_type();
	    object no = find_object(n);
	    if (no) {
		rename_object(no, n + "/del_" + random(10000));
		destruct(no);
		}
	    rename_object(ws, n);
	    // move_object(ws, this_object());
	    add_soul(ws);       // done by soul when `owner' is set. 
        ws->init();
	}
	newSouls[i] = ws;
    }

}

/* resoul */
soul(a,silent)
{
    int i, s, num;
    array inv;
    string nam;

    inv = GetAliasedLS(0)[1];
    if (souls) 
    {
	 if (inv) 
     {
	    s = sizeof(inv);
	    for (i = 0; i < s; i++) 
        {
		  if (inv[i] && inv[i]->id("soul") && !(inv[i]->id("guild_soul")))
		  {
		    move_object(inv[i], "room/storage");
		    destruct(inv[i]);
          }
	    }
	 }
    }

    restore_souls();
    inv = contents(myself);
    call_out("restore_items", 0.2, inv, silent);
    if (environment(this_object()) && !silent)
        tell_object(myself, "You feel momentarily blank, as if you have lost your soul...\n");
    return 1;
}

restore_items(inv, silent)   /* Jenna Nov 99 */
{
    int i;

    // set_this_player(myself);
    for (i = 0; i < sizeof(inv); i ++)
    {
	    if (inv[i]) move_object(inv[i], myself);
    }
    if (environment(this_object()) && !silent)
        tell_object(myself, "You have been re-souled.\n");
    return 1;
}

nosave object combat_soul;
set_combat_soul(object arg) { combat_soul = arg;	}
query_combat_soul()	{ return combat_soul; }

/*
 * Delete this again after we fix the driver - G.
 */

