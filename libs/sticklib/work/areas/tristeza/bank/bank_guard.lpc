#include <npc.h>
#include <areas.h>
#include <mud_name.h>

#define GUARD_ROOM "bank/bank_back"
#define BANK       "bank/bank"

object note; /* The note with the code to the vault */
int code;

void
reset_monster()
{
    // We change the code at every reset
    code=random(1000); /* 0-999 */
    if ( note=clone_object(AREA_TRISTEZA+"bank/bank_note"))
	note->set_code(code);
    if ( strstr(object_name(environment()),GUARD_ROOM)==-1)
	move_player("X#"+AREA_TRISTEZA+GUARD_ROOM);
    (AREA_TRISTEZA+GUARD_ROOM)->set_code(code);
    // Players have four seconds time to kill this guard when a reset comes,
    // before he goes to Teller 
    call_out("round",2);
}

void
create_monster()
{
    set_name("guard");
    set_id("bank guard");
    set_gender(G_MALE);
    set_short("Guard of the First Mudional Bank of "+MUD_NAME+"");
    set_level(19);
    set_hp(600);
    set(NPC_SET_PK_FLAG, 1);
    set_long("He is a very big man with long powerful arms. He has those special guard-like features that are so common with guards.");
    set_ac(20,1);
    set_wc(35,1);
    set_spell_chance(40);
    set_spell_mess2("Guard points at you with his hand and bolts of burning flame strike you.");
    set_spell_mess1("Guard extends his arm and red flames strike out beside you.");
    set_spell_dam(35);
    set_alignment(AL_NEUTRAL);
}

void
round() 
{
    remove_call_out("round");
    if( strstr(object_name(environment()),GUARD_ROOM)!=-1) 
    {
	move_player("through the southern wall#"+AREA_TRISTEZA+BANK);
	call_out("round2",2);
    }
    else 
    {
	move_player("X#"+AREA_TRISTEZA+GUARD_ROOM);
	call_out("round",1);
    }
}

void
round2()
{
    object teller,old_note;
    remove_call_out("round2");
    if( strstr(object_name(environment()),BANK)!=-1)
    {
	teller=present("teller",environment());
	if(!teller)
	{
	    environment()->tell_here("Guard sighs.");
	    if(note && present("note",this_object()))
		destruct(note);
	    move_player("through the northern wall#"+AREA_TRISTEZA+GUARD_ROOM);
	}
	else
	{
	    old_note=present("note",teller);
	    if(old_note)
	    {
		destruct(old_note);
		environment()->tell_here(
		  "Teller gives a note to Guard who crumples it up.");
	    }
	    move_object(note,teller);
	    environment()->tell_here("Guard gives a note to Teller.");
	    move_player("through the northern wall#"+AREA_TRISTEZA+GUARD_ROOM);
	}
    }
    else
    {
	move_player("X#"+AREA_TRISTEZA+GUARD_ROOM);
	call_out("round2",1);
    }
}
