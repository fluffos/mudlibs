// Gototh, 13/04/99
/**
 * This effect has a classification of "body.hairstyle".  It adds
 * a string of text to the player's description detailing what sort
 * of hair style they have.  The first parameter should be an array
 * of strings describing the hair style.  The first member of the
 * array should be what the hair style looks like the first week,
 * the second member what it looks like the second week, etc.
 * The second parameter is the age of the player when the hair 
 * style was added (use query_time_on() * -1). 
 * <p>
 * @classification body.hairstyle
 * @see help::effects
 */
#include <effect.h>

/**
 * @ignore yes
 */
string query_classification()
{
  return "body.hairstyle";
} /* query_classification() */

/**
 * @ignore yes
 */
int survive_death()
{
  return 0;
} /* survive_death() */

/**
 * @ignore yes
 */
int query_indefinite()
{
  return 1;
} /* query_indefinite() */

/**
 * @ingnore yes
 */
mixed *beginning(object player, mixed *hairstyle)
{
  player->add_extra_look(this_object());
  return hairstyle;
} /* beginning() */

/**
 * @ignore yes
 */
mixed *restart(object player, mixed *arg)
{
  player->add_extra_look(this_object());
  return arg;
} /* restart() */

/**
 * @ignore yes
 */
mixed *merge_effect( object player, mixed *arg1, mixed *arg2)
{
  return arg2;
} /* merge_effect() */

/**
 * @ignore yes
 */
void end(object player)
{
  player->remove_extra_look(this_object());
} /* end() */

/**
 * @ignore yes
 */
string extra_look(object player)
{
  string *style;
  int h_time, weeks_passed;  
  style = player->arg_of(player->effects_matching("body.hairstyle")[0])[0];
  h_time = player->arg_of(player->effects_matching("body.hairstyle")[0])[1];
  weeks_passed = ((player->query_time_on() * -1) - h_time) / 
    ((24 * 60 * 60 * 7) / 3) * -1;
  if(weeks_passed > sizeof(style) - 1)
  {
    player->submit_ee(0, 0, EE_REMOVE);
    return "";
  }
  return "$C$"+player->query_pronoun()+" has "+style[weeks_passed]+".\n";
} /* extra_look() */
