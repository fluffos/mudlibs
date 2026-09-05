
string *shield_types;		/* different types of damage we'll shield from */
int *shield_resistances;	/* how much resistance we have to each damage type */
int *shield_points;		/* how many damage points we can absorb */

/* these go in the reset() */
shield_types = ({ "physical", "magical", "other|fire" });
shield_resistances = ({ 10, 10, 50 });
shield_points = ({ 100, 100, 100 });

/*
 * custom do_damage func inside a mob
 */

do_damage(int *damage, string *method)
{
  int i, x;
  int new_dmg;
  string type;

  if(!damage)
	return 0;

  /* examine all the damage amounts and damage types that were given to us */
  i = sizeof(damage);
  while(i--)
  {
	if(!method || !method[i])
		type = "physical";
	else
		type = method[i];

	/* see if we shield this type of damage or not ... */
	x = member_array(shield_types, type);
	if(x == -1)
		continue;

	new_dmg = damage[i] * shield_resistances[x] / 100;

	shield_points[x] = damage[i] - new_dmg;

	/* once a shield type runs out of points remove it */
	if(new_dmg <= 0)
		shield_types -= ({ type; });

	/* set the new lowered damage amount into the damage array */
	damage[i] = new_dmg;
  }

  /* now pass the modified do_damage call onto the inherited object (living.c) */
  return ::do_damage(damage, method);
}

