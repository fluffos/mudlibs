#define Targeted       1
#define NoTarget       2
#define NoArgs         3
#define ForceAdverb    4
#define ExtraAdverbs   5
#define Locations      6
#define ForceLocation  7
#define Preposition    8
#define DisableAnd     9
 
#define SaveFile "/daemon/soul/soul"
#define FallBackFile "/daemon/soul/default.lpc"
#define SOUL_ADVERBS "/daemon/adverbs"

/* FluffOS PORT NOTE: HelpPage used to be defined right here as a real
 * global-variable initializer -- harmless textually, but daemon/soul.lpc
 * #include's this header BEFORE its own `inherit SOUL_ADVERBS;` line
 * (SOUL_ADVERBS is itself defined a few lines up in this same header),
 * so the variable definition landed ahead of the inherit in the
 * expanded token stream. This driver hard-errors on that ordering
 * ("Illegal to inherit after defining global variables") where the
 * CD/MudOS driver this originally shipped for evidently didn't. Moved
 * the actual variable to daemon/soul.lpc (its only reader) after its
 * inherit line instead of editing this header's own macro-only
 * contents any single other includer might also pull in.
 */
