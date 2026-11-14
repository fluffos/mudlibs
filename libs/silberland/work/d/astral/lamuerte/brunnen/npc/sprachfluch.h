
void spell_sprachfluch( object enemy, int damage, mixed dam_type)
{
  if(present("\nsprachfluch",enemy)) 
    return;
  switch( random(30) )
  {
    case 0:
      clone_object("/d/seher/angrox/obj/backspeech.lpc")->move(enemy,M_NOCHECK);
      break;
    case 1:
      clone_object("/d/seher/angrox/obj/gnome.lpc")->move(enemy,M_NOCHECK);
      break;
    case 2:
      clone_object("/d/seher/angrox/obj/rnd.lpc")->move(enemy,M_NOCHECK);
      break;
    case 3:
      clone_object("/d/seher/angrox/obj/schwob.lpc")->move(enemy,M_NOCHECK);
      break;
    case 4:
      clone_object("/d/seher/angrox/obj/words.lpc")->move(enemy,M_NOCHECK);
      break;
    case 5:
      clone_object("/d/seher/feyaria/obj/sternchen.lpc")->move(enemy,M_NOCHECK);
      break;
    case 6:
      clone_object("/d/seher/feyaria/obj/capslock.lpc")->move(enemy,M_NOCHECK);
      break;
    case 7:
      clone_object("/d/seher/feyaria/obj/uppercase.lpc")->move(enemy,M_NOCHECK);
      break;
    case 8:
      clone_object("/d/seher/feyaria/obj/aeiou.lpc")->move(enemy,M_NOCHECK);
      break;
    case 9:
      clone_object("/d/seher/feyaria/obj/nospace.lpc")->move(enemy,M_NOCHECK);
      break;
    case 10:
      clone_object("/d/seher/feyaria/obj/typo.lpc")->move(enemy,M_NOCHECK);
      break;
    case 11:
      clone_object("/d/seher/feyaria/obj/yoda.lpc")->move(enemy,M_NOCHECK);
      break;
    case 12:
      clone_object("/d/seher/feyaria/obj/typo2.lpc")->move(enemy,M_NOCHECK);
      break;
    case 13:
      clone_object("/d/seher/feyaria/obj/n.lpc")->move(enemy,M_NOCHECK);
      break;
    case 14:
      clone_object("/d/seher/feyaria/obj/hash.lpc")->move(enemy,M_NOCHECK);
      break;
    case 15:
      clone_object("/d/seher/feyaria/obj/zahlen.lpc")->move(enemy,M_NOCHECK);
      break;
    case 16:
      clone_object("/d/seher/feyaria/obj/double.lpc")->move(enemy,M_NOCHECK);
      break;
    case 17:
      clone_object("/d/seher/feyaria/obj/stabier.lpc")->move(enemy,M_NOCHECK);
      break;
    case 18:
      clone_object("/d/seher/feyaria/obj/orkisch.lpc")->move(enemy,M_NOCHECK);
      break;
    case 19:
      clone_object("/d/seher/feyaria/obj/zahnlos.lpc")->move(enemy,M_NOCHECK);
      break;
    case 20:
      clone_object("/d/seher/feyaria/obj/hoeflich.lpc")->move(enemy,M_NOCHECK);
      break;
    case 21:
      clone_object("/d/seher/feyaria/obj/bb.lpc")->move(enemy,M_NOCHECK);
      break;
    case 22:
      clone_object("/d/seher/feyaria/obj/ancient.lpc")->move(enemy,M_NOCHECK);
      break;
  }
  return;
}

