#ifndef SKILLS_H
#define SKILLS_H

void	create();
mapping	query_skills();
void	set_skills(mapping sk);
void	set_skill(string name, float val);
int	add_skill(string name, float value);
float	query_skill(string name);
float	add_skill_val(string name, float val);
mixed	use_skill(string name, float fac, mixed *data);
int	add_skill_hook(string name, closure cl);
void	set_skill_lev(string name, int lev);
int	query_skill_lev(string name);
mixed	query_skill_hook(string name, closure cl);
int	remove_skill_hook(string name, closure cl);

#endif /* SKILLS_H */
