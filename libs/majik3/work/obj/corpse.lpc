inherit "/inherit/container";

int death_time;
string race;

#define DECAY_1     2 * 60
#define DECAY_2     4 * 60
#define DECAY_3     6 * 60
#define DECAY_4     8 * 60
#define DECAY_LIMIT 10 * 60

string *corpse_short = ({
  "a dead body of $N",
  "a bloody corpse of $N",
  "a mutilated corpse of $N",
  "a scattered remains of $N"
});

string *corpse_long = ({
  "Being dead still with severe bruises you guess that $N is dead.",

  "Covered in blood, $N lies on the ground, dead.",

  "$N lies on the ground with $po bodyparts severely wounded.", 

  "Blood and mutilated limbs are scattered all over the place and you " +
  "can barely recognize $N from them."
});

string *decay = ({
  "The corpse is still warm.\n",
  "The corpse is a bit cold but still has some warmth in it.\n",
  "The corpse is quite cold and it has started to decay.\n",
  "The corpse is rotten and very cold.\n"
});



init()
{
    object o, *inv;

    if ((time() - death_time) > DECAY_LIMIT)
    {
	inv = all_inventory(THOB);
	foreach (o in inv)
	o->move(ENV(THOB));
	destruct(THOB);
    }
}


create_item ()
{
  set_name (({ "a corpse", "corpse", "remains", "body", "dead body" }));
  set_short ("a nondescript corpse");
  set_dimensions (1, 1, 1);
  set_material ("flesh");
  set_no_autoload (1);
}

int create_corpse(object mon)
{
    int cond, sz;
    int hp, max_hp;
    string ldesc;
    if(!mon)
	return;

    hp = mon->query_hp();
    max_hp = mon->query_max_hp();
    weight = mon->query_weight();
	race = mon->query_race();

    if (hp > 0)
	return 0;

    sz = sizeof(corpse_short);
    cond = (100 * (-hp) / max_hp) / (100 / sz);

    if (cond >= sz)
	cond = sz - 1;
    if (cond < 0)
	cond = 0;

    set_name(({ "a corpse", "corpse", "remains", "body", "dead body" }));
    set_short(replace_string(corpse_short[cond], "$N", mon->query_cap_name()));

    set_dimensions (mon->query_weight()/2000, mon->query_height(), mon->query_weight()/5000);
    set_material ("flesh");
    set_no_autoload (1);

    if (mon->query_death_desc())
	set_long(mon->query_death_desc());
    else
    {
	ldesc = corpse_long[cond];
	ldesc = replace_string(ldesc, "$N", mon->query_cap_name());
	ldesc = replace_string(ldesc, "$n", mon->query_name());
	ldesc = replace_string(ldesc, "$po", mon->query_possessive());
	set_long(ldesc);
    }
    death_time = time();
}


string long()
{
    string str;
    object *inv;
    int i, sz;

    str = long_desc + "\n";
    if ((time() - death_time) < DECAY_1)
	str += decay[0];
    else if ((time() - death_time) < DECAY_2)
	str += decay[1];
    else if ((time() - death_time) < DECAY_3)
	str += decay[2];
    else str += decay[3];

    inv = all_inventory(THOB);
    if (sizeof(inv) == 0)
	str += "There's nothing worth of interest in this corpse.\n";
    else
    {
	str += "As you search the corpse you find ";
	for (i = 0, sz = sizeof(inv) - 1; i < sz; i++)
	    str += inv[i]->short() + ", ";
	str = str + " and " + inv[sz]->short() + ".\n";
    }

    return wrap(str);

}

string query_race()
{
	return race;
}

int query_is_corpse() { return 1; }	// should be obsolete
int is_corpse() { return 1; }
