/****
****    Command                         look
***     Description                     Look things around you :)
**      Coder                           Dazzt
*/

#undef THIS
#define THIS previous_object()

int sort_by_length (string a, string b)
{
    return strlen(a) < strlen(b);
}

main (string str, object this)
{
    string targstr, meps, outbuf = "", *buf, *desc, *out, *dir, desci = "";
    object ob, env, *liv;
    int sc, found, x, y, columns;

    if (!this)
	this = THIS;

    if (!env)
	env = ENV(this);

            columns = THIS->query_columns();
            
            if (!columns)
                columns = 75;
                 
            if (columns < 16)
                columns = 16;

    sc=this->query_sight_clarity(env->query_light_level());
    if(sc<0)
    {
	if(sc==-1)
	{
	    message("standard","It is too dark here for you to see.\n",this);
	    return 1;
	}
	if (sc==2)
	{
	    message("standard","It is too bright here for you to see.\n",this);
	    return 1;
	}
    }

    /*  If no arguments were given, return room long_desc
    */

    if (!str)
    {
	if (env->long() && !virtualp(env) && !env->query_no_wrap() &&
            !THIS->query_no_map())
	{

	    buf = allocate(6);

	    if (env->query_outdoors() != 4)
	    {
		buf[0] = "#########";
		buf[1] = "#.......#";
		buf[2] = "#.......#";
		buf[3] = "#.......#";
		buf[4] = "#.......#";
		buf[5] = "#########";
	    }
	    else
	    {
		// 012345678
		buf[0] = "%%%%%%%%%";
		buf[1] = "%.......%";
		buf[2] = "%.......%";
		buf[3] = "%.......%";
		buf[4] = "%.......%";
		buf[5] = "%%%%%%%%%";
	    }

	    dir = env->query_exit_dir();

	    for (int i=0;i<sizeof(dir);i++)
	    {
		if (dir[i] == "north")
		    buf[0][3..5] = "...";
		if (dir[i] == "northwest") {
		    buf[1][0] = '.';
		    buf[0][0..2] = "...";
		}
		if (dir[i] == "northeast") {
		    buf[1][8] = '.';
		    buf[0][6..8] = "...";
		}
		if (dir[i] == "west") {
		    buf[2][0] = '.';
		    buf[3][0] = '.';
		}
		if (dir[i] == "east") {
		    buf[2][8] = '.';
		    buf[3][8] = '.';
		}
		if (dir[i] == "south")
		    buf[5][3..5] = "...";
		if (dir[i] == "southwest") {
		    buf[4][0] = '.';
		    buf[5][0..2] = "...";
		}
		if (dir[i] == "southeast") {
		    buf[4][8] = '.';
		    buf[5][6..8] = "...";
		}
		if (dir[i] == "down")
		    buf[4][3] = '>';
		if (dir[i] == "up")
		    buf[1][5] = '<';
	    }

	    buf[this->query_gridmap()[1]][this->query_gridmap()[0]] = '@';

	    liv = all_inventory(env);

	    for (int i=0;i<sizeof(liv);i++)
	    {
		if (!liv[i]->query_gridmap())
		{
		    x = 0;
		    y = 0;
		}
		else
		{
		    x = liv[i]->query_gridmap()[0];
		    y = liv[i]->query_gridmap()[1];
		}

		if (buf[y][x] == '.' && liv[i] != this && living(liv[i]))
		    buf[y][x] = '&';
	    }

	    desc = explode(wrap(replace_string(env->query_long() +
		  env->show_doors() + env->show_blood() +
"\n" + WEATHER_D->query_weather(env->query_weather_zone()[0],
                         env->query_weather_zone()[1],
                         env->query_outdoors()), "\n", " "),columns-15), "\n");

	    out = ({ });

	    for (int i=0;i<sizeof(buf);i++)
	    {
		if (!out)
		    out = ({ "/command/mortal/map"->colorize(buf[i]) + "  " });
		else
		    out += ({ "/command/mortal/map"->colorize(buf[i]) + "  " });
	    }

	    for (int i=0;i<sizeof(desc);i++)
	    {
		if (i>sizeof(out)-1)
		    out += ({ "           ^c0^cg" + desc[i] });
		else
		    out[i] += "^c0^cg" + desc[i];
	    }
	    desci = implode(out, "\n") + "^c0\n";
	    if (this->query_security())
		outbuf += "File name: "+file_name(env)+""
		+(virtualp(env) ? " (virtual)" : "")+""
		+(env->query_no_wrap() ? " (no wrap)" : "")+"\n";

	    if (env->query_short())
		outbuf += "           ^cG" + env->query_short() + ".^c0\n";

	}
	else {
            string *k;
            string *items;
            string *allitems;
            string *obvious;
            int i;
            string tmp;

	    if (this->query_security())
		outbuf += "File name: "+file_name(env)+""
		+(virtualp(env) ? " (virtual)" : "")+""
		+(env->query_no_wrap() ? " (no wrap)" : "")+"\n";

            if (!env->query_no_wrap() && !THIS->query_no_map())
              outbuf += "           ^cG" + env->query_short() + ".^c0\n";
            else
              outbuf += "^cG" + env->query_short() + ".^c0\n";

            k = keys(env->query_exits());
            k = sort_array(k, (: sort_by_length :));

            items = keys(env->query_items());
            allitems = ({ });
            for (i = 0; i < sizeof(items); i++) {
                allitems += explode(items[i], " ");
            }
            items = sort_array(allitems, (: sort_by_length :));

            desci = env->query_long();
            obvious = ({ });
            for (i = 0; i < sizeof(k); i++) {
                tmp = replace_string(desci, k[i], "^cY" + k[i] + "^cg");
                if (tmp != desci)
                    obvious += ({ k[i] });
                desci = tmp;
            }

            for (i = 0; i < sizeof(items); i++) {
                desci = replace_string(desci, " " + items[i] + " ", " ^cG" + items[i] + "^cg ");
            }

            desci = desci + env->show_doors() + env->show_blood() +
              "\n" + WEATHER_D->query_weather(env->query_weather_zone()[0],
              env->query_weather_zone()[1], env->query_outdoors());
            
	    desci = "^cg" + desci + "\n";

            if (this->query_security()) {
                k -= obvious;
                for (i = 0; i < sizeof(k); i++) {
                    efun::write("Non-described exit: " + k[i] + "\n");
                }
            }
	}

	outbuf += desci;
	outbuf += "^c0" + env->show_exits() + "\n";

	message ("0", "\n" + outbuf, this);

	list_inventory (this);
	return 1;
    }

    /*  Parse arguments, either 'look <target>' or 'look at <target>' will do.
	 */

    if (sscanf(str, "at %s", targstr) != 1)
	targstr = str;


    /*  Check for objects in player's inventory and environment
	 */

    if (targstr == "me" || targstr == "myself")
        ob = THIS;
    else
        ob = present(targstr);

    if (ob)
    {
	message("longdesc", ob->long(), this);

	if (living(ob))
	{
	    if (ob == this)
	    {
		message("environment", capitalize(this->query_name()) +
		  " looks at " + this->query_objective() + "self.\n",
		  environment(this), this);
	    }
	    else
	    {
		message("environment", capitalize(this->query_name()) +
		  " looks at " + capitalize(ob->query_name()) + ".\n",
		  environment(this), ({ this, ob }));
		message("standard", capitalize(this->query_name()) +
		  " looks at you.\n", ob);
	    }

	    message("standard", "        " + capitalize(ob->query_possessive())+" equipment:\n", this);
	    call_other("/command/mortal/eq", "eq", ob, this);

	    return 1;
	}
	else
	{
	    message("environment", capitalize(this->query_name()) + " looks at " + 
	      ob->short() + ".\n", environment(this), this);
	    return 1;
	}
    }

    if (str)
	meps = replace_string(str, " ", "_");

    if (meps && environment(this)->look_item(meps) != "")
    {
	message("standard", environment(this)->look_item(meps), this);
	message("environment", capitalize(this->query_name()) +
	  " looks at " + str + ".\n", environment(this), this);
	return 1;
    }

    /*  No object found -- display error message
	 */

    notify_fail("There's no " + str + " here.\n");
    return 0;
}

list_inventory (object who)
{
    object *inv;
    string ext = "";

    inv = all_inventory(environment(who));
    for (int i = 0; i < sizeof(inv); i++)
    {
	ext = "";

	if (inv[i] != who)
	{
	    if (inv[i]->short() == "BATTLEMASTER")
		continue;

	    if (inv[i]->query_hide() == 1 && who->query_skill_result("awareness",inv[i]->query_skill_chance("hiding")/10) < 0)
		continue;

	    if (inv[i]->query_invis() == 1 && random(101) >
	      who->query_skill_chance("see invisible"))
		continue;

            if (living(inv[i]) && inv[i]->query_position() < POS_STANDING)
              {
                if (inv[i]->query_position() == POS_RESTING)
                  ext += " is resting here";
                else if (inv[i]->query_position() == POS_SITTING)
                  ext += " is sitting here";
                else if (inv[i]->query_position() == POS_SLEEPING)
                  ext += " is sleeping here";
                else if (inv[i]->query_position() == POS_DEAD)
                  ext += " is lying here, dead";
                else if (inv[i]->query_position() == POS_UNCONS)
                  ext += " is lying here, unconscious";
                else if (inv[i]->query_position() == POS_STUNNED)
                  ext += " is lying here, stunned";
                else
                  ext += " is floating around here";
              }

	    if (inv[i]->query_invis() == 1)
		ext += " (invisible)";

	    if (inv[i]->query_hide() == 1)
		ext += " (hiding)";

            if (living(inv[i]) && !query_heart_beat(inv[i]))
                ext += " (zombie)";

            if (inv[i]->query_is_dead() == 1)
                ext += " (dead)";

            if (inv[i]->query_is_unconscious() == 1)
                ext += " (unconscious)";

	    if (living(inv[i]) && inv[i]->query_npc() && inv[i]->query_aggressive())
	    {
		message("0", "^cP" + capitalize(inv[i]->short()) + ext+".^c0\n", who);
	    }
	    else if (living(inv[i]) && inv[i]->query_npc())
	    {
		message("standard", "^cC" + capitalize(inv[i]->short()) + ext+".^c0\n", who);
	    }
	    else if (living(inv[i]))
	    {
		message ("0", "^cY" + capitalize(inv[i]->short(who)) + ext+".^c0\n", who);
	    }
	    else
	    if(inv[i]->short())
              {
                if (inv[i]->query_weapon())
                  message ("0", "^cP" + capitalize(inv[i]->short()) +ext+".^c0\n", who);
                else if (inv[i]->is_armour())
                  message ("0", "^cc" + capitalize(inv[i]->short())+ext+".^c0\n", who);
                else
		message("standard", "^cp" + capitalize(inv[i]->short()) + ext+".^c0\n", who);
              }
	}
    }
    return 1;
}

query_author ()
{
  return "dazzt";
}

query_synopsis ()
{
  return "look [at/in] [target]";
}

query_help ()
{
  return "If no target is given for look command it will display "
       + "the description of the current room you are in. If you "
       + "specify a target you will see the description of the target. "
       + "This is one of the most used commands in the murpe. Use it "
       + "alot for there are many things to be seen and found from "
       + "item and room descriptions. The look command has been aliased " 
       + "to 'l', builtinly.";
}

query_example ()
{
  return "look at namhas";
}

query_see_also ()
{
  return "blook(1), peer(1), brief(1)";
}

query_position ()
{
  return POS_RESTING;
}

