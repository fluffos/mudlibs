/**
 * Nice login cat, full of smart things to say.
 * Created by: Who knows (If it was you, feel free to change this comment :)
 * Tidied a bit by Terano, 27/9/98
 *
 */

#define CAT_QUOTE_DIR "/save/books/cat/"

inherit NPC_OBJ;

object owner;
int max_num;
object prev_env;

void give_advice();
void check_env();

void setup() {
    set_name( "cat" );
    set_short( (: ({ "fuzzy", "warm", "hairy" })[random(3)] +" cat" :) );
    set_long("The nice warm fuzzy hairy cat sits on the ground looking "
      "perfectly at home.\n");
    add_adjective( ({ "fuzzy", "warm", "hairy" }) );
    basic_setup("cat", 1+random(5), 0 );

    load_chat(30, ({
      1, "@purr",
        1, (: give_advice() :),
        1, "@meow ?",
        1, (: check_env() :),
        }));
    
    add_respond_to_with(({ ({ "@stroke", "@pat" }), query_name() }),
                        (: give_advice() :) );
    max_num = unguarded((: sizeof(get_dir(CAT_QUOTE_DIR+"*"))-2 :) );
    
} /* setup() */

void give_advice() {
    int num;
    string str;
   
    num = random(max_num);
    str = unguarded( (: read_file(CAT_QUOTE_DIR + $(num)) :) );
    if (str) {
        call_out("do_command", 1, "emote gives you some advice: \n"+str);
    }
} /* give_advice() */

void set_owner( object thing ) {
    owner = thing;
    this_object()->add_extra_look( this_object() );
} /* set_owner() */

void init() {
    ::init();
    this_player()->add_command("eat", this_object());
} /* init() */

int attack_by(object ob) {
    ob->stop_fight(this_object());
} /* attack_by() */

int attack_ob(object ob) {
    ob->stop_fight(this_object());
    tell_object(ob, "The cat ignores you completely and washes it's nose.\n");
} /* attack_by() */

void event_exit(object ob, string mess, object to) {
  if (!objectp(owner)) return ;
  if (ob == owner) 
    call_out("check_env", 0);
  
} /* event_exit() */

void event_dest_me(object ob) {
    call_out("check_env", 0);
} /* check_env() */

void check_env() {
  if (!owner) {
    command("cry");
    call_out("dest_me", 2);
    return ;
  }
  if ( environment() != environment( owner ) ) {
    move( environment( owner ),
          "$N slink$s in.", "$N casually disappear$s into the ground." );
    command( "follow "+ owner->query_name() );
  }
} /* check_env() */

object query_owner() { return owner; }

void dest_me() {
  if ( environment() )
    all_inventory()->move( environment() );
  ::dest_me();
} /* dest_me() */

string extra_look() { 
  return capitalize(query_pronoun())+" is studiously ignoring "+
    owner->the_short() +".\n";
}
