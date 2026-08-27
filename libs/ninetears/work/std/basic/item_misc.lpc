int in_use;

/* handles all the cutsey in-use testing */
#define HANDLER "/obj/handlers/item_handler"

// Move hack so that wearables/holdables will leave the wear/hold
// arrays of living creatures.
// SET_IN_USE retocados - Tyrael
int move(mixed dest, mixed messout, mixed messin) 
{
    object ob;
    int i;
    int UNUSED_IT = 0;  /* Hamlet's nastiness */

    /* Next line is Hamlet's and it's ugly, but needed */
    if(this_object()->query_in_use()) 
    {
	this_object()->set_in_use(0, ETO);
	UNUSED_IT = 1;
    }

    ob = environment(this_object());
    i = (int)::move(dest, messout, messin);

    if (!i && UNUSED_IT && objectp(ob) && living(ob))
    {
	if (this_object()->query_holdable())  /* Hamlet fixed me */
	    ob->unhold_ob(this_object());
	else if (this_object()->query_wearable()) /* hamlet fixed me */
	    ob->unwear_ob(this_object());
    }	
    if(i && UNUSED_IT)  this_object()->set_in_use(1, ob); /* Hamlet */
    return i;
}

/* Added april '95 by Baldrick, does the same as the move, just for dest_me
 * Not sure if it will work tho 
 */
void dest_me()
{
    object ob;

    ob = environment(this_object());

    if (in_use && objectp(ob) && living(ob))
	if (this_object()->query_holdable()) /* Hamlet fixed me */
	    ob->unhold_ob(this_object());
	else if (this_object()->query_wearable()) /* Hamlet */
	    ob->unwear_ob(this_object());
    ::dest_me();
} /* void dest_me */

// Major hack, Taniwha 1996, most of it is in HANDLER
// To clean up adding reistances on magic stuff, stat mods etc
int set_in_use(int i, object amo)
{
    in_use = i;
// Taniwha, see if there is any cute stuff
   if( !(sizeof(map_prop) || sizeof(timed_prop) || sizeof(query_static_properties()))) return i;
   catch(in_use = HANDLER->local_in_use(i,ETO,TO));
   //tell_object(TP, "SIU called from "+TO->query_short()+" PO: "+file_name(previous_object())+" return "+in_use+"\n");
   // Se puede evitar el bug de q salga 2 veces lo d q no lo puedes emp
   // si hacemos q local_in_use dewelva tb el mensaje para un notify_fail
   // el problema es q iwal incurrimos en lo de darle el mensaje a
   // quien no debemos! Como cuando el npc se ekipa al entrar nosotros.
   return in_use;
}

