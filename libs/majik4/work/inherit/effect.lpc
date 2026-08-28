/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <effect.h>

/* --- -- - variables - -- --- */

mapping effects;

/* --- function prototypes --- */

int reset_effects();
int add_hb_effect(string,int,string,string,string);
int add_effect(string,string,string,string); 
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

int 
reset_effects()
{
   effects = ([ ]);
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
 *        (string)    round_f        - name of the function that is called
 *                                     each round the effect is activated
 * 
 *  the functions given in start_f and end_f _must_ exist. 
 *  round_f is optional. 
 *
 *  ** WARNING **:
 *         Creating effect that doesn't have properly working end function,
 *         for example +str potion that doesn't reduce str after effect has
 *         ended, is NOT allowed !!
 * */

int 
add_hb_effect(string fx, int duration, string start_f, string end_f, string round_f)
{
   if (!effects)
	 reset_effects();
   
   /* We do not redefine effects in case they are already defined because
	* this may cause a lot of problems with certain types of effects, notably
	* if there is a variable which is incremented every hb within an effect,
	* and that variable has some sort of role which directly translates
	* to objects. An example would be a light spell which causes a living
	* object's gridlight to change every 20 hb's. */
   if(!effects[fx])
	 call_other(PREV(0), start_f);
   else
	 return 0;
   
   effects += ([ fx : ({ 0, duration, base_name(PREV(0)), start_f, end_f, round_f }) ]);
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
 *        (string)    round_f        - name of the function that is called
 *                                     every round the effect is activated
 * 
 *  the functions given in start_f and end_f _must_ exist. 
 *  round_f is optional.
 *
 *  ** WARNING **:
 *         Creating effect that doesn't end properly, is NOT allowed!
 * */

int 
add_effect(string fx, string start_f, string end_f, string round_f)
{
   if (!effects)
	 reset_effects();
   
    /* We do not redefine effects in case they are already defined because
	 * this may cause a lot of problems with certain types of effects, notably
	 * if there is a variable which is incremented every hb within an effect,
	 * and that variable has some sort of role which directly translates
	 * to objects. An example would be a light spell which causes a living
	 *  object's gridlight to change every 20 hb's. */
   if (!effects[fx])
	 call_other(PREV(0), start_f);
   else
	 return 0;
   
   effects += ([ fx : ({ 0, -1, base_name(PREV(0)), start_f, end_f, round_f }) ]);
   return 1;
}

/*
 * int stop_effect(string fx)          stops an active effect
 * */

int 
stop_effect(string name)
{
   mixed fx;
   if (!name)
	 return 0;
   
   fx = effects[name];
   
   if (!fx)
	 return 0;
   
   call_other(load_object(fx[FX_OBJECT]), fx[FX_END_FUN]);
   map_delete(effects, name);	
   return 1;
}

/*
 * mapping query_effects()             returns the effect mapping
 * */

mapping 
query_effects()
{
   return effects;
}

/*
 * mixed query_effect()                returns the effect array
 * */

mixed 
query_effect(string fx)
{
   return effects[fx];
}

/*
 * int query_effect_duration()         returns the duration of an effect or -1
 *                                     if effect doesn't have one
 * */

int 
query_effect_duration(string fx)
{
   if (!effects[fx])
	 return 0;
   return effects[fx][FX_DURATION];
}

/*
 * int query_effect_counter()          returns the number of seconds effect
 *                                     has been active
 * */

int
query_effect_counter(string fx)
{
   if (!effects[fx])
	 return 0;
   return effects[fx][FX_COUNTER];
}

/*
 * void effect_beat()                  called by heart beat 
 * 
 * */

void 
effect_beat()
{
   int i, j;
   string *fxs;
   mixed fx;
      
   if (!effects || effects == ([]))
	 return;
   
   fxs = keys(effects);
   
   for(i=0,j=sizeof(fxs);i<j;i++)
	 {
		fx = effects[fxs[i]];
		
		if (fx[FX_DURATION] >= 0)
		  {
			 fx[FX_COUNTER]++;
			 if (fx[FX_ROUND_FUN])
			   call_other(load_object(fx[FX_OBJECT]), fx[FX_ROUND_FUN], fx[FX_COUNTER]);
			 if (fx[FX_COUNTER] >= fx[FX_DURATION])
			   stop_effect(fxs[i]);
		  }
	 }
}
