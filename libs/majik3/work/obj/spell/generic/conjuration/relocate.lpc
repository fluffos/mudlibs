/* Coder: Doughnut */

inherit SPELL;

create_spell()
{
	set_level (3);
	set_casting_time (3);
	set_components (1, 0, "candle");
}

perform_spell (object caster, string target_name, int result)
{
        object target,abcs;
	if (!target_name)
	{
		emote ("Suddenly a dry wind starts to blow here. In a moment the place is charged"
			+" with energy. The winds of magic swirl around $n, making it hard to distinguish"
			+" any shapes in the cloud of energy. The cloud of magic starts to expand, and in"
			+" the verge of exploding, the cloud dissipates quickly.", THIS, THIS, ENV(THIS));
		return 0;
	}

	target = find_player (target_name);

	if (!caster->query_security() && target->query_security())
	{
		emote ("The lights in the room go out. A gush of raw energy {sprout} from $s"
			+" fingertips. Suddenly a ball of black energy engulfs $n and screaming"
			+" hysterically $n is drawn into a swirling pool of black energy.", THIS, THIS, ENV(THIS));
		EXPLORE_D->teleport(THIS);
		return 0;
	}			
	
	abcs = environment(target);
		
	if (!(abcs==environment(caster)))	
	{
		emote ("Suddenly a dry wind starts to blow here. In a moment the place is charged"
			+" with energy. The winds of magic swirl around $n, making it hard to distinguish"
			+" any shapes in the cloud of energy. The cloud of magic starts to expand, and with"
			+" a terrible sound it explodes, leaving no trace of $n behind.", THIS, THIS, ENV(THIS));
		emote ("A high pitched noise starts to sound all around $N. Suddenly there is a loud"
			+" bang and the rifts of reality open. Blackness takes over the place and huge energic"
			+" sparks fly all over. Little by little, an opening in the fabric starts to form, and after"
			+" a while, the opening is big enough for someone to step through. Slowly a blurry character"
			+" steps out from the opening, and in moments transforms into a figure resembling $n.", THIS, target, ENV(target));
	        caster->move (file_name(ENV(target)));    		
		caster->force_us("blook");
	}
	else
	{
		emote ("In the last second $n {stop} the spell, and {eye} everyone suspiciously.", THIS, THIS, ENV(THIS));
   	}
	return 1;
}

query_help()
{
	return "Teleports mortal player to target player's current location. Relocating to immortals is rumoured to have serious consequences.";
}
		