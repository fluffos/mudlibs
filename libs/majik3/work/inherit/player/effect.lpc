/*
 * 'effect' system for Majik MURPE
 * 
 * [29.12.97, Dazzt]: v1.0, Initial revision
 * */

#define FX_COUNTER             0
#define FX_DURATION            1
#define FX_FILENAME            2
#define FX_START_FUN           3
#define FX_END_FUN             4

/* --- -- - variables - -- --- */

mapping effects;

/* --- function prototypes --- */

int reset_effects();
int add_hb_effect(string, int, string, string);
int stop_effect(string);

mapping query_effects();
mixed query_effect(string);
int query_effect_duration(string);
int query_effect_counter(string);

void effect_beat();

/* --- -- - functions - -- --- */

/*
 * void reset_effects()                resets the effect system
 * 
 * */

int reset_effects()
{
	effects = ([]);
	return 1;
}

/*
 * int add_hb_effect()                 starts a new effect on player that
 *                                     lasts 'duration' seconds
 * 
 * parameters: 
 *        (string)    fx             - effect name, _unique_ !!
 *        (int)       duration       - how many seconds effect lasts
 *        (string)    start_f        - name of the function that starts effect
 *        (string)    end_f          - name of the function that ends effect
 * 
 *  the functions given in start_f and end_f _must_ exist. 
 *
 *  ** WARNING **:
 *         Creating effect that doesn't have properly working end function,
 *         for example +str potion that doesn't reduce str after effect has
 *         ended, is NOT allowed !!
 * */

int add_hb_effect(string fx, int duration, string start_f, string end_f)
{
	string fname;
	
	if (!effects)
		reset_effects();

/* call start function */	
	if (!effects[fx])
		call_other(previous_object(), start_f);
	
	fname = file_name(previous_object());
	sscanf(fname, "%s#%*s", fname);
	
/* add the effect into effect list */	
	effects[fx] = ({ 0, duration, fname, start_f, end_f });
	
	return duration;
}

/*
 * int add_effect()                    starts a new effect on player that
 *                                     lasts until stopped
 * 
 * parameters: 
 *        (string)    fx             - effect name, _unique_ !!
 *        (string)    start_f        - name of the function that starts effect
 *        (string)    end_f          - name of the function that ends effect
 * 
 *  the functions given in start_f and end_f _must_ exist. 
 *
 *  ** WARNING **:
 *         Creating effect that doesn't end properly, is NOT allowed!
 * */

int add_effect(string fx, string start_f, string end_f)
{
	string fname;
	
	if (!effects)
		reset_effects();
	
	if (!effects[fx])
		call_other(previous_object(), start_f);

	fname = file_name(previous_object());
	sscanf(fname, "%s#%*s", fname);
	
	effects[fx] = ({ 0, -1, fname, start_f, end_f });
		
	return 1;
}

/*
 * int stop_effect(string fx)          stops an active effect
 * */

int stop_effect(string name)
{
        object ob;
	mixed fx;
	if (!name)
		return;
	
	fx = effects[name];
	
	if (!fx)
		return 0;
	
        ob = find_object(fx[FX_FILENAME]);

        if (ob)
	  call_other(find_object(fx[FX_FILENAME]), fx[FX_END_FUN]);

	map_delete(effects, name);	
	return 1;
}

/*
 * mapping query_effects()             returns the effect mapping
 * */

mapping query_effects()
{
	return effects;
}

/*
 * mixed query_effect()                returns the effect array
 * */

mixed query_effect(string fx)
{
	return effects[fx];
}

/*
 * int query_effect_duration()         returns the duration of an effect or -1
 *                                     if effect doesn't have one
 * */

int query_effect_duration(string fx)
{
	if (!effects[fx])
		return 0;
	return effects[fx][FX_DURATION];
}

/*
 * int query_effect_counter()          returns the number of seconds effect
 *                                     has been active
 * */

int query_effect_counter(string fx)
{
	if (!effects[fx])
		return 0;
	return effects[fx][FX_COUNTER];
}

/*
 * void effect_beat()                  called by heart beat 
 * 
 * */

void effect_beat()
{
	string *fxs;
	mixed fx;
	int i;
	
	if (!effects || effects == ([]))
		return;
	
	fxs = keys(effects);
	
	for (i = 0; i < sizeof(fxs); i++)
	{
		fx = effects[fxs[i]];
		
		if (fx[FX_DURATION] >= 0)
		{
			fx[FX_COUNTER]++;
			if (fx[FX_COUNTER] >= fx[FX_DURATION])
				stop_effect(fxs[i]);
		}
	}
}
			
		
		
		
	
	
	
	
