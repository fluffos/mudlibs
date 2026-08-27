
/*** An inheritable base spell.  Wonderflug 1995 ***/
#define RANGE_HANDLER "/obj/handlers/range"
inherit "/std/spells/patch";
string spell_name;              /* name of the spell */
string sphere;                  /* sphere the spell belongs to */
string school;                  /* school the spell belongs to */
string help_desc;               /* The text of the help description */
string help_extras;             /* Extra fields of help to go before desc */
string target_type;             /* targeting that the spell shall use */
string* property_checks;        /* Properties to prevent this spell casting */
int casting_time;               /* time in hbs to cast the spell */
int gp_cost;                    /* cost in gp of the spell */
int spell_level;                /* level of the spell */
int spell_range;                /* range of the spell */
int line_of_sight_needed;       /* if line of sight is needed during casting */
int on_ghost;                   /* if the spells is allowed on ghosts */
/* The following can be either function names or other strings.
 * If they are function names then that function will get called during
 * the corresponding round of casting.  If they are strings then they
 * shall just be output during that round of casting.  (Yes in both
 * cases they are strings you idiot, but we check if they are functions
 * with function_exists).  For functions the format of the function should
 * be:
 *    int function(object caster, mixed target, mixed out, int time, int quiet)
 *      - caster is the caster of the spell
 *      - target is 0, a single target object or an array of target objects
 *        note all of these are in range of the spell during this round
 *      - out is either 0, a single target or an array of targets that are now
 *        out of range of the caster.
 *      - time is the number of the round of casting we are performing 
 *      - quiet is whether the spell is being actually cast or not
 *        ('not' being, of course, from a wand or something)
 */
mixed* round;                   /* what happens during various rounds */
void set_spell_name(string str) { spell_name = str; }
void set_sphere(string str) { sphere = str; }
void set_school(string str) { school = str; }
void set_help_desc(string str) { help_desc = str; }
void set_help_extras(string str) { help_extras = str; }
void set_casting_time(int i) { casting_time = i; }
int query_gp_cost() { return gp_cost; }
void set_gp_cost(int i) { gp_cost = i; }
void set_spell_level(int i) { spell_level = i; }
void set_range(int i) { spell_range = i; }
void set_line_of_sight_needed(int i) { line_of_sight_needed = i; }
void add_property_to_check(string str) { property_checks += ({ str }); }
void set_target_type(string str) {  target_type = str; }
void set_rounds(mixed* p)
{
    if ( sizeof(p) != casting_time )
	write("This spell has a bug to do with casting times, tell someone.\n");
    round = p;
}
void allow_on_ghosts() { on_ghost = 1; }
int query_allowed_on_ghosts() { return on_ghost; }
create()
{
    spell_name = "Wonderflug's Ultimate Torture";
    sphere = 0;
    school = 0;
    spell_level = 0;
    target_type = "none";
    spell_range = 0;
    line_of_sight_needed = 0;
    property_checks = ({"casting"});
    help_desc = "This spell provides ultimate torture to the builder "
    "who wrote it, since they forgot to add a help description.\n\n";
    help_extras = 0;
    casting_time = 1;
    gp_cost = 1;
    round = ({ });
    // Radix was here...
    seteuid("/secure/master"->creator_file(file_name(this_object())));
    this_object()->setup();
}
mixed stats()
{
    return ({ "Spell_name", spell_name, 
      "Sphere", sphere, 
      "School", school, 
      "Spell_level", spell_level, 
      "Target_type", target_type,
      "Range", spell_range,
      "Line_of_sight_needed", line_of_sight_needed,
      "Property_checks", property_checks,
      "Help_desc", help_desc,
      "Help_extras", help_extras,
      "Casting_time", casting_time,
      "Gp_cost", gp_cost,
      "Round", round,
    });
} 
string help() 
{
    string ret = "";
    ret += "\n\n";
    ret += "Spell Name: " + spell_name;
    if ( school )
	ret +=  "\nSchool: " + school;
    else if ( sphere )  
	ret +=  "\nSphere: " + sphere;
    ret += "\nLevel: " + spell_level;
    ret += "\nRange: " + spell_range;
    if ( line_of_sight_needed )
	ret += "  (A line of sight is needed)";
    ret += "\nGp Cost: "+ gp_cost;
    if ( help_extras )
	ret += "\n" + help_extras;
    ret += "\nDescription: \n     " + help_desc;
    ret += "\n\n";
    return ret;
}
int cast_spell(string str, object who, int quiet)
{
    mixed ob;
    mixed exstr;
    object caster;
    int i;
    int my_gp_cost;
    if (who) 
	caster = who;
    else 
	caster = this_player();
    // Inaudibility spell patch
    if(caster->query_property("inaudible"))
    {
	caster->remove_static_property("inaudible");
	quiet = 1;
    }
    if ( interactive(caster) )
    {
	string s = file_name(this_object());
	/* Yes we do an anal check, but there is a back door */
	if ( strlen(s) && !caster->query_creator() 
	  && !caster->query_property("I am a test character") )
	{
	    string* ss = explode( s, "/" );
	    if ( sizeof(ss) && ss[0] != "std" )
	    {
		tell_object(caster, "Mortals may not use this spell, since it "
		  "has not been approved.\n");
		return 1;
	    }
	}
	str = (string)caster->expand_nickname(str);
    }
    if(caster->query_property("nocast") ||
     environment(caster)->query_property("nocast") ||
     caster->query_property("passed out")){
      tell_object(caster,"You can't cast anything right now.\n");
      return 1;
   }
    if ( (int)caster->query_spell_effect(sphere) ||
      (int)caster->query_spell_effect(school) )
    {
	tell_object(caster,"You are already casting a "+
	  (sphere ? sphere : (school ? school : "") ) + " spell.\n");
	return 1; 
    }
    /* This goes out if allowing multiple casting */
    if ( caster->query_spell_effect("spell") )
    {
	tell_object(caster, "You are too busy casting a spell.\n");
	return 1;
    }
    /* Do the property checks. */
    for ( i=0; i<sizeof(property_checks); i++)
	if ( caster->query_property(property_checks[i]) )
	{
	    tell_object(caster, "You cannot cast this spell right now.\n");
	    return 1;
	}
	// Taniwha, prevent "spam" casting
    caster->add_timed_property("casting",1,1);
    /* This allows some extra, customizable checks here. */
    if ( function_exists("extra_checks", this_object() ) &&
      ( stringp( exstr=this_object()->extra_checks(str, caster) ) ) )
    {
	tell_object(caster, exstr);
	return 1;
    }
    ob = 0;
    if ( target_type == "one" )
    {
	ob = find_one_match( str, environment(caster), !on_ghost);
	//if(ob && ob->query_hide_shadow()) ob = 0; // Taniwha 1996 
    }
    else if ( target_type == "many" )
	ob = find_unique_match( str, environment(caster), !on_ghost);
    else if ( target_type == "item" )
    {      
	string str1,str2;
	object inwho;
	if(strsrch(str," on ") >= 0) // it's an item in someone/something
	{
	    sscanf(str,"%s on %s",str1,str2);
	    if(stringp(str2))
	    {
		inwho = present(str2,ENV(caster));
		if(inwho)
		{
   ob = present(str1,inwho);
		}
	    }
	}
	if(!ob)
	{
	    ob = find_one_match( str, caster );
	}
	if(!ob)
	    ob = find_one_match( str, environment(caster), !on_ghost);

    }
    else if ( target_type == "pass" )
	ob = str;
    if ( ( (target_type == "one" || target_type == "item") && !ob ) || 
      ( target_type == "many" && !sizeof(ob) ) )
    {
	tell_object(caster, "There doesn't appear to be anyone of that name "
	  "here.\n");
	return 1;
    }
    if ( sphere )
	switch ( caster->query_sphere_power(sphere) )
    {
    case "minor": my_gp_cost = 2*gp_cost; break;
    case "major": my_gp_cost = gp_cost/2; break;
    default: my_gp_cost = gp_cost;
    }
    else
	my_gp_cost = gp_cost;
    if ( caster->adjust_gp(-my_gp_cost) < 0 )
    {
	tell_object(caster, "You are currently too mentally drained to cast.\n");
	return 1;
    }
    /* This goes back in if we allow multicasting.
     *if ( sphere )
     *  caster->add_spell_effect(casting_time, sphere, spell_name, 
     *    this_object(), "hb_spell", ({ ob, quiet }) );
     *else if ( school )
     *  caster->add_spell_effect(casting_time, school, spell_name,
     *    this_object(), "hb_spell", ({ ob, quiet }) );
     *else 
     *  tell_object(caster, "This spell is bugged.  Notify someone.\n");
     */
    caster->add_spell_effect(casting_time, "spell", spell_name,
      this_object(), "hb_spell", ({ ob, quiet, environment(caster) }) );
    if( !quiet )
    {
	/* So they cannot cast and move. *2 cause spell hbs are every other hb */
	/* Taking out for now, with spell hbs every other real hb, this is too
	 * erratic.  Instead we pass the original environment and check that it has
	 * not changed.
	 *  caster->add_timed_property("passed out",
	 *    "You are too busy casting a spell.\n", casting_time*2);
	 */
	tell_object(caster,"You begin to cast " + spell_name + ".\n");
	tell_room(environment(caster),
	  caster->query_cap_name()+" begins to cast a spell.\n",
	  caster);
	// Taniwha 1996. Add AND do. Problem with much delayed start to casting
	// I'll add this back if we put it in. As the mages want, they'll get better with level. (+ a "luck" component)
	if( ((int)caster->query_level() + (int)caster->query_cha()) > random(100) )
	    caster->do_spell_effects(0);
    }
    else tell_object(caster,"You begin chanting, but the words seem to disappear into a faint mist as they leave your mouth.\n");
    return 1;
}
int hb_spell(object caster, mixed *params, int time)
{
    int which_round;
    mixed target, out_of_range, mess;
    int quiet;
    int ret;
    int i;
    if ( caster->query_property("nocast") || 
      environment(caster)->query_property("nocast") )
    {
	tell_object(caster, "Bugger, you can't continue casting right now.\n");
	return 0;
    }
    if ( (target_type != "none") && environment(caster) != params[2] )
    {
	tell_object(caster, "Your movement has destroyed your spell.\n");
	// Let's remove the spell effect... Flode - 070397
	call_out("end_spell_now",0,caster);
	return 0;
    }
    which_round = casting_time - time;
    target = params[0];
    quiet = params[1];
    mess = round[which_round];
    /* First we do range checking.  What fun. */
    switch( target_type )
    {
    case "pass":
    case "none":
	out_of_range = 0;
	break;
    case "item":
	out_of_range = 0;
	/*
		if ( target )
		    if ( environment(target) != caster && 
		      environment(target) != environment(caster) )
			target = 0;
	*/
	if(!target)
	{
	    tell_object(caster,"The target of your spell seems absent.\n");
	    return 0;
	}
	break;
    case "one":
	out_of_range = 0;
	if(target)
	{
	    if ( !living(target) )
	    {
		out_of_range = 0;
		target = 0;
	    }
	    else if ( ( line_of_sight_needed && 
		!RANGE_HANDLER->check_line_of_sight( caster, target, spell_range ) )
	      || ( !RANGE_HANDLER->check_in_range( caster, target, spell_range )) )
	    {
		out_of_range = target;
		target = 0;
	    }
	}
	break;
    case "many":
	out_of_range = ({ });
	for (i=sizeof(target)-1; i>=0; i-- )
	    if ( !target[i] || !living(target[i]) )
		target = delete(target, i, 1);
	    else if (( line_of_sight_needed &&
		!RANGE_HANDLER->check_line_of_sight(caster, target[i], spell_range))
	      || ( !RANGE_HANDLER->check_in_range(caster, target[i], spell_range)))
	    {
		out_of_range += ({ target[i] });
		target = delete(target, i, 1);
	    }
	if(!target)
	{
	    tell_object(caster,"The target of your spell seems absent.\n");
	    return 0;
	}
	break;
    case "all":
	out_of_range = ({ });
	target = all_inventory(environment(caster));
	if ( !target )
	    target = ({ });
	for ( i=sizeof(target)-1; i>=0; i-- )
	    if ( !living(target[i]) )
		target = delete(target, i, 1);
	if(!sizeof(target))
	{
	    tell_object(caster,"The targets of your spell seem absent.\n");
	    return 0;
	}
	break;
    default:
	write("The targeting on this spell is broken. Tell someone.\n");
	return 0;
    }
    /* Now we call functions or what have you. */
    if ( stringp(mess) ) 
    {
	if ( function_exists( mess, this_object() ) )
	{
	    /* the string is a function name, call the function */
	    ret = call_other(this_object(), mess, caster, target, 
	      out_of_range, which_round, quiet);
	    if ( ret < 0 && !quiet )
	    {
		/* This means we must give the buggers their gp back. *scowl* */
		int my_gp_cost;
		if ( sphere )
		    switch ( caster->query_sphere_power(sphere) )
		{
		case "minor": my_gp_cost = 2*gp_cost; break;
		case "major": my_gp_cost = gp_cost/2; break;
		default: my_gp_cost = gp_cost;
		}
		else
		    my_gp_cost = gp_cost;
		// a few bugs. Easier to NOT refund GP for now. Multipel round damage spells, holy storm etc.
		//caster->adjust_gp(my_gp_cost);
		// Taniwha, remove it if it failed.
		//caster->remove_spell_effect(spell_name);
	    }
	}
	else
	{
	    /* the string is a casting message to caster only. */
	    if ( !quiet )
		tell_object(caster, ret);
	    ret = 0;
	}
    }
    else if ( pointerp( mess ) )
    {
	/* we have a set of casting messages */
	ret = 0;
	if ( quiet ) 
	    return ret;
	if ( sizeof(mess) >= 2 )
	{
	    /* one to caster, one to room */
	    tell_object(caster, mess[0]);
	    tell_room(environment(caster), mess[1], caster);
	}
	else
	    tell_room(environment(caster), 
	      "The spell is in error, notify someone.\n");
    }
    else write("This spell has an invalid round action.  Tell someone this.\n");
    return ret;
}

// Flode
void end_spell_now(object ob)
{
    ob->remove_spell_effect(spell_name);
}
