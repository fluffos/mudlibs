object *ai_modules = ({ });

// How many RL seconds between AI ticks. This is set pretty high to keep
// the load down; when fast responses are needed, you should try and find
// events other than the tick. The tick runs no matter what, and should
// be used primarily to move the AI through its daily routine and to
// 'turn on' the AI when there's something that needs to be taken care of.
#define HEART_BEAT_FREQUENCY 48

// Stuff that uses closures has to be nosave anyway,
// won't work otherwise...
nosave mapping ai_objects = ([ ]);
nosave mapping ai_talk_response = ([ ]);
nosave mapping ai_talk_condition = ([ ]);
nosave mixed sight_response, sight_condition;
nosave mixed depart_response, depart_condition;
nosave mixed show_response, show_condition;

symbol ai_home;

// My "home" building. Many AI's go home to one particular place
// (a lair or cave or barracks or house). It's possible to have
// two AI's that are identical but for their home. This value IS
// saved over reboots.
object query_home() {
   if( !symbolp(ai_home) )
      return 0;
   return find_objectref( ai_home );
}

void set_home( object x ) {
   ai_home = to_objectref( x );
}

mixed query_talk_response( string s ) {
   if( !s ) return ai_talk_response;
   return ai_talk_response[s];
}

mixed query_talk_responses() {
   return ai_talk_response;
}

mixed parse_talk( string s, object actor, object target ) {
   mixed key, val;

   foreach( key, val : ai_talk_response ) {
      if( member(ai_talk_condition, key) )
         if( !funcall(ai_talk_condition[key], s, actor, target) ) continue;
      if( strstr(s, key) >= 0 ) return val;
   }
   return 0;
}

void set_talk_response( mapping m ) {
   if( mappingp(m) ) ai_talk_response = m;
}

void set_talk_condition( mapping m ) {
   if( mappingp(m) ) ai_talk_condition = m;
}

void set_sight_response( mixed x ) {
   sight_response = x;
}

mixed query_sight_response() { return sight_response; }

void set_sight_condition( mixed x ) {
   sight_condition = x;
}

mixed query_sight_condition() { return sight_condition; }

void set_show_response( mixed x ) {
   show_response = x;
}

mixed query_show_response() { return show_response; }

void set_show_condition( mixed x ) {
   show_condition = x;
}

mixed query_show_condition() { return show_condition; }

void set_depart_response( mixed x ) {
   depart_response = x;
}

mixed query_depart_response() { return depart_response; }

void set_depart_condition( mixed x ) {
   depart_condition = x;
}

mixed query_depart_condition() { return depart_condition; }

varargs void add_talk_response( string keyword, mixed response, mixed condition ) {
   ai_talk_response[keyword] = response;
   if( condition ) ai_talk_condition[keyword] = condition;
   else m_delete( ai_talk_condition, keyword );
}

void remove_talk_response( string keyword ) {
   ai_talk_response -= ([ keyword ]);
   ai_talk_condition -= ([ keyword ]);
}

void _create_base_ai() {
   string *default_modules, imod;

   call_out( "update_modules", 2 );
   default_modules = this_object()->query_default_ai();
   if( pointerp(default_modules) )
   foreach( imod : default_modules ) {
      clone_object( "/ai/" + imod )->move(this_object());
   }
}

int priority_compare( object a, object b ) {
   return a->query_priority() < b->query_priority();
}

void update_modules() {
   object ob;
   int i;
   mapping free_resources, used_names;

   used_names = ([ ]);
   ai_modules = ({ });
   foreach( ob : all_inventory() ) {
      string n = ob->query_name();

      if( !ob->query_is_ai_module() ) continue;

      if( member(used_names, n) ) {
         destruct(ob);
         continue;
      }

      if( ob->query_is_ai_module() ) ai_modules += ({ ob });
      used_names += ([ ob->query_name() ]);
   }

   foreach( ob : ai_modules ) if( !objectp(ob) ) ai_modules -= ({ ob });
   ai_modules = sort_array( ai_modules, #'priority_compare );

   for( i = 0; i < sizeof(ai_modules); i++ ) {
      if( ai_modules[i]->query_priority() > 0 && (!mappingp(ai_modules[i]->query_resources()) || sizeof(ai_modules[i]->query_resources() - free_resources) == 0) )
         ai_modules[i]->enable();
      else
         ai_modules[i]->disable();
   }
}

object *query_ai_modules() {
   return ai_modules;
}

void add_ai_module( object x ) {
   if( member(ai_modules, x) >= 0 ) return;
   ai_modules += ({ x });

   remove_call_out( "update_modules" );
   call_out( "update_modules", 2 );
}

void remove_ai_module( object x ) {
   object ob;
   ai_modules -= ({ x });

   remove_call_out( "update_modules" );
   call_out( "update_modules", 2 );
}

#define AI_CALL(fn) { object ob; ai_modules -= ({ 0 }); foreach(ob: ai_modules) ob->fn; }
#define AI_SCRIPT_CALL(fn, vars) apply( (: int x = 0; mapping v=vars; object ob; ai_modules -= ({ 0 }); x += this_object()->run(fn,v); foreach(ob: ai_modules) { x += ob->run(fn,v); } return x; :) );

void on_tick() {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_tick() );
   AI_SCRIPT_CALL( "on_tick", ([]) );
}

nosave int tick_time;

void ai_heart_beat() {
   if( this_object()->query_dead() )
      return;
   if( time() > tick_time ) {
      on_tick();
      tick_time = time() + HEART_BEAT_FREQUENCY - random(3);
   }
   // used to increment tick_time outside of the if statement...
   // but that means that tick_time ALWAYS equaled now + 30 seconds
   // and as the method was being called every 2 seconds or so...
   // these ticks would absolutely NEVER happen
   //
   // Yeesh.
   //
   // - Al [ Oct, 17, 05 ]
}

int on_hire() {
   object module;

   if( this_object()->query_dead() )
      return 0;

   AI_CALL( on_hire() );
   foreach( module : ai_modules ) {
      if( member( functionlist(module), "on_hire" ) >= 0 )
         return 1;
   }
   return AI_SCRIPT_CALL( "on_hire", ([]) );
}

void on_move( object src ) {
   if( this_object()->query_dead() )
      return;
   //AI_CALL( on_move(src) );
}

void on_combat_tick( object form ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_combat_tick(form) );
   AI_SCRIPT_CALL( "on_combat_tick", ([ "target": form ]) );
}

varargs void on_talk( string text, object actor, object target ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_talk(text,actor,target) );
   AI_SCRIPT_CALL( "on_talk", ([ "actor":actor, "target":target, "message":text ]) );
}

varargs void on_show( object shown, object actor, object target ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_show(shown,actor,target) );
   AI_SCRIPT_CALL( "on_show", ([ "actor":actor, "target":target, "item":shown ]) );
}

varargs void on_soul( int type, object actor, object target, string text ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_soul(type,actor,target,text) );
   AI_SCRIPT_CALL( "on_soul", ([ "actor":actor, "target":target, "message":text, "type":type ]) );
}

varargs int on_buy( string item, object buyer ) {
   object module;

   if( this_object()->query_dead() )
      return 0;

   AI_CALL( on_buy(item,buyer) );
   foreach( module : ai_modules ) {
      if( member( functionlist(module), "on_buy" ) >= 0 )
         return 1;
   }
   return AI_SCRIPT_CALL( "on_buy", ([ "actor":buyer, "item":item ]) );
}

varargs int on_sell( string item, object seller ) {
   object module;

   if( this_object()->query_dead() )
      return 0;

   AI_CALL( on_sell(item,seller) );
   foreach( module : ai_modules ) {
      if( member( functionlist(module), "on_sell" ) >= 0 )
         return 1;
   }
   return AI_SCRIPT_CALL( "on_sell", ([ "actor":seller, "item":item ]) );
}

varargs void on_offer( object *offer, object giver ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_offer(offer, giver) );
   AI_SCRIPT_CALL( "on_offer", ([ "actor":giver, "items":offer ]) );
}

varargs void on_death( object what ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_death(what) );
   AI_SCRIPT_CALL( "on_death", ([ "actor":what ]) );
}

varargs void on_hunger() {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_hunger() );
   AI_SCRIPT_CALL( "on_hunger", ([ ]) );
}

varargs void on_thirst() {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_thirst() );
   AI_SCRIPT_CALL( "on_thirst", ([ ]) );
}

varargs void on_sight( object target, object old_env ) {
   if( this_object()->query_dead() )
      return;
   if( !target ) debug( "on_sight called in base_ai with null target. Previous object was " + as_lpc(previous_object()) );
   AI_CALL( on_sight(target, old_env) );
   AI_SCRIPT_CALL( "on_sight", ([ "actor":target, "from":old_env ]) );
}

varargs void on_depart( object who, string moveverb, string dir, object dest ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_depart(who, moveverb, dir, dest) );
   AI_SCRIPT_CALL( "on_depart", ([ "actor":who, "moveverb":moveverb, "dir":dir, "target":dest ]) );
}

varargs void on_hit( object attacker, int damage ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_hit(attacker, damage) );
   AI_SCRIPT_CALL( "on_hit", ([ "actor":attacker, "amount":damage ]) );
}

varargs void on_fight( object attacker, object victim ) {
   if( this_object()->query_dead() )
      return;
   AI_CALL( on_fight(attacker,victim) );
   AI_SCRIPT_CALL( "on_fight", ([ "actor":attacker, "target":victim ]) );
}

/// A function that picks a random exit and uses it. For convenience.
void wander() {
   object *exit_list;

   if( this_object()->query_dead() )
      return;

   // Don't wander if currently occupied.
   if( sizeof(this_object()->query_actions()) || this_object()->query_in_combat() ) return;

   exit_list = filter( all_inventory(environment()), (: $1->query_is_exit() :) );

   if( !sizeof(exit_list) ) {
      // if they can't wander out of the room, at least wander some within :P
      command("walk random",this_object());
      return;
   }

   // prevent potential problems with walking daemon
   set_this_player(this_object());
   exit_list[random(sizeof(exit_list))]->exit_action();
}

void use_ai_module( string name ) {
   object ob = clone_object( "/ai/" + name );
   ob->move(this_object());
}

object get_ai_module( string name ) {
   object *mods = filter( ai_modules, (: $1->query_module_name() == name :) );
   if( sizeof(mods) == 0 ) return 0;
   return mods[0];
}
