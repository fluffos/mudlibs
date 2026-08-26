nosave string *suicide_messages = ({
   "$N $vshove a pistol into $p mouth and $vpull the trigger.",
   "$N $vgrab some razors, $vslit $p wrists, and $vbleed to death.",
   "$N $vtake a long knife in $p good hand, $vstab it clear through $p other hand, and $p world $vblack out into nothingness.",
});

string get_suicide_message()
{
   return suicide_messages[random(sizeof(suicide_messages))];
}