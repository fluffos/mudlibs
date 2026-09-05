/*
 * <perceivable.h>
 * macros for the result value of simul_efun perceivable()
 */

/* see */
#define PERCEIVE_VISUAL    0x01
#define PERCEIVE_SIGHT     PERCEIVE_VISUAL
#define PERCEIVE_SEE       PERCEIVE_VISUAL

/* hear */
#define PERCEIVE_AURAL     0x02
#define PERCEIVE_HEAR      PERCEIVE_AURAL

/* feel */
#define PERCEIVE_TACTILE   0x04
#define PERCEIVE_FEEL      PERCEIVE_TACTILE

/* smell */
#define PERCEIVE_OLFACTORY 0x08
#define PERCEIVE_SMELL     PERCEIVE_OLFACTORY

/* taste */
#define PERCEIVE_GUSTATORY 0x10
#define PERCEIVE_TASTE     PERCEIVE_GUSTATORY

/* balance (handled in the inner ear by humans) */
#define PERCEIVE_BALANCE   0x20

/* supernatural */
#define PERCEIVE_SUPERNATURAL 0x40

/* magic */
#define PERCEIVE_MAGIC     0x80

/* all */
#define PERCEIVE_ALL       0xff
