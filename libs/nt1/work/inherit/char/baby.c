#define BABY_DIR  "/data/baby/"
#include <ansi.h>
inherit NPC;
inherit F_SAVE;
static int last_age_set;

int query_current_neili_limit();
int query_neili_limit();
int query_current_jingli_limit();
int query_jingli_limit();
int query_potential_limit();
int query_experience_limit();

void update_age()
{
    	if (! environment()) return;

        if (environment()->is_chat_room())
                last_age_set = time(); 

    	if (! last_age_set ) last_age_set = time();
    	add("mud_age", time() - last_age_set);
    	last_age_set = time();
    	set("age", ((int)query("mud_age") / 86400));
}

string query_save_file()
{
     	if (! stringp(query("parents/mother"))) return 0;

     	return sprintf(BABY_DIR"%s", query("parents/mother"));
}

int save()
{
    	int res;
    	update_age();
    	res = ::save();
    	return res;
}

#define MAX_NEILI_IMPROVE       query("con")
#define MAX_JINGLI_IMPROVE      query("con")

int query_neili_limit()
{
        string *skill_names;
        mapping skills;
        int neili_limit;
        int base_lvl, lvl;
        int tmp;
        int i;
        string fam;

        skills = this_object()->query_skills();
        if (! mapp(skills))
                return 0;

        skill_names = keys(skills);

        base_lvl = ((int) skills["force"]) / 2; 
        neili_limit = base_lvl * 10;
        for (i = 0; i < sizeof(skill_names); i++)
        {
                if (file_size(SKILL_D(skill_names[i]) + ".c") == -1)
                {
                        // No such skill
                        continue;
                }

                if (! SKILL_D(skill_names[i])->valid_enable("force"))
                        continue;

                lvl = (int) skills[skill_names[i]];
                tmp = (base_lvl + lvl) * 10;
                tmp += (int) SKILL_D(skill_names[i])->query_neili_improve(this_object());
                if (tmp > neili_limit) neili_limit = tmp;
        }

        neili_limit += neili_limit / 100 * query("improve/neili");
        if (query("breakup"))
                neili_limit += neili_limit / 10 * 3;

        if (query("special_skill/mystery"))
                neili_limit += query("con") * 15;

        fam = query("family/family_name");
        if (query("class") == "bonze" &&
            (fam == "雪山寺" || fam == "少林派" || fam == "峨嵋派" || fam == "血刀门"))
                neili_limit += 500;

        return neili_limit;
}

int query_current_neili_limit()
{
        int neili;
        string force;
        string fam;

        force = query_skill_mapped("force");
        neili = (int)query_skill("force", 1) / 2 * 10;
        if (stringp(force) && force != "")
        {
                neili += (int)query_skill(force, 1) * 10;
                neili += SKILL_D(force)->query_neili_improve(this_object());
        }    

        neili += neili / 100 * query("improve/neili");
        if (query("breakup"))
                neili += neili / 10 * 3;

        if (query("special_skill/mystery"))
                neili += query("con") * 15;

        fam = query("family/family_name");
        if (query("class") == "bonze" &&
            (fam == "雪山寺" || fam == "少林派" || fam == "峨嵋派" || fam == "血刀门"))
                neili += 500;

        return neili;
}

int query_jingli_limit()
{
        int limit;

        limit = ((int)query("magic_points") / 30) + query("int") * 30;
        limit += limit / 100 * query("improve/jingli");
        if (query("animaout"))
                limit += limit / 10 * 4;
        return limit;
}

int query_current_jingli_limit()
{
        return query_jingli_limit();
}

int query_potential_limit()
{
	int p;

        /*
	if (ultrap(this_object()))
                p = 1000000;
	else
                p = query_int() / 2 * 100 + 1000;
        return (int)query("learned_points") + p;
        */
        p = (int)query("combat_exp") / 5;
        p += (query_int() / 100) * p;
        if (ultrap(this_object()))
                p += 1000000;
        p += 5000;
        return (int)query("learned_points") + p;
}

int query_experience_limit()
{
	int p;

	if (ultrap(this_object()))
		p = 10000;
	else
        {
                p = query("score");
                if (p < 100)
                        p = p / 2;
                else
                if (p < 300)
                        p = p / 4 + 25;
                else
                if (p < 1100)
                        p = (p - 300) / 8 + 100;
                else
                        p = (p - 1100) / 16 + 200;
                if (p > 8000)
                        p = 8000;
        }

        return (int)query("learned_experience") + p;
}

int improve_potential(int n)
{
        int max;

        max = query_potential_limit() - query("potential");
        if (max <= 0) return 0;
        if (n > max) n = max;
        add("potential", n);
        return n;
}

int improve_experience(int n)
{
        int max;

        max = query_potential_limit() - query("experience");
        if (max <= 0) return 0;
        if (n > max) n = max;
        add("experience", n);
        return n;
}

int can_improve_neili()
{
        return query("improve/neili") < MAX_NEILI_IMPROVE;
}

int can_improve_jingli()
{
        return query("improve/jingli") < MAX_NEILI_IMPROVE;
}

int improve_neili(int n)
{
        int delta;

        if ((delta = query_neili_limit() - query("max_neili")) <= 0)
                return 0;

        if (n > delta) n = delta;
        add("max_neili", n);
        return n;
}

int improve_jingli(int n)
{
        int delta;

        if ((delta = query_jingli_limit() - query("max_jingli")) <= 0)
                return 0;

        if (n > delta) n = delta;
        add("max_jingli", n);
        return n;
}

void die()
{
        object killer, corpse;

        killer = this_object()->query_last_damage_from();

        if (objectp(killer))
        {
          	message("channel:rumor", HIM "【江湖谣言】某人：" + NOR + HIW +
                	"我看见" + this_object()->name() + "被" + killer->name() +
                	"杀害了，真是惨无人道啊！\n" NOR, users());
          
          	if (playerp(killer))
          		killer->apply_condition("killer", 1000 + killer->query_condition("killer"));
        } else
        	message("channel:rumor",HIM "【江湖谣言】某人：" + NOR + HIW +
                	"听说" + this_object()->name() +
                	"死了，死状惨不忍睹！\n" NOR, users());

        if (objectp(corpse = CHAR_D->make_corpse(this_object(), killer)))
        	corpse->move(environment());
        add("DIED", 1);
        if (userp(killer)) add("PKD", 1);
        add("shen", - (int)query("shen") / 10);
        add("combat_exp", - (int)query("combat_exp") / 50);

        if ((int)query("potential") > (int)query("learned_points"))
        	add("potential",
            	    	((int)query("learned_points") - (int)query("potential")) / 5);
        this_object()->skill_death_penalty();
        save();

        return :: die();
}

