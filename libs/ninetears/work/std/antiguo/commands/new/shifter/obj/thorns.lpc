/* Shapeshifter Vine object, to prevent movement
 *  And cause minor damage.  Modified from Flug's Thorn
 *  Hedge code by Timion, 02 NOV 96.
 */
#include "/std/spells/cleric/tweaks.h"
inherit "/std/object";

#define THORN_DAMAGE -2
int hb;
object mycaster;
int mycount;

void do_damage(object ob);

int dispell_me()
{
    tell_room(ETO,"The vines writhe "
      "and seem to be absorbed into "+mycaster->query_cap_name()+"\n");
    this_object()->dest_me();
    return 1;
}

void attack_by(object ob)
{
    ob->stop_fight(this_object());
    tell_room(ETO,(string)ob->query_cap_name()+
      " hacks ineffectively at the vines.\n");
    mycaster->attack_by(ob);
    do_damage(ob);
}

int do_cut(string str)
{
    if(random(10))
    {
	tell_object(TP,"You are blocked by vines!\n");
	tell_room(ETO,(string)TP->query_cap_name()+" is prevented from "
	  "leaving by the vines.\n",({ TP }));
	do_damage(this_player());
	return 1;
    }
    return 0;
}

void init()
{
    ::init();
    reset_get();
    set_heart_beat(1);
    add_action("do_cut","s*outh");
    add_action("do_cut","n*orth");
    add_action("do_cut","e*ast");
    add_action("do_cut","u*p");
    add_action("do_cut","d*own");
    add_action("do_cut","w*est");
    add_action("do_cut","se");
    add_action("do_cut","sw");
    add_action("do_cut","ne");
    add_action("do_cut","nw");
    add_action("do_cut","southwest");
    add_action("do_cut","southeast");
    add_action("do_cut","northwest");
    add_action("do_cut","northeast");
    add_action("do_cut","sn*eak");
}

void do_damage(object ob)
{
    int i;

    if ( ob == this_object() || ob->query_dead() || !living(ob) ||
      (IMMORTLOCK && ob->query_creator()) )
	return;

    if (ob == mycaster) 
	return;

    tell_object(ob,"The spiky thorns stick into your flesh "
      "as you struggle against the vines.\n");
    ob->adjust_hp(THORN_DAMAGE);
    return;
}

void setup()
{
    set_name("");
    set_short("");
    add_alias("thorns");
    set_long("\n A mass of thorn covered vines surrounds the area."
      "\n");
}

void heart_beat()
{
    object *olist;
    object ob;
    int i;

    if(!mycaster || (mycaster->query_vine_shadow() != 1))
    {
	dispell_me();
	return;
    } 

    olist = all_inventory(ETO);

    for(i = 0; i < sizeof(olist); i++)
    {
	do_damage(olist[i]);
    }
}     

void begin_vines(object ob, object loc)
{
    mycaster=ob;
    this_object()->move(loc);
    tell_room(environment(mycaster), "Vines spring forth from "
      ""+mycaster->query_cap_name()+" as "+mycaster->query_pronoun()+" "
      "explodes into a vine!\n");
    return;
}
