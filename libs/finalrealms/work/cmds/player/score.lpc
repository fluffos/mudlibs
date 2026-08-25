// score cmd from player.c, now external. Morgoth 2/Mar/95
// Fr'ized by Baldrick oct '95.

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;
}

string query_usage()
{
	return "score [verbose|brief] [stats]";
}

string query_short_help()
{
	return "Shows various player statistics.";
}


protected int cmd (string str, object me)
{
	int age, i;
	string *st;

	if (str)
		st = explode(str, " ");
	else
		st = ({ });

        if (me->query_dead())
          {
	  write("You are just a disembodied spirit, you do not need to know"
                " this.\n");
          return 0;
          }

	if ((me->query_verbose() && (member_array("brief", st) == -1)) ||
		(member_array("verbose", st) != -1))
	{
		if (member_array("stats", st) != -1)
		{
      			write("Here are some arbitrary numbers for you to "+
				"look at:\n");
			printf("%-#*s\n", me->query_cols(),
			"Strength     : "+stat_string(me->query_str())+
			"\nIntelligence : "+me->query_int()+
			"\nDexterity    : "+me->query_dex()+
			"\nConstitution : "+me->query_con()+
			"\nWisdom       : "+me->query_wis()+
			"\n");
			return 1;
		}
		write("You are level "+me->query_level()+
                      " and have "+me->query_hp()+
			" ("+me->query_max_hp()+") hit points, "+
			me->query_gp()+" ("+me->query_max_gp()+
			") guild points and "+me->query_social_points()+
			" ("+me->query_max_social_points()+") social "+
			"points.\n");
		write("Your current experience is "+me->query_xp()+
			".\n");
		write("You are ");
		age = me->query_time_on();
		age = -age;
		if (age > 86400)
			printf("%d days, ", age/86400);
		if (age > 3600)
			printf("%d hours, ", (age/3600)%24);
		if (age > 60)
			printf("%d minutes and ", (age/60)%60);
		printf("%d seconds old.\n", age % 60);
		if (me->query_wimpy())
			write("Wimpy set to "+me->query_wimpy()+"%\n");
		else
			write("You are in brave mode.\n");
		return 1;
	}
	else
		if (member_array("stats", st) != -1)
		{
			write("Here are some arbitrary numbers for you to "+
				"look at:\n");
			printf("%-#*s\n", me->query_cols(), 
			"Strength     : "+stat_string(me->query_str())+
			"\nIntelligence : "+me->query_int()+
			"\nDexterity    : "+me->query_dex()+
			"\nConstitution : "+me->query_con()+
			"\nWisdom       : "+me->query_wis()+
				"\n");
			return 1;
		}
	write("Hp: "+me->query_hp()+"("+me->query_max_hp()+")"+
		"  Gp: "+me->query_gp()+"("+me->query_max_gp()+")"+
		"  Xp: "+me->query_xp()+"  Socp: "+
		me->query_social_points()+"\n");
	return 1;
}
