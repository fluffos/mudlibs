#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <equipment.h>
#include <living.h>
#include <search.h>
#include <macros.h>

inherit "/std/weapon";

#define MODE_SHOOT 0
#define MODE_RELOAD 1
#define MODE_NOARROW 2

/*
*******************************************************************************
** Global variables
*******************************************************************************
*/

private int reload=0;
private int numshots=0;
private int degnum=15; // it is +-5!
private int degam=4;
private string arrowid;

private int bowmode=MODE_RELOAD;
private int bowloaded=0;
private object currentarrow = 0;

/*
*******************************************************************************
** Builtin Properties
*******************************************************************************
*/

int SetDegradeNumber( int num ) { return degnum = num; }
int QueryDegradeNumber() { return degnum; }

int SetDegradeAmount( int num ) { return degam = num; }
int QueryDegradeAmount() { return degam; }

string SetArrowId( string id ) { return arrowid = id; }
string QueryArrowId() { return arrowid; }

int SetReloadWeapon( int val ) { return reload = val; }
int QueryReloadWeapon() { return reload; }

/*
*******************************************************************************
** Custom message, damage and degrading
*******************************************************************************
*/

int QueryOldCombat() { return 0; }

mixed * NotifyHit( object attacker, object victim, mixed dam,
		   int val1, int val2 ) {
  mixed rval;
  object ob;
  string what, whats, how;

  if ( ( bowmode == MODE_SHOOT ) && ( ! objectp( currentarrow ) ) )
    bowmode == MODE_NOARROW;

  switch( bowmode ) {
  case MODE_SHOOT:
    if ( reload ) {
      rval = ({
	"You aim with your "+strip_a(QueryShort())+", shoot at "+NAME(victim),
	"  "+NAME(attacker)+" aims with "+HISHER(attacker)+" "+strip_a(QueryShort())+", shoots at you",
	NAME(attacker)+" aims with "+HISHER(attacker)+" "+strip_a(QueryShort())+", shoots at "+NAME(victim)
      });
    }
    else {
      rval = ({
	"You bend your "+strip_a(QueryShort())+", shoot at "+NAME(victim),
	"  "+NAME(attacker)+" bends "+HISHER(attacker)+" "+strip_a(QueryShort())+", shoots at you",
	NAME(attacker)+" bends "+HISHER(attacker)+" "+strip_a(QueryShort())+", shoots at "+NAME(victim)
      });
    }

    switch( dam["TOTAL"] ) {
    case 0: what = " miss "; whats = " misses "; how = "";
      break;
    case 1: what=" pierce ";whats=" pierces ";how=" lightly";
      break;
    case 2..3: what = " pierce "; whats = " pierces "; how = " barely";
      break;
    case 4..5: what = " pierce "; whats = " pierces "; how = "";
      break;
    case 6..10: what = " pierce "; whats = " pierces "; how = " painfully";
      break;
    case 11..20: what = " pierce "; whats = " pierces "; how = " very painfully";
      break;
    case 21..30: what = " pierce "; whats = " pierces ";
      how = " with a bone crushing sound";
      break;
    default:
      what=" pierce straight through ";
      whats=" pierces straight through ";how=", leaving a gaping hole";
    }
    if (dam) { what = " and"+what; whats = " and"+whats; }
    else { what = ", but"+what; whats = ", but"+whats; }

    rval[0]+=what+HIMHER(victim)+how+".\n";
    rval[1]+=whats+"you"+how+".\n";
    rval[2]+=whats+HIMHER(victim)+how+".\n";

    if ( dam["TOTAL"] ) {
      switch( random( 100 ) ) {
      case 0..50:
	if ( dam["TOTAL"] > 10 ) {
	  if ( ob = ({object})currentarrow->SplitOff(1) ) {
	    if ( ({int})ob->move( victim, M_SILENT ) != ME_OK ) {
	      ob->remove();
	      if ( ob ) destruct( ob );
	    }
	    break;
	  }

	  if ( currentarrow )
	    currentarrow->ReduceAmount(1);

	  break;
	}
	/* FALLTHROUGH */
      default:
	if ( ob = ({object})currentarrow->SplitOff(1) ) {
	  ob->SetShort( "broken "+strip_article(({string})ob->QueryShort()) );
	  if (arrowid) ob->RemoveId( arrowid );
	  ob->RemoveId( GENERIC_ARROW_ID );
	  ob->AddAdjective( "broken" );
	  ob->SetLong( "It is broken and cannot be used anymore.\n" );
	  ob->SetPluralLong( "They are broken and cannot be used anymore.\n" );
	  if ( ({int})ob->move( environment( attacker ), M_SILENT ) != ME_OK ) {
	    ob->remove();
	    if ( ob ) destruct( ob );
	  }
	  break;
	}

	if ( currentarrow )
	  currentarrow->ReduceAmout( 1 );
	break;
      }
    }
    else {
      switch( random( 100 ) ) {
      case 0..24:
	if ( ob = ({object})currentarrow->SplitOff(1) ) {
	  if ( ({int})ob->move( environment( attacker ), M_SILENT ) != ME_OK ) {
	    ob->remove();
	    if ( ob ) destruct( ob );
	  }
	  break;
	}
	/* FALLTHROUGH */
      default:
	if ( currentarrow )
	  currentarrow->ReduceAmount(1);
	break;
      }
    }
    break;
  case MODE_RELOAD:
    rval = ({
      "You bend and reload your "+strip_a(QueryShort())+".\n",
      "  "+NAME(attacker)+" bends and reloads "+HISHER(attacker)+" "+strip_a(QueryShort())+".\n",
      NAME(attacker)+" bends and reloads "+HISHER(attacker)+" "+strip_a(QueryShort())+".\n"
    });
    break;
  case MODE_NOARROW:
    rval = ({
      "You have no more projectiles to shoot with!\n",
      "",
      ""
    });
    break;
  default:
    rval = 0;
    break;
  }

  return rval;
}

int QueryDamage( object enemy ) {
  object arrow;

  if ( ! QueryWielded() )
    return 0; /* paranoia check */

  if ( reload ) {
    if ( bowloaded ) {
      bowmode = MODE_SHOOT;
      bowloaded = 0;
      /* FALLTHOUGH */
    }
    else {
      if (!(arrow=search( QueryWielded(),GENERIC_ARROW_ID,SEARCH_INV|SM_OBJECT))
       && !(arrowid && (arrow=search( QueryWielded(),arrowid,SEARCH_INV|SM_OBJECT)))
         ) {
	bowmode = MODE_NOARROW;
	return 0;
      }
      currentarrow = arrow;
      bowloaded = 1;
      bowmode = MODE_RELOAD;
      return 0;
    }
  }
  else {
    if (!(arrow=search( QueryWielded(),GENERIC_ARROW_ID,SEARCH_INV|SM_OBJECT))
     && !(arrowid && (arrow=search( QueryWielded(),arrowid,SEARCH_INV|SM_OBJECT)))
       ) {
      bowmode = MODE_NOARROW;
      return 0;
    }
    currentarrow = arrow;
    bowmode = MODE_SHOOT;
    /* FALLTHROUGH */
  }

  return ::QueryDamage( enemy );
}

public void DegradeWeapon ( mapping soaked, mapping damage, int success
			    , int target) {
  if ( ( bowmode == MODE_SHOOT ) && ( degnum ) ) {
    numshots ++;
    if ( ( numshots + 5 - random(10) ) > degnum ) {
      SetQuality(QueryQuality()-degam);
      numshots = 0;
    }
  }
}

/*
*******************************************************************************
** Initialize us
*******************************************************************************
*/

void create() {
  if (::create() ) return;

  SetStandard( WT_SPEAR, 12 ); /* There's now WT_BOW, so use a different piercing weapon */
  SetShort( "a bow" );
  SetLong("The bow has no distinguishing marks or features. However, it "
           "will shoot arrows just fine.\n");
  SetWeight(2000);
  SetValue(50);

  RemoveId("spear");
  AddId("bow");

  SetNumberHands(2);
}

