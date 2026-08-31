#ifndef __COMBAT_H__
#define __COMBAT_H__

void combat_round();
int start_attack(object victim);
varargs void swing(int count, int multi);
int next_round();
public int can_strike(object enemy, mixed weapon);
private fail_strike(object enemy, object weapon);
public varargs void strike_enemy(object enemy, object weapon, int off_hand);
mapping query_weapon_info(object weapon);
int attacking(object victim);
varargs int stop_attack(object victim, int seen);
void stop_all_attacks();
int in_combat();
int seen_enemy(object victim);
int current_enemy(object victim);
mapping current_enemies();
object highest_threat();
object lowest_threat();
object highest_seen_threat();
object lowest_seen_threat();
void clean_up_enemies();
varargs int valid_enemy(object enemy);
void clean_up_seen_enemies();
int valid_seen_enemy(object enemy);
float add_threat(object enemy, float amount);
float add_seen_threat(object enemy, float amount);
float add_attack_speed(float amount);
float set_attack_speed(float speed);
float query_attack_speed();
void set_defence(mapping def);
void add_defence(string type, float amount);
mapping query_defence();
float query_defence_amount(string type);
mapping adjust_protection();
float query_ac();
float query_spell_ac();
object last_damaged_by();
object set_last_damaged_by(object ob);
object killed_by();
object set_killed_by(object ob);
float set_damage(float x);
float query_damage();
string set_weapon_name(string str);
string query_weapon_name();
string set_weapon_type(string str);
string query_weapon_type();
mixed prevent_combat(object victim);
void set_no_combat(int x);
int query_no_combat();

#endif // __COMBAT_H__
