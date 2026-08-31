/* Ethereal Cashimor: Changed weight of robe: gave errors 1 -> 0 */
/********************************************************************
*                                                                   *
*             This is the tuning-header of the mage guild.          *
*                                                                   *
*            !!! PLEASE !!! comment ALL change exactly !!!          *
*                                                          Llort    *
********************************************************************/

/**************************** COMMENTS ******************************
  Date of creation: Sun Aug 23, 1992

************************* END OF COMMENTS **************************/

/* Standard AC of the Mage-robe */
#define		STD_AC_OF_ROBE		1 

/* Weight of the Mage-robe */
#define         WEIGHT_OF_ROBE          0

/* Armourtype of the Mage-robe */
#define         TYPE_OF_ROBE            "guild" /* 170992 Cashimor */

/* Time how often the SP for invis are decremented. */
#define		CHK_SP_FOR_INVIS	60	/* given in secs. */

/* This value determines if the player get a 'wakeup' command. */
#define		WAKEUP_FOR_PLAYERS	0	/* 0=no or 1=yes */

/* what intoxination is allowed for casting the spells? */
#define 	ALLOWED_INTOXINATION    0	/* int value */

/* Time how long the shield spell is up. */
#define		TIME_SHIELD		180	/* in secs */

/* Time how long the normal light will last. */
#define 	TIME_LIGHT		1200	/* in secs */

/* Time how long the 'lasting light' will last */
#define 	TIME_LLIGHT		100000  	/* in secs */

/* Time how long a player will stay in the mage-prison. */ 
#define 	JAIL_TIME		300	/* in secs */

/* Time * Level is the time for the fireshield */
#define 	FIRESHIELD_TIME         60      /* in secs */

/* counter for the stoneskin spell */
#define         STONESKIN_TIME          5

/* This the formula how the fizzel is calculated.  (lvl..spell-level)
   The result is the chance for a spell to work in percent. */
#define 	CHK_FIZZEL		((TPWI+TPL)*50/lvl-20)  

/* This are the spell-levels and spell-costs of the mage spells.
   spell-cost = -1 means .... MAXSP 
   For meaning of the spell-level look at the above define. */
#define		STAFF_LVL		1
#define		STAFF_SP		-1
#define		POSE_LVL		15	/* special */
#define		POSE_SP			50
#define		PRISON_LVL		17	
#define		PRISON_SP		100
#define		EYE_LVL			6
#define		EYE_SP			20
#define		HOLD_LVL		5
#define		HOLD_SP			20
#define		MEDITATE_LVL		2
#define		MEDITATE_SP		1
#define		DETECT_LVL		13
#define		DETECT_SP		30
#define		MELT_LVL		14
#define		MELT_SP			50
#define		ILLUSION_LVL 		9
#define		ILLUSION_SP		50
#define 	MISSILE_LVL		5
#define		MISSILE_SP		15
#define 	COLORSPRAY_LVL 		1
#define 	COLORSPRAY_SP		-1 /* (TPWI/2+1) */
#define		CRUSH_LVL		20
#define		CRUSH_SP		50
#define         DISINT_LVL		25
#define         DISINT_SP		300
#define 	BLAST_LVL		20
#define		BLAST_SP		75
#define 	FIREBALL_LVL		10
#define		FIREBALL_SP		20
#define 	FIRESHIELD_LVL		10
#define		FIRESHIELD_SP		50
#define         STONESKIN_LVL            1
#define         STONESKIN_SP            40
#define		LOCATE_LVL		12
#define 	LOCATE_SP		40
#define		TAME_LVL		11
#define		TAME_SP			80
#define		GATE_LVL		20
#define		GATE_SP			100
#define		FEAR_LVL		3
#define		FEAR_SP			30
#define 	INVISIBLE_LVL		15
#define		INVISIBLE_SP		20	/* per time period */
#define		VISIBLE_LVL		1
#define 	VISIBLE_SP		0
#define		FEEBLE_LVL		3
#define 	FEEBLE_SP		30
#define		GOGUILD_LVL		2
#define		GOGUILD_SP		10
#define 	TELEPORT_LVL		20
#define		TELEPORT_SP		50
#define		MEMORIZE_LVL		20
#define		MEMORIZE_SP		10
#define		GOBACK_LVL		3
#define		GOBACK_SP		20
#define		MAGE_LVL		1
#define		MAGE_SP			5
#define		LIGHT_LVL		1
#define		LIGHT_SP		10
#define 	KNOCK_LVL		7
#define		KNOCK_SP		40
#define		SHIELD_LVL		2
#define 	SHIELD_SP		20
#define		STOPLIGHT_LVL		1
#define		STOPLIGHT_SP		0
#define		LASTLIGHT_LVL		5
#define		LASTLIGHT_SP		30

/* here follow the damages of the attack spells. */
#define 	BLAST_DAM		(40+random(30))
#define         CRUSH_DAM               (60+random(45))  /*lowered from 50+75*/
#define		FIREBALL_DAM		(20+random(10))
#define		MISSILE_DAM		(15+random(10))
#define         DISINT_DAM  		(200+random(500))
#define 	COLORSPRAY_DAM		(random(TPWI)+random(TPIN)+2)

/* specials for the meditate spell */
#define		HEAL_TIME		2	/* time btw heals in sec */
#define		HEAL_RATE		5	/* amount of hp/sp healed */
#define		MED_TIME		((tim-1)*60+random(120)+1) /* secs */

/* specials for the staff spell */
#define 	STAFF_TIME		1	/* time btw heals in
						   heart-beats          */
#define 	STAFF_RATE		3	/* hp/sp per heal */

/* specials for the hold spell (in heart-beats) */
#define		HOLD_PLAYER		random((TPIN+1)*1/ob->query_level())
/* Random added in by Colossus 041294 */
#define		HOLD_NPC		random((TPIN+1)*10)/(ob->query_level()+1)+4

/* special for the illusion spell in secs */
#define		ILLU_TIME		((random(TPL/2)+TPL/2)*60)

/* special for the melt spell (chance to melt the weapon) */
#define		MELT_IT		((random(TPL)+10) > wep[i]->weapon_class())

/* special for the prison spell in percent (0-99) */
#define		PRISON_CHANCE	(50+(TPL-prisoner->query_level())*5)

/* AC of the shield spell */
#define		SHIELD_AC	((TPL/10) + 1) /* Way too with TPL/3 + 10

/* WC of the cloned staff */
#define 	STAFF_WC	0

/* chance to knock a door in percent (1-100) */
#define		KNOCK_CHANCE	(TPL * 100 / MS->query_max_stats())

/* chance to feeble in percent (1-100) */
#define		FEEBLE_CHANCE	((TPL*2-wat->query_level())*100/(MS->query_max_stats()*2))

/* chance to tame in percent (1-100) */
#define		TAME_CHANCE	(TPL-ob->query_level()+50)

