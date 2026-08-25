/* header file -- AD&D, 2nd Edition (c) Ability Scores */
#ifndef ABILITY_H                  /* for indempotency of header file */
#define ABILITY_H

  /* ability score indexes */
#define STR 0
#define DEX 1
#define CON 2
#define INT 3
#define WIS 4
#define CHA 5
  /* number of ability scores */
#define NUM_AS 6

/* Description of Function Parameters                                */
/*                                                                   */
/*   ab (ability) is one of the macros STR, DEX, CON, INT, WIS, or   */
/*   CHA.  The integer values 0 through 5 can also be used                     
                                       */
/*                                                                   */
/*   sc (score) is a value in the range [1, 25] for DEX, CON, INT,   */
/*   WIS, or CHA.  sc is a value in the range of [-100, -1] AND      */
/*   [1, 25] for STR.                                                */
/*   NOTE THAT THE RANGE IS DIFFERENT FOR STRENGTH TO ACCOUNT FOR    */
/*   THE EXCEPTIONAL STRENGTH OF WARRIORS.                           */
/*                                                                   */
/*   adj (adjustment) is any integer value.  A positive value will   */
/*   raise the score and a negative value will lower the score.      */
/*   The score, however, will not exceed the range given for the     */
/*   parameter, sc, above.                                           */
/*   NOTE FOR EXCEPTIONAL STR: an adjustment of 1 will raise         */
/*   exceptional str to a score of 19 and an adjustment of -1 will   */
/*   lower it to 18.  Once the actual exceptional strength score is  */
/*   adjusted, it cannot be regained (unless stored elsewhere).      */

  /* function declarations for ability scores */
int query_real_stat(int ab);
int set_real_stat(int ab, int sc);
int adjust_real_stat(int ab, int adj);

int query_stat(int ab);
int set_stat(int ab, int sc);  
int adjust_stat(int ab, int adj);

int reset_stat(int ab);
void reset_all_stats();

string query_ability_name(int ab);
string query_real_stat_string(int ab);
string query_stat_string(int ab);

  /* function declarations for game effects */
int to_hit_prob();
int damage_adj();
int wgt_allow();
int max_press();
int open_normal_doors();
int open_special_doors();
int bnd_brs_lft_gts();

int surprise_adj();
int missle_att_adj();
int defensive_adj();

int hit_point_adj(int warrior);
int system_shock();
int resurrect_survival();
int poison_save();
int regeneration();

int num_languages();
int spell_level();
int learn_spell();
int max_spells();
int illusion_immunity();

int magical_defense_adj();
int spell_fail();
void bonus_spells(int *spell_tbl);
string *spell_immunity();

int num_henchmen();
int loyalty_base();
int reaction_adj();

  /* query functions return nonzero if check succeeded */
int query_open_doors(int special);
int query_bblg();
int query_system_shock();
int query_resurrect_survival();
int query_learn_spell();
int query_illusion_immunity(int spell_level);
int query_spell_fail();
int query_spell_immunity(string spell_name);

#endif
