#define THRUST_COST 	30
/* Spell formulae */
/* Added extra damage and minused costs for higher levels */

#define THRUST_LEVEL	10
#define THRUST_DAM      30+(TPD+TPW)/5

#define DEATH_COST	50+(TPI/5)
#define DEATH_LEVEL	13
#define DEATH_DAM       (85+(random(TPI/10)))

#define CHARIOT_COST	10
#define CHARIOT_LEVEL	4

#define CLOAK_COST	15
#define CLOAK_LEVEL	2

#define STUDY_COST	5
#define STUDY_LEVEL	1

#define TIME_COST	25
#define TIME_LEVEL	10
#define TIME_DAM	10+(TPW+TPI)/5
#define TIME_DUR	random(TPL+(TPW+TPI)/25)

#define GLANCE_COST	3
#define GLANCE_LEVEL	1

#define FASTTALK_COST	15
#define FASTTALK_LEVEL	10

#define APPRAISE_COST	10
#define APPRAISE_LEVEL	7

#define HL TP->query_property("higher_lev")+1
#define DAM(x) (x + (HL*x)/130)
#define COST(x) (x - (HL*x)/190)
